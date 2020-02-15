//===============================================
#ifndef _GSerialize_
#define _GSerialize_
//===============================================
#include "GInclude.h"
//===============================================
QDataStream &operator<<(QDataStream& out, sGManager& data);
QDataStream &operator>>(QDataStream& out, sGManager* data);
QDataStream &operator<<(QDataStream& out, sGCommon& data);
QDataStream &operator>>(QDataStream& out, sGCommon* data);
QDataStream &operator<<(QDataStream& out, sGModule& data);
QDataStream &operator>>(QDataStream& out, sGModule* data);
QDataStream &operator<<(QDataStream& out, sGImage& data);
QDataStream &operator>>(QDataStream& out, sGImage* data);
QDataStream &operator<<(QDataStream& out, sGImageItem& data);
QDataStream &operator>>(QDataStream& out, sGImageItem* data);
QDataStream &operator<<(QDataStream& out, sGVideo& data);
QDataStream &operator>>(QDataStream& out, sGVideo* data);
QDataStream &operator<<(QDataStream& out, sGVideoItem& data);
QDataStream &operator>>(QDataStream& out, sGVideoItem* data);
//===============================================
#endif
//===============================================
