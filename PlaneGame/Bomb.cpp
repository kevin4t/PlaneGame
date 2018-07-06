#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"


CBomb::~CBomb(void)
{
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.y = m_ptPos.y - 5;
	//if(m_ptPos.y<20) return false;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Bomb, RGB(0, 0, 0), 10, 20, 1);
}

CImageList CBomb::m_Images;