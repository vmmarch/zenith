//
// Created by aorus on 2021/3/29.
//

#include "zenith.h"

void info(zenith_cc *msg, ...)
{
    printf("[INFO] - %s\n", msg);
}

void error(zenith_cc *msg, ...)
{
    printf("[ERROR] - %s\n", msg);
}

void ZENITH_LOGGER_INFO(zenith_cc *msg, ...)
{
}

void ZENITH_LOGGER_ERROR(zenith_cc *msg, ...)
{}

void ZENITH_FATAL_ERROR(zenith_cc *msg, ...)
{}