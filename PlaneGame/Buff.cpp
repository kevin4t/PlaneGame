#include "stdafx.h"
#include "Buff.h"
#include "Resource.h"
#include "Me.h"
#include "Blood.h"

CImageList CBuff::m_Images;

CBuff::CBuff()
{
	m_nType = rand() % 4;
	m_ptPos.x = rand() % 650 ;
}


CBuff::~CBuff()
{
}

BOOL CBuff::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Buff, RGB(255, 255, 255), 60, 107, 1);
}

BOOL CBuff::Draw(CDC* pDC, BOOL bPause)
{


	if (m_ptPos.y > 1000) return FALSE;
	m_ptPos.y = m_ptPos.y + 5;
	m_Images.Draw(pDC, m_nType, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

void CBuff::GetBuff(CObList* listObj, CMe* myPlane)
{
	if (m_nType == 0 && listObj[enBlood].GetCount() <= 4)
	{
		int numOfHeart = listObj[enBlood].GetCount();
		int heart_x = numOfHeart * 30;
		listObj[enBlood].AddTail(new CBlood(heart_x));
	}
	else if (m_nType == 1 && !myPlane->IsRealNoEnemy())
	{
		myPlane->WhosYourDaddy(TRUE);
	}
	else if (m_nType >= 2)
	{
		myPlane->SetBullet(m_nType - 1);
	}
	
}