#pragma once
#ifndef _GUIDE_
#define _GUIDE_
#include "cocos2d.h"
USING_NS_CC;
static CCNode* m_parent = NULL;
static CCClippingNode* clipNode = NULL;
//灰色的底板
static CCLayerColor* pLayer = NULL;
//绘制镂空的节点
static CCDrawNode *drawNode = NULL;
class Guide
{
public:
	Guide();
	~Guide();

	//************************************
	// Description:初始化
	// Parameter: CCNode * parent	外部容器
	// Parameter: float stageWidth	舞台宽度
	// Parameter: float stageHeight
	// Parameter: ccColor4B bgColor
	// Returns:   void
	//************************************
	void static init(CCNode* parent, float stageWidth, float stageHeight, ccColor4B bgColor = ccc4(0, 0, 0, 200));

	//************************************
	// Description:创建一个矩形引导
	// Parameter: float width		宽度	
	// Parameter: float height		高度
	// Parameter: float posX		位置x
	// Parameter: float posY		位置y
	// Returns:   void
	//************************************
	void static createGuide(float width, float height, float posX, float posY);

	//************************************
	// Description:
	// Description:创建一个圆形引导
	// Parameter: float radius			半径
	// Parameter: float posX			位置x
	// Parameter: float posY			位置y
	// Returns:   void
	//************************************
	void static createGuide(float radius, float posX, float posY);

	
	void static move(float posX, float posY);
};
#endif
