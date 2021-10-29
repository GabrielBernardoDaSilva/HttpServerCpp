#include "Method.h"
#include "QueryString.h"
#include <string>
#include <iostream>
#pragma once

class Request
{
private:
	const char* path;
	QueryString* queryString;
	Method method;
public:
	Request();
	~Request();
	const char* getPath() const { return path; }
	const QueryString getQueryString() const { return *queryString; }
	const Method getMethod() const { return method; }

	void CreateRequest(const char* buffer);
};

