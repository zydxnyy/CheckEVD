#pragma once
#include <qlistwidget.h>
#include <algorithm>
#include "Util.h"
#include "ui_item.h"

class Item: public QWidget
{
	Q_OBJECT
private:
	Ui::Item ui;

	QString name;
	QString group;
	time_t check_in_time;
	time_t check_out_time;
	time_t duration;
public:
	Item(const QString& _name, const QString& _group, time_t _check_in_time, time_t _check_out_time);
	Item(const QString& _name, const QString& _group, const QString& _check_in_time, const QString& _check_out_time, const QString& _duration);
	~Item();
};

