; CLW ÉtÉ@ÉCÉãÇÕ MFC ClassWizard ÇÃèÓïÒÇä‹ÇÒÇ≈Ç¢Ç‹Ç∑ÅB

[General Info]
Version=1
LastClass=CTargetPage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "F2FSetup.h"

ClassCount=11
Class1=CF2FSetupApp
Class2=CF2FSetupDlg

ResourceCount=19
Resource2=IDD_INSTALL (âpåÍ (±“ÿ∂))
Resource1=IDR_MAINFRAME
Class3=CInstallDlg
Resource3=IDD_TARGET_PROPERTY (∆≠∞ƒ◊Ÿ)
Class4=CTargetPage
Class5=CSetupSheet
Resource4=IDD_IGNORE_PAGE (âpåÍ (±“ÿ∂))
Class6=CGlobalPage
Resource5=IDD_TARGET_PAGE
Class7=CTargetPropertyDlg
Class8=CDinamicDlgSheet
Resource6=IDD_F2FSETUP_DIALOG
Class9=CF4PatchPage
Resource7=IDD_LOG_PAGE
Class10=CIgnorePage
Resource8=IDD_IGNORE_PAGE
Class11=CLogPage
Resource9=IDD_F2FSETUP_DIALOG (∆≠∞ƒ◊Ÿ)
Resource10=IDD_TARGET_PROPERTY
Resource11=IDD_F4PATCH_PAGE
Resource12=IDD_INSTALL
Resource13=IDD_LOG_PAGE (âpåÍ (±“ÿ∂))
Resource14=IDD_TARGET_PAGE (âpåÍ (±“ÿ∂))
Resource15=IDD_GLOBAL_PAGE (âpåÍ (±“ÿ∂))
Resource16=IDD_GLOBAL_PAGE
Resource17=IDD_F4PATCH_PAGE (âpåÍ (±“ÿ∂))
Resource18=IDD_F2FSETUP_DIALOG (âpåÍ (±“ÿ∂))
Resource19=IDD_TARGET_PROPERTY (âpåÍ (±“ÿ∂))

[CLS:CF2FSetupApp]
Type=0
HeaderFile=F2FSetup.h
ImplementationFile=F2FSetup.cpp
Filter=N

[CLS:CF2FSetupDlg]
Type=0
HeaderFile=F2FSetupDlg.h
ImplementationFile=F2FSetupDlg.cpp
Filter=D
LastObject=CF2FSetupDlg



[DLG:IDD_INSTALL]
Type=1
Class=CInstallDlg
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_JOYSTICK,listbox,1352728835
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[CLS:CInstallDlg]
Type=0
HeaderFile=InstallDlg.h
ImplementationFile=InstallDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_TARGET_PAGE]
Type=1
Class=CTargetPage
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_TARGET_LIST,SysListView32,1350631709
Control4=IDC_ADD_TARGET,button,1342373888
Control5=IDC_DROP_TARGET,button,1342242816
Control6=IDC_TARGET_PROPERTY,button,1342242816

[CLS:CTargetPage]
Type=0
HeaderFile=TargetPage.h
ImplementationFile=TargetPage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CTargetPage

[CLS:CSetupSheet]
Type=0
HeaderFile=SetupSheet.h
ImplementationFile=SetupSheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CSetupSheet
VirtualFilter=hWC

[DLG:IDD_GLOBAL_PAGE]
Type=1
Class=CGlobalPage
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CGlobalPage]
Type=0
HeaderFile=GlobalPage.h
ImplementationFile=GlobalPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CGlobalPage

[CLS:CTargetPropertyDlg]
Type=0
HeaderFile=TargetPropertyDlg.h
ImplementationFile=TargetPropertyDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTargetPropertyDlg

[CLS:CDinamicDlgSheet]
Type=0
HeaderFile=DinamicDlgSheet.h
ImplementationFile=DinamicDlgSheet.cpp
BaseClass=CPropertySheet
Filter=W
VirtualFilter=hWC
LastObject=CDinamicDlgSheet

[DLG:IDD_F4PATCH_PAGE]
Type=1
Class=CF4PatchPage
ControlCount=12
Control1=IDC_STATIC,button,1342308359
Control2=IDC_GAIN,msctls_trackbar32,1342373888
Control3=IDC_DEFAULT_GAIN,button,1342373889
Control4=IDC_STATIC,static,1342308866
Control5=IDC_STATIC,static,1342308864
Control6=IDC_GAIN_DISPLAY,static,1342308353
Control7=IDC_STATIC,button,1342177287
Control8=IDC_LOGGING,button,1342242819
Control9=IDC_STATIC,static,1342308352
Control10=IDC_LOG_PATH,edit,1350631552
Control11=IDC_APPEND,button,1342373897
Control12=IDC_NEW,button,1342177289

