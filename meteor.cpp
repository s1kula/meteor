#include "meteor.hpp"
#include "setting_parser.hpp"

web_server::web_server(const std::string& settingPath)
    : serverEndPoint(ip::tcp::v4(), setting.port)
    , acceptor(mtrio, serverEndPoint)
{
    setting = setting_parser(settingPath);
}
    