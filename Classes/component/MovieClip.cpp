#include "MovieClip.h"
using namespace std;

MovieClip::MovieClip(void)
{
	this->frameList = CCArray::create();
	this->frameList->retain();
}


MovieClip::~MovieClip(void)
{
}

MovieClip* MovieClip::create( const char* xmlFileName)
{
	MovieClip* mc = new MovieClip();
	if(mc && mc->init(xmlFileName))
	{
		mc->autorelease();
		return mc;
	}
	CC_SAFE_DELETE(mc);
	return mc;
}

bool MovieClip::init( const char* xmlFileName)
{
	unsigned char* pBuffer = NULL;
	unsigned long bufferSize = 0;
	//先将xml读入buffer
	pBuffer = CCFileUtils::sharedFileUtils()->getFileData(xmlFileName, "r", &bufferSize);
	this->doc.Parse((const char*)pBuffer);
	//图片地址
	CCString* imagePath = CCString::create(this->doc.RootElement()->Attribute("imagePath"));
	CCLOG("imagePath %s", imagePath->getCString());
	XMLElement *element = doc.RootElement()->FirstChildElement();
	while (element)
	{
		CCString* node = ccs(element->GetText());
		element = element->NextSiblingElement();
	}
}
