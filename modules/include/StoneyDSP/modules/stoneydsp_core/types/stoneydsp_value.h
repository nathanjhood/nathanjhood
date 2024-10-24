/***************************************************************************//**
 * @file stoneydsp_value.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 ******************************************************************************/

#pragma once

#define __STONEYDSP_CORE_TYPES_VALUE_H__

namespace StoneyDSP
{
namespace Core
{
namespace Types
{
/**
 * @brief The 'Value' class.
 *
 * @tparam T
 */
template <class T>
class Value
{
public:
    //==========================================================================
    //  CONSTRUCTORS
    //==========================================================================

    /** Default-Constructor. */
    inline Value() : value{ T(0.0) }
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        //*this = value;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    };

    /** Initialized Constructor. */
    inline explicit Value(T initialValue) : value{ initialValue }
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        //*this = initialValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /** Initialized Constructor. */
    inline explicit Value(T* initialValue) : value{ *initialValue }
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        //*this = initialValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /** Copy Constructor. */
    inline explicit Value(Value<T>& newValue) : value{ T(0.0) }
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /** Copy Constructor (const). */
    inline explicit Value(const Value<T>& newValue) : value{ T(0.0) }
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /** Move Constructor. */
    inline explicit Value(Value<T>&& otherValue) noexcept : value{ T(0.0) }
    {
        *this = otherValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /** Deconstructor. */
    inline ~Value() noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;

        if (value == T(0.0))
        {
            std::cout << this << " - " << typeid(*this).name() << " - Final Value = 0" << std::endl;
        }

        else
        {
            std::cout << this << " - " << typeid(*this).name() << " - Final Value = " << value << std::endl;

            value = T(0.0);
        }

        std::cout << this << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //==========================================================================

    /** Copy Assignment Operator [=]. */
    inline Value<T>& operator=(Value<T>& newValue)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        //* Performs no operation if you try to assign the object to itself. */
        if (this == &newValue)
        {
            return *this;
        }


        else //(value != newValue.value)
        {
            // Free the resource
            value = T(0.0);

            // Copy the data from the source object.
            value = newValue.value;
        }

        return *this;
    }

    /** Copy Assignment Operator (const) [=]. */
    inline Value<T>& operator=(const Value<T>& newValue)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        //* Performs no operation if you try to assign the object to itself. */
        if (this == &newValue)
        {
            return *this;
        }


        else //(value != newValue.value)
        {
            // Free the resource
            value = T(0.0);

            // Copy the data from the source object.
            value = newValue.value;
        }

        return *this;
    }

    /** Move Assignment Operator [=]. */
    inline Value<T>& operator=(Value<T>&& otherValue) noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;

        if (this == &otherValue)
        {
            std::cout << " - Move failed!" << std::endl;
            std::cout << std::endl;

            return *this;
        }

        // Performs no operation if you try to assign the object to itself.
        else //(&otherValue != this)
        {
            // Free the resource
            value = T(0.0);

            // Copy the data from the source object.
            value = otherValue.value;

            // Release the data from the source object so that
            // the destructor does not free the memory multiple times.
            otherValue.value = T(0.0);

            std::cout << " - Move successfull!" << std::endl;
            std::cout << std::endl;
        }

        return *this;
    }

    //==========================================================================
    //  BINARY ARITHMETIC OPERATORS
    //==========================================================================

