#pragma once
#ifndef _ALERT_
#define _ALERT_
#include "cocos2d.h"
#include "TextButton.h"
USING_NS_CC;
//定义按钮的回调函数类型
typedef void (CCObject::*SEL_ALERT_SELECTOR)();
#define alert_selector(_SELECTOR) (SEL_ALERT_SELECTOR)(&_SELECTOR)
class Alert:public CCNodeRGBA
{
public:
	Alert(char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	~Alert(void);
	//初始化纹理
	static void initTexture(CCTexture2D* texture);
	static void initTexture(const char* name);
	static Alert* create( char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	static void initParent(CCNode* parent);
	/**
	 * 显示弹出框
	 * @param	content				文字内容		
	 * @param	showCancel			是否显示关闭按钮		
	 * @param	touchHide			是否点击确定后关闭界面	
	 * @param	eventTarget			事件监听目标指针	
	 * @param	confirmHandler		确定回调函数	
	 * @param	cancelHandler		取消回调函数	
	 */
	static void show(char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	//关闭和确定按钮
	TextButton* confirmBtn;
	TextButton* cancelBtn;
	//文本
	CCLabelTTF* pLabel;
	//滚动组件
	CCScrollView* scrollView;
private:
	CCSprite* bg;
	bool showCancel;
	bool touchHide;
	//隐藏面板
	void hide();
	//事件目标
	CCNode* eventTarget;
	//外部回调方法。
	SEL_ALERT_SELECTOR confirmHandler;
	SEL_ALERT_SELECTOR cancelHandler;
	//内部点击方法
	void confirmBtnClickHandler(CCNode* target);
	void cancelBtnClickHandler(CCNode* target);
	void initUI();
};
#endif
