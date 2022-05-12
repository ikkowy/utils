cmake_minimum_required(VERSION 3.10)

project(utils)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_library(utils STATIC
    include/utils/base64.h
    include/utils/bitrot.h
    include/utils/byteorder.h
    include/utils/byteswap.h
    include/utils/sha1.h
    inlcude/utils/strops.h
    src/base64.c
    src/sha1.c
    src/strops.c)

target_include_directories(utils PUBLIC include)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
