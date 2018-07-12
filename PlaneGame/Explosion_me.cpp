#include "stdafx.h"
#include "Explosion_me.h"
#include "resource.h"
CImageList CExplosion_me::m_Images;
CExplosion_me::CExplosion_me(int x, int y):CGameObject(x, y), m_nProcess(0)
{
}


CExplosion_me::~CExplosion_me()
{
}

BOOL CExplosion_me::Draw(CDC* pDC, BOOL bPause)
{
	if (m_nProcess == 13)
	{
		m_nProcess = 0;
		return FALSE;
	}

	//用新位置绘制图像
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	m_nProcess++;
	return TRUE;
}


BOOL CExplosion_me::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Explosion_me, RGB(255, 255, 255), 60, 76, 1);
}
