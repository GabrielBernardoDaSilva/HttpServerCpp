#pragma once

#include <unordered_map>
#include <vector>

class QueryString
{
private:
	std::unordered_map<std::string, std::string> data{};
public:
	const std::unordered_map<std::string, std::string>& getData() const {
		return data;
	}
	QueryString(std::string bufferQueryString);
	~QueryString();
	void createQueryString(std::string);

	
};

