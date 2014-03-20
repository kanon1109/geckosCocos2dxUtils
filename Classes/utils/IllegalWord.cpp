#include "IllegalWord.h"
USING_NS_CC;
static CCArray* wordArr = NULL;
static XMLElement* rootElement;
static tinyxml2::XMLDocument* doc;
static bool isInit = false;
IllegalWord::IllegalWord()
{
}

IllegalWord::~IllegalWord()
{
}

void IllegalWord::init(string name /*= "cfg/illegalWords.xml"*/)
{
	if (!isInit)
	{
		unsigned char* pBuffer = NULL;
		unsigned long bufferSize = 0;
		//先将xml读入buffer
		pBuffer = CCFileUtils::sharedFileUtils()->getFileData(name.c_str(), "r", &bufferSize);
		wordArr = CCArray::create();
		wordArr->retain();
		doc = new tinyxml2::XMLDocument();
		doc->Parse((const char*)pBuffer);
		rootElement = doc->RootElement();
		XMLElement *element = rootElement->FirstChildElement();
		while (element)
		{
			CCString* node = ccs(element->Attribute("name"));
			wordArr->addObject(node);
			element = element->NextSiblingElement();
		}
		isInit = true;
		delete doc;
	}
}

void IllegalWord::filter(string &target)
{
	//创建一个元素的string
	CCString* keyWordStr;
	unsigned int count = wordArr->count();
	for (unsigned int i = 0; i < count; i++)
	{
		keyWordStr = (CCString*)wordArr->objectAtIndex(i);
		StringUtil::replace(target, keyWordStr->m_sString, "**");
	}
}
