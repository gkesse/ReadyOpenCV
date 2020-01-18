//===============================================
#ifndef _GStruct_
#define _GStruct_
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGModule sGModule;
typedef struct _sGModuleItem sGModuleItem;
typedef struct _sGImage sGImage;
typedef struct _sGImageItem sGImageItem;
typedef struct _sGVideo sGVideo;
typedef struct _sGVideoItem sGVideoItem;
//===============================================
struct _sGManager {
	sGModule* module;
	sGImage* image;
	sGVideo* video;
};
//===============================================
struct _sGModule{
	int index;
	int count;
	int max;
};
//===============================================
struct _sGImage {
	int index;
	int count;
	QList<sGImageItem*> list;
};
//===============================================
struct _sGVideo {
	int index;
	int count;
};
//===============================================
struct _sGImageItem {
	QString path;
	QString filename;
	QString fullname;
};
//===============================================
#endif
//===============================================
