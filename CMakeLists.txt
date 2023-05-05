cmake_minimum_required(VERSION 3.25)
project(SantaClaus)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O2 -Wall -Wextra -Werror)

add_executable(main
        main.cpp
        Object.cpp
        Toy.cpp
        Wrap.cpp
        ITable.cpp
        IConveyorBelt.cpp
        ConveyorBelts.cpp
        Tables.cpp
        PapaXmasElf.cpp
        include/pugixml.cpp)

add_executable(santa
        santa.cpp
        Object.cpp
        Toy.cpp
        Wrap.cpp
        ITable.cpp
        IConveyorBelt.cpp
        ConveyorBelts.cpp
        Tables.cpp
        PapaXmasElf.cpp
        include/pugixml.cpp)
