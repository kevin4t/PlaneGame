#pragma once
#include "Boss.h"
class CBoss_big :
	public CBoss
{
public:
	CBoss_big(int);
	~CBoss_big(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	void AddBomb(CObList*, CMe*);
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
	BOOL Created();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_WIDTH, m_ptPos.y + BOSS_HEIGHT));
	}
private:
	static const int BOSS_WIDTH = 400;
	static const int BOSS_HEIGHT = 150;
	static CImageList m_Images;
	int m_nCreationWait;//创建子机延时
};

