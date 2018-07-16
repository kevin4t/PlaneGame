#include "stdafx.h"
#include "Welcome.h"
#include "resource.h"
#include "Me.h"
CWelcome::CWelcome()
{
	me = new CMe();
	Mode = 0;
	Selected = FALSE;
}


CWelcome::~CWelcome()
{
}

void CWelcome::SelectMode(int down)
{
	if (down && Mode <= 1)
	{
		Mode++;
	}
	else if(!down && Mode >= 1)
	{
		Mode--;
	}
}

void CWelcome::OK()
{
	Selected = TRUE;
}
void CWelcome::No()
{
	Selected = FALSE;
}

int CWelcome::Draw(CDC* pDC, BOOL bPause)
{

	if (Mode == 0)
	{
		me->SetPoint(150, 370);
	}
	else if (Mode == 1)
	{
		me->SetPoint(150, 550);
	}
	else
	{
		me->SetPoint(150, 730);
	}
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	me->Draw(pDC,FALSE);
	if(Selected) return (Mode + 1);
	return FALSE;
}

BOOL CWelcome::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_WELCOME, RGB(0, 0, 0), 650, 1000, 1);
}

CImageList CWelcome::m_Images;