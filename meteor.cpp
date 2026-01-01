#include "meteor.hpp"
#include "setting_parser.hpp"
#include <cstddef>

#define MB8 8388698

web_server::web_server(const std::string& settingPath)
    : serverEndPoint(ip::tcp::v4(), setting.port)
    , acceptor(mtrio, serverEndPoint)
{
    setting = setting_parser(settingPath);

    while (true) {
        boost::asio::ip::tcp::socket socket(mtrio);
        std::string buffer(MB8, 0);

        acceptor.accept(socket);

        size_t sizeRead = socket.read_some(asio::buffer(buffer.data(), buffer.size()));
        buffer.resize(sizeRead);
    }
}
    