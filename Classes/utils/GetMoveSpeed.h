#pragma once
#ifndef _GET_MOUSE_SPEED_
#define _GET_MOUSE_SPEED_
#include "cocos2d.h"
USING_NS_CC;
class GetMoveSpeed
{
public:
	GetMoveSpeed();
	~GetMoveSpeed();

	//************************************
	// Description: 初始化鼠标位置
	// Parameter: float x	x坐标
	// Parameter: float y	y坐标
	// Returns:   void
	//************************************
	static void initPos(float x, float y);
	
	//************************************
	// Description:获取滑动速度
	// Parameter: float x	当前滑动的x位置
	// Parameter: float y	当前滑动的y位置
	// Returns:   float		当前滑动的速度
	//************************************
	static float getSpeed(float x, float y);
};
#endif