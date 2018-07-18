#pragma once
#include "GameObject.h"
class CBackground :
	public CGameObject
{
public:
	CBackground();
	~CBackground(void);

	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 650, m_ptPos.y + 1000));
	}
	void SetScene(int n)
	{
		m_nScene = n;
	}

private:
	static CImageList m_Images;
	int m_nScene;
};

