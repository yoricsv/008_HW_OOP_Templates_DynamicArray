#pragma once
#ifndef TMP_T_DArr_H
#define TMP_T_DArr_H

#include <iostream>
#include <ctime>
//#include <cassert>


#ifndef USE_RANDOM
    #define USE_INCREMENT
#else
    #ifndef _RANDOM_H_
    #define _RANDOM_H_
        #include <random>
    #endif // _RANDOM_H_
#endif

template <typename T>
class T_DArr
{
private:
          T     * ptrDArr;
          size_t   length;
          size_t   capacity = 0;

    const size_t   MIN_CAP  = 2;

    bool check_bound(size_t position)
    {
        if (0 <= position && position < get_size())
            return true;
        return false;
    }

    T_DArr<T>& mem_alloc(const size_t size)
    {
        if(!capacity)
        {
            if(size <= 0)
                this -> ptrDArr  = nullptr;
            else
            {
                this -> capacity = MIN_CAP + (size * size/2);
                this -> ptrDArr  = new T[capacity];
            }
        }
        else if(capacity < length)
        {
            if(length < capacity * 2)
                capacity *= 2;
            else
                capacity  = capacity * 2 * length / capacity;

            T * ptr_tmp  = new T[capacity];
            for(size_t i = 0; i < get_size(); i++)
                ptr_tmp[i] = ptrDArr[i];
            this -> ptrDArr = ptr_tmp;
            if(ptr_tmp != nullptr)
                delete[] ptr_tmp;
        }
        return *this;
    }
public:
             T_DArr() = default;                                               // DEFAULT CONSTRUCTOR //
    explicit T_DArr(const size_t    size) noexcept;                                    // CONSTRUCTOR //
    explicit T_DArr(const T_DArr &  copyObj) noexcept;                            // COPY CONSTRUCTOR //
    explicit T_DArr(      T_DArr && moveObj) noexcept;                            // MOVE CONSTRUCTOR //
    ~T_DArr(){if(this -> ptrDArr != nullptr) delete[] ptrDArr;}                         // DISTRUCTOR //

     T_DArr& operator = (const T_DArr &  copyObj) noexcept; // COPY ASSIGNMENT OPERATOR (OVERLOAD = ) //
     T_DArr& operator = (      T_DArr && moveObj) noexcept; // MOVE ASSIGNMENT OPERATOR (OVERLOAD = ) //

          T& operator [](size_t index);                    // ARRAY SUBSCRIPT OPERATOR (OVERLOAD [] ) //
    const T& operator [](size_t index) const {return   ptrDArr[index];}
          T& operator * ()             const {return * ptrDArr;}
          T* operator ->()             const {return   ptrDArr;}

    void   a_filling   ();
    void   m_filling   ();

    void   push_front  (      T      value);
    void   push_at     (const size_t index,  T      value);
    void   push_into   (      size_t begin,  size_t end);
    void   push_back   (      T      value);

    void   pop_front   ();
    void   pop_at      (const size_t index);
    void   pop_into    (      size_t begin,  size_t end);
    void   pop_back    ();

    void   print_front ();
    void   print_at    (const size_t index);
    void   print_range (      size_t begin,  size_t end);
    void   print_all   ();
    void   print_back  ();

    bool   isEmpty     () const {return ptrDArr == nullptr;};
    size_t get_size    ();
    void   swap        (      size_t first,  size_t second) noexcept;

    void   erase       ();
};

// CONSTRUCTOR //
template <typename T>
T_DArr<T>::T_DArr(const size_t    size) noexcept    : length (size)
{
    if(size <= 0)
        this -> length = 0;
    else
        this -> length = size;

    mem_alloc(size);
}

// COPY CONSTRUCTOR //
template <typename T>
T_DArr<T>::T_DArr(const T_DArr &  copyObj) noexcept : length (copyObj.length)
{
    if(copyObj.length <= 0)
        this -> length = 0;
    else
        this -> length = copyObj.length;

    if(capacity < get_size())
        mem_alloc(capacity);

    for(size_t i = 0; i < get_size(); i++)
        this -> ptrDArr[i] = copyObj.ptrDArr[i];
}

// MOVE CONSTRUCTOR //
template <typename T>
T_DArr<T>::T_DArr(      T_DArr && moveObj) noexcept : length (moveObj.length)
{
    if(moveObj.length <= 0)
        this -> length = 0;
    else
        this -> length = moveObj.length;

    for(size_t i = 0; i < get_size(); i++)
        this -> ptrDArr[i] = moveObj.ptrDArr[i];

    moveObj.length  = 0;
    moveObj.ptrDArr = nullptr;
}

// COPY ASSIGNMENT OPERATOR (OVERLOAD = ) //
template <typename T>
T_DArr<T>& T_DArr<T>::operator = (const T_DArr & copyObj) noexcept
{
    if (this != &copyObj)
    {
        if(this -> ptrDArr != nullptr)
            delete[] this -> ptrDArr;

        if(copyObj.length <= 0)
            this -> length = 0;
        else
            this -> length = copyObj.length;

        if(capacity < get_size())
            mem_alloc(capacity);

        for(size_t i = 0; i < get_size(); i++)
            this -> ptrDArr[i] = copyObj.ptrDArr[i];
    }
    return *this;
}

