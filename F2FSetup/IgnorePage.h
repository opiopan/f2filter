#if !defined(AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_)
#define AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IgnorePage.h : �w�b�_�[ �t�@�C��
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage �_�C�A���O

class CIgnorePage : public CDinamicDlgPage
{
// �R���X�g���N�V����
public:
	CIgnorePage();   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CIgnorePage)
	enum { IDD = IDD_IGNORE_PAGE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CIgnorePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CIgnorePage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_)
