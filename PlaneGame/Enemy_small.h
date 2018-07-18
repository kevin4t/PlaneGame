#pragma once
#include "gameobject.h"
#include "Enemy.h"

class CEnemy_small :public CEnemy
{
public:
	//ö��
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
	//�Ƿ���Կ������ӵ�
	BOOL Fired();

	//�ܵ�����
	BOOL Attacked(int&);

	//����ӵ�
	void AddBomb(CObList*,CMe*);
private:
	static const int ENEMY_HEIGHT = 35;
	static CImageList m_Images;

};
