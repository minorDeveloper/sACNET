#include "library.h"
#include "Artnet/ArtConsts.h"

#include <iostream>

void hello() {
    std::cout << "Hello, World!" << std::endl;
    Artnet::ArtOp artop = Artnet::ArtOp::OpPollReply;
    std::cout << char(artop) << std::endl;
}
