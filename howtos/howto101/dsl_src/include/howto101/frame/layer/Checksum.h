#pragma once

#include <limits>

#include "comms/protocol/ChecksumPrefixLayer.h"
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
        comms::protocol::ChecksumPrefixLayer<
        TField,
        comms::protocol::checksum::Crc_16, // Not really used, but the parameter needs to be populated
        TNextLayer,
        TOptions...,
        comms::option::def::ChecksumLayerVerifyBeforeRead,
        comms::option::def::ExtendingClass<Checksum<TField, TNextLayer, TOptions...> >
        >
      {
        // Repeat base type
        using Base =
          comms::protocol::ChecksumPrefixLayer <
          TField,
          comms::protocol::checksum::Crc_16,
          TNextLayer,
          TOptions...,
          comms::option::def::ChecksumLayerVerifyBeforeRead,
          comms::option::def::ExtendingClass<Checksum<TField, TNextLayer, TOptions...> >
          >;

      public:
        // Repeat types defined in the base class (not visible by default)
        using Field = typename Base::Field;

        // Override default way of calculating checksum
        template <typename TMsg, typename TIter>
        static typename Field::ValueType calculateChecksum(const TMsg* msgPtr, TIter& iter, std::size_t len, bool& checksumValid)
        {
          std::cout << "Checksum calculation\n";

          if (msgPtr == nullptr) {
            checksumValid = false;
            return static_cast<typename Field::ValueType>(0);
          }

          checksumValid = true;

          //using calc = comms::protocol::checksum::BasicSum<std::uint8_t>;
          // Iter points to user payload but we don't want that.
          // We want to calculate checksum of header bytes.
          // We have to substract 10 bytes (header size) from iter.
          TIter itr = iter - 6;

          using calc = comms::protocol::checksum::BasicSum<std::uint8_t>;
          calc()(itr, len - 2); // We don't want to include checksum bytes           into calculation
          return static_cast<typename Field::ValueType>(0);
        }

      private:

      };
    }
  }
}
