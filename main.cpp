//
// Created by samla on 09/03/2023.
//
#include <iostream>
#include <asio.hpp>
#include "Artnet/ArtPacket/ArtPoll.h"

using asio::ip::udp;

int main() {
    ArtPoll artPollPacket;

    try {
        asio::io_context io_context;
        udp::resolver resolver(io_context);
        udp::endpoint receiver_endpoint = *resolver.resolve(udp::v4(), "192.168.0.208", "6454").begin();

        udp::socket socket(io_context);
        socket.open(udp::v4());
        socket.bind(udp::endpoint(udp::v4(), 6454));

        socket.send_to(asio::buffer(artPollPacket.getBytes()), receiver_endpoint);

        char recv_buf[128];
        udp::endpoint sender_endpoint;
        sender_endpoint.port(6454);
        size_t len = socket.receive_from(
                asio::buffer(recv_buf), sender_endpoint
                );


        // Need to listen on 6454
        std::cout.write(recv_buf, len);
        //std::cout << "Reached here" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
