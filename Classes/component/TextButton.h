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
private:
	//按钮
	CCControlButton* button;
	//9宫格
	CCScale9Sprite* psc9Selected;
	//文本
	CCLabelTTF* label;
};
#endif
