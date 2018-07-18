#pragma once
#include "GameObject.h"
class CBackhole :
	public CGameObject
{
public:
	CBackhole();
	~CBackhole(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 200, m_ptPos.y + 200));
	}

private:
	static CImageList m_Images;
};

