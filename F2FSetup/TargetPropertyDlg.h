#if !defined(AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_)
#define AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TargetPropertyDlg.h : ヘッダー ファイル
//

#include "DinamicDlgSheet.h"
#include "F4PatchPage.h"
#include "IgnorePage.h"
#include "LogPage.h"
#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CTargetPropertyDlg ダイアログ

class CTargetPropertyDlg : public CDialog
{
protected:
	CTargetProgram* m_pTarget;

	CDinamicDlgSheet m_DlgSheet;
	CF4PatchPage m_F4PatchPage;
	CIgnorePage m_IgnorePage;
	CLogPage m_LogPage;

// コンストラクション
public:
	CTargetPropertyDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

	bool ModifyTargetInfo(CTargetProgram* tp);

// ダイアログ データ
	//{{AFX_DATA(CTargetPropertyDlg)
	enum { IDD = IDD_TARGET_PROPERTY };
	CComboBox	m_Mode;
	CString	m_TargetName;
	CString	m_TargetPath;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CTargetPropertyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	void SetActivePage();

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CTargetPropertyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMode();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_TARGETPROPERTYDLG_H__1D467A50_503A_40D7_8B44_A2CA4CE2E083__INCLUDED_)
