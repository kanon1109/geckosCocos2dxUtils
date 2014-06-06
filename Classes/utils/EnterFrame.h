#pragma once
#ifndef _ENTER_FRAME_INIT_
#define _ENTER_FRAME_INIT_
#include "cocos2d.h"
USING_NS_CC;
class EnterFrame
{
public:
	EnterFrame(void);
	~EnterFrame(void);
	//初始化
	//container		外部容器
	//fps			帧频
	static void init(CCNode* container, float fps=60.0);
	//开始运行
	static void start();
	//停止运行
	static void stop();
	//放入方法
	static void push(SEL_CallFunc callfunc);
	//删除指定方法
	static void pop(SEL_CallFunc callfunc);
	//清空列表
	static void clear();
	
	//FUNCADDR是指向这样一个函数的指针，该函数的返回值为void类型，函数有一个int型的
	//typedef void (*FUNCADDR)(int) 
};

class Node:public CCNode
{
public:
	//循环
	void loop(float dt);
};
#endif