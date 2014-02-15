#include "Alert.h"
#include "component/TextButton.h"
#include "utils/Language.h"
USING_NS_CC;
static CCTexture2D* bgTexture;
//Ä¬ÈÏalert±³¾°µØÖ·
static const char* bgName = "images/AlertBg.png";
//¸¸ÈÝÆ÷
static CCNode* m_parent;
//µ¯³ö¿ò
static Alert* alert;
Alert::Alert(bool showCancel /*= false*/, bool touchHide /*= true*/, SEL_ALERT_SELECTOR callBackFunc /*= NULL*/ )
{
	if(bgTexture) this->bg = CCSprite::createWithTexture(bgTexture);
	else this->bg = CCSprite::create(bgName);
	this->addChild(this->bg);
	this->cancelBtn = TextButton::create(TYPE_RECT_RED, Language::get("btn_close"));
	this->confirmBtn = TextButton::create(TYPE_RECT_GREEN, Language::get("btn_yes"));
	this->addChild(this->confirmBtn);
	this->addChild(this->cancelBtn);
	this->cancelBtn->setVisible(showCancel);
	if(showCancel)
	{
		this->cancelBtn->setPositionX(-this->cancelBtn->getContentSize().width + 10);
		this->confirmBtn->setPositionX(this->confirmBtn->getContentSize().width - 10);
	}
	this->confirmBtn->setPositionY(-this->bg->getContentSize().height * .5 + this->cancelBtn->getContentSize().height * .5 + 10);
	this->cancelBtn->setPositionY(-this->bg->getContentSize().height * .5 + this->cancelBtn->getContentSize().height * .5 + 10);
}

Alert::~Alert(void)
{
	if(this->bg->getParent())this->bg->removeFromParentAndCleanup(true);
	if(this->cancelBtn->getParent()) this->cancelBtn->removeFromParentAndCleanup(true);
	if(this->confirmBtn->getParent()) this->confirmBtn->removeFromParentAndCleanup(true);
	alert->removeFromParent();
}

Alert* Alert::create(bool showCancel /*= false*/, bool touchHide /*= true*/, SEL_ALERT_SELECTOR callBackFunc /*= NULL*/ )
{
	Alert* alert = new Alert(showCancel, touchHide, callBackFunc);
	if(alert && alert->init())
	{
		alert->autorelease();
		return alert;
	}
	CC_SAFE_DELETE(alert);
	return NULL;
}

void Alert::initTexture( CCTexture2D* texture )
{
	bgTexture = texture;
}

void Alert::initTexture( const char* name )
{
	bgName = name;
}

void Alert::initParent( CCNode* parent )
{
	m_parent = parent;	
}

void Alert::show( char* content, bool showCancel /*= false*/, bool touchHide /*= true*/, SEL_ALERT_SELECTOR callBackFunc /*= NULL*/ )
{
	if(!alert) alert = Alert::create(showCancel, touchHide, callBackFunc);
	alert->setPosition(ccp(320, 350));
	if(m_parent && (!alert->getParent() || alert->getParent() != m_parent))
	{
		m_parent->addChild(alert);
	}
}
