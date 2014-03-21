#pragma once
#ifndef _SCREEN_UTIL_
#define _SCREEN_UTIL_
#include "cocos2d.h"
USING_NS_CC;
class ScreenUtil
{
public:
	ScreenUtil();
	~ScreenUtil();
	/**
	* иХжцфад╩╢Сп║
	* @width	фад╩©М╤х
	* @height	фад╩╦ъ╤х
	*/
	static void setScreenSize(float width = 960, float height = 640, bool isFixHeight = true);

	/*фад╩жппд╣ЦвС╠ъ*/
	static CCPoint getCenter();

	/*фад╩вСио╫гвС╠ъ*/
	static CCPoint getLeftTop();

	/*фад╩вСоб╫гвС╠ъ*/
	static CCPoint getLeftBottom();

	/*фад╩срио╫гвС╠ъ*/
	static CCPoint getRightTop();
	
	/*фад╩сроб╫гвС╠ъ*/
	static CCPoint getRightBottom();

	static float getLeft();

	static float getRight();

	static float getBottom();

	static float getTop();
};
#endif
