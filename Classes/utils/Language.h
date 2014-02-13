#pragma once
#ifndef _LANGUAGE_INIT_
#define _LANGUAGE_INIT_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class Language
{
public:
	Language(void);
	~Language(void);
	/**
	 * 解析xml配置`
	 * @param name	配置名称
	 */
	static void init(string name);
	/**
	 * 获取配置中文字
	 * @param name			节点名
	 * @param vector		需要####替换特殊符号的vector
	 */
	static const char* get(string name, vector<string> *v=NULL);
};
#endif

