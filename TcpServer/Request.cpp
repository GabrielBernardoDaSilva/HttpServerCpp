#include "Request.h"
#include "Helpers.h"
#include "Method.h"
#include "ParseError.h"

Request::Request()
{
	path = "asd";
	queryString = nullptr;
	
}

Request::~Request()
{
	delete queryString;
}

void Request::CreateRequest(const char* buffer)
{
	std::string localMethod, path, protocol, req;
	std::string request(buffer);
	std::tie(localMethod, req) = Helpers::get_next_word(request.c_str());
	std::tie(path, req) = Helpers::get_next_word(req.c_str());
	std::tie(protocol, req) = Helpers::get_next_word(req.c_str());

	if (protocol != "HTTP/1.1")
	{
		std::cout << "Protocol error: " << Helpers::ParserErrorToString(ParseError::InvalidProtocol) << std::endl;
		return;
	}

	method = Helpers::StringToMethod(localMethod.c_str());
	if (method == Method::ERR)
	{
		std::cout << "Invalid method error: " << Helpers::ParserErrorToString(ParseError::InvalidMethod) << std::endl;
	}

	if (int i = path.find_first_of("?"); i != std::string::npos) {
		queryString = new QueryString(path.substr(i + 1, path.size()));
		
	}

}
