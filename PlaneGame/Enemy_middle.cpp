#include "stdafx.h"
#include "Enemy_middle.h"
#include "resource.h"
#include "cmath"
#define PI 3.1415926
CImageList CEnemy_middle::m_Images;
CEnemy_middle::CEnemy_middle(CMe* p):pPlane(p)
{
	switch (rand() % 4)
	{
	case 0:
	{	m_ptPos.x = 0;
		m_ptPos.y = rand() % 1000;
		break;
	}
	case 1:
	{
		m_ptPos.y = 0;
		m_ptPos.x = rand() % 650;
		break;
	}
	case 2:
	{
		m_ptPos.x = 650;
		m_ptPos.y = rand() % 1000;
		break;
	}
	case 3:
	{
		m_ptPos.y = 1000;
		m_ptPos.x = rand() % 650;
		break;
	}
	}

	//测试数据
	//m_nMotion = 4;
	//m_ptPos.x = 300;
	//m_ptPos.y = 300;
}
CEnemy_middle::~CEnemy_middle(void)
{
	
}
BOOL CEnemy_middle::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Middle, RGB(255, 255, 255), 38, 38, 1);
}
BOOL CEnemy_middle::Draw(CDC* pDC, BOOL bPause)
{
	if (pPlane == NULL)return FALSE;
	CPoint pP = pPlane->GetPoint();
	CPoint pE = m_ptPos;
	if (pP.x == pE.x)
	{
		if (pP.y >= pE.y)
		{
			m_nMotion = 6;
		}
		else
		{
			m_nMotion = 0;
		}

	}
	else
	{
		//计算斜率
		double k = (double)(pP.y - pE.y) / (pE.x - pP.x);

		//判断方向
		if (k >= -tan(PI / 12) && k < tan(PI / 12))
		{
			if (pP.x >= pE.x)
			{
				m_nMotion = 3;
			}
			else
			{
				m_nMotion = 9;
			}
		}
		else if (k >= tan(PI / 12) && k < 1)
		{
			if (pP.x >= pE.x)
				m_nMotion = 2;
			else
				m_nMotion = 8;
		}
		else if (k >= 1 && k < tan(5*PI / 12))
		{
			if (pP.x >= pE.x)
				m_nMotion = 1;
			else
				m_nMotion = 7;
		}
		else if (k >= tan(5 * PI / 12) || k < -tan(5 * PI / 12))
		{
			if (pP.y >= pE.y)
				m_nMotion = 6;
			else
				m_nMotion = 0;
		}


		else if (k >= -1 && k < -tan(PI / 12))
		{
			if (pP.x >= pE.x)
				m_nMotion = 4;
			else
				m_nMotion = 10;
		}
		else if (k >= -tan(5 * PI / 12) && k < -1)
		{
			if (pP.x >= pE.x)
				m_nMotion = 5;
			else
				m_nMotion = 11;
		}
	}

	if (m_nMotion == 0)
	{
		m_ptPos.y -= 10;
	}
	else if (m_nMotion == 6)
	{
		m_ptPos.y += 10;
	}
	else if (m_nMotion > 0 && m_nMotion <= 3)
	{
		m_ptPos.x += 10 * cos((3-m_nMotion)*PI / 6);
		m_ptPos.y -= 10 * sin((3-m_nMotion)*PI / 6);
	}
	else if (m_nMotion > 3 && m_nMotion < 6)
	{
		m_ptPos.x += 10 * cos((6-m_nMotion)*PI / 6);
		m_ptPos.y += 10 * sin((6-m_nMotion)*PI / 6);
	}
	else if (m_nMotion > 6 && m_nMotion <= 9)
	{
		m_ptPos.x += 10 * cos((3-m_nMotion)*PI / 6);
		m_ptPos.y -= 10 * sin((3-m_nMotion)*PI / 6);
	}
	else if (m_nMotion > 9 && m_nMotion <= 11)
	{
		m_ptPos.x += 10 * cos((6-m_nMotion)*PI / 6);
		m_ptPos.y += 10 * sin((6-m_nMotion)*PI / 6);
	}

	m_Images.Draw(pDC, m_nMotion, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}