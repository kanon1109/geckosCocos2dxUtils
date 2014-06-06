#include "ProgressLabel.h"
#include <string>
using namespace std;
ProgressLabel::ProgressLabel()
{
	this->isPause = false;
	this->wordCount = 0;
}

ProgressLabel::~ProgressLabel()
{
}

void ProgressLabel::show(const char* str, float delay)
{
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
		this->schedule(schedule_selector(ProgressLabel::timerHandler), (float)(this->m_delay / 1000));
	}
}

void ProgressLabel::timerHandler(float dt)
{
	int length = strlen(this->m_str);
	string s = this->m_str;
	this->setString(s.substr(0, wordCount).c_str());
	this->wordCount++;
	if (this->wordCount > length)
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
