// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of all client input messages bundle.

#pragma once

#include <tuple>
#include "tutorial1/message/Msg1.h"
#include "tutorial1/message/Msg2.h"
#include "tutorial1/options/DefaultOptions.h"

namespace tutorial1
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = tutorial1::options::DefaultOptions>
using ClientInputMessages =
    std::tuple<
        tutorial1::message::Msg1<TBase, TOpt>,
        tutorial1::message::Msg2<TBase, TOpt>
    >;

} // namespace input

} // namespace tutorial1


