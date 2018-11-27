#include "DBUtil.h"

void get_user_check_from_query(User & user, Check & check, QSqlQuery & result)
{
	user.id = result.value(0).toInt();
	user.user_type = result.value(1).toInt();
	user.name = result.value(2).toString();
	user.sex = result.value(3).toString();
	user.grade = result.value(4).toString();
	user.major = result.value(5).toString();
	user.group_id = result.value(6).toInt();
	user.student_id = result.value(7).toInt();
	user.campus = result.value(8).toString();
	user.phone = result.value(9).toString();
	user.wechat = result.value(10).toString();
	user.qq = result.value(11).toString();
	user.extra = result.value(13).toString();

	check.id = result.value(14).toInt();
	check.user_id = result.value(15).toInt();
	check.check_in_time = result.value(16).toLongLong();
	check.check_out_time = result.value(17).toLongLong();
}

vector<pair<User, Check>> query_user_join_check(int group_id, const QString& name, time_t start_time, time_t end_time, int& total_page, int page)
{
	vector<pair<User, Check>> rtn;
	DbBase* base = DbBase::getInstance();
	QString select_sm = QString("select * from user inner join checks on user.id = checks.user_id ");
	QString count_sm = QString("select count(*) from user inner join checks on user.id = checks.user_id ");
	QString where_sm = QString("where True ");
	if (group_id) where_sm += QString("and user.group_id = %1 ").arg(group_id);
	if (!name.isEmpty()) where_sm += QString("and user.name like '%%1%' ").arg(name);
	if (start_time) where_sm += QString("and checks.check_in_time >= %1 ").arg(start_time);
	if (end_time) where_sm += QString("and checks.check_in_time <= %1 ").arg(end_time);
	QString order_sm = QString(" order by checks.check_in_time ");
	QString page_sm;
	if (page) page_sm = QString("limit 10 offset %1;").arg(10 * (page - 1));
	QString statement = count_sm + where_sm;
	QSqlQuery result = base->query(statement);
	if (result.next()) {
		total_page = (result.value(0).toInt() - 1) / 10 + 1;
	}
	statement = select_sm + where_sm + order_sm + page_sm;
	qDebug() << statement;
	result = base->query(statement);
	while (result.next()) {
		User user; Check check;
		get_user_check_from_query(user, check, result);
		std::pair<User, Check> p(std::move(user), std::move(check));
		rtn.emplace_back(std::move(p));
	}
	return std::move(rtn);
}
