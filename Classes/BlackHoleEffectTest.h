#pragma once
#ifndef _BLACK_HOLE_EFFECT_TEST_
#define _BLACK_HOLE_EFFECT_TEST_
#include "cocos2d.h"
USING_NS_CC;
class BlackHoleEffectTest :public CCScene, public CCTargetedTouchDelegate
{
public:
	BlackHoleEffectTest();
	~BlackHoleEffectTest();
	CREATE_FUNC(BlackHoleEffectTest);
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	void update(float dt);
private:
	CCArray* ary;
	CCArray* objList;
	void inHoleComplete(CCObject* obj);
	void attenuationComplete(CCObject* obj);
	void overComplete(CCObject* obj);
	float randnum(float a, float b);
	void addObj();
};
#endif