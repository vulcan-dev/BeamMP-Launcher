// Copyright (c) 2019-present Anonymous275.
// BeamMP Launcher code is not in the public domain and is not free software.
// One must be granted explicit permission by the copyright holder in order to modify or distribute any part of the source or binaries.
// Anything else is prohibited. Modified works may not be published and have be upstreamed to the official repository.
///
/// Created by Anonymous275 on 4/2/2020.
///
#pragma once
#include <string>
#include <iostream>
#include <thread>

void InitLog();

const char* wsa_get_err_str();

enum class LogLevel : uint8_t {
    Verbose,
    Debug,
    Info,
    Warning,
    Error,
    Exception,
    Fatal,
};

template <typename... Args>
inline std::string format_log(const char* format, Args&&... args) {
    std::string result;
    result.resize(std::snprintf(nullptr, 0, format, std::forward<Args>(args)...));
    std::snprintf(result.data(), result.size() + 1, format, std::forward<Args>(args)...);
    return result;
}

void log(LogLevel level, const char* message, bool new_line = true);

template <typename... Args>
inline void log_verbose(const char* format, Args&&... args) {
    log(LogLevel::Verbose, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_debug(const char* format, Args&&... args) {
    log(LogLevel::Debug, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_info(const char* format, Args&&... args) {
    log(LogLevel::Info, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_warn(const char* format, Args&&... args) {
    log(LogLevel::Warning, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_error(const char* format, Args&&... args) {
    log(LogLevel::Error, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_exception(const char* format, Args&&... args) {
    log(LogLevel::Exception, format_log(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
inline void log_fatal(const char* format, Args&&... args) {
    log(LogLevel::Fatal, format_log(format, std::forward<Args>(args)...).c_str());
    std::this_thread::sleep_for(std::chrono::seconds(5));
    _Exit(-1);
}