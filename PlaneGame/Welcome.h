#pragma once
#include "GameObject.h"
#include "Me.h"
class CWelcome :
	public CGameObject
{
public:
	CWelcome();
	~CWelcome();
	void SelectMode(int);	//0ио 1об
	void OK();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 600, m_ptPos.y + 1000));
	}
	
private:
	static CImageList m_Images;
	int Mode;
	BOOL Selected;
	CMe* me;
};

