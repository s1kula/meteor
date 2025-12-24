#ifndef METEOR_SETTING_PARSER
#define METEOR_SETTING_PARSER

#include <cstdint>
#include <nlohmann/detail/conversions/from_json.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <nlohmann/json_fwd.hpp>
#include <utility>

struct meteorSetting{
    uint16_t port;
    std::vector<std::pair<std::string, std::string>> route; 
};

inline void from_json(const nlohmann::json& jsonInput, std::pair<std::string, std::string>& pairOutput){
    pairOutput.first = jsonInput.at(0).get<std::string>();
    pairOutput.second = jsonInput.at(1).get<std::string>();
}

inline void from_json(const nlohmann::json &jsonInput, meteorSetting& structOutput){
    structOutput.port = jsonInput.at("port").get<uint16_t>();
    structOutput.route = jsonInput.at("route").get<std::vector<std::pair<std::string, std::string>>>();
}

inline meteorSetting setting_parser(const std::string& settingPath){
    nlohmann::json jsonResult;

    std::ifstream config(settingPath);

    if (!config.is_open()) {
        throw std::runtime_error("config error");
    }

    config >> jsonResult;

    return jsonResult.get<meteorSetting>();
}

#endif