// DinamicDlgSheet.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "DinamicDlgSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDinamicDlgPage
IMPLEMENT_DYNCREATE(CDinamicDlgPage, CDialog)

CDinamicDlgPage::CDinamicDlgPage(DWORD id) : m_DlgId(id){
}

CDinamicDlgPage::~CDinamicDlgPage(){
}

BOOL CDinamicDlgPage::Create(CWnd* pParentWnd, DWORD dwStyle, DWORD dwExStyle){
	BOOL rc = CDialog::Create(m_DlgId, pParentWnd);

	if (rc){
		this->ModifyStyle(0, dwStyle, 0);
		this->ModifyStyleEx(0, dwExStyle, 0);
	}

	return rc;
}

BOOL CDinamicDlgPage::OnInitDialog(){
	return CDialog::OnInitDialog();
}

BEGIN_MESSAGE_MAP(CDinamicDlgPage, CDialog)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDinamicDlgSheet

CDinamicDlgSheet::CDinamicDlgSheet():m_nActive(0){
}


CDinamicDlgSheet::~CDinamicDlgSheet(){
}

void CDinamicDlgSheet::AddPage(CDinamicDlgPage* pDlg){
	m_PageList.Add(pDlg);
}

void CDinamicDlgSheet::SetActivePage(UINT id){
	if (id != m_nActive){
		m_PageList[id]->ShowWindow(SW_SHOW);
		m_PageList[m_nActive]->ShowWindow(SW_HIDE);
		m_nActive = id;
	}
};

CDinamicDlgPage* CDinamicDlgSheet::GetActivePage() const{
	return m_PageList[m_nActive];
};

void CDinamicDlgSheet::AttachControl(CDialog* wnd, DWORD id, SheetType type){
		CWnd* pWnd = wnd->GetDlgItem(id);
		CRect rcPage;
		pWnd->GetWindowRect(rcPage);
		wnd->ScreenToClient(&rcPage);

		// Create Childs
		for (int i = 0; i < m_PageList.GetSize(); i++){
			CDinamicDlgPage* pPage = m_PageList[i];

			pPage->Create(wnd, WS_CHILD | WS_VISIBLE | WS_TABSTOP, 0);
			//pPage->ModifyStyleEx(0, WS_EX_CONTROLPARENT);
			pPage->ShowWindow(SW_HIDE);

			pPage->MoveWindow(&rcPage);
			pPage->SetWindowPos(pWnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		m_PageList[m_nActive]->ShowWindow(SW_SHOW);
}
