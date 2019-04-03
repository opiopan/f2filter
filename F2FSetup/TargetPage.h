#if !defined(AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_)
#define AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TargetPage.h : ヘッダー ファイル
//

#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CTargetPage ダイアログ

class CTargetPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTargetPage)

public:
	CGlobalConfig* m_GConf;
	CUserConfig* m_UConf;

protected:

		
// コンストラクション
public:
	CTargetPage();
	~CTargetPage();

// ダイアログ データ
	//{{AFX_DATA(CTargetPage)
	enum { IDD = IDD_TARGET_PAGE };
	CListCtrl	m_TargetList;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CTargetPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CTargetPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddTarget();
	afx_msg void OnOdstatechangedTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDropTarget();
	afx_msg void OnTargetProperty();
	afx_msg void OnDblclkTargetList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_TARGETPAGE_H__AA1AF125_5BDC_4970_8111_ED06D46DA297__INCLUDED_)
