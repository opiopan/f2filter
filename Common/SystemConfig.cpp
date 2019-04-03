#include "stdafx.h"
#include "f2freg.h"

#include <comdef.h>


// CSystemConfig
//  システムグローバルな定義情報
//  レジストリのHKEY_LOCAL_MACHINE配下に永続化

CGlobalConfig::CGlobalConfig() : 
	bModOriginal(false), bModTarget(false), bModEffectId(false), bModTargetName(false){
}

CGlobalConfig::~CGlobalConfig(){
}

void CGlobalConfig::Load(){
	bModOriginal = false;
	bModTarget = false;
	bModEffectId = false;
	bModTargetName = false;
	CRegistory reg(HKEY_LOCAL_MACHINE, BASE_KEY, CRegistory::READ);
	target = reg.GetValue("Target");

	std::string tmp = reg.GetValue("Original");
	_bstr_t ustr = tmp.c_str();
	if (CLSIDFromString(ustr, &original) != NOERROR)
		throw CRegistory::NoKeyException();

	try{
		effectId = reg.GetValue("EffectId");
	}catch (HSSException&){
		effectId = 0;
	}
	try{
		targetName = reg.GetValue("TargetName");
	}catch (HSSException&){
		targetName = "";
	}
}

void CGlobalConfig::Save(){
	CRegistory reg(HKEY_LOCAL_MACHINE, BASE_KEY, CRegistory::WRITE);

	if (bModTarget){
		reg.SetValue("Target", target.c_str());
		bModTarget = false;
	}
	if (bModOriginal){
		LPOLESTR pstr;
		if (StringFromCLSID(original, &pstr) != S_OK){
			throw NoMemoryException();
		}
		_bstr_t ustr = pstr;
		CoTaskMemFree(pstr);
		reg.SetValue("Original", static_cast<const char*>(ustr));
		bModOriginal = false;
	}
	if (bModEffectId){
		reg.SetValue("EffectId", effectId);
		bModEffectId = false;
	}
	if (bModTargetName){
		reg.SetValue("TargetName", targetName.c_str());
		bModTargetName = false;
	}
}

void CGlobalConfig::Drop(){
	LONG rc = RegDeleteKey(HKEY_LOCAL_MACHINE, BASE_KEY);
	if (rc != ERROR_SUCCESS){
		throw CRegistory::AccessDeniedException();
	}
}

const char* CGlobalConfig::GetOriginalString(){
	LPOLESTR pstr;
	if (StringFromCLSID(original, &pstr) != S_OK){
		throw NoMemoryException();
	}
	_bstr_t ustr = pstr;
	CoTaskMemFree(pstr);
	buf = ustr;
	return buf.c_str();
}

void CGlobalConfig::SetOriginal(const char* value){
	_bstr_t ustr = value;
	unsigned long rc = CLSIDFromString(ustr, &original);
	if (rc != NOERROR)
		throw SystemException(rc);
	bModOriginal = true;
}
