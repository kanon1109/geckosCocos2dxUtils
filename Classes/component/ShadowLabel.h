/********************************************************************
	created:	2014/07/25
	file base:	shadowLabel
	file ext:	h
	author:		fox
	purpose:	画带阴影的label
*********************************************************************/
#ifndef __SHADOWLABEL_H_FILE__
#define __SHADOWLABEL_H_FILE__

#include "cocos2d.h"

USING_NS_CC;

class ShadowLabel : public CCLabelTTF
{
public:
	ShadowLabel();
	~ShadowLabel();

	CREATE_FUNC(ShadowLabel);

	static ShadowLabel * create(const char *string, const char *fontName, float fontSize);
	static ShadowLabel * create(const char *string, const char *fontName, float fontSize, const CCSize& dimensions, CCTextAlignment hAlignment);
	static ShadowLabel * create(const char *string, const char *fontName, float fontSize, const CCSize& dimensions, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment);
public:
	/**  [7/25/2014 hjw]
	 * @desc:	设置阴影颜色
	 * @param:	shadowColor阴影颜色
	 * @return: 无
	 **/
	void setShadowColor(const ccColor3B &shadowColor = ccBLACK);

	virtual void setString(const char *label);

	/**  [10/13/2014 yong]
	* @desc:	设置字体大小（原字体及阴影）
	* @param:	字体大小
	* @return: 无
	**/
	virtual void setFontSize(float fontSize);
private:
	CCLabelTTF *pShadowTTF_;
};

#endif