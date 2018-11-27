#include "User.h"

DbBase* User::base = DbBase::getInstance();

User::User()
{
}


User::~User()
{
}

User User::login_by_name(const QString & name, const QString & password)
{
	User user;
	QString statement = QString("select * from user where name = '%1' and password = '%2';").arg(name).arg(password);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		get_user_from_query(user, result);
	}
	else {
		qDebug() << "Error: login by name";
	}
	return std::move(user);
}

User User::login_by_sid(const int & student_id, const QString& password)
{
	User user;
	QString statement = QString("select * from user where student_id = %1 and password = '%2';").arg(student_id).arg(password);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		get_user_from_query(user, result);
	}
	else {
		qDebug() << "Error: login by name";
	}
	return std::move(user);
}

User User::query_user_by_id(int id)
{
	User user;
	QString statement = QString("select * from user where id = %1;").arg(id);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		get_user_from_query(user, result);
	}
	else {
		qDebug() << "Error: Query User by Id";
	}
	return std::move(user);
}

vector<User> User::query_user_by_name(const char * name, int page)
{
	vector<User> vuser;
	QString statement;
	if (page) statement = QString("select * from user where name like '%%1%' limit 10 offset %2;").arg(name).arg(10*(page-1));
	else statement = QString("select * from user where name like '%%1%';").arg(name);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		do {
			User user;
			get_user_from_query(user, result);
			vuser.emplace_back(user);
		} while (result.next());
	}
	else {
		qDebug() << "Error: Query User by Name";
	}
	return std::move(vuser);
}

vector<User> User::query_user_by_group(const int & group_id, int page)
{
	vector<User> vuser;
	QString statement;
	if (page) statement = QString("select * from user where group_id = %1 limit 10 offset %2;").arg(group_id).arg(10 * (page - 1));
	else statement = QString("select * from user where group_id = %1;").arg(group_id);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		do {
			User user;
			get_user_from_query(user, result);
			vuser.emplace_back(user);
		} while (result.next());
	}
	else {
		qDebug() << "Error: Query User by group";
	}
	return std::move(vuser);
}

int User::insert(const int& user_type, const QString& name, const QString& sex, const QString& grade, const QString major, int group_id,
	const int& student_id, const QString& campus, const QString& phone, const QString& wechat, const QString& qq, const QString& password, const QString& extra) 
{
	QString statement = QString("insert into user (user_type, name, sex, grade, major, group_id, student_id, campus, phone, wechat, qq, password, extra)\
		 values(%1, '%2', '%3', '%4', '%5', %6, %7, '%8', '%9', '%10', '%11', '%12', '%13');")
		.arg(user_type).arg(name).arg(sex).arg(grade).arg(major).arg(group_id)
		.arg(student_id).arg(campus).arg(phone).arg(wechat).arg(qq).arg(password).arg(extra);
	return base->exec(statement);
}

int User::delete_by_id(const int & id)
{
	QString statement = QString("delete * from user where id = %1;").arg(id);

	return base->exec(statement);
}