    /** Addition Assignment Operator [+=]. */
    inline virtual Value<T>& operator+=(const Value<T>& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator+=(const Value<T>& rhs) with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " += " << rhs.value << " = ";

        value = value + rhs.value; // Actual addition of rhs to *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Subtraction Assignment Operator [-=]. */
    inline Value<T>& operator-=(const Value<T>& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator-=(const Value<T>& rhs) with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " -= " << rhs.value << " = ";

        value = value - rhs.value; // Actual subtraction of rhs from *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Multiplication Assignment Operator [*=]. */
    inline Value& operator*=(const Value& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator*=(const Value& rhs) with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " *= " << rhs.value << " = ";

        value = value * rhs.value; // Actual multiplication of rhs with *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Division Assignment Operator [/=]. */
    inline Value& operator/=(const Value& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator/=(const Value& rhs) with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " /= " << rhs.value << " = ";

        value = value / rhs.value; // Actual division of *this by rhs.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    //==========================================================================
    //  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
    //==========================================================================

    /** Addition Allocation Operator [+]. */
    template <typename Type>
    friend inline Value<Type> operator+(Value<Type> lhs, const Value<Type>& rhs) // passing lhs by value helps optimize chained a+b+c, otherwise, both parameters may be const references
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called operator+(Value<Type> lhs, const Value<Type>& rhs) with address " << &rhs << " = " << rhs.value << std::endl;

        lhs += rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /** Subtraction Allocation Operator [-]. */
    template <typename Type>
    friend inline Value<Type> operator-(Value<Type> lhs, const Value<Type>& rhs) // passing lhs by value helps optimize chained a-b-c, otherwise, both parameters may be const references
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called operator-(Value<Type> lhs, const Value<Type>& rhs) with address " << &rhs << " = " << rhs.value << std::endl;

        lhs -= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /** Multiplication Allocation Operator [*]. */
    template <typename Type>
    friend inline Value operator*(Value lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called operator*(Value lhs, const Value& rhs) with address " << &rhs << " = " << rhs.value << std::endl;

        lhs *= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /** Division Allocation Operator [/]. */
    template <typename Type>
    friend inline Value operator/(Value lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called operator/(Value lhs, const Value& rhs) with address " << &rhs << " = " << rhs.value << std::endl;

        lhs /= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    //==========================================================================
    //  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
    //==========================================================================

    /** Equality Comparison Operator [==]. */
    template <typename Type>
    friend inline bool operator==(const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Equality Comparison Operator [==] with address " << &rhs << " = " << rhs.value << std::endl;

        return (lhs.value == rhs.value) ? true : false; // do actual comparison
    }

    /** Inequality Comparison Operator [!=]. */
    template <typename Type>
    friend inline bool operator!=(const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Inequality Comparison Operator [!=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator==(lhs, rhs);
    }

    /** Less-Than Comparison Operator [<]. */
    template <typename Type>
    friend inline bool operator< (const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Less-Than Comparison Operator [<] with address " << &rhs << " = " << rhs.value << std::endl;

        return (lhs.value < rhs.value) ? true : false; // do actual comparison
    }

    /** Greater-Than Comparison Operator [>]. */
    template <typename Type>
    friend inline bool operator> (const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than Comparison Operator [>] with address " << &rhs << " = " << rhs.value << std::endl;

        return  operator< (rhs, lhs);
    }

    /** Less-Than or Equal-To Comparison Operator [<=]. */
    template <typename Type>
    friend inline bool operator<=(const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Less-Than or Equal-To Comparison Operator [<=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator> (lhs,rhs);
    }

    /** Greater-Than or Equal-To Comparison Operator [>=]. */
    template <typename Type>
    friend inline bool operator>=(const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than or Equal-To Comparison Operator [>=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator< (lhs,rhs);
    }

    //==========================================================================
    //  TYPE CONVERSION OPERATORS
    //==========================================================================

    /** Conversion Operator int(). */
    inline explicit operator int() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator int()" << std::endl;
        std::cout << std::endl;

        return int(*this);
    }

    /** Conversion Operator float(). */
    inline explicit operator float() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator float()" << std::endl;
        std::cout << std::endl;

        return float(*this);
    }

    /** Conversion Operator double(). */
    inline explicit operator double() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called operator double()" << std::endl;
        std::cout << std::endl;

        return double(*this);
    }

    //==========================================================================
    //  ACCESSOR FUNCTIONS
    //==========================================================================

    /** Assertions to check Constructor succeeded */
    inline void assertion()
    {
        assert(this != nullptr);
        std::cout << this << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    /** Runs and prints a set of boolean checks on this variable. */
    template <typename Type>
    friend inline void booleanChecks(const Value& lhs, const Value& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Boolean checks:" << std::endl;
        std::cout << std::endl;
        std::cout << "(value < "  << rhs.value << ") = " << (lhs < rhs) << std::endl;
        std::cout << "(value > "  << rhs.value << ") = " << (lhs > rhs) << std::endl;
        std::cout << "(value <= " << rhs.value << ") = " << (lhs <= rhs) << std::endl;
        std::cout << "(value >= " << rhs.value << ") = " << (lhs >= rhs) << std::endl;
        std::cout << "(value == " << rhs.value << ") = " << (lhs == rhs) << std::endl;
        std::cout << "(value != " << rhs.value << ") = " << (lhs != rhs) << std::endl;
        std::cout << std::endl;
    }

    /** Describes the details of this Value instance. */
    inline void describe_Value(const Value<T>& value)
    {
        std::cout << "describe_Value(const Value<T>& value)" << std::endl;
        std::cout << std::endl;
        std::cout << value.name() << std::endl;
        std::cout << &value << std::endl;
        std::cout << std::endl;
    }

    /** Prints information about this variable. */
    inline void info()
    {
        std::cout << this << " - " << typeid(*this).name() << "info()" << std::endl;
        std::cout << std::endl;
        std::cout << this << " - name - " << typeid(*this).name() << std::endl;
        // std::cout << this << " - raw name - " << typeid(*this).raw_name() << std::endl;
        std::cout << this << " - hash code - " << typeid(*this).hash_code() << std::endl;
        std::cout << this << " - this = " << this << std::endl;
        std::cout << this << " - *this = " << *this << std::endl;
        std::cout << this << " - size in bytes = " << sizeof(*this) << std::endl;
        std::cout << std::endl;
        std::cout << this << " - member type - " << typeid(value).name() << std::endl;
        // std::cout << this << " - member raw name - " << typeid(value).raw_name() << std::endl;
        std::cout << this << " - member hash code - " << typeid(value).hash_code() << std::endl;
        std::cout << this << " - member value = " << value << std::endl;
        std::cout << this << " - member &value = " << &value << std::endl;
        std::cout << this << " - member size in bytes = " << sizeof(value) << std::endl;
        std::cout << std::endl;
    }

    /** Prints information about this variable to Terminal. */
    template <typename Type>
    friend inline std::ostream& operator<<(std::ostream& ostream, Value& source)
    {
        ostream << source.value;

        return ostream;
    }

    /** Prints information about this variable to Terminal. */
    template <typename Type>
    friend inline std::istream& operator>>(std::istream& istream, Value& source)
    {
        if(source)
        istream.setstate(std::ios::failbit);

        return istream;
    }

    //==========================================================================
    //  DATA MEMBERS
    //==========================================================================

    /** Value. */
    T value {};
};

} // namespace Types
} // namespace Core
} // namespace StoneyDSP
