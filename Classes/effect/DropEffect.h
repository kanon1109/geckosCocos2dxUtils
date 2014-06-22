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
	// Parameter: const char* pszFileName	资源地址
	// Parameter: float floorPosY			底板位置
	// Parameter: float fps					帧频
	// Returns:   DropEffect*		
	//************************************
	static DropEffect* create(const char* pszFileName, float floorPosY = 0, float fps = .01f);

	//初始化
	bool init(const char* pszFileName, float floorPosY, float fps);
	//************************************
	// Description:显示掉落效果
	// Parameter: int count				掉落物品的数量
	// Parameter: float x				x坐标
	// Parameter: float y				y坐标
	// Parameter: float gravity			重力
	// Parameter: float elasticity		弹性
	// Parameter: float friction		摩擦系数（0-1）系数越大摩擦力越小
	// Parameter: float minDropHeight	最小下落高度
	// Parameter: float maxDropHeight	最大下落高度
	// Parameter: float minVx			最小横向速度
	// Parameter: float maxVx			最大横向速度
	// Parameter: float minVy			最小纵向速度
	// Parameter: float maxVy			最大横向速度
	// Returns:   void
	//************************************
	void drop(int count = 5,
			float x = 0,
			float y = 0,
			float gravity = .9,
			float elasticity = .4,
			float friction = 1,
			float minDropHeight = 0,
			float maxDropHeight = 0,
			float minVx = -5, float maxVx = 5,
			float minVy = 4, float maxVy = 10);
	//循环
	void loop(float dt);
private:
	//批量加载纹理的节点
	CCSpriteBatchNode* batchNode;
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
	// Parameter: CCTexture2D* texture			掉落物品的纹理
	// Parameter: float gravity					重力
	// Parameter: float elasticity				弹性
	// Parameter: float friction				摩擦力
	// Parameter: float floorPosY				底板位置
	// Parameter: float minDropHeight			最小下落高度
	// Parameter: float maxDropHeight			最大下落高度
	// Returns:   DropItem*
	//************************************
	static DropItem* create(CCTexture2D* texture,
							float gravity, 
							float elasticity, 
							float friction,
							float minDropHeight, 
							float maxDropHeight);

	//************************************
	// Description:初始化
	// Parameter: int gravity				重力
	// Parameter: int elasticity			弹性
	// Parameter: float friction			摩擦力
	// Parameter: float floorPosY			底板位置
	// Parameter: float minDropHeight		最小下落高度
	// Parameter: float maxDropHeight		最大下落高度
	// Returns:   bool	
	//************************************
	bool init(float gravity, float elasticity, float friction, float minDropHeight, float maxDropHeight);
	//更新方法
	void update();
	//设置底板位置
	void setFloorPos(float pos);
	//横向速度
	float vx;
	//纵向速度
	float vy;
private:
	//重力
	float gravity;
	//弹性
	float elasticity;
	//摩擦力
	float friction;
	//地面高度
	float floorPosY;
	//最小下落高度
	float minDropHeight;
	//最大下落高度
	float maxDropHeight;

	CCLabelTTF* text;
};
#endif
