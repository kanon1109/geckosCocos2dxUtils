#include "SlotEffectTest.h"
#include "effect/SlotEffect.h"

SlotEffectTest::SlotEffectTest()
{
	int startX = 10;
	int startY = 500;
	int gap = 5;
	int index = 1;
	for (int i = 1; i <=15; i++)
	{
		CCSprite* spt = CCSprite::create("effect/a1.png");
		spt->setPositionX((startX + gap + spt->getContentSize().height) * index);
		spt->setPositionY(startY);
		this->addChild(spt);
		spt->setTag(i);
		index++;
		if (i % 5 == 0)
		{
			index = 1;
			startY -= spt->getContentSize().height + gap;
		}
	}
	SlotEffect* se = SlotEffect::create(1, 15, 2, 50);
	se->setTag(100);
	this->addChild(se);
	se->start(5);
	se->addEventListener(this, callfunc_selector(SlotEffectTest::selectSpt));

}

SlotEffectTest::~SlotEffectTest()
{

}

void SlotEffectTest::selectSpt()
{
	this->resetAllSpt();
	SlotEffect* se = (SlotEffect* )this->getChildByTag(100);
	CCLOG("se->getCurIndex() %d", se->getCurIndex());
	CCSprite* spt = (CCSprite* )this->getChildByTag(se->getCurIndex());
	spt->initWithFile("effect/a2.png");
}

void SlotEffectTest::resetAllSpt()
{
	for (int i = 1; i <= 15; i++)
	{
		CCSprite* spt = (CCSprite*)this->getChildByTag(i);
		spt->initWithFile("effect/a1.png");
	}
}
