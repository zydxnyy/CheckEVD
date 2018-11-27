#include "IOFile.h"



IOFile::IOFile()
{
}


IOFile::~IOFile()
{
}

int IOFile::WriteFile(const vector<pair<User, Check>>& vp, const QString & outpath)
{
	QFile qfile(outpath);
	if (!qfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		qWarning() << "Error: write to:" << outpath << qfile.errorString();
		return 0;
	}
	QTextStream out(&qfile);
	out.setCodec("GBK");
	{
		QString line = "部门,日期,工作日,签到时间,签退时间,名字\n";
		out << line;
	}
	for (auto pr : vp) {
		User& user = pr.first;
		Check& check = pr.second;
		QDateTime check_in_time = QDateTime::fromTime_t(check.check_in_time);
		QDateTime check_out_time = QDateTime::fromTime_t(check.check_out_time);
		QString line = QString::fromStdString(GROUP_NAME[user.group_id]) + check_in_time.toString(",MM-dd,ddd,hh:mm") + check_out_time.toString(",hh:mm,") + user.name + "\n";
		out << line;
	}
	qfile.flush();
	qfile.close();
	qDebug() << "Info: write to:" << outpath;
	return 1;
}
