cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(scheduler_tests VERSION 1.0 LANGUAGES CXX)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT COMBINED_PROJECT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../source ${CMAKE_CURRENT_BINARY_DIR}/source)
endif()

set(test_sources
        main.cpp
        test_common.cpp
        )

set(TEST_EXE_NAME SchedulerTest)
add_executable(${TEST_EXE_NAME} ${test_sources})
target_link_libraries(${TEST_EXE_NAME}
        PRIVATE scheduler
        PRIVATE ${GTEST_LIBRARIES}
        )
target_include_directories(${TEST_EXE_NAME}
        PRIVATE ../include
        PRIVATE ../source
        PRIVATE ../third-party/xlnt/include
        PRIVATE ${GTEST_INCLUDE_DIRS}
        )

if(MSVC)
    # bigobj because there are so many headers in one source file
    set_target_properties(${TEST_EXE_NAME} PROPERTIES COMPILE_FLAGS "/wd\"4068\" /bigobj")
endif()

if(MSVC AND NOT STATIC)
    # copy xlnt DLL into xlnt.test directory
    add_custom_command(TARGET ${TEST_EXE_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:scheduler>
            $<TARGET_FILE_DIR:scheduler_tests>)
endif()

enable_testing()
add_test(${TEST_EXE_NAME} ./${TEST_EXE_NAME})