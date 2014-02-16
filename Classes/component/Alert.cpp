#include "Alert.h"
#include "component/TextButton.h"
#include "utils/Language.h"
USING_NS_CC;
static CCTexture2D* bgTexture;
//默认alert背景地址
static const char* bgName = "images/AlertBg.png";
//父容器
static CCNode* m_parent;
//弹出框
static Alert* alert;
Alert::Alert( char* content, bool showCancel /*= false*/, bool touchHide /*= true*/, CCNode* eventTarget /*= NULL*/, SEL_ALERT_SELECTOR confirmHandler /*= NULL*/, SEL_ALERT_SELECTOR cancelHandler /*= NULL*/ )
{
	if(bgTexture) this->bg = CCSprite::createWithTexture(bgTexture);
	else this->bg = CCSprite::create(bgName);
	this->addChild(this->bg);
	this->cancelBtn = TextButton::create(TYPE_RECT_RED, Language::get("btn_close"));
	this->confirmBtn = TextButton::create(TYPE_RECT_GREEN, Language::get("btn_yes"));
	this->addChild(this->confirmBtn);
	this->addChild(this->cancelBtn);
	this->confirmBtn->setPositionY(-this->bg->getContentSize().height * .5 + this->cancelBtn->getContentSize().height * .5 + 10);
	this->cancelBtn->setPositionY(-this->bg->getContentSize().height * .5 + this->cancelBtn->getContentSize().height * .5 + 10);
	this->cancelHandler = cancelHandler;
	this->confirmHandler = confirmHandler;
	this->confirmBtn->addEventListener(this, text_button_selector(Alert::confirmBtnClickHandler));
	this->cancelBtn->addEventListener(this, text_button_selector(Alert::cancelBtnClickHandler));

	this->pLabel = CCLabelTTF::create(content, "隶书", 32);
	this->pLabel->setDimensions(CCSizeMake(480, 0));
	this->pLabel->setHorizontalAlignment(kCCTextAlignmentLeft);

	this->scrollView = CCScrollView::create(CCSizeMake(480, 210), this->pLabel);
	this->scrollView->setDirection(kCCScrollViewDirectionVertical);
	this->scrollView->setViewSize(CCSizeMake(480, 210));
	this->scrollView->setPosition(ccp(-240, -91));
	this->scrollView->setAnchorPoint(ccp(0, 1));
	//调整起始位置
	this->scrollView->setContentOffset(ccp(0, 210 - this->pLabel->getContentSize().height));
	this->addChild(this->scrollView);
	
}

Alert::~Alert(void)
{
	if(this->bg->getParent())this->bg->removeFromParentAndCleanup(true);
	if(this->cancelBtn->getParent()) this->cancelBtn->removeFromParentAndCleanup(true);
	if(this->confirmBtn->getParent()) this->confirmBtn->removeFromParentAndCleanup(true);
	this->pLabel->removeFromParent();
	this->scrollView->removeFromParent();
	alert = NULL;
}

Alert* Alert::create( char* content, bool showCancel /*= false*/, bool touchHide /*= true*/, CCNode* eventTarget /*= NULL*/, SEL_ALERT_SELECTOR confirmHandler /*= NULL*/, SEL_ALERT_SELECTOR cancelHandler /*= NULL*/ )
{
	Alert* alert = new Alert(content, showCancel, touchHide, eventTarget, confirmHandler, cancelHandler);
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

void Alert::show( char* content, bool showCancel /*= false*/, bool touchHide /*= true*/, CCNode* eventTarget /*= NULL*/, SEL_ALERT_SELECTOR confirmHandler /*= NULL*/, SEL_ALERT_SELECTOR cancelHandler /*= NULL*/ )
{
	if(!alert) 
	{
		CCLOG("show");
		alert = Alert::create(content, showCancel, touchHide, eventTarget, confirmHandler, cancelHandler);
		//alert->retain();
		alert->setCascadeOpacityEnabled(true);
	}
	else 
	{
		alert->pLabel->setString(content);
		alert->scrollView->setContentOffset(ccp(0, 210 - alert->pLabel->getContentSize().height));
	}
	if(showCancel)
	{
		alert->cancelBtn->setPositionX(-alert->cancelBtn->getContentSize().width + 30);
		alert->confirmBtn->setPositionX(alert->confirmBtn->getContentSize().width - 30);
	}
	else alert->confirmBtn->setPositionX(0);
	alert->cancelBtn->setVisible(showCancel);
	alert->setOpacity(0x00);
	alert->setPosition(ccp(320, 350));
	alert->stopAllActions();
	if(m_parent && (!alert->getParent() || alert->getParent() != m_parent))
	{
		m_parent->addChild(alert);
	}
	CCMoveTo* moveTo = CCMoveTo::create(.2f, ccp(alert->getPositionX(), alert->getPositionY() + 20));
	CCFadeIn* fadeIn = CCFadeIn::create(.2f);
	CCSpawn* spawn = CCSpawn::create(moveTo, fadeIn, NULL);
	alert->runAction(spawn);

	CCFadeIn* fadeIn2 = CCFadeIn::create(.2f);
	alert->cancelBtn->runAction(fadeIn2);
	fadeIn2 = CCFadeIn::create(.2f);
	alert->confirmBtn->runAction(fadeIn2);

}

void Alert::confirmBtnClickHandler( CCNode* target )
{
	if(this->eventTarget && this->confirmHandler)
	{
		(this->eventTarget->*confirmHandler)();
	}
	if(this->touchHide)
	{
		this->hide();
	}
}

void Alert::cancelBtnClickHandler( CCNode* target )
{
	if(this->eventTarget && this->cancelHandler)
	{
		(this->eventTarget->*cancelHandler)();
	}
	this->hide();
}

void Alert::hide()
{
	alert->stopAllActions();
	alert->removeFromParent();
}