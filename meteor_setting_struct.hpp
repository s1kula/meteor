#ifndef METEOR_SETTING_STRUCT
#define METEOR_SETTING_STRUCT

#include <cstdint>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>

struct meteorSetting{
    uint16_t port;
    std::unordered_map<std::string, uint16_t> route; 
};

#endif