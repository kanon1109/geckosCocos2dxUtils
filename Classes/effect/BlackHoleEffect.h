#pragma once
#ifndef _BLACK_HOLE_EFFECT_
#define _BLACK_HOLE_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
//进入黑洞回调
typedef void (CCObject::*SEL_IN_HOLE_SELECTOR)(CCObject*);
#define in_hole_selector(_SELECTOR) (SEL_IN_HOLE_SELECTOR)(&_SELECTOR)
//黑洞衰减消息回调
typedef void (CCObject::*SEL_ATTENUATION_SELECTOR)(CCObject*);
#define attenuation_selector(_SELECTOR) (SEL_ATTENUATION_SELECTOR)(&_SELECTOR)
//结束消息回调
typedef void (CCObject::*SEL_OVER_SELECTOR)(CCObject*);
#define over_selector(_SELECTOR) (SEL_OVER_SELECTOR)(&_SELECTOR)
class BlackHoleEffect:public CCNode
{
public:
	BlackHoleEffect();
	~BlackHoleEffect();

	//************************************
	// Description:创建黑洞
	// Parameter: float g			重力
	// Parameter: float range		影响范围
	// Parameter: float angleSpeed	角速度
	// Parameter: int time			持续时间
	// Parameter: int fps			帧频
	// Returns:   BlackHoleEffect*	黑洞	
	//************************************
	static BlackHoleEffect* create(float g = 10.0f, float range = 400.0f, 
								   float angleSpeed = 5.0f, int time = 2000, 
								   int fps = 60);

	//************************************
	// Description:创建黑洞
	// Parameter: float g			重力
	// Parameter: float range		影响范围
	// Parameter: float angleSpeed	旋转时的角速度
	// Parameter: int time			持续时间
	// Parameter: int fps			帧频
	// Returns:   BlackHoleEffect*	黑洞	
	//************************************
	bool init(float g = 10.0f, float range = 400.0f,
			  float angleSpeed = 5.0f, int time = 2000,
			  int fps = 60);

	//************************************
	// Description:添加黑洞
	// Parameter: float holePosX	黑洞位置x
	// Parameter: float holePosY	黑洞位置y
	// Returns:   void
	//************************************
	void addHole(float holePosX, float holePosY);

	//************************************
	// Description:添加物质列表
	// Parameter: CCArray * ary
	// Returns:   void
	//************************************
	void addSubstanceList(CCArray* ary);

	//************************************
	// Description:计算距离
	// Parameter: float x1	点1的x坐标
	// Parameter: float y1	点1的y坐标
	// Parameter: float x2	点2的x坐标
	// Parameter: float y2	点2的y坐标
	// Returns:   float		距离
	//************************************
	float mathDistance(float x1, float y1, float x2, float y2);

	//更新
	void update();

	//添加进入黑洞监听
	void setInHoleSelector(CCObject* target, SEL_IN_HOLE_SELECTOR inHoleComplete);

	//添加黑洞衰减消息监听
	void setAttenuationSelector(CCObject* target, SEL_ATTENUATION_SELECTOR attenuationComplete);

	//添加结束消息监听
	void setOverSelector(CCObject* target, SEL_OVER_SELECTOR overComplete);
private:
	//重力
	float g;
	//影响范围
	float range;
	//旋转时的角速度
	float angleSpeed;
	//持续时间
	int time;
	//帧频
	int fps;
	//黑洞位置
	float holePosX;
	float holePosY;
	//是否开启黑洞
	bool isStart;
	//是否结束
	bool isOver;
	//最短距离
	int minDis;
	//持续时间（帧）
	int timeFrame;
	//结束后缓动时间（毫秒）
	int overTime;
	//结束后缓动时间（帧）
	int overTimeFrame;
	//物质列表存放被吸引的物质
	CCArray* subList;
	//摩擦力
	float f;
	//进入黑洞回调方法
	SEL_IN_HOLE_SELECTOR inHoleCompleteFun;
	//黑洞衰减回调方法
	SEL_ATTENUATION_SELECTOR attenuationCompleteFun;
	//结束消息回调方法
	SEL_OVER_SELECTOR overCompleteFun;
	//回调方法的目标
	CCObject* target;
};
#endif
