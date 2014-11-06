#pragma once
#ifndef _GUIDE_
#define _GUIDE_
#include "cocos2d.h"
USING_NS_CC;
static CCNode* m_parent = NULL;
static CCClippingNode* clipNode = NULL;
//��ɫ�ĵװ�
static CCLayerColor* pLayer = NULL;
//�����οյĽڵ�
static CCDrawNode *drawNode = NULL;
//��̨���
static float m_stageWidth = 960;
//��̨�߶�
static float m_stageHeight = 640;
//������ɫ
static ccColor4B m_bgColor = ccc4(0, 0, 0, 200);
class Guide
{
public:
	Guide();
	~Guide();

	//************************************
	// Description:��ʼ��
	// Parameter: CCNode * parent	�ⲿ����
	// Parameter: float stageWidth	��̨���
	// Parameter: float stageHeight
	// Parameter: ccColor4B bgColor
	// Returns:   void
	//************************************
	void static init(CCNode* parent, float stageWidth, float stageHeight, ccColor4B bgColor = ccc4(0, 0, 0, 200));

	//************************************
	// Description:����һ����������
	// Parameter: float width		���	
	// Parameter: float height		�߶�
	// Parameter: float posX		λ��x
	// Parameter: float posY		λ��y
	// Returns:   void
	//************************************
	void static createGuide(float width, float height, float posX, float posY);

	//************************************
	// Description:
	// Description:����һ��Բ������
	// Parameter: float radius			�뾶
	// Parameter: float posX			λ��x
	// Parameter: float posY			λ��y
	// Returns:   void
	//************************************
	void static createGuide(float radius, float posX, float posY);

	//�ƶ�����	
	void static move(float posX, float posY);

	//�������
	void static clear();

	//���������Ƿ�������ʾ��
	bool static isShowing();

private:
	void static create();
};
#endif
