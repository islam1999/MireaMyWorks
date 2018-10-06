cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Schedule-Editor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)


#build and link scheduler and xlnt as static libraries
set(STATIC ON CACHE BOOL "Set to ON to build scheduler as a shared library instead of a static library" FORCE)
add_subdirectory(scheduler)
set(SCHEDULER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/schdeuler/include)

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/source)
set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/include)
set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/resources)

file(GLOB HEADERS ${HEADERS_DIR}/*.h)
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)

if (WIN32 AND NOT ${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS -static)
    add_executable(${PROJECT_NAME} WIN32 ${HEADERS} ${SOURCES})
else ()
    add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${SCHEDULER_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} scheduler)
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Sql)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_DIR} ${CMAKE_BINARY_DIR}/resources)
endif()

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
            ${QT_BIN_VERSION_PATH}/Qt5Sql${DEBUG_SYMBOL}.dll

            # MinGW libraries
            ${QT_BIN_VERSION_PATH}/libgcc_s_dw2-1.dll
            ${QT_BIN_VERSION_PATH}/libstdc++-6.dll
            ${QT_BIN_VERSION_PATH}/libwinpthread-1.dll
        )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${dll_files} ${CMAKE_BINARY_DIR})
endif ()
