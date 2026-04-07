#pragma once

#include "minecraft/world/level/chunk/ChunkSource.h"

class yuri_1908 : public ChunkStorage {
public:
    virtual yuri_1759* yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    virtual void yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    virtual void yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    virtual void yuri_9265();
    virtual void flush();
};