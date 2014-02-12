#include "TextButton.h"
static const int TYPE_RECT_BLUE	 = 1;
static const int TYPE_RECT_GRAY = 2;
static const int TYPE_RECT_GREEN = 3;
static const int TYPE_RECT_RED = 4;
static const int TYPE_2CORNER_GREEN = 5;
static const int TYPE_2CORNER_RED = 6;
static const int TYPE_1CORNER_GREEN = 7;
static const int TYPE_1CORNER_RED = 8;
static const int TYPE_2CORNER_GRAY = 9;
//默认按钮前缀
static string nameStr = "images/button/common_btn_";
static string tailStr = ".png";
TextButton::TextButton(int type, string str, float width)
{
	char num[2] = "";
	sprintf(num, "%i", type);
	string name = nameStr + num + tailStr;
	this->upSpt = CCScale9Sprite::create(name.c_str());  

	this->label = CCLabelTTF::create(str.c_str(), "隶书", 30);
	
	this->coreTarget = CCControlButton ::create(label, upSpt);
	switch(type)
	{
		case TYPE_RECT_BLUE:
		case TYPE_RECT_GRAY:
		case TYPE_RECT_GREEN:
		case TYPE_RECT_RED:
			this->coreTarget->setPreferredSize(CCSize(137, 67)); 
			break;
		case TYPE_2CORNER_GREEN	:
		case TYPE_2CORNER_RED	:
		case TYPE_2CORNER_GRAY	:
			this->coreTarget->setPreferredSize(CCSize(209, 63)); 
			break;
		case TYPE_1CORNER_GREEN	:
		case TYPE_1CORNER_RED	:
			this->coreTarget->setPreferredSize(CCSize(177, 63)); 
			break;
	}
	this->addChild(this->coreTarget);
	this->label->setPositionY(this->label->getPositionY() + 3);

	this->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchDown);  
	this->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchUpInside);  
}

TextButton::~TextButton(void)
{
	this->coreTarget->removeTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchDown);  
	this->coreTarget->removeTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchUpInside);  
	this->label->removeFromParent();
	this->coreTarget->removeFromParent();
	this->upSpt->removeFromParent();
	CC_SAFE_RELEASE(this->upSpt);
	CC_SAFE_RELEASE(this->label);
	CC_SAFE_RELEASE(this->coreTarget);
	CCLOG("remove");
}

void TextButton::setTag( int nTag )
{
	CCNodeRGBA::setTag(nTag);
	this->coreTarget->setTag(nTag);
}

void TextButton::btnClickHandler( CCObject* pSender, CCControlEvent event )
{  
	this->label->setPositionY(this->label->getPositionY() + 3);
}
