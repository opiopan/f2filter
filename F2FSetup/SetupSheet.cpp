// SetupSheet.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "SetupSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupSheet

IMPLEMENT_DYNAMIC(CSetupSheet, CPropertySheet)

CSetupSheet::CSetupSheet(CGlobalConfig& gconf, CUserConfig& uconf)
	:CPropertySheet(IDS_SETUP_TITLE, NULL, 1),
	 m_GConf(gconf), m_UConf(uconf),
	 m_TargetPage(){

	// �e��ݒ�
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_psh.dwFlags |= PSP_USEHICON;
	m_psh.hIcon = m_hIcon;
	m_psh.dwFlags &= ~PSH_HASHELP;  // �w���v �{�^�����Ȃ���

	// �v���p�e�B�y�[�W�ǉ�
	AddPage(&m_GlobalPage);
	m_TargetPage.m_GConf = &m_GConf;
	m_TargetPage.m_UConf = &m_UConf;
	AddPage(&m_TargetPage);
}

CSetupSheet::~CSetupSheet(){
}

void CSetupSheet::AddPages(){
}



BEGIN_MESSAGE_MAP(CSetupSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSetupSheet)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupSheet ���b�Z�[�W �n���h��

BOOL CSetupSheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	CWnd* help = GetDlgItem(IDHELP);
	if (help){
		CWnd* cur = GetDlgItem(IDOK);
		CWnd* next;
		for (int i = 0; i < 3; i++){
			next = cur->GetNextWindow();
			RECT r;
			next->GetWindowRect(&r);
			ScreenToClient(&r);
			cur->MoveWindow(&r);
			cur = next;
		}

		help->MoveWindow(0, 0, 0, 0);
		help->ShowWindow(SW_HIDE);
	}

	return bResult;
}
