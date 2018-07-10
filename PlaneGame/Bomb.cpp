#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"

CImageList CBomb::m_Images;

CBomb::~CBomb(void)
{
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.y = m_ptPos.y - 15;
	//if(m_ptPos.y<20) return false;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_blue_bullet, RGB(0, 0, 0), 4, 10, 1);
}

