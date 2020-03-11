//===============================================
#include "GSetting.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GSetting* GSetting::m_instance = 0;
//===============================================
GSetting::GSetting() {
	__CLASSNAME__ = __FUNCTION__;
	m_filename = "setting.ini";
	m_setting = new QSettings(m_filename, QSettings::IniFormat);
}
//===============================================
GSetting::~GSetting() {

}
//===============================================
GSetting* GSetting::Instance() {
	if(m_instance == 0) {
		m_instance = new GSetting;
	}
	return m_instance;
}
//===============================================
void GSetting::load() {
	int lModuleMax = m_setting->value("module/max", G_MODULE_MAX).toInt();
	GManager::Instance()->setModuleMax(lModuleMax);
}
//===============================================
void GSetting::save() {

}
//===============================================
void GSetting::test() {
	m_setting->setValue("module/max", 3);
}
//===============================================
