#include "stdafx.h"
#include "Explosion.h"
#include "Resource.h"
CImageList CExplosion::m_Images;

CExplosion::CExplosion(int x, int y):CGameObject(x, y), m_nProcess(0)
{
}

BOOL CExplosion::Draw(CDC* pDC, BOOL bPause)
{
	if (m_nProcess == 15)
	{
		m_nProcess = 0;
		return FALSE;
	}

	//用新位置绘制图像
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	m_nProcess++;
	return TRUE;
}
CExplosion::~CExplosion()
{
}


BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Explosion, RGB(0, 0, 0), 64, 64, 1);
}
