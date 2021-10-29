#pragma once
#include <unordered_map>



enum class Method
{
    GET,
    POST,
    PUT,
    DEL,
    HEAD,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH,
    ERR
};

std::unordered_map<std::string, Method> const table = {
    {"GET", Method::GET},
    {"POST", Method::POST},
    {"PUT", Method::PUT},
    {"DEL", Method::DEL},
    {"HEAD", Method::HEAD},
    {"CONNECT", Method::CONNECT},
    {"OPTIONS", Method::OPTIONS},
    {"PATCH", Method::PATCH},
};


