#if !defined(AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_)
#define AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GlobalPage.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage �_�C�A���O

class CGlobalPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGlobalPage)

// �R���X�g���N�V����
public:
	CGlobalPage();
	~CGlobalPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CGlobalPage)
	enum { IDD = IDD_GLOBAL_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CGlobalPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CGlobalPage)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_)
