#pragma once
#include <iostream>
#include <qstring.h>
#include <time.h>
#include <qdatetime.h>
#include "config.h"
#pragma execution_character_set("utf-8")

QString get_time(time_t time);

int get_group_id(const QString& group_name);

int get_user_type(const QString& user_type_name);