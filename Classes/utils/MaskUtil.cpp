#include "MaskUtil.h"

MaskUtil::MaskUtil()
{
}

MaskUtil::~MaskUtil()
{
}

CCSprite* MaskUtil::createMaskedSprite(CCSprite* src, CCSprite* mask, bool sameSize)
{
	assert(src);
	assert(mask);

	CCSize srcContent = src->getContentSize();

	CCRenderTexture * rt = CCRenderTexture::create(srcContent.width, srcContent.height, kTexture2DPixelFormat_RGBA8888);
	//判断遮罩是否需要和原始图片一样大小
	if (sameSize)
	{
		CCSize maskContent = mask->getContentSize();
		float ratiow = srcContent.width / maskContent.width;
		float ratioh = srcContent.height / maskContent.height;
		mask->setScaleX(ratiow);
		mask->setScaleY(ratioh);
	}

	//绘制位置归零
	mask->setPosition(ccp(srcContent.width / 2, srcContent.height / 2));
	src->setPosition(ccp(srcContent.width / 2, srcContent.height / 2));

	//设置混合模式
	ccBlendFunc blendFunc2 = { GL_ONE, GL_ZERO };
	mask->setBlendFunc(blendFunc2);
	ccBlendFunc blendFunc3 = { GL_DST_ALPHA, GL_ZERO };
	src->setBlendFunc(blendFunc3);
	//开始绘制
	rt->begin();
	mask->visit();
	src->visit();
	rt->end();
	//获取绘制后的sprite
	CCSprite * retval = CCSprite::createWithTexture(rt->getSprite()->getTexture());
	//翻转新绘制的sprite（因为绘制出的精灵上下颠倒）
	retval->setFlipY(true);
	return retval;
}
