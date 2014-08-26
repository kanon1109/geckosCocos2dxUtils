#include "CCStrokeLabelTTF.h"

CCStrokeLabelTTF::CCStrokeLabelTTF()
{
	m_string		= "";
	m_strokeSize	= 0;
	m_fontName		= "";
	m_fontSize		= 0;
	m_sprite		= NULL;
}


CCStrokeLabelTTF::~CCStrokeLabelTTF()
{
}

CCStrokeLabelTTF* CCStrokeLabelTTF::create(const char* string, const char* fontName, int fontSize, ccColor3B color, ccColor3B strokeColor, int strokeSize)
{
	CCStrokeLabelTTF*	sTf;
	sTf					= new CCStrokeLabelTTF();
	
	if (sTf && sTf->initWithString(string, fontName, fontSize, color, strokeColor, strokeSize))
	{
		sTf->autorelease();
		
	}
	else
	{
		CC_SAFE_DELETE(sTf);
	}
	return sTf;
}

bool CCStrokeLabelTTF::initWithString(const char *label, const char *fontName, int fontSize, ccColor3B color, ccColor3B strokeColor, int strokeSize)
{
	if (CCNode::init())
	{
		m_fontName		= fontName;
		m_fontSize		= fontSize;
		m_color			= color;
		m_strokeColor	= strokeColor;
		m_strokeSize	= strokeSize;
		setString(label);
		return true;
	}
	return false;
}

void CCStrokeLabelTTF::setString(const char *string)
{
	CCLabelTTF*			lTf;
	CCSize				textureSize;
	CCRenderTexture*	rt;
	ccBlendFunc			originalBlend;
	ccBlendFunc			func;

	CCAssert(string != NULL, "Invalid string");

	if (m_string.compare(string) || 1)
	{
		m_string	= string;
		if(m_sprite)
		{
			m_sprite->removeFromParent();
		}
	}
	else
	{
		return;
	}
	lTf				= CCLabelTTF::create(string, m_fontName, m_fontSize);
	textureSize		= lTf->getContentSize();
	textureSize.width	+= 2 * m_strokeSize;
	textureSize.height	+= 2 * m_strokeSize;
	//call to clear error
	glGetError();
	rt				= CCRenderTexture::create(textureSize.width, textureSize.height);
	if (!rt)
	{
		CCLOG("create render texture failed");
		addChild(lTf);
	}

	lTf->setColor(m_strokeColor);

	originalBlend	= lTf->getBlendFunc();
	//func			= { GL_SRC_ALPHA, GL_ONE };
	//lTf->setBlendFunc(func);
	//lTf->setAnchorPoint(ccp(0.5, 0.5));
	rt->begin();
	for (int i = 0; i < 360; i += 15)
	{
		float r = CC_DEGREES_TO_RADIANS(i);
		lTf->setPosition(ccp(
			textureSize.width * 0.5f + sin(r) * m_strokeSize,
			textureSize.height * 0.5f + cos(r) * m_strokeSize));
		lTf->visit();
	}
	lTf->setColor(m_color);
	lTf->setBlendFunc(originalBlend);
	lTf->setPosition(ccp(textureSize.width * 0.5f, textureSize.height * 0.5f));
	lTf->visit();
	rt->end();

	CCTexture2D *texture = rt->getSprite()->getTexture();
	texture->setAliasTexParameters();
	m_sprite = CCSprite::createWithTexture(rt->getSprite()->getTexture());
	//setContentSize(m_sprite->getContentSize());
	m_sprite->setPosition(ccp(0, 0));
	((CCSprite *)m_sprite)->setFlipY(true);
	addChild(m_sprite);
}

const char* CCStrokeLabelTTF::getString(void)
{
	return m_string.c_str();
}

void CCStrokeLabelTTF::setAnchorPoint(const CCPoint& point)
{
	m_sprite->setAnchorPoint(point);
}