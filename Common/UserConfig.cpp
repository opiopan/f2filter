#include "stdafx.h"
#include "f2freg.h"

// CUserConfig
//  ユーザ毎の定義情報
//  レジストリのHKEY_CURRENT_USER配下に永続化

CUserConfig::CUserConfig() : maxId(0){
	currentTarget = list.end();
}

CUserConfig::~CUserConfig(){
}

void CUserConfig::Load(const char* target){
	// グローバルな定義展開
	CRegistory rBase(HKEY_CURRENT_USER, BASE_KEY, CRegistory::READ);

	//　ターゲットプログラムの展開
	CRegistory rTarget(rBase, "Target", CRegistory::READ);
	const char* name;
	for (unsigned i = 0; name = rTarget.EnumKey(i); i++){
		CTargetProgram tp(atoi(name));
		tp.Load(rTarget);
		if (tp.GetId() > maxId){
			maxId = tp.GetId();
		}
		if (target == NULL ||
			CompareString(
				LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
				tp.GetTargetPath(), -1, target, -1) == CSTR_EQUAL){
			AddTargetProgram(tp);
		}
	}
}

void CUserConfig::Save(){
	// グローバルな定義のセーブ
	CRegistory rBase(HKEY_CURRENT_USER, BASE_KEY, CRegistory::WRITE);

	//　ターゲットプログラムのセーブ
	CRegistory rTarget(rBase, "Target", CRegistory::WRITE);

	std::vector<std::string>::iterator i;
	for (i = dropList.begin(); i != dropList.end(); i++){
		LONG rc = RegDeleteKey(rTarget, i->c_str());
		if (rc != ERROR_SUCCESS){
			// throw CRegistory::AccessDeniedException();
		}
	}

	ResetEnumlate(); 
	CTargetProgram* tp;
	while (tp = EnumTargetProgram()){
		tp->Save(rTarget);
	}
}


// CUserConfig
//  ユーザ毎の定義情報
//  レジストリのHKEY_CURRENT_USER配下に永続化
void CTargetProgram::InitProperty(){
	name = "";
	bModName = false;
	targetPath = "";
	bModTargetPath = false;
	ignoreForce = false;
	bModIgnoreForce = false;
	setGain = false;
	bModSetGain = false;
	F4Patch = false;
	bModF4Patch = false;
	bModGain = false;
	logging = false;
	bModLogging = false;
	bModLogFile = false;
	logAppend = true;
	bModLogAppend = false;
}

CTargetProgram::CTargetProgram(DWORD i) : id(i){
	InitProperty();
}

CTargetProgram::~CTargetProgram(){
}

void CTargetProgram::Load(HKEY base){
	InitProperty();
	
	char buf[11];
	sprintf(buf, "%u", id);
	CRegistory reg(base, buf, CRegistory::READ);

#pragma warning(disable : 4800)
	try{
		name = reg.GetValue("Name");
	}catch (CRegistory::NoKeyException&){
	}
	try{
		targetPath = reg.GetValue("TargetPath");
	}catch (CRegistory::NoKeyException&){
	}
	try{
		ignoreForce = static_cast<DWORD>(reg.GetValue("IgnoreForce"));
	}catch (CRegistory::NoKeyException&){
	}
	try{
		setGain = static_cast<DWORD>(reg.GetValue("SetGain"));
	}catch (CRegistory::NoKeyException&){
	}
	try{
		F4Patch = static_cast<DWORD>(reg.GetValue("F4Patch"));
	}catch (CRegistory::NoKeyException&){
	}
	try{
		gain = reg.GetValue("Gain");
	}catch (CRegistory::NoKeyException&){
	}
	try{
		logging = static_cast<DWORD>(reg.GetValue("Logging"));
	}catch (CRegistory::NoKeyException&){
	}
	try{
		logFile = reg.GetValue("LogFile");
	}catch (CRegistory::NoKeyException&){
	}
	try{
		logAppend = static_cast<DWORD>(reg.GetValue("LogAppend"));
	}catch (CRegistory::NoKeyException&){
	}
#pragma warning(default : 4800)
}


void CTargetProgram::Save(HKEY base){
	
	char buf[11];
	sprintf(buf, "%u", id);
	CRegistory reg(base, buf, CRegistory::WRITE);

	if (bModName){
		reg.SetValue("Name", name.c_str());
	}
	if (bModTargetPath){
		reg.SetValue("TargetPath", targetPath.c_str());
	}
	if (bModIgnoreForce){
		reg.SetValue("IgnoreForce", ignoreForce);
	}
	if (bModSetGain){
		reg.SetValue("SetGain", setGain);
	}
	if (bModF4Patch){
		reg.SetValue("F4Patch", F4Patch);
	}
	if (bModGain){
		reg.SetValue("Gain", gain);
	}
	if (bModLogging){
		reg.SetValue("Logging", logging);
	}
	if (bModLogFile){
		reg.SetValue("LogFile", logFile.c_str());
	}
	if (bModLogAppend){
		reg.SetValue("LogAppend", logAppend);
	}

}

