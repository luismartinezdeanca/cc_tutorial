#pragma once

#include <limits>

#include "comms/protocol/ChecksumLayer.h"
#include "comms/options.h"
#include "comms/protocol/checksum/BasicSum.h"
#include "comms/protocol/checksum/Crc.h"

#include <iostream>

namespace howto101
{

namespace frame
{

namespace layer
{
/// @brief Customizing the ChecksumLayer
template<typename TField, typename TNextLayer, typename... TOptions>
class Checksum : public
    comms::protocol::ChecksumLayer<
    TField,
    comms::protocol::checksum::BasicSum<std::uint64_t>, 
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
          comms::protocol::checksum::BasicSum<std::uint64_t>, 
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
        if (m_checksumExists) {
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
        bool hasChecksum = false;
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
        bool hasChecksum = false;
        if (hasChecksum) {
            return Base::doFieldLength(msg);
        }

        return 0U;
    }

    // Allow update of the flags from outer layers
    void setChecksumExists(bool value)
    {
        m_checksumExists = value;
    }

private:
    bool m_checksumExists = true;
};

}

}

}
