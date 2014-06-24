#include "MathUtilTest.h"
#include "utils/MathUtil.h"
#include "utils/ColorUtil.h"
MathUtilTest::MathUtilTest(void)
{

	CCPoint a = ccp(339.95, 117.1);
	CCPoint b = ccp(411.15, 190.1);
	CCPoint c = ccp(325.05, 273.8);
	CCPoint d = ccp(253.95, 200.7);
	CCPoint p = ccp(310, 250);

	CCDrawNode* node = CCDrawNode::create();
	node->drawDot(a, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(b, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(c, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(d, 5, ColorUtil::getColor4F(0xFF, 0x00, 0x00, 0xFF));
	node->drawDot(p, 5, ColorUtil::getColor4F(0xFF, 0xCC, 0x00, 0xFF));

	this->addChild(node);

	//CCLOG("%d", MathUtil::isInsideTriangle(a, b, c, p));
	CCLOG("%d", MathUtil::isInsideSquare(a, b, c, d, p));

}


MathUtilTest::~MathUtilTest(void)
{
}
