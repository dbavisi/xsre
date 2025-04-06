/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Packet core component interfaces and definitions.
** identifier: xsre.include/core.packet
**
*/

#ifndef xsre_core_packet
#define xsre_core_packet
#include <string>
#include <cstdint>
#include <vector>

#include "include/core/packet.def.hpp"
#include "include/baseline/fragment.def.hpp"

namespace xsre::core::packet {
    template<int spec = 0>
    class Packet{
    protected:
        std::string _filename;
        std::vector<xsre::baseline::fragment::Fragment> _fragments;
    public:
        Packet(std::string filename): _filename(filename), _size(0) {
            // Constructor implementation
        }                    // storage
        ~Packet() {
            // Destructor implementation
        }                                  // deletion
        Packet<spec>& operator=(const Packet& packet) {
            // Assignment operator implementation
            if (this != &packet) {
                _filename = packet._filename;
                _fragments = packet._fragments;
            }
            return *this;
        }   // Modification
        std::vector<xsre::baseline::fragment::Fragment> getFragments() const {
            return _fragments;
        }
        void setFragments(const std::vector<xsre::baseline::fragment::Fragment>& fragments) {
            _fragments = fragments;
            _size = fragments.size();
        }
        void addFragment(const xsre::baseline::fragment::Fragment& fragment) {
            _fragments.push_back(fragment);
        }
        void clearFragments() {
            _fragments.clear();
        }
    };
}; // namespace xsre::core::packet
#endif // xsre_core_packet