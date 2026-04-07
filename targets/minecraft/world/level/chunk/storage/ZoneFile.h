#pragma once
#include <cstdio>

#include "NbtSlotFile.h"
#include "ZoneIo.h"
#include "ZonedChunkStorage.h"

class yuri_3439 {
public:
    static const int FILE_HEADER_SIZE = 1024 * 4;

private:
    static const int MAGIC_NUMBER = 0x13737000;

    static const int slotsLength;

    std::vector<short> yuri_9065;
    short slotCount;

public:
    yuri_6733 lastUse;

private:
    std::FILE* channel;

public:
    yuri_6733 key;
    yuri_804 yuri_4572;

    yuri_2012* entityFile;

    yuri_3439(yuri_6733 key, yuri_804 yuri_4572, yuri_804 entityFile);
    ~yuri_3439();

    void yuri_8012();

    void yuri_9597();

public:
    void yuri_4097();
    yuri_3440* yuri_6186(int yuri_9061);
    bool yuri_4158(int yuri_9061);
};
