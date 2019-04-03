// F4PatchPage.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "F4PatchPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CF4PatchPage プロパティ ページ

IMPLEMENT_DYNCREATE(CF4PatchPage, CDinamicDlgPage)

CF4PatchPage::CF4PatchPage() : CDinamicDlgPage(CF4PatchPage::IDD)
{
	//{{AFX_DATA_INIT(CF4PatchPage)
	m_Gain = 0;
	m_LogPath = _T("");
	m_OpenType = -1;
	m_bLogging = FALSE;
	//}}AFX_DATA_INIT
}

CF4PatchPage::~CF4PatchPage()
{
}

void CF4PatchPage::DoDataExchange(CDataExchange* pDX)
{
	CDinamicDlgPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CF4PatchPage)
	DDX_Slider(pDX, IDC_GAIN, m_Gain);
	DDX_Text(pDX, IDC_LOG_PATH, m_LogPath);
	DDX_Radio(pDX, IDC_APPEND, m_OpenType);
	DDX_Check(pDX, IDC_LOGGING, m_bLogging);
	//}}AFX_DATA_MAP

	CString tmp;
	tmp.Format("%d%%", m_Gain * 100 / FORCE_MAX_GAIN);
	GetDlgItem(IDC_GAIN_DISPLAY)->SetWindowText(tmp);
	
	this->GetDlgItem(IDC_LOG_PATH)->EnableWindow(m_bLogging);
	this->GetDlgItem(IDC_APPEND)->EnableWindow(m_bLogging);
	this->GetDlgItem(IDC_NEW)->EnableWindow(m_bLogging);
}


BEGIN_MESSAGE_MAP(CF4PatchPage, CDinamicDlgPage)
	//{{AFX_MSG_MAP(CF4PatchPage)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_DEFAULT_GAIN, OnDefaultGain)
	ON_BN_CLICKED(IDC_LOGGING, OnLogging)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CF4PatchPage メッセージ ハンドラ

BOOL CF4PatchPage::OnInitDialog() 
{
	CDinamicDlgPage::OnInitDialog();

	HWND hCtl;
	this->GetDlgItem(IDC_GAIN, &hCtl);
	CSliderCtrl ctl;
	ctl.Attach(hCtl);
	ctl.SetRange(0, FORCE_MAX_GAIN);
	ctl.SetPos(m_Gain);
	ctl.Detach();
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
}

void CF4PatchPage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UpdateData();
	
	CDinamicDlgPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CF4PatchPage::OnDefaultGain() 
{
	m_Gain = FORCE_DEFAULT_GAIN;
	UpdateData(FALSE);
	HWND hCtl;
	this->GetDlgItem(IDC_GAIN, &hCtl);
	CSliderCtrl ctl;
	ctl.Attach(hCtl);
	ctl.SetPos(m_Gain);
	ctl.Detach();
}

void CF4PatchPage::OnLogging() 
{
	UpdateData();
}
