#include "Guide.h"

Guide::Guide()
{
}

Guide::~Guide()
{
}

void Guide::init(CCNode* parent, float stageWidth, float stageHeight, ccColor4B bgColor /*= ccc4(0, 0, 0, 200)*/)
{
	m_parent = parent;
	m_stageWidth = stageWidth;
	m_stageHeight = stageHeight;
	m_bgColor = bgColor;
}

void Guide::createGuide(float width, float height, float posX, float posY)
{
	Guide::create();
	if (!drawNode) return;
	//创建drawnode对象
	CCPoint rect[4] = { ccp(-width * .5, height * .5), ccp(width * .5, height * .5),
					    ccp(width * .5, -height * .5), ccp(-width * .5, -height * .5) };
	//用上面的数据保存一个100x100的矩形
	drawNode->drawPolygon(rect, 4, ccc4f(0, 0, 0, 0), 0, ccc4f(0, 0, 0, 0));
	//设置到屏幕的中心
	drawNode->setPosition(ccp(posX, posY));
}

void Guide::createGuide(float radius, float posX, float posY)
{
	Guide::create();
	if (!drawNode) return;
	//圆形其实可以看做正多边形,我们这里用正100边型来模拟圆
	const int count = 100;
	//计算每两个相邻顶点与中心的夹角
	const float coef = 2.0f * (float)M_PI / count;
	//顶点数组
	CCPoint circle[count];
	for (unsigned int i = 0; i < count; ++i)
	{
		//弧度
		float rads = i * coef;
		//对应顶点的x
		circle[i].x = radius * cosf(rads);
		//对应顶点的y
		circle[i].y = radius * sinf(rads);
	}
	drawNode->drawPolygon(circle, count, ccc4f(0, 0, 0, 0), 0, ccc4f(0, 0, 0, 0));
	//设置到屏幕的中心
	drawNode->setPosition(ccp(posX, posY));
}

void Guide::move(float posX, float posY)
{
	if (!drawNode) return;
	drawNode->setPosition(posX, posY);
}

void Guide::clear()
{
	if (drawNode)
	{
		drawNode->clear();
		drawNode->removeFromParent();
	}
	if (clipNode) clipNode->removeFromParent();
	clipNode = NULL;
	if (pLayer) pLayer->removeFromParent();
	pLayer = NULL;
}

bool Guide::isShowing()
{
	if (!clipNode) return false;
	return true;
}

void Guide::create()
{
	if (!m_parent) return;
	//创建cliper对象
	if (!clipNode) clipNode = CCClippingNode::create();
	//加入灰色的底板
	if (!pLayer) pLayer = CCLayerColor::create(m_bgColor, m_stageWidth, m_stageHeight);
	//绘制镂空的区域节点
	if (!drawNode) drawNode = CCDrawNode::create();
	if (!clipNode->getParent()) m_parent->addChild(clipNode);
	if (!pLayer->getParent()) clipNode->addChild(pLayer);
	//是否反向?
	clipNode->setInverted(true);
	//设置为pclip的模板
	clipNode->setStencil(drawNode);
}
