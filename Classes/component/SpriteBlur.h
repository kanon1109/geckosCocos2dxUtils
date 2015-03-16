/****************************************************************************
 SpriteBlur.h 
 模糊精灵

 created by:yong
 Created on:2014-07-24
 ****************************************************************************/

#ifndef __SPRITEBLUR_H__
#define __SPRITEBLUR_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class SpriteBlur : public CCSprite
{
public:
	SpriteBlur();
	~SpriteBlur();

	static SpriteBlur* create(const char *pszFileName);
	bool initWithTexture(CCTexture2D* texture, const CCRect&  rect);

	void draw();
	void initProgram();
	void setBlurSize(float f);
	void listenBackToForeground(CCObject *obj);

private:
	CCPoint		blur_;
	GLfloat		sub_[4];
	GLuint		subLocation;
	GLuint		blurLocation;
};

#endif /* defined(__SPRITEBLUR_H__) */
