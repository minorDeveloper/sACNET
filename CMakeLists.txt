cmake_minimum_required(VERSION 3.20)
project(sACNET)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio
        GIT_TAG asio-1-26-0
        UPDATE_DISCONNECTED 1
)

FetchContent_Populate(asio)

include_directories(${asio_SOURCE_DIR}/asio/include)
link_libraries(ws2_32 wsock32)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASIO_STANDALONE -pthread")
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(sACNET consts.h library.cpp Artnet/ArtConsts.h RDM/RDMConsts.h Artnet/Artnet.cpp Artnet/Artnet.h Artnet/ArtPacket/ArtPoll.h Artnet/ArtPacket/ArtPacket.h)

add_executable(sACNETTest main.cpp)
