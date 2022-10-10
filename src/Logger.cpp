// Copyright (c) 2019-present Anonymous275.
// BeamMP Launcher code is not in the public domain and is not free software.
// One must be granted explicit permission by the copyright holder in order to modify or distribute any part of the source or binaries.
// Anything else is prohibited. Modified works may not be published and have be upstreamed to the official repository.
///
/// Created by Anonymous275 on 7/17/2020
///

#include "Startup.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <WinSock2.h>
#include <iomanip>

std::string getDate() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    tm buf{};
    localtime_s(&buf, &in_time_t);
    ss << std::put_time(&buf, "[%d/%m/%Y %H:%M:%S] ");
    return ss.str();
}

void InitLog(){
    std::ofstream LFS;
    LFS.open(GetEP() + "Launcher.log");
    if (!LFS.is_open()) {
        printf("Failed to open log file!");
    } else {
        LFS.close();
    }
}

void addToLog(const std::string& line){
    std::ofstream logFile;
    logFile.open(GetEP() + "Launcher.log", std::ios_base::app);
    logFile << line.c_str();
    logFile.close();
}

const char* wsa_get_err_str() {
    DWORD err = WSAGetLastError();
    const char* err_str = "Unknown error";

    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr,
        err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&err_str,
        0,
        nullptr
    );

    return err_str;
}

void log(LogLevel level, const char* message, bool new_line) {
    const char* level_str = "";
    switch (level) {
        case LogLevel::Verbose:
            level_str = "[VERBOSE]";
            break;
        case LogLevel::Debug:
            level_str = "[DEBUG]";
            break;
        case LogLevel::Info:
            level_str = "[INFO]";
            break;
        case LogLevel::Warning:
            level_str = "[WARN]";
            break;
        case LogLevel::Error:
            level_str = "[ERROR]";
            break;
        case LogLevel::Exception:
            level_str = "[EXCEPTION]";
            break;
        case LogLevel::Fatal:
            level_str = "[FATAL]";
            break;
        default:
            level_str = "[UNKNOWN]";
            break;
    }

    if (!Dev && level == LogLevel::Debug)
        return;

    if (!Verbose && level == LogLevel::Verbose)
        return;

    std::string output = getDate() + level_str + " " + message + (new_line ? "\n" : "");
    if (level == LogLevel::Fatal) {
        output += "Closing in 5 seconds...";
    }
    std::cout << output;
    addToLog(output);
}