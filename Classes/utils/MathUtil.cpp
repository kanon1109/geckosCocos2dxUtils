#include "MathUtil.h"
#include "math.h"

MathUtil::MathUtil()
{
}


MathUtil::~MathUtil()
{
}

float MathUtil::fixNumber(float num, float min, float range)
{
	(float)num = (int)num % (int)range;
	if (num < min)
		return num + range;
	return num;
}

float MathUtil::fixAngle(float angle)
{
	return MathUtil::fixNumber(angle, 0, 360);
}

unsigned int MathUtil::getFactorial(unsigned int num)
{
	if (num == 0) return 1;
	return num * MathUtil::getFactorial(num - 1);
}

float MathUtil::getSlope(float x1, float x2, float y1, float y2)
{
	float slope = (y1 - y2) / (x1 - x2);
	return slope;
}

float MathUtil::rds2dgs(float radians)
{
	return fixAngle(radians * 180 / M_PI);
}

float MathUtil::dgs2rds(float degrees)
{
	return degrees * M_PI / 180;
}

void MathUtil::threeSidesMathAngle(vector<float>&vect, float a, float b, float c)
{
	float cosA = (c * c + b * b - a * a) / (2 * b * c);
	float A = round(MathUtil::rds2dgs(acos(cosA)));

	float cosB = (a * a + c * c - b * b) / (2 * a * c);
	float B = round(MathUtil::rds2dgs(acos(cosB)));

	float cosC = (a * a + b * b - c * c) / (2 * a * b);
	float C = round(MathUtil::rds2dgs(acos(cosC)));
	
	vect.clear();
	vect.push_back(A);
	vect.push_back(B);
	vect.push_back(C);
}

void MathUtil::rotate(vector<float>&vect, float cx, float cy, 
						float tx, float ty, 
						float angle, bool reverse)
{
	float x;
	float y;
	float dx = tx - cx;
	float dy = ty - cy;
	float c = cos(MathUtil::dgs2rds(angle));
	float s = sin(MathUtil::dgs2rds(angle));
	if (reverse)
	{
		x = dx * c + dy * s + cx;
		y = dy * c - dx * s + cy;
	}
	else
	{
		x = dx * c - dy * s + cx;
		y = dy * c + dx * s + cy;
	}
	vect.clear();
	vect.push_back(x);
	vect.push_back(y);
}


