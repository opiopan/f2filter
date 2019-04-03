// f2freg.h : レジストリアクセス機能

#ifndef _F2FREG_H_
#define _F2FREG_H_

#pragma warning(disable : 4786)

#include <string>
#include <vector>
#include <map>
#include <hsscommon.h>

#define BENDER_NAME "HSS"
#define PRODUCT_NAME "F2Filter"
#define BASE_KEY "SOFTWARE\\" BENDER_NAME "\\" PRODUCT_NAME

// CRegistory
//  レジストリ操作の抽象化
class CRegistory{
protected:
    HKEY hKey;
	unsigned char primeBuf[256];
	unsigned char* buf;
	DWORD length;

public:
    enum ACCESS {READ, WRITE};
	class NotExistException : public HSSException{};
	class AccessDeniedException : public HSSException{};
	class NoKeyException : public HSSException{};
	class InvalidTypeException : public HSSException{};

	class CValue{
	public:
		DWORD type;
		unsigned char* buf;
		DWORD length;
		
		operator const char* (){
			if (type == REG_SZ){
				return reinterpret_cast<char*>(buf);
			}else{
				throw InvalidTypeException();
			}
		};

		operator DWORD (){
			if (type == REG_DWORD){
				return *reinterpret_cast<DWORD*>(buf);
			}else{
				throw InvalidTypeException();
			}
		};
	};

	CRegistory(HKEY base, const char* sub, ACCESS mode);
	~CRegistory();

	CValue GetValue(const char* name);

	void SetValue(const char* name, const char* value);
	void SetValue(const char* name, DWORD value);

	const char* EnumKey(unsigned int index);

	operator HKEY (){
		return hKey;
	};
};


// CSystemConfig
//  システムグローバルな定義情報
//  レジストリのHKEY_LOCAL_MACHINE配下に永続化
class CGlobalConfig{
protected:
	std::string target;
	bool bModTarget;
	GUID original;
	bool bModOriginal;
	DWORD effectId;
	bool bModEffectId;
	std::string targetName;
	bool bModTargetName;

	std::string buf;

public:
	CGlobalConfig();
	~CGlobalConfig();

    // 永続化・インスタンス化
	void Load();
	void Save();
	void Drop();

	// プロパティ取得・設定
	const char* GetTarget() const{
		return target.c_str();
	};
	void SetTarget(const char* value){
		target = value;
		bModTarget = true;
	};

	const GUID& GetOriginal() const{
		return original;
	};
	const char* GetOriginalString();
	void SetOriginal(const GUID& value){
		original = value;
        bModOriginal = true;
	};
	void SetOriginal(const char* value);

	const DWORD GetEffectId() const{
		return effectId;
	};
	void SetEffectId(DWORD value){
		effectId = value;
		bModEffectId = true;
	};

	const char* GetTargetName() const{
		return targetName.c_str();
	};
	void SetTargetName(const char* value){
		targetName = value;
		bModTargetName = true;
	};
};

// CTargetProgram
//  フィルタリング対象プログラム毎の定義情報
//  HKEY_CURRENT_USER\Software\HSS\F2Filter\Target配下に
//  永続化
class CTargetProgram{
protected:
	DWORD id;
	std::string name;
	bool bModName;
	std::string targetPath;
	bool bModTargetPath;
	bool ignoreForce;
	bool bModIgnoreForce;
	bool setGain;
	bool bModSetGain;
	bool F4Patch;
	bool bModF4Patch;
	DWORD gain;
	bool bModGain;
	bool logging;
	bool bModLogging;
	std::string logFile;
	bool bModLogFile;
	bool logAppend;
	bool bModLogAppend;

	void InitProperty();

public:
	CTargetProgram(DWORD id);
	~CTargetProgram();

    // 永続化・インスタンス化
	void Load(HKEY base);
	void Save(HKEY base);

	// プロパティ取得・設定
	DWORD GetId() const{
		return id;
	};

	const char* GetName() const{
		return name.c_str();
	};
	void SetName(const char* value){
		bModName = true;
		name = value;
	};

	const char* GetTargetPath() const{
		return targetPath.c_str();
	};
	void SetTargetPath(const char* value){
		bModTargetPath = true;
		targetPath = value;
	};

	bool GetIgnoreForce() const{
		return ignoreForce;
	};
	void SetIgnoreForce(bool value){
		bModIgnoreForce = true;
		ignoreForce = value;
	};

	bool GetSetGain() const{
		return setGain;
	};
	void SetSetGain(bool value){
		bModSetGain = true;
		setGain = value;
	};

	bool GetF4Patch() const{
		return F4Patch;
	};
	void SetF4Patch(bool value){
		bModF4Patch = true;
		F4Patch = value;
	};

	DWORD GetGain() const{
		return gain;
	};
	void SetGain(DWORD value){
		bModGain = true;
		gain = value;
	};

	bool GetLogging() const{
		return logging;
	};
	void SetLogging(bool value){
		bModLogging = true;
		logging = value;
	};

	const char* GetLogFile() const{
		return logFile.c_str();
	};
	void SetLogFile(const char* value){
		bModLogFile = true;
		logFile = value;
	};

	bool GetLogAppend() const{
		return logAppend;
	};
	void SetLogAppend(bool value){
		bModLogAppend = true;
		logAppend = value;
	};
};


// CUserConfig
//  ユーザ毎の定義情報
//  レジストリのHKEY_CURRENT_USER配下に永続化
class CUserConfig{
protected:
	typedef std::map<std::string, CTargetProgram> TargetList;
	typedef TargetList::iterator iTargetList;
	typedef TargetList::value_type vTargetList;

	TargetList list;
	std::vector<std::string> dropList;
	iTargetList currentTarget;
	DWORD maxId;

public:
	CUserConfig();
	~CUserConfig();

    // 永続化・インスタンス化
	void Load(const char* target = NULL);
	void Save();

	// フィルタリング対象プログラム情報の操作
	unsigned GetTargetNum(){
		return list.size();
	};

	void ResetEnumlate(){
		currentTarget = list.begin();
	};
	CTargetProgram* EnumTargetProgram(){
		if (currentTarget == list.end()){
			return NULL;
		}
		CTargetProgram* rc = &currentTarget->second;
		currentTarget++;
		return rc;
	};
	DWORD GetTargetId(){
		return ++maxId;
	};

	/*
	CTargetProgram* GetTargetProgram(const char* name){
		iTargetList i = list.find(name);
		if (i == list.end()){
			return NULL;
		}else{
			return &i->second;
		}
	};
	*/

	CTargetProgram* AddTargetProgram(CTargetProgram& v){
		std::pair<iTargetList, bool> rc = list.insert(vTargetList(v.GetTargetPath(), v));
		if (rc.second){
			return &(rc.first->second);
		}else{
			return NULL;
		}
	};

	void DropTargetProgram(const char* name){
		iTargetList i = list.find(name);
		if (i == list.end()){
			//
		}else{
			char buf[11];
			sprintf(buf, "%u", i->second.GetId());
			dropList.push_back(std::string(buf));
			list.erase(i->second.GetTargetPath());
		}
	};
};

#endif
