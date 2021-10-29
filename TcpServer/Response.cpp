#include "Response.h"
#include <sstream>
#include "Helpers.h"

Response::Response(StatusCode status, std::string newBody): statusCode(status), body(newBody)
{
	
}

Response::~Response()
{
}

std::string Response::send()
{
	std::ostringstream oss{};
	oss << "HTTP/1.1 ";
	oss << (int)statusCode;
	oss << " ";
	oss << Helpers::ParserStatusCodeToString(statusCode);
	oss << "\r\n\r\n";
	oss << (StatusCode::Ok == statusCode ?  body : "");
	

	return oss.str();
}
