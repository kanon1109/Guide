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
	//����drawnode����
	CCPoint rect[4] = { ccp(-width * .5, height * .5), ccp(width * .5, height * .5),
					    ccp(width * .5, -height * .5), ccp(-width * .5, -height * .5) };
	//����������ݱ���һ��100x100�ľ���
	drawNode->drawPolygon(rect, 4, ccc4f(0, 0, 0, 0), 0, ccc4f(0, 0, 0, 0));
	//���õ���Ļ������
	drawNode->setPosition(ccp(posX, posY));
}

void Guide::createGuide(float radius, float posX, float posY)
{
	Guide::create();
	if (!drawNode) return;
	//Բ����ʵ���Կ����������,������������100������ģ��Բ
	const int count = 100;
	//����ÿ�������ڶ��������ĵļн�
	const float coef = 2.0f * (float)M_PI / count;
	//��������
	CCPoint circle[count];
	for (unsigned int i = 0; i < count; ++i)
	{
		//����
		float rads = i * coef;
		//��Ӧ�����x
		circle[i].x = radius * cosf(rads);
		//��Ӧ�����y
		circle[i].y = radius * sinf(rads);
	}
	drawNode->drawPolygon(circle, count, ccc4f(0, 0, 0, 0), 0, ccc4f(0, 0, 0, 0));
	//���õ���Ļ������
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
	//����cliper����
	if (!clipNode) clipNode = CCClippingNode::create();
	//�����ɫ�ĵװ�
	if (!pLayer) pLayer = CCLayerColor::create(m_bgColor, m_stageWidth, m_stageHeight);
	//�����οյ�����ڵ�
	if (!drawNode) drawNode = CCDrawNode::create();
	if (!clipNode->getParent()) m_parent->addChild(clipNode);
	if (!pLayer->getParent()) clipNode->addChild(pLayer);
	//�Ƿ���?
	clipNode->setInverted(true);
	//����Ϊpclip��ģ��
	clipNode->setStencil(drawNode);
}
