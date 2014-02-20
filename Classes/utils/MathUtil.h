#pragma once
#ifndef _MATH_UTIL_
#define _MATH_UTIL_
#include <vector>
using namespace std;
using std::vector;
class MathUtil
{
public:
	MathUtil();
	~MathUtil();
	/**
	* 修正数字 在一个范围内
	* @param	num     需要修正的数字
	* @param	min     最小的范围
	* @param	range   最大范围
	* @return  修正后的数字
	*/
	static float fixNumber(float num, float min, float range);

	/**
	* 标准化角度值，将传入的角度值返回成一个确保落在 0 ~ 360 之间的数字。
	*
	* <pre>
	* MathUtil::fixAngle(380); // 返回 20
	* MathUtil::fixAngle(-340); // 返回 20
	* </pre>
	*
	* 该方法详情可查看 《Flash MX 编程与创意实现》的第69页。
	*/
	static float fixAngle(float angle);

	/**
	* 求取阶乘
	* @param	num     求阶层的值
	*/
	static unsigned int getFactorial(unsigned int num);

	/**
	* 斜率公式
	* @param	x1 坐标点
	* @param	y1
	* @param	x2
	* @param	y2
	* @return  相应的斜率
	*/
	static float getSlope(float x1, float x2, float y1, float y2);

	/**
	* 弧度转换成角度  radians -> degrees
	*
	* @param radians 弧度
	* @return 相应的角度
	*/
	static float rds2dgs(float radians);

	/**
	* 角度转换成弧度 degrees -> radians
	*
	* @param degrees 角度
	* @return 相应的弧度
	*/
	static float dgs2rds(float degrees);
	
	/**
	* 已知3边求出某边对应的角的角度
	* CosC=(a^2+b^2-c^2)/2ab
	* CosB=(a^2+c^2-b^2)/2ac
	* CosA=(c^2+b^2-a^2)/2bc
	*
	* @param	vect 存放三个对应的角度的vect
	* @param	a 边
	* @param	b 边
	* @param	c 边
	*/
	static void MathUtil::threeSidesMathAngle(vector<float>&vect, float a, float b, float c);

	/**
	* 坐标旋转公式
	* @param	vect		坐标vect
	* @param	cx			中心点x坐标
	* @param	cy			中心点y坐标
	* @param	x			需要旋转的物体的x坐标
	* @param	y			需要旋转的物体的y坐标
	* @param	sin			sin(旋转角度);
	* @param	cos			cos(旋转角度);
	* @param	reverse		是否逆时针旋转
	*/
	static void MathUtil::rotate(vector<float>&vect, float cx, float cy,
									float tx, float ty,
									float angle, bool reverse);
};
#endif
