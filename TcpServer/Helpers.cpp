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

std::tuple<std::string, std::string> Helpers::get_next_word(std::string full_string)
{
    for (size_t i = 0; i < full_string.size(); i++) {
        if (full_string[i] == ' ' || full_string[i] == '\r')
        {
            return std::make_tuple(full_string.substr(0, i), full_string.substr(i + 1, full_string.size()));
        }
    }
    return std::make_tuple("", "");
}

Method Helpers::StringToMethod(const char* method)
{
    auto it = table.find(method);
    if (it != table.end()) {
        return it->second;
    }
    else {
        return Method::ERR;
    }
}

const char* Helpers::ParserErrorToString(ParseError err)
{
    switch (err)
    {
    case ParseError::InvalidRequest:
        return "InvalidRequest";
    case ParseError::InvalidEnconding:
        return "InvalidEnconding";
    case ParseError::InvalidProtocol:
        return "InvalidProtocol";
    case ParseError::InvalidMethod:
        return "InvalidMethod";
    default:
        return "UnknowError";
    }
}

const char* Helpers::ParserStatusCodeToString(StatusCode statusCode)
{
    switch (statusCode)
    {
    case StatusCode::Ok:
        return "Ok";
    case StatusCode::Created:
        return "Created";
    case StatusCode::NoContent:
        return "NoContent";
    case StatusCode::BadRequest:
        return "BadRequest";
    case StatusCode::Unauthorized:
        return "Unauthorized";
    case StatusCode::NotFound:
        return "NotFound";
    default:
        return "InvalidStatusCode";
    }
}
