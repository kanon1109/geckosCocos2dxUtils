#pragma once
#ifndef _MATH_UTIL_
#define _MATH_UTIL_
#include <vector>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
using std::vector;
#ifndef CC_PLATFORM_WIN32
#include <math.h>
#endif
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
     * 已知一个角度以及角度对应的边长 可以求出三角外接圆半径R的2倍
	 * 正弦公式
	 * a/sinA=b/sinB=c/sinC=2R
     * @param	angle               角度
     * @param	line                角对应的变长
     * @return  三角外接圆半径R
     */
	static float sineLaw(float angle, float line);

	/**
     * 求出直角坐标系 三角形的重心
     * @param	a      三角形顶点a
     * @param	b      三角形顶点b
     * @param	c      三角形顶点c
     * @return  三角形的重心
     */
	static CCPoint triangleCentroid(CCPoint a, CCPoint b, CCPoint c);

	/**
     * 求出直角坐标系 三角形外接圆中心坐标
     * x = ((y2 - y1) * (y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1) - 
     *      (y3 - y1) * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1)) / 
     *      (2 * (x3 - x1) * (y2 - y1) - 2 * ((x2 - x1) * (y3 - y1))); 
     * 
     * y = ((x2 - x1) * (x3 * x3 - x1 * x1 + y3 * y3 - y1 * y1) - 
     *      (x3 - x1) * (x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1)) / 
     *      (2 * (y3 - y1) * (x2 - x1) - 2 * ((y2 - y1) * (x3 - x1)));
     * @param	a      三角形顶点a
     * @param	b      三角形顶点b
     * @param	c      三角形顶点c
     * @return  外接圆中心坐标
     */
	static CCPoint triangleCircumscribedCircleCenter(CCPoint a, CCPoint b, CCPoint c);
	
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
	static void threeSidesMathAngle(vector<float>&vect, float a, float b, float c);

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
	static void rotate(vector<float>&vect, float cx, float cy,
									float tx, float ty,
									float angle, bool reverse);

	/**
	 * 根据项数和公差求出等差数列项数所对应的值 
	 * @param	sn  n项的和
	 * @param	d   公差
	 * @return  项数所对应的值
	 */
	static float arithmeticSequenceIndexValue(unsigned int sn, unsigned int d);

	/**
	 * 根据数列的和求出等差数列项的次数
	 * @param	sn  n项的和
	 * @param	d   公差
	 * @return  项的次数
	 */
	static unsigned int arithmeticSequenceIndex(unsigned int sn, unsigned int d);

	/**
	 * 计算距离
	 * @param	x1	点1的x坐标
	 * @param	y1	点1的y坐标
	 * @param	x2	点2的x坐标
	 * @param	y2	点2的y坐标
	 * @return	2点之间的距离
	 */
	static float distance(float x1, float y1, float x2, float y2);

	/**
	 * 获取整数的位数	
	 * MathUtil::getIntLength(1000)  4;
	 * @param	num	需要获取位数的整数
	 * @return	位数
	 */
	static double getIntLength(double num);

	//************************************
	// Method:    isInsideTriangle	判断点是否在任意三角形内部
	// Parameter: CCPoint a			三角形点a
	// Parameter: CCPoint b			三角形点b
	// Parameter: CCPoint c			三角形点c
	// Parameter: CCPoint p			三角形点p
	// Returns:   bool				是否在三角形内部
	//************************************
	static bool isInsideTriangle(CCPoint a, CCPoint b, CCPoint c, CCPoint p);

	//************************************
	// Method:    triangleArea	求三角形面积
	// Parameter: CCPoint a		点a
	// Parameter: CCPoint b		点b
	// Parameter: CCPoint c		点c
	// Returns:   float			面积
	//************************************
	static float triangleArea(CCPoint a, CCPoint b, CCPoint c);

	//************************************
	// Method:    isInsideSquare	判断点是否在一个矩形范围内（矩形可旋转）点必须是顺时针
	// Parameter: CCPoint a			点a
	// Parameter: CCPoint b			点b
	// Parameter: CCPoint c			点c
	// Parameter: CCPoint d			点d
	// Parameter: CCPoint p			点坐标
	// Returns:   bool				是否在一个矩形范围内
	//************************************
	static bool isInsideSquare(CCPoint a, CCPoint b, CCPoint c, CCPoint d, CCPoint p);

private:
	static int sign(float n);
};
#endif
