#pragma once
#include <qlistwidget.h>
#include <qfiledialog.h>
#include <qdatetime.h>
#include "ui_ManagerWnd.h"
#include "config.h"
#include "Util.h"
#include "Item.h"
#include "DBUtil.h"
#include "User.h"
#include "AddUser.h"
#include "IOFile.h"
#pragma execution_character_set("utf-8")

class ManagerWnd: public QMainWindow
{
	Q_OBJECT
private:
	Ui::ManagerWnd ui;

	User user;
	int total_page, cur_page;

	void fill();
public:
	ManagerWnd(User user);
	~ManagerWnd();

public slots:
	void refill();
	void pre();
	void next();
	void add_user();
	void export_to();
};

