//
// Created by samla on 09/03/2023.
//
#include <iostream>
#include <asio.hpp>
#include "Artnet/ArtPacket/ArtPoll.h"
#include "Artnet/ArtPacket/ArtPollReply.h"


using asio::ip::udp;

int main() {
    ArtPoll artPollPacket;
    ArtPollReply artPollReply;

    try {

        std::cout << "Sending Packet" << std::endl;
        asio::io_context io_context;
        udp::resolver resolver(io_context);
        udp::endpoint receiver_endpoint = *resolver.resolve(udp::v4(), "192.168.0.208", "6454").begin();

        udp::socket socket(io_context);
        socket.open(udp::v4());
        socket.bind(udp::endpoint(udp::v4(), 6454));

        socket.send_to(asio::buffer(artPollPacket.getBytes()), receiver_endpoint);


        std::cout << "Packet sent" << std::endl;
        char recv_buf[256];
        udp::endpoint sender_endpoint(asio::ip::address_v4::broadcast(), 6454);

        size_t len = socket.receive_from(
                asio::buffer(recv_buf), sender_endpoint
                );


        std::cout << "Packet received" << std::endl;
        std::cout << len << std::endl;
        // Need to listen on 6454
        std::cout.write(recv_buf, len);

        //std::vector<uint8_t> packet(recv_buf, recv_buf + len);
        //bool validPacket = artPollReply.parse(packet);


        //std::cout << validPacket << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
