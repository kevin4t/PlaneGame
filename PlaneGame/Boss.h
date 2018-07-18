#pragma once
#include "GameObject.h"
#include "Enemy.h"
class CBoss :
	public CEnemy
{
public:
	//枚举
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CBoss();
	~CBoss();
	BOOL IsBoss()
	{
		return TRUE;
	}
	

protected:
	static CImageList m_Images;
	int m_nLife;//当前生命值
	int m_nNumber;//总生命值
};

