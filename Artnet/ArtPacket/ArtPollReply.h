
#ifndef SACNET_ARTPOLLREPLY_H
#define SACNET_ARTPOLLREPLY_H

#include <cstdint>
#include <vector>
#include "../ArtConsts.h"
#include "ArtPacket.h"

class ArtPollReply : ArtPacket{

public:
    ArtPollReply() : ArtPacket(256, Artnet::ArtOp::OpPollReply) {

    }

    bool parse(std::vector<uint8_t>& packetBytes) override {
        if (!ArtPacket::parse(packetBytes)) return false;

        return true;
    };

};

#endif //SACNET_ARTPOLLREPLY_H
