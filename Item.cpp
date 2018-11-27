#include "Item.h"



Item::Item(const QString& _name, const QString& _group, time_t _check_in_time, time_t _check_out_time)
{
	ui.setupUi(this);
	name = _name;
	group = _group;
	check_in_time = _check_in_time;
	check_out_time = _check_out_time;
	duration = std::max(0LL, check_out_time - check_in_time);
	ui.name->setText(name);
	ui.group->setText(group);
	if (check_in_time) ui.check_in_time->setText(get_time(check_in_time));
	if (check_out_time) ui.check_out_time->setText(get_time(check_out_time));
	int hour = duration / 3600; duration %= 3600;
	int min = duration / 60;
	ui.duration->setText(QString().sprintf("%02d:%02d", hour, min));
}


Item::Item(const QString& _name, const QString& _group, const QString& _check_in_time, const QString& _check_out_time, const QString& _duration) 
{
	ui.setupUi(this);
	ui.name->setText(_name);
	ui.group->setText(_group);
	ui.check_in_time->setText(_check_in_time);
	ui.check_out_time->setText(_check_out_time);
	ui.duration->setText(_duration);
}


Item::~Item()
{
}
