cmake_minimum_required(VERSION 3.23)
project(AED1_2UFP C)

set(CMAKE_C_STANDARD 99)

include_directories(libs_src)
include_directories(lp)
include_directories(tp)

add_executable(AED1_2UFP main.c lp/aed1_00.c lp/aed1_00.h libs_src/lib_util.h libs_src/lib_util.c libs_src/lib_stats.c libs_src/lib_stats.h lp/aed1_02.c
        lp/aed1_02.h lp/aed1_03.c lp/aed1_04.c lp/aed1_05.c teste_estudo/teste_estudo.c teste_estudo/teste_estudo.h teste_estudo/teste_estudo2.c
        lp/aed1_06.c lp/aed1_07.c)
