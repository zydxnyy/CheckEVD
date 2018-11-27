#pragma once
#include <qpair.h>
#include <vector>
#include "config.h"
#include "User.h"
#include "Check.h"

void get_user_check_from_query(User& user, Check& check, QSqlQuery& result);

vector<pair<User, Check>> query_user_join_check(int group_id, const QString& name, time_t start_time, time_t end_time, int& total_page, int page=0);


