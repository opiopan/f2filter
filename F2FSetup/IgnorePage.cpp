// IgnorePage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "IgnorePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage �_�C�A���O


CIgnorePage::CIgnorePage()
	: CDinamicDlgPage(CIgnorePage::IDD)
{
	//{{AFX_DATA_INIT(CIgnorePage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CIgnorePage::DoDataExchange(CDataExchange* pDX)
{
	CDinamicDlgPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIgnorePage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIgnorePage, CDinamicDlgPage)
	//{{AFX_MSG_MAP(CIgnorePage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage ���b�Z�[�W �n���h��

BOOL CIgnorePage::OnInitDialog() 
{
	CDinamicDlgPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
