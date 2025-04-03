/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Fragment core component interfaces and definitions.
** identifier: xsre.include/core.fragment
**
** Design references:
** - xsre.design/101.core.fragment
*/

#ifndef xsre_core_fragment
#define xsre_core_fragment

#include "include/core/fragment.def.hpp"

namespace xsre::core::fragment {
    template <typename T, bool Spec>
    Fragment<T, Spec>::Fragment(T fragment) : _fragment(fragment) {}

    template <typename T, bool Spec>
    Fragment<T, Spec>::~Fragment() = default;

    template <typename T, bool Spec>
    Fragment<T, Spec>::operator T() {
        return _fragment;
    };

    template <typename T, bool Spec>
    Fragment<T, Spec>& Fragment<T, Spec>::operator=(const T& fragment) {
        _fragment = fragment;
        return *this;
    };
};     // namespace xsre::core::fragment
#endif // xsre_core_fragment
