#include "CBFloatTips.h"
#include "utils/ScreenUtil.h"
USING_NS_CC;

CBFloatTip::CBFloatTip()
{
	m_bg = CCSprite::create("cocosBaseComponetTest/ftips_bg.png");
	m_tf = CCLabelTTF::create();
	m_tf->setColor(ccWHITE);
	m_tf->setFontSize(40);
	m_tf->setAnchorPoint(ccp(0.5, 0.5));
	addChild(m_bg);
	addChild(m_tf);
}

void CBFloatTip::setContent(const char* content)
{
	m_tf->setString(content);
}

CBFloatTip::~CBFloatTip()
{
	m_bg->removeFromParent();
	m_tf->removeFromParent();
}

//////////////////////////////////////////////////////////////////////////
CBFloatTips::CBFloatTips(void)
{
	setCachable(true);
	setAutoRemoveUnusedTexture(false);
	this->ftAry = CCArray::create();
	this->ftAry->retain();
	m_state	= state_hide;

	CCLOG("FloatTips");
}

CBFloatTips::~CBFloatTips(void)
{
	CCLOG("~FloatTips");
}

void CBFloatTips::show(const char* content)
{
	CBFloatTip* ft = CBFloatTip::create();
	ft->setContent(content);
	ft->setCascadeOpacityEnabled(true);
	ft->setOpacity(0xFF);
	this->addChild(ft);
	this->ftAry->addObject(ft);

	if(m_state == state_show)
	{
		stopAllActions();
	}
	else
	{
		CCSceneManager::sharedManager()->runUIScene(this);
		m_state	= state_show;
	}

	
	int				initX		= ScreenUtil::getScreenWidth() / 2;
	int				initY		= ScreenUtil::getTop() - 100;
	CCMoveTo*		move1		= CCMoveTo::create(0.2f, ccp(initX, initY + 20));
	CCDelayTime*	delayTime	= CCDelayTime::create(1.0f);
	CCMoveTo*		move2		= CCMoveTo::create(0.3f, ccp(initX, initY + 40));
	CCFadeOut*		fadeOut		= CCFadeOut::create(0.3f);
	CCSpawn*		spawn		= CCSpawn::create(move2, fadeOut, NULL);
	CCSequence*		sequence	= CCSequence::create(move1, delayTime, spawn, NULL);

	//创建回调方法。
	CCCallFuncN *		callBackFunc	= CCCallFuncN::create(this, callfuncN_selector(CBFloatTips::hide));
	CCFiniteTimeAction* seq				= CCSequence::create(sequence, callBackFunc, NULL);
	ft->setPosition(ccp(initX, initY));
	ft->runAction(seq);
}

void CBFloatTips::hide(CCNode* pNode)
{
	if (this->ftAry->count() > 0)
		this->ftAry->removeObjectAtIndex(0);
	
	if (this->ftAry->count() == 0)
	{
		CCSceneManager::sharedManager()->popUIScene(this);
		m_state	= state_hide;
	}
}

void CBFloatTips::onExitScene()
{
	//CCLOG("onExitScene FloatTips");
}

static CBFloatTips* instance = NULL;
CBFloatTips* CBFloatTips::getInstance()
{
	if (instance == NULL)
	{
		REGISTER_SCENE_FUNC(CBFloatTips);
		instance = (CBFloatTips*)LoadScene("CBFloatTips");
	}
	return instance;
}
