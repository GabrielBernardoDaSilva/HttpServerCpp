#pragma once

#include <unordered_map>
#include <vector>

class QueryString
{
private:
	std::unordered_map<const char*, const char*> data{};
public:
	const std::unordered_map<const char*, const char*> getData()const {
		return data;
	}
	void createQueryString(char* bufferQueryString);

	
};

