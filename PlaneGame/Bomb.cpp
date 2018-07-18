#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"

CImageList CBomb::m_Images;

CBomb::~CBomb(void)
{
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	if(m_nChange==0)
	m_ptPos.y = m_ptPos.y - 12;
	if (m_nChange == 1)//ÓÒÆ«
	{
		m_ptPos.x = m_ptPos.x + 6;
		m_ptPos.y = m_ptPos.y - 12;
	}
	if (m_nChange == 2)
	{
		m_ptPos.x = m_ptPos.x + 9;
		m_ptPos.y = m_ptPos.y - 9;
	}
	if (m_nChange == -1)//×óÆ«
	{
		m_ptPos.x = m_ptPos.x - 6;
		m_ptPos.y = m_ptPos.y - 12;
	}
	if (m_nChange == -2)
	{
		m_ptPos.x = m_ptPos.x - 9;
		m_ptPos.y = m_ptPos.y - 9;
	}
	if (m_nChange == 3)
	{
		if (m_ptPos.x - m_nPx < 50)
		{
			m_ptPos.x = m_ptPos.x + 4;
			m_ptPos.y = m_ptPos.y - 2;
		}
		else
		{
			m_ptPos.y = m_ptPos.y - 12;
		}
	}
	if (m_nChange == -3)
	{
		if (m_ptPos.x - m_nPx > -50)
		{
			m_ptPos.x = m_ptPos.x - 4;
			m_ptPos.y = m_ptPos.y - 2;
		}
		else
		{
			m_ptPos.y = m_ptPos.y - 12;
		}
	}
	return m_Images.Draw(pDC, m_nBulletType, m_ptPos, ILD_TRANSPARENT);
}

BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Bomb, RGB(255, 255, 255), 4, 28, 1);
}
