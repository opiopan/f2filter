// F2FSetup.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "F2FSetupDlg.h"
#include "InstallDlg.h"
#include "f2freg.h"
#include "SetupSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// F2FSetup�p�R�}���h���C���p�[�T
class CMyCommandLineInfo : public CCommandLineInfo
{
public:
	bool m_bInstall;
	bool m_bUninstall;

public:
	CMyCommandLineInfo();
	~CMyCommandLineInfo();
	virtual void ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast);
};

CMyCommandLineInfo::CMyCommandLineInfo() : m_bInstall(false), m_bUninstall(false){
}

CMyCommandLineInfo::~CMyCommandLineInfo(){
}

void CMyCommandLineInfo::ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast){
	if (bFlag){
		if (CompareString(
				LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
				lpszParam, -1, "INSTALL", -1) == CSTR_EQUAL){
			m_bInstall = true;
		}else if (CompareString(
				LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
				lpszParam, -1, "UNINSTALL", -1) == CSTR_EQUAL){
			m_bUninstall = true;
		}else{
			CCommandLineInfo::ParseParam(lpszParam, bFlag, bLast);
		}
	}else{
		CCommandLineInfo::ParseParam(lpszParam, bFlag, bLast);
	}
}


/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp

BEGIN_MESSAGE_MAP(CF2FSetupApp, CWinApp)
	//{{AFX_MSG_MAP(CF2FSetupApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp �N���X�̍\�z

CF2FSetupApp::CF2FSetupApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}



/////////////////////////////////////////////////////////////////////////////
// �B��� CF2FSetupApp �I�u�W�F�N�g

CF2FSetupApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp �N���X�̏�����

CString caption;

BOOL CF2FSetupApp::InitInstance(){
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������������
	//  ��Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ��̂��폜����
	//  ���������B

#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ�͂������R�[�����Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ�͂������R�[�����Ă��������B
#endif

	// �R�}���h���C�������p�[�Y
	CMyCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (cmdInfo.m_bInstall){
		//-----------------------------------------------
		// �C���X�g�[�����[�h
		//-----------------------------------------------
		caption.LoadString(IDS_INSTALL_TITLE);
		CGlobalConfig gconf;
		try{
			gconf.Load();
			//�@����Ƀ��[�h�����Ƃ������Ƃ͊��ɃC���X�g�[����
			CString m;
			m.LoadString(IDS_MSG_ALREADYINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}catch(HSSException&){
		}

		// �����`�F�b�N
		try{
			gconf.Save();
		}catch(CRegistory::AccessDeniedException&){
			CString m;
			m.LoadString(IDS_MSG_ACCESS_DENIED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		CInstallDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();

		if (nResponse == IDOK){
			// �_�C�A���O�v���V�[�W�����Ŋ������Ă�B
		}

	}else if (cmdInfo.m_bUninstall){
		//-----------------------------------------------
		// �A���C���X�g�[�����[�h
		//-----------------------------------------------
		caption.LoadString(IDS_UNINSTALL_TITLE);
		CGlobalConfig gconf;

		// �����`�F�b�N
		try{
			gconf.Save();
		}catch(CRegistory::AccessDeniedException&){
			CString m;
			m.LoadString(IDS_MSG_ACCESS_DENIED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// �C���X�g�[���ς��`�F�b�N
		try{
			gconf.Load();
		}catch(HSSException&){
			CString m;
			m.LoadString(IDS_MSG_NOTINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// �I���W�i���h���C�o�ɖ߂�
		CString key = "SYSTEM\\CurrentControlSet\\Control"
				      "\\MediaProperties\\PrivateProperties\\Joystick\\OEM\\";
		key += gconf.GetTarget();
		key += "\\OEMForceFeedback";
		CRegistory rBase(HKEY_LOCAL_MACHINE, key, CRegistory::WRITE);
		rBase.SetValue("CLSID", gconf.GetOriginalString());

		// ���W�X�g���폜
		gconf.Drop();
		
		// �h���C�o�R���|�[�l���g�o�^����
		CoInitialize(NULL);
		HMODULE hMod = LoadLibrary(F2FILTER_DRIVER_NAME);
		FARPROC func = GetProcAddress(hMod, "DllUnregisterServer");
		HRESULT rc = func();
		
		// ����
		CString m;
		m.LoadString(IDS_MSG_UNINSTALL_FINISH);
		::MessageBox(NULL, m, caption, MB_OK | MB_ICONINFORMATION);
	}else{
		//-----------------------------------------------
		//�@�Z�b�g�A�b�v���[�h
		//-----------------------------------------------
		caption.LoadString(IDS_SETUP_TITLE);
		
		// �C���X�g�[���ς��`�F�b�N
		CGlobalConfig gconf;
		try{
			gconf.Load();
		}catch(HSSException&){
			CString m;
			m.LoadString(IDS_MSG_NOTINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// ���[�U���̃R���t�B�M�����[�V�������[�h
		CUserConfig uconf; 
		try{
			uconf.Load();
		}catch(HSSException&){
			// ����̎��s���ɂ͖����Ă��悢
		}

		CSetupSheet dlg(gconf, uconf);
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK){
			uconf.Save();
		}else if (nResponse == IDCANCEL){
		}
	}

	return FALSE;
}
