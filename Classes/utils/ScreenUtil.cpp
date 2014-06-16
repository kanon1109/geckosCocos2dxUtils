#include "ScreenUtil.h"
#include "cocos2d.h"
USING_NS_CC;
static CCPoint leftTop;		//左上边屏幕坐标
static CCPoint leftBottom;	//左下边屏幕坐标
static CCPoint rightTop;	//右边屏幕坐标
static CCPoint rightBottom;	//右边屏幕坐标
static CCPoint center;		//中心点屏幕坐标
//屏幕参考大小
static float screenReferenceWidth;
static float screenReferenceHeight;
ScreenUtil::ScreenUtil()
{
}

ScreenUtil::~ScreenUtil()
{
}

void ScreenUtil::setScreenSize(float width /*= 960*/, float height /*= 640*/, bool isFixHeight /*= true*/)
{
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	CCSize frameSize = pEGLView->getFrameSize();
	screenReferenceWidth = width;
	screenReferenceHeight = height;
	CCLOG("frameSize %f; %f", frameSize.width, frameSize.height);
	CCSize vSize = CCSizeMake(width, height);
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

	CCDirector* pDirector = CCDirector::sharedDirector();
	CCPoint visibleOrigin = pDirector->getVisibleOrigin();
	CCSize visibleSize = pDirector->getVisibleSize();
	leftBottom = ccp(visibleOrigin.x, visibleOrigin.y);
	leftTop = ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height);
	rightBottom = ccp(visibleOrigin.x + visibleSize.width, visibleOrigin.y);
	rightTop = ccp(visibleOrigin.x + visibleSize.width, visibleOrigin.y + visibleSize.height);
	center = ccp(visibleOrigin.x + (rightTop.x - leftTop.x) * .5, 
				visibleOrigin.y + (rightTop.y - rightBottom.y) * .5);
}

CCPoint ScreenUtil::getCenter()
{
	return center;
}

CCPoint ScreenUtil::getLeftTop()
{
	return leftTop;
}

CCPoint ScreenUtil::getLeftBottom()
{
	return leftBottom;
}

CCPoint ScreenUtil::getRightTop()
{
	return rightTop;
}

CCPoint ScreenUtil::getRightBottom()
{
	return rightBottom;
}

float ScreenUtil::getLeft()
{
	return leftTop.x;
}

float ScreenUtil::getRight()
{
	return rightTop.x;
}

float ScreenUtil::getBottom()
{
	return leftBottom.y;
}

float ScreenUtil::getTop()
{
	return leftTop.y;
}

cocos2d::CCPoint ScreenUtil::getScreenPoint(float x, float y)
{
	return ccp(getScreenX(x), getScreenY(y));
}

float ScreenUtil::getScreenX( float x )
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
	return visibleOrigin.x + x / screenReferenceWidth * visibleSize.width; 
}

float ScreenUtil::getScreenY( float y )
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
	return  visibleOrigin.y + y / screenReferenceHeight * visibleSize.height;
}

float ScreenUtil::getScreenWidth()
{
	return CCDirector::sharedDirector()->getVisibleSize().width;
}

float ScreenUtil::getScreenHeight()
{
	return CCDirector::sharedDirector()->getVisibleSize().height;
}