// MOVE ASSIGNMENT OPERATOR (OVERLOAD = ) //
template <typename T>
T_DArr<T>& T_DArr<T>::operator = (      T_DArr && moveObj) noexcept
{
    if (this != &moveObj)
    {
        if(this -> ptrDArr != nullptr)
            delete[] this -> ptrDArr;

        if(moveObj.length <= 0)
            this -> length = 0;
        else
            this -> length = moveObj.length;

        for(size_t i = 0; i < get_size(); i++)
            this -> ptrDArr[i] = moveObj.ptrDArr[i];

        moveObj.length  = 0;
        moveObj.ptrDArr = nullptr;
    }
    return *this;
}

// SQUARE BRACKETS (OVERLOAD [] ) //
template <typename T>
T& T_DArr<T>::operator [](size_t index)
{
//    assert(!check_bound(index));
    if (check_bound(index))
        return ptrDArr[index];
    else
    {
        std::cerr << "Out of range! ";
        std::cerr << "Maximum size of your array is ";
        std::cerr << get_size() << std::endl;
        exit(-1);
    }
}

// AUTOMATIC FILLING METHOD //
template <typename T>
void T_DArr<T>::a_filling()
{
#ifndef USE_INCREMENT
    for(size_t i = 0; i < length; i++)
        ptrDArr[i] = (32767 * time(0)) % 47;
    printArray();
#else
    srand((T)(time(0)));
    for (size_t i = 0; i < get_size(); i++)
        ptrDArr[i] = rand() % static_cast<int>(get_size());

    print_all();
#endif
}

// MANUALLY FILLING METHOD //
template <typename T>
void T_DArr<T>::m_filling()
{
    for(size_t i = 0; i < get_size(); i++)
    {
        T value = 0;
        std::cout << "To fill array in, enter your value";
        std::cout << " in DynamicArray["<< i <<"]:"<< std::endl;
        std::cin >> value;
        ptrDArr[i] = value;
    }
    std::cout << "Your array is:\n";

    print_all();
}

// VARIOUS PUSH METHODS //
template <typename T>
void T_DArr<T>::push_front (T value)
{
    if(!get_size())
    {
        mem_alloc(1);
        this -> ptrDArr[0] = value;
    }
    else
    {
        this -> length += 1;
        if(capacity < get_size())
            mem_alloc(capacity);

        for(size_t i = get_size() - 1; get_size() - 1 > 0; i--)
           this -> ptrDArr[i] = ptrDArr[i - 1];
    }
}
template <typename T>
void T_DArr<T>::push_at    (const size_t index, T value)
{
    if (check_bound(index))
        ptrDArr[index] = value;
    else
    {
        std::cerr << "WARRNING! The PUSH function can't do this.\n";
        std::cerr << "\tOut of range! \n";
        std::cerr << "Maximum size of your array is " << get_size() << std::endl;
    }
}
template <typename T>
void T_DArr<T>::push_into  (      size_t begin, size_t end)
{
    if (check_bound(begin) && check_bound(end))
    {
        if(end < begin)
            std::swap(begin, end);

        size_t gap = end - begin;
        this -> length += gap;

        if(capacity < get_size())
            mem_alloc(capacity);

        for(size_t i = get_size() - 1 ; i <= begin; i--)
            this -> ptrDArr[i] = ptrDArr[i - gap];

        T value = 0;
        for(size_t i = begin; i < end; i++)
        {
            std::cout << "You need to fill in " << gap << "position." << std::endl;
            std::cout << "Type value (Press Enter to type next)." << std::endl;
            std::cout << "To left - " << gap-- << std::endl;

            std::cin >> value;

            ptrDArr[i] = value;
        }
    }
    else
    {
        std::cerr << "WARRNING! The PUSH function can't do this.\n";
        std::cerr << "\tOut of range! \n";
        std::cerr << "Maximum size of your array is " << get_size() << std::endl;
    }
}
template <typename T>
void T_DArr<T>::push_back  (T value)
{
    if(!get_size())
    {
        mem_alloc(1);
        this -> ptrDArr[0] = value;
    }
    else
    {
        this -> length += 1;

        if(capacity < get_size())
            mem_alloc(capacity);

        this -> ptrDArr[get_size()] = value;
    }
}

