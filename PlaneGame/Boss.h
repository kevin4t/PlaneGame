#pragma once
#include "GameObject.h"
class CBoss :
	public CGameObject
{
public:
	CBoss(void);
	~CBoss(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSS_HEIGHT, m_ptPos.y + BOSS_HEIGHT));
	}
	//是否可以开火发射子弹
	BOOL Fired();
	void SetLife()
	{
		m_life = 50;
	}
	void Change()
	{
		m_life = m_life - 1;
	}
	int GetLife()
	{
		return m_life;
	}
private:
	static const int BOSS_HEIGHT = 90;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向左 0->停止 -1->向右
					 //图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	int m_life;//生命值
};

