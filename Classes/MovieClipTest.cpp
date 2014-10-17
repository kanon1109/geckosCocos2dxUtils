#include "MovieClipTest.h"
#include "component/MovieClip.h"
#include "utils/ScreenUtil.h"
#include "utils/MathUtil.h"
MovieClipTest::MovieClipTest()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	clock_t	time;
	time = clock();
	MovieClip* mc = NULL;
	CCArray* frameList = NULL;
	this->curTag = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (!mc)
		{
			mc = MovieClip::create("spider", ".pvr.ccz");
			frameList = mc->getFrameList();
			mc->addEventListener(this, complete_selector(MovieClipTest::playComplete));
		}
		else
		{
			//mc = MovieClip::create("spider", ".pvr.ccz");
			mc = MovieClip::create(frameList);
		}
		mc->setPosition(ccp(ScreenUtil::getLeft() + 20 + (i * 120), ScreenUtil::getCenter().y));
		mc->play(.03f, true, true);
		this->addChild(mc);
		mc->setTag(i);
	}
	CCLOG("view time : %d ms", clock() - time);
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
	MovieClip* mc = (MovieClip*) this->getChildByTag(this->curTag);
	if (mc) mc->stop();
	return true;
}

void MovieClipTest::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	MovieClip* mc = (MovieClip*) this->getChildByTag(this->curTag);
	if (!mc) return;
	mc->play(mc->fps);
	mc->removeFromParent();
	this->curTag++;
}

void MovieClipTest::playComplete( CCObject* obj )
{
	CCLOG("playComplete");
}
