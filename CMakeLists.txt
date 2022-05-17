cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled src/main.cpp src/Produkt.cpp headers/Produkt.h src/Console.cpp headers/Console.h headers/Word.h src/Word.cpp src/Chapter.cpp headers/Chapter.h src/Polish_Word.cpp headers/Polish_Word.h src/English_Word.cpp headers/English_Word.h)
