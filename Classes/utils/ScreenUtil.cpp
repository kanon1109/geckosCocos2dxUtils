#include "ScreenUtil.h"
#include "cocos2d.h"
USING_NS_CC;

ScreenUtil::ScreenUtil()
{
}


ScreenUtil::~ScreenUtil()
{
}

void ScreenUtil::setScreenSize(float width, float height, bool isFixHeight /*= true*/)
{
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	CCSize frameSize = pEGLView->getFrameSize();
	CCLOG("frameSize %f; %f", frameSize.width, frameSize.height);
	CCSize vSize = CCSizeMake(960, 640);
	float scaleX = (float)frameSize.width / vSize.width;
	float scaleY = (float)frameSize.height / vSize.height;
	float scale = MAX(scaleX, scaleY);
	if (isFixHeight)
	{
		// 固定高度
		if (scaleX > scaleY) scale = scaleX / (frameSize.height / (float)vSize.height);
		else scale = scaleX / (frameSize.width / (float)vSize.width);
	}
	else
	{
		// 固定宽度
		if (scaleX > scaleY) scale = scaleY / (frameSize.height / (float)vSize.height);
		else scale = scaleY / (frameSize.width / (float)vSize.width);
	}
	CCLOG("scaleX, scaleY %f;%f", scaleX, scaleY);
	CCLOG("scale%f", scale);
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(vSize.width * scale, vSize.height * scale, kResolutionNoBorder);
}
