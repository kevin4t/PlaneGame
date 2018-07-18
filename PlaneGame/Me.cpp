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
	m_bNoEnemy = FALSE;
	m_bRealNoEnemy = FALSE;
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

	//防止飞机出界
	if (m_ptPos.x < 0)m_ptPos.x += 10;
	if (m_ptPos.x > 650-77)m_ptPos.x -= 10;
	if (m_ptPos.y < 0)m_ptPos.y += 10;
	if (m_ptPos.y > 1000-116)m_ptPos.y -= 10;

	//无敌时间限制
	if (m_bNoEnemy == TRUE)
	{
		m_nCount++;
	}
	if (m_nCount == 200)m_bNoEnemy = FALSE;
	return m_Images.Draw(pDC, m_bNoEnemy, m_ptPos, ILD_TRANSPARENT);
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

void CMe:: WhosYourDaddy(BOOL TF)
{
	if (TF == TRUE)
	{
		m_nCount = 0;
	}
 	m_bNoEnemy = TF;
}
void CMe::WZH()
{
	m_nCount = 666;
	m_bRealNoEnemy = TRUE;
	m_bNoEnemy = TRUE;
}
BOOL CMe::IsNoEnemy()
{
	return m_bNoEnemy;
}
BOOL CMe::IsRealNoEnemy()
{
	return m_bRealNoEnemy;
}