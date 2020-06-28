// Generated by commsdsl2comms v3.4.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref tutorial12::message::Msg1 message and its fields.

#pragma once

namespace tutorial12
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref tutorial12::message::Msg1 message.
/// @see tutorial12::message::Msg1Fields
struct Msg1FieldsCommon
{
    /// @brief Scope for all the common definitions of the
    ///     @ref tutorial12::message::Msg1Fields::F1 field.
    struct F1Common
    {
        /// @brief Name of the @ref tutorial12::message::Msg1Fields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the
    ///     @ref tutorial12::message::Msg1Fields::F2 field.
    struct F2Common
    {
        /// @brief Name of the @ref tutorial12::message::Msg1Fields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref tutorial12::message::Msg1 message.
/// @see tutorial12::message::Msg1
struct Msg1Common
{
    /// @brief Name of the @ref tutorial12::message::Msg1 message.
    static const char* name()
    {
        return "Message 1";
    }
    
};

} // namespace message

} // namespace tutorial12


