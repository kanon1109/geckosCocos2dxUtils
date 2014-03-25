#include "Random.h"
USING_NS_CC;
Random::Random(void)
{
}

Random::~Random(void)
{
}

float Random::randomFloat( float a, float b )
{
	return CCRANDOM_0_1() * (b - a) + a;
}

int Random::randomInt( int a, int b )
{
	if (a > b) a++;
	else b++;
	return Random::randrange(a, b);
}

int Random::randrange( int start, int stop, unsigned int step/*=1*/ )
{
	if (step == 0) step = 1;
	int width = stop - start;
	if (width == 0) return start;
	if (width < 0) width = start - stop;
	int n = (int)((width + step - 1) / step);
	return (int)(CCRANDOM_0_1() * n) * step + min(start, stop);
}

bool Random::boolean( float chance/*=.5f*/ )
{
	return (CCRANDOM_0_1() < chance) ? true : false;
}

void Random::initRandomSeed()
{
	//设置随机数种子
	const time_t t = time(NULL);
	srand(unsigned(time(NULL)));
}

void Random::initRandomSeed(unsigned int seed)
{
	srand(seed);
}
