#ifndef METEOR_HTTP_DATA 
#define METEOR_HTTP_DATA

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

struct httpData{
    uint8_t method;
    std::string path;
    uint8_t protocol;
    std::vector<std::pair<std::string, std::string>> headers;
    std::vector<std::pair<std::string, std::string>> parameters;
};

#endif