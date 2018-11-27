#pragma once
#include <qmainwindow.h>
#include <qmessagebox.h>
#include "ui_NormalWnd.h"
#include "ManagerWnd.h"
#include "config.h"
#include "User.h"
#include "Check.h"
#pragma execution_character_set("utf-8")

class NormalWnd: public QMainWindow
{
	Q_OBJECT
private:
	Ui::NormalWnd ui;
	bool state;
	User user;

public:
	NormalWnd(User& user);
	~NormalWnd();
public slots:
	void check();
	void manage();
};

