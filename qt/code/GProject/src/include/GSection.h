//===============================================
#ifndef _GSection_
#define _GSection_
//===============================================
#include "GInclude.h"
#include "GModule.h"
//===============================================
class GSection : public QFrame {
	Q_OBJECT

public:
	GSection(QWidget* parent = 0);
	virtual ~GSection();
	static GSection* Create(QString key);

protected:
	bool eventFilter(QObject *object, QEvent *event);

public slots:
	virtual void slotAddModuleMenuSelect(QString module, int index);
	virtual void slotAddModuleMenuTimer();
	virtual void slotModuleCurrent(GModule* module);

signals:
	void emitModuleMenuAction(QString action);
	void emitModuleCurrent(int index);

protected:
	QScrollArea* m_scrollArea;
	QWidget* m_scrollWidget;
	QVBoxLayout* m_scrollLayout;
	QList<GModule*> m_moduleMap;
	QTimer* m_timer;
};
//===============================================
#endif
//===============================================
