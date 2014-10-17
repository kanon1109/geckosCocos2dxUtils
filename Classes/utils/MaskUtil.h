#pragma once
#ifndef _MASK_UTIL_
#define _MASK_UTIL_
#include "cocos2d.h"
USING_NS_CC;
class MaskUtil
{
public:
	MaskUtil();
	~MaskUtil();

	//************************************
	// Description: 创建遮罩
	// Parameter: CCSprite * src		需要被遮罩的精灵
	// Parameter: CCSprite * mask		遮罩精灵
	// Parameter: bool sameSize			返回的新的遮罩精灵是否和被遮罩的精灵大小小同
	// Returns:   CCSprite*				重新绘制被遮罩精灵
	//************************************
	static CCSprite* createMaskedSprite(CCSprite* src, CCSprite* mask, bool sameSize = false);
};
#endif
