#include "Method.h"
#include "QueryString.h"
#include <string>
#include <iostream>
#pragma once

class Request
{
private:
	std::string path;
	QueryString* queryString;
	Method method;
public:
	Request();
	~Request();
	std::string getPath() const { return path; }
	const QueryString getQueryString() const { return *queryString; }
	const Method getMethod() const { return method; }

	void CreateRequest(const char* buffer);
};

