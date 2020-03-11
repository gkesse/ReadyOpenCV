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
	int lLenght = 0;
	getCurrentDate();
	lLenght += sprintf(&lBuffer[lLenght], "%s | ", m_date);
	va_list lArgs;
	va_start(lArgs, format);
	lLenght += vsprintf(&lBuffer[lLenght], format, lArgs);
	va_end(lArgs);
	FILE* lpFile = fopen(m_filename.c_str(), "a+");
	fprintf(lpFile, "%s\n", lBuffer);
	fclose(lpFile);
	cout << lBuffer << "\n";
}
//===============================================
void GDebug::write(int format, ...) {
	if(format == 0) return;
	char lBuffer[G_BUFFER_STRING];
	int lLenght = 0;
	getCurrentDate();
	lLenght += sprintf(&lBuffer[lLenght], "%s | ", m_date);
	int lType = format;
	va_list lArgs;
	va_start(lArgs, format);
	while(1) {
		if(lType == 0) break;
		if(lType == 1) {
			int lData = va_arg(lArgs, int);
			lLenght += sprintf(&lBuffer[lLenght], "%d", lData);
		}
		else if(lType == 2) {
			double lData = va_arg(lArgs, double);
			lLenght += sprintf(&lBuffer[lLenght], "%f", lData);
		}
		else if(lType == 3) {
			char* lData = va_arg(lArgs, char*);
			lLenght += sprintf(&lBuffer[lLenght], "%s", lData);
		}
		lType = va_arg(lArgs, int);
	}
	va_end(lArgs);
	FILE* lpFile = fopen(m_filename.c_str(), "a+");
	fprintf(lpFile, "%s\n", lBuffer);
	fclose(lpFile);
	cout << lBuffer << "\n";
}
//===============================================
