#include "MaskTest.h"
#include "utils\MaskUtil.h"
MaskTest::MaskTest()
{
	CCSprite* spt = CCSprite::create("effect/a1.png");
	CCSprite* mask = CCSprite::create("normal_body.png");
	CCSprite* maskMc = MaskUtil::createMaskedSprite(spt, mask, true);
	maskMc->setPosition(ccp(200, 200));
	this->addChild(maskMc);

	maskMc = MaskUtil::createMaskedSprite(spt, mask);
	maskMc->setPosition(ccp(500, 200));
	this->addChild(maskMc);
}


MaskTest::~MaskTest()
{
}
