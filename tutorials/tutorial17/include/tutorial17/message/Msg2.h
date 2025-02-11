// Generated by commsdsl2comms v3.6.4

/// @file
/// @brief Contains definition of <b>"Message 2"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"
#include "comms/field/String.h"
#include "comms/options.h"
#include "tutorial17/MsgId.h"
#include "tutorial17/field/FieldBase.h"
#include "tutorial17/message/Msg2Common.h"
#include "tutorial17/options/DefaultOptions.h"

namespace tutorial17
{

namespace message
{

/// @brief Fields of @ref Msg2.
/// @tparam TOpt Extra options
/// @see @ref Msg2
/// @headerfile "tutorial17/message/Msg2.h"
template <typename TOpt = tutorial17::options::DefaultOptions>
struct Msg2Fields
{
    /// @brief Scope for all the member fields of
    ///     @ref F1 string.
    struct F1Members
    {
        /// @brief Definition of <b>"Length"</b> field.
        struct Length : public
            comms::field::IntValue<
                tutorial17::field::FieldBase<>,
                std::uint8_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return tutorial17::message::Msg2FieldsCommon::F1MembersCommon::LengthCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F1"</b> field.
    class F1 : public
        comms::field::String<
            tutorial17::field::FieldBase<>,
            typename TOpt::message::Msg2Fields::F1,
            comms::option::def::SequenceSerLengthFieldPrefix<typename F1Members::Length>
        >
    {
        using Base = 
            comms::field::String<
                tutorial17::field::FieldBase<>,
                typename TOpt::message::Msg2Fields::F1,
                comms::option::def::SequenceSerLengthFieldPrefix<typename F1Members::Length>
            >;
    public:
        /// @brief Default constructor
        F1()
        {
            static const char Str[] = "hello";
            static const std::size_t StrSize = std::extent<decltype(Str)>::value;
            Base::value() = typename Base::ValueType(&Str[0], StrSize - 1);
        }
        
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial17::message::Msg2FieldsCommon::F1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref F2 optional.
    struct F2Members
    {
        /// @brief Definition of <b>"F2"</b> field.
        struct Field : public
            comms::field::IntValue<
                tutorial17::field::FieldBase<>,
                std::uint16_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return tutorial17::message::Msg2FieldsCommon::F2MembersCommon::FieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F2"</b> field.
    /// @details
    ///     The field exists only when B1 in interface flags is set.
    struct F2 : public
        comms::field::Optional<
            typename F2Members::Field,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial17::message::Msg2FieldsCommon::F2Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        F1,
        F2
    >;
};

/// @brief Definition of <b>"Message 2"</b> message class.
/// @details
///     See @ref Msg2Fields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "tutorial17/message/Msg2.h"
template <typename TMsgBase, typename TOpt = tutorial17::options::DefaultOptions>
class Msg2 : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<tutorial17::MsgId_M2>,
        comms::option::def::FieldsImpl<typename Msg2Fields<TOpt>::All>,
        comms::option::def::MsgType<Msg2<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<tutorial17::MsgId_M2>,
            comms::option::def::FieldsImpl<typename Msg2Fields<TOpt>::All>,
            comms::option::def::MsgType<Msg2<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_f1 index, @b Field_f1 type and @b field_f1() access fuction
    ///         for @ref Msg2Fields::F1 field.
    ///     @li @b FieldIdx_f2 index, @b Field_f2 type and @b field_f2() access fuction
    ///         for @ref Msg2Fields::F2 field.
    COMMS_MSG_FIELDS_NAMES(
        f1,
        f2
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return tutorial17::message::Msg2Common::name();
    }
    
    /// @brief Custom read functionality
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        doRefresh(); // Update mode according to flags in the interface
        return Base::doRead(iter, len);
    }
     
    // @brief Custom refresh functionality
    bool doRefresh()
    {
        bool updated = Base::doRefresh(); // Don't forget default refresh functionality
    
        auto expF2Mode = comms::field::OptionalMode::Missing;
        if (Base::transportField_flags().getBitValue_B1()) {
            expF2Mode = comms::field::OptionalMode::Exists;
        }
    
        if (field_f2().getMode() == expF2Mode) {
            return updated;
        }
    
        field_f2().setMode(expF2Mode);
        return true;
    }
    
};

} // namespace message

} // namespace tutorial17


