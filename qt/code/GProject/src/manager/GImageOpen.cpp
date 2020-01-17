//===============================================
#include "GImageOpen.h"
//===============================================
GImageOpen::GImageOpen(QWidget* parent) :
QDialog(parent) {
	setObjectName("GDialog");

	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QFrame* lFilenameFrame = new QFrame;
	lFilenameFrame->setObjectName("GRow");
	QHBoxLayout* lFilenameLayout = new QHBoxLayout;
	QLabel* lFilenameLabel = new QLabel(tr("Chemin:"));
	lFilenameLabel->setObjectName("GLabel2");
	m_filenameEdit = new QLineEdit;
	m_filenameEdit->setObjectName("GLineEdit");
	lFilenameLayout->setMargin(0);
	lFilenameLayout->setSpacing(0);
	lFilenameLayout->setAlignment(Qt::AlignTop);
	lFilenameLayout->addWidget(lFilenameLabel);
	lFilenameLayout->addWidget(m_filenameEdit, 1);
	lFilenameFrame->setLayout(lFilenameLayout);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lFilenameFrame);

	setLayout(lMainLayout);

	resize(300, 150);
}
//===============================================
GImageOpen::~GImageOpen() {

}
//===============================================
