#pragma once
#include "GameObject.h"
class CTwo__bombs :
	public CGameObject
{
public:
	CTwo__bombs(int x, int y) :CGameObject(x, y) {};
	~CTwo__bombs(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;
};

