#include "Test.h"
#include "common/EnterFrame.h"
#include "TestChildScene.h"
Test::Test(void)
{
	
}

Test::~Test(void)
{
}

bool Test::init()
{
	EnterFrame::init(this);
	EnterFrame::push(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun2));
	EnterFrame::push(callfunc_selector(Test::runFun));

	EnterFrame::pop(callfunc_selector(Test::runFun2));
	EnterFrame::pop(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun));
	TestChildScene* cs = TestChildScene::create();
	this->addChild(cs);

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

bool Test::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	EnterFrame::clear();
	return true;
}

void Test::runFun()
{
	CCLOG("run1");
}

void Test::runFun2()
{
	CCLOG("run2");
}
