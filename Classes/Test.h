#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Test:public CCScene, public CCTargetedTouchDelegate
{
public:
	Test(void);
	~Test(void);
	virtual bool init();
	virtual void onEnter();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	void runFun();
	void runFun2();
	CREATE_FUNC(Test);
};

