#if !defined(AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_)
#define AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogPage.h : �w�b�_�[ �t�@�C��
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CLogPage �_�C�A���O

class CLogPage : public CDinamicDlgPage
{
// �R���X�g���N�V����
public:
	CLogPage();   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CLogPage)
	enum { IDD = IDD_LOG_PAGE };
	CString	m_LogPath;
	int		m_OpenType;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CLogPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CLogPage)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_)
