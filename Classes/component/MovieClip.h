#pragma once
#ifndef _MOVIE_CLIP_
#define _MOVIE_CLIP_
#include "cocos2d.h"
using namespace tinyxml2;
USING_NS_CC;
//影片剪辑序列帧代替cocos的动画
class MovieClip:public CCSprite
{
public:
	MovieClip(void);
	~MovieClip(void);
	
	//************************************
	// Method:    create	创建影片剪辑
	// Parameter: const char * xmlFileName	xml文件 规格要求和starling中的配置相同
	// Returns:   MovieClip*
	//************************************
	static MovieClip* create(const char* xmlFileName);

	//初始化
	bool init(const char* xmlFileName);
private:
	//存放帧数据的列表
	CCArray* frameList;
	//xml工具
	tinyxml2::XMLDocument doc;
};
#endif // !_MOVIE_CLIP_
