#include "AppDelegate.h"
#include "Test.h"
#include "ScreenSizeTest.h"
#include "utils/ScreenUtil.h"
#include "SlotEffectTest.h"
#include "GetMoveSpeedTest.h"
#include "DropEffectTest.h"
#include "CocosBaseComponetTest.h"
#include "MathUtilTest.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	ScreenUtil::setScreenSize(960, 540);

    // create a scene. it's an autorelease object
	CCScene *pScene = MathUtilTest::create();
	//CCScene *pScene = CocosBaseComponetTest::create();
    // run
    pDirector->runWithScene(pScene);

	//REGISTER_SCENE_FUNC(CocosBaseComponetTest);

	//CCSceneManager::sharedManager()->runWithScene(LoadScene("CocosBaseComponetTest"));

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
