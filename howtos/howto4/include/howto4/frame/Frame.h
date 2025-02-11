// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of <b>"Frame"</b> frame class.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "comms/protocol/ChecksumLayer.h"
#include "comms/protocol/MsgDataLayer.h"
#include "comms/protocol/MsgIdLayer.h"
#include "comms/protocol/MsgSizeLayer.h"
#include "comms/protocol/SyncPrefixLayer.h"
#include "comms/protocol/checksum/Crc.h"
#include "howto4/field/FieldBase.h"
#include "howto4/frame/FrameCommon.h"
#include "howto4/input/AllMessages.h"
#include "howto4/options/DefaultOptions.h"

namespace howto4
{

namespace frame
{

/// @brief Layers definition of @ref Frame frame class.
/// @tparam TOpt Protocol options.
/// @see @ref Frame
/// @headerfile "howto4/frame/Frame.h"
template <typename TOpt = howto4::options::DefaultOptions>
struct FrameLayers
{
    /// @brief Definition of layer "Data".
    using Data =
        comms::protocol::MsgDataLayer<
            typename TOpt::frame::FrameLayers::Data
        >;
    
    /// @brief Scope for field(s) of @ref Id layer.
    struct IdMembers
    {
        /// @brief Definition of <b>"IdField"</b> field.
        struct IdField : public
            comms::field::IntValue<
                howto4::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::EmptySerialization
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return howto4::frame::FrameLayersCommon::IdMembersCommon::IdFieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of layer "Id".
    template <typename TMessage, typename TAllMessages>
    using Id =
        comms::protocol::MsgIdLayer<
            typename IdMembers::IdField,
            TMessage,
            TAllMessages,
            Data,
            typename TOpt::frame::FrameLayers::Id
        >;
    
    /// @brief Scope for field(s) of @ref Size layer.
    struct SizeMembers
    {
        /// @brief Definition of <b>"SizeField"</b> field.
        struct SizeField : public
            comms::field::IntValue<
                howto4::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::NumValueSerOffset<2>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return howto4::frame::FrameLayersCommon::SizeMembersCommon::SizeFieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of layer "Size".
    template <typename TMessage, typename TAllMessages>
    using Size =
        comms::protocol::MsgSizeLayer<
            typename SizeMembers::SizeField,
            Id<TMessage, TAllMessages>
        >;
    
    /// @brief Scope for field(s) of @ref Checksum layer.
    struct ChecksumMembers
    {
        /// @brief Definition of <b>"ChecksumField"</b> field.
        struct ChecksumField : public
            comms::field::IntValue<
                howto4::field::FieldBase<>,
                std::uint16_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return howto4::frame::FrameLayersCommon::ChecksumMembersCommon::ChecksumFieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of layer "Checksum".
    template <typename TMessage, typename TAllMessages>
    using Checksum =
        comms::protocol::ChecksumLayer<
            typename ChecksumMembers::ChecksumField,
            comms::protocol::checksum::Crc_CCITT,
            Size<TMessage, TAllMessages>
        >;
    
    /// @brief Scope for field(s) of @ref Sync layer.
    struct SyncMembers
    {
        /// @brief Definition of <b>"SyncField"</b> field.
        struct SyncField : public
            comms::field::IntValue<
                howto4::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::FailOnInvalid<comms::ErrorStatus::ProtocolError>,
                comms::option::def::DefaultNumValue<43981L>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return howto4::frame::FrameLayersCommon::SyncMembersCommon::SyncFieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of layer "Sync".
    template <typename TMessage, typename TAllMessages>
    using Sync =
        comms::protocol::SyncPrefixLayer<
            typename SyncMembers::SyncField,
            Checksum<TMessage, TAllMessages>
        >;
    
    /// @brief Final protocol stack definition.
    template<typename TMessage, typename TAllMessages>
    using Stack = Sync<TMessage, TAllMessages>;
    
};

/// @brief Definition of <b>"Frame"</b> frame class.
/// @tparam TMessage Common interface class of all the messages
/// @tparam TAllMessages All supported input messages.
/// @tparam TOpt Frame definition options
/// @headerfile "howto4/frame/Frame.h"
template <
   typename TMessage,
   typename TAllMessages = howto4::input::AllMessages<TMessage>,
   typename TOpt = howto4::options::DefaultOptions
>
class Frame : public
    FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>
{
    using Base =
        typename FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>;
public:
    /// @brief Allow access to frame definition layers.
    /// @details See definition of @b COMMS_PROTOCOL_LAYERS_ACCESS macro
    ///     from COMMS library for details.
    ///
    ///     The generated functions are:
    ///     @li layer_data() for @ref FrameLayers::Data layer.
    ///     @li layer_id() for @ref FrameLayers::Id layer.
    ///     @li layer_size() for @ref FrameLayers::Size layer.
    ///     @li layer_checksum() for @ref FrameLayers::Checksum layer.
    ///     @li layer_sync() for @ref FrameLayers::Sync layer.
    COMMS_PROTOCOL_LAYERS_ACCESS(
        data,
        id,
        size,
        checksum,
        sync
    );
};

} // namespace frame

} // namespace howto4


