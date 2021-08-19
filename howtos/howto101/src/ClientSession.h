#pragma once

#include <iterator>
#include <vector>

#include "howto101/Interface.h"
#include "howto101/frame/Frame.h"
#include "howto101/input/AllMessages.h"
#include "howto101/options/DefaultOptions.h"
#include "howto101/options/DataViewDefaultOptions.h"

#include "Session.h"

namespace cc_tutorial
{

class ClientSession : public Session
{
    using Base = Session;
public:
    using Base::Base; // Inherit constructors

    // Common interface class for all the messages
    using Message = 
        howto101::Interface<
            comms::option::app::ReadIterator<const std::uint8_t*>, // Polymorphic read
            comms::option::app::WriteIterator<std::back_insert_iterator<std::vector<std::uint8_t> > >, // Polymorphic write
            comms::option::app::IdInfoInterface, // Polymorphic message ID retrieval
            comms::option::app::LengthInfoInterface, // Polymorphic length retrieval
            comms::option::app::NameInterface, // Polymorphic name retrieval
            comms::option::app::Handler<ClientSession> // Polymorphic dispatch        
        >;

    // Protocol options for client
    using ClientProtocolOptions = 
        howto101::options::DefaultOptions;
        
    // Definition of all the used message classes
    using Msg1 = howto101::message::MSG1<Message, ClientProtocolOptions>;
    
    // Handling functions for all the dispatched message objects
    void handle(Msg1& msg);
    void handle(Message& msg);

protected:
    virtual bool startImpl() override final;
    virtual std::size_t processInputImpl(const std::uint8_t* buf, std::size_t bufLen) override final;

private:
    enum CommsStage
    {
        CommsStage_Msg1,
        CommsStage_NumOfValues
    };

    void sendMessage(const Message& msg);
    void doNextStage();
    void sendMsg1();

    // Client specific frame 
    using Frame = 
        howto101::frame::Frame<
            Message,
            howto101::input::AllMessages<Message, ClientProtocolOptions>,
            ClientProtocolOptions
        >;

    Frame m_frame;
    CommsStage m_currentStage = CommsStage_NumOfValues;
};

} // namespace cc_tutorial
