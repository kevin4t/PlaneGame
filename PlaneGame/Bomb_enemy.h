#pragma once
#include "GameObject.h"
class CBomb_enemy :
	public CGameObject
{
public:
	CBomb_enemy(int x, int y, int c, int nMontion) :CGameObject(x, y), m_nChange(c),m_nMotion(nMontion)
	{
		m_nPx = x; m_nPy = y;
	}

	~CBomb_enemy(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + CBomb_enemy_HEIGHT, m_ptPos.y + CBomb_enemy_HEIGHT));
	}
private:
	static const int CBomb_enemy_HEIGHT = 10;
	static CImageList m_Images;
	int    m_nMotion;
	int m_nChange;
	int m_nPx, m_nPy;
};

