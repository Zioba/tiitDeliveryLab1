#pragma once
#ifndef _STRING_HELP_FILE_INCLUDED_
#define _STRING_HELP_FILE_INCLUDED_

#include <string>

inline int ToInt(const std::string& str)
{
	return atoi(str.c_str());
}

#endif