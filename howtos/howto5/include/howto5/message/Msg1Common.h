// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref howto5::message::Msg1 message and its fields.

#pragma once

#include <cstdint>

namespace howto5
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref howto5::message::Msg1 message.
/// @see howto5::message::Msg1Fields
struct Msg1FieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref howto5::message::Msg1Fields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     howto5::message::Msg1Fields::F1 field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref howto5::message::Msg1Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref howto5::message::Msg1Fields::F2 field.
    struct F2MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref howto5::message::Msg1Fields::F2Members::Field field.
        struct FieldCommon
        {
            /// @brief Re-definition of the value type used by
            ///     howto5::message::Msg1Fields::F2Members::Field field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref howto5::message::Msg1Fields::F2Members::Field field.
            static const char* name()
            {
                return "F3";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref howto5::message::Msg1Fields::F2 field.
    struct F2Common
    {
        /// @brief Name of the @ref howto5::message::Msg1Fields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    
    /// @brief Common types and functions for
    ///     @ref howto5::message::Msg1Fields::F3 field.
    struct F3Common
    {
        /// @brief Re-definition of the value type used by
        ///     howto5::message::Msg1Fields::F3 field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref howto5::message::Msg1Fields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref howto5::message::Msg1 message.
/// @see howto5::message::Msg1
struct Msg1Common
{
    /// @brief Name of the @ref howto5::message::Msg1 message.
    static const char* name()
    {
        return "Message 1";
    }
    
};

} // namespace message

} // namespace howto5


