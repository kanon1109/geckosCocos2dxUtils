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
}

MovieClip::~MovieClip(void)
{
	CC_SAFE_RELEASE_NULL(this->frameList);
}

MovieClip* MovieClip::create(const char* name)
{
	MovieClip* mc = new MovieClip();
	if (mc && mc->init(name))
	{
		mc->autorelease();
		return mc;
	}
	CC_SAFE_DELETE(mc);
	return mc;
}

bool MovieClip::init(const char* name)
{
	string plistName = name;
	plistName += ".plist";
	string textureName = name;
	textureName += ".png";
	this->mcName = name;
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
	this->totalFrames = framesDict->count();
	this->startFrame = 1;
	this->endFrame = this->totalFrames;
	this->currentFrame = this->startFrame;
	//将帧的key存入数组
	CCDictElement* pElement = NULL;
	CCDICT_FOREACH(framesDict, pElement)
	{
		CCDictionary* frameDict = (CCDictionary*)pElement->getObject();
		string spriteFrameName = pElement->getStrKey();
		this->frameList->addObject(CCString::create(spriteFrameName.c_str()));
	}
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
}


void MovieClip::updateFrame()
{
	CCString* str = (CCString* )this->frameList->objectAtIndex(this->currentFrame - 1);
	this->initWithSpriteFrameName(str->getCString());
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
