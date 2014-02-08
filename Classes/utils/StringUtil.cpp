#include "StringUtil.h"
#include "cocos2d.h"
#include <stdio.h>
using namespace std;
StringUtil::StringUtil(void)
{
}


StringUtil::~StringUtil(void)
{
}

bool StringUtil::isWhiteSpace( string* str )
{
	if (*str == " " || *str == "\t" || 
		*str == "\r" || *str == "\n") return true;
	return false;
}

void StringUtil::lTrim( string* target )
{
	int length = 0;
	//创建一个元素的string
	string str = string(1, target->at(length));
	while(StringUtil::isWhiteSpace(&str))
	{
		length++;
		str = string(1, target->at(length));
	}
	target->replace(0, length, "");
}

void StringUtil::rTrim( string* target )
{
	int length = target->length() - 1;
	string str = string(1, target->at(length));
	while(StringUtil::isWhiteSpace(&str))
	{
		length--;
		str = string(1, target->at(length));
	}
	target->replace(length, target->length() - 1, "");
}

void StringUtil::trim( string* target )
{
	StringUtil::lTrim(target);
	StringUtil::rTrim(target);
}
