// Generated by commsdsl2comms v3.4.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref tutorial13::message::Msg2_1 message and its fields.

#pragma once

#include <cstdint>

namespace tutorial13
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref tutorial13::message::Msg2_1 message.
/// @see tutorial13::message::Msg2_1Fields
struct Msg2_1FieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref tutorial13::message::Msg2_1Fields::Type field.
    struct TypeCommon
    {
        /// @brief Re-definition of the value type used by
        ///     tutorial13::message::Msg2_1Fields::Type field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref tutorial13::message::Msg2_1Fields::Type field.
        static const char* name()
        {
            return "Type";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref tutorial13::message::Msg2_1Fields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     tutorial13::message::Msg2_1Fields::F1 field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref tutorial13::message::Msg2_1Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref tutorial13::message::Msg2_1 message.
/// @see tutorial13::message::Msg2_1
struct Msg2_1Common
{
    /// @brief Name of the @ref tutorial13::message::Msg2_1 message.
    static const char* name()
    {
        return "Message 2 (1)";
    }
    
};

} // namespace message

} // namespace tutorial13


