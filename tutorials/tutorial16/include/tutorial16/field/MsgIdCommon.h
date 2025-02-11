// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref tutorial16::field::MsgId field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "tutorial16/MsgId.h"

namespace tutorial16
{

namespace field
{

/// @brief Common types and functions for
///     @ref tutorial16::field::MsgId field.
struct MsgIdCommon
{
    /// @brief Values enumerator for
    ///     @ref tutorial16::field::MsgId field.
    using ValueType = tutorial16::MsgId;
    
    /// @brief Name of the @ref tutorial16::field::MsgId field.
    static const char* name()
    {
        return "MsgId";
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(tutorial16::MsgId val)
    {
        static const char* Map[] = {
            nullptr,
            "Message 1",
            "Message 2"
        };
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
        
        if (MapSize <= static_cast<std::size_t>(val)) {
            return nullptr;
        }
        
        return Map[static_cast<std::size_t>(val)];
    }
    
};

/// @brief Values enumerator for
///     @ref tutorial16::field::MsgId field.
using MsgIdVal = MsgIdCommon::ValueType;

} // namespace field

} // namespace tutorial16


