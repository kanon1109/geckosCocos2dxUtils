#pragma once
#ifndef _TEXTBUTTON_
#define _TEXTBUTTON_
#include "cocos2d.h"
#include "cocos-ext.h"
#include <algorithm>
USING_NS_CC;
/************************************************************************/
/* 文本按钮，仅限游戏内常用按钮使用                                           */
/************************************************************************/
using namespace std;
using namespace extension;
//定义按钮的回调函数类型
typedef void (CCObject::*SEL_TEXT_BUTTON_SELECTOR)(CCNode*);
#define text_button_selector(_SELECTOR) (SEL_TEXT_BUTTON_SELECTOR)(&_SELECTOR)

#define TYPE_RECT_BLUE  1
#define TYPE_RECT_GRAY  2
#define TYPE_RECT_GREEN  3
#define TYPE_RECT_RED  4
#define TYPE_2CORNER_GREEN  5
#define TYPE_2CORNER_RED  6
#define TYPE_1CORNER_GREEN  7
#define TYPE_1CORNER_RED  8
#define TYPE_2CORNER_GRAY  9
class TextButton:public CCNodeRGBA
{
public:
	/**
	 * @param	type		颜色类型		
	 * @param	str			文字内容	
	 * @param	width		按钮宽度	
	 */
	TextButton(int type, string str, float width = 0);
	~TextButton(void);
	//获取高宽
	CCSize getContentSize();
	static TextButton* create(int type, string str, float width = 0);
	//设置是否可以点击
	void setMouseEnabeld(bool flag);
	//设置是否按钮效果
	void setEnabled(bool flag);
	//监听回调
	void addEventListener(CCObject* target, SEL_TEXT_BUTTON_SELECTOR callBackFunc);	
private:
	//按钮
	CCControlButton* coreTarget;
	//9宫格
	CCScale9Sprite* upSpt;
	//文本
	CCLabelTTF* label;
	//内部点击方法
	void btnClickHandler(CCObject* pSender, CCControlEvent event);
	//外部回调方法。
	SEL_TEXT_BUTTON_SELECTOR callBackFunc;
	//调用回调的目标指针
	CCObject* target;
};
#endif
