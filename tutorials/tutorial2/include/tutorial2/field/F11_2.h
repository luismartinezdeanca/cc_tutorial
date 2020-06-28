// Generated by commsdsl2comms v3.4.2

/// @file
/// @brief Contains definition of <b>"Field 11_2"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "tutorial2/field/F11_2Common.h"
#include "tutorial2/field/FieldBase.h"
#include "tutorial2/options/DefaultOptions.h"

namespace tutorial2
{

namespace field
{

/// @brief Definition of <b>"Field 11_2"</b> field.
/// @see @ref tutorial2::field::F11_2Val
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial2::options::DefaultOptions, typename... TExtraOpts>
class F11_2 : public
    comms::field::EnumValue<
        tutorial2::field::FieldBase<>,
        tutorial2::field::F11_2Val,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<0, 2>
    >
{
    using Base = 
        comms::field::EnumValue<
            tutorial2::field::FieldBase<>,
            tutorial2::field::F11_2Val,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<0, 2>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial2::field::F11_2Common::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return tutorial2::field::F11_2Common::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace tutorial2


