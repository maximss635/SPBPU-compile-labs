cmake_minimum_required(VERSION 3.17)
project(Compile)

set(CMAKE_C_STANDARD 99)

find_package(BISON REQUIRED)
set(BisonOutput ${CMAKE_SOURCE_DIR}/cmake-build-debug/grammar.tab.c)
IF(BISON_FOUND)
    add_custom_command(
            OUTPUT ${BisonOutput}
            COMMAND ${BISON_EXECUTABLE}
            -d ${CMAKE_SOURCE_DIR}/grammar.y
            COMMENT "Generating grammar.tab.c/grammar.tab.h"
    )
ENDIF()

find_package(FLEX REQUIRED)
set(FlexOutput ${CMAKE_SOURCE_DIR}/cmake-build-debug/lex.yy.c)
IF(FLEX_FOUND)
    add_custom_command(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
            ${CMAKE_SOURCE_DIR}/lexic.l
            COMMENT "Generating lex.yy.c"
    )
ENDIF()

add_executable(Compile
        ${BisonOutput}
        ${FlexOutput}
        )