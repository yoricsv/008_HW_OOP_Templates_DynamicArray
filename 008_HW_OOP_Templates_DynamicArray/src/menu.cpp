#include "menu.h"

int prog_state = 0;
int action     = 0;

int creation_type()
{
    unsigned type_of_fill = 0;
    std::cout << "Choose your type to fill it in:" << std::endl;
    std::cout << "\t1 - auto (random):"            << std::endl;
    std::cout << "\t2 - manually:"                 << std::endl;

    std::cin >> type_of_fill;

    switch(type_of_fill)
    {
        case(AUTO):     prog_state = AUTO;     return prog_state; break;
        case(MANUALLY): prog_state = MANUALLY; return prog_state; break;
        default:        creation_type();       return prog_state; break;
    }
}
template<typename T>
void action_type(T_DArr<T> &obj)
{
    std::cout << "\nChoose action:\n";
    std::cout << "\t1  - change some value,"                << std::endl;
    std::cout << "\t2  - exchange the position,\n"          << std::endl;
    std::cout << "\t3  - insert new value at the begin,"    << std::endl;
    std::cout << "\t4  - insert new value at the position," << std::endl;
    std::cout << "\t5  - insert several values between,"    << std::endl;
    std::cout << "\t6  - insert new value to the end,\n"    << std::endl;
    std::cout << "\t7  - delete value at the begin,"        << std::endl;
    std::cout << "\t8  - delete value at the position,"     << std::endl;
    std::cout << "\t9  - delete several values between,"    << std::endl;
    std::cout << "\t10 - delete value to the end,\n"        << std::endl;
    std::cout << "\t11 - get the array size,"               << std::endl;
    std::cout << "\t12 - get info - is the array empty,\n"  << std::endl;
    std::cout << "\t13 - show first item,"                  << std::endl;
    std::cout << "\t14 - show element at the position"      << std::endl;
    std::cout << "\t15 - show the range of items"           << std::endl;
    std::cout << "\t16 - show the array"                    << std::endl;
    std::cout << "\t17 - show last item\n"                  << std::endl;
    std::cout << "\t18 - wipe out the array\n"              << std::endl;
    std::cout << "\t0  - close program"                     << std::endl;

    std::cin >> action;

    switch(action)
    {
        case(CHANGE_VALUE):     change_value (obj); break;
        case(SWAP_VALUES):      swap_items   (obj); break;

        case(PUSH_VALUE_FRONT): insert_front (obj); break;
        case(PUSH_VALUE_AT):    insert_at    (obj); break;
        case(PUSH_VALUE_INTO):  insert_into  (obj); break;
        case(PUSH_VALUE_BACK):  insert_back  (obj); break;

        case(POP_VALUE_FRONT):  remove_front (obj); break;
        case(POP_VALUE_AT):     remove_at    (obj); break;
        case(POP_VALUE_INTO):   remove_into  (obj); break;
        case(POP_VALUE_BACK):   remove_back  (obj); break;

        case(GET_SIZE):         get_size     (obj); break;
        case(CHECK_EMPTY):      empty_check  (obj); break;

        case(OUTPUT_FRONT):     display_front(obj); break;
        case(OUTPUT_ITEM):      display_item (obj); break;
        case(OUTPUT_RANGE):     display_range(obj); break;
        case(OUTPUT_ARRAY):     display_all  (obj); break;
        case(OUTPUT_BACK):      display_back (obj); break;

        case(WIPE_OUT):         erase        (obj); break;

        case(EXIT):             exit(0);            break;

        default:                action_type  (obj); break;
    }
}



template<typename T>
void change_value  (T_DArr<T> &obj)
{
    size_t index = 0;
    int    value = 0;
    std::cout << "First, enter which element do you want to change:" << std::endl;
    std::cout << "After pressing Enter, type the value:" << std::endl;

    std::cin >> index >> value;

    obj[index] = value;

    std::cout << "The item has been changed! New value is:" << std::endl;
    obj.print_at(index);

    action_type(obj);
}
template<typename T>
void swap_items    (T_DArr<T> &obj)
{
    size_t first_index  = 0;
    size_t second_index = 0;
    obj.print_all();
    std::cout << "To swap the data, you need type their indices:" << std::endl;

    std::cin >> first_index  >> second_index;

    obj.swap(first_index, second_index);

    std::cout << "The data has been changed! New value is:" << std::endl;
    obj.print_at(first_index);
    std::cout << std::endl;
    obj.print_at(second_index);

    action_type(obj);
}

template<typename T>
void insert_front  (T_DArr<T> &obj)
{
    int value = 0;
    std::cout << "Type the value what you want to add at the begin:" << std::endl;

    std::cin >> value;

    obj.push_front(value);

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}

template<typename T>
void insert_at     (T_DArr<T> &obj)
{
    size_t index = 0;
    int    value = 0;
    std::cout << "Type the position number where you want to insert the new data," << std::endl;
    std::cout << "after pressing Enter, type the value:" << std::endl;

    std::cin >> index >> value;

    obj.push_at(index, value);

    std::cout << "The array has been changed! New value is:" << std::endl;
    obj.print_all();

    action_type(obj);
}
template<typename T>
void insert_into   (T_DArr<T> &obj)
{
    size_t begin = 0;
    size_t end   = 0;
    obj.print_all();
    std::cout << "Type start position, after pressing Enter, type end position:" << std::endl;
    std::cin >> begin >> end;

    obj.push_into(begin, end);

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}
template<typename T>
void insert_back   (T_DArr<T> &obj)
{
    int value = 0;
    std::cout << "Type the value what you want to add to the end:" << std::endl;
    std::cin >> value;

    obj.push_back(value);

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}

template<typename T>
void remove_front  (T_DArr<T> &obj)
{
    std::cout << "Array before removing the first element:" << std::endl;
    obj.print_all();

    obj.pop_front();

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}
template<typename T>
void remove_at     (T_DArr<T> &obj)
{
    size_t index = 0;
    std::cout << "What the position you want to remove?" << std::endl;
    std::cin >> index;

    obj.pop_at(index);

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}

template<typename T>
void remove_into   (T_DArr<T> &obj)
{
    size_t begin = 0;
    size_t end   = 0;
    obj.print_all();
    std::cout << "Type start position, after pressing Enter, type end position:" << std::endl;
    std::cin >> begin >> end;

    obj.pop_into(begin, end);

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}
template<typename T>
void remove_back   (T_DArr<T> &obj)
{
    std::cout << "Array before removing the last element:" << std::endl;
    obj.print_all();

    obj.pop_back();

    std::cout << "The array has been changed! New array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}

template<typename T>
void get_size      (T_DArr<T> &obj)
{
    std::cout << "The size of Array is - " << obj.get_size() << " elements." << std::endl;

    action_type(obj);
}
template<typename T>
void empty_check   (T_DArr<T> &obj)
{
    if(obj.isEmpty())
        std::cout << "The Array is empty." << std::endl;
    else
        std::cout << "The Array is not empty." << std::endl;

    action_type(obj);
}

template<typename T>
void display_front (T_DArr<T> &obj)
{
    obj.print_front();

    action_type(obj);
}
template<typename T>
void display_item  (T_DArr<T> &obj)
{
    size_t index = 0;
    std::cout << "What's the item do you want to see?" << std::endl;

    std::cin >> index;

    std::cout << "Your element is:" << std::endl;
    obj.print_at(index);

    action_type(obj);
}
template<typename T>
void display_range (T_DArr<T> &obj)
{
    size_t begin = 0;
    size_t end   = 0;
    obj.print_all();
    std::cout << "Type start position, after pressing Enter, type end position:" << std::endl;
    std::cin >> begin >> end;

    std::cout << "Your range is:" << std::endl;
    obj.print_range(begin, end);

    action_type(obj);
}
template<typename T>
void display_all   (T_DArr<T> &obj)
{
    std::cout << "Your Array is:" << std::endl;
    obj.print_all();

    action_type(obj);
}
template<typename T>
void display_back  (T_DArr<T> &obj)
{
    obj.print_back();

    action_type(obj);
}

template<typename T>
void erase         (T_DArr<T> &obj)
{
    char answer;
    std::cout << "Are you seriously? (y/n)" << std::endl;
    std::cin >> answer;

    if(answer == 'y')
    {
        obj.erase();
        std::cout << "The array has been wiped out." << std::endl;
    }
    else
        std::cout << "Congratulations! The array was saved." << std::endl;

    action_type(obj);
}
