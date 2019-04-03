// TargetPropertyDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "TargetPropertyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTargetPropertyDlg ダイアログ


CTargetPropertyDlg::CTargetPropertyDlg(CWnd* pParent)
	: CDialog(CTargetPropertyDlg::IDD, pParent){
	//{{AFX_DATA_INIT(CTargetPropertyDlg)
	m_TargetName = _T("");
	m_TargetPath = _T("");
	//}}AFX_DATA_INIT
}


bool CTargetPropertyDlg::ModifyTargetInfo(CTargetProgram* tp){
	m_pTarget = tp;

	// 初期値設定
	m_TargetName = tp->GetName();
	m_TargetPath = tp->GetTargetPath();
	m_F4PatchPage.m_Gain = tp->GetGain();
	m_F4PatchPage.m_LogPath = tp->GetLogFile();
	m_F4PatchPage.m_OpenType = tp->GetLogAppend() ? 0 : 1;
	m_LogPage.m_LogPath = tp->GetLogFile();
	m_LogPage.m_OpenType = tp->GetLogAppend() ? 0 : 1;

	if (m_pTarget->GetF4Patch()){
		m_F4PatchPage.m_bLogging = m_pTarget->GetLogging();
	}

	if (DoModal() == IDOK){
		tp->SetName(m_TargetName);
		tp->SetTargetPath(m_TargetPath);

		switch (m_DlgSheet.GetActivePageNum()){
		case 0:
			tp->SetIgnoreForce(true);
			tp->SetF4Patch(false);
			tp->SetLogging(false);
			break;
		case 1:
			tp->SetIgnoreForce(false);
			tp->SetF4Patch(true);
			tp->SetLogging(false);
			tp->SetGain(m_F4PatchPage.m_Gain);
			if (m_F4PatchPage.m_bLogging){
				tp->SetLogging(true);
				tp->SetLogFile(m_F4PatchPage.m_LogPath);
				tp->SetLogAppend(m_F4PatchPage.m_OpenType == 0);
			}
			break;
		default:
			tp->SetIgnoreForce(false);
			tp->SetF4Patch(false);
			tp->SetLogging(true);
			tp->SetLogFile(m_LogPage.m_LogPath);
			tp->SetLogAppend(m_LogPage.m_OpenType == 0);
			break;
		}
		

		return true;
	}else{
		return false;
	}
}


void CTargetPropertyDlg::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTargetPropertyDlg)
	DDX_Control(pDX, IDC_MODE, m_Mode);
	DDX_Text(pDX, IDC_TARGET_NAME, m_TargetName);
	DDX_Text(pDX, IDC_TARGET_PATH, m_TargetPath);
	//}}AFX_DATA_MAP
}


void CTargetPropertyDlg::SetActivePage(){
	m_DlgSheet.SetActivePage(m_Mode.GetCurSel());	
	CString str;
	str.LoadString(m_Mode.GetItemData(m_Mode.GetCurSel()));
	(this->GetDlgItem(IDC_MODE_DESC))->SetWindowText(str);
}


BEGIN_MESSAGE_MAP(CTargetPropertyDlg, CDialog)
	//{{AFX_MSG_MAP(CTargetPropertyDlg)
	ON_CBN_SELCHANGE(IDC_MODE, OnSelchangeMode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTargetPropertyDlg メッセージ ハンドラ

BOOL CTargetPropertyDlg::OnInitDialog() {
	CDialog::OnInitDialog();
	
	m_DlgSheet.AddPage(&m_IgnorePage);
	m_DlgSheet.AddPage(&m_F4PatchPage);
	m_DlgSheet.AddPage(&m_LogPage);
	m_DlgSheet.AttachControl(this, IDC_PAGE);

	CString str;
	str.LoadString(IDS_TP_PAGE_IGNORE);
	m_Mode.InsertString(0, str);
	m_Mode.SetItemData(0, IDS_TP_DESC_IGNORE);
	str.LoadString(IDS_TP_PAGE_F4Patch);
	m_Mode.InsertString(1, str);
	m_Mode.SetItemData(1, IDS_TP_DESC_F4Patch);
	str.LoadString(IDS_TP_PAGE_LOG);
	m_Mode.InsertString(2, str);
	m_Mode.SetItemData(2, IDS_TP_DESC_LOG);

	if (m_pTarget->GetF4Patch()){
		m_Mode.SetCurSel(1);
	}else if (m_pTarget->GetIgnoreForce()){
		m_Mode.SetCurSel(0);
	}else{
		m_Mode.SetCurSel(2);
	}

	SetActivePage();

	//str.LoadString(m_Mode.GetItemData(m_Mode.GetCurSel()));
	//(this->GetDlgItem(IDC_MODE_DESC))->SetWindowText(str);
	
	return TRUE; 
}

void CTargetPropertyDlg::OnSelchangeMode() {
	this->UpdateData(FALSE);
	SetActivePage();
}

void CTargetPropertyDlg::OnOK() 
{
	m_DlgSheet.GetActivePage()->UpdateData();
	CDialog::OnOK();
}
