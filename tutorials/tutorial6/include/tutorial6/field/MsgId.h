// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of <b>"MsgId"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "tutorial6/MsgId.h"
#include "tutorial6/field/FieldBase.h"
#include "tutorial6/field/MsgIdCommon.h"
#include "tutorial6/options/DefaultOptions.h"

namespace tutorial6
{

namespace field
{

/// @brief Definition of <b>"MsgId"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial6::options::DefaultOptions, typename... TExtraOpts>
class MsgId : public
    comms::field::EnumValue<
        tutorial6::field::FieldBase<>,
        tutorial6::MsgId,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<1, 3>
    >
{
    using Base = 
        comms::field::EnumValue<
            tutorial6::field::FieldBase<>,
            tutorial6::MsgId,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<1, 3>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial6::field::MsgIdCommon::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return tutorial6::field::MsgIdCommon::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace tutorial6


