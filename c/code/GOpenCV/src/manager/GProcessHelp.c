//===============================================
#include "GProcessHelp.h"
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
    printf("\n");
    printf("gopencv est une application de traitement d'images video.\n\n");
    printf("Utilisation:\n");
    printf("\tgopencv [ process ] [ options ]\n\n");
    printf("Process:\n");
    printf("\t%-15s : %s\n", "help", "Affiche le programme d'aide");
    printf("\t%-15s : %s\n", "opencv_test", "Lance le programme de test");
    printf("\n");
}
//===============================================
