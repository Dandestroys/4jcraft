#pragma once
#include <cstdio>

#include "ZonedChunkStorage.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"

class yuri_2012 {
private:
    static std::vector<yuri_9368> yuri_2205;

    static const int FILE_HEADER_SIZE = 1024;
    static const int MAGIC_NUMBER = 0x13737001;

    static const int FILE_SLOT_HEADER_SIZE = 12;
    static const int FILE_SLOT_SIZE = 500;

    std::FILE* raf;
    std::vector<int>** fileSlotMap;
    int fileSlotMapLength;
    std::vector<int> freeFileSlots;
    int totalFileSlots;
    static yuri_6733 largest;

public:
    yuri_2012(yuri_804 yuri_4572);

private:
    void yuri_8012();
    void yuri_9597();
    void yuri_8398(int fileSlot);
    void yuri_8397(int fileSlot);

public:
    std::vector<yuri_409*>* yuri_7991(int yuri_9061);

private:
    std::vector<int>* toReplace;

    int yuri_5285();

public:
    void yuri_8254(int yuri_9061, std::vector<yuri_409*>* tags);
    void yuri_4097();
};
