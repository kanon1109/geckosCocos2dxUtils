#include "MovieClip.h"
using namespace std;

MovieClip::MovieClip(void)
{
	this->frameList = CCArray::create();
	this->frameList->retain();
	this->currentFrame = 1;
	this->totalFrames = 1;
	this->startFrame = 1;
	this->endFrame = 1;
	this->fps = 0.0333f;
	this->isLoop = true;
	this->distroy = false;
	this->target = NULL;
	this->completeFun = NULL;
}

MovieClip::~MovieClip(void)
{
	CC_SAFE_RELEASE_NULL(this->frameList);
}

MovieClip* MovieClip::create(const char* name, const char* fileType, const char* prefix)
{
	MovieClip* mc = new MovieClip();
	if (mc && mc->init(name, fileType, prefix))
	{
		mc->autorelease();
		return mc;
	}
	CC_SAFE_DELETE(mc);
	return mc;
}

bool MovieClip::init(const char* name, const char* fileType, const char* prefix)
{
	string plistName = name;
	plistName += ".plist";
	string textureName = name;
	textureName += fileType;
	this->mcName = name;
	this->prefix = prefix;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plistName.c_str(), textureName.c_str());
	this->initFrame();
	this->gotoAndStop(this->currentFrame);
	return true;
}

void MovieClip::initFrame()
{
	string plistName = this->mcName;
	plistName += ".plist";
	//获取总帧数
	string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(plistName.c_str());
	CCDictionary* dictionary = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
	CCDictionary* framesDict = (CCDictionary*)dictionary->objectForKey("frames");
	//将帧的key存入数组
	CCDictElement* pElement = NULL;
	CCDICT_FOREACH(framesDict, pElement)
	{
		string spriteFrameName = pElement->getStrKey();
		string prefixStr = this->prefix;
		if (!prefixStr.empty())
		{
			//提取key的子字符串
			string subStr = spriteFrameName.substr(0, prefixStr.length());
			//比较子字符串的参数 如果相同则放入帧数组
			if (subStr.compare(prefixStr) == 0)
				this->frameList->addObject(CCString::create(spriteFrameName.c_str()));
		}
		else
		{
			this->frameList->addObject(CCString::create(spriteFrameName.c_str()));
		}
	}
	this->totalFrames = this->frameList->count();
	this->startFrame = 1;
	this->endFrame = this->totalFrames;
	this->currentFrame = this->startFrame;
	dictionary->release();
}

void MovieClip::gotoAndStop(int frame)
{
	this->stop();
	this->currentFrame = frame;
	if (frame > this->endFrame) this->endFrame = this->totalFrames;
	if (this->currentFrame > this->totalFrames) this->currentFrame = this->totalFrames;
	if (this->currentFrame < 1) this->currentFrame = 1;
	this->updateFrame();
}

void MovieClip::stop()
{
	this->unschedule(schedule_selector(MovieClip::loop));
}

void MovieClip::play(float fps /*= .033f*/, bool isLoop /*= true*/)
{
	this->stop();
	this->schedule(schedule_selector(MovieClip::loop), fps);
	this->fps = fps;
	this->isLoop = isLoop;
	this->distroy = false;
}


void MovieClip::updateFrame()
{
	CCString* str = (CCString*)this->frameList->objectAtIndex(this->currentFrame - 1);
	if (this->getTexture())
	{
		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString());
		CCRect rect = frame->getRect();
		this->m_obUnflippedOffsetPositionFromCenter = frame->getOffset();
		this->setTextureRect(rect, frame->isRotated(), frame->getOriginalSize());
	}
	else
	{
		this->initWithSpriteFrameName(str->getCString());
	}
}

void MovieClip::loop(float dt)
{
	this->currentFrame++;
	if (this->isLoop)
	{
		if (this->currentFrame > this->endFrame) this->currentFrame = this->startFrame;
	}
	else
	{
		if (this->currentFrame > this->endFrame)
		{
			this->currentFrame = this->endFrame;
			this->stop();
			//调用回调函数
			if (this->target && this->completeFun)
			{
				(this->target->*completeFun)(this);
			}
			//销毁
			if (this->distroy)
			{
				this->removeFromParent();
			}
		}
	}
	this->updateFrame();
}

void MovieClip::gotoAndPlay(int start, int end /*= 0*/, float fps /*= .033f*/, bool isLoop /*= true*/)
{
	if (start < 1) start = 1;
	if (start > this->totalFrames) start = this->totalFrames;
	if (end <= 0) end = this->totalFrames;
	if (end > this->totalFrames) end = this->totalFrames;
	this->startFrame = start;
	this->endFrame = end;
	this->play(fps, isLoop);
}

void MovieClip::playOnce(float fps /*= .033f*/, bool distroy /*= true*/)
{
	this->gotoAndPlay(1, this->totalFrames, fps, false);
	this->distroy = distroy;
}

void MovieClip::addEventListener(CCObject* target, SEL_COMPLETE_SELECTOR completeFun)
{
	this->target = target;
	this->completeFun = completeFun;
}
