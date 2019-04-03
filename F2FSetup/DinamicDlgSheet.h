#if !defined(AFX_DINAMICDLGSHEET_H__C12EE4CA_0D6D_44DC_A2D5_EB8E31894D2A__INCLUDED_)
#define AFX_DINAMICDLGSHEET_H__C12EE4CA_0D6D_44DC_A2D5_EB8E31894D2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DinamicDlgSheet.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CDinamicDlgPage
class CDinamicDlgPage : public CDialog{
	DECLARE_DYNCREATE(CDinamicDlgPage)

public:
	DWORD m_DlgId;

// コンストラクション
public:
	CDinamicDlgPage(DWORD id = 0);
	virtual ~CDinamicDlgPage();
	void SetDlgId(DWORD id){
		m_DlgId = id;
	};

	BOOL Create(CWnd* pParentWnd = NULL, DWORD dwStyle = (DWORD)-1, DWORD dwExStyle = 0);
	
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CDinamicDlgSheet

class CDinamicDlgSheet{
public:
	enum SheetType {DIALOG, PROPETYSHEET};

protected:
	CArray<CDinamicDlgPage*, CDinamicDlgPage*> m_PageList;
	UINT m_nActive;

public:
	CDinamicDlgSheet();
	virtual ~CDinamicDlgSheet();

public:
	virtual void AddPage(CDinamicDlgPage* pDlg);
	virtual void SetActivePage(UINT id);
	virtual CDinamicDlgPage* GetActivePage() const;
	UINT GetActivePageNum() const{
		return m_nActive;
	};
	virtual void AttachControl(CDialog* wnd, DWORD id, SheetType type = DIALOG);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DINAMICDLGSHEET_H__C12EE4CA_0D6D_44DC_A2D5_EB8E31894D2A__INCLUDED_)
