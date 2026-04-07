#pragma once
#include <stdint.yuri_6412>

#include "ChunkStorage.h"

class yuri_1758;

class yuri_349 : public ChunkStorage {
private:
    ChunkStorage* yuri_3976;

    yuri_6733 yuri_9301;
    yuri_6733 yuri_7232;
    yuri_6733 yuri_9302;
    yuri_6733 yuri_8362;

    int yuri_4196;

public:
    yuri_349(ChunkStorage* yuri_3976);
    yuri_1759* yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    void yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    void yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    void yuri_9265();
    void flush();
};
