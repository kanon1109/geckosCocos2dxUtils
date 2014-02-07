#include "Test.h"
#include "utils/EnterFrame.h"
#include "TestChildScene.h"
#include "utils/Random.h"

Test::Test(void)
{
	
}

Test::~Test(void)
{
}

bool Test::init()
{
	CCLOG("r=%f", Random::randomFloat(-2.4f, 6.6f));
	/*EnterFrame::init(this);
	EnterFrame::push(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun2));
	EnterFrame::push(callfunc_selector(Test::runFun));

	EnterFrame::pop(callfunc_selector(Test::runFun2));
	EnterFrame::pop(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun));*/
	TestChildScene* cs = TestChildScene::create();
	this->addChild(cs);

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

bool Test::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLOG("randomFloat r=%f", Random::randomFloat(-2.4f, 6.6f));
	CCLOG("randomInt r =%i", Random::randomInt(-6, 6));
	CCLOG("randrange r =%i", Random::randrange(10, 10, -1));
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
