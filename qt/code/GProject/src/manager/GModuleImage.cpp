//===============================================
#include "GModuleImage.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GModuleImage::GModuleImage(QWidget* parent) :
GModule(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QLabel* lTitle = new QLabel("Image");
	lTitle->setObjectName("title");
	lTitle->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lTitle);

	setLayout(lMainLayout);

	setCursor(Qt::PointingHandCursor);
	setToolTip(tr("Module Image"));

	m_moduleMenu = new QMenu(this);

	QAction* lAction;

	lAction = new QAction(this);
	m_actionMap[lAction] = "OPEN_IMAGE";
	lAction->setText(tr("Ouvrir une image"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
	m_moduleMenu->addAction(lAction);

	connect(m_moduleMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotModuleMenuSelect(QAction*)));
}
//===============================================
GModuleImage::~GModuleImage() {

}
//===============================================
void GModuleImage::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		QPoint lCursorPos = QCursor::pos();
		m_moduleMenu->exec(lCursorPos);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
void GModuleImage::slotModuleMenuSelect(QAction* action) {
	QString lAction = m_actionMap[action];
	GPrint::Instance()->print(lAction);
}
//===============================================
