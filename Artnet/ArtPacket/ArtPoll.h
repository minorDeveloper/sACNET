//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPOLL_H
#define SACNET_ARTPOLL_H

#include "../ArtConsts.h"
#include "ArtPacket.h"


#include <iostream>

class ArtPoll : public ArtPacket {


public:
    ArtPoll() : ArtPacket(14, Artnet::ArtOp::OpPoll) {
        // Artnet message
        for (int i = 0; i < 8; i++) {
            this->bytes[i] = std::uint8_t(Artnet::ArtnetString[i]);
        }

        // Opcode
        this->bytes[8] = std::uint16_t(this->opcode) & 0xFF;
        this->bytes[9] = std::uint16_t(this->opcode) >> 8;

        // Flags
        this->bytes[10] = 14 >> 8;
        this->bytes[11] = 14 & 0xFF;
        this->bytes[12] = 0;
        this->bytes[13] = 0;

    }

    bool parse(std::vector<uint8_t>& packetBytes) override {
        return true;
    };
};


#endif //SACNET_ARTPOLL_H
