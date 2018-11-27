#include "Util.h"

QString get_time(time_t t)
{

	return  QDateTime::fromTime_t(t).toString("MM-dd[ddd] hh:mm");
}

int get_group_id(const QString& group_name)
{
	for (int i = 0; i < GROUP_CNT; ++i) {
		if (group_name == QString::fromStdString(GROUP_NAME[i])) {
			return i;
		}
	}
	return ALL;
}

int get_user_type(const QString & user_type_name)
{
	for (int i = 0; i < USER_TYPE_CNT; ++i) {
		if (user_type_name == QString::fromStdString(USER_TYPE_NAME[i])) {
			return i;
		}
	}
	return NORMAL;
}
