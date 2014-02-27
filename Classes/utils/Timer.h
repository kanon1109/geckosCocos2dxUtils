#pragma once
#ifndef _UTILS_TIMER_
#define _UTILS_TIMER_
#include "cocos2d.h"
USING_NS_CC;
//一个计时器时间结束时回调
typedef void (CCObject::*SEL_TIMER_SELECTOR)(CCNode*);
#define timer_selector(_SELECTOR) (SEL_TIMER_SELECTOR)(&_SELECTOR)

class Timer:public CCNode
{
public:
	/**
	* 计时器
	* @param delay				计时器事件间的延迟（以毫秒为单位）。 
	* @param repeatCount		设置的计时器运行总次数。 
	*/
	Timer(float delay, int repeatCount = 0);
	~Timer();
	static Timer* create(float delay, int repeatCount = 0);
	void addEventListener(CCNode* target, SEL_TIMER_SELECTOR timeFunc);
	//开始和暂停
	void start();
	void stop();
	//如果计时器正在运行，则停止计时器，并将 currentCount 属性设回为 0，这类似于秒表的重置按钮。
	void reset();
	//计时器是否在运行
	bool running;
	int currentCount;
	//设置重复次数
	void setRepeatCount(int count);
	//设置计时器间隔
	void setDelay(float delay);
private:
	float m_delay;
	int m_repeatCount;
	CCNode* target;
	SEL_TIMER_SELECTOR timeHandler;
	void loop(float dt);
};
#endif
