#if !defined(AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_)
#define AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// F4PatchPage.h : �w�b�_�[ �t�@�C��
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CF4PatchPage �_�C�A���O

class CF4PatchPage : public CDinamicDlgPage
{
	DECLARE_DYNCREATE(CF4PatchPage)

// �R���X�g���N�V����
public:
	CF4PatchPage();
	~CF4PatchPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CF4PatchPage)
	enum { IDD = IDD_F4PATCH_PAGE };
	int		m_Gain;
	CString	m_LogPath;
	int		m_OpenType;
	BOOL	m_bLogging;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CF4PatchPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CF4PatchPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDefaultGain();
	afx_msg void OnLogging();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_)
