//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPACKET_H
#define SACNET_ARTPACKET_H

#include "../ArtConsts.h"

class ArtPacket {
private:

protected:
    std::uint16_t length;
    std::vector<std::uint8_t> bytes;
    Artnet::ArtOp opcode;

    bool validatePacketString(std::vector<uint8_t>& stringBytes) {
        return stringBytes == Artnet::ArtnetBytes;
    }

    bool validateOpCode(std::vector<uint8_t> opcodeBytes) {
        return true;
    }

    Artnet::ArtOp getPacketOpcode() {
        return Artnet::ArtOp::OpNull;
    }

public:
    ArtPacket(uint16_t _length, Artnet::ArtOp _opcode) {
        this->length = _length;
        this->opcode = _opcode;
        this->bytes.resize(length);
    }

    // TODO note this returns a copy
    std::vector<std::uint8_t> getBytes(){
        return this->bytes;
    }

    Artnet::ArtOp getOpCode() {
        return this->opcode;
    }

    uint16_t getLength() {
        return this->length;
    }

    virtual bool parse(std::vector<uint8_t>& packetBytes) {
        std::vector<std::uint8_t> stringBytes(packetBytes.begin(), packetBytes.begin() + Artnet::ArtnetBytes.size());
        if (!validatePacketString(stringBytes)) return false;

        std::vector<std::uint8_t> opcodeBytes(packetBytes.begin() + 8, packetBytes.begin() + 9);
        if (!validateOpCode(opcodeBytes)) return false;

        return true;
    };


};


#endif //SACNET_ARTPACKET_H
