#include "DropEffect.h"
#include "utils/Random.h"
DropEffect::DropEffect()
{
	this->itemList = CCArray::create();
	this->itemList->retain();
}

DropEffect::~DropEffect()
{
}

void DropEffect::drop(const char* pszFileName, int count, float gravity /*= 1*/, float elasticity /*= .9*/, float minVx /*= -5*/, float maxVx /*= 5*/, float minVy /*= 10*/, float maxVy /*= 20*/)
{
	if (count < 0) count = 0;
	for (int i = 0; i < count; ++i)
	{
		DropItem* dVo = DropItem::create(pszFileName, gravity, elasticity);
		dVo->vx = Random::randomFloat(minVx, maxVx);
		dVo->vy = Random::randomFloat(minVy, maxVy);
		this->addChild(dVo);
		this->itemList->addObject(dVo);
	}
	this->schedule(schedule_selector(DropEffect::loop), .003f);
}

void DropEffect::loop(float dt)
{
	int count = this->itemList->count();
	CCLOG("count", count);
	for (int i = 0; i < count; ++i)
	{
		DropItem* dVo = (DropItem* )this->itemList->objectAtIndex(i);
		dVo->update();
	}
}

DropItem::DropItem()
{
	this->vx = 0;
	this->vy = 0;
}


DropItem::~DropItem()
{
}

void DropItem::update()
{
	this->setPositionX(this->getPositionX() + this->vx);
	this->setPositionY(this->getPositionY() + this->vy);
	this->vy -= this->gravity;
}

DropItem* DropItem::create(const char* pszFileName, float gravity /*= 1*/, float elasticity /*= .9*/)
{
	DropItem* dVo = new DropItem();
	if (dVo && dVo->init(gravity, elasticity))
	{
		dVo->initWithFile(pszFileName);
		dVo->autorelease();
		return dVo;
	}
	CC_SAFE_DELETE(dVo);
	return NULL;
}

bool DropItem::init(float gravity /*= 1*/, float elasticity /*= .9*/)
{
	this->gravity = gravity;
	this->elasticity = elasticity;
	return true;
}
