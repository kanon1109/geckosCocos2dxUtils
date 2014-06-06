#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "component/TextButton.h"
#include "component/TabBar.h"
#include "utils/Timer.h"
USING_NS_CC;
using namespace extension;
class Test:public CCScene//, public CCTargetedTouchDelegate
{
public:
	Test(void);
	~Test(void);
	virtual bool init();
	virtual void onEnter();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	void runFun();
	void runFun2();
	void initTarBarList();
	CREATE_FUNC(Test);
private:
	TextButton* btn;
	TextButton* btn2;
	TabBar* tarBar;
	CCArray* tarBarList;
	//clickÊÂ¼þ
	void btnClickHandler(CCNode* node);
	void btn2ClickHandler(CCNode* node);
	void alertConfirmClickHandler();
	void alertCancelClickHandler();
	void tarBarClickHandler(int selectedIndex);

	void timerCompleteHandler(Timer* timer);
	void timerHandler(Timer* timer);

	void test(int& i);
};

