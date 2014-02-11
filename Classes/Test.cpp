#include "Test.h"
#include "utils/EnterFrame.h"
#include "TestChildScene.h"
#include "utils/Random.h"
#include "utils/StringUtil.h"
#include "utils/TimeFormat.h"
#include "utils/Language.h"
#include "component/FloatTips.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>   
#include <algorithm>  
#include "cocos-ext.h"
using namespace extension;
using namespace std;
using std::vector;
Test::Test(void)
{
	
}

Test::~Test(void)
{
}

bool Test::init()
{
	CCLOG("r=%f", Random::randomFloat(-2.4f, 6.6f));

	std::string s = " ";
	CCLOG("rfind = %i\n", s.rfind("\t"));
	CCLOG("is WhiteSpace: %i\n", StringUtil::isWhiteSpace(s));

	std::string str = "  111111  ";
	//str.replace(0, 2, "");
	StringUtil::trim(&str);
	CCLOG("1 str%s", str.c_str());
	StringUtil::zfill(&str, 9);
	CCLOG("zfill%s", str.c_str());
	str = "1234";
	StringUtil::reverse(&str);
	CCLOG("reverse= %s", str.c_str());
	StringUtil::cutOff(&str, 1, 1);
	CCLOG("cutOff= %s", str.c_str());

	string email = "kanontang@gmail.com";
	StringUtil::trim(&email);
	CCLOG("email= %s", email.c_str());
	bool isEmail = StringUtil::isEmail(&email);
	CCLOG("%d", isEmail);
	//CCLOG("bool", StringUtil::isEmail(&email));
	//CCLOG("email= %s", email.c_str());
	vector<string> v;
	StringUtil::split(v, "00:06:11", ":");
	for (unsigned int i = 0; i < v.size(); i++)
	{
		CCLOG("v[i]%s", v[i].c_str());
	}

	string time;
	TimeFormat::secondToTime(&time, 7735);
	CCLOG("secondToTime= %s", time.c_str());

	TimeFormat::timeToSecond(&time, "00:60:00");
	CCLOG("timeToSecond= %s", time.c_str());

	Language::init("language.xml");

	v.clear();
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	//恢复####点体力######## 恢复3点体力45
	CCLOG("test= %s", Language::get("test", &v)->getCString());

	/*EnterFrame::init(this);
	EnterFrame::push(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun2));
	EnterFrame::push(callfunc_selector(Test::runFun));

	EnterFrame::pop(callfunc_selector(Test::runFun2));
	EnterFrame::pop(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun));*/


	CCScale9Sprite *psc9Selected = CCScale9Sprite::create("ftips_bg.png");  
	CCLabelTTF *label = CCLabelTTF::create("My Button", "Arial", 30);
	CCControlButton * button = CCControlButton ::create(label, psc9Selected);
	/* 强制设置按钮大小,如果按钮标题大小超过这个范围，则会自动扩大 */  
	button->setPreferredSize(CCSize(300, 50)); 
	this->addChild(button);

	button->setPosition(ccp(300, 500));

	FloatTips::init(this);

	TestChildScene* cs = TestChildScene::create();
	this->addChild(cs);

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

bool Test::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLOG("randomFloat r=%f", Random::randomFloat(-2.4f, 6.6f));
	CCLOG("randomInt r =%i", Random::randomInt(-6, 6));
	CCLOG("randrange r =%i", Random::randrange(1, 10, 2));
	CCLOG("boolean=%i", Random::boolean(.2f));
	EnterFrame::clear();

	vector<string> v;
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	
	FloatTips::show(Language::get("test", &v)->getCString());

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

void Test::onEnter()
{
	CCScene::onEnter();
}
