#pragma once
#include "GameObject.h"
#include "Enemy.h"
class CBoss :
	public CEnemy
{
public:
	//ö��
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CBoss();
	~CBoss();
	BOOL IsBoss()
	{
		return TRUE;
	}
	

protected:
	static CImageList m_Images;
	int m_nLife;//��ǰ����ֵ
	int m_nNumber;//������ֵ
};

