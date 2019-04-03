#if !defined(AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_)
#define AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IgnorePage.h : ヘッダー ファイル
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CIgnorePage ダイアログ

class CIgnorePage : public CDinamicDlgPage
{
// コンストラクション
public:
	CIgnorePage();   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CIgnorePage)
	enum { IDD = IDD_IGNORE_PAGE };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CIgnorePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CIgnorePage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_IGNOREPAGE_H__F0AA5C42_21B3_4918_A052_74F5BD85120A__INCLUDED_)
