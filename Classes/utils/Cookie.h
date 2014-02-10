#pragma once
#ifndef _COOKIE_
#define _COOKIE_
#include "cocos2d.h"
USING_NS_CC;
class Cookie
{
public:
	Cookie(void);
	~Cookie(void);
	//是否保存过本地存储
	static bool isSaved();
	//获取用户存储指针
	static CCUserDefault* getShareUserData();
};
#endif
