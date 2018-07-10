#pragma once
#include "GameObject.h"
class CBuff :
	public CGameObject
{
public:
	CBuff();
	~CBuff();
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 60, m_ptPos.y + 107));
	}
private:
	static CImageList m_Images;
};

