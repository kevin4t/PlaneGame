#pragma once
#include "GameObject.h"
class CExplosion_me :
	public CGameObject
{
public:
	CExplosion_me(int, int);
	~CExplosion_me();

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 60, m_ptPos.y + 76));
	}
private:
	static CImageList m_Images;
	int   m_nProcess;
};

