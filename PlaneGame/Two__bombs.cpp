#include "stdafx.h"
#include "Two__bombs.h"
#include "resource.h"
CTwo__bombs::~CTwo__bombs(void)
{
}

BOOL CTwo__bombs::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.y = m_ptPos.y - 15;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CTwo__bombs::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_blue_bullet, RGB(0, 0, 0), 4, 10, 1);
}

CImageList CTwo__bombs::m_Images;