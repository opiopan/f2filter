// hsscommon.h : ��{�ݒ�

#ifndef _HSSCOMMON_H_
#define _HSSCOMMON_H_

// ��O�N���X

class HSSException{};
class NoMemoryException : public HSSException{};
class SystemException : public HSSException{
public:
	LONG code;
	SystemException(LONG c):code(c){};
};

#endif
