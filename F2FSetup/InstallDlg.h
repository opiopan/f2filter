#if !defined(AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// InstallDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CInstallDlg �_�C�A���O

class CInstallDlg : public CDialog
{
public:
	class Controler{
	public:
		CString name;
		CString targetId;
		CString clsId;
	};
	
	Controler m_controler;

protected:
	CArray<Controler, Controler&> m_list;

// �R���X�g���N�V����
public:
	CInstallDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CInstallDlg)
	enum { IDD = IDD_INSTALL };
	CListBox	m_selectedList;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CInstallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CInstallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeJoystick();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
