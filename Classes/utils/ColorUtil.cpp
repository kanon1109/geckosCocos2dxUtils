#include "ColorUtil.h"


ColorUtil::ColorUtil(void)
{
}


ColorUtil::~ColorUtil(void)
{
}

/*获取ccColorf的颜色对象*/
ccColor4F ColorUtil::getColor4F(int r,int g,int b,int alpha)
{
	ccColor4F c4 = {r/255.f, g/255.f, b/255.f, alpha/255.f};
	return c4;
}