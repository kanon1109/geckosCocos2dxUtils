#include "Timer.h"

Timer::Timer(float delay, int repeatCount)
{
	this->timeHandler = NULL;
	this->m_delay = delay;
	this->m_repeatCount = repeatCount;
	if (this->m_repeatCount < 0) this->m_repeatCount = 0;
	this->currentCount = 0;
	this->running = false;
}

Timer::~Timer()
{
}

void Timer::start()
{
	if (this->running) return;
	this->running = true;
	this->schedule(schedule_selector(Timer::loop), (float)(this->m_delay / 1000));
}

void Timer::stop()
{
	if (!this->running) return;
	this->running = false;
	this->unschedule(schedule_selector(Timer::loop));
}

Timer* Timer::create(float delay, int repeatCount)
{
	Timer* timer = new Timer(delay, repeatCount);
	if (timer && timer->init())
	{
		timer->autorelease();
		return timer;
	}
	CC_SAFE_DELETE(timer);
	return NULL;
}

void Timer::loop(float dt)
{
	if (this->m_repeatCount > 0)
	{
		if (this->currentCount < this->m_repeatCount)
		{
			this->currentCount++;
			if (this->target && this->timeHandler)
			{
				(this->target->*timeHandler)(this);
			}
		}
		else
		{
			this->stop();
		}
	}
	else
	{
		this->currentCount++;
		if (this->target && this->timeHandler)
		{
			(this->target->*timeHandler)(this);
		}
	}
}

void Timer::addEventListener(CCNode* target, SEL_TIMER_SELECTOR timeFunc)
{
	this->target = target;
	this->timeHandler = timeFunc;
}

void Timer::reset()
{
	this->currentCount = 0;
	this->stop();
}

void Timer::setRepeatCount(int count)
{
	this->m_repeatCount = count;
	this->stop();
	this->start();
}

void Timer::setDelay(float delay)
{
	this->m_delay = delay;
	this->stop();
	this->start();
}
