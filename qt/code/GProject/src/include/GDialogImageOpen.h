//===============================================
#ifndef _GDialogImageOpen_
#define _GDialogImageOpen_
//===============================================
#include "GDialog.h"
//===============================================
class GDialogImageOpen : public GDialog {
public:
	GDialogImageOpen(QWidget* parent = 0);
	~GDialogImageOpen();

public slots:
	void slotWindowPress(QPoint position);
	void slotWindowMove(QPoint position);

private:
	QPoint m_pressPosition;
};
//===============================================
#endif
//===============================================
