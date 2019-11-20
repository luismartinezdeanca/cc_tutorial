#include "Tutorial1ServerSession.h"

#include <iostream>
#include <cassert>

#include "comms/process.h"
#include "comms/iterator.h"

namespace cc_tutorial
{

void Tutorial1ServerSession::handle(Message& msg)
{
    // The statement below uses polymorphic message name and ID retrievals.
    std::cout << "Received message \"" << msg.name() << "\" with ID=" << msg.getId() << std::endl;

    std::vector<std::uint8_t> output;

    // Use polymorphic serialization length calculation to create
    // buffer of the requires size
    output.resize(m_frame.length(msg));

    // Serialize message into the buffer (including framing)
    // The serialization uses polymorphic write functionality.
    auto writeIter = &output[0];
    auto es = m_frame.write(msg, writeIter, output.size());
    if (es != comms::ErrorStatus::Success) {
        assert(!"Write operation failed unexpectedly");
        return;
    }

    // writeIter has been advanced, check that it reached end of the allocated buffer.
    assert(output.size() == static_cast<std::size_t>(std::distance(&output[0], writeIter)));

    // Send (re)serialized message back
    sendOutput(&output[0], output.size());
}

std::size_t Tutorial1ServerSession::processInputImpl(const std::uint8_t* buf, std::size_t bufLen)
{
    // Process reported input, create relevant message objects and
    // dispatch all the created messages
    // to this object for handling (handle() member function will be called)
    return comms::processAllWithDispatch(buf, bufLen, m_frame, *this);
}

SessionPtr Session::createServer(boost::asio::io_service& io)
{
    return SessionPtr(new Tutorial1ServerSession(io));
}

} // namespace cc_tutorial
