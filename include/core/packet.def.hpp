/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Packet Core component interfaces and definitions.
** identifier: xsre.include/core.packet.def
**
*/

#ifndef xsre_core_fragment_def
#define xsre_core_fragment_def

#include <string>

namespace xsre::core::packet {
    template<int spec = 0>
    class Packet{
    protected:
        string _filename;
        std::vector<xsre::baseline::fragment::Fragment> _fragments;
    public:
        Packet(std::string filename);                                                               // storage
        ~Packet();                                                                                  // deletion
        Packet<spec>& operator=(const Packet& packet);                                              // Modification
        std::vector<xsre::baseline::fragment::Fragment> getFragments() const;
        void setFragments(const std::vector<xsre::baseline::fragment::Fragment>& fragments);
        void addFragment(const xsre::baseline::fragment::Fragment& fragment);
        void clearFragments();
    };
};
#endif