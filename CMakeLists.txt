cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

    set (PROJECT_NAME    008_HW_OOP_Templates_DynamicArray)
project (${PROJECT_NAME} LANGUAGES CXX)

    set (CMAKE_CXX_STANDARD           14)
    set (CMAKE_CXX_STANDARD_REQUIRED  ON)

add_executable (${PROJECT_NAME}
    src/main.cpp    inc/main.h
    scr/menu.cpp    inc/menu.h 
	                inc/tmp_safearray.h
)
