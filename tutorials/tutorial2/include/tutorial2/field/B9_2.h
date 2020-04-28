// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains definition of <b>"B9_2"</b> field.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "tutorial2/field/B9_2Common.h"
#include "tutorial2/field/FieldBase.h"
#include "tutorial2/options/DefaultOptions.h"

namespace tutorial2
{

namespace field
{

/// @brief Scope for all the member fields of
///     @ref B9_2 bitfield.
/// @tparam TOpt Protocol options.
template <typename TOpt = tutorial2::options::DefaultOptions>
struct B9_2Members
{
    /// @brief Definition of <b>"M1"</b> field.
    struct M1 : public
        comms::field::IntValue<
            tutorial2::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::FixedBitLength<12U>,
            comms::option::def::DefaultNumValue<16>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::B9_2MembersCommon::M1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"M2"</b> field.
    /// @see @ref tutorial2::field::B9_2MembersCommon::M2Val
    class M2 : public
        comms::field::EnumValue<
            tutorial2::field::FieldBase<>,
            tutorial2::field::B9_2MembersCommon::M2Val,
            comms::option::def::DefaultNumValue<2>,
            comms::option::def::FixedBitLength<4U>,
            comms::option::def::ValidNumValue<2>,
            comms::option::def::ValidNumValue<5>
        >
    {
        using Base = 
            comms::field::EnumValue<
                tutorial2::field::FieldBase<>,
                tutorial2::field::B9_2MembersCommon::M2Val,
                comms::option::def::DefaultNumValue<2>,
                comms::option::def::FixedBitLength<4U>,
                comms::option::def::ValidNumValue<2>,
                comms::option::def::ValidNumValue<5>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::B9_2MembersCommon::M2Common::name();
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            return tutorial2::field::B9_2MembersCommon::M2Common::valueName(val);
        }
        
        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::value());
        }
        
    };
    
    /// @brief Definition of <b>"M3"</b> field.
    class M3 : public
        comms::field::BitmaskValue<
            tutorial2::field::FieldBase<>,
            comms::option::def::FixedBitLength<8U>,
            comms::option::def::DefaultNumValue<0x81U>,
            comms::option::def::BitmaskReservedBits<0x5EU, 0x0U>
        >
    {
        using Base = 
            comms::field::BitmaskValue<
                tutorial2::field::FieldBase<>,
                comms::option::def::FixedBitLength<8U>,
                comms::option::def::DefaultNumValue<0x81U>,
                comms::option::def::BitmaskReservedBits<0x5EU, 0x0U>
            >;
    public:
        /// @brief Provide names for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///      The generated enum values:
        ///      @li @b BitIdx_B0.
        ///      @li @b BitIdx_B5.
        ///      @li @b BitIdx_B7.
        COMMS_BITMASK_BITS(
            B0=0,
            B5=5,
            B7=7
        );
        
        /// @brief Generates independent access functions for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_ACCESS macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///     The generated access functions are:
        ///      @li @b getBitValue_B0() and @b setBitValue_B0().
        ///      @li @b getBitValue_B5() and @b setBitValue_B5().
        ///      @li @b getBitValue_B7() and @b setBitValue_B7().
        COMMS_BITMASK_BITS_ACCESS(
            B0,
            B5,
            B7
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::B9_2MembersCommon::M3Common::name();
        }
        
        /// @brief Retrieve name of the bit.
        static const char* bitName(BitIdx idx)
        {
            return
                tutorial2::field::B9_2MembersCommon::M3Common::bitName(
                    static_cast<std::size_t>(idx));
        }
        
    };
    
    /// @brief All members bundled in @b std::tuple.
    using All =
        std::tuple<
           M1,
           M2,
           M3
        >;
};

/// @brief Definition of <b>"B9_2"</b> field.
/// @details
///     Some Field Description
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial2::options::DefaultOptions, typename... TExtraOpts>
class B9_2 : public
    comms::field::Bitfield<
        tutorial2::field::FieldBase<>,
        typename B9_2Members<TOpt>::All,
        TExtraOpts...
    >
{
    using Base = 
        comms::field::Bitfield<
            tutorial2::field::FieldBase<>,
            typename B9_2Members<TOpt>::All,
            TExtraOpts...
        >;
public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
    ///     related to @b comms::field::Bitfield class from COMMS library
    ///     for details.
    ///
    ///     The generated types and access functions are:
    ///     @li @b Field_m1 type and @b field_m1() access function -
    ///         for B9_2Members::M1 member field.
    ///     @li @b Field_m2 type and @b field_m2() access function -
    ///         for B9_2Members::M2 member field.
    ///     @li @b Field_m3 type and @b field_m3() access function -
    ///         for B9_2Members::M3 member field.
    COMMS_FIELD_MEMBERS_NAMES(
        m1,
        m2,
        m3
    );
    
    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial2::field::B9_2Common::name();
    }
    
};

} // namespace field

} // namespace tutorial2


