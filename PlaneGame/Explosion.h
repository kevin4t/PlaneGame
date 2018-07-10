#pragma once
#include "GameObject.h"
class CExplosion :
	public CGameObject
{
public:
	CExplosion(int, int);
	~CExplosion();

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 64, m_ptPos.y + 64));
	}
private:
	static CImageList m_Images;
	int   m_nProcess;
};

