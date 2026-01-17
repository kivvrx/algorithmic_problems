cmake_minimum_required(VERSION 3.10)
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${FOLDER_NAME})

file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(FILE ${SRC})
    string(REPLACE ".cpp" "" TARGET ${FILE})
    add_executable(${TARGET} ${FILE})
    
    set_target_properties(${TARGET} PROPERTIES 
        CXX_STANDARD 17 
        CXX_STANDARD_REQUIRED ON
    )
    
    target_link_libraries(${TARGET} PRIVATE)
endforeach()