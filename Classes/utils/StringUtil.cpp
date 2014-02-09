#include "StringUtil.h"
#include "cocos2d.h"
#include <stdio.h>
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
#include <regex>  
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM == CC_PLATFORM_IOS)  
#include <regex.h>
#endif
using namespace std;
StringUtil::StringUtil(void)
{
}


StringUtil::~StringUtil(void)
{
}

bool StringUtil::isWhiteSpace( string str )
{
	if (str == " " || str == "\t" || 
		str == "\r" || str == "\n") return true;
	return false;
}

void StringUtil::lTrim( string* target )
{
	int length = 0;
	//创建一个元素的string
	string str = string(1, target->at(length));
	while(StringUtil::isWhiteSpace(str))
	{
		length++;
		str = string(1, target->at(length));
	}
	target->replace(0, length, "");
}

void StringUtil::rTrim( string* target )
{
	int length = target->length();
	string str = string(1, target->at(length - 1));
	while(StringUtil::isWhiteSpace(str))
	{
		length--;
		str = string(1, target->at(length - 1));
	}
	target->replace(length, target->length(), "");
}

void StringUtil::trim( string* target )
{
	StringUtil::lTrim(target);
	StringUtil::rTrim(target);
}

void StringUtil::zfill( string* str, unsigned int width /*= 2*/ )
{
	if(str == NULL ) return;
	unsigned int slen = str->length();
	if( slen >= width )	return;
	//查找负号 并保存状态。
	bool negative = false;
	string nStr = "-";
	size_t found = str->find(nStr);
	if(found != str->npos)
	{
		//如果找到了
		negative = true;
		str->replace(0, 1, "");
	}
	int len = width - slen;
	for( int i = 0; i < len; i+=1 )
	{
		*str = '0' + *str;
	}
	if( negative ) 	*str = '-' + *str;
}

void StringUtil::reverse( string* str )
{
	if(str->length() == 1) return;
	std::reverse(str->begin(), str->end());
}

void StringUtil::cutOff( string* str, unsigned int start, unsigned int len, bool order )
{
	unsigned int length = str->length();
	if (start > length) start = length;
	int s = start;
	int e = start + len;
	string newStr;
	if (order)
	{
		newStr = str->substr(0, s) + str->substr(e, length);
	}
	else 
	{
		s = length - 1 - start - len;
		e = s + len;
		newStr = str->substr(0, s + 1) + str->substr(e + 1 , length);
	}
	*str = newStr;
}

bool StringUtil::isEmail( string* email )
{
	StringUtil::trim(email);
	string regStr = "([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)";
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	char ss[100] = {};  
	sprintf(ss,"%s", email->c_str());  
	regmatch_t pmatch[4];  
	regex_t match_regex;  
	regcomp( &match_regex,  regStr, REG_EXTENDED );  
	if (regexec( &match_regex, ss, 4, pmatch, 0 ) != 0 )  return false;
	regfree( &match_regex );  
	return true;
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
	regex pattern(regStr);  
	if (!regex_match(*email, pattern ))  
		return false;
	return true;
#endif
	//其他平台暂时不能验证
	return false;
}