// VARIOUS POP METHODS //
template <typename T>
void T_DArr<T>::pop_front  ()
{
    if(!isEmpty())
    {
        for(size_t i = 0; i < get_size(); i++)
            this -> ptrDArr[i] = ptrDArr[i + 1];
        this -> length--;
        if(!get_size())
        {
            this -> ptrDArr  = nullptr;
            this -> capacity = 0;
        }
    }
    else
        std::cerr << "WARRNING! The POP function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::pop_at     (const size_t index)
{
    if(!isEmpty())
    {
        if (check_bound(index))
        {
            for(size_t i = index; i < get_size(); i++)
                ptrDArr[i] = ptrDArr[i + 1];
            this -> length--;
            if(!get_size())
            {
                this -> ptrDArr  = nullptr;
                this -> capacity = 0;
            }
        }
        else
        {
            std::cerr << "WARRNING! The POP function can't do this.\n";
            std::cerr << "\tOut of range! \n";
            std::cerr << "Maximum size of your array is " << get_size() << std::endl;
        }
    }
    else
        std::cerr << "WARRNING! The POP function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::pop_into   (      size_t begin, size_t end)
{
    if(!isEmpty())
    {
        if (check_bound(begin) && check_bound(end))
        {
            if(begin > end)
                std::swap(begin, end);

            size_t gap = end - begin;

            for(size_t i = begin; i < get_size() - end; i++)
                this -> ptrDArr[i] = ptrDArr[i + gap];

            this -> length -= gap;
            if(!get_size())
            {
                this -> ptrDArr  = nullptr;
                this -> capacity = 0;
            }
        }
        else
        {
            std::cerr << "WARRNING! The POP function can't do this.\n";
            std::cerr << "\tOut of range! \n";
            std::cerr << "Maximum size of your array is " << get_size() << std::endl;
        }
    }
    else
        std::cerr << "WARRNING! The POP function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::pop_back   ()
{
    if(!isEmpty())
    {
        this -> length--;
        if(!get_size())
        {
            this -> ptrDArr  = nullptr;
            this -> capacity = 0;
        }
    }
    else
        std::cerr << "WARRNING! The POP function can't do this. Array is EMPTY!\n";
}

// VARIOUS DISPLAY METHODS //
template <typename T>
void T_DArr<T>::print_front()
{
    if(!isEmpty())
    {
        std::cout << "The first element contains the value is " << ptrDArr[0] << "  \t";
        std::cout << "Address: "<< this << std::endl;
    }
    else
        std::cerr << "WARRNING! The PRINT function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::print_at   (const size_t index)
{
    if (check_bound(index))
    {
        std::cout << "Element [" << index << "] = " << ptrDArr[index] << "  \t";
        std::cout << "Address: "<< this + index << std::endl;
    }
    else
    {
        std::cerr << "WARRNING! The PRINT function can't do this.\n";
        std::cerr << "\tOut of range! \n";
        std::cerr << "Maximum size of your array is " << get_size() << std::endl;
    }
}
template <typename T>
void T_DArr<T>::print_range(      size_t begin,    size_t end)
{
    if(!isEmpty())
    {
        if (check_bound(begin) && check_bound(end))
        {
            if(begin > end)
                std::swap(begin, end);

            for(size_t i = begin; i < end; i++)
            {
                std::cout << "Element [" << i << "] = " << ptrDArr[i] << "  \t";
                std::cout << "Address: "<< this + i << std::endl;
            }
        }
        else
        {
            std::cerr << "WARRNING! The PRINT function can't do this.\n";
            std::cerr << "\tOut of range! \n";
            std::cerr << "Maximum size of your array is " << get_size() << std::endl;
        }
    }
    else
        std::cerr << "WARRNING! The PRINT function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::print_all  ()
{
    if(!isEmpty())
        for (size_t i = 0; i < get_size(); i++)
        {
            std::cout << "Element [" << i << "] = " << ptrDArr[i] << "  \t";
            std::cout << "Address: "<< this + i << std::endl;
        }
    else
        std::cerr << "WARRNING! The PRINT function can't do this. Array is EMPTY!\n";
}
template <typename T>
void T_DArr<T>::print_back ()
{
    if(!isEmpty())
    {
        std::cout << "Element [" << get_size() - 1 << "] = " << ptrDArr[get_size() - 1] << "  \t";
        std::cout << "Address: "<< this + get_size() << std::endl;
    }
    else
        std::cerr << "WARRNING! The PRINT function can't do this. Array is EMPTY!\n";
}

// THE SAME AS STD::SIZEOF METHOD //
template <typename T>
size_t T_DArr<T>::get_size()
{
    if(!isEmpty())
        return this -> length;
    else
        std::cerr << "ERROR! Array is EMPTY! Length is Zero.\n";
    return 0;
}

// THE SAME AS STD::SWAP METHOD //
template <typename T>
void T_DArr<T>::swap       (      size_t first, size_t second) noexcept
{
    if (check_bound(first) && check_bound(second))
    {
        T tmp           = ptrDArr[first];
        ptrDArr[first]  = ptrDArr[second];
        ptrDArr[second] = tmp;
    }
    else
    {
        std::cerr << "WARRNING! The SWAP function can't do this.\n";
        std::cerr << "\tOut of range! \n";
        std::cerr << "Maximum size of your array is " << get_size() << std::endl;
    }
}

// WIPE ARRAY OUT METHOD //
template <typename T>
void T_DArr<T>::erase      ()
{
    if(this -> ptrDArr != nullptr)
        delete[] ptrDArr;
}

#endif // T_DArr_H
