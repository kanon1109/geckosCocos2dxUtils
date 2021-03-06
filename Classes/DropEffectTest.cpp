#include "DropEffectTest.h"
#include "effect/DropEffect.h"
#include "utils/ScreenUtil.h"
DropEffectTest::DropEffectTest()
{
	DropEffect* de = DropEffect::create("effect/coin.png", ScreenUtil::getBottom(), .01f);
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
	de->drop(5, touch->getLocation().x, touch->getLocation().y, 0, 1, .9f, 0, 0, -5, 5, -5, 5);
}
