// GlobalPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "GlobalPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(CGlobalPage, CPropertyPage)

CGlobalPage::CGlobalPage() : CPropertyPage(CGlobalPage::IDD)
{
	//{{AFX_DATA_INIT(CGlobalPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

CGlobalPage::~CGlobalPage()
{
}

void CGlobalPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGlobalPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGlobalPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGlobalPage)
		// ����: ClassWizard �͂��̈ʒu�� DDX ����� DDV �̌Ăяo���R�[�h��ǉ����܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage ���b�Z�[�W �n���h��
