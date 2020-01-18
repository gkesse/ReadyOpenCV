//===============================================
#include "GWindowDefault.h"
#include "GTitle.h"
#include "GMenu.h"
#include "GWorkspace.h"
#include "GSection.h"
#include "GStatusBar.h"
#include "GDialog.h"
#include "GPicto.h"
#include "GImage.h"
#include "GManager.h"
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
	GManager* lManager = GManager::Instance();

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

	setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
	setAttribute(Qt::WA_TranslucentBackground);

	m_sizeGrip = new QSizeGrip(this);
	m_shape = 0;

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMinimize()), this, SLOT(slotWindowMinimize()));
	connect(lTitle, SIGNAL(emitWindowMaximize()), this, SLOT(slotWindowMaximize()));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(close()));
	connect(lTitle, SIGNAL(emitWindowFullScreen()), this, SLOT(slotWindowFullScreen()));

	connect(lMenu, SIGNAL(emitAddModuleMenuSelect(QString)), lWorkspace, SLOT(slotAddModuleMenuSelect(QString)));

	connect(lWorkspace, SIGNAL(emitAddModuleMenuSelect(QString)), lSection, SLOT(slotAddModuleMenuSelect(QString)));

	connect(lSection, SIGNAL(emitModuleImageAction(QString)), this, SLOT(slotModuleImageAction(QString)));

	connect(lManager, SIGNAL(emitModuleMax()), this, SLOT(slotModuleMax()));

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
	delete m_shape;
}
//===============================================
void GWindowDefault::paintEvent(QPaintEvent *event) {
	if(m_shape != 0) {
		QPainter lPainter(this);
		lPainter.drawPixmap(0, 0, *m_shape);
	}
}
//===============================================
void GWindowDefault::resizeEvent(QResizeEvent *event) {
	int lSizeGrip = 10;
	m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);

	delete m_shape;
	m_shape = new QPixmap(size());
	m_shape->fill(Qt::transparent);
	QPainter lPainter(m_shape);

	QPolygon lShape;
	lShape
	<< QPoint(0, 16)
	<< QPoint(16, 0)
	<< QPoint(width(), 0)
	<< QPoint(width(), height())
	<< QPoint(0, height());
	lPainter.setPen(Qt::NoPen);
	lPainter.setBrush(QBrush("#536d5a"));
	lPainter.drawPolygon(lShape);

	QPolygon lEdge;
	int lMargin = 2;
	lEdge
	<< QPoint(lMargin, 16)
	<< QPoint(16, lMargin)
	<< QPoint(width() - lMargin , lMargin)
	<< QPoint(width() - lMargin, height() - lMargin)
	<< QPoint(lMargin, height() - lMargin);
	lPainter.setPen(QPen(Qt::transparent));
	lPainter.setBrush(Qt::NoBrush);
	lPainter.drawPolygon(lEdge);
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
void GWindowDefault::slotModuleMax() {
	GManager::Instance()->infoModuleMax(this);
}
//===============================================
void GWindowDefault::slotModuleImageAction(QString action) {
	if(action == "IMAGE_OPEN") GImage::Instance()->open(this);
}
//===============================================
