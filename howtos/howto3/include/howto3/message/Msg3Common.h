// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref howto3::message::Msg3 message and its fields.

#pragma once

#include <cstdint>

namespace howto3
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref howto3::message::Msg3 message.
/// @see howto3::message::Msg3Fields
struct Msg3FieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref howto3::message::Msg3Fields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     howto3::message::Msg3Fields::F1 field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref howto3::message::Msg3Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref howto3::message::Msg3 message.
/// @see howto3::message::Msg3
struct Msg3Common
{
    /// @brief Name of the @ref howto3::message::Msg3 message.
    static const char* name()
    {
        return "Message 3";
    }
    
};

} // namespace message

} // namespace howto3


