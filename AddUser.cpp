#include "AddUser.h"


AddUser::AddUser()
{
	ui.setupUi(this);

	for (int i = 1; i < GROUP_CNT; ++i) {
		ui.group->addItem(GROUP_NAME[i].c_str());
	}

	for (int i = 0; i < USER_TYPE_CNT - 1; ++i) {
		ui.user_type->addItem(USER_TYPE_NAME[i].c_str());
	}
}


AddUser::~AddUser()
{
}


void AddUser::add_user()
{
	bool flag = false;
	if (ui.name->text().isEmpty()) flag = true;
	if (ui.student_id->text().isEmpty()) flag = true;
	if (ui.password->text().isEmpty()) flag = true;
	if (flag) {
		QMessageBox::warning(this, "", "带星号的项目必须填写", QMessageBox::Yes);
	}
	else {
		int user_type = get_user_type(ui.user_type->currentText());
		QString name = ui.name->text();
		int student_id = ui.student_id->text().toInt();
		int group_id = get_group_id(ui.group->currentText());
		QString password = ui.password->text();
		QString sex = ui.sex->currentText();
		QString grade = ui.grade->currentText();
		QString major = ui.major->text();
		QString campus = ui.campus->text();
		QString phone = ui.phone->text();
		QString wechat = ui.wechat->text();
		QString qq = ui.qq->text();
		QString extra = ui.extra->toPlainText();
		if (User::insert(user_type, name, sex, grade, major, group_id, student_id, campus, phone, wechat, qq, password, extra)) {
			QMessageBox::information(this, "", "用户添加成功", QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(this, "", "添加失败，请重试", QMessageBox::Yes);
		}
	}
}
