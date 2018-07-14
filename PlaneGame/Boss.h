#pragma once
#include "GameObject.h"
class CBoss :
	public CGameObject
{
public:
	CBoss(void);
	~CBoss(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_HEIGHT, m_ptPos.y + BOSS_HEIGHT));
	}
	//�Ƿ���Կ������ӵ�
	BOOL Fired();
	void SetLife()
	{
		m_life = 50;
	}
	void Change()
	{
		m_life = m_life - 1;
	}
	int GetLife()
	{
		return m_life;
	}
private:
	static const int BOSS_HEIGHT = 90;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
					 //ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
	int m_life;//����ֵ
};

