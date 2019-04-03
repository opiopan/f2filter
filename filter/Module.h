// Module.h : 

#ifndef _MODULE_H_
#define _MODULE_H_

#include <string>

/////////////////////////////////////////////////////////////////////////////
// CExecModule �F�@�J�����g�v���Z�X�̎��s���W���[�����J�v�Z����

class CExecModule{
protected:
	std::string name;

public:
	CExecModule();
	~CExecModule();

	operator const char*() const{
		return name.c_str();
	};

	bool operator == (const char*) const;
};

#endif
