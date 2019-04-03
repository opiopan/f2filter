// TargetPage.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "TargetPage.h"
#include "TargetPropertyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define NAME_COLUMN_SIZE  100
#define MODULE_ITEM_NUM		1


/////////////////////////////////////////////////////////////////////////////
// CTargetPage プロパティ ページ

IMPLEMENT_DYNCREATE(CTargetPage, CPropertyPage)

CTargetPage::CTargetPage() : 
	CPropertyPage(CTargetPage::IDD), m_GConf(NULL), m_UConf(NULL)
{
	//{{AFX_DATA_INIT(CTargetPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

CTargetPage::~CTargetPage()
{
}

void CTargetPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTargetPage)
	DDX_Control(pDX, IDC_TARGET_LIST, m_TargetList);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate){
	}else{
	}

	bool flag = (m_TargetList.GetSelectedCount() != 0);
	GetDlgItem(IDC_DROP_TARGET)->EnableWindow(flag);
	GetDlgItem(IDC_TARGET_PROPERTY)->EnableWindow(flag);
}


BEGIN_MESSAGE_MAP(CTargetPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTargetPage)
	ON_BN_CLICKED(IDC_ADD_TARGET, OnAddTarget)
	ON_NOTIFY(LVN_ODSTATECHANGED, IDC_TARGET_LIST, OnOdstatechangedTargetList)
	ON_NOTIFY(NM_CLICK, IDC_TARGET_LIST, OnClickTargetList)
	ON_BN_CLICKED(IDC_DROP_TARGET, OnDropTarget)
	ON_BN_CLICKED(IDC_TARGET_PROPERTY, OnTargetProperty)
	ON_NOTIFY(NM_DBLCLK, IDC_TARGET_LIST, OnDblclkTargetList)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_TARGET_LIST, OnClickTargetList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTargetPage メッセージ ハンドラ


BOOL CTargetPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();

	// リストビューコントロールのカラム設定
	CRect rect;
	m_TargetList.GetClientRect(&rect);
	CString name;
	name.LoadString(IDS_TL_NAME);
	m_TargetList.InsertColumn(0, name, LVCFMT_LEFT, NAME_COLUMN_SIZE);
	name.LoadString(IDS_TL_PATH);
	m_TargetList.InsertColumn(1, name, LVCFMT_LEFT, 
        rect.right - NAME_COLUMN_SIZE - ::GetSystemMetrics(SM_CXVSCROLL),
		MODULE_ITEM_NUM);

	m_TargetList.DeleteAllItems();
	m_UConf->ResetEnumlate();
	CTargetProgram* tp;
	while (tp = m_UConf->EnumTargetProgram()){
		int index = m_TargetList.InsertItem(0, tp->GetName());
		m_TargetList.SetItemText(index, MODULE_ITEM_NUM, tp->GetTargetPath());
		m_TargetList.SetItemData(index, (DWORD)tp);
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CTargetPage::OnAddTarget(){
	// ターゲットファイル選択
	CString title;
	CString filter;
	title.LoadString(IDS_OT_TITLE);
	filter.LoadString(IDS_OT_FILTER);
	CFileDialog fdlg(TRUE, "exe", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
	                 filter, this);
	fdlg.m_ofn.lpstrTitle = title;
	if (fdlg.DoModal() != IDOK)
		return;

	// 重複チェック
	m_UConf->ResetEnumlate();
	while (CTargetProgram* ptp = m_UConf->EnumTargetProgram()){
		if (CompareString(
				LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
				ptp->GetTargetPath(), -1, fdlg.GetPathName(), -1) == CSTR_EQUAL){
			// エラー
			CString tmp;
			tmp.LoadString(IDS_MSG_EXIT_TARGET);
			MessageBox(tmp, caption, MB_OK | MB_ICONWARNING);
			return;
		}
	}

	//　新規ターゲット作成
	CTargetProgram tp(m_UConf->GetTargetId());
	tp.SetName(fdlg.GetFileTitle());
	tp.SetTargetPath(fdlg.GetPathName());
	tp.SetGain(FORCE_DEFAULT_GAIN);
	tp.SetLogFile(fdlg.GetPathName() + ".log");
	tp.SetLogAppend(true);
	if (CompareString(
			LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
			fdlg.GetFileTitle(), -1, "eFalcon", -1) == CSTR_EQUAL ||
		CompareString(
			LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
			fdlg.GetFileTitle(), -1, "FalconSP", -1) == CSTR_EQUAL ||
		CompareString(
			LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
			fdlg.GetFileTitle(), -1, "F4-BMS", -1) == CSTR_EQUAL){
		tp.SetF4Patch(true);
		tp.SetIgnoreForce(false);
		tp.SetLogging(false);
	}else{
		tp.SetF4Patch(false);
		tp.SetIgnoreForce(true);
		tp.SetLogging(false);
	}

	CTargetPropertyDlg dlg;
	if (dlg.ModifyTargetInfo(&tp)){
		// 追加
		CTargetProgram* ptp = m_UConf->AddTargetProgram(tp);
		int index = m_TargetList.InsertItem(0, ptp->GetName());
		m_TargetList.SetItemText(index, MODULE_ITEM_NUM, ptp->GetTargetPath());
		m_TargetList.SetItemData(index, (DWORD)ptp);
		this->SetModified(TRUE);
	}
}

void CTargetPage::OnDropTarget(){
	POSITION p;
	p = m_TargetList.GetFirstSelectedItemPosition();
	int index = m_TargetList.GetNextSelectedItem(p);
	CTargetProgram* tp = (CTargetProgram*)m_TargetList.GetItemData(index);

	m_TargetList.DeleteItem(index);
	m_UConf->DropTargetProgram(tp->GetTargetPath());
	this->SetModified(TRUE);
}

void CTargetPage::OnTargetProperty(){
	POSITION p;
	p = m_TargetList.GetFirstSelectedItemPosition();
	int index = m_TargetList.GetNextSelectedItem(p);
	if (index >= 0){
		CTargetProgram* tp = (CTargetProgram*)m_TargetList.GetItemData(index);
		CTargetPropertyDlg dlg;
		if (dlg.ModifyTargetInfo(tp)){
			m_TargetList.SetItemText(index, 0, tp->GetName());
			this->SetModified(TRUE);
		}
	}
}


void CTargetPage::OnOdstatechangedTargetList(NMHDR* pNMHDR, LRESULT* pResult){
	NMLVODSTATECHANGE* pStateChanged = (NMLVODSTATECHANGE*)pNMHDR;
	this->UpdateData();

	*pResult = 0;
}

void CTargetPage::OnClickTargetList(NMHDR* pNMHDR, LRESULT* pResult){
	this->UpdateData();
		
	*pResult = 0;
}


void CTargetPage::OnDblclkTargetList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	this->OnTargetProperty();
	
	*pResult = 0;
}

BOOL CTargetPage::OnApply() 
{
	m_UConf->Save();
	
	return CPropertyPage::OnApply();
}
