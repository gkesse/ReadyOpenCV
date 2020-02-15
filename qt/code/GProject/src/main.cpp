//===============================================
#include "GWindow.h"
#include "GStyle.h"
//===============================================
int main( int argc, char **argv ) {
    QApplication app(argc, argv);
    GStyle::Instance()->load(":/css/style.css");
    GWindow* lWindow = GWindow::Create("DEFAULT");
    lWindow->show();
    return app.exec();
}
//===============================================
