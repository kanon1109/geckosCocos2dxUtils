#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#define g_tips CBFloatTips::getInstance()
#include <cocos-base.h>
#include <cocos2d.h>
USING_NS_CC;
class CBFloatTip :public CCNodeRGBA
{
public:
	CBFloatTip();
	~CBFloatTip();
	//设置文字内容
	void setContent(const char* content);
	CREATE_FUNC(CBFloatTip);
private:
	CCSprite*		m_bg;		//背景
	CCLabelTTF*		m_tf;		//文本
};

class CBFloatTips : public CCSceneExtension
{
public:
	enum tip_state
	{
		state_show,
		state_hide
	};
	CBFloatTips(void);
	~CBFloatTips(void);
	CREATE_SCENE_FUNC(CBFloatTips);
	/**
	 * 显示漂浮文字
	 * @param	content	内容
	 */
	void show(const char* content);

	/**
	 * 隐藏
	 */
	void hide(CCNode* pNode);

	void onExitScene();

	static CBFloatTips* getInstance();

private:
	tip_state		m_state;	//当前显示状态
	//飘子数组	
	CCArray* ftAry;
};

#endif
