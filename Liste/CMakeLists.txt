cmake_minimum_required(VERSION 3.8)
project(TestListe)

set(SOURCE_FILES mainNode.c node.h node.c)
add_executable(TestListe ${SOURCE_FILES})