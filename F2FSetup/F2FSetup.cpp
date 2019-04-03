// F2FSetup.cpp : アプリケーション用クラスの定義を行います。
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
// F2FSetup用コマンドラインパーサ
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp クラスの構築

CF2FSetupApp::CF2FSetupApp()
{
	// TODO: この位置に構築用のコードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}



/////////////////////////////////////////////////////////////////////////////
// 唯一の CF2FSetupApp オブジェクト

CF2FSetupApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp クラスの初期化

CString caption;

BOOL CF2FSetupApp::InitInstance(){
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さくしたけ
	//  れば以下の特定の初期化ルーチンの中から不必要なものを削除して
	//  ください。

#ifdef _AFXDLL
	Enable3dControls();			// 共有 DLL 内で MFC を使う場合はここをコールしてください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクする場合はここをコールしてください。
#endif

	// コマンドライン引数パーズ
	CMyCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (cmdInfo.m_bInstall){
		//-----------------------------------------------
		// インストールモード
		//-----------------------------------------------
		caption.LoadString(IDS_INSTALL_TITLE);
		CGlobalConfig gconf;
		try{
			gconf.Load();
			//　正常にロードしたということは既にインストール済
			CString m;
			m.LoadString(IDS_MSG_ALREADYINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}catch(HSSException&){
		}

		// 権限チェック
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
			// ダイアログプロシージャ内で完了してる。
		}

	}else if (cmdInfo.m_bUninstall){
		//-----------------------------------------------
		// アンインストールモード
		//-----------------------------------------------
		caption.LoadString(IDS_UNINSTALL_TITLE);
		CGlobalConfig gconf;

		// 権限チェック
		try{
			gconf.Save();
		}catch(CRegistory::AccessDeniedException&){
			CString m;
			m.LoadString(IDS_MSG_ACCESS_DENIED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// インストール済かチェック
		try{
			gconf.Load();
		}catch(HSSException&){
			CString m;
			m.LoadString(IDS_MSG_NOTINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// オリジナルドライバに戻す
		CString key = "SYSTEM\\CurrentControlSet\\Control"
				      "\\MediaProperties\\PrivateProperties\\Joystick\\OEM\\";
		key += gconf.GetTarget();
		key += "\\OEMForceFeedback";
		CRegistory rBase(HKEY_LOCAL_MACHINE, key, CRegistory::WRITE);
		rBase.SetValue("CLSID", gconf.GetOriginalString());

		// レジストリ削除
		gconf.Drop();
		
		// ドライバコンポーネント登録解除
		CoInitialize(NULL);
		HMODULE hMod = LoadLibrary(F2FILTER_DRIVER_NAME);
		FARPROC func = GetProcAddress(hMod, "DllUnregisterServer");
		HRESULT rc = func();
		
		// 完了
		CString m;
		m.LoadString(IDS_MSG_UNINSTALL_FINISH);
		::MessageBox(NULL, m, caption, MB_OK | MB_ICONINFORMATION);
	}else{
		//-----------------------------------------------
		//　セットアップモード
		//-----------------------------------------------
		caption.LoadString(IDS_SETUP_TITLE);
		
		// インストール済かチェック
		CGlobalConfig gconf;
		try{
			gconf.Load();
		}catch(HSSException&){
			CString m;
			m.LoadString(IDS_MSG_NOTINSTALLED);
			MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
			return FALSE;
		}

		// ユーザ毎のコンフィギュレーションロード
		CUserConfig uconf; 
		try{
			uconf.Load();
		}catch(HSSException&){
			// 初回の実行時には無くてもよい
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
