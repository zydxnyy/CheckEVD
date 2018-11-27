#pragma once
#include <qmainwindow.h>
#include <qmessagebox.h>
#include "ui_Login.h"
#include "User.h"
#include "NormalWnd.h"
#include "ManagerWnd.h"
#pragma execution_character_set("utf-8")

class LoginWnd: public QMainWindow
{
	Q_OBJECT
private:
	Ui::LoginWnd ui;

public:
	LoginWnd();
	~LoginWnd();
public slots:
	void login();
};

