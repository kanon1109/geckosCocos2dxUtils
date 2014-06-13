#pragma once
#ifndef _DROP_EFFECT_
#define _DROP_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
class DropEffect :public CCNode
{
public:
	DropEffect();
	~DropEffect();

	//************************************
	// Description:创建
	// Parameter: float floorPosY	底板位置
	// Parameter: float fps			帧频
	// Returns:   DropEffect*		
	//************************************
	static DropEffect* create(float floorPosY = 0, float fps = .01f);

	//初始化
	bool init(float floorPosY, float fps);
	//************************************
	// Description:显示掉落效果
	// Parameter: const char*		资源地址
	// Parameter: int count			掉落物品的数量
	// Parameter: float x			x坐标
	// Parameter: float y			y坐标
	// Parameter: float gravity		重力
	// Parameter: float elasticity	弹性
	// Parameter: float minVx		最小横向速度
	// Parameter: float maxVx		最大横向速度
	// Parameter: float minVy		最小纵向速度
	// Parameter: float maxVy		最大横向速度
	// Returns:   void
	//************************************
	void drop(const char* pszFileName, 
				int count = 5, 
				float x = 0,
				float y = 0,
				float gravity = .9, 
				float elasticity = .4, 
				float minVx = -5, float maxVx = 5, 
				float minVy = 4, float maxVy = 10);
	//循环
	void loop(float dt);
private:
	//掉落物品列表
	CCArray* itemList;
	//帧频
	float fps;
	//地面坐标
	float floorPosY;
};

//掉落物品
class DropItem :public CCSprite
{
public:
	DropItem();
	~DropItem();

	//************************************
	// Description:创建掉落物品
	// Parameter: const char * pszFileName	掉落物品的资源
	// Parameter: float gravity				重力
	// Parameter: float elasticity			弹性
	// Returns:   DropItem*
	//************************************
	static DropItem* create(const char* pszFileName, float gravity, float elasticity, float floorPosY);

	//************************************
	// Description:初始化
	// Parameter: int gravity		重力
	// Parameter: int elasticity	弹性
	// Returns:   bool	
	//************************************
	bool init(float gravity , float elasticity, float floorPosY);
	//横向速度
	float vx;
	//纵向速度
	float vy;
	//重力
	float gravity;
	//弹性
	float elasticity;
	//地面高度
	float floorPosY;
	//更新方法
	void update();
};
#endif
