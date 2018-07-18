#pragma once
#include "gameobject.h"
#include "Enemy.h"

class CEnemy_small :public CEnemy
{
public:
	//枚举
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CEnemy_small(void);
	~CEnemy_small(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	BOOL IsBoss()
	{
		return FALSE;
	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY_HEIGHT, m_ptPos.y + ENEMY_HEIGHT));
	}

	int GetMontion() 
	{
		return m_nMotion;
	}
	//是否可以开火发射子弹
	BOOL Fired();

	//受到攻击
	BOOL Attacked(int&);

	//添加子弹
	void AddBomb(CObList*,CMe*);
private:
	static const int ENEMY_HEIGHT = 35;
	static CImageList m_Images;

};
