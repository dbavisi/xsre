/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Packet Baseline component interfaces and definitions.
** identifier: xsre.include/baseline.packet.def
**
*/

#ifndef xsre_baseline_packet_def
#define xsre_baseline_packet_def
#include <cstdint>

#include "include/core/packet.def.hpp"

namespace xsre::baseline::packet {
    template <int Spec = 0>
    class ColumnMajorPacket : public core::packet::Packet<Spec> {
    public:
        using core::packet::Packet<Spec>::Packet;

        // Column-major packet-specific methods can be added heres
    };
    template <int Spec = 0>
    class RowMajorPacket : public core::packet::Packet<Spec> {
    public:
        using core::packet::Packet<Spec>::Packet;

        // Row-major packet-specific methods can be added here
    };
};
#endif // xsre_baseline_packet_def