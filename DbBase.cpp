#include "DbBase.h"

DbBase* DbBase::base = new DbBase();

DbBase::DbBase(): database(QSqlDatabase::addDatabase("QSQLITE"))
{
	database.setUserName("xuanchuanbu");
	database.setPassword("/*-xcb123");
	database.setDatabaseName("checkEVD.db");

	if (!database.open())
	{
		qDebug(QString("Error: Failed to connect database." + database.lastError().text()).toStdString().c_str());
	}
	else
	{
		// do something
	}

	//init();
}


void DbBase::init() {
	QSqlQuery sql_query;
	QString create_user_sql =
		"create table user (\
			id integer primary key AUTOINCREMENT ,\
			user_type integer default 1,\
			name varchar(30),\
			sex varchar(10) default '',\
			grade varchar(30) default '',\
			major varchar(100) default '',\
			group_id integer default 1,\
			student_id unsigned int unique,\
			campus varchar(10) default '',\
			phone varchar(20) default '',\
			wechat varchar(50) default '',\
			qq	varchar(20) default '',\
			password varchar(100),\
			extra text\
		);";
	QString create_check_sql =
		"create table checks (\
			id integer primary key AUTOINCREMENT , \
			user_id int,\
			check_in_time bigint(64) default 0,\
			check_out_time bigint(64) default 0\
		);";
	if (!sql_query.exec(create_user_sql))
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table user created!";
	}
	if (!sql_query.exec(create_check_sql))
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table checks created!";
	}
}

QSqlQuery DbBase::query(const QString& statement) {
	QSqlQuery sql_query;
	sql_query.prepare(statement);
	if (!sql_query.exec()) {
		qCritical() << "Error: failed to query." << sql_query.lastError();
	}
	return std::move(sql_query);
}

int DbBase::exec(const QString & statement)
{
	QSqlQuery sql_query;
	sql_query.prepare(statement);
	if (!sql_query.exec()) {
		qCritical() << "Error: failed to query." << sql_query.lastError();
		return 0;
	}
	return 1;
}


DbBase::~DbBase()
{
}
