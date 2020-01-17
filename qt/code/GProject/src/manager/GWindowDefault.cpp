//===============================================
#include "GWindowDefault.h"
#include "GTitle.h"
#include "GMenu.h"
#include "GWorkspace.h"
#include "GSection.h"
#include "GStatusBar.h"
#include "GDialog.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GWindowDefault::GWindowDefault(QWidget* parent) :
GWindow(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;
	QHBoxLayout* lCenterLayout = new QHBoxLayout;

	GTitle* lTitle = GTitle::Create("DEFAULT");
	GMenu* lMenu = GMenu::Create("DEFAULT");
	GWorkspace* lWorkspace = GWorkspace::Create("DEFAULT");
	GSection* lSection = GSection::Create("DEFAULT");
	GStatusBar* lStatusBar = GStatusBar::Create("DEFAULT");

	lCenterLayout->setMargin(0);
	lCenterLayout->setSpacing(0);
	lCenterLayout->addWidget(lMenu);
	lCenterLayout->addWidget(lWorkspace, 1);
	lCenterLayout->addWidget(lSection);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lTitle);
	lMainLayout->addLayout(lCenterLayout, 1);
	lMainLayout->addWidget(lStatusBar);

	setLayout(lMainLayout);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMinimize()), this, SLOT(slotWindowMinimize()));
	connect(lTitle, SIGNAL(emitWindowMaximize()), this, SLOT(slotWindowMaximize()));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(close()));
	connect(lTitle, SIGNAL(emitWindowFullScreen()), this, SLOT(slotWindowFullScreen()));
	connect(lMenu, SIGNAL(emitAddModuleMenuSelect(QString)), lSection, SLOT(slotAddModuleMenuSelect(QString)));

	connect(lSection, SIGNAL(emitModuleImageAction(QString)), this, SLOT(slotModuleImageAction(QString)));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));
	connect(this, SIGNAL(emitWindowMaximize(int, int)), lTitle, SLOT(slotWindowMaximize(int, int)));
	connect(this, SIGNAL(emitWindowFullScreen(int, int)), lTitle, SLOT(slotWindowFullScreen(int, int)));

	setWindowTitle(tr("OpenCV | ReadyDev"));
	GPicto::Instance()->setColor("navy");
	setWindowIcon(GPicto::Instance()->getPicto(fa::snowflakeo));
}
//===============================================
GWindowDefault::~GWindowDefault() {

}
//===============================================
void GWindowDefault::slotWindowPress(QPoint position) {
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GWindowDefault::slotWindowMove(QPoint position) {
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
void GWindowDefault::slotWindowMinimize() {
	showMinimized();
}
//===============================================
void GWindowDefault::slotWindowMaximize() {
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowMaximized) {
		showNormal();
	}
	else if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showMaximized();
	}
	emit emitWindowMaximize(lWindowState, windowState());
}
//===============================================
void GWindowDefault::slotWindowFullScreen() {
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showFullScreen();
	}
	emit emitWindowFullScreen(lWindowState, windowState());
}
//===============================================
void GWindowDefault::slotModuleImageAction(QString action) {
	GDialog* lImageOpen = GDialog::Create("IMAGE_OPEN", this);
	int lOk = lImageOpen->exec();

	if(lOk == QDialog::Accepted) {
		GPrint::Instance()->print("QDialog::Accepted");
	}
	else if(lOk == QDialog::Rejected) {
		GPrint::Instance()->print("QDialog::Rejected");
	}

	delete lImageOpen;
}
//===============================================