[CLS:CF4PatchPage]
Type=0
HeaderFile=F4PatchPage.h
ImplementationFile=F4PatchPage.cpp
BaseClass=CDinamicDlgPage
Filter=D
LastObject=CF4PatchPage
VirtualFilter=dWC

[DLG:IDD_IGNORE_PAGE]
Type=1
Class=CIgnorePage
ControlCount=7
Control1=IDC_STATIC,button,1342308359
Control2=IDC_SET_GAIN,button,1476591619
Control3=IDC_STATIC_GAIN,static,1476526592
Control4=IDC_GAIN,msctls_trackbar32,1476591616
Control5=IDC_STATIC_GAIN_WEEK,static,1476526594
Control6=IDC_STATIC_GAIN_STRONG,static,1476526592
Control7=IDC_GAIN_DISPLAY,static,1342308353

[CLS:CIgnorePage]
Type=0
HeaderFile=IgnorePage.h
ImplementationFile=IgnorePage.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CIgnorePage

[DLG:IDD_LOG_PAGE]
Type=1
Class=CLogPage
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LOG_PATH,edit,1350631552
Control4=IDC_APPEND,button,1342373897
Control5=IDC_NEW,button,1342177289

[CLS:CLogPage]
Type=0
HeaderFile=LogPage.h
ImplementationFile=LogPage.cpp
BaseClass=CDinamicDlgPage
Filter=D
LastObject=IDC_APPEND
VirtualFilter=dWC

[DLG:IDD_F2FSETUP_DIALOG (∆≠∞ƒ◊Ÿ)]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_F2FSETUP_DIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_TARGET_PROPERTY (∆≠∞ƒ◊Ÿ)]
Type=1
Class=?
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TARGET_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TARGET_PATH,edit,1350568064
Control5=IDC_STATIC,button,1342177287
Control6=IDC_MODE,combobox,1344340227
Control7=IDC_MODE_DESC,static,1342308352
Control8=IDC_PAGE,static,1342308352
Control9=IDOK,button,1342373889
Control10=IDCANCEL,button,1342242816

[DLG:IDD_TARGET_PROPERTY]
Type=1
Class=?
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TARGET_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TARGET_PATH,edit,1350568064
Control5=IDC_STATIC,button,1342177287
Control6=IDC_MODE,combobox,1344340227
Control7=IDC_MODE_DESC,static,1342308352
Control8=IDC_PAGE,static,1342308352
Control9=IDOK,button,1342373889
Control10=IDCANCEL,button,1342242816

[DLG:IDD_F2FSETUP_DIALOG (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_F4PATCH_PAGE (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=12
Control1=IDC_STATIC,button,1342308359
Control2=IDC_GAIN,msctls_trackbar32,1342373888
Control3=IDC_DEFAULT_GAIN,button,1342373889
Control4=IDC_STATIC,static,1342308866
Control5=IDC_STATIC,static,1342308864
Control6=IDC_GAIN_DISPLAY,static,1342308353
Control7=IDC_STATIC,button,1342177287
Control8=IDC_LOGGING,button,1342242819
Control9=IDC_STATIC,static,1342308352
Control10=IDC_LOG_PATH,edit,1350631552
Control11=IDC_APPEND,button,1342373897
Control12=IDC_NEW,button,1342177289

[DLG:IDD_GLOBAL_PAGE (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_IGNORE_PAGE (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,button,1342308359
Control2=IDC_SET_GAIN,button,1476591619
Control3=IDC_STATIC_GAIN,static,1476526592
Control4=IDC_GAIN,msctls_trackbar32,1476591616
Control5=IDC_STATIC_GAIN_WEEK,static,1476526594
Control6=IDC_STATIC_GAIN_STRONG,static,1476526592
Control7=IDC_GAIN_DISPLAY,static,1342308353

[DLG:IDD_INSTALL (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_JOYSTICK,listbox,1352728835
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[DLG:IDD_LOG_PAGE (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LOG_PATH,edit,1350631552
Control4=IDC_APPEND,button,1342373897
Control5=IDC_NEW,button,1342177289

[DLG:IDD_TARGET_PAGE (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_TARGET_LIST,SysListView32,1350631709
Control4=IDC_ADD_TARGET,button,1342373888
Control5=IDC_DROP_TARGET,button,1342242816
Control6=IDC_TARGET_PROPERTY,button,1342242816

[DLG:IDD_TARGET_PROPERTY (âpåÍ (±“ÿ∂))]
Type=1
Class=?
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TARGET_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TARGET_PATH,edit,1350568064
Control5=IDC_STATIC,button,1342177287
Control6=IDC_MODE,combobox,1344340227
Control7=IDC_MODE_DESC,static,1342308352
Control8=IDC_PAGE,static,1342308352
Control9=IDOK,button,1342373889
Control10=IDCANCEL,button,1342242816

