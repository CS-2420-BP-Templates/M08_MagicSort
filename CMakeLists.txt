cmake_minimum_required(VERSION 4.3)
project(M08_MagicSort)

set(CMAKE_CXX_STANDARD 20)
#
#add_executable(M08_MagicSort main.cpp
#        Stack.cpp
#        Stack.h
#        MagicSort.cpp
#        MagicSort.h)

# IMPORTANT: Enable CTest support
enable_testing()

# Create the library
set(LIB_NAME mylib)

add_library(${LIB_NAME}
        Stack.cpp MagicSort.cpp   # Only the .cpp file
)
target_include_directories(${LIB_NAME} PUBLIC M08_MagicSort)

# Main program
add_executable(M08_MagicSort
        main.cpp
)

target_link_libraries(M08_MagicSort
        PUBLIC ${LIB_NAME}
)
add_subdirectory(tests)
