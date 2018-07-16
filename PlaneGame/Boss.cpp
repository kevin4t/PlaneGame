#include "stdafx.h"
#include "Boss.h"
#include "resource.h"
#include "Bomb_enemy.h"
CImageList CBoss::m_Images;

CBoss::CBoss(int m):m_life(m)
{
	//确定XY位置
	m_ptPos.x = 200;
	m_ptPos.y = 30;
	//确定运动方向
	m_nMotion = 1;
	//确定速度
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


	CString str;
	CPoint p = this->GetPoint();
	str.Format(_T("HP:  %d / %d"), this->GetLife(), 50);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextAlign(TA_TOP);
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOut(p.x, p.y + 90, str);

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
BOOL CBoss::Attacked(int& score)
{
	m_life -= 1;
	if (m_life == 0)
	{
		score += 1000;
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}
void CBoss::AddBomb(CObList* listObj, CMe* myPlane)
{
	CPoint bossPt = this->GetPoint();
	if (this->Fired())
	{
		listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 100, bossPt.y + 140, 1));
		listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 50, bossPt.y + 120, 1));
		listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 0, bossPt.y + 100, 1));
		listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 50, bossPt.y + 120, 1));
		listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 100, bossPt.y + 140, 1));
	}
}