// ForceFeedbackFilter.cpp : CForceFeedbackFilter のインプリメンテーション
#include "stdafx.h"
#include "Filter.h"
#include "ForceFeedbackFilter.h"
#include "f2freg.h"
#include "module.h"

#define DUMMY_EFFECT 0xffff0000


/////////////////////////////////////////////////////////////////////////////
// ログ採取用ヘルパ関数

void DumpWord(FILE* fp, const char* name, const void* buf, int size){
	fprintf(fp, "\t%s: %d bytes\n", name, size);
	int i;
	int* p;
	for (p = (int*)buf, i = 0; i < ((size + 3) / 4); i += 4, p += 4){
		fprintf(fp, "\t\t[%.8x] %.8x %.8x %.8x %.8x\n",
			p, p[0], p[1], p[2], p[3]);
	}
}

inline unsigned char C2F(unsigned char d){
	if (d >= 0x20 && d < 0x7f)
		return d;
	else
		return '?';
}

void DumpByte(FILE* fp, const char* name, const void* buf, int size){
	fprintf(fp, "\t%s: %d bytes\n", name, size);
	int i;
	unsigned char* p;
	for (p = (unsigned char*)buf, i = 0; i < size; i += 16, p += 16){
		fprintf(fp, 
			"\t\t[%.8x] "
			"%.2x%.2x%.2x%.2x %.2x%.2x%.2x%.2x "
			"%.2x%.2x%.2x%.2x %.2x%.2x%.2x%.2x "
			"[%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c]\n",
			p, 
			(int)p[0], (int)p[1], (int)p[2], (int)p[3], 
			(int)p[4], (int)p[5], (int)p[6], (int)p[7],
			(int)p[8], (int)p[9], (int)p[10], (int)p[11], 
			(int)p[12], (int)p[13], (int)p[14], (int)p[15],
			C2F(p[0]), C2F(p[1]), C2F(p[2]), C2F(p[3]), 
			C2F(p[4]), C2F(p[5]), C2F(p[6]), C2F(p[7]), 
			C2F(p[8]), C2F(p[9]), C2F(p[10]), C2F(p[11]), 
			C2F(p[12]), C2F(p[13]), C2F(p[14]), C2F(p[15]));
	}
}


/////////////////////////////////////////////////////////////////////////////
// CForceFeedbackFilter

//------------------------------------
// コンストラクタ

