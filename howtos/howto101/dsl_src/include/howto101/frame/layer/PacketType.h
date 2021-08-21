#pragma once

#include <limits>

#include "comms/protocol/MsgIdLayer.h"
#include "comms/options.h"

#include <iostream>

namespace howto101
{

namespace frame
{

namespace layer
{
/// @brief Customizing the Id layer
template<typename TField, typename TMessage, typename TAllMessages, typename TNextLayer, typename... TOptions>
class PacketType : public
    comms::protocol::MsgIdLayer<
        TField,
        TMessage,
        TAllMessages,
        TNextLayer,
        TOptions...,
        comms::option::def::ExtendingClass<PacketType<TField, TMessage, TAllMessages, TNextLayer, TOptions...> >
    >
{
    // Repeat base type
    using Base = 
        comms::protocol::MsgIdLayer<
            TField,
            TMessage,
            TAllMessages,
            TNextLayer,
            TOptions...,
            comms::option::def::ExtendingClass<PacketType<TField, TMessage, TAllMessages, TNextLayer, TOptions...> >
        >;

public:
    // Repeat some types from the base class
    using Field = typename Base::Field;    
    using MsgIdType = typename Base::MsgIdType;
    using MsgIdParamType = typename Base::MsgIdParamType;

    // Given the combined bitfield field, retrieve message ID value
    MsgIdType getMsgIdFromField(const Field& field)
    {
        auto id = field.field_packetTypeField().value();

        // Use your code to analyze the presence of the checksum and upate
        // its flag accordingly
        Base::nextLayer().setChecksumExists(false);
        return id;
    }

    // Before forwarding read to the next layer update flags extra transport field in the interface
    template<typename TMsg> 
    static void beforeRead(const Field& field, TMsg& msg)
    {
        msg.transportField_flagField().value() = field.field_flagField().value();
    } 

    // Prepare field value to be written
    template <typename TMsg>
    static void prepareFieldForWrite(MsgIdParamType id, const TMsg& msg, Field& field)
    {
        field.field_packetTypeField().value() = id;
        field.field_flagField().value() = msg.transportField_flagField().value();
    }
};

}

}

}
