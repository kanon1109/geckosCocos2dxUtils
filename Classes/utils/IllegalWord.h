#pragma once
#ifndef _ILLEGAL_WORD_
#define _ILLEGAL_WORD_
#include "cocos2d.h"
#include "StringUtil.h"
USING_NS_CC;
using namespace std;
using namespace tinyxml2;
class IllegalWord
{
public:
	IllegalWord();
	~IllegalWord();
	/**
	* 初始化关键字配置
	* @param name	配置名称
	*/
	static void init(string name = "illegalWords.xml");

	/**
	* 过滤文字
	* @param str	需要过滤的文字
	* @return		过滤后的文字
	*/
	static void filter(string &target);
};
#endif
