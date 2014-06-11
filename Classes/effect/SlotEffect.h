#pragma once
#ifndef	_SLOT_EFFECT_
#define _SLOT_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
//老虎机效果（纯数据）
class SlotEffect :public CCNode
{
public:
	SlotEffect();
	~SlotEffect();

	//************************************
	// Description:初始化老虎机效果
	// Parameter: int curIndex	初始化的位置索引。
	// Parameter: int maxIndex	总的索引数量。
	// Parameter: int loop		快速模式的滚动次数。在快速滚动次数达到后会有一次慢速滚动。所以总滚动次数是loop + 1
	// Parameter: float delay	运行间隔 毫秒
	// Parameter: int gapIndex	触发慢速滚动之前的索引
	// Parameter: int addDelay	间隔增量
	// Returns:   是否初始化
	//************************************
	virtual bool init(int curIndex, int maxIndex, int loop = 1, float delay = 50, int gapIndex = 5, int addDelay = 200);
	//创建
	static SlotEffect* create(int curIndex, int maxIndex, int loop = 1, float delay = 50, int gapIndex = 5, int addDelay = 200);
	//开始
	void start(int targetIndex, bool reverse = false);
	//暂停
	void pause();
	//获取当前索引
	int getCurIndex();
	//获取当前随机索引
	int getRandomIndex();
	//************************************
	// Description:添加监听
	// Parameter: CCObject* target	指针调用回调函数的指针
	// Parameter: SEL_CallFunc func	回调方法
	// Returns:   void
	//************************************
	void addEventListener(CCObject* target, SEL_CallFunc func);
private:
	//初始化的位置索引
	int m_curIndex;
	//总的索引数量
	int m_maxIndex;
	//快速模式的滚动次数
	int m_loop;
	//运行间隔
	float m_delay;
	//触发慢速滚动之前的索引
	int m_gapIndex;
	//是否进入慢速状态
	bool isSlowing;
	//目标索引
	int m_targetIndex;
	//慢速滚动的开始索引
	int m_slowIndex;
	//是否逆时针
	bool m_reverse;
	//随机索引
	int m_randomIndex;
	//当前计时器的计数器
	int currentCount;
	//增加的间隔
	int addDelay;
	//事件目标
	CCObject* m_target;
	//方法回调
	SEL_CallFunc func;
	//更新方法
	void update(float dt);
	//************************************
	// Description: 修正数字 在一个范围内
	// Parameter: float num		需要修正的数字
	// Parameter: float min		最小的范围
	// Parameter: float range	最大范围
	// Returns:   float			修正后的数字
	//************************************
	float fixNumber(float num, float min, float range);
};

#endif