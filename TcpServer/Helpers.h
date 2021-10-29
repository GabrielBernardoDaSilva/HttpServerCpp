#pragma once

#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include "Method.h"
#include "ParseError.h"

class Helpers
{
public:
	static std::vector<std::string> split_char(char cstr[], const char* del="");
	static std::tuple<std::string, std::string> get_next_word(std::string full_string);
	static Method StringToMethod(const char* method);
	static const char* ParserErrorToString(ParseError err);
};

