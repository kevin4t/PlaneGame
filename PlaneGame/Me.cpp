#include "stdafx.h"
#include "Me.h"
#include "Resource.h"

CMe::CMe(void)
{
	m_ptPos.x = 512;
	m_ptPos.y = 400;
	m_nHorMotion = 0;
	m_nVerMotion = 0;
}

CMe::~CMe(void)
{
}

CImageList CMe::m_Images;

BOOL CMe::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.x = m_ptPos.x + m_nHorMotion * 10;
	m_ptPos.y = m_ptPos.y + m_nVerMotion * 10;
	m_nHorMotion = 0;
	m_nVerMotion = 0;

	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CMe::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Plane, RGB(0, 0, 0), 60, 76, 1);
}

BOOL CMe::Fired()
{
	return true;
}