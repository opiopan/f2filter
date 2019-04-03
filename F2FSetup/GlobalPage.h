#if !defined(AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_)
#define AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GlobalPage.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CGlobalPage ダイアログ

class CGlobalPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGlobalPage)

// コンストラクション
public:
	CGlobalPage();
	~CGlobalPage();

// ダイアログ データ
	//{{AFX_DATA(CGlobalPage)
	enum { IDD = IDD_GLOBAL_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CGlobalPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CGlobalPage)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_GLOBALPAGE_H__55D15041_152A_43F1_BDD6_5FAA0657BF8A__INCLUDED_)
