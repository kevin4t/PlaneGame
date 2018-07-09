#pragma once
#include "GameObject.h"
class Cbackgroud :
	public CGameObject
{
public:
	Cbackgroud();
	~Cbackgroud();
	BOOL Draw(CDC* pDC, BOOL bPause);
	CRect CGameObject::GetRect()
	{
		return CRect(m_ptPos, CPoint(650,1000));
	}

	static BOOL LoadImage();
private:
	static CImageList m_Images;
};

