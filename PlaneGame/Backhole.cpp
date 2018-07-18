#include "stdafx.h"
#include "Backhole.h"
#include "resource.h"

CBackhole::CBackhole()
{
	m_ptPos.x = 200;
	m_ptPos.y = 30;
}


CBackhole::~CBackhole()
{
}

BOOL CBackhole::Draw(CDC* pDC, BOOL bPause)
{
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CBackhole::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_hole, RGB(255, 255, 255), 200, 200, 1);
}

CImageList CBackhole::m_Images;