cmake_minimum_required(VERSION 2.8)
PROJECT(myParserFramework)
SET(LIB_TOKENIZER tokenizer.cpp)
ADD_LIBRARY(tokenizer STATIC ${LIB_TOKENIZER})
SET(CMAKE_CXX_FLAGS "-Wall -std=c++0x -O3")
