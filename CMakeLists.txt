cmake_minimum_required(VERSION 3.16)
project(pvt_box)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})


add_executable(pbox main.cpp main.h Session.cpp Session.h Server.cpp Server.h Directory.cpp Directory.h SessionManager.cpp SessionManager.h RequestHandler.cpp RequestHandler.h Request.h RequestParser.cpp RequestParser.h Reply.cpp Reply.h)
add_executable(client client.cpp client.h)
target_link_libraries(pbox ${Boost_LIBRARIES})