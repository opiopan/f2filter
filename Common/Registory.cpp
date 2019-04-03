#include "stdafx.h"
#include "f2freg.h"
#include <string.h>

// CRegistory
//  ÉåÉWÉXÉgÉäëÄçÏÇÃíäè€âª

CRegistory::CRegistory(HKEY base, const char* sub, ACCESS mode) : 
hKey(NULL), buf(primeBuf), length(sizeof(primeBuf)){
	if (mode == WRITE){
		DWORD result;
		LONG rc = ::RegCreateKeyEx(
			base, sub, 0, NULL,REG_OPTION_NON_VOLATILE, 
			KEY_WRITE | KEY_READ, NULL, &hKey, &result);
		if (rc != ERROR_SUCCESS){
			throw AccessDeniedException();
		}
	}else{
		LONG rc = ::RegOpenKeyEx(base, sub, 0, KEY_READ, &hKey);
		if (rc != ERROR_SUCCESS){
			throw NotExistException();
		}
	}
}

CRegistory::~CRegistory(){
	if (buf != primeBuf){
		delete[] buf;
	}
	if (hKey != NULL){
		RegCloseKey(hKey);
	}
}

CRegistory::CValue CRegistory::GetValue(const char* name){
	CValue value;
RETRY:
	value.buf = buf;
	value.length = length;
	LONG rc = ::RegQueryValueEx(hKey, name, NULL, &value.type, value.buf, &value.length);
	if (rc == ERROR_MORE_DATA){
		if (buf != primeBuf){
			delete[] buf;
		}
		length = value.length + 1;
		buf = new unsigned char[length];
		goto RETRY;
	} else if (rc != ERROR_SUCCESS){
		throw NoKeyException();
	}

	return value;
}

void CRegistory::SetValue(const char* name, const char* value){
	LONG rc = RegSetValueEx(hKey, name, 0, REG_SZ, reinterpret_cast<const BYTE*>(value), strlen(value) + 1);
	if (rc != ERROR_SUCCESS){
		throw SystemException(rc);
	}
}

void CRegistory::SetValue(const char* name, DWORD value){
	LONG rc = RegSetValueEx(hKey, name, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(value));
	if (rc != ERROR_SUCCESS){
		throw SystemException(rc);
	}
}


const char* CRegistory::EnumKey(unsigned int index){
	FILETIME ft;
RETRY:
	unsigned long len = length;
	LONG rc = RegEnumKeyEx(
		hKey, index, reinterpret_cast<char*>(buf), &len, NULL, NULL, NULL, &ft);
	if (rc == ERROR_MORE_DATA){
		if (buf != primeBuf){
			delete[] buf;
		}
		buf = new unsigned char[len + 1];
		length = len + 1;
		goto RETRY;
	} else if (rc == ERROR_NO_MORE_ITEMS){
		return NULL;
	} else if (rc != ERROR_SUCCESS){
		throw SystemException(rc);
	}

	return reinterpret_cast<char*>(buf);
}
