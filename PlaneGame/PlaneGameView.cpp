
// PlaneGameView.cpp: CPlaneGameView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneGame.h"
#endif

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"
#include "Bomb.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView()
{
	// TODO: 在此处添加构造代码

}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView 绘图

void CPlaneGameView::OnDraw(CDC* pDC)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

}


// CPlaneGameView 打印

BOOL CPlaneGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPlaneGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPlaneGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序


void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	short key = GetKeyState(VK_LEFT);
	if ((key & 0x8000) != 0)
	{
		me.SetHorMotion(-1);
	}
	key = GetKeyState(VK_RIGHT);
	if ((key & 0x8000) != 0)
	{
		me.SetHorMotion(1);
	}
	key = GetKeyState(VK_UP);
	if ((key & 0x8000) != 0)
	{
		me.SetVerMotion(-1);
	}
	key = GetKeyState(VK_DOWN);
	if ((key & 0x8000) != 0)
	{
		me.SetVerMotion(1);
	}

	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(RGB(146, 146, 146));
	pDC->SelectObject(&brush);
	pDC->Rectangle(&rect);

	me.Draw(pDC, false);
	POSITION pos1, pos2;
	for (pos1 = listBomb.GetHeadPosition(); (pos2 = pos1) != NULL;)
	{
		CBomb *pbomb = (CBomb*)listBomb.GetNext(pos1);
		if (pbomb->GetRect().top < 0)
		{
			CObject *pa = listBomb.GetAt(pos2);
			listBomb.RemoveAt(pos2);
			delete pa;
		}
		else
		{
			pbomb->Draw(pDC, true);
		}
	}


	CString s;
	s.Format(_T("(%d,%d)"), me.GetRect().left, me.GetRect().top);
	pDC->TextOutW(10, 10, s, s.GetLength());


	CView::OnTimer(nIDEvent);
}


int CPlaneGameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 50, 0);
	CMe::LoadImage();
	CBomb::LoadImageW();
	return 0;
}


void CPlaneGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_SPACE)
	{
		listBomb.AddTail(new CBomb(me.GetRect().left + 5, me.GetRect().top));
		listBomb.AddTail(new CBomb(me.GetRect().left + 25, me.GetRect().top));
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
