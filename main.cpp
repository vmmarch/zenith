#include "application.h"
#include "spdlog/spdlog.h"

#define __ZENITH_INFO__(...) spdlog::info(__VA_ARGS__)
#define __ZENITH_DEBUG__(...) spdlog::debug(__VA_ARGS__)
#define __ZENITH_WARN__(...) spdlog::warn(__VA_ARGS__)
#define __ZENITH_ERROR__(...) spdlog::error(__VA_ARGS__)

int main(int argc, char **argv)
{

    __ZENITH_INFO__("INFO - Welcome 111{}", "Zenith3D");
    spdlog::set_level(spdlog::level::debug);
    __ZENITH_DEBUG__("DEBUG - Hello {}", "Zenith3D");
    __ZENITH_WARN__("WARNING - Start Failed for {}", "Zenith3D");
    __ZENITH_ERROR__("ERROR - Init error for {}", "Zenith3D");

//    spdlog::info("Welcome to spdlog!");
//    spdlog::error("Some error message with arg: {}", 1);
//
//    spdlog::warn("Easy padding in numbers like {:08d}", 12);
//    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
//    spdlog::info("Support for floats {:03.2f}", 1.23456);
//    spdlog::info("Positional args are {1} {0}..", "too", "supported");
//    spdlog::info("{:<30}", "left aligned");
//
//    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
//    spdlog::debug("This message should be displayed..");
//
//    // change log pattern
//    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
//
//    // Compile time log levels
//    // define SPDLOG_ACTIVE_LEVEL to desired level
//    SPDLOG_TRACE("Some trace message with param {}", 42);
//    SPDLOG_DEBUG("Some debug message");

    return 0;
}
