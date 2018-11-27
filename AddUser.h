#pragma once
#include <qwidget.h>
#include <qmessagebox.h>
#include "User.h"
#include "config.h"
#include "Util.h"
#include "ui_AddUser.h"

class AddUser: public QWidget
{
	Q_OBJECT
private:
	Ui::AddUser ui;
public:
	AddUser();
	~AddUser();

public slots:
	void add_user();
};

