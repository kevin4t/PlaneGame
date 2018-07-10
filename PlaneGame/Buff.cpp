#include "stdafx.h"
#include "Buff.h"
#include "Resource.h"

CImageList CBuff::m_Images;

CBuff::CBuff()
{
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
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}