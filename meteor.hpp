#ifndef METEOR_WEB_FW
#define METEOR_WEB_FW

#include <boost/asio.hpp>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include "setting_parser.hpp"

/* meteorSetting is defined in setting_parser.hpp
struct meteorSetting{
    uint16_t port;
    std::vector<std::pair<uint16_t, std::string>> route; 
};
*/

class web_server {
private:
    meteorSetting setting; 
    boost::asio::io_context mtrio;

public:
    web_server(const std::string& settingPath);

};

#endif