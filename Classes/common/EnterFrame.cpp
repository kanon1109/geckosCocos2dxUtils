#include "EnterFrame.h"
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
//创建计时器的节点
static Node* node = NULL;
//帧频
static float fps = 0.0;
//保存函数指针的vecotr
static vector<SEL_CallFunc> funcVect;
EnterFrame::EnterFrame(void)
{
}

EnterFrame::~EnterFrame(void)
{
}

void EnterFrame::init(CCNode* container, float fps )
{
	fps = fps;
	CCLog("fps%f", fps);
	if(!node)
	{
		node = new Node();
		container->addChild(node);
	}
	EnterFrame::start();
}

void EnterFrame::start()
{
	node->schedule(schedule_selector(Node::loop), fps);
}

void EnterFrame::stop()
{
	node->unschedule(schedule_selector(Node::loop));
}

void EnterFrame::push( SEL_CallFunc callfunc )
{
	//删除迭代器和元素
	EnterFrame::pop(callfunc);
	funcVect.push_back(callfunc);
}

void EnterFrame::pop( SEL_CallFunc callfunc )
{
	vector<SEL_CallFunc>::iterator it = find(funcVect.begin(), funcVect.end(), callfunc);
	if (it != funcVect.end()) funcVect.erase(it);
}

void EnterFrame::clear()
{
	funcVect.clear();
}

void Node::loop(float dt)
{
	//CCLog("size%i", funcVect.size());
	//funcVect.size() 为无符号int
	for (unsigned int i = 0; i < funcVect.size(); i++)
	{
		//成员函数的指针一定要用某个对象来调用
		(this->*funcVect[i])();
	}
}
