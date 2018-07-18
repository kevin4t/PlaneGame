#include "stdafx.h"
#include "Background.h"
#include "resource.h"

CBackground::CBackground()
{
}


CBackground::~CBackground(void)
{
}

BOOL CBackground::Draw(CDC* pDC, BOOL bPause)
{
	return m_Images.Draw(pDC, m_nScene, m_ptPos, ILD_TRANSPARENT);
}

BOOL CBackground::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Background, RGB(0, 0, 0), 650, 1000, 1);
}

CImageList CBackground::m_Images;