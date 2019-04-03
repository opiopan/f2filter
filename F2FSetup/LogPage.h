#if !defined(AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_)
#define AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogPage.h : ヘッダー ファイル
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CLogPage ダイアログ

class CLogPage : public CDinamicDlgPage
{
// コンストラクション
public:
	CLogPage();   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CLogPage)
	enum { IDD = IDD_LOG_PAGE };
	CString	m_LogPath;
	int		m_OpenType;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CLogPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CLogPage)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_LOGPAGE_H__C6EA28D6_AB8A_457E_8CA8_1DEDF69CDA77__INCLUDED_)
