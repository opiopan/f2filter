// IgnorePage.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "IgnorePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage ダイアログ


CIgnorePage::CIgnorePage()
	: CDinamicDlgPage(CIgnorePage::IDD)
{
	//{{AFX_DATA_INIT(CIgnorePage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CIgnorePage::DoDataExchange(CDataExchange* pDX)
{
	CDinamicDlgPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIgnorePage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIgnorePage, CDinamicDlgPage)
	//{{AFX_MSG_MAP(CIgnorePage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage メッセージ ハンドラ

BOOL CIgnorePage::OnInitDialog() 
{
	CDinamicDlgPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
