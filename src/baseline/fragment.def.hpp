/*
** xsre
** Experimental Storage and Retrieval Engine
**
** identifier: xsre.src/baseline.fragment.def
**
** Design references:
** - xsre.design/101.core.fragment #xsre-baseline
*/

#ifndef xsre_baseline_fragment_def
#define xsre_baseline_fragment_def

#include <cstdint>

namespace xsre::baseline::fragment
{
    using ch = char;

    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    using f32 = float;
    using f64 = double;

    /*
    ** Unique identifiers for cross-platform compatibility.
    */
    using dtype = u32;
    namespace type
    {
        static inline constexpr const dtype unknown = 0;

        static inline constexpr const dtype ch = 10 + sizeof(fragment::ch);

        static inline constexpr const dtype i8 = 20 + sizeof(fragment::i8);
        static inline constexpr const dtype i16 = 20 + sizeof(fragment::i16);
        static inline constexpr const dtype i32 = 20 + sizeof(fragment::i32);
        static inline constexpr const dtype i64 = 20 + sizeof(fragment::i64);

        static inline constexpr const dtype u8 = 30 + sizeof(fragment::u8);
        static inline constexpr const dtype u16 = 30 + sizeof(fragment::u16);
        static inline constexpr const dtype u32 = 30 + sizeof(fragment::u32);
        static inline constexpr const dtype u64 = 30 + sizeof(fragment::u64);

        static inline constexpr const dtype f32 = 40 + sizeof(fragment::f32);
        static inline constexpr const dtype f64 = 40 + sizeof(fragment::f64);

        static inline constexpr const dtype buffer = 50;
        static inline constexpr const dtype string = 60;
        static inline constexpr const dtype array = 70;
    } // namespace xsre::baseline::fragment::type
} // namespace xsre::baseline::fragment
#endif // xsre_baseline_fragment_def
