cmake_minimum_required(VERSION 3.28)
project(arvoreBinaria)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(arvoreBinaria
        .idea/.gitignore
        .idea/arvoreBinaria.iml
        .idea/modules.xml
        main.c
        t_binarytree.c
        t_binarytree.h)
