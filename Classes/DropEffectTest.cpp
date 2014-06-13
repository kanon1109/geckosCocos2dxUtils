#include "DropEffectTest.h"
#include "effect/DropEffect.h"
#include "utils/ScreenUtil.h"
DropEffectTest::DropEffectTest()
{
	DropEffect* de = DropEffect::create(ScreenUtil::getBottom(), .01f);
	de->setTag(1);
	this->addChild(de);
	CCLOG("DropEffectTest");
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}


DropEffectTest::~DropEffectTest()
{
}

bool DropEffectTest::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLOG("ccTouchBegan");
	return true;
}

void DropEffectTest::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}

void DropEffectTest::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLOG("ccTouchEnded");
	DropEffect* de = (DropEffect* )this->getChildByTag(1);
	de->drop("effect/coin.png", 5, touch->getLocation().x, touch->getLocation().y, .9f, .4f, 50, 200);
}
