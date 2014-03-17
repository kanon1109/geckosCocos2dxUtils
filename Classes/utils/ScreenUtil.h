#pragma once
class ScreenUtil
{
public:
	ScreenUtil();
	~ScreenUtil();
	/**
	* 设置屏幕大小
	* @width	屏幕宽度
	* @height	屏幕高度
	*/
	static void setScreenSize(float width, float height, bool isFixHeight = true);
};

