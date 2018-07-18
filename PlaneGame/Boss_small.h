#pragma once
#include "Boss.h"
class CBoss_small :
	public CBoss
{
public:
	CBoss_small(int, int);
	~CBoss_small(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	void AddBomb(CObList*, CMe*);
	static CImageList m_Images;
	BOOL Fired();
	void Change()
	{
		m_nLife = m_nLife - 1;
	}
	int GetLife()
	{
		return m_nLife;
	}
	BOOL Attacked(int&);

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_WIDTH, m_ptPos.y + BOSS_HEIGHT));
	}

private:
	static const int BOSS_WIDTH = 62;
	static const int BOSS_HEIGHT = 90;
	int m_nType;

};

