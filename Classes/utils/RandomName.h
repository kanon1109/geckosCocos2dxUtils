#pragma once
#ifndef _RANDOM_NAME_
#define _RANDOM_NAME_
#include "cocos2d.h"
#include "Random.h"
USING_NS_CC;
using namespace tinyxml2;
using namespace std;
class RandomName
{
public:
	RandomName();
	~RandomName();
	/**
	* 初始化随机名字表
	* @param name	配置表名称
	*/
	static void init(const char* name);

	/**
	* 创建随机名字
	* @param str	需要创建的随机名称字符串
	*/
	static void getRandomName(string &str);
};
#endif
