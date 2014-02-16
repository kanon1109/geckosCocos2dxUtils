#pragma once
#ifndef _TEXTURE_TAB_BAR_
#define _TEXTURE_TAB_BAR_
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace extension;
/************************************************************************/
/* 横向标签																*/
/************************************************************************/
//定义tabBar的回调函数类型
typedef void (CCObject::*SEL_TAR_BAR_SELECTOR)(int);
#define tar_bar_selector(_SELECTOR) (SEL_TAR_BAR_SELECTOR)(&_SELECTOR)
class TabBar:public CCNodeRGBA
{
public:
	/**
	 * @param	textureList		纹理列表		
	 * @param	gap				按钮间隔	
	 */
	TabBar(CCArray* textureList, int gap=0);
	~TabBar(void);

	static TabBar* create(CCArray* textureList, int gap=0);
	//监听回调
	void addEventListener(CCObject* target, SEL_TAR_BAR_SELECTOR callBackFunc);	
	//设置透明度
	void setOpacity(GLubyte opacity);
private:
	//间隔
	int gap;
	CCArray* textureList;
	//回调函数
	SEL_TAR_BAR_SELECTOR callBackFunc;
	void initUI();
	//设置选择按钮
	void setSelectedIndex(int index);
	//外部回调方法。
	void btnClickHandler(CCObject* pSender, CCControlEvent event);
	//调用回调的目标指针
	CCObject* target;
};
#endif
