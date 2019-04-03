// InstallDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "F2FSetup.h"
#include "InstallDlg.h"
#include "f2freg.h"
#pragma warning(disable : 4786)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CInstallDlg ダイアログ


CInstallDlg::CInstallDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInstallDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInstallDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT


}


void CInstallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInstallDlg)
	DDX_Control(pDX, IDC_JOYSTICK, m_selectedList);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate){
		m_controler = m_list[m_selectedList.GetCurSel()];
	}else{
	}
}


BEGIN_MESSAGE_MAP(CInstallDlg, CDialog)
	//{{AFX_MSG_MAP(CInstallDlg)
	ON_LBN_SELCHANGE(IDC_JOYSTICK, OnSelchangeJoystick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInstallDlg メッセージ ハンドラ

BOOL CInstallDlg::OnInitDialog() {
	CDialog::OnInitDialog();
	
	// コントローラ一覧作成
	CRegistory rBase(HKEY_LOCAL_MACHINE,
	                 "SYSTEM\\CurrentControlSet\\Control"
					 "\\MediaProperties\\PrivateProperties\\Joystick\\OEM",
	                 CRegistory::READ);
	const char* target;
	for (DWORD i = 0; target = rBase.EnumKey(i); i++){
		try{
			CRegistory rTarget(rBase, target, CRegistory::READ);
			
			Controler cnt;
			cnt.targetId = target;
			cnt.name = rTarget.GetValue("OEMName");
			
			CRegistory rFF(rTarget, "OEMForceFeedback", CRegistory::READ);
			cnt.clsId = rFF.GetValue("CLSID");

			m_list.Add(cnt);
		}catch (HSSException&){
			continue;
		}
	}

	// リストボックスにコントローラ名を挿入
	for (i = 0; i < m_list.GetSize(); i++){
		m_selectedList.InsertString(-1, m_list[i].name);
	}
	
	(this->GetDlgItem(IDOK))->EnableWindow(FALSE);

	return TRUE;
}

void CInstallDlg::OnSelchangeJoystick() 
{
	(this->GetDlgItem(IDOK))->EnableWindow(TRUE);
}

void CInstallDlg::OnOK() {
	this->UpdateData();

	this->EnableWindow(FALSE);

	CString caption;
	caption.LoadString(IDS_INSTALL_TITLE);
	CGlobalConfig gconf;

	try{

		// スプリング動作のEffectIDを決定する
		CString kname = "SYSTEM\\CurrentControlSet\\Control"
						"\\MediaProperties\\PrivateProperties\\Joystick\\OEM\\";
		kname += m_controler.targetId;
		kname += "\\OEMForceFeedback\\Effects\\{13541C27-8E33-11D0-9AD0-00A0C9A06E35}";
		CRegistory rCntl(HKEY_LOCAL_MACHINE, kname, CRegistory::READ);
		CRegistory::CValue val = rCntl.GetValue("Attributes");
		DIEFFECTATTRIBUTES* attr = (DIEFFECTATTRIBUTES*)val.buf;


		// 権限チェック
		gconf.Save();

		// ドライバコンポーネント登録
		CoInitialize(NULL);
		HMODULE hMod = LoadLibrary(F2FILTER_DRIVER_NAME);
		FARPROC func = GetProcAddress(hMod, "DllRegisterServer");
		HRESULT rc = func();

		// レジストリ登録
		gconf.SetTarget(m_controler.targetId);
		gconf.SetOriginal(m_controler.clsId);
		gconf.SetEffectId(attr->dwEffectId);
		gconf.SetTargetName(m_controler.name);
		gconf.Save();
		CString key = "SYSTEM\\CurrentControlSet\\Control"
				      "\\MediaProperties\\PrivateProperties\\Joystick\\OEM\\";
		key += gconf.GetTarget();
		key += "\\OEMForceFeedback";
		CRegistory rBase(HKEY_LOCAL_MACHINE, key, CRegistory::WRITE);
		rBase.SetValue("CLSID", "{2DB4C62E-11D0-11D6-B76B-0000E8D4B3D9}");

		//　完了
		CString m;
		m.LoadString(IDS_MSG_INSTALL_FINISH);
		::MessageBox(NULL, m, caption, MB_OK | MB_ICONINFORMATION);
	}catch(CRegistory::AccessDeniedException&){
		CString m;
		m.LoadString(IDS_MSG_ACCESS_DENIED);
		::MessageBox(NULL, m, caption, MB_OK | MB_ICONWARNING);
	}

	CDialog::OnOK();
}
