#pragma once
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <qdebug.h>
#include <qlogging.h>

class DbBase
{
private:
	QSqlDatabase database;
	static DbBase* base;
	DbBase();
public:
	static DbBase* getInstance() { return base; }

	~DbBase();

	void init();

	QSqlQuery query(const QString& statement);
	int exec(const QString& statement);
};

