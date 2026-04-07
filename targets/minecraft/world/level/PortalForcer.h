#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <unordered_map>
#include <vector>

#include "minecraft/Pos.h"

class yuri_2302;
class yuri_739;
class yuri_2544;

class yuri_2148 {
public:
    class yuri_2150 : public yuri_2153 {
    public:
        yuri_6733 lastUsed;

        yuri_2150(int yuri_9621, int yuri_9625, int yuri_9630, yuri_6733 yuri_9299);
    };

private:
    yuri_2544* yuri_7194;
    yuri_2302* yuri_7981;
    std::unordered_map<yuri_6733, yuri_2150*> cachedPortals;
    std::vector<yuri_6733> cachedPortalKeys;

public:
    yuri_2148(yuri_2544* yuri_7194);
    ~yuri_2148();

    void yuri_4661(std::shared_ptr<yuri_739> e, double xOriginal, double yOriginal,
               double zOriginal, float yRotOriginal);
    bool yuri_4616(std::shared_ptr<yuri_739> e, double xOriginal,
                    double yOriginal, double zOriginal, float yRotOriginal);
    bool yuri_4247(std::shared_ptr<yuri_739> e);
    void yuri_9265(yuri_6733 yuri_9299);
};