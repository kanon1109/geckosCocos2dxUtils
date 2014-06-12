#include "GetMoveSpeed.h"
static float prevX = 0;
static float prevY = 0;
GetMoveSpeed::GetMoveSpeed()
{
}

GetMoveSpeed::~GetMoveSpeed()
{
}

void GetMoveSpeed::initPos(float x, float y)
{
	prevX = x;
	prevY = y;
}

float GetMoveSpeed::getSpeed(float x, float y)
{
	float xSpeed = abs(x - prevX);
	float ySpeed = abs(y - prevY);
	prevX = x;
	prevY = y;
	return xSpeed + ySpeed;
}
