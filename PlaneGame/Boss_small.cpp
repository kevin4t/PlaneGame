#include "stdafx.h"
#include "Boss_small.h"
#include "resource.h"
#include "Bomb_enemy.h"
CImageList CBoss_small::m_Images;

CBoss_small::CBoss_small(int m, int t):m_nType(t)
{
	m_nNumber = m;
	//确定XY位置
	if (m_nType == 3)
	{
		m_ptPos.x = 200;
		m_ptPos.y = 200;
	}
	if (m_nType == 1) 
	{
		m_ptPos.x = 0;
		m_ptPos.y = 30;
	}
	if (m_nType == 2)
	{
		m_ptPos.x = 80;
		m_ptPos.y = 90;
	}
	//确定运动方向
	m_nMotion = 1;
	//确定速度
	m_nV = 10;
	m_nWait = 0;
	m_nLife = m_nNumber;
}


CBoss_small::~CBoss_small(void)
{
}
BOOL CBoss_small::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
BOOL CBoss_small::Attacked(int& score)
{
	m_nLife -= 1;
	if (m_nLife == 0)
	{
		if (m_nType == 1 || m_nType == 3)score += 50;
		if (m_nType == 2)score += 300;
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}
BOOL CBoss_small::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Boss_small, RGB(0, 0, 0), 62, 90, 1);
}
BOOL CBoss_small::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>25)
		m_nWait = 0;
	if (m_nType==1)
	{
		m_ptPos.x = m_ptPos.x + m_nMotion * m_nV;
		if (m_ptPos.x > GAME_WIDTH - 62)
			m_nMotion *= -1;
		if (m_ptPos.x < 0)
			m_nMotion *= -1;
		CString str;
		CPoint p = this->GetPoint();
		str.Format(_T("HP:  %d / %d"), this->GetLife(), m_nNumber);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextAlign(TA_TOP);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(p.x, p.y + 90, str);
	}
	if (m_nType == 2)
	{
		if (m_nMotion == 1)
		{
			m_ptPos.x = m_ptPos.x + m_nMotion * m_nV;
			m_ptPos.y = (0.00218)*(m_ptPos.x - 294)*(m_ptPos.x - 294);
		}
		if (m_nMotion == -1)
		{
			m_ptPos.x = m_ptPos.x + m_nMotion * m_nV;
			m_ptPos.y = (-0.00218)*(m_ptPos.x - 294)*(m_ptPos.x - 294)+200;
		}
		if (m_ptPos.x > GAME_WIDTH - 62-80)
			m_nMotion *= -1;
		if (m_ptPos.x < 90)
			m_nMotion *= -1;
		CString str;
		CPoint p = this->GetPoint();
		str.Format(_T("HP:  %d / %d"), this->GetLife(), m_nNumber);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextAlign(TA_TOP);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(p.x, p.y + 90, str);
	}
	if (m_nType == 3)
	{
		m_ptPos.x = m_ptPos.x + m_nMotion * m_nV;
		if (m_ptPos.x > GAME_WIDTH - 62)
			m_nMotion *= -1;
		if (m_ptPos.x < 0)
			m_nMotion *= -1;
	}
	
	m_Images.Draw(pDC, m_nType-1, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}
void CBoss_small::AddBomb(CObList* listObj, CMe* myPlane)
{
	CPoint bossPt = this->GetPoint();
	if (m_nType == 3)
	{
		if (this->Fired())
		{
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x, bossPt.y + 95, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x +60, bossPt.y + 95, 0, 1));
		}
	}
	if (m_nType == 1)
	{
		if (this->Fired())
		{
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 100, bossPt.y + 140, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 50, bossPt.y + 120, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 0, bossPt.y + 100, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 50, bossPt.y + 120, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 100, bossPt.y + 140, 0, 1));
		}
	}
	if (m_nType == 2)
	{
		if (this->Fired())
		{
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 30, bossPt.y - 10, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 17, bossPt.y + 10, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 77, bossPt.y + 10, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 50, bossPt.y + 46, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 110, bossPt.y + 46, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 70, bossPt.y + 90, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 130, bossPt.y + 90, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 50, bossPt.y + 134, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 110, bossPt.y + 134, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x - 17, bossPt.y + 170, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 77, bossPt.y + 170, 0, 1));
			listObj[enBall].AddTail(new CBomb_enemy(bossPt.x + 30, bossPt.y + 190, 0, 1));
		}
	}
}