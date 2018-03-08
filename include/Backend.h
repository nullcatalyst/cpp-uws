#ifndef BACKEND_H
#define BACKEND_H

#if !defined(__linux__) || defined(USE_LIBUV)
// Default to Libuv if nothing specified and not on Linux
#include "Libuv.h"
#else
// Default to Epoll if nothing specified and on Linux
#define USE_EPOLL
#include "Epoll.h"
#endif

#endif // BACKEND_H
