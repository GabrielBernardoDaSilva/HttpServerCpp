#include "QueryString.h"
#include "Helpers.h"

void QueryString::createQueryString(char* bufferQueryString)
{

	const auto queries = Helpers::split_char((char*)bufferQueryString, "&");
	for (auto query : queries)
	{
		std::string key = "";
		std::string value = "";

		auto pos = query.find_first_of("=");
		if (pos != std::string::npos) {
			key = query.substr(0, pos);
			value = query.substr(pos, query.size());
			data.insert(std::make_pair(key.c_str(), query.c_str()));
		}
	}
}
