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
				QMessageBox::warning(this, "", "�㲻�ǹ���Ա", QMessageBox::Yes);
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
		QMessageBox::warning(this, "", "�û������������", QMessageBox::Yes);
	}
}
