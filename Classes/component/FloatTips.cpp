#include "FloatTips.h"
USING_NS_CC;
static CCNode* mParent;
static CCArray* ftPool;
static CCPoint startPos;
static CCTexture2D* texture = NULL;
static const char* defaultFileName = "ftips_bg.png";
FloatTips::FloatTips(void)
{
}

FloatTips::~FloatTips(void)
{
}

void FloatTips::show(const char* content)
{
	if(!mParent) return;
	FloatTip* ft = FloatTips::getAFloatTip();
	ft->setAnchorPoint(ccp(.5f, .5f));
	ft->setPosition(startPos);
	ft->setText(content);
	mParent->addChild(ft);
}

FloatTip* FloatTips::getAFloatTip()
{
	FloatTip* ft;
	CCLOG("ftPool->count() %i", ftPool->count());
	if(ftPool->count() == 0)
	{
		//如果池中没有对象则新建对象
		ft = FloatTip::createWithTexture(texture);
		
		ft->retain();
		//父sprite执行颜色变化的时候，子sprite也可以执行到这个变化
		ft->setCascadeOpacityEnabled(true);
	}
	else
	{
		ft = (FloatTip *)ftPool->lastObject();
		//设置透明度
		ft->setOpacity(0xFF);
		ftPool->removeLastObject();
	}
	CCMoveTo* moveTo = CCMoveTo::create(.2f, ccp(startPos.x, startPos.y + 20));
	CCDelayTime* delayTime = CCDelayTime::create(1.0f);
	CCMoveTo* moveTo2 = CCMoveTo::create(.3f, ccp(startPos.x, startPos.y + 40));
	CCFadeOut* fadeOut = CCFadeOut::create(.3f);
	CCSpawn* spawn = CCSpawn::create(moveTo2, fadeOut, NULL);
	CCSequence* sequence = CCSequence::create(moveTo, delayTime, spawn, NULL);

	//创建回调方法。
	CCCallFuncN * callBackFunc = CCCallFuncN::create(ft, callfuncN_selector(FloatTips::actionCompleteCallBackFunc));
	CCFiniteTimeAction * seq = CCSequence::create(sequence, callBackFunc, NULL);
	ft->runAction(seq);
	return ft;
}

void FloatTips::actionCompleteCallBackFunc(CCNode* ft)
{
	ft->removeFromParentAndCleanup(true);
	ftPool->addObject(ft);
}

void FloatTips::init( CCNode* parent, CCPoint p/*=ccp(320, 760)*/, CCTexture2D *pTexture/*=NULL*/ )
{
	startPos = p;
	mParent = parent;
	texture = pTexture;
	if(!ftPool)
	{
		ftPool = CCArray::create();
		ftPool->retain();
	}
}

void FloatTips::clear()
{
	if(ftPool)
	{
		CCObject* ft;
		int count = ftPool->count();
		for (int i = 0; i < count; i++)
		{
			ft = ftPool->objectAtIndex(i);
			//谁retain谁就负责release
			ft->release();
			CCLOG("retainCount %i", ft->retainCount());
		}
		ftPool->removeAllObjects();
	}
}

FloatTip::FloatTip()
{
	this->contentTf = NULL;
}

FloatTip::~FloatTip()
{
	CCLOG("remove FloatTip");
	if(this->contentTf) this->contentTf->removeFromParent();
	this->contentTf = NULL;
}

void FloatTip::setText(const char* str)
{
	this->createContentText();
	this->contentTf->setString(str);
}

void FloatTip::createContentText()
{
	if (!this->contentTf)
	{
		this->contentTf = CCLabelTTF::create("", "Arial", 40);
		this->contentTf->setAnchorPoint(ccp(.5, .5));
		this->contentTf->setPositionX(this->getContentSize().width * .5);
		this->contentTf->setPositionY(this->getContentSize().height * .5);
		this->addChild(this->contentTf);
	}
}

FloatTip* FloatTip::createWithTexture(CCTexture2D *pTexture)
{
	FloatTip* ft = new FloatTip();
	if (ft && ft->initWithTexture(pTexture))
	{
		ft->autorelease();
		return ft;
	}
	CC_SAFE_DELETE(ft);
	return NULL;
}
