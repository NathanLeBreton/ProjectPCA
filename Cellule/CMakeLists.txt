cmake_minimum_required(VERSION 3.8)
project(TestCellule)

set(SOURCE_FILES testCellule.c ../Liste/node.h ../Liste/node.c ../Pile/pile.h ../Pile/pile.c cellule.h cellule.c )
add_executable(TestCellule ${SOURCE_FILES})