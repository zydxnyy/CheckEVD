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
			QMessageBox::information(this, "", "Ç©µ½³É¹¦£¬ÇëÎð¹Ø±Õ´Ë³ÌÐò", QMessageBox::Yes);
			state = CHECK_OUT;
			ui.pushButton->setText("Ç©ÍË");
		}
		else {
			QMessageBox::warning(this, "", "Ç©µ½Ê§°Ü£¬ÇëÖØÊÔ", QMessageBox::Yes);
		}
	}
	else if (state == CHECK_OUT) {
		if (Check::check_out(user.id)) {
			QMessageBox::information(this, "", "Ç©ÍË³É¹¦", QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(this, "", "Ç©ÍËÊ§°Ü£¬ÇëÖØÊÔ", QMessageBox::Yes);
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