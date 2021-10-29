#include "QueryString.h"
#include "Helpers.h"

QueryString::QueryString(std::string bufferQueryString)
{
	createQueryString(bufferQueryString);
}

QueryString::~QueryString()
{
}

void QueryString::createQueryString(std::string bufferQueryString)
{

	const auto queries = Helpers::split_char((char*)bufferQueryString.c_str(), "&");
	for (auto query : queries)
	{
		std::string key = "";
		std::string value = "";

		auto pos = query.find_first_of("=");
		if (pos != std::string::npos) {
			key = query.substr(0, pos);
			value = query.substr(pos + 1, query.size());
			data.insert(std::make_pair(key, query));
		}
	}
}
