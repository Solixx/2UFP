cmake_minimum_required(VERSION 3.23)
project(LP1_2UFP C)

set(CMAKE_C_STANDARD 99)

add_executable(LP1_2UFP main.c tp/tp01.c tp/tp01.h lp/pr01.c tp/tp02.c tp/tp02.h lp/pr02.c lp/pr02.h tp/tp03.c lp/pr03.c tp/tp04.c lp/pr04.c tp/tp05.c
        lp/pr05.c tp/tp06.c testes/testes.c lp/pr06.c lp/pr06.h lp/pr07.c)
