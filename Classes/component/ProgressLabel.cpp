#include "ProgressLabel.h"

using namespace std;
ProgressLabel::ProgressLabel()
{
}

ProgressLabel::~ProgressLabel()
{
}

void ProgressLabel::show(const char* str, float delay)
{
	this->isPause = false;
	this->wordCount = 0;
	this->m_delay = delay;
	this->m_str = str;
	this->schedule(schedule_selector(ProgressLabel::timerHandler), (float)(delay / 1000));
}

void ProgressLabel::togglePause()
{
	this->isPause = !this->isPause;
	if (this->isPause)
	{
		this->unschedule(schedule_selector(ProgressLabel::timerHandler));
	}
	else
	{
		if (this->wordCount >= (int)strlen(this->m_str))
		{
			this->setString("");
			this->wordCount = 0;
		}
		this->schedule(schedule_selector(ProgressLabel::timerHandler), (float)(this->m_delay / 1000));
	}
}

void ProgressLabel::timerHandler(float dt)
{
	int length = strlen(this->m_str);
	string s = this->m_str;
	//根据ASCII码找出中英文字符
	if(s.at(this->wordCount) >= 0 && s.at(this->wordCount) <= 127)
	{
		//英文
		this->setString(s.substr(0, wordCount).c_str());
		this->wordCount++;
	}
	else
	{
		//中文
		this->setString(s.substr(0, wordCount + 3).c_str());
		this->wordCount += 3;
	}
	if (this->wordCount >= length)
		this->unschedule(schedule_selector(ProgressLabel::timerHandler));
}

ProgressLabel* ProgressLabel::create(const char *fontName, float fontSize)
{
	ProgressLabel* pLabel = new ProgressLabel();
	if (pLabel && pLabel->initWithString("", fontName, fontSize))
	{
		pLabel->autorelease();
		return pLabel;
	}
	CC_SAFE_DELETE(pLabel);
	return NULL;
}

void ProgressLabel::setDelay( float delay )
{
	this->m_delay = delay;
	this->unschedule(schedule_selector(ProgressLabel::timerHandler));
	if(this->m_delay == 0) 
	{
		this->setString(this->m_str);
		return;
	}
	if (this->isPause) return;
	this->schedule(schedule_selector(ProgressLabel::timerHandler), (float)(this->m_delay / 1000));
}
