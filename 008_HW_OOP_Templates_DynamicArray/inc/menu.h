#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib> // for exit()
#include <chrono>

#include "tmp_safearray.h"


enum PROG_STATE
{
    CREATE_ARRAY,
    AUTO,
    MANUALLY
};
enum ACTION
{
    CHANGE_VALUE = 1,
    SWAP_VALUES,
    PUSH_VALUE_FRONT,
    PUSH_VALUE_AT,
    PUSH_VALUE_INTO,
    PUSH_VALUE_BACK,
    POP_VALUE_FRONT,
    POP_VALUE_AT,
    POP_VALUE_INTO,
    POP_VALUE_BACK,
    GET_SIZE,
    CHECK_EMPTY,
    OUTPUT_FRONT,
    OUTPUT_ITEM,
    OUTPUT_RANGE,
    OUTPUT_ARRAY,
    OUTPUT_BACK,
    WIPE_OUT,
    EXIT = 0
};

int  creation_type ();
template<typename T>
void action_type   (T_DArr<T> &obj);


template<typename T>
void change_value  (T_DArr<T> &obj);
template<typename T>
void swap_items    (T_DArr<T> &obj);
template<typename T>
void insert_front  (T_DArr<T> &obj);
template<typename T>
void insert_at     (T_DArr<T> &obj);
template<typename T>
void insert_into   (T_DArr<T> &obj);
template<typename T>
void insert_back   (T_DArr<T> &obj);

template<typename T>
void remove_front  (T_DArr<T> &obj);
template<typename T>
void remove_at     (T_DArr<T> &obj);
template<typename T>
void remove_into   (T_DArr<T> &obj);
template<typename T>
void remove_back   (T_DArr<T> &obj);

template<typename T>
void get_size      (T_DArr<T> &obj);
template<typename T>
void empty_check   (T_DArr<T> &obj);

template<typename T>
void display_front (T_DArr<T> &obj);
template<typename T>
void display_item  (T_DArr<T> &obj);
template<typename T>
void display_range (T_DArr<T> &obj);
template<typename T>
void display_all   (T_DArr<T> &obj);
template<typename T>
void display_back  (T_DArr<T> &obj);

template<typename T>
void erase         (T_DArr<T> &obj);

#endif // MENU_H
