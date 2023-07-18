//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPOLL_H
#define SACNET_ARTPOLL_H

#include "../ArtConsts.h"
#include "ArtPacket.h"


#include <iostream>

class ArtPoll : ArtPacket {

public:
    ArtPoll() {

        this->length = 14;
        this->OpCode = Artnet::ArtOp::OpPoll;
        std::cout << this->length << std::endl;
        this->bytes.reserve(this->length);
        std::cout << this->bytes.size() << std::endl;


        // Artnet message
        for (int i = 0; i < 8; i++) {
            this->bytes.push_back(std::uint8_t(Artnet::ArtNetString[i]));
        }

        std::cout << "Packet created" << std::endl;

        // Opcode
        this->bytes.push_back(std::uint16_t(this->OpCode) & 0xFF);
        this->bytes.push_back(std::uint16_t(this->OpCode) >> 8);

        // Flags
        this->bytes[10]= 14 >> 8;
        this->bytes[11]= 14 & 0xFF;
        this->bytes[12]= 0;
        this->bytes[13]= 0;

    }

    // TODO note this returns a copy
    std::vector<std::uint8_t> getBytes(){
        return this->bytes;
    }

};


#endif //SACNET_ARTPOLL_H
