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
	CREATE_FUNC(DropEffect);
	//************************************
	// Description:显示掉落效果
	// Parameter: const char*		资源地址
	// Parameter: int count			掉落物品的数量
	// Parameter: float gravity		重力
	// Parameter: float elasticity	弹性
	// Parameter: float minVx		最小横向速度
	// Parameter: float maxVx		最大横向速度
	// Parameter: float minVy		最小纵向速度
	// Parameter: float maxVy		最大横向速度
	// Returns:   void
	//************************************
	void drop(const char* pszFileName, 
				int count, float gravity = 1, 
				float elasticity = .9, float minVx = -5, 
				float maxVx = 5, float minVy = 10, float maxVy = 20);
	//循环
	void loop(float dt);
private:
	//掉落物品列表
	CCArray* itemList;
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
	static DropItem* create(const char* pszFileName, float gravity = 1, float elasticity = .9);

	//************************************
	// Description:初始化
	// Parameter: int gravity
	// Parameter: int elasticity
	// Returns:   bool
	//************************************
	bool init(float gravity = 1, float elasticity = .9);
	//横向速度
	float vx;
	//纵向速度
	float vy;
	//重力
	float gravity;
	//弹性
	float elasticity;
	//更新方法
	void update();
};
#endif
