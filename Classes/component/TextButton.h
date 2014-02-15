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
	static TextButton* create(int type, string str, float width = 0);
	//设置是否可以点击
	void setMouseEnabeld(bool flag);
	//设置是否按钮效果
	void setEnabled(bool flag);
	//监听回调
	void addEventListener(SEL_TEXT_BUTTON_SELECTOR callBackFunc);
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
	SEL_TEXT_BUTTON_SELECTOR btnCallBackFunc;
};
#endif
