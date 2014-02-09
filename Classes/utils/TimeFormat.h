#pragma once
#ifndef _TIME_FORMAT_
#define _TIME_FORMAT_
#include <iostream>
using namespace std;
class TimeFormat
{
public:
	TimeFormat(void);
	~TimeFormat(void);
	/**
     * 秒数转换为时间形式。
	 * @param	targetStr 需要修改的字符串    
	 * @param	time 秒数    
     * @param	partition 分隔符
     * @param	showHour  是否显示小时
     * 
     * 比如: time = 4351; secondToTime(time)返回字符串01:12:31;
     */
	static void secondToTime(string* targetStr, int second = 0, string partition = ":", bool showHour = true);
};
#endif
