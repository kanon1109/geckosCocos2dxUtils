#pragma once
#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#include "cocos2d.h"
USING_NS_CC;
class FloatTip:public CCNodeRGBA
{
public:
	FloatTip();
	~FloatTip();
	static FloatTip* create();
	//设置文字内容
	void setText(const char* str);
	//根据文件名称路径创建图片
	void createWithImage(const char *pszFileName);
	//根据纹理创建图片
	void createWithTexture(CCTexture2D *pTexture);
private:
	//背景图片
	CCSprite* bg;
	//文本框
	CCLabelTTF* contentTf;
	//创建文本框
	void createContentText();
};

class FloatTips
{
public:
	FloatTips(void);
	~FloatTips(void);

	/**
	 * 初始化，设置父容器
	 */
	static void init(CCNode* parent, CCPoint p=ccp(320, 760), CCTexture2D *pTexture=NULL);

	/**
	 * 显示漂浮文字
	 * @param	content	内容
	 */
	static void show(const char* content);

	/**
	 * 获取一个漂浮提示
	 */
	static FloatTip* getAFloatTip();

	/**
	 * 清空池
	 */
	static void clear();

	//动作结束后回调
	void actionCompleteCallBackFunc(CCNode* ft);
};
#endif
