// F2FSetup.h : F2FSETUP �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��


#define FORCE_DEFAULT_GAIN  8000
#define FORCE_MAX_GAIN      0x7fff


extern CString caption;

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� F2FSetup.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CF2FSetupApp : public CWinApp
{
public:
	CF2FSetupApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CF2FSetupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CF2FSetupApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#define F2FILTER_DRIVER_NAME "F2FILTER.DLL"

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
