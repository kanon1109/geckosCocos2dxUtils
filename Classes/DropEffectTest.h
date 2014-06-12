#pragma once
#ifndef _DROP_EFFECT_TEST_
#define _DROP_EFFECT_TEST_
#include "cocos2d.h"
USING_NS_CC;
class DropEffectTest :public CCScene, public CCTargetedTouchDelegate
{
public:
	DropEffectTest();
	~DropEffectTest();
	CREATE_FUNC(DropEffectTest);

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
};
#endif
