#include "stdafx.h"
#include "backgroud.h"
#include "resource.h"

Cbackgroud::Cbackgroud(void)
{
}

CImageList Cbackgroud::m_Images;
Cbackgroud::~Cbackgroud(void)
{
}

BOOL Cbackgroud::Draw(CDC* pDC, BOOL bPause)
{
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}
BOOL  Cbackgroud::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Background, RGB(0, 0, 0), 650, 1000, 1);
}