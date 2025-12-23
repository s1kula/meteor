#ifndef METEOR_SETTING_PARSER
#define METEOR_SETTING_PARSER

#include <cstdint>
#include <nlohmann/json.hpp>
#include <fstream>

struct meteorSetting{
    uint16_t port;
    std::vector<std::pair<std::string, std::string>> route; 
};

meteorSetting setting_parser(const std::string& settingPath){
    meteorSetting resultSetting;

}

#endif