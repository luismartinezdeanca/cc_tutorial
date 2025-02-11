// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref howto4::message::Msg message and its fields.

#pragma once

namespace howto4
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref howto4::message::Msg message.
/// @see howto4::message::MsgFields
struct MsgFieldsCommon
{
    /// @brief Scope for all the common definitions of the
    ///     @ref howto4::message::MsgFields::Props field.
    struct PropsCommon
    {
        /// @brief Name of the @ref howto4::message::MsgFields::Props field.
        static const char* name()
        {
            return "Props";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref howto4::message::Msg message.
/// @see howto4::message::Msg
struct MsgCommon
{
    /// @brief Name of the @ref howto4::message::Msg message.
    static const char* name()
    {
        return "Message";
    }
    
};

} // namespace message

} // namespace howto4


