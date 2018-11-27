#pragma once
#include <vector>
#include "config.h"
#include "DbBase.h"

class Check
{
public:
	static DbBase* base;

	int id;
	int user_id;
	time_t check_in_time;
	time_t check_out_time;
protected:
	bool is_checkined() {
		return check_in_time != 0;
	}
	bool is_checkouted() {
		return check_out_time != 0;
	}

	static void get_check_from_query(Check& check, QSqlQuery& result) {
		check.id = result.value(0).toInt();
		check.user_id = result.value(1).toInt();
		check.check_in_time = result.value(2).toLongLong();
		check.check_out_time = result.value(3).toLongLong();
	}

	static Check query_user_last_check(int user_id);

public:
	Check();
	~Check();

	void print() {
		qDebug() << id << user_id << check_in_time << check_out_time;
	}

	static vector<Check> query_by_user_id(int user_id, int page=0);
	static int check_in(int user_id);
	static int check_out(int user_id);
};

