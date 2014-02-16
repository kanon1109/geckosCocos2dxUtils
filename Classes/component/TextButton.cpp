#include "TextButton.h"

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
	this->coreTarget = CCControlButton::create(this->label, this->upSpt);
	float btnWidth;
	float btnHeight;
	switch(type)
	{
		case TYPE_RECT_BLUE:
		case TYPE_RECT_GRAY:
		case TYPE_RECT_GREEN:
		case TYPE_RECT_RED:
			btnWidth = 137;
			btnHeight = 67;
			break;
		case TYPE_2CORNER_GREEN	:
		case TYPE_2CORNER_RED	:
		case TYPE_2CORNER_GRAY	:
			btnWidth = 209;
			btnHeight = 63;
			break;
		case TYPE_1CORNER_GREEN	:
		case TYPE_1CORNER_RED	:
			btnWidth = 177;
			btnHeight = 63;
			break;
	}
	if(width > 0) btnWidth = width;
	this->addChild(this->coreTarget);
	this->coreTarget->setPreferredSize(CCSize(btnWidth, btnHeight)); 
	this->label->setPositionY(this->label->getPositionY() + 3);
	this->callBackFunc = NULL;
	this->target = NULL;
	this->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchDown);  
	this->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchUpInside);  
}

TextButton::~TextButton(void)
{
	CCLOG("remove");
	this->coreTarget->removeTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchDown);  
	this->coreTarget->removeTargetWithActionForControlEvents(this, cccontrol_selector(TextButton::btnClickHandler), CCControlEventTouchUpInside);  
	this->label->removeFromParent();
	this->upSpt->removeFromParent();
	this->coreTarget->removeFromParent();
}

void TextButton::btnClickHandler( CCObject* pSender, CCControlEvent event )
{  
	this->label->setPositionY(this->label->getPositionY() + 3);
	if(this->target && this->callBackFunc && event == CCControlEventTouchUpInside)
	{
		(this->target->*callBackFunc)(this);
	}
}

TextButton* TextButton::create(int type, string str, float width)
{
	TextButton* textButton = new TextButton(type, str, width);
	if (textButton && textButton->init())
	{
		textButton->autorelease();
		return textButton;
	}
	CC_SAFE_DELETE(textButton);
	return NULL;
}

void TextButton::setMouseEnabeld( bool flag )
{
	this->coreTarget->setEnabled(flag);
	this->label->setPositionY(this->label->getPositionY() + 3);
}

void TextButton::setEnabled( bool flag )
{
	this->coreTarget->setZoomOnTouchDown(flag);
}

void TextButton::addEventListener(CCObject* target, SEL_TEXT_BUTTON_SELECTOR callBackFunc )
{
	this->callBackFunc = callBackFunc;
	this->target = target;
}

CCSize TextButton::getContentSize()
{
	return this->coreTarget->getContentSize();
}

void TextButton::setOpacity( GLubyte opacity )
{
	this->coreTarget->setOpacity(opacity);
	this->label->setOpacity(opacity);
	CCNodeRGBA::setOpacity(opacity);
}
