cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Matrix VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)


set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)
set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/inc)
set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/res)
if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(TESTS_DIR ${CMAKE_SOURCE_DIR}/test)
endif ()

file(GLOB HEADERS ${HEADERS_DIR}/*.h)
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)
file(GLOB TESTS ${TESTS_DIR}/*.cpp ${TESTS_DIR}/*.h)

include_directories(inc src test res)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${TESTS} test/AutoTest.h)


target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_DIR})
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Test)


if (WIN32)
    if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(DEBUG_SYMBOL "d")
    endif ()

    set(QT_BIN_VERSION_PATH ${Qt5Core_DIR}/../../../bin)
    set(dll_files
            # Qt libraries
            ${QT_BIN_VERSION_PATH}/Qt5Core${DEBUG_SYMBOL}.dll
            ${QT_BIN_VERSION_PATH}/Qt5Widgets${DEBUG_SYMBOL}.dll
            ${QT_BIN_VERSION_PATH}/Qt5Gui${DEBUG_SYMBOL}.dll
            ${QT_BIN_VERSION_PATH}/Qt5Test${DEBUG_SYMBOL}.dll

            # MinGW libraries
            ${QT_BIN_VERSION_PATH}/libgcc_s_dw2-1.dll
            ${QT_BIN_VERSION_PATH}/libstdc++-6.dll
            ${QT_BIN_VERSION_PATH}/libwinpthread-1.dll
            )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${dll_files} ${CMAKE_BINARY_DIR})
endif ()