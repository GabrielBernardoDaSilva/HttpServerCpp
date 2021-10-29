#include "Helpers.h"



std::vector<std::string> Helpers::split_char(char cstr[], const char* del)
{
    std::vector<std::string> splited_char{};
    const char* delimiter = del;
    char* next_token = NULL;
    char* token = strtok_s(cstr, delimiter, &next_token);
    while (token != nullptr)
    {
        splited_char.push_back(std::string(token));
        token = strtok_s(NULL, delimiter, &next_token);
    }

    
    return splited_char;
}
