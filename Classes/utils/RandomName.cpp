#include "RandomName.h"
static bool isInit = false;
static CCArray* lastNameAry;
static CCArray* firstNameAry;
static XMLElement* rootElement;
static tinyxml2::XMLDocument* doc;
RandomName::RandomName()
{
}

RandomName::~RandomName()
{
}

void RandomName::init(const char* name)
{
	if (!isInit)
	{
		unsigned char* pBuffer = NULL;
		unsigned long bufferSize = 0;
		//先将xml读入buffer
		pBuffer = CCFileUtils::sharedFileUtils()->getFileData(name, "r", &bufferSize);
		firstNameAry = CCArray::create();
		firstNameAry->retain();
		lastNameAry = CCArray::create();
		lastNameAry->retain();
		doc = new tinyxml2::XMLDocument();
		doc->Parse((const char*)pBuffer);
		rootElement = doc->RootElement();
		XMLElement *element = rootElement->FirstChildElement();
		while (element)
		{
			//名字
			const char* cln = element->Attribute("prefixName");
			if (cln)
			{
				CCString* ln = ccs(cln);
				lastNameAry->addObject(ln);
			}
			//姓
			const char* cfn = element->Attribute("postfixName");
			if (cfn)
			{
				CCString* fn = ccs(cfn);
				firstNameAry->addObject(fn);
			}
			element = element->NextSiblingElement();
		}
		isInit = true;
		delete doc;
	}
}

void RandomName::getRandomName(string &str)
{
	int ran = Random::randomInt(0, lastNameAry->count() - 1);
	CCString* ln = (CCString*)lastNameAry->objectAtIndex(ran);
	ran = Random::randomInt(0, firstNameAry->count() - 1);
	CCString* fn = (CCString*)firstNameAry->objectAtIndex(ran);
	str = ln->m_sString + fn->m_sString;
}
