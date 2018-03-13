cmake_minimum_required(VERSION 3.10)

project(uws)
set(CMAKE_CXX_STANDARD 17)

set(WEBSOCKET_KEY "d2Vic29ja2V0c2VjcmV0a2V5" CACHE STRING "A 24 character ASCII string used to establish a WebSocket connection with a server")

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

target_link_libraries(uws
PUBLIC
    b64
    uv
    OpenSSL::SSL
    z
)
