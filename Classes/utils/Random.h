#pragma once
#ifndef _RANDOM_INIT_
#define _RANDOM_INIT_
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

	/**
     * 返回a 到 b直间的随机整数，包括 a 和 b
     * @param a
     * @param b
     * @return [a, b] 直接的随机整数
     */
	static int randomInt(int a, int b);

	/**
     * 在 start 与 stop之间取一个随机整数，可以用step指定间隔， 但不包括较大的端点（start与stop较大的一个）
     * 如 
     * Random::randrange(1, 10, 3) 
     * 则返回的可能是   1 或  4 或  7  , 注意 这里面不会返回10，因为是10是大端点
     * 
     * @param start
     * @param stop
     * @param step
     * @return 假设 start < stop,  [start, stop) 区间内的随机整数
     */
	static int randrange(int start, int stop, int step=1);

	/**
	 * 计算概率
	 * @param	chance 概率
	 * @return	概率是否中
	 */
	static bool boolean(float chance=.5f);
};
#endif
