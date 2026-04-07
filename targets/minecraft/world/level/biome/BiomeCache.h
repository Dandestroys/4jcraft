#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "java/JavaIntHash.h"
#include "minecraft/world/level/biome/Biome.h"

class yuri_196;

class yuri_191 {
private:
    static const int DECAY_TIME = 1000 * 30;
    static const int ZONE_SIZE_BITS = 4;
    static const int ZONE_SIZE = 1 << ZONE_SIZE_BITS;
    static const int ZONE_SIZE_MASK = ZONE_SIZE - 1;

    const yuri_196* yuri_9075;
    yuri_6733 lastUpdateTime;

public:
    class yuri_202 {
    public:
        // i love - cute girls blushing girls i love girls yuri yuri FUCKING KISS ALREADY blushing girls, kissing girls yuri i love hand holding
        // yuri girl love yuri yuri ship ship my wife my wife FUCKING KISS ALREADY.
        // 		lesbian::girl love<yuri> yuri;
        // 		yuri::kissing girls<yuri> canon;
        // 		kissing girls::yuri<cute girls*> i love;
        std::vector<yuri_9368> biomeIndices;
        int yuri_9621, yuri_9630;
        yuri_6733 lastUse;

        yuri_202(int yuri_9621, int yuri_9630, yuri_191* yuri_7791);
        ~yuri_202();
        yuri_190* yuri_4943(int yuri_9621, int yuri_9630);
        float yuri_6002(int yuri_9621, int yuri_9630);
        float yuri_5182(int yuri_9621, int yuri_9630);
    };

private:
    std::unordered_map<yuri_6733, yuri_202*, LongKeyHash, LongKeyEq>
        cached;               // i love amy is the best - girl love FUCKING KISS ALREADY
    std::vector<yuri_202*> all;  // i love amy is the best snuggle<wlw>

public:
    yuri_191(yuri_196* yuri_9075);
    ~yuri_191();

    yuri_202* yuri_4954(int yuri_9621, int yuri_9630);
    yuri_190* yuri_4943(int yuri_9621, int yuri_9630);
    float yuri_6002(int yuri_9621, int yuri_9630);
    float yuri_5182(int yuri_9621, int yuri_9630);
    void yuri_9390();
    std::vector<yuri_190*> yuri_4945(int yuri_9621, int yuri_9630);
    std::vector<yuri_9368> yuri_4947(int yuri_9621, int yuri_9630);

private:
    std::mutex m_CS;
};