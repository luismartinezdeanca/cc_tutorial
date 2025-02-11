// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of protocol default options.

#pragma once

#include "comms/options.h"

namespace howto4
{

namespace options
{

/// @brief Default (empty) options of the protocol.
struct DefaultOptions
{
    /// @brief Extra options for fields.
    struct field
    {
        /// @brief Extra options for all the member fields of
        ///     @ref howto4::field::TlvProp bitfield.
        struct TlvPropMembers
        {
            /// @brief Extra options for all the member fields of
            ///     @ref howto4::field::TlvPropMembers::Prop3 bundle.
            struct Prop3Members
            {
                /// @brief Extra options for @ref
                ///     howto4::field::TlvPropMembers::Prop3Members::Val
                ///     field.
                using Val = comms::option::app::EmptyOption;
                
            };
            
            /// @brief Extra options for all the member fields of
            ///     @ref howto4::field::TlvPropMembers::Any bundle.
            struct AnyMembers
            {
                /// @brief Extra options for @ref
                ///     howto4::field::TlvPropMembers::AnyMembers::Val
                ///     field.
                using Val = comms::option::app::EmptyOption;
                
            };
            
        };
        
    }; // struct field
    
    /// @brief Extra options for messages.
    struct message
    {
        /// @brief Extra options for fields of
        ///     @ref howto4::message::Msg message.
        struct MsgFields
        {
            /// @brief Extra options for @ref
            ///     howto4::message::MsgFields::Props field.
            using Props = comms::option::app::EmptyOption;
            
        }; // struct MsgFields
        
        
    }; // struct message
    
    /// @brief Extra options for frames.
    struct frame
    {
        /// @brief Extra options for Layers of
        ///     @ref howto4::frame::Frame frame.
        struct FrameLayers
        {
            /// @brief Extra options for @ref
            ///     howto4::frame::FrameLayers::Data layer.
            using Data = comms::option::app::EmptyOption;
            
            /// @brief Extra options for @ref
            ///     howto4::frame::FrameLayers::Id layer.
            using Id = comms::option::app::EmptyOption;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

} // namespace options

} // namespace howto4


