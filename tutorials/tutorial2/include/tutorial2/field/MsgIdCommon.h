// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref tutorial2::field::MsgId field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "tutorial2/MsgId.h"

namespace tutorial2
{

namespace field
{

/// @brief Common types and functions for
///     @ref tutorial2::field::MsgId field.
struct MsgIdCommon
{
    /// @brief Values enumerator for
    ///     @ref tutorial2::field::MsgId field.
    using ValueType = tutorial2::MsgId;
    
    /// @brief Name of the @ref tutorial2::field::MsgId field.
    static const char* name()
    {
        return "MsgId";
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(tutorial2::MsgId val)
    {
        static const char* Map[] = {
            nullptr,
            "M1",
            "M2",
            "M3",
            "M4",
            "M5",
            "M6",
            "M7",
            "M8",
            "M9",
            "M10"
        };
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
        
        if (MapSize <= static_cast<std::size_t>(val)) {
            return nullptr;
        }
        
        return Map[static_cast<std::size_t>(val)];
    }
    
};

/// @brief Values enumerator for
///     @ref tutorial2::field::MsgId field.
using MsgIdVal = MsgIdCommon::ValueType;

} // namespace field

} // namespace tutorial2


