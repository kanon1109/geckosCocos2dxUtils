#include "ShadowLabel.h"

ShadowLabel::ShadowLabel()
: pShadowTTF_(NULL)
{

}

ShadowLabel::~ShadowLabel()
{

}

ShadowLabel * ShadowLabel::create(const char *string, const char *fontName, float fontSize)
{
	return ShadowLabel::create(string, fontName, fontSize, CCSizeZero, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
}

ShadowLabel * ShadowLabel::create(const char *string, const char *fontName, float fontSize, const CCSize& dimensions, CCTextAlignment hAlignment)
{
	return ShadowLabel::create(string, fontName, fontSize, dimensions, hAlignment, kCCVerticalTextAlignmentTop);
}

ShadowLabel * ShadowLabel::create(const char *string, const char *fontName, float fontSize, const CCSize& dimensions, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment)
{
	ShadowLabel *pRet = new ShadowLabel();
	if (pRet && pRet->initWithString(string, fontName, fontSize, dimensions, hAlignment, vAlignment))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void ShadowLabel::setShadowColor(const ccColor3B &shadowColor /*= ccBLACK*/)
{
	do 
	{
		CCSize size = getContentSize();
		CCPoint anchorPos = getAnchorPoint();
		pShadowTTF_ = CCLabelTTF::create(getString(), getFontName(), getFontSize(), getDimensions(), getHorizontalAlignment(), getVerticalAlignment());
		CC_BREAK_IF(!pShadowTTF_);
		pShadowTTF_->setColor(shadowColor);
		pShadowTTF_->setAnchorPoint(anchorPos);
		pShadowTTF_->setPosition(ccp(size.width*anchorPos.x + 2.0f, size.height*anchorPos.y - 2.0f));
		addChild(pShadowTTF_, getZOrder() - 1);

	} while (false);
}

void ShadowLabel::setString(const char *label)
{
	CCLabelTTF::setString(label);
	if (pShadowTTF_)
	{
		CCSize size = getContentSize();
		CCPoint anchorPos = getAnchorPoint();
		pShadowTTF_->setString(label);
		pShadowTTF_->setAnchorPoint(anchorPos);
		pShadowTTF_->setPosition(ccp(size.width*anchorPos.x + 2.0f, size.height*anchorPos.y - 2.0f));
	}
}

void ShadowLabel::setFontSize(float fontSize)
{
	CCLabelTTF::setFontSize(fontSize);
	if (pShadowTTF_)
	{
		CCSize size = getContentSize();
		CCPoint anchorPos = getAnchorPoint();
		pShadowTTF_->setFontSize(fontSize);
		pShadowTTF_->setAnchorPoint(anchorPos);
		pShadowTTF_->setPosition(ccp(size.width*anchorPos.x + 2.0f, size.height*anchorPos.y - 2.0f));
	}
}
