cmake_minimum_required(VERSION 3.20)
project(sACNET)

set(CMAKE_CXX_STANDARD 14)

add_library(sACNET consts.h library.cpp Artnet/ArtConsts.h RDM/RDMConsts.h Artnet/Artnet.cpp Artnet/Artnet.h)
