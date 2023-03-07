# Copyright (c) 2023 Michał Gibas

cmake_minimum_required(VERSION 3.15)
project(rv32isim C CXX)

### project settings ###

# -std=c23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# app executable file name
set(APP_TARGET_NAME rv32isim)

# # tests executable file name
# set(TEST_TARGET_NAME rv32isim_test)

# warning level
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

######

### app source files ###
set(APP_SOURCES_PATH src/)

set(APP_SOURCES
    logs.c
)

list(TRANSFORM APP_SOURCES PREPEND ${APP_SOURCES_PATH})

### app build ###
add_executable(
    ${APP_TARGET_NAME} ${APP_SOURCES} src/sim.c
)

# ### test source files ###
# set(TEST_SOURCES_PATH src/tests/)

# set(TEST_SOURCES
#     instructions_test.cpp
# )

# list(TRANSFORM TEST_SOURCES PREPEND ${TEST_SOURCES_PATH})

# ### tests ###
# # fetch GoogleTest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(
#   ${TEST_TARGET_NAME}
#   ${TEST_SOURCES}
#   ${APP_SOURCES}
# )
# target_link_libraries(
#   ${TEST_TARGET_NAME}
#   GTest::gtest_main
#   spdlog::spdlog 
#   ${SDL2_LIBRARIES}
# )

# include(GoogleTest)
# gtest_discover_tests(${TEST_TARGET_NAME})