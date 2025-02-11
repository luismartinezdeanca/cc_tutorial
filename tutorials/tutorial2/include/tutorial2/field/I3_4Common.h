// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref tutorial2::field::I3_4 field.

#pragma once

#include <cstdint>

namespace tutorial2
{

namespace field
{

/// @brief Common types and functions for
///     @ref tutorial2::field::I3_4 field.
struct I3_4Common
{
    /// @brief Re-definition of the value type used by
    ///     tutorial2::field::I3_4 field.
    using ValueType = std::uint8_t;

    /// @brief Name of the @ref tutorial2::field::I3_4 field.
    static const char* name()
    {
        return "I3_4";
    }
    
    /// @brief Special value <b>"S1"</b>.
    static constexpr ValueType valueS1()
    {
        return static_cast<ValueType>(1);
    }
    
    
    /// @brief Special value <b>"S2"</b>.
    static constexpr ValueType valueS2()
    {
        return static_cast<ValueType>(5);
    }
    
    
    
};

} // namespace field

} // namespace tutorial2


