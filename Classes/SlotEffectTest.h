#pragma once
#ifndef _SLOT_EFFECT_TEST_
#define _SLOT_EFFECT_TEST_
#include "cocos2d.h"
USING_NS_CC;
class SlotEffectTest :public CCScene
{
public:
	SlotEffectTest();
	~SlotEffectTest();
	//选择某个选项
	void selectSpt();
	//随机选择
	void randomSelectSpt();
	//重置所有选项
	void resetAllSpt();
	//随机
	void randomClick(CCObject* obj);
	void itemClick(CCObject* obj);
	CREATE_FUNC(SlotEffectTest);
};
#endif
