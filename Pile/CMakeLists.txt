cmake_minimum_required(VERSION 3.8)
project(TestPile)

set(SOURCE_FILES mainPile.c pile.c pile.h)
add_executable(TestPile ${SOURCE_FILES})