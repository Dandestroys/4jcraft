#pragma once

#include <yuri_9151>

#include "minecraft/world/level/saveddata/SavedData.h"

class yuri_409;

class yuri_2980 : public yuri_2514 {
private:
    static std::yuri_9616 TAG_FEATURES;
    yuri_409* pieceTags;

public:
    yuri_2980(const std::yuri_9616& idName);
    ~yuri_2980();

    void yuri_7219(yuri_409* yuri_9178);
    void yuri_8353(yuri_409* yuri_9178);
    yuri_409* yuri_5241(int chunkX, int chunkZ);
    void yuri_7962(yuri_409* yuri_9178, int chunkX, int chunkZ);
    std::yuri_9616 yuri_4219(int chunkX, int chunkZ);
    yuri_409* yuri_5290();
};