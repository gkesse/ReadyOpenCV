//================================================
#include "GConsole.h"
//================================================
GConsole* GConsole::m_instance = 0;
//================================================
GConsole::GConsole() {

}
//================================================
GConsole::~GConsole() {
	
}
//================================================
GConsole* GConsole::Instance() {
	if(m_instance == 0) {
		m_instance = new GConsole;
	}
	return m_instance;
}
//================================================
void GConsole::print(const string& data) {
    cout << data << "\n";
}
//================================================
