cmake_minimum_required(VERSION 3.10)

project(uws)

add_library(uws "")

find_package(OpenSSL REQUIRED)

target_include_directories(uws
PUBLIC
    include
PRIVATE
    src
)

target_sources(uws
PRIVATE
    # src/Epoll.cpp
    src/Extensions.cpp
    src/Group.cpp
    src/HTTPSocket.cpp
    src/Hub.cpp
    src/Networking.cpp
    src/Node.cpp
    src/Socket.cpp
    src/WebSocket.cpp
)

target_compile_definitions(uws
PRIVATE
    USE_LIBUV
)

target_compile_options(uws
PRIVATE
    -std=c++11
)

target_link_libraries(uws
PUBLIC
    uv
    z
    OpenSSL::SSL
)
