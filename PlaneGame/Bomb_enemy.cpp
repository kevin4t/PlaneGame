#include "stdafx.h"
#include "Bomb_enemy.h"
#include "resource.h"

CImageList CBomb_enemy::m_Images;

CBomb_enemy::CBomb_enemy(int x, int y, int nMontion) :CGameObject(x,y), m_nMotion(nMontion)
{
}

CBomb_enemy::~CBomb_enemy(void)
{
}
BOOL CBomb_enemy::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y +8* m_nMotion;
	}

	if (m_ptPos.y > GAME_HEIGHT + CBomb_enemy_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -CBomb_enemy_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}
BOOL CBomb_enemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_yellow_bullet, RGB(0, 0, 0), 4, 10, 1);
}