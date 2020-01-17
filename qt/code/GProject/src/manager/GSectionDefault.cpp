//===============================================
#include "GSectionDefault.h"
#include "GModule.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GSectionDefault::GSectionDefault(QWidget* parent) :
GSection(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_scrollArea = new QScrollArea;
	m_scrollLayout = new QVBoxLayout;
	m_scrollWidget = new QWidget;

	m_scrollLayout->setMargin(0);
	m_scrollLayout->setSpacing(0);
	m_scrollLayout->setAlignment(Qt::AlignTop);

	m_scrollWidget->setLayout(m_scrollLayout);
	m_scrollWidget->installEventFilter(this);

	m_scrollArea->setWidget(m_scrollWidget);
	m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_scrollArea->setWidgetResizable(true);
	m_scrollArea->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
	m_scrollArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
	m_scrollArea->verticalScrollBar()->installEventFilter(this);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(m_scrollArea);

	setLayout(lMainLayout);

    m_timer = new QTimer(this);
    m_timer->setInterval(50);
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slotAddModuleMenuTimer()));
}
//===============================================
GSectionDefault::~GSectionDefault() {

}
//===============================================
void GSectionDefault::slotAddModuleMenuSelect(QString module) {
	GModule* lModule = GModule::Create(module);
	m_scrollLayout->addWidget(lModule);
	connect(lModule, SIGNAL(emitModuleImageAction(QString)), this, SIGNAL(emitModuleImageAction(QString)));
}
//===============================================
void GSectionDefault::slotAddModuleMenuTimer() {
	int lWidth = 0;
	lWidth += m_scrollWidget->sizeHint().width();
	if(m_scrollArea->verticalScrollBar()->isVisible() == true) {
		lWidth += m_scrollArea->verticalScrollBar()->sizeHint().width();
	}
	m_scrollArea->setMinimumWidth(lWidth);
}
//===============================================
bool GSectionDefault::eventFilter(QObject *object, QEvent *event) {
	if (event->type() == QEvent::Resize) {
		if(object == m_scrollWidget || object == m_scrollArea->verticalScrollBar()) {
			m_timer->start();
		}
	}
	return QWidget::eventFilter(object, event);
}
//===============================================
