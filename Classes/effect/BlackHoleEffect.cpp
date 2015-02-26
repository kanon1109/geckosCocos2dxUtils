#include "BlackHoleEffect.h"

BlackHoleEffect::BlackHoleEffect()
{
	this->inHoleCompleteFun = NULL;
	this->attenuationCompleteFun = NULL;
	this->overCompleteFun = NULL;
}

BlackHoleEffect::~BlackHoleEffect()
{
}

BlackHoleEffect* BlackHoleEffect::create(float g /*= 10.0f*/, float range /*= 400.0f*/, float angleSpeed /*= 5.0f*/, int time /*= 2000*/, int fps /*= 60*/)
{
	BlackHoleEffect* bh = new BlackHoleEffect();
	if (bh && bh->init(g, range, angleSpeed, time, fps))
	{
		bh->autorelease();
		return bh;
	}
	CC_SAFE_DELETE(bh);
	return NULL;
}

bool BlackHoleEffect::init(float g /*= 10.0f*/, float range /*= 400.0f*/, float angleSpeed /*= 5.0f*/, int time /*= 2000*/, int fps /*= 60*/)
{
	this->g = g;
	this->range = range;
	this->angleSpeed = angleSpeed;
	this->time = time;
	this->fps = fps;
	this->minDis = 15;
	this->overTime = 2000;
	this->f = .99f;
	return true;
}

void BlackHoleEffect::addHole(float holePosX, float holePosY)
{
	this->holePosX = holePosX;
	this->holePosY = holePosY;
	this->isStart = true;
	this->isOver = false;
	this->timeFrame = this->time / 1000 * fps;
	this->overTimeFrame = this->overTime / 1000 * fps;
}

float BlackHoleEffect::mathDistance(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void BlackHoleEffect::addSubstanceList(CCArray* ary)
{
	this->subList = ary;
}

void BlackHoleEffect::update()
{
	if (!this->isStart) return;
	int length = this->subList->count();
	CCNode* obj;
	float dis;
	for (int i = length - 1; i >= 0; i--)
	{
		obj = (CCNode* )this->subList->objectAtIndex(i);
		dis = this->mathDistance(this->holePosX, this->holePosY, obj->getPositionX(), obj->getPositionY());
		if (dis <= range)
		{
			float speed = this->g * (1 - dis / range);
			if (!this->isOver)
			{
				if (dis <= this->minDis)
				{
					//小于最短距离
					if (this->target && this->inHoleCompleteFun) (this->target->*inHoleCompleteFun)(obj);
					//这里外部可能将物体销毁，所以循环下面不做处理。
					continue;
				}
				if (speed > dis) speed = dis;
			}
			else
			{
				//黑洞生命周期结束
				speed = 0;
				this->angleSpeed = this->angleSpeed * this->f;
			}
			//如果在影响范围内
			float dx = obj->getPositionX() - this->holePosX;
			float dy = obj->getPositionY() - this->holePosY;
			float radians = atan2(dy, dx);
			float vx = speed * cos(radians);
			float vy = speed * sin(radians);

			obj->setPositionX(obj->getPositionX() - vx);
			obj->setPositionY(obj->getPositionY() - vy);

			//算出角速度
			radians += (float)(M_PI / 2);
			vx = this->angleSpeed * cos(radians);
			vy = this->angleSpeed * sin(radians);
			obj->setPositionX(obj->getPositionX() - vx);
			obj->setPositionY(obj->getPositionY() - vy);

			float angle = radians / M_PI * 180;
			obj->setRotation(angle);
		}
	}
	this->timeFrame--;
	if (this->timeFrame <= 0 && !this->isOver)
	{
		this->timeFrame = 0;
		//黑洞持续时间结束
		this->isOver = true;
		if (this->target && this->attenuationCompleteFun) (this->target->*attenuationCompleteFun)(this);
	}
	if (this->isOver)
	{
		//进入衰减期
		this->overTimeFrame--;
		if (this->overTimeFrame <= 0)
		{
			//衰减期结束
			this->overTimeFrame = 0;
			this->isStart = false;
			if (this->target && this->overCompleteFun) (this->target->*overCompleteFun)(this);
		}
	}
}

void BlackHoleEffect::setInHoleSelector(CCObject* target, SEL_IN_HOLE_SELECTOR inHoleComplete)
{
	this->target = target;
	this->inHoleCompleteFun = inHoleComplete;
}

void BlackHoleEffect::setAttenuationSelector(CCObject* target, SEL_ATTENUATION_SELECTOR attenuationComplete)
{
	this->target = target;
	this->attenuationCompleteFun = attenuationComplete;
}

void BlackHoleEffect::setOverSelector(CCObject* target, SEL_OVER_SELECTOR overComplete)
{
	this->target = target;
	this->overCompleteFun = overComplete;
}
