#ifndef __CCSTROKE_LABEL_TF
#define __CCSTROKE_LABEL_TF
#pragma once
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class CCStrokeLabelTTF : public CCNodeRGBA, public CCLabelProtocol
{
public:
	CCStrokeLabelTTF();
	~CCStrokeLabelTTF();

	/**
	 * create a stroke label
	 */
	static CCStrokeLabelTTF*	create(const char* string, const char* fontName, int fontSize, ccColor3B color, ccColor3B strokeColor, int strokeSize = 3);
	
	/**
	 * set label content
	 */
	void						setString(const char *label);

	/**
	 * get label content
	 */
	const char*					getString(void);

	void						setAnchorPoint(const CCPoint& anchorPoint);
private:
	/**
	 * init
	 */
	bool						initWithString(const char *label, const char *fontName, int fontSize, ccColor3B color, ccColor3B strokeColor, int strokeSize = 3);
	string						m_string;
	const char*					m_fontName;
	int							m_fontSize;
	int							m_strokeSize;
	CCSprite*					m_sprite;
	ccColor3B					m_color;
	ccColor3B					m_strokeColor;
};

#endif