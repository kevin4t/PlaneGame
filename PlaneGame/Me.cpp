#include "stdafx.h"
#include "Me.h"
#include "Resource.h"

CMe::CMe(void)
{
	m_ptPos.x = 512;
	m_ptPos.y = 400;
	m_nHorMotion = 0;
	m_nVerMotion = 0;
	m_nWait = 0;
}

CMe::~CMe(void)
{
}

CImageList CMe::m_Images;

BOOL CMe::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>3)
	m_nWait = 0;
	m_ptPos.x = m_ptPos.x + m_nHorMotion * 10;
	m_ptPos.y = m_ptPos.y + m_nVerMotion * 10;
	m_nHorMotion = 0;
	m_nVerMotion = 0;
	if (m_ptPos.x < 0)m_ptPos.x += 10;
	if (m_ptPos.x > 650-77)m_ptPos.x -= 10;
	if (m_ptPos.y < 0)m_ptPos.y += 10;
	if (m_ptPos.y > 1000-116)m_ptPos.y -= 10;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CMe::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Plane, RGB(0, 0, 0), 60, 76, 1);
}

BOOL CMe::Fired()
{
   if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

void CMe::SetPoint(int x = 0, int y = 0)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
}