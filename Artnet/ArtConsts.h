//
// Created by samla on 12/02/2023.
//

#ifndef SACNET_ARTCONSTS_H
#define SACNET_ARTCONSTS_H

#include <cstdint>
#include <string>
#include <vector>

namespace Artnet {
    std::string ArtnetString = "Art-Net\0";
    std::vector<std::uint8_t> ArtnetBytes{0x41, 0x72, 0x74, 0x2D, 0x4E, 0x65, 0x74, 0x00};

    enum class ArtOp : std::uint16_t {
        OpNull              = 0x0000,
        OpPoll              = 0x2000,   // Transmited by controllers to discover devices
        OpPollReply         = 0x2100,   // Discovery process acknowledgement, also contains status info
        OpDiagData          = 0x2300,   // Diagnostics and data loging packet
        OpCommand           = 0x2400,   // Used to issue property->set commands

        OpDmx               = 0x5000,   // ArtDMX Packet - zero start code DMX512 info for a single universe
        OpNzs               = 0x5100,   // ArtNzs Packet - non zero start code (except RDM) DMX512 info for a single universe
        OpSynz              = 0x5200,   // ArtSync - force synchronous transfer of a ArtDmx packets to a node output

        OpAddress           = 0x6000,   // Configures port->address (universe), name strings, and operating mode
        OpInput             = 0x7000,   // Enables or disables DMX512 inputs of a node

        OpTodRequest        = 0x8000,   // Used to send a table of devices for RDM discovery
        OpTodData           = 0x8100,   // RDM discovery control message
        OpRdm               = 0x8300,   // All non-discovery rdm messages
        OpRdmSub            = 0x8400,   // Compressed RDM sub-device data

        OpVideoSetup        = 0xA010,   // Video screen setup information for supported nodes

        OpIpProg            = 0xF800,   // Reprograms IP address of a node
        OpIpProgReply       = 0xF900,   // Acknowledgement of IP reprogram
    };

}

#endif //SACNET_ARTCONSTS_H
