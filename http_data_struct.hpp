#ifndef METEOR_HTTP_DATA 
#define METEOR_HTTP_DATA

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

struct httpData{
    uint16_t method;
    std::string path;
    uint16_t protocol;
    std::vector<std::pair<std::string, std::string>> headers;
    std::vector<std::pair<std::string, std::string>> parameters;
};

#endif