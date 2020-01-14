//===============================================
#ifndef _GSectionDefault_
#define _GSectionDefault_
//===============================================
#include "GSection.h"
//===============================================
class GSectionDefault : public GSection {
public:
	GSectionDefault(QWidget* parent = 0);
	~GSectionDefault();

protected:
	bool eventFilter(QObject *object, QEvent *event);

public slots:
	void slotAddModuleMenuSelect(QString module);
	void slotAddModuleMenuTimer();

private:
	QScrollArea* m_scrollArea;
	QWidget* m_scrollWidget;
	QVBoxLayout* m_scrollLayout;
	QTimer* m_timer;
};
//===============================================
#endif
//===============================================
