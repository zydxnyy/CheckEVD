#include "LoginWnd.h"



LoginWnd::LoginWnd()
{
	ui.setupUi(this);
}


LoginWnd::~LoginWnd()
{
}

void LoginWnd::login()
{
	QString name = ui.username_edit->text();
	QString password = ui.password_edit->text();
	User user = User::login_by_name(name, password);
	if (user.is_valid()) {
		if (ui.checkBox->isChecked()) {
			if (user.user_type == NORMAL) {
				QMessageBox::warning(this, "", "你不是管理员", QMessageBox::Yes);
			}
			else {
				this->close();
				ManagerWnd* manager_wnd = new ManagerWnd(user);
				manager_wnd->show();
			}
		}
		else {
			this->close();
			NormalWnd* normal_wnd = new NormalWnd(user);
			normal_wnd->show();
		}
	}
	else {
		QMessageBox::warning(this, "", "用户名或密码错误", QMessageBox::Yes);
	}
}
