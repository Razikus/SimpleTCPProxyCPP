cmake_minimum_required(VERSION 3.13)
project(socketer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")


add_executable(socketer main.cpp server/Server.cpp server/Server.h proxyfier/Proxyfier.cpp proxyfier/Proxyfier.h server/ServerClient.cpp server/ServerClient.h proxyfier/ProxyConsumer.cpp proxyfier/ProxyConsumer.h)