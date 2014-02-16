#include "TabBar.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace extension;
TabBar::TabBar(CCArray* textureList, int gap/*=0*/)
{
	this->textureList = textureList;
	this->gap = gap;
	this->callBackFunc = NULL;
	this->target = NULL;
	this->initUI();
}

TabBar::~TabBar(void)
{
	int count = this->textureList->count();
	CCControlButton* btn;
	CCControlButton* selectedBtn;
	for (int i = 0; i < count; i+=1)
	{
		btn = (CCControlButton* )this->getChildByTag(i + 1);
		selectedBtn = (CCControlButton*)this->getChildByTag((i + 1) * 10);
		btn->removeFromParentAndCleanup(true);
		selectedBtn->removeFromParentAndCleanup(true);
	}
	this->textureList->removeAllObjects();
}

TabBar* TabBar::create( CCArray* textureList, int gap/*=0*/)
{
	TabBar* textureTabBar = new TabBar(textureList, gap);
	if (textureTabBar && textureTabBar->init())
	{
		textureTabBar->autorelease();
		return textureTabBar;
	}
	CC_SAFE_DELETE(textureTabBar);
	return NULL;
}

void TabBar::initUI()
{
	int count = this->textureList->count();
	CCArray* ary;
	CCScale9Sprite* spt;
	CCString* str;
	CCControlButton* btn;
	CCLabelTTF* label;
	for (int i = 0; i < count; i+=1)
	{
		ary = (CCArray*)this->textureList->objectAtIndex(i);
		for (unsigned int j = 0; j < ary->count(); j+=1)
		{
			str = (CCString*)ary->objectAtIndex(j);
			spt = CCScale9Sprite::create(str->getCString());
			label = CCLabelTTF::create("", "Arial", 30);
			btn = CCControlButton::create(label, spt);
			btn->setAnchorPoint(ccp(0, 0));
			if (j == 0)
			{
				btn->setPreferredSize(CCSize(145, 62)); 
				btn->setTag(i + 1);
				btn->addTargetWithActionForControlEvents(this, cccontrol_selector(TabBar::btnClickHandler), CCControlEventTouchDown);  
				btn->setZOrder(0);
			}
			else 
			{
				btn->setPreferredSize(CCSize(145, 80)); 
				btn->setTag((i + 1) * 10);
				btn->setVisible(false);
				btn->setPositionY(btn->getPositionY() - 9);
				btn->setZOrder(count + 1);
			}
			this->addChild(btn);
			btn->setPositionX(i * (btn->getContentSize().width + this->gap));
			//设置不现实按钮效果
			btn->setZoomOnTouchDown(false);
		}
	}
}

void TabBar::btnClickHandler( CCObject* pSender, CCControlEvent event )
{
	CCControlButton* btn = (CCControlButton*) pSender;
	//其余按钮按下状态隐藏
	this->setSelectedIndex(btn->getTag());
	//设置单个按钮按下状态显示
	btn = (CCControlButton* )this->getChildByTag(btn->getTag());
	CCControlButton* selectedBtn = (CCControlButton* )this->getChildByTag(btn->getTag() * 10);
	selectedBtn->setVisible(true);
	btn->setVisible(false);
	//目标指针调用回调函数
	if(this->target && this->callBackFunc)
	{
		(this->target->*callBackFunc)(btn->getTag() - 1);
	}
}

void TabBar::setSelectedIndex( int index )
{
	int count = this->textureList->count();
	CCControlButton* btn;
	CCControlButton* selectedBtn;
	if(index > count) return;
	for (int i = 0; i < count; i+=1)
	{
		if(i != index - 1)
		{
			btn = (CCControlButton* )this->getChildByTag(i + 1);
			btn->setZOrder(count - abs(index - i));
			selectedBtn = (CCControlButton*)this->getChildByTag((i + 1) * 10);
			selectedBtn->setVisible(false);
			btn->setVisible(true);
			//CCLOG("getZOrder = %i%i", btn->getZOrder(), selectedBtn->getZOrder());
		}
	}
}

void TabBar::addEventListener( CCObject* target, SEL_TAR_BAR_SELECTOR callBackFunc )
{
	this->target = target;
	this->callBackFunc = callBackFunc;
}

void TabBar::setOpacity( GLubyte opacity )
{
	int count = this->textureList->count();
	CCControlButton* btn;
	CCControlButton* selectedBtn;
	for (int i = 0; i < count; i+=1)
	{
		btn = (CCControlButton* )this->getChildByTag(i + 1);
		selectedBtn = (CCControlButton*)this->getChildByTag((i + 1) * 10);
		selectedBtn->setOpacity(opacity);
		btn->setOpacity(opacity);
	}
	CCNodeRGBA::setOpacity(opacity);
}
