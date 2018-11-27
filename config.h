#pragma once
#include <string.h>
using namespace std;
#pragma execution_character_set("utf-8")

const int USER_TYPE_CNT = 3;

enum USER_TYPE {
	NORMAL = 0,
	MANAGER,
	ADMIN
};

const string USER_TYPE_NAME[] = {
	"��ͨ�û�",
	"����Ա",
	"�߼�����"
};

const int GROUP_CNT = 3;

enum GROUP_ID {
	ALL = 0,
	WANGXUN,
	SHEYING
};

const string GROUP_NAME[] = {
	"ȫ����",
	"��Ѷ��",
	"��Ӱ��"
};

const bool CHECK_IN = false;
const bool CHECK_OUT = true;