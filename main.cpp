//
// Created by samla on 09/03/2023.
//
#include <iostream>
#include <asio.hpp>

void print(const asio::error_code& /*e*/) {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    asio::io_context io;

    asio::steady_timer t(io, asio::chrono::seconds(5));

    t.async_wait(&print);
    io.run();

    std::cout << "This should happen first" << std::endl;

    return 0;
}
