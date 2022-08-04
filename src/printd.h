#include <stdio.h>
#include <stdarg.h>

#ifndef DEBUG
#define DEBUG 0

void printd(const char *format, ...){
    if(DEBUG){
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

#endif