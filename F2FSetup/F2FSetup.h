// F2FSetup.h : F2FSETUP アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
#define AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル


#define FORCE_DEFAULT_GAIN  8000
#define FORCE_MAX_GAIN      0x7fff


extern CString caption;

/////////////////////////////////////////////////////////////////////////////
// CF2FSetupApp:
// このクラスの動作の定義に関しては F2FSetup.cpp ファイルを参照してください。
//

class CF2FSetupApp : public CWinApp
{
public:
	CF2FSetupApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CF2FSetupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CF2FSetupApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#define F2FILTER_DRIVER_NAME "F2FILTER.DLL"

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_F2FSETUP_H__11DB1D65_20CF_11D6_B76B_0000E8D4B3D9__INCLUDED_)
