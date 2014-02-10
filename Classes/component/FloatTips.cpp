#include "FloatTips.h"
USING_NS_CC;
static CCNode* parent;
static CCArray* ftPool;
FloatTips::FloatTips(void)
{
}

FloatTips::~FloatTips(void)
{
}

void FloatTips::init( CCNode* parent )
{
	parent = parent;
	if(!ftPool)
	{
		ftPool = CCArray::create();
		ftPool->retain();
	}
}

void FloatTips::show(const char* content)
{
	FloatTip* ft = FloatTips::getAFloatTip();
	ft->setText(content);
	parent->addChild(ft);
}

FloatTip* FloatTips::getAFloatTip()
{
	/*FloatTip* ft = new FloatTip();
	return ft;*/
	return NULL;
}

FloatTip::FloatTip()
{
	this->bg = CCSprite::create("ftips_bg");
	this->bg->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->bg);

	this->contentTf = CCLabelTTF::create();
	this->contentTf->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->contentTf);
}

FloatTip::~FloatTip()
{
	this->bg->removeFromParent();
	CC_SAFE_RELEASE(this->bg);

	this->contentTf->removeFromParent();
	CC_SAFE_RELEASE(this->contentTf);
}

void FloatTip::setText(const char* str)
{
	this->contentTf->setString(str);
}