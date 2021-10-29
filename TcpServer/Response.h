#pragma once

#include<string>
#include "StatusCode.h"

class Response
{
private:
	StatusCode statusCode;
	std::string body;
public:
	Response(StatusCode status, std::string newBody);
	~Response();
	std::string getBody() { return body; }
	std::string send();
};

