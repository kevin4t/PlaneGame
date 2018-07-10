#pragma once
#include "GameObject.h"
class CBlood :
	public CGameObject
{
public:
	CBlood(int);
	~CBlood();
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 30 , m_ptPos.y + 32));
	}
private:
	static CImageList m_Images;
};


