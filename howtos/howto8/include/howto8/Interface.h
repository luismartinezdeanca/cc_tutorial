// Generated by commsdsl2comms v3.6.2

/// @file
/// @brief Contains definition of <b>"Interface"</b> interface class.

#pragma once

#include <tuple>
#include "comms/Message.h"
#include "comms/options.h"
#include "howto8/InterfaceCommon.h"
#include "howto8/MsgId.h"
#include "howto8/field/FieldBase.h"
#include "howto8/field/Flags.h"

namespace howto8
{

/// @brief Extra transport fields of @ref Interface interface class.
/// @see @ref Interface
/// @headerfile "howto8/Interface.h"
struct InterfaceFields
{
    /// @brief Definition of <b>"Flags"</b> field.
    using Flags =
        howto8::field::Flags<
            howto8::options::DefaultOptions
        >;
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags
    >;
};

/// @brief Definition of <b>"Interface"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile "howto8/Interface.h"
template <typename... TOpt>
class Interface : public
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<howto8::MsgId>,
        comms::option::def::ExtraTransportFields<InterfaceFields::All>
    >
{
    using Base =
        comms::Message<
            TOpt...,
            comms::option::def::BigEndian,
            comms::option::def::MsgIdType<howto8::MsgId>,
            comms::option::def::ExtraTransportFields<InterfaceFields::All>
        >;
public:
    /// @brief Allow access to extra transport fields.
    /// @details See definition of @b COMMS_MSG_TRANSPORT_FIELDS_NAMES macro
    ///     related to @b comms::Message class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b TransportField_flags type and @b transportField_flags() function for
    ///         @ref InterfaceFields::Flags field.
    COMMS_MSG_TRANSPORT_FIELDS_NAMES(
        flags
    );
};

} // namespace howto8