CForceFeedbackFilter::CForceFeedbackFilter(){
	dwEffectCache = 0;

	//
	// オリジナルのフォースフィードバックドライバロード
	//
	CGlobalConfig gconf;
	try{
		gconf.Load();

		swapEffectId = gconf.GetEffectId();

		IDirectInputEffectDriver* p;
		HRESULT rc;

	RETRY:
		rc = CoCreateInstance(
			gconf.GetOriginal(), NULL, CLSCTX_ALL,
			IID_IDirectInputEffectDriver, (void**)&p);
		switch (rc){
		case CO_E_NOTINITIALIZED:
			rc = CoInitialize(NULL);
			goto RETRY;
		case S_OK:
			pOrg = p;
			break;
		}
	}catch(HSSException&){
		pOrg = NULL;
	}

	//
	// フィルタリング動作決定
	//
	try{
		CExecModule mod;

		CUserConfig uconf;
		uconf.Load(mod);
		uconf.ResetEnumlate();
		CTargetProgram* tp = uconf.EnumTargetProgram();
		if (tp){
			bPatch = tp->GetF4Patch();			// F4向けパッチフラグ
			bIgnore = tp->GetIgnoreForce();		// フォースフィードバック無効化フラグ
			bIgnoreSetGain = tp->GetSetGain();	// フォースフィードバック無効化時のゲイン設定フラグ
			gain = tp->GetGain();				// ゲイン

			if (tp->GetLogging()){
				// ログ採取モード
				fp = fopen(tp->GetLogFile(), tp->GetLogAppend() ? "a+" : "w+");
				if (fp){
					SYSTEMTIME st;
					GetLocalTime(&st);

					fprintf(fp, "##################### Driver Loaded %d-%.2d-%.2d %.2d:%.2d:%.2d #####################\n",
					        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
					fprintf(fp, "# Execute File:    %s\n", tp->GetTargetPath());
					fprintf(fp, "# Game Controler:  %s\n", gconf.GetTargetName());
					fprintf(fp, "# OEMID:           %s\n", gconf.GetTarget());
					fprintf(fp, "# CLSID:           %s\n", gconf.GetOriginalString());
					fprintf(fp, "# Spring EffectID: 0x%.8x\n", gconf.GetEffectId());
					fprintf(fp, "#\n");
					fflush(fp);
				}
			}else{
				fp = NULL;
			}
		}else{
			fp = NULL;
			bIgnore = false;
			bIgnoreSetGain = false;
			bPatch = false;
		}
	}catch(HSSException&){
		fp = NULL;
		bIgnore = false;
		bIgnoreSetGain = false;
		bPatch = false;
	}
}


//------------------------------------
// デストラクタ

CForceFeedbackFilter::~CForceFeedbackFilter(){
	if (fp){
		SYSTEMTIME st;
		GetLocalTime(&st);
		fprintf(fp, "#################### Driver Unoaded %d-%.2d-%.2d %.2d:%.2d:%.2d ####################\n\n\n",
		        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		fclose(fp);
	}
}


//------------------------------------------
// IDirectInputEffectDriverのインプリメント

STDMETHODIMP CForceFeedbackFilter::DeviceID(DWORD dwDIVer, DWORD dwExternalID, 
											DWORD fBegin, DWORD dwInternalId, LPVOID lpReserved){
	if (fp){
		fprintf(fp, "DeviceID()\n");
		fprintf(fp, "\tdwDIVer:%.8x dwExternalID:%.8x\n\tfBegin:%.8x dwInternalID:%.8x\n",
			dwDIVer, dwExternalID, fBegin, dwInternalId);
		fflush(fp);
	}
	if (pOrg){
		return pOrg->DeviceID(dwDIVer, dwExternalID, fBegin, dwInternalId, lpReserved);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::GetVersions(LPDIDRIVERVERSIONS pvers){
	if (fp){
		fprintf(fp, "GetVersions()\n");
		fflush(fp);
	}
	if (pOrg){
		HRESULT rc = pOrg->GetVersions(pvers);
		if(fp){
			DumpWord(fp, "pvers[o]", pvers, sizeof(*pvers));
		}
		return rc;
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::Escape(DWORD dwID, DWORD dwEffect, LPDIEFFESCAPE pesc){
	if (fp){
		fprintf(fp, "Escape()\n");
		fprintf(fp, "\tdwID:%.8x dwEffect:%.8x\n", dwID, dwEffect);
		DumpWord(fp, "pesc", pesc, sizeof(*pesc));
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffect == DUMMY_EFFECT){
			return pOrg->Escape(dwID, dwEffectCache, pesc);
		}
		return pOrg->Escape(dwID, dwEffect, pesc);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::SetGain(DWORD dwID, DWORD dwGain){
	if (fp){
		fprintf(fp, "SetGain()\n");
		fprintf(fp, "\tdwID:%.8x dwGain:%.8x\n", dwID, dwGain);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		return pOrg->SetGain(dwID, dwGain);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::SendForceFeedbackCommand(DWORD dwID, DWORD  dwCommand){
	if (fp){
		fprintf(fp, "SendForceFeedbackCommand()\n");
		fprintf(fp, "\tdwID:%.8x dwCommand:%.8x\n", dwID, dwCommand);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		HRESULT rc = pOrg->SendForceFeedbackCommand(dwID, dwCommand);
		if (bPatch && dwCommand == DISFFC_STOPALL){
			static DWORD rgdwAxes[] = {0x01000002, 0x01000102, 0, 0};
			static LONG rglDirection[] = {0x00002328, 0, 0, 0};
			static unsigned char  parm[] = {
				0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x10,0x27,0x00,0x00,0x10,0x27,0x00,0x00,
				0x10,0x27,0x00,0x00,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,
				0x10,0x27,0x00,0x00,0x10,0x27,0x00,0x00,0x10,0x27,0x00,0x00,0x64,0x00,0x00,0x00};
				/*
				0x00,0x00,0x00,0x00,0xfa,0x19,0x00,0x00,0xfa,0x19,0x00,0x00,0xfa,0x19,0x00,0x00,
				0xfa,0x19,0x00,0x00,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfa,0x19,0x00,0x00,
				0xfa,0x19,0x00,0x00,0xfa,0x19,0x00,0x00,0xfa,0x19,0x00,0x00,0x64,0x00,0x00,0x00};
				*/
			DIEFFECT eff;
			eff.dwSize = sizeof(eff);
			//eff.dwFlags = 0x20;
			eff.dwFlags = DIEFF_POLAR;
			eff.dwDuration = 0xffffffff;
			eff.dwSamplePeriod = 0x0;
			eff.dwGain = gain;
			eff.dwTriggerButton = 0xffffffff;
			eff.dwTriggerRepeatInterval = 0;
			eff.cAxes = 2;
			eff.rgdwAxes = rgdwAxes;
			eff.rglDirection = rglDirection;
			eff.lpEnvelope = 0;
			eff.cbTypeSpecificParams = 0x30;
			eff.lpvTypeSpecificParams = parm;
			eff.dwStartDelay = 0;
			
			pOrg->DownloadEffect(dwID, swapEffectId, &dwEffectCache, &eff, 0x3ff);
			pOrg->StartEffect(dwID, dwEffectCache, 0, 1);
			if (fp){
				fprintf(fp, "\t**** For Falcon4.0 (Download & Start a spring effect) ****\n");
				fflush(fp);
			}
		}

		return rc;
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::GetForceFeedbackState(DWORD dwID, LPDIDEVICESTATE pds){
	if (fp){
		fprintf(fp, "GetForceFeedbackState()\n");
		fflush(fp);
	}
	if (pOrg){
		return pOrg->GetForceFeedbackState(dwID, pds);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::DownloadEffect(DWORD dwID, DWORD  dwEffectID, LPDWORD pdwEffect, 
												  LPCDIEFFECT peff, DWORD dwFlags){
	if (fp){
		fprintf(fp, "DownloadEffect()\n");
		fprintf(fp, "\tdwID:%.8x dwEffectID:%.8x\n", dwID, dwEffectID);
		if(pdwEffect)
			fprintf(fp, "\tpdwEffect:%.8x\n", *pdwEffect);
		else
			fprintf(fp, "\tpdwEffect:NULL\n");
		DumpWord(fp, "peff", peff, sizeof(*peff));
		DumpWord(fp, "peff->rgdwAxes", 
			peff->rgdwAxes, sizeof(DWORD) * peff->cAxes);
		DumpWord(fp, "peff->rglDirection", 
			peff->rglDirection, sizeof(DWORD) * peff->cAxes);
		DumpByte(fp, "peff->lpvTypeSpecificParams",
			peff->lpvTypeSpecificParams, peff->cbTypeSpecificParams);
		fprintf(fp, "\tdwFlags:%.8x\n", dwFlags);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffectID == swapEffectId){
			*pdwEffect = DUMMY_EFFECT;
			if (fp){
				fprintf(fp, "\t**** For Falcon4.0 (Ignore this effect & Return dummy id/%.8x) ****\n", DUMMY_EFFECT);
				fflush(fp);
			}
			return S_OK;
		}

		HRESULT rc = pOrg->DownloadEffect(dwID, dwEffectID, pdwEffect, peff, dwFlags);
        if (fp){
			if(pdwEffect)
				fprintf(fp, "\tpdwEffect[o]:%.8x\n", *pdwEffect);
			else
				fprintf(fp, "\tpdwEffect[o]:NULL\n");
		}
		return rc;
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::DestroyEffect(DWORD dwID, DWORD dwEffect){
	if (fp){
		fprintf(fp, "DestroyEffect()\n");
		fprintf(fp, "\tdwID:%.8x dwEffect:%.8x\n", dwID, dwEffect);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffect == DUMMY_EFFECT){
			if (fp){
				fprintf(fp, "\t**** For Falcon4.0 (Ignore this function) ****\n");
				fflush(fp);
			}
			return S_OK;
		}
		return pOrg->DestroyEffect(dwID, dwEffect);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::StartEffect(DWORD dwID, DWORD dwEffect, DWORD dwMode, 
											   DWORD dwCount){
	if (fp){
		fprintf(fp, "StartEffect()\n");
		fprintf(fp, "\tdwID:%.8x dwEffect:%.8x\n", dwID, dwEffect);
		fprintf(fp, "\tdwMode:%.8x dwCount:%.8x\n", dwMode, dwCount);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffect == DUMMY_EFFECT){
			if (fp){
				fprintf(fp, "\t**** For Falcon4.0 (Ignore this function) ****\n");
				fflush(fp);
			}
			return S_OK;
		}
		return pOrg->StartEffect(dwID, dwEffect, dwMode, dwCount);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::StopEffect(DWORD dwID, DWORD dwEffect){
	if (fp){
		fprintf(fp, "StopEffect()\n");
		fprintf(fp, "\tdwID:%.8x dwEffect:%.8x\n", dwID, dwEffect);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffect == DUMMY_EFFECT){
			if (fp){
				fprintf(fp, "\t**** For Falcon4.0 (Ignore this function) ****\n");
				fflush(fp);
			}
			return S_OK;
		}
		return pOrg->StopEffect(dwID, dwEffect);
	}
	return S_OK;
}

STDMETHODIMP CForceFeedbackFilter::GetEffectStatus(DWORD dwID, DWORD  dwEffect, LPDWORD pdwStatus){
	if (fp){
		fprintf(fp, "GetEffectStatus()\n");
		fprintf(fp, "\tdwID:%.8x dwEffect:%.8x\n", dwID, dwEffect);
		fflush(fp);
	}
	if (pOrg && !bIgnore){
		if (bPatch && dwEffect == DUMMY_EFFECT){
			return pOrg->GetEffectStatus(dwID, dwEffectCache, pdwStatus);
		}
		return pOrg->GetEffectStatus(dwID, dwEffect, pdwStatus);
	}
	return S_OK;
}
