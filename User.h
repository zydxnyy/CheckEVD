#pragma once
#include <qdebug.h>
#include <vector>
#include "config.h"
#include "DbBase.h"
using namespace std;

class User
{
public:
	static DbBase* base;

	int id;
	int user_type;
	QString name;
	QString sex;
	QString grade;
	QString major;
	int group_id;
	int student_id;
	QString campus;
	QString phone;
	QString wechat;
	QString qq;
	QString password;
	QString extra;
protected:
	static void get_user_from_query(User& user, QSqlQuery& result) {
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
	}

public:
	User();
	~User();
	bool is_valid() { return !name.isEmpty(); }

	void print() {
		qDebug() << id << user_type << name << sex << grade << major << group_id << student_id << campus << phone << wechat << qq;
	}

	static User login_by_name(const QString& name, const QString& password);
	static User login_by_sid(const int& student_id, const QString& password);
	static User query_user_by_id(int id);
	static vector<User> query_user_by_name(const char* name, int page=0);
	static vector<User> query_user_by_group(const int& group_id, int page=0);
	static int insert(const int& user_type, const QString& name, const QString& sex, const QString& grade, const QString major, int group_id, 
		const int& student_id, const QString& campus, const QString& phone, const QString& wechat, const QString& qq, const QString& password, const QString& extra);
	static int delete_by_id(const int& id);
};

