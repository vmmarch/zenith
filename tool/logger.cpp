//
// Created by aorus on 2021/3/29.
//

#include "zenith/zenith.h"
#include <cstdarg>

void INFO(std::string __fmt, ...)
{
    va_list  argument;
    va_start(argument, __fmt);
    __fmt = "[INFO] - " + __fmt + "\n";
    printf(__fmt.c_str(), argument);
    va_end(argument);
}

void ERROR(std::string __fmt, ...)
{
    va_list  argument;
    va_start(argument, __fmt);
    __fmt = "[ERROR] - " + __fmt + "\n";
    printf(__fmt.c_str(), argument);
    va_end(argument);
}

void ZENITH_LOGGER_INFO(std::string __fmt, ...)
{
    va_list  argument;
    va_start(argument, __fmt);
    INFO(__fmt, argument);
    va_end(argument);
}

void ZENITH_LOGGER_ERROR(std::string __fmt, ...)
{
    va_list  argument;
    va_start(argument, __fmt);
    ERROR(__fmt, argument);
    va_end(argument);
}

void ZENITH_FATAL_ERROR(std::string __fmt, ...)
{
    va_list  argument;
    va_start(argument, __fmt);
    ERROR(__fmt, argument);
    va_end(argument);
}