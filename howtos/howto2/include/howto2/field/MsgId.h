// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of <b>"MsgId"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "howto2/MsgId.h"
#include "howto2/field/FieldBase.h"
#include "howto2/field/MsgIdCommon.h"
#include "howto2/options/DefaultOptions.h"

namespace howto2
{

namespace field
{

/// @brief Definition of <b>"MsgId"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = howto2::options::DefaultOptions, typename... TExtraOpts>
class MsgId : public
    comms::field::EnumValue<
        howto2::field::FieldBase<>,
        howto2::MsgId,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<1, 4>
    >
{
    using Base = 
        comms::field::EnumValue<
            howto2::field::FieldBase<>,
            howto2::MsgId,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<1, 4>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return howto2::field::MsgIdCommon::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return howto2::field::MsgIdCommon::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace howto2


