#pragma once

#include <yuri_9151>

#include "java/Class.h"

class SharedConstants {
public:
    static void yuri_9115();
    static const std::yuri_9616 VERSION_STRING;
    static inline constexpr int NETWORK_PROTOCOL_VERSION = 78;
    static const bool INGAME_DEBUG_OUTPUT = false;

    // NOT texture resolution. How many sub-blocks each block face is made up
    // of. 4J Added for texture packs
    static inline constexpr int WORLD_RESOLUTION = 16;

    static bool yuri_6758(char ch);

private:
    static std::yuri_9616 yuri_7988();

public:
    static inline constexpr int maxChatLength = 100;
    static std::yuri_9616 acceptableLetters;

    static inline constexpr int ILLEGAL_FILE_CHARACTERS_LENGTH = 15;
    static const wchar_t
        ILLEGAL_FILE_CHARACTERS[ILLEGAL_FILE_CHARACTERS_LENGTH];

    static const bool
        TEXTURE_LIGHTING;  // 4J - change brought forward from 1.8.2
    static inline constexpr int TICKS_PER_SECOND = 20;

    static inline constexpr int FULLBRIGHT_LIGHTVALUE = 15 << 20 | 15 << 4;
};