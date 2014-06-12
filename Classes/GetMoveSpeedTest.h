#pragma once
#ifndef _GET_MOVE_SPEED_TEST_
#define _GET_MOVE_SPEED_TEST_
#include "cocos2d.h"
USING_NS_CC;
class GetMoveSpeedTest :public CCScene, public CCTargetedTouchDelegate
{
public:
	GetMoveSpeedTest();
	~GetMoveSpeedTest();
	CREATE_FUNC(GetMoveSpeedTest);

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
};
#endif

