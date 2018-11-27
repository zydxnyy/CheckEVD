#include "ManagerWnd.h"


void ManagerWnd::fill()
{
	ui.listWidget->clear();
	{
		Item* item = new Item("����", "����", "ǩ��ʱ��", "ǩ��ʱ��", "ʱ��");
		QListWidgetItem* p = new QListWidgetItem();
		p->setSizeHint(QSize(750, 40));
		ui.listWidget->addItem(p);
		ui.listWidget->setItemWidget(p, item);
	}
	time_t start_time = ui.start_time->dateTime().toTime_t();
	time_t end_time = ui.end_time->dateTime().toTime_t();
	vector<pair<User, Check>> v = query_user_join_check(get_group_id(ui.group->currentText()), ui.name->text(), start_time, end_time, total_page, cur_page);
	for (auto pr : v) {
		User& user = pr.first;
		Check& check = pr.second;
		Item* item = new Item(user.name, QString::fromStdString(GROUP_NAME[user.group_id]), check.check_in_time, check.check_out_time);
		QListWidgetItem* p = new QListWidgetItem();
		p->setSizeHint(QSize(750, 40));
		ui.listWidget->addItem(p);
		ui.listWidget->setItemWidget(p, item);
	}
	ui.label_4->setText(QString().sprintf("%d/%d", cur_page, total_page));
}

ManagerWnd::ManagerWnd(User user)
{
	ui.setupUi(this);
	this->user = std::move(user);
	if (user.user_type == ADMIN) {
		for (int i = 0; i < GROUP_CNT; ++i) {
			ui.group->addItem(GROUP_NAME[i].c_str());
		}
	}
	else if (user.user_type == MANAGER){
		ui.group->addItem(GROUP_NAME[user.group_id].c_str());
	}
	ui.end_time->setDate(QDate::currentDate().addDays(1));
	cur_page = 1;
	fill();
}

void ManagerWnd::refill() {
	cur_page = 1;
	fill();
}


void ManagerWnd::pre() {
	if (cur_page <= 1) {

	}
	else {
		cur_page -= 1;
		fill();
	}
}

void ManagerWnd::next() {
	if (cur_page >= total_page) {

	}
	else {
		cur_page += 1;
		fill();
	}
}


void ManagerWnd::add_user()
{
	if (user.user_type != ADMIN) {
		QMessageBox::warning(this, "", "�㲻�Ǹ߼�����Ա��û��Ȩ������û�", QMessageBox::Yes);
	}
	else {
		AddUser* addUser = new AddUser();
		addUser->show();
	}
}

void ManagerWnd::export_to()
{
	QString path = QFileDialog::getSaveFileName(this, "ѡ�񵼳��ļ��ı���λ��", "", "*.csv");
	if (path.isEmpty()) {
		return;
	}
	qDebug() << path;
	int t_p;
	auto result_set = query_user_join_check(ALL, "", 0, 0, t_p);
	int ret = IOFile::WriteFile(result_set, path);
	if (ret) {
		QMessageBox::information(this, "", "�ļ������ɹ�", QMessageBox::Yes);
	}
	else {
		QMessageBox::warning(this, "", "�ļ�����ʧ�ܣ�������", QMessageBox::Yes);
	}
}

ManagerWnd::~ManagerWnd()
{

}
