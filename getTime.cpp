//Thanks to TrungTN on Stack Overflow for the getCurrentTime function.

#define _CRT_SECURE_NO_WARNINGS

#include "getTime.h"
#include <time.h>

std::string getTime::getCurrentTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
