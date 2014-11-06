#include "GuideTest.h"
#include "Guide.h"

GuideTest::GuideTest()
{
	CCSprite* bg = CCSprite::create("HelloWorld.png");
	bg->setAnchorPoint(ccp(0, 0));
	this->addChild(bg);

	CCSprite* spt = CCSprite::create();
	this->addChild(spt);

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//��һ����������ɫccc4(r,g,b,a) aȡֵ(0~255),Խ��Խ��͸�� ������������Ϊ���,����Ĭ��Ϊ��Ļ��С
	
	float stageWidth = visibleSize.width;
	float stageHeight = visibleSize.height;
	ccColor4B bgColor = ccc4(0, 0, 0, 200);
	float width = 120;
	float height = 90;
	float posX = visibleSize.width / 2;
	float posY = visibleSize.height / 2;

	Guide::init(spt, stageWidth, stageHeight, bgColor);

	Guide::createGuide(width, height, posX, posY);

	posX = 20;
	posY = 20;

	//Guide::createGuide(130, posX, posY);

	Guide::move(posX, posY);

	//Guide::clear();

	//spt->removeFromParent();
	//spt = NULL;

	CCLOG("isShowing %d", Guide::isShowing());
}


GuideTest::~GuideTest()
{
}
