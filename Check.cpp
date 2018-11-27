#include "Check.h"

DbBase* Check::base = DbBase::getInstance();

Check::Check()
{
}


Check::~Check()
{
}

vector<Check> Check::query_by_user_id(int user_id, int page)
{
	vector<Check> vcheck;
	QString statement;
	if (page != 0) statement = QString("select * from checks where user_id = %1 order by check_in_time limit 10 offset %2;").arg(user_id).arg(10 * (page - 1));
	else statement = QString("select * from checks where user_id = %1 order by check_in_time;").arg(user_id);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		do {
			Check check;
			get_check_from_query(check, result);
			vcheck.emplace_back(check);
		} while (result.next());
	}
	else {
		qDebug() << "Error: Query check by user id;";
	}
	return std::move(vcheck);
}

Check Check::query_user_last_check(int user_id)
{
	Check check;
	QString statement = QString("select * from checks where id = (select max(id) from checks where user_id = %1);").arg(user_id);
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		get_check_from_query(check, result);
	}
	else {
		qDebug() << "Error: query check user last check.";
	}
	return check;
}

int Check::check_in(int user_id)
{
	QString statement = QString("insert into checks (user_id, check_in_time) values (%1, %2);")
		.arg(user_id).arg(time(nullptr));
	return base->exec(statement);
}

int Check::check_out(int user_id)
{
	Check lastCheck = std::move(query_user_last_check(user_id));
	if (lastCheck.is_checkouted() || !lastCheck.is_checkined()) {
		check_in(user_id);
		lastCheck = std::move(query_user_last_check(user_id));
	}
	lastCheck.check_out_time = time(nullptr);
	QString statement = QString("update checks set check_out_time = %1 where id = %2;").arg(time(nullptr)).arg(lastCheck.id);
	return base->exec(statement);
}
