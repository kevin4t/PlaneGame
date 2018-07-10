#pragma once
#include "GameObject.h"
class CBomb_enemy :
	public CGameObject
{
public:
	CBomb_enemy(int x, int y, int nMontion);

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
};

