#include "MathUtilTest.h"
#include "utils/MathUtil.h"
#include "utils/ColorUtil.h"
MathUtilTest::MathUtilTest(void)
{

	CCPoint a = ccp(100, 100);
	CCPoint b = ccp(100, 400);
	CCPoint c = ccp(440, 340);
	CCPoint p = ccp(140, 140);

	CCDrawNode* node = CCDrawNode::create();
	node->drawDot(a, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(b, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(c, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(p, 5, ColorUtil::getColor4F(0xFF, 0xCC, 0x00, 0xFF));

	this->addChild(node);

	CCLOG("%d", MathUtil::isInsideTriangle(a, b, c, p));

}


MathUtilTest::~MathUtilTest(void)
{
}
