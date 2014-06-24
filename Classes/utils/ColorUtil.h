#pragma once
#include "cocos2d.h"
USING_NS_CC;
class ColorUtil
{
public:
	ColorUtil(void);
	~ColorUtil(void);
	static ccColor4F getColor4F(int r, int g, int b, int alpha);
};

