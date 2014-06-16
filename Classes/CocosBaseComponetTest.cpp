#include "CocosBaseComponetTest.h"
#include "cocosBaseComponet/CBFloatTips.h"
#include "utils/Language.h"
#include "component/TextButton.h"
CocosBaseComponetTest::CocosBaseComponetTest()
{
}


CocosBaseComponetTest::~CocosBaseComponetTest()
{
}

void CocosBaseComponetTest::btnClickHandler(CCNode* node)
{
	CBFloatTips::getInstance()->show(Language::get("alert_netClose"));
}

void CocosBaseComponetTest::onLoadResources()
{
	//是否使用缓存 如果使用缓存则无法执行到onLoadResources和onLoadResourcesCompleted 但是会使用同一个对象
	setCachable(false);
	//是否自动销毁纹理 不销毁纹理 每次则使用同一个纹理
	setAutoRemoveUnusedTexture(true);
}

void CocosBaseComponetTest::onLoadResourcesCompleted()
{

}

void CocosBaseComponetTest::onLoadScene()
{
	Language::init("language.xml");

	TextButton* btn = TextButton::create(TYPE_RECT_BLUE, "CBFloatTips", 200);
	this->addChild(btn);
	btn->setPosition(ccp(200, 200));
	btn->setTag(11);
	btn->addEventListener(this, text_button_selector(CocosBaseComponetTest::btnClickHandler));
}

void CocosBaseComponetTest::onEnterScene()
{

}

void CocosBaseComponetTest::onExitScene()
{

}
