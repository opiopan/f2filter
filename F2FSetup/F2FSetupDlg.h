// F2FSetupDlg.h : ヘッダー ファイル
//

#if !defined(AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupDlg ダイアログ

class CF2FSetupDlg : public CDialog
{
// 構築
public:
	CF2FSetupDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CF2FSetupDlg)
	enum { IDD = IDD_F2FSETUP_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CF2FSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CF2FSetupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_F2FSETUPDLG_H__11DB1D67_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
