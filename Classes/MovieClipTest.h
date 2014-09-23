#pragma once
#ifndef _MOVIE_CLIP_TEST_
#define _MOVIE_CLIP_TEST_
#include "cocos2d.h"
USING_NS_CC;
class MovieClipTest :public CCScene, public CCTargetedTouchDelegate
{
public:
	MovieClipTest();
	~MovieClipTest();
	CREATE_FUNC(MovieClipTest);
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
private:
	void playComplete(CCObject* obj);
	//µ±Ç°tag
	int curTag;
};
#endif
