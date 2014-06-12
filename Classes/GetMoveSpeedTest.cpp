#include "GetMoveSpeedTest.h"
#include "utils/GetMoveSpeed.h"

GetMoveSpeedTest::GetMoveSpeedTest()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCLOG("GetMoveSpeedTest");
}


GetMoveSpeedTest::~GetMoveSpeedTest()
{
}

bool GetMoveSpeedTest::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	GetMoveSpeed::initPos(touch->getLocation().x, touch->getLocation().y);
	CCLOG("ccTouchBegan");
	return true;
}

void GetMoveSpeedTest::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	float speed = GetMoveSpeed::getSpeed(touch->getLocation().x, touch->getLocation().y);
	CCLOG("speed %f", speed);
}

void GetMoveSpeedTest::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

}
