#include "TabBar.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace extension;
TabBar::TabBar(CCArray* textureList, int gap/*=0*/)
{
	this->textureList = textureList;
	this->gap = gap;
	this->initUI();
}

TabBar::~TabBar(void)
{
}

TabBar* TabBar::create( CCArray* textureList, int gap/*=0*/ )
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
	CCScale9Sprite* spt;
	CCString* str;
	CCControlButton* btn;
	CCLabelTTF* label;
	for (int i = 0; i < count; i+=1)
	{
		str = (CCString*)this->textureList->objectAtIndex(i);
		spt = CCScale9Sprite::create(str->getCString());
		label = CCLabelTTF::create("", "Arial", 30);
		btn = CCControlButton::create(label, spt);
		btn->setPreferredSize(CCSize(148, 62)); 
		 //设置不现实按钮效果
		btn->setZoomOnTouchDown(false);
		this->addChild(btn);
	}
}
