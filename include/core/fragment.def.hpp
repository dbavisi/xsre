/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Fragment core component interfaces and definitions.
** identifier: xsre.include/core.fragment.def
**
** Design references:
** - xsre.design/101.core.fragment
*/

#ifndef xsre_core_fragment_def
#define xsre_core_fragment_def

namespace xsre::core::fragment {
    template <typename T, int Spec = 0>
    class Fragment {
    protected:
        T _fragment;

    public:
        Fragment(T fragment);                            // storage
        ~Fragment();                                     // deletion
                           operator T() const;           // retrieval
        Fragment<T, Spec>& operator=(const T& fragment); // modification

    }; // class xsre::core::fragment::Fragment
};     // namespace xsre::core::fragment
#endif // xsre_core_fragment_def
