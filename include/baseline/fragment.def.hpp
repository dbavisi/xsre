/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Fragment Baseline component interfaces and definitions.
** identifier: xsre.include/baseline.fragment.def
**
** Design references:
** - xsre.design/101.core.fragment
** - xsre.design/101.baseline.fragment
*/

#ifndef xsre_baseline_fragment_def
#define xsre_baseline_fragment_def

#include <type_traits>

#include "include/core/fragment.def.hpp"

namespace xsre::baseline::fragment {
    template <typename T, bool Spec = false>
    class NumericFragment : public core::fragment::Fragment<T, true> {
        static_assert(std::is_arithmetic<T>::value, "NumericFragment can only be used with arithmetic types");

    public:
        using core::fragment::Fragment<T, true>::Fragment;

        NumericFragment<T, Spec> operator+(const NumericFragment<T, Spec>& other) const;
        NumericFragment<T, Spec> operator-(const NumericFragment<T, Spec>& other) const;
        NumericFragment<T, Spec> operator*(const NumericFragment<T, Spec>& other) const;
        NumericFragment<T, Spec> operator/(const NumericFragment<T, Spec>& other) const;
    }; // class xsre::baseline::fragment::NumericFragment
};     // namespace xsre::baseline::fragment
#endif // xsre_baseline_fragment_def
