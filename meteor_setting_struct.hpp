#ifndef METEOR_SETTING_STRUCT
#define METEOR_SETTING_STRUCT

#include <cstdint>
#include <vector>
#include <utility>
#include <string>

struct meteorSetting{
    uint16_t port;
    std::vector<std::pair<uint16_t, std::string>> route; 
};

#endif