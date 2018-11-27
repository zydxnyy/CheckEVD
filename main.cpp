#include <QtWidgets/QApplication>
#include <qapplication.h>
#include <qlogging.h>
#include <vector>
#include <qdir.h>
#include <qpluginloader.h>
#include "config.h"
#include "User.h"
#include "Check.h"
#include "DBUtil.h"
#include "LoginWnd.h"
#include "Log.h"
#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	//qInstallMessageHandler(logger);

	//User::insert(ADMIN, "ADMIN", "男", "大四", "**", WANGXUN, 1111111, "南校", "", "", "", "ADMIN", "");

	LoginWnd loginwnd;
	loginwnd.show();

	return a.exec();
}
