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
     * 返回该字符是否为空白字符
     * @param    str
     * @return  返回该字符是否为空白字符
     */
	static bool isWhiteSpace(string* str);

	 /**
     * 去除字符串左端的空白字符
     * @param    target		目标字符串
     */
	static void lTrim(string* target);

	/**
     * 去除字符串右端的空白字符
     * @param    target		目标字符串
     */
	static void rTrim(string* target);

	/**
     * 返回一个去除2段空白字符的字符串
     * @param    target		目标字符串
     */
	static void trim(string* target);

	/**
     * 给数字字符前面添 "0"
     * 
     * <pre> 
     * 
     * CClog( StringFormat::zfill('1') );
     * // 01
     * 
     * CClog( StringFormat::zfill('16', 5) );
     * // 00016
     * 
     * CClog( StringFormat::zfill('-3', 3) );
     * // -03
     * 
     * </pre>
     * 
     * @param str 要进行处理的字符串
     * @param width 处理后字符串的长度，
     *              如果str.length >= width，将不做任何处理直接返回原始的str。
     */
	static void zfill(string* str, unsigned int width = 2);
};
#endif
