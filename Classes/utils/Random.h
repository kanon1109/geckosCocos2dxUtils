#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Random
{
public:
	Random(void);
	~Random(void);
	 /**
     * 返回 a - b之间的随机数，不包括  max(a, b)
     * @param a
     * @param b
     * @return 假设 a < b, [a, b)
     */
	static float randomFloat(float a, float b);
};

