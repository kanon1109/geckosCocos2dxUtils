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

int Random::randrange( int start, int stop, int step/*=1*/ )
{
	if (step <= 0) step = 1;
	int width = stop - start;
	if (width == 0) return start;
	if (width < 0) width = start - stop;
	int n = (int)((width + step - 1) / step);
	return (int)(CCRANDOM_0_1() * n) * step + min(start, stop);
}
