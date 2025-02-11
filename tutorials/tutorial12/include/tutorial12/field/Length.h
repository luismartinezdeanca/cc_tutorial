// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of <b>"Length"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "tutorial12/field/FieldBase.h"
#include "tutorial12/field/LengthCommon.h"
#include "tutorial12/options/DefaultOptions.h"

namespace tutorial12
{

namespace field
{

/// @brief Definition of <b>"Length"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial12::options::DefaultOptions, typename... TExtraOpts>
struct Length : public
    comms::field::IntValue<
        tutorial12::field::FieldBase<>,
        std::uint8_t,
        TExtraOpts...
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial12::field::LengthCommon::name();
    }
    
};

} // namespace field

} // namespace tutorial12


