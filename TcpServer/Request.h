#pragma once
#include "Method.h"
class Request
{
private:
	const char* path;
	const char* queryString;
	const Method method;
public:

	const char* getPath() const { return path; }
	const char* getQueryString() const { return queryString; }
	const Method getMethod() const { return method; }

	void CreateRequest(const char* buffer);
};

