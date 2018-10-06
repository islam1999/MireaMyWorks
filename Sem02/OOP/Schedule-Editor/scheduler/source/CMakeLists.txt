cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(scheduler_api VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    message(FATAL_ERROR "OSX can not built on OX yet")
endif()

# Commonly used project directories
set(SCHEDULER_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(SCHEDULER_INCLUDE_DIR ${SCHEDULER_ROOT_DIR}/include)
set(SCHEDULER_SOURCE_DIR ${SCHEDULER_ROOT_DIR}/source)
set(SCHEDULER_RESOURCES_DIR ${SCHEDULER_ROOT_DIR}/resources)
set(THIRD_PARTY_DIR ${SCHEDULER_ROOT_DIR}/third-party)

# Include xlnt library
add_subdirectory(${THIRD_PARTY_DIR}/QtXlsxWriter
        ${CMAKE_CURRENT_BINARY_DIR}/third-party/QtXlsxWriter)

# Non-target-specific compiler settings
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4") # level 4 warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") # multi-processor compilation
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # all warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # extra warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas") # ignore MSVC and Clang pragmas
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything") # all warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror") # warnings are errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat") # ignore warnings about C++98 compatibility
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat-pedantic") # ignore pedantic warnings about C++98 compatibility
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-padded") # ignore padding warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-documentation-unknown-command") # ignore unknown commands in Javadoc-style comments
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas") # ignore Windows and GCC pragmas
endif ()

set(SCHEDULER_HEADERS
        ${SCHEDULER_INCLUDE_DIR}/common.h
        ${SCHEDULER_INCLUDE_DIR}/schedule_error.h
        ${SCHEDULER_INCLUDE_DIR}/xlsx_file.h
        ${SCHEDULER_INCLUDE_DIR}/lesson.h
        ${SCHEDULER_INCLUDE_DIR}/group_schedule.h
        ${SCHEDULER_INCLUDE_DIR}/scheduler.h
        )

set(SCHEDULER_SOURCES
        ${SCHEDULER_SOURCE_DIR}/common.cpp
        ${SCHEDULER_SOURCE_DIR}/schedule_error.cpp
        ${SCHEDULER_SOURCE_DIR}/xlsx_file.cpp
        ${SCHEDULER_SOURCE_DIR}/lesson.cpp
        ${SCHEDULER_SOURCE_DIR}/group_schedule.cpp
        ${SCHEDULER_SOURCE_DIR}/scheduler.cpp
        )

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # Set a default CMAKE_INSTALL_PREFIX if one wasn't specified

    set(DEFAULT_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed")

    # Apply the variable and save to cache
    set(CMAKE_INSTALL_PREFIX ${DEFAULT_INSTALL_PREFIX}
            CACHE PATH "default install path" FORCE)
endif ()

set(LIBRARY_NAME scheduler)
if (NOT STATIC)
    # Compile shared library
    add_library(${LIBRARY_NAME} SHARED
            ${SCHEDULER_HEADERS}
            ${SCHEDULER_SOURCES})
    add_dependencies(${LIBRARY_NAME} xlnt)

    # Set SO version (for symbolic links like libscheduler.so.1.2 and libscheduler.so.1)
    set_target_properties(${LIBRARY_NAME}
            PROPERTIES
            VERSION ${PROJECT_VERSION}
            SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
else ()
    # Compile static library
    add_library(${LIBRARY_NAME} STATIC ${SCHEDULER_HEADERS} ${SCHEDULER_SOURCES})

    add_dependencies(${LIBRARY_NAME} QtXlsxWriter)
endif ()

# Includes
target_include_directories(${LIBRARY_NAME} PUBLIC ${SCHEDULER_INCLUDE_DIR})
target_include_directories(${LIBRARY_NAME} PUBLIC ${THIRD_PARTY_DIR}/QtXlsxWriter/src/)
target_link_libraries(${LIBRARY_NAME} QtXlsxWriter)

# Platform- and file-specific settings, MSVC
if (MSVC)
    target_compile_definitions(${LIBRARY_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS=1)

    if (NOT STATIC)
        target_compile_definitions(${LIBRARY_NAME} PRIVATE SCHEDULER_EXPORT=1)
    endif ()

    set_target_properties(${LIBRARY_NAME} PROPERTIES
            COMPILE_FLAGS "/wd\"4251\" /wd\"4275\" /wd\"4068\"")
endif ()

# Configure resources files
configure_file(${SCHEDULER_RESOURCES_DIR}/schedule_default_template.xlsx
        ${CMAKE_BINARY_DIR}/jstf.dat COPYONLY)

if (NOT STATIC)
    if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(DEBUG_SYMBOL "d")
    endif ()

    if (WIN32)
        set(shared_libs
#                ${CMAKE_CURRENT_BINARY_DIR}/third-party/xlnt/source/libxlnt${DEBUG_SYMBOL}.dll
                ${CMAKE_CURRENT_BINARY_DIR}/libscheduler${DEBUG_SYMBOL}.dll)
    elseif (UNIX AND NOT APPLE)
        set(XLNT_VERSION 1.2)

        set(shared_libs
#                ${CMAKE_CURRENT_BINARY_DIR}/third-party/xlnt/source/libxlnt${DEBUG_SYMBOL}.so.${XLNT_VERSION}
#                ${CMAKE_CURRENT_BINARY_DIR}/third-party/xlnt/source/libxlnt${DEBUG_SYMBOL}.so
                ${CMAKE_CURRENT_BINARY_DIR}/libscheduler${DEBUG_SYMBOL}.so.${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                ${CMAKE_CURRENT_BINARY_DIR}/libscheduler${DEBUG_SYMBOL}.so)
    endif ()

    add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${shared_libs} ${CMAKE_BINARY_DIR})
endif()