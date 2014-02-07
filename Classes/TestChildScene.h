#pragma once
#include "cocos2d.h"
USING_NS_CC;
class TestChildScene:public CCScene
{
public:
	TestChildScene(void);
	~TestChildScene(void);
	virtual void onEnter();
	void loop();
	CREATE_FUNC(TestChildScene);
};

