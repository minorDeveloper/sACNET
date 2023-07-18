//
// Created by samla on 14/03/2023.
//

#ifndef SACNET_ARTPACKET_H
#define SACNET_ARTPACKET_H

class ArtPacket {
private:

protected:
    std::uint16_t length;
    std::vector<std::uint8_t> bytes;
    Artnet::ArtOp OpCode;

public:


};


#endif //SACNET_ARTPACKET_H
