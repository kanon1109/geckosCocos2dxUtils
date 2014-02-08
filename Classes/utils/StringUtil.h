#pragma once
#ifndef _STRING_UTIL_INIT_
#define _STRING_UTIL_INIT_
#include <iostream>
using namespace std;
class StringUtil
{
public:
	StringUtil(void);
	~StringUtil(void);

	/**
     * ·µ»Ø¸Ã×Ö·ûÊÇ·ñÎª¿Õ°××Ö·û
     * @param    str
     * @return  ·µ»Ø¸Ã×Ö·ûÊÇ·ñÎª¿Õ°××Ö·û
     */
	static bool isWhiteSpace(string* str);

	 /**
     * È¥³ý×Ö·û´®×ó¶ËµÄ¿Õ°××Ö·û
     * @param    target		Ä¿±ê×Ö·û´®
     */
	static void lTrim(string* target);

	/**
     * È¥³ý×Ö·û´®ÓÒ¶ËµÄ¿Õ°××Ö·û
     * @param    target		Ä¿±ê×Ö·û´®
     */
	static void rTrim(string* target);

	/**
     * ·µ»ØÒ»¸öÈ¥³ý2¶Î¿Õ°××Ö·ûµÄ×Ö·û´®
     * @param    target		Ä¿±ê×Ö·û´®
     */
	static void trim(string* target);
};
#endif
