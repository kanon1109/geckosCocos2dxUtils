#pragma once
#ifndef _TEXT_EFFECT_
#define _TEXT_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
class ProgressLabel :public CCLabelTTF
{
public:
	ProgressLabel();
	~ProgressLabel();
	
	//************************************
	// Description:创建
	// Parameter: const char * fontName	字体
	// Parameter: float fontSize		大小
	// Returns:   ProgressLabel*
	//************************************
	static ProgressLabel* create(const char *fontName, float fontSize);
	
	//************************************
	// Description: 显示文字逐行显示效果
	// Parameter: const char * str		文字内容
	// Parameter: int delay				显示间隔（豪秒）
	// Returns:   void
	//************************************
	void show(const char* str, float delay = 10);
	
	//************************************
	// Description: 暂停或恢复
	// Returns:   void
	//************************************
	void togglePause();
private:
	//间隔
	int m_delay;
	//是否暂停
	bool isPause;
	//需要显示的字符串
	const char* m_str;
	//计时器回调
	void timerHandler(float dt);
	//字符串位置索引
	int wordCount;
};
#endif
