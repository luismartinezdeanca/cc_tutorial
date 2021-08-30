#pragma once

#include <limits>

#include "comms/protocol/ChecksumLayer.h"
#include "comms/options.h"

#include "howto101/MsgId.h"

#include <iostream>

namespace howto101
{

namespace frame
{

namespace layer
{

struct CustomChecksum
{
    template <typename TIter>
    std::uint64_t operator()(TIter& iter, std::size_t len) const
    {
        // TODO: proper calculation
        std::advance(iter, len);
        return 0xdeadbeef;
    }

    template <typename TIter>
    static std::uint64_t specialChecksum(TIter& iter, std::size_t len)
    {
        // TODO: proper calculation
        std::advance(iter, len);
        return 0xfeebdaed;
    }
};

/// @brief Customizing the ChecksumLayer
template<typename TField, typename TNextLayer, typename... TOptions>
class Checksum : public
    comms::protocol::ChecksumLayer<
    TField,
    CustomChecksum, 
    TNextLayer,
    TOptions...,
    comms::option::def::ChecksumLayerVerifyBeforeRead,
    comms::option::def::ExtendingClass<Checksum<TField, TNextLayer, TOptions...> >
    >
{
  // Repeat base type
  using Base =
      comms::protocol::ChecksumLayer <
          TField,
          CustomChecksum, 
          TNextLayer,
          TOptions...,
          comms::option::def::ChecksumLayerVerifyBeforeRead,
          comms::option::def::ExtendingClass<Checksum<TField, TNextLayer, TOptions...> >
      >;

public:
    // Repeat types defined in the base class (not visible by default)
    using Field = typename Base::Field;

    // Override the default doRead() functionality,
    // See the signature in the documentation:
    // https://commschamp.github.io/comms_doc/classcomms_1_1protocol_1_1ChecksumLayer.html
    template<
        typename TMsg , 
        typename TIter , 
        typename TNextLayerReader, 
        typename... TExtraValues>
    comms::ErrorStatus doRead(
        Field& field, 
        TMsg& msg, 
        TIter& iter, 
        std::size_t size, 
        TNextLayerReader&& nextLayerReader, 
        TExtraValues... extraValues)
    {
        assert(msg); // message object has been created

        bool hasChecksum = msg->getId() != howto101::MsgId_MSG1PacketType;
        
        if (hasChecksum) {
            // Perform the read
            return Base::doRead(field, msg, iter, size, std::forward<TNextLayerReader>(nextLayerReader), extraValues...);
        }

        // Skip the read of current layer and forward it no the next
        // The signature is the same as read() operation of the layer
        return nextLayerReader.read(msg, iter, size, extraValues...);
    }

    template<
        typename TMsg, 
        typename TIter, 
        typename TNextLayerWriter>
    comms::ErrorStatus doWrite(
        Field& field, 
        const TMsg& msg, 
        TIter& iter, 
        std::size_t size, 
        TNextLayerWriter&& nextLayerWriter) const
    {
        // TODO: Analyze message ID and decide whether to have the checksum
        auto id = msg.getId();
        static_cast<void>(id);
        bool hasChecksum = id != howto101::MsgId_MSG1PacketType;
        if (hasChecksum) {
            return Base::doWrite(field, msg, iter, size, std::forward<TNextLayerWriter>(nextLayerWriter));
        }

        // Skip the read of current layer and forward it no the next
        // The signature is the same as write() operation of the layer
        return nextLayerWriter.write(msg, iter, size);
    }

    template <typename TMsg>
    std::size_t doFieldLength(const TMsg& msg) const
    {
        // TODO: Analyze message ID and decide whether to have the checksum
        auto id = msg.getId();
        static_cast<void>(id);
        bool hasChecksum = id != howto101::MsgId_MSG1PacketType;
        if (hasChecksum) {
            return Base::doFieldLength(msg);
        }

        return 0U;
    }

    template <typename TMsg, typename TIter>
    typename Field::ValueType calculateChecksum(
        const TMsg* msg,
		TIter& iter,
		std::size_t len,
		bool& checksumValid) const
    {
        assert(msg != nullptr); // Message object must exist
        auto id = msg->getId();
        assert(id != howto101::MsgId_MSG1PacketType);

        if (id != howto101::MsgId_MSG2PacketType) {
            // Invoke default calculation
            return Base::calculateChecksum(msg, iter, len, checksumValid);
        }

        // Use special calculation for Msg2 only
        checksumValid = true;
        return CustomChecksum::specialChecksum(iter, len);
    }
};

}

}

}
