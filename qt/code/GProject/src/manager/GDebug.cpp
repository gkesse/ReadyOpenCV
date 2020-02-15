//===============================================
#include "GDebug.h"
//===============================================
GDebug* GDebug::m_instance = 0;
//===============================================
GDebug::GDebug() {
	__CLASSNAME__ = __FUNCTION__;
	m_filename = "debug.txt";
	clear();
}
//===============================================
GDebug::~GDebug() {

}
//===============================================
GDebug* GDebug::Instance() {
	if(m_instance == 0) {
		m_instance = new GDebug;
	}
	return m_instance;
}
//===============================================
void GDebug::clear() {
	FILE* lpFile = fopen(m_filename.c_str(), "w");
	fclose(lpFile);
}
//===============================================
void GDebug::getCurrentDate() {
	time_t lTimeT = time(0);
	struct tm* lTimeInfo = localtime(&lTimeT);
	int lDay = lTimeInfo->tm_mday;
	int lMonth = lTimeInfo->tm_mon + 1;
	int lYear = lTimeInfo->tm_year + 1900;
	int lHour = lTimeInfo->tm_hour;
	int lMin = lTimeInfo->tm_min;
	int lSec = lTimeInfo->tm_sec;
	sprintf(m_date, "%02d/%02d/%04d %02d:%02d:%02d", lDay, lMonth, lYear, lHour, lMin, lSec);
}
//===============================================
void GDebug::write(const char* format, ...) {
	char lBuffer[G_BUFFER_STRING];
	va_list lArgs;
	va_start(lArgs, format);
	vsprintf(lBuffer, format, lArgs);
	va_end(lArgs);
	getCurrentDate();
	FILE* lpFile = fopen(m_filename.c_str(), "a+");
	fprintf(lpFile, "%s | %s\n", m_date, lBuffer);
	fclose(lpFile);
}
//===============================================
void GDebug::writeClass(const char* className, const char* methodName, const char* format, ...) {
	char lBuffer[G_BUFFER_STRING];
	va_list lArgs;
	va_start(lArgs, format);
	vsprintf(lBuffer, format, lArgs);
	va_end(lArgs);
	getCurrentDate();
	FILE* lpFile = fopen(m_filename.c_str(), "a+");
	fprintf(lpFile, "%s | %s::%s() | %s\n", m_date, className, methodName, lBuffer);
	fclose(lpFile);
}
//===============================================
void GDebug::test() {
	writeClass(__CLASSNAME__, __FUNCTION__, "%s: %s", "key", "value");
}
//===============================================
