#pragma once
#include "GameObject.h"
#include "Me.h"
class CEnemy :
	public CGameObject
{
public:
	CEnemy();
	~CEnemy();
	virtual BOOL Attacked(int&) = 0;//是否可以删除
	virtual void AddBomb(CObList*, CMe*) = 0;//添加子弹到链表中
protected:
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上	 
	int m_nImgIndex;//图像索引
	int    m_nWait;//发射延时
	int m_V;//速度


};

