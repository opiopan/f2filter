// GlobalPage.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "F2FSetup.h"
#include "GlobalPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage プロパティ ページ

IMPLEMENT_DYNCREATE(CGlobalPage, CPropertyPage)

CGlobalPage::CGlobalPage() : CPropertyPage(CGlobalPage::IDD)
{
	//{{AFX_DATA_INIT(CGlobalPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

CGlobalPage::~CGlobalPage()
{
}

void CGlobalPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGlobalPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGlobalPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGlobalPage)
		// メモ: ClassWizard はこの位置に DDX および DDV の呼び出しコードを追加します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage メッセージ ハンドラ
