#pragma once
#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#include "cocos2d.h"
USING_NS_CC;
class FloatTips
{
public:
	FloatTips(void);
	~FloatTips(void);

	/**
	 * 初始化，设置父容器
	 */
	static void init(CCNode* parent);

	/**
	 * 显示漂浮文字
	 * @param	content	内容
	 */
	static void show(const char* content);

	/**
	 * 获取一个漂浮提示
	 */
	static FloatTip* getAFloatTip();

};

class FloatTip:public CCSprite
{
public:
	FloatTip();
	~FloatTip();
	void setText(const char* str);
private:
	//背景图片
	CCSprite* bg;
	//文本框
	CCLabelTTF* contentTf;
};
#endif
