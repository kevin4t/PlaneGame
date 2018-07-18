#pragma once
#include "gameobject.h"

class CBomb :
	public CGameObject
{
public:
	CBomb(int x, int y, int c, int type) :CGameObject(x, y), m_nChange(c), m_nBulletType(type)
	{
		m_nPx = x; m_nPy = y;
	}
	~CBomb(void);
	
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;
	int m_nChange;
	int m_nPx,m_nPy;
	int m_nBulletType;
};
