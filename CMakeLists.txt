cmake_minimum_required(VERSION 3.8)
project(ProjectPCA)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Cellule/cellule.h Cellule/cellule.c Liste/node.h Liste/node.c Pile/pile.h Pile/pile.c Cellule/testCellule.c)
add_executable(ProjectPCA ${SOURCE_FILES})

add_subdirectory(Pile)
add_subdirectory(Liste)
add_subdirectory(Cellule)