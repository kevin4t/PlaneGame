#pragma once
#include "GameObject.h"
#include "Me.h"
class CEnemy :
	public CGameObject
{
public:
	CEnemy();
	~CEnemy();
	virtual BOOL Attacked(int&) = 0;//�Ƿ����ɾ��
	virtual void AddBomb(CObList*, CMe*) = 0;//����ӵ���������
	virtual BOOL IsBoss() = 0;
protected:
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����	 
	int m_nImgIndex;//ͼ������
	int    m_nWait;//������ʱ
	int m_nV;//�ٶ�


};

