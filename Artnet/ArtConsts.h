//
// Created by samla on 12/02/2023.
//

#ifndef SACNET_ARTCONSTS_H
#define SACNET_ARTCONSTS_H

#include <cstdint>
#include <string>

namespace Artnet {
    std::string ArtNetString = "Art-Net\n";

    enum class ArtOp : std::uint16_t {
        OpPoll              = 0x2000,   // Transmited by controllers to discover devices
        OpPollReply         = 0x2100,   // Discovery process acknowledgement, also contains status info
        OpCommand           = 0x2400,   // Used to issue property->set commands

        OpAddress           = 0x6000,   // Configures port->address (universe), name strings, and operating mode
        OpInput             = 0x7000,   // Enables or disables DMX512 inputs of a node
        OpIpProg            = 0xF800,   // Reprograms IP address of a node
        OpIpProgReply       = 0xF900,   // Acknowledgement of IP reprogram
    };

}

#endif //SACNET_ARTCONSTS_H
