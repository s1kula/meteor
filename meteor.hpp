#ifndef METEOR_WEB_FW
#define METEOR_WEB_FW

#include <boost/asio.hpp>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include "setting_parser.hpp"

namespace asio = boost::asio;
namespace ip = boost::asio::ip;

/* meteorSetting is defined in setting_parser.hpp
struct meteorSetting{
    uint16_t port;
    std::vector<std::pair<uint16_t, std::string>> route; 
};
*/

class web_server {
private:
    meteorSetting setting; 
    asio::io_context mtrio;
    ip::tcp::endpoint serverEndPoint;
    ip::tcp::acceptor acceptor;
public:
    web_server(const std::string& settingPath);
    
};

#endif