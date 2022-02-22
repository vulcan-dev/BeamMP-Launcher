///
/// Created by Anonymous275 on 1/21/22
/// Copyright (c) 2021-present Anonymous275 read the LICENSE file for more info.
///

#pragma once
namespace Patterns {
    const char* GetTickCount[2] {
            "\x48\xff\x25\x00\x00\x00\x00\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\x48\x83\xec\x00\x48\x8d\x4c\x24",
            "xxx????xxxxxxxxxxxx?xxxx"
    };
    const char* open_jit[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xec\x00\x48\x8b\x05\x00\x00\x00\x00\x48\x33\xc4\x48\x89\x44\x24\x00\x48\x8b\x71\x00\x48\x8d\x54\x24",
            "xxxx?xxxx?xxxx?xxx????xxxxxxx?xxx?xxxx"
    };
    const char* get_field[2] {
            "\x48\x89\x5c\x24\x00\x57\x48\x83\xec\x00\x4d\x8b\xd0\x48\x8b\xd9\xe8\x00\x00\x00\x00\x48\x8b\xf8\x49\xc7\xc0\x00\x00\x00\x00\x90\x49\xff\xc0\x43\x80\x3c\x02\x00\x75\x00\x49\x8b\xd2\x48\x8b\xcb\xe8\x00\x00\x00\x00\x48\xb9\x00\x00\x00\x00\x00\x00\x00\x00\x4c\x8d\x44\x24\x00\x48\x0b\xc1\x48\x8b\xd7\x48\x8b\xcb\x48\x89\x44\x24\x00\xe8\x00\x00\x00\x00\x48\x85\xc0",
            "xxxx?xxxx?xxxxxxx????xxxxxx????xxxxxxxx?x?xxxxxxx????xx????????xxxx?xxxxxxxxxxxxx?x????xxx"
    };
    const char* push_fstring[2] {
            "\x48\x89\x54\x24\x00\x4c\x89\x44\x24\x00\x4c\x89\x4c\x24\x00\x53\x48\x83\xec\x00\x4c\x8b\x41",
            "xxxx?xxxx?xxxx?xxxx?xxx"
    };
    const char* p_call[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xec\x00\x48\x8b\x59\x00\x41\x8b\xf0\x4c\x63\xda",
            "xxxx?xxxx?xxxx?xxx?xxxxxx"
    };
    const char* lua_setfield[2] {
            "\x48\x89\x5c\x24\x00\x57\x48\x83\xec\x00\x4d\x8b\xd0\x48\x8b\xd9\xe8\x00\x00\x00\x00\x48\x8b\xf8\x49\xc7\xc0\x00\x00\x00\x00\x90\x49\xff\xc0\x43\x80\x3c\x02\x00\x75\x00\x49\x8b\xd2\x48\x8b\xcb\xe8\x00\x00\x00\x00\x48\xb9\x00\x00\x00\x00\x00\x00\x00\x00\x4c\x8d\x44\x24\x00\x48\x0b\xc1\x48\x8b\xd7\x48\x8b\xcb\x48\x89\x44\x24\x00\xe8\x00\x00\x00\x00\x48\x8b\x53",
            "xxxx?xxxx?xxxxxxx????xxxxxx????xxxxxxxx?x?xxxxxxx????xx????????xxxx?xxxxxxxxxxxxx?x????xxx"
    };
    const char* lua_createtable[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xec\x00\x4c\x8b\x49\x00\x41\x8b\xf8",
            "xxxx?xxxx?xxxx?xxx?xxx"
    };
    const char* lua_settable[2] {
            "\x40\x53\x48\x83\xec\x00\x48\x8b\xd9\xe8\x00\x00\x00\x00\x4c\x8b\x43\x00\x48\x8b\xd0\x49\x83\xe8\x00\x48\x8b\xcb\xe8\x00\x00\x00\x00\x48\x8b\x53",
            "xxxxx?xxxx????xxx?xxxxxx?xxxx????xxx"
    };
    const char* lua_pushcclosure[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xec\x00\x48\x8b\xd9\x49\x63\xf8\x48\x8b\x49\x00\x48\x8b\xf2",
            "xxxx?xxxx?xxxx?xxxxxxxxx?xxx"
    };
    const char* lua_tolstring[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xec\x00\x49\x8b\xf8\x8b\xda\x48\x8b\xf1\xe8",
            "xxxx?xxxx?xxxx?xxxxxxxxx"
    };
    const char* GEUpdate[2] {
            "\x48\x89\x5c\x24\x00\x48\x89\x6c\x24\x00\x56\x57\x41\x56\x48\x83\xec\x00\x4c\x8b\x31\x49\x8b\xf0",
            "xxxx?xxxx?xxxxxxx?xxxxxx"
    };
    const char* lua_settop[2] {
            "\x4c\x8b\xc1\x85\xd2\x7e\x00\x48\x8b\x41\x00\x48\x8b\x49",
            "xxxxxx?xxx?xxx"
    };
}