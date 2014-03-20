#include "ScreenSizeTest.h"
#include "utils/ScreenUtil.h"
#include "utils/StringUtil.h"
USING_NS_CC;

ScreenSizeTest::ScreenSizeTest(void)
{
	//ÎÄ±¾	
	CCSprite* bg = CCSprite::create("bg.jpg");
	this->addChild(bg);
	bg->setPosition(ScreenUtil::getCenter());

	CCLabelTTF* label = CCLabelTTF::create("hello world", "Á¥Êé", 30);
	this->addChild(label);
	label->setPosition(ccp(ScreenUtil::getLeftTop().x + label->getContentSize().width / 2, 
							ScreenUtil::getLeftTop().y - label->getContentSize().height / 2));

	CCLOG("isSymbolWord %i", StringUtil::isSymbolWord("/*-"));
	CCLOG("isAlphabetWord %i", StringUtil::isAlphabetWord("aaa"));
	CCLOG("isNumberWord %i", StringUtil::isNumberWord("158"));
}


ScreenSizeTest::~ScreenSizeTest(void)
{
}
