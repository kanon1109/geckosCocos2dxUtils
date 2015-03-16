#include "ShadowLabelTest.h"
#include "component\ShadowLabel.h"
#include "utils\Language.h"
#include "utils\ScreenUtil.h"
#include "component\SpriteBlur.h"

ShadowLabelTest::ShadowLabelTest()
{
	CCLayerColor* layer = CCLayerColor::create(ccc4(0x00, 0xFF, 0xFF, 0xFF), ScreenUtil::getScreenWidth(), ScreenUtil::getScreenHeight());
	this->addChild(layer);

	Language::init("language.xml");
	ShadowLabel* text = ShadowLabel::create(Language::get("eatWhiteBtn"), "Arial", 30);
	text->setShadowColor(ccc3(0x00, 0x00, 0x00));
	text->setPosition(ccp(400, 200));
	this->addChild(text);

	SpriteBlur* spt = SpriteBlur::create("normal_body.png");
	spt->setPosition(ccp(300, 400));
	spt->setBlurSize(1.3f);
	this->addChild(spt);
}


ShadowLabelTest::~ShadowLabelTest()
{
}
