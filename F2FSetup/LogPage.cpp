// LogPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "LogPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogPage �_�C�A���O


CLogPage::CLogPage()
	: CDinamicDlgPage(CLogPage::IDD)
{
	//{{AFX_DATA_INIT(CLogPage)
	m_LogPath = _T("");
	m_OpenType = -1;
	//}}AFX_DATA_INIT
}


void CLogPage::DoDataExchange(CDataExchange* pDX)
{
	CDinamicDlgPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogPage)
	DDX_Text(pDX, IDC_LOG_PATH, m_LogPath);
	DDX_Radio(pDX, IDC_APPEND, m_OpenType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogPage, CDinamicDlgPage)
	//{{AFX_MSG_MAP(CLogPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogPage ���b�Z�[�W �n���h��
