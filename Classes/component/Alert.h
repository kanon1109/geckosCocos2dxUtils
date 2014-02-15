#pragma once
#ifndef _ALERT_
#define _ALERT_
#include "cocos2d.h"
#include "TextButton.h"
USING_NS_CC;
//定义按钮的回调函数类型
typedef void (CCObject::*SEL_ALERT_SELECTOR)(CCNode*);
#define alert_selector(_SELECTOR) (SEL_ALERT_SELECTOR)(&_SELECTOR)
class Alert:public CCNodeRGBA
{
public:
	Alert(bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
	~Alert(void);
	//初始化纹理
	static void initTexture(CCTexture2D* texture);
	static void initTexture(const char* name);
	static Alert* create(bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
	static void initParent(CCNode* parent);
	/**
	 * 显示弹出框
	 * @param	content				文字内容		
	 * @param	showCancel			是否显示关闭按钮		
	 * @param	touchHide			是否点击确定后关闭界面	
	 * @param	callBackFunc		回调函数	
	 */
	static void show(char* content, bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
private:
	TextButton* confirmBtn;
	TextButton* cancelBtn;
	CCSprite* bg;
	bool showCancel;
	bool touchHide;
	//外部回调方法。
	SEL_ALERT_SELECTOR callBackFunc;
	void initUI();
};
#endif
