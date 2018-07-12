#pragma once
#include "GameObject.h"
#include "Me.h"
class CEnemy_middle :
	public CGameObject
{
public:
	CEnemy_middle(CMe*);
	~CEnemy_middle();
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 38, m_ptPos.y + 38));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
private:
	static CImageList m_Images;
	int    m_nMotion;//���� 1~12 ��12�㷽��˳ʱ��
	int m_nImgIndex;//ͼ������
	CMe *pPlane;
};

