// F2FSetupDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupDlg �_�C�A���O

class CF2FSetupDlg : public CDialog
{
// �\�z
public:
	CF2FSetupDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CF2FSetupDlg)
	enum { IDD = IDD_F2FSETUP_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CF2FSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CF2FSetupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
