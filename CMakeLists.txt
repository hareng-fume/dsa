cmake_minimum_required(VERSION 3.5)

project(DataStructuresAndAlgorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsa main.cpp
    suffix_trie.h
    suffix_trie.cpp
    multi_string_search.h
    multi_string_search.cpp
    walls_and_gates_multisource_bfs.h
    walls_and_gates_multisource_bfs.cpp)

include(GNUInstallDirs)
install(TARGETS dsa
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
