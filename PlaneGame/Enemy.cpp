#include "stdafx.h"
#include "Enemy.h"
#include "Resource.h"

CImageList CEnemy::m_Images;

CEnemy::CEnemy(void)
{


	//确定XY位置
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMY_HEIGHT) + 1;
	m_ptPos.y = ENEMY_HEIGHT;

	//确定运动方向
	m_nMotion = 1;

	//随机确定速度
	m_V = rand() % 6 + 2;

	m_nWait = 0;
}

CEnemy::~CEnemy(void)
{
}
BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_small, RGB(0, 0, 0), 32, 23, 1);
}
BOOL CEnemy::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>20)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;
	}

	if (m_ptPos.y > GAME_HEIGHT + ENEMY_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}
BOOL CEnemy::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}