#include "stdafx.h"
#include "Boss_big.h"
#include "resource.h"
#include "Bomb_enemy.h"
#include "Boss_small.h"
CImageList CBoss_big::m_Images;

CBoss_big::CBoss_big(int m) 
{
	//初始化BOSS血量
	m_nNumber = m;
	//确定XY位置
	m_ptPos.x = 0;
	m_ptPos.y = 100;
	//确定运动方向
	m_nMotion = 1;
	//确定速度
	m_nV = 5;
	m_nWait = 0;
	m_nCreationWait = 0;
	m_nLife = m_nNumber;
}


CBoss_big::~CBoss_big(void)
{
}
BOOL CBoss_big::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
BOOL CBoss_big::Attacked(int& score)
{
	m_nLife -= 1;
	if (m_nLife == 0)
	{
		score += 1000;
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}
BOOL CBoss_big::Created()
{
	if (m_nCreationWait == 0)return true;
	else
	{
		return false;
	}
}
BOOL CBoss_big::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Boss_big, RGB(255, 255, 255), 400, 150, 1);
}
BOOL CBoss_big::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	m_nCreationWait++;
	if (m_nWait>10)
		m_nWait = 0;
	if (m_nCreationWait > 150)
	{
		m_nCreationWait = 0;
	}
	if (!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nMotion * m_nV;
		m_ptPos.y = (0.0064)*(m_ptPos.x - 125)*(m_ptPos.x - 125);
	}

	if (m_ptPos.x > GAME_WIDTH - 400)
		m_nMotion *= -1;
	if (m_ptPos.x < 0)
		m_nMotion *= -1;


	CString str;
	CPoint p = this->GetPoint();
	str.Format(_T("HP:  %d / %d"), this->GetLife(), m_nNumber);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextAlign(TA_TOP);
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOut(p.x, p.y + 190, str);

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}
void CBoss_big::AddBomb(CObList* listObj, CMe* myPlane)
{
	CPoint pt = this->GetPoint();
	if (this->Fired())
	{
		listObj[enBall].AddTail(new CBomb_enemy(pt.x, pt.y + 150, -2, 1));
		listObj[enBall].AddTail(new CBomb_enemy(pt.x + 100, pt.y + 150, -1, 1));
		listObj[enBall].AddTail(new CBomb_enemy(pt.x + 200, pt.y + 150, 0, 1));
		listObj[enBall].AddTail(new CBomb_enemy(pt.x + 300, pt.y + 150, 1, 1));
		listObj[enBall].AddTail(new CBomb_enemy(pt.x + 400, pt.y + 150, 2, 1));
	}
	if (this->Created())
	{
		listObj[enEnemy].AddTail(new CBoss_small(20, 3));
	}
}