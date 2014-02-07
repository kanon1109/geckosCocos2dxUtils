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
