#include "MovieClipTest.h"
#include "component/MovieClip.h"
#include "utils/ScreenUtil.h"

MovieClipTest::MovieClipTest()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	MovieClip* mc = MovieClip::create("attack", ".pvr.ccz");
	mc->setTag(0);
	mc->setPosition(ScreenUtil::getCenter());
	mc->gotoAndStop(3);
	mc->gotoAndPlay(3, 5, .12f);
	this->addChild(mc);
}


MovieClipTest::~MovieClipTest()
{
}

bool MovieClipTest::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	MovieClip* mc = (MovieClip*) this->getChildByTag(0);
	if (mc) mc->stop();
	return true;
}

void MovieClipTest::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	MovieClip* mc = (MovieClip*) this->getChildByTag(0);
	if (!mc) return;
	mc->play(mc->fps);
	mc->removeFromParent();
}
