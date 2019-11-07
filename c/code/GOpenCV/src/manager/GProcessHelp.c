//===============================================
#include "GProcessHelp.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessHelpO = 0;
//===============================================
static void GProcessHelp_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessHelp_New() {
	GProcessO* lParent = GProcess_New();
	GProcessHelpO* lChild = (GProcessHelpO*)malloc(sizeof(GProcessHelpO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessHelp_Delete;
	lParent->Run = GProcessHelp_Run;
	return lParent;
}
//===============================================
void GProcessHelp_Delete() {
	GProcess_Delete(m_GProcessHelpO);
	m_GProcessHelpO = 0;
}
//===============================================
GProcessO* GProcessHelp() {
	if(m_GProcessHelpO == 0) {
		m_GProcessHelpO = GProcessHelp_New();
	}
	return m_GProcessHelpO;
}
//===============================================
static void GProcessHelp_Run(int argc, char** argv) {
    GConsole()->Print("\n");
    GConsole()->Print("gopencv est une application de traitement d'images video.\n\n");
    GConsole()->Print("Utilisation:\n");
    GConsole()->Print("\tgopencv [ process ] [ options ]\n\n");
    GConsole()->Print("Process:\n");
    GConsole()->Print("\t%-15s : %s\n", "Help", "Affiche le programme d'aide");
    GConsole()->Print("\t%-15s : %s\n", "Compile", "Lance le programme de compilation");
    GConsole()->Print("\n");
}
//===============================================
