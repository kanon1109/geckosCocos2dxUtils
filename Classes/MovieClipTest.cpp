#include "MovieClipTest.h"
#include "component/MovieClip.h"
#include "utils/ScreenUtil.h"
#include "utils/MathUtil.h"

MovieClipTest::MovieClipTest()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	clock_t	time;
	time = clock();
	MovieClip* mc;
	for (int i = 0; i < 10; ++i)
	{
		 mc = MovieClip::create("spider", ".pvr.ccz");
	}
	CCLOG("view time : %d ms", clock() - time);
	mc->setTag(0);
	mc->setPosition(ScreenUtil::getCenter());
	mc->addEventListener(this, complete_selector(MovieClipTest::playComplete));
	/*mc->gotoAndStop(3);
	mc->gotoAndPlay(3, 5, .12f);
	mc->playOnce(.12f);*/
	mc->play(.12f, true, true);
	this->addChild(mc);

	CCSprite* sp = CCSprite::create("node.png");
	this->addChild(sp);

	CCSprite* sp1 = CCSprite::create("node.png");
	this->addChild(sp1);
	sp1->setPosition(ccp(180, 126.65));

	CCSprite* sp2 = CCSprite::create("node.png");
	this->addChild(sp2);
	sp2->setPosition(ccp(293.05, 271.75));

	CCSprite* sp3 = CCSprite::create("node.png");
	this->addChild(sp3);
	sp3->setPosition(ccp(150.45, 54.5));

	CCSprite* sp4 = CCSprite::create("node.png");
	this->addChild(sp4);
	sp4->setPosition(ccp(150.45, 167.5));

	vector<float> vect;
	MathUtil::segmentsIntr(sp1->getPosition(), sp2->getPosition(), ccp(150.45, 54.5), ccp(150.45, 167.5), vect);
	CCLOG("%d", vect.size());

	sp->setOpacity(0xCC);
	if (vect.size() > 0)
	{
		sp->setPositionX(vect.at(0));
		sp->setPositionY(vect.at(1));
	}
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

void MovieClipTest::playComplete( CCObject* obj )
{
	CCLOG("playComplete");
}
