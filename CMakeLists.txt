cmake_minimum_required(VERSION 3.23)
project(Swiss_Bank C)

set(CMAKE_C_STANDARD 11)

add_executable(Swiss_Bank Ncc_Bank.h Ncc_Bank_Fun.h Ncc_Bank.c)
