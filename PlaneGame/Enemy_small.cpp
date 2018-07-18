#include "stdafx.h"
#include "Enemy_small.h"
#include "Resource.h"
#include "me.h"
#include "Bomb_enemy.h"
CImageList CEnemy_small::m_Images;

CEnemy_small::CEnemy_small(void)
{


	//确定XY位置
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMY_HEIGHT) + 1;
	m_ptPos.y = ENEMY_HEIGHT;

	//确定运动方向
	m_nMotion = 1;


	m_nWait = 0;
}

CEnemy_small::~CEnemy_small(void)
{
}
BOOL CEnemy_small::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_small, RGB(0, 0, 0), 32, 23, 1);
}
BOOL CEnemy_small::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>20)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * 5;
	}

	if (m_ptPos.y > GAME_HEIGHT + ENEMY_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}
BOOL CEnemy_small::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
BOOL CEnemy_small::Attacked(int& score)
{
	score++;
	return TRUE;

}
void CEnemy_small::AddBomb(CObList* listObj, CMe* myPlane)
{
	CPoint pt = this->GetPoint();
	CPoint mpt = myPlane->GetPoint();
	if (!this->Fired())
		return;
	BOOL by = FALSE;
	if (this->GetMontion() == 1 && pt.y < mpt.y)
		by = TRUE;
	if (by &&pt.x >= mpt.x - 50 && pt.x < mpt.x + 50)
	{
		listObj[enBall].AddTail(new CBomb_enemy(pt.x + 14, pt.y + 18, 0, this->GetMontion()));
	}
}