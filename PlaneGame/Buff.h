#pragma once
#include "GameObject.h"
#include "Me.h"
class CBuff :
	public CGameObject
{
public:
	//枚举
	enum ObjType { enEnemy, enBomb, enBall, enExplosion, enBlood, enBuff };

	CBuff(); //0:加血, 1:防护罩, 2:子弹（1）, 3:子弹（2）
	~CBuff();
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 60, m_ptPos.y + 107));
	}
	void GetBuff(CObList* listObj, CMe* myPlane);
private:
	static CImageList m_Images;
	int m_nType;
};

