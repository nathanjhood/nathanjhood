/**
 * @file stoneydsp_unique_ptr.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#define __STONEYDSP_CORE_MEMORY_UNIQUEPTR_H__

namespace StoneyDSP
{
namespace Core
{
namespace Memory
{
template<typename Type>
class unique_ptr
{
    Type* ptr;

public:
    //==========================================================================
    /** Default Constructor. */
    inline unique_ptr() : ptr(nullptr)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Initialized Constructor. **/
    inline unique_ptr(Type* source) : ptr(source)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &source << " = " << source << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Move Constructor. */
    inline unique_ptr(unique_ptr<Type>&& source) : ptr()  // note the rvalue reference
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &source << " = " << source << "!" << std::endl;

        // Assign the class data members from the source object to the
        // object that is being constructed:
        ptr = source.ptr;

        // Assign the data members of the source object to default values.
        // This prevents the destructor from freeing resources (such as memory)
        // multiple times:
        source.ptr = nullptr;

        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Destructor. */
    inline ~unique_ptr()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;

        ptr = nullptr;
        delete ptr;

        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    void assertion()
    {
        assert(this->ptr != nullptr);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    //==========================================================================
    /** Assignment operator [MOVE]. */
    unique_ptr& operator=(unique_ptr<Type>&& source) noexcept  // note the rvalue reference
    {
        if (&source != this)    // beware of self-assignment
        {
            ptr = nullptr;         // release the old resource

            ptr = source.ptr;   // acquire the new resource
            source.ptr = nullptr;
        }

        return *this;
    }

    //==========================================================================
    Type* operator->();

    const Type* operator->() const;

    Type& operator*();

    const Type& operator*() const;

    inline friend std::ostream& operator<<(std::ostream& ostream, unique_ptr<Type>& source)
    {
        ostream << source.operator->();

        return ostream;
    }

    inline friend std::istream& operator>>(std::istream& istream, unique_ptr<Type>& source)
    {
        if(source.operator->() != nullptr)
            istream.setstate(std::ios::failbit);

        return istream;
    }

    // __DECLARE_NON_COPYABLE(unique_ptr)

    /** Copy-Construct a new 'unique_ptr' object. */
    unique_ptr (const unique_ptr&) = delete;
    /**
     * @brief Move operator [=].
     *
     * @return unique_ptr&
     */
    unique_ptr& operator= (const unique_ptr&) = delete;
};

//==============================================================================
template<typename Type>
inline Type* unique_ptr<Type>::operator->()
{
    return ptr;
}

template<typename Type>
inline const Type* unique_ptr<Type>::operator->() const
{
    return ptr;
}

template<typename Type>
inline Type& unique_ptr<Type>::operator*()
{
    return *ptr;
}

template<typename Type>
inline const Type& unique_ptr<Type>::operator*() const
{
    return *ptr;
}

//==============================================================================

/** Make a unique_ptr */
template <class Type, class... Types>
unique_ptr<Type> make_unique(Types&&... Args)
{
    return unique_ptr<Type> (new Type(std::forward<Types>(Args)...));
}

} // namespace Types
} // namespace Core
} // namespace StoneyDSP
