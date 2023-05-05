cmake_minimum_required(VERSION 3.25)
project(SantaClaus)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost 1.42.0 REQUIRED COMPONENTS system thread regex)
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O2 -Wall -Wextra -Werror)

add_executable(send_gifts
        SendGifts.cpp
        Object.cpp
        Toy.cpp
        Wrap.cpp
        ITable.cpp
        IConveyorBelt.cpp
        ConveyorBelts.cpp
        Tables.cpp
        PapaXmasElf.cpp
        include/pugixml.cpp)
target_link_libraries(send_gifts ${USED_LIBS})

add_executable(santa
        Santa.cpp
        Object.cpp
        Toy.cpp
        Wrap.cpp
        ITable.cpp
        IConveyorBelt.cpp
        ConveyorBelts.cpp
        Tables.cpp
        PapaXmasElf.cpp
        include/pugixml.cpp)
target_link_libraries(santa ${USED_LIBS})
