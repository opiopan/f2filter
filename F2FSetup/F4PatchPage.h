#if !defined(AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_)
#define AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// F4PatchPage.h : ヘッダー ファイル
//

#include "DinamicDlgSheet.h"

/////////////////////////////////////////////////////////////////////////////
// CF4PatchPage ダイアログ

class CF4PatchPage : public CDinamicDlgPage
{
	DECLARE_DYNCREATE(CF4PatchPage)

// コンストラクション
public:
	CF4PatchPage();
	~CF4PatchPage();

// ダイアログ データ
	//{{AFX_DATA(CF4PatchPage)
	enum { IDD = IDD_F4PATCH_PAGE };
	int		m_Gain;
	CString	m_LogPath;
	int		m_OpenType;
	BOOL	m_bLogging;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CF4PatchPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CF4PatchPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDefaultGain();
	afx_msg void OnLogging();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_F4PATCHPAGE_H__D0F22C06_9734_417E_ACA8_B29E253DC4AD__INCLUDED_)
