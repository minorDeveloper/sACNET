//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPOLL_H
#define SACNET_ARTPOLL_H

#include <array>
#include <cstdint>


class ArtPoll{
    std::array<std::uint8_t, 14> byteArray;

    //Artnet::ArtOp OpCode = Artnet::ArtOp::OpPoll;;
    std::uint16_t OpCode = 0x2000;


public:
    ArtPoll() {
        byteArray[0] = std::uint8_t('A');
        byteArray[1] = std::uint8_t('r');
        byteArray[2] = std::uint8_t('t');
        byteArray[3] = std::uint8_t('-');
        byteArray[4] = std::uint8_t('N');
        byteArray[5] = std::uint8_t('e');
        byteArray[6] = std::uint8_t('t');
        byteArray[7] = std::uint8_t('\n');
        byteArray[8] = std::uint16_t(OpCode) >> 8;
        byteArray[9] = std::uint16_t(OpCode) & 0xFF;
        byteArray[10]= 14 >> 8;
        byteArray[11]= 14 & 0xFF;
        byteArray[12]= 0;
        byteArray[13]= 0;
    }

    // TODO note this returns a copy
    std::array<std::uint8_t, 14> getByteArray(){
        return byteArray;
    }

};


#endif //SACNET_ARTPOLL_H
