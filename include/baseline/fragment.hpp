/*
** xsre
** Experimental Storage and Retrieval Engine
**
** Fragment Baseline component interfaces and definitions.
** identifier: xsre.include/baseline.fragment
**
** Design references:
** - xsre.design/101.baseline.fragment
** - xsre.design/101.agnostic.spec
*/

#ifndef xsre_baseline_fragment
#define xsre_baseline_fragment

#include <cstdint>

#include "include/baseline/fragment.def.hpp"

namespace xsre::baseline::fragment {
    template <typename T, int Spec>
    NumericFragment<T, Spec> NumericFragment<T, Spec>::operator+(const NumericFragment<T, Spec>& other) const {
        return NumericFragment<T, Spec>(this->_fragment + other._fragment);
    };

    template <typename T, int Spec>
    NumericFragment<T, Spec> NumericFragment<T, Spec>::operator-(const NumericFragment<T, Spec>& other) const {
        return NumericFragment<T, Spec>(this->_fragment - other._fragment);
    };

    template <typename T, int Spec>
    NumericFragment<T, Spec> NumericFragment<T, Spec>::operator*(const NumericFragment<T, Spec>& other) const {
        return NumericFragment<T, Spec>(this->_fragment * other._fragment);
    };

    template <typename T, int Spec>
    NumericFragment<T, Spec> NumericFragment<T, Spec>::operator/(const NumericFragment<T, Spec>& other) const {
        return NumericFragment<T, Spec>(this->_fragment / other._fragment);
    };
}; // namespace xsre::baseline::fragment

namespace xsre::core::fragment {
    template <>
    class Fragment<std::int8_t> : public baseline::fragment::NumericFragment<std::int8_t> {
        using baseline::fragment::NumericFragment<int8_t>::NumericFragment;
    };

    template <>
    class Fragment<std::int16_t> : public baseline::fragment::NumericFragment<std::int16_t> {
        using baseline::fragment::NumericFragment<int16_t>::NumericFragment;
    };

    template <>
    class Fragment<std::int32_t> : public baseline::fragment::NumericFragment<std::int32_t> {
        using baseline::fragment::NumericFragment<int32_t>::NumericFragment;
    };

    template <>
    class Fragment<std::int64_t> : public baseline::fragment::NumericFragment<std::int64_t> {
        using baseline::fragment::NumericFragment<int64_t>::NumericFragment;
    };

    template <>
    class Fragment<std::uint8_t> : public baseline::fragment::NumericFragment<std::uint8_t> {
        using baseline::fragment::NumericFragment<uint8_t>::NumericFragment;
    };

    template <>
    class Fragment<std::uint16_t> : public baseline::fragment::NumericFragment<std::uint16_t> {
        using baseline::fragment::NumericFragment<uint16_t>::NumericFragment;
    };

    template <>
    class Fragment<std::uint32_t> : public baseline::fragment::NumericFragment<std::uint32_t> {
        using baseline::fragment::NumericFragment<uint32_t>::NumericFragment;
    };

    template <>
    class Fragment<std::uint64_t> : public baseline::fragment::NumericFragment<std::uint64_t> {
        using baseline::fragment::NumericFragment<uint64_t>::NumericFragment;
    };

    template <>
    class Fragment<float> : public baseline::fragment::NumericFragment<float> {
        using baseline::fragment::NumericFragment<float>::NumericFragment;
    };

    template <>
    class Fragment<double> : public baseline::fragment::NumericFragment<double> {
        using baseline::fragment::NumericFragment<double>::NumericFragment;
    };
};     // namespace xsre::core::fragment
#endif // xsre_baseline_fragment
