#pragma once
#include <qapplication.h>
#include <qmutex.h>
#include <qdatetime.h>
#include <qfile.h>
#include <qtextstream.h>

void logger(QtMsgType type, const QMessageLogContext &context, const QString &msg);
