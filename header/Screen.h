#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <windows.h>

#ifdef __WIN32__
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

#endif // SCREEN_H_INCLUDED
