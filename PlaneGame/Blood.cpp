#include "stdafx.h"
#include "Blood.h"
#include "resource.h"
CImageList CBlood::m_Images;

CBlood::CBlood(int x):CGameObject(x)
{
}


CBlood::~CBlood()
{
}


BOOL CBlood::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Heart, RGB(255, 255, 255), 30, 32, 1);
}

BOOL CBlood::Draw(CDC* pDC, BOOL bPause)
{
	
	//if(m_ptPos.y<20) return false;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}
