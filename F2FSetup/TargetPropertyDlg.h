#if !defined(AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_)
#define AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TargetPropertyDlg.h : �w�b�_�[ �t�@�C��
//

#include "DinamicDlgSheet.h"
#include "F4PatchPage.h"
#include "IgnorePage.h"
#include "LogPage.h"
#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CTargetPropertyDlg �_�C�A���O

class CTargetPropertyDlg : public CDialog
{
protected:
	CTargetProgram* m_pTarget;

	CDinamicDlgSheet m_DlgSheet;
	CF4PatchPage m_F4PatchPage;
	CIgnorePage m_IgnorePage;
	CLogPage m_LogPage;

// �R���X�g���N�V����
public:
	CTargetPropertyDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	bool ModifyTargetInfo(CTargetProgram* tp);

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTargetPropertyDlg)
	enum { IDD = IDD_TARGET_PROPERTY };
	CComboBox	m_Mode;
	CString	m_TargetName;
	CString	m_TargetPath;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CTargetPropertyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	void SetActivePage();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTargetPropertyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMode();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_)
