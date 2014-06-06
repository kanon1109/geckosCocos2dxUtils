#include "TimeFormat.h"
#include <string>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "utils/StringUtil.h"
#ifndef CC_PLATFORM_WIN32
#include <math.h>
#endif
using namespace std;
TimeFormat::TimeFormat(void)
{
}


TimeFormat::~TimeFormat(void)
{
}

void TimeFormat::secondToTime(string* targetStr, int second /*= 0*/, string partition /*= ":"*/, bool showHour /*= true*/ )
{
	int hours = second / 3600;
	int minutes = second % 3600 / 60;
	int seconds = second % 3600 % 60;

	char h[10];
	sprintf(h, "%d", hours);
	char m[10];
	sprintf(m, "%d", minutes);
	char s[10];
	sprintf(s, "%d", seconds);

	string hStr = h;
	string mStr = m;
	string sStr = s;

	if (hours < 10)  hStr = "0" + hStr;
	if (minutes < 10) mStr = "0" + mStr;
	if (seconds < 10) sStr = "0" + sStr;

	if (showHour) 
		*targetStr = hStr + partition + mStr + partition + sStr;
	else
		*targetStr = mStr + partition + sStr;
}

void TimeFormat::timeToSecond( string* targetStr, string timeStr, string partition /*= ":"*/ )
{
	vector<string> v;
	StringUtil::split(v, timeStr, partition);
	int time = 0;
	unsigned int size = v.size();
	for (unsigned int i = 0; i < size; i++)
	{
		string str = v[i];
		//stringתint
		int n = atoi(str.c_str());
		time += n * pow(60.0f, (int)(size - 1 - i));
	}
	sprintf((char* )targetStr->c_str(), "%d", time);
}
