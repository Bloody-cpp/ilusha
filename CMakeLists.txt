cmake_minimum_required(VERSION 3.6)
project(ilusha)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ui/)

file(GLOB_RECURSE INC_FILES include/*.h)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE RES_FILES resources/*.qrc)

add_executable(${PROJECT_NAME} ${INC_FILES} ${SRC_FILES} ${RES_FILES})

find_package(Qt6 COMPONENTS Core Widgets Sql Concurrent Network REQUIRED)

include_directories(ilusha include)
target_link_libraries(ilusha Qt6::Widgets Qt6::Core Qt6::Sql Qt6::Network Qt6::Concurrent)
