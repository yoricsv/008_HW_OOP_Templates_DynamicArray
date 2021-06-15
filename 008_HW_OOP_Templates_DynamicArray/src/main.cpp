#include <iostream>

#include "main.h"

#ifdef USE_MEMU
extern int prog_state;
extern int action;
#endif

// SET ARRAY SIZE FUNCTION //
size_t set_size()
{
    size_t default_size = 0;

    std::cout << "To create a Dynamic Array, enter its length:" << std::endl;
    std::cin >> default_size;

    return default_size;
}

int main()
{

#ifdef USE_MEMU
    while(true)
    {
        switch(prog_state)
        {
            case(CREATE_ARRAY):
            {
                creation_type();
            }
            break;
            case(AUTO):
            {
#endif
                T_DArr<float> dynArr_1(set_size());
                dynArr_1.a_filling();
                std::cout << std::endl;

                T_DArr<float> dynArr_2(set_size());
                dynArr_2.a_filling();
                std::cout << std::endl;

                T_DArr<float> dynArr_3(set_size());
                dynArr_3.a_filling();
                std::cout << std::endl;


                dynArr_1 = dynArr_2;

                std::cout <<"After COPY assignment "<< std::endl;
                std::cout <<"First array: "<< std::endl;
                dynArr_1.print_all();
                std::cout <<"Second array: "<< std::endl;
                dynArr_2.print_all();


                dynArr_2 = std::move(dynArr_3);

                std::cout <<"After MOVE assignment "<< std::endl;
                std::cout <<"Second array: "<< std::endl;
                dynArr_2.print_all();
                std::cout <<"Third array: "<< std::endl;
                dynArr_3.print_all();

                std::cout << "Dyn Arr is - " << dynArr_2.isEmpty() << std::endl;


#ifndef USE_MENU
                dynArr_1.erase();
                dynArr_2.erase();
#endif

#ifdef USE_MEMU
                action_type(dynArr);
            }
            break;
            case(MANUALLY):
            {
                T_DArr<int> dynArr(set_size());
                dynArr.m_filling();
                action_type(dynArr);
            }
            break;
        }
    }
#endif

    return 0;
}
    // CHRONO OF AUTO FILL ARRAY IN BEGIN //
//    auto begin = std::chrono::high_resolution_clock::now();

//    auto end = std::chrono::high_resolution_clock::now();
//    auto time_took = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
//    std::cout << "Executed in " << time_took.count();
    // CHRONO OF AUTO FILL ARRAY IN END //
