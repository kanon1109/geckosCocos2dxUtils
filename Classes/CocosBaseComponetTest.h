#pragma once
#ifndef _COCOS_BASE_COMPONETTEST_
#define _COCOS_BASE_COMPONETTEST_
#include "cocos2d.h"
#include "cocos-base.h"
USING_NS_CC;
class CocosBaseComponetTest :public CCSceneExtension
{
public:
	CocosBaseComponetTest();
	~CocosBaseComponetTest();

	CREATE_SCENE_FUNC(CocosBaseComponetTest);

	void onLoadResources();
	void onLoadResourcesCompleted();
	void onLoadScene();
	void onEnterScene();
	void onExitScene();
private:
	void btnClickHandler(CCNode* node);
};
#endif
