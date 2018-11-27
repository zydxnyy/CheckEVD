#pragma once
#include <fstream>
#include <qfile.h>
#include <qtextstream.h>
#include "config.h"
#include "Util.h"
#include "DBUtil.h"
#pragma execution_character_set("utf-8")

class IOFile
{
public:
	IOFile();
	~IOFile();

	static int WriteFile(const vector<pair<User, Check>>& vp, const QString& outpath);
};

