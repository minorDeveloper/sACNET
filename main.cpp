//
// Created by samla on 09/03/2023.
//
#include <iostream>
#include <asio.hpp>

using asio::ip::udp;

int main() {
    try {
        asio::io_context io_context;
        udp::resolver resolver(io_context);
        udp::endpoint receiver_endpoint =
                *resolver.resolve(udp::v4(), "192.168.1.1", "daytime").begin();

        udp::socket socket(io_context);
        socket.open(udp::v4());

        char send_buf[1] = {0};
        socket.send_to(asio::buffer(send_buf), receiver_endpoint);

        char recv_buf[128];
        udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(
                asio::buffer(recv_buf), sender_endpoint
                );

        std::cout.write(recv_buf, len);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
