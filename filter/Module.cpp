#include "stdafx.h"
#include "Filter.h"
#include "Module.h"
#include "hsscommon.h"

#include <tlhelp32.h>
#include <string.h>

class CHandle{
protected:
	HANDLE hHandle;

public:
	CHandle(HANDLE h){
		hHandle = h;
	};
	~CHandle(){
		CloseHandle(hHandle);
	};
	operator HANDLE (){
		return hHandle;
	};
};

/////////////////////////////////////////////////////////////////////////////
// 実行モジュール名のカプセル化
CExecModule::CExecModule(){
	CHandle hMod = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
	if (hMod == reinterpret_cast<HANDLE>(-1)){
		throw SystemException(GetLastError());
	}

	MODULEENTRY32 me;
	me.dwSize = sizeof(me);
	for (BOOL result = Module32First(hMod, &me);
	     result;
		 result = Module32Next(hMod, &me)){
		int length = strlen(me.szModule);
		if (CompareString(LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE, 
			me.szModule + length - 4, -1, ".EXE", -1) == CSTR_EQUAL){
			name = me.szExePath;
			break;
		}
	}
}

CExecModule::~CExecModule(){
}

bool CExecModule::operator == (const char* dest) const{
	return CompareString(
		LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE, 
		name.c_str(), -1, dest, -1) == CSTR_EQUAL;
}
