#include "NormalWnd.h"



NormalWnd::NormalWnd(User& user)
{
	ui.setupUi(this);
	state = CHECK_IN;
	this->user = std::move(user);
	if (user.user_type == NORMAL) {
		ui.pushButton_2->hide();
	}
	else {
	}
}


NormalWnd::~NormalWnd()
{
}

void NormalWnd::check()
{
	if (state == CHECK_IN) {
		if (Check::check_in(user.id)) {
			QMessageBox::information(this, "", "ǩ���ɹ�������رմ˳���", QMessageBox::Yes);
			state = CHECK_OUT;
			ui.pushButton->setText("ǩ��");
		}
		else {
			QMessageBox::warning(this, "", "ǩ��ʧ�ܣ�������", QMessageBox::Yes);
		}
	}
	else if (state == CHECK_OUT) {
		if (Check::check_out(user.id)) {
			QMessageBox::information(this, "", "ǩ�˳ɹ�", QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(this, "", "ǩ��ʧ�ܣ�������", QMessageBox::Yes);
		}
	}
}


void NormalWnd::manage() {
	if (user.user_type == NORMAL) {

	}
	else {
		ManagerWnd* manager_wnd = new ManagerWnd(user);
		manager_wnd->show();
	}
}