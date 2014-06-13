#include "DropEffect.h"
#include "utils/Random.h"
DropEffect::DropEffect()
{
	this->itemList = CCArray::create();
	this->itemList->retain();
}

DropEffect::~DropEffect()
{
	CC_SAFE_RELEASE_NULL(this->itemList);
}

void DropEffect::drop(const char* pszFileName, 
					int count /*= 5*/, 
					float x /*= 0*/, 
					float y /*= 0*/, 
					float gravity /*= .9*/, 
					float elasticity /*= .4*/, 
					float minDropHeight /*= 0*/,
					float maxDropHeight /*= 0*/,
					float minVx /*= -5*/, float maxVx /*= 5*/, 
					float minVy /*= 4*/, float maxVy /*= 10*/)
{
	if (count < 0) count = 0;
	for (int i = 0; i < count; ++i)
	{
		DropItem* dVo = DropItem::create(pszFileName, gravity, elasticity, 
										 minDropHeight, maxDropHeight);
		dVo->vx = Random::randomFloat(minVx, maxVx);
		dVo->vy = Random::randomFloat(minVy, maxVy);
		dVo->setAnchorPoint(ccp(.5, .5));
		dVo->setPosition(ccp(x, y));
		dVo->setFloorPos(this->floorPosY);
		this->addChild(dVo);
		this->itemList->addObject(dVo);
	}
	this->schedule(schedule_selector(DropEffect::loop), this->fps);
}


void DropEffect::loop(float dt)
{
	int count = this->itemList->count();
	for (int i = 0; i < count; ++i)
	{
		DropItem* dVo = (DropItem* )this->itemList->objectAtIndex(i);
		dVo->update();
	}
}

DropEffect* DropEffect::create(float floorPosY /*= 0*/, float fps /*= .01f*/)
{
	DropEffect* de = new DropEffect();
	if (de && de->init(floorPosY, fps))
	{
		de->autorelease();
		return de;
	}
	CC_SAFE_DELETE(de);
	return NULL;
}

bool DropEffect::init(float floorPosY, float fps)
{
	this->fps = fps;
	this->floorPosY = floorPosY;
	return CCNode::init();
}

DropItem::DropItem()
{
	this->vx = 0;
	this->vy = 0;
	this->floorPosY = 0;
}

DropItem::~DropItem()
{
}

void DropItem::update()
{
	this->setPositionX(this->getPositionX() + this->vx);
	this->setPositionY(this->getPositionY() + this->vy);
	if (this->getPositionY() < this->floorPosY + this->getContentSize().height * .5)
	{
		this->setPositionY(this->floorPosY + this->getContentSize().height * .5);
		this->vy *= -this->elasticity;
		this->vx *= this->elasticity;
	}
	else
	{
		this->vy -= this->gravity;
	}
	if (abs(this->vy) < .1f) this->vy = 0;
	if (abs(this->vx) < .1f) this->vx = 0;
}

DropItem* DropItem::create(const char* pszFileName, 
							float gravity, 
							float elasticity, 
							float minDropHeight, 
							float maxDropHeight)
{
	DropItem* dVo = new DropItem();
	if (dVo && dVo->init(gravity, elasticity, minDropHeight, maxDropHeight))
	{
		dVo->initWithFile(pszFileName);
		dVo->autorelease();
		return dVo;
	}
	CC_SAFE_DELETE(dVo);
	return NULL;
}

bool DropItem::init(float gravity, float elasticity, 
					float minDropHeight, 
					float maxDropHeight)
{
	this->gravity = gravity;
	this->elasticity = elasticity;
	this->minDropHeight = minDropHeight;
	this->maxDropHeight = maxDropHeight;
	return true;
}

void DropItem::setFloorPos(float pos)
{
	this->floorPosY = pos;
	if (this->maxDropHeight != this->minDropHeight && this->minDropHeight != 0)
		this->floorPosY = this->getPositionY() - Random::randomFloat(minDropHeight, maxDropHeight);
}
