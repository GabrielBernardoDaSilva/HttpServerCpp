#pragma once
#include <string>
#include "Request.h"
#include "Response.h"

class WebHandler
{
private:
	std::string physicalFilesPath;
	std::string readFile(std::string filePath);
public:
	WebHandler(const char* path);
	~WebHandler();
	Response handleResponse(const Request& req);
};

