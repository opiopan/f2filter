#if !defined(AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_)
#define AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetupSheet.h : ヘッダー ファイル
//

#include "TargetPage.h"
#include "GlobalPage.h"
#include "f2freg.h"

/////////////////////////////////////////////////////////////////////////////
// CSetupSheet

class CSetupSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetupSheet)

// コンストラクション
public:
	CSetupSheet(CGlobalConfig& gconf, CUserConfig& uconf);

// アトリビュート
public:

protected:
	HICON m_hIcon;

	CGlobalConfig& m_GConf;
	CUserConfig& m_UConf;

	CTargetPage m_TargetPage;
	CGlobalPage m_GlobalPage;

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupSheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CSetupSheet();


protected:
	void AddPages();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CSetupSheet)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPSHEET_H__E8DF3147_8A8A_4CED_B60E_8086441FE673__INCLUDED_)
