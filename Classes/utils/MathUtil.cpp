#include "MathUtil.h"
#include <math.h>

MathUtil::MathUtil()
{
}


MathUtil::~MathUtil()
{
}

float MathUtil::fixNumber(float num, float min, float range)
{
	num = (int)num % (int)range;
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
	float A = MathUtil::rds2dgs(acos(cosA));

	float cosB = (a * a + c * c - b * b) / (2 * a * c);
	float B = MathUtil::rds2dgs(acos(cosB));

	float cosC = (a * a + b * b - c * c) / (2 * a * b);
	float C = MathUtil::rds2dgs(acos(cosC));

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

float MathUtil::sineLaw( float angle, float line )
{
	return line / sin(angle) / 2;
}

CCPoint MathUtil::triangleCentroid( CCPoint a, CCPoint b, CCPoint c )
{
	return ccp((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
}

unsigned int MathUtil::arithmeticSequenceIndex( unsigned int sn, unsigned int d )
{
	//前n项和公式为：Sn=n×a1+n×(n-1)×(d/2); 
	//等差数列分解因式公式
	//d/2×n^2-(1-d/2)×n-dis = 0
	//一元二次方程表示法 ax^2+bx+c = 0;
	//一元二次方程 带入公式法  x = -b+Math.sqrt(b^2-4ac)/2a;
	float hd = d * .5;
	float a = hd;
	float b = 1 - hd;
	int c = -(int)sn;
	return ( -b + sqrt(b * b - (4 * a * c))) / (2 * a);
}

float MathUtil::arithmeticSequenceIndexValue( unsigned int sn, unsigned int d )
{
	unsigned int n = MathUtil::arithmeticSequenceIndex(sn, d);
	return (n + 1) * d - (d - 1);
}

CCPoint MathUtil::triangleCircumscribedCircleCenter( CCPoint a, CCPoint b, CCPoint c )
{
	float axp =  pow(a.x, 2);
	float bxp =  pow(b.x, 2);
	float cxp =  pow(c.x, 2);

	float ayp =  pow(a.y, 2);
	float byp =  pow(b.y, 2);
	float cyp =  pow(c.y, 2);

	float x = ((b.y - a.y) * (cyp - ayp + cxp - axp) - (c.y - a.y) * (byp - ayp + bxp - axp)) / 
		(2 * (c.x - a.x) * (b.y - a.y) - 2 * ((b.x - a.x) * (c.y - a.y)));

	float y = ((b.x - a.x) * (cxp - axp + cyp - ayp) - (c.x - a.x) * (bxp - axp + byp - ayp)) / 
		(2 * (c.y - a.y) * (b.x - a.x) - 2 * ((b.y - a.y) * (c.x - a.x)));
	return ccp(x, y);
}

float MathUtil::distance( float x1, float y1, float x2, float y2 )
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double MathUtil::getIntLength(double num)
{
	return log10(num) + 1;
}

bool MathUtil::isInsideTriangle( CCPoint a, CCPoint b, CCPoint c, CCPoint p )
{
	float planeAB = (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
	float planeBC = (b.x - p.x) * (c.y - p.y) - (c.x - p.x) * (b.y - p.y);
	float planeCA = (c.x - p.x) * (a.y - p.y) - (a.x - p.x) * (c.y - p.y);
	return sign(planeAB) == sign(planeBC) && sign(planeBC) == sign(planeCA);
}

int MathUtil::sign( float n )
{
	return (int)(abs(n) / n);
}

float MathUtil::triangleArea( CCPoint a, CCPoint b, CCPoint c )
{
	return (c.x * b.y - b.x * c.y) - (c.x * a.y - a.x * c.y) + (b.x * a.y - a.x * b.y);
}

bool MathUtil::isInsideSquare( CCPoint a, CCPoint b, CCPoint c, CCPoint d, CCPoint p )
{
	if (MathUtil::triangleArea(a, b, p) > 0 || 
		MathUtil::triangleArea(b, c, p) > 0 || 
		MathUtil::triangleArea(c, d, p) > 0 || 
		MathUtil::triangleArea(d, a, p) > 0) 
		return false;
	return true;
}

void MathUtil::segmentsIntr(CCPoint a, CCPoint b, CCPoint c, CCPoint d, vector<float> &vect)
{
	vect.clear();
	float area_abc = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);

	// 三角形abd 面积的2倍  
	float area_abd = (a.x - d.x) * (b.y - d.y) - (a.y - d.y) * (b.x - d.x);

	// 面积符号相同则两点在线段同侧,不相交 (对点在线段上的情况,本例当作不相交处理);  
	if (area_abc * area_abd >= 0)
	{
		return;
	}

	// 三角形cda 面积的2倍  
	float area_cda = (c.x - a.x) * (d.y - a.y) - (c.y - a.y) * (d.x - a.x);
	// 三角形cdb 面积的2倍  
	// 注意: 这里有一个小优化.不需要再用公式计算面积,而是通过已知的三个面积加减得出.  
	float area_cdb = area_cda + area_abc - area_abd;
	if (area_cda * area_cdb >= 0)
	{
		return;
	}

	//计算交点坐标  
	float t = area_cda / (area_abd - area_abc);
	float dx = t * (b.x - a.x);
	float dy = t * (b.y - a.y);

	//存放坐标
	vect.push_back(a.x + dx);
	vect.push_back(a.y + dy);
}











