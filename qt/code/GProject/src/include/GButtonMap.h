//===============================================
#ifndef _GButtonMap_
#define _GButtonMap_
//===============================================
#include "GInclude.h"
//===============================================
class GButtonMap : public QFrame {
	Q_OBJECT

public:
	GButtonMap(QWidget* parent = 0);
	virtual ~GButtonMap();
	static GButtonMap* Create(QString key);

signals:
	void emitWindowAccept();
	void emitWindowReject();

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
