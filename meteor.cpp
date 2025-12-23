#include "meteor.hpp"
#include "setting_parser.hpp"

web_server::web_server(const std::string& settingPath){
    setting = setting_parser(settingPath);
}
    