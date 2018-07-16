#pragma once
#include "GameObject.h"
#include "Enemy.h"
class CBoss :
	public CEnemy
{
public:
	//枚举
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CBoss(int);
	~CBoss(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_HEIGHT, m_ptPos.y + BOSS_HEIGHT));
	}
	//是否可以开火发射子弹
	BOOL Fired();
	void Change()
	{
		m_life = m_life - 1;
	}
	int GetLife()
	{
		return m_life;
	}
	BOOL Attacked(int&);
	void AddBomb(CObList*,CMe*);
private:
	static const int BOSS_HEIGHT = 90;
	static CImageList m_Images;
	int m_life;//生命值
};

