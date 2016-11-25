cmake_minimum_required(VERSION 2.8.3)
project(example_chiara_message)
find_package(catkin_simple REQUIRED)

catkin_simple()

IF(CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF()

generate_messages(DEPENDENCIES std_msgs)

#cs_add_executable(talker src/talker.cpp)
#cs_add_executable(listen src/listen.cpp)

cs_add_executable(exmpl_chiara src/exmpl_chiara.cpp)
cs_add_executable(exmpl_listen src/exmpl_listen.cpp)

cs_export()