// Copyright (c) 2019-present Anonymous275.
// BeamMP Launcher code is not in the public domain and is not free software.
// One must be granted explicit permission by the copyright holder in order to modify or distribute any part of the source or binaries.
// Anything else is prohibited. Modified works may not be published and have be upstreamed to the official repository.
///
/// Created by Anonymous275 on 9/25/2020
///

#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>
#include "Logger.h"

std::string GetAddr(const std::string&IP){
    if(IP.find_first_not_of("0123456789.") == -1)return IP;
    WSADATA wsaData;
    if(WSAStartup(514, &wsaData) != 0){
        log_error("WSA Startup Failed!");
        WSACleanup();
        return "";
    }

    addrinfo *result = nullptr, *ptr = nullptr, hints{};
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(IP.c_str(), "http", &hints, &result) != 0) {
        log_error("getaddrinfo failed with error: %s", wsa_get_err_str());
        WSACleanup();
        return "";
    }
    std::string Ret = inet_ntop(result->ai_family, &((sockaddr_in*)result->ai_addr)->sin_addr, new char[INET_ADDRSTRLEN], INET_ADDRSTRLEN);
    WSACleanup();
    return Ret;
}