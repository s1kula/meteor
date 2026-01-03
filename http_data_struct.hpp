#ifndef METEOR_HTTP_DATA 
#define METEOR_HTTP_DATA

#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct httpData{
    uint16_t method;
    std::string path;
    uint16_t protocol;
    std::unordered_map<std::string, std::string> headers;
    std::unordered_map<std::string, std::string> parameters;
};

#endif