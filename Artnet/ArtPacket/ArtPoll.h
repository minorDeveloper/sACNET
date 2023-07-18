//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPOLL_H
#define SACNET_ARTPOLL_H

#include "../ArtConsts.h"
#include "ArtPacket.h"


class ArtPoll : ArtPacket {
    const static std::uint8_t length = 14;
    std::array<std::uint8_t, length> byteArray;
    Artnet::ArtOp OpCode = Artnet::ArtOp::OpPoll;

public:
    ArtPoll() {
        // Artnet message
        for (int i = 0; i < 8; i++) {
            byteArray[i] = std::uint8_t(Artnet::ArtNetString[i]);
        }

        // Opcode
        byteArray[8] = std::uint16_t(OpCode) & 0xFF;
        byteArray[9] = std::uint16_t(OpCode) >> 8;

        // Flags
        byteArray[10]= 14 >> 8;
        byteArray[11]= 14 & 0xFF;
        byteArray[12]= 0;
        byteArray[13]= 0;
    }

    // TODO note this returns a copy
    std::array<std::uint8_t, length> getByteArray(){
        return byteArray;
    }

};


#endif //SACNET_ARTPOLL_H
