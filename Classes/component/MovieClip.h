#pragma once
#ifndef _MOVIE_CLIP_
#define _MOVIE_CLIP_
#include "cocos2d.h"
USING_NS_CC;
//播放结束回调
typedef void (CCObject::*SEL_COMPLETE_SELECTOR)(CCObject*);
#define complete_selector(_SELECTOR) (SEL_COMPLETE_SELECTOR)(&_SELECTOR)
//影片剪辑序列帧代替cocos的动画
class MovieClip:public CCSprite
{
public:
	MovieClip(void);
	~MovieClip(void);
	
	//************************************
	// Description: 创建影片剪辑 
	// Parameter: const char * name		plist文件或者纹理名称前缀（去除后缀）
	// Parameter: const char * fileType 纹理文件类型（1为.png, 2为.pvr, 3为.pvr.cc, 4为jpg）
	// Parameter: const char * prefix	前缀名称字符串
	// Returns:   MovieClip*
	//************************************
	static MovieClip* create(const char* name, const char* fileType = ".png", const char* prefix = "");
	
	//初始化
	bool init(const char* name, const char* fileType, const char* prefix);

	//跳帧
	void gotoAndStop(int frame);

	//************************************
	// Description:从第几帧开始播放到第几帧
	// Parameter: int start		起始帧数
	// Parameter: int end		结尾帧数（默认0 为播放到最后一帧）
	// Parameter: float fps		帧频
	// Parameter: bool isLoop	是否循环播放
	// Returns:   void
	//************************************
	void gotoAndPlay(int start, int end = 0, float fps = .033f, bool isLoop = true);

	//暂停
	void stop();

	//播放
	void play(float fps = .033f, bool isLoop = true);

	
	//************************************
	// Method:    playOnce		播放一次
	// Parameter: float fps		帧频
	// Parameter: bool distroy	是否销毁
	// Returns:   void
	//************************************
	void playOnce(float fps = .033f, bool distroy = true);

	//当前帧频
	float fps;

	//是否循环
	bool isLoop;

	//添加监听
	void addEventListener(CCObject* target, SEL_COMPLETE_SELECTOR completeFun);
private:
	//存放帧数据的列表
	CCArray* frameList;
	//回调方法的目标
	CCObject* target;
	//回调方法
	SEL_COMPLETE_SELECTOR completeFun;
	//plist文件或者纹理名称前缀（去除后缀）
	const char* mcName;
	//当前帧
	int currentFrame;
	//起始帧
	int startFrame;
	//结束帧
	int endFrame;
	//总帧数
	int totalFrames;
	//是否播放一次后销毁
	bool distroy;
	//前缀名称
	const char* prefix;
	//初始化所有帧
	void initFrame();
	//更新帧
	void updateFrame();
	//循环
	void loop(float dt);
};
#endif // !_MOVIE_CLIP_
