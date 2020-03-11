//===============================================
#include "GDialogImageConvert.h"
#include "GTitle.h"
#include "GButtonMap.h"
#include "GRow.h"
#include "GDebug.h"
//===============================================
GDialogImageConvert::GDialogImageConvert(QWidget* parent) :
GDialog(parent) {
	__CLASSNAME__ = __FUNCTION__;
	GTitle* lTitle = GTitle::Create("DIALOG");
	m_convertType = GRow::Create("COMBOBOX");
	m_convertType->setTextLabel(tr("Type de conversion :"));
	m_convertType->clearComboBox();
	m_convertType->addDataComboBox(tr("Sélectionner un type"));
	QStringList lNameList = GEnum::Instance()->getConvertNameList();
	m_convertType->addDataComboBox(lNameList);
	GButtonMap* lButtonMap = GButtonMap::Create("OK_CANCEL");

	m_frameLayout->addWidget(lTitle);
	m_frameLayout->addWidget(m_convertType);
	m_buttonMapLayout->addWidget(lButtonMap);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setSizeGripEnabled(true);

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(reject()));
	connect(lButtonMap, SIGNAL(emitWindowAccept()), this, SLOT(accept()));
	connect(lButtonMap, SIGNAL(emitWindowReject()), this, SLOT(reject()));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));

	setWindowTitle(tr("Choisir le type de conversion | ReadyDev"));
	if(parent != 0) setWindowIcon(parent->windowIcon());
}
//===============================================
GDialogImageConvert::~GDialogImageConvert() {

}
//===============================================
