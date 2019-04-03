#if !defined(AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_)
#define AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TargetPage.h : �w�b�_�[ �t�@�C��
//

#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CTargetPage �_�C�A���O

class CTargetPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTargetPage)

public:
	CGlobalConfig* m_GConf;
	CUserConfig* m_UConf;

protected:

		
// �R���X�g���N�V����
public:
	CTargetPage();
	~CTargetPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTargetPage)
	enum { IDD = IDD_TARGET_PAGE };
	CListCtrl	m_TargetList;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CTargetPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTargetPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddTarget();
	afx_msg void OnOdstatechangedTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDropTarget();
	afx_msg void OnTargetProperty();
	afx_msg void OnDblclkTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_)
