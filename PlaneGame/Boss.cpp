#include "stdafx.h"
#include "Boss.h"
#include "resource.h"

CImageList CBoss::m_Images;

CBoss::CBoss(void)
{


	//确定XY位置
	m_ptPos.x = 200;
	m_ptPos.y = 30;

	//确定运动方向
	m_nMotion = 1;

	m_V = 10;

	m_nWait = 0;
}

CBoss::~CBoss(void)
{
}
BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BIG, RGB(0, 0, 0), 62, 90, 1);
}
BOOL CBoss::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>25)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nMotion * m_V;
	}

	if (m_ptPos.x > GAME_WIDTH-62)
		m_nMotion *= -1;
	if (m_ptPos.x < 0)
		m_nMotion *= -1;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}
BOOL CBoss::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}