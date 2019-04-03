// hsscommon.h : 基本設定

#ifndef _HSSCOMMON_H_
#define _HSSCOMMON_H_

// 例外クラス

class HSSException{};
class NoMemoryException : public HSSException{};
class SystemException : public HSSException{
public:
	LONG code;
	SystemException(LONG c):code(c){};
};

#endif
