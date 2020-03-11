//===============================================
#include "GSerialize.h"
#include "GDebug.h"
//===============================================
QDataStream &operator<<(QDataStream& out, sGManager& data) {
	out << *(data.commun);
	out << *(data.module);
	//out << *(data.image);
	//out << *(data.video);
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGManager* data) {
	in >> data->commun;
	in >> data->module;
	//in >> data->image;
	//in >> data->video;
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGCommon& data) {
	out << data.setting_path;
	out << data.current_path;
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGCommon* data) {
	in >> data->setting_path;
	in >> data->current_path;
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGModule& data) {
	//out << data.count;
	//out << data.index;
	out << data.max;
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGModule* data) {
	//in >> data->count;
	//in >> data->index;
	in >> data->max;
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGImage& data) {
	out << data.count;
	for(int i = 0; i < data.count; i++) {
		sGImageItem* lImageItem = data.list.at(i);
		out << *lImageItem;
	}
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGImage* data) {
	in >> data->count;
	for(int i = 0; i < data->count; i++) {
		sGImageItem* lImageItem = new sGImageItem;
		in >> lImageItem;
		data->list.append(lImageItem);
	}
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGImageItem& data) {
	out << data.index;
	out << data.filename;
	out << data.fullname;
	out << data.path;
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGImageItem* data) {
	in >> data->index;
	in >> data->filename;
	in >> data->fullname;
	in >> data->path;
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGVideo& data) {
	out << data.count;
	for(int i = 0; i < data.count; i++) {
		sGVideoItem* lVideoItem = data.list.at(i);
		out << *lVideoItem;
	}
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGVideo* data) {
	in >> data->count;
	for(int i = 0; i < data->count; i++) {
		sGVideoItem* lVideoItem = new sGVideoItem;
		in >> lVideoItem;
		data->list.append(lVideoItem);
	}
	return in;
}
//===============================================
QDataStream &operator<<(QDataStream& out, sGVideoItem& data) {
	out << data.filename;
	out << data.fullname;
	out << data.path;
	return out;
}
//===============================================
QDataStream &operator>>(QDataStream& in, sGVideoItem* data) {
	in >> data->filename;
	in >> data->fullname;
	in >> data->path;
	return in;
}
//===============================================
