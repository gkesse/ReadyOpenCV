//===============================================
#include "GWindow.h"
#include "GStyle.h"
#include "GDebug.h"
//===============================================
int main( int argc, char **argv ) {
	GDebug::Instance()->write("%s()", __FUNCTION__);
    QApplication app(argc, argv);
    GStyle::Instance()->load(":/css/style.css");
    GWindow* lWindow = GWindow::Create("DEFAULT");
    lWindow->show();
    return app.exec();
}
//===============================================
