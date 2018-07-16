#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Me.h"
class CEnemy_middle :
	public CEnemy
{
public:
	//Ã¶¾Ù
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CEnemy_middle(CMe*);
	~CEnemy_middle();
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY_HEIGHT, m_ptPos.y + ENEMY_HEIGHT));
	}

	int GetMontion() 
	{
		return m_nMotion;
	}

	BOOL Attacked(int&);

	void AddBomb(CObList*, CMe*);


private:
	static const int ENEMY_HEIGHT = 38;
	static CImageList m_Images;
	CMe *pPlane;
	
};

