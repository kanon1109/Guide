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
	//第一个参数是颜色ccc4(r,g,b,a) a取值(0~255),越大越不透明 下面两个参数为宽高,不传默认为屏幕大小
	
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
