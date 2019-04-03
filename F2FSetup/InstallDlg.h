#if !defined(AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// InstallDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CInstallDlg ダイアログ

class CInstallDlg : public CDialog
{
public:
	class Controler{
	public:
		CString name;
		CString targetId;
		CString clsId;
	};
	
	Controler m_controler;

protected:
	CArray<Controler, Controler&> m_list;

// コンストラクション
public:
	CInstallDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CInstallDlg)
	enum { IDD = IDD_INSTALL };
	CListBox	m_selectedList;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CInstallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CInstallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeJoystick();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_INSTALLDLG_H__11DB1D6F_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
