// ForceFeedbackFilter.h : CForceFeedbackFilter の宣言

#ifndef __FORCEFEEDBACKFILTER_H_
#define __FORCEFEEDBACKFILTER_H_

#include "resource.h"       // メイン シンボル


// Helper　UUID
/*
struct __declspec(uuid("{db11d351-3bf6-4f2c-a82b-b26cb9676d2b}")) SWFF2EffectDriver;
#define CLSID_SWFF2EffectDriver _uuidof(SWFF2EffectDriver)
*/

/////////////////////////////////////////////////////////////////////////////
// CForceFeedbackFilter
class ATL_NO_VTABLE CForceFeedbackFilter : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CForceFeedbackFilter, &CLSID_ForceFeedbackFilter>,
	public IDirectInputEffectDriver
{
protected:
	typedef CComPtr<IDirectInputEffectDriver> CDriverPtr;
	CDriverPtr pOrg;
	FILE* fp;
	BOOL bPatch;
	BOOL bIgnore;
	BOOL bIgnoreSetGain;
	DWORD gain;
	DWORD swapEffectId;
	DWORD dwEffectCache;

public:
	// Constructer & Destructer
	CForceFeedbackFilter();

	virtual ~CForceFeedbackFilter();

	// ATL COM Macros
	DECLARE_REGISTRY_RESOURCEID(IDR_FORCEFEEDBACKFILTER)

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CForceFeedbackFilter)
		COM_INTERFACE_ENTRY_IID(IID_IDirectInputEffectDriver, IDirectInputEffectDriver)
	END_COM_MAP()

public:
	// IDirectInputEffectDriver
    STDMETHOD(DeviceID)(DWORD,DWORD,DWORD,DWORD,LPVOID);
    STDMETHOD(GetVersions)(LPDIDRIVERVERSIONS);
    STDMETHOD(Escape)(DWORD,DWORD,LPDIEFFESCAPE);
    STDMETHOD(SetGain)(DWORD,DWORD);
    STDMETHOD(SendForceFeedbackCommand)(DWORD,DWORD);
    STDMETHOD(GetForceFeedbackState)(DWORD,LPDIDEVICESTATE);
    STDMETHOD(DownloadEffect)(DWORD,DWORD,LPDWORD,LPCDIEFFECT,DWORD);
    STDMETHOD(DestroyEffect)(DWORD,DWORD);
    STDMETHOD(StartEffect)(DWORD,DWORD,DWORD,DWORD);
    STDMETHOD(StopEffect)(DWORD,DWORD);
    STDMETHOD(GetEffectStatus)(DWORD,DWORD,LPDWORD);
};

#endif //__FORCEFEEDBACKFILTER_H_
