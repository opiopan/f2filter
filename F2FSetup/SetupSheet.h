#if !defined(AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_)
#define AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetupSheet.h : �w�b�_�[ �t�@�C��
//

#include "TargetPage.h"
#include "GlobalPage.h"
#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CSetupSheet

class CSetupSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetupSheet)

// �R���X�g���N�V����
public:
	CSetupSheet(CGlobalConfig& gconf, CUserConfig& uconf);

// �A�g���r���[�g
public:

protected:
	HICON m_hIcon;

	CGlobalConfig& m_GConf;
	CUserConfig& m_UConf;

	CTargetPage m_TargetPage;
	CGlobalPage m_GlobalPage;

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupSheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CSetupSheet();


protected:
	void AddPages();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CSetupSheet)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_)
