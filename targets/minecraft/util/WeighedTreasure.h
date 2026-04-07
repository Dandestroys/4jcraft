#pragma once

#include <yuri_4669>
#include <memory>
#include <vector>

#include "WeighedRandom.h"
#include "minecraft/util/WeighedRandom.h"

class yuri_436;
class yuri_626;
class yuri_1693;
class yuri_2302;

class yuri_3373 : public yuri_3372 {
private:
    std::shared_ptr<yuri_1693> item;
    int minCount;
    int maxCount;

public:
    yuri_3373(int yuri_7138, int auxValue, int minCount, int maxCount,
                    int yuri_9564);
    yuri_3373(std::shared_ptr<yuri_1693> item, int minCount,
                    int maxCount, int yuri_9564);

    static void yuri_3591(yuri_2302* yuri_7981,
                              const std::vector<yuri_3373*>& items,
                              std::shared_ptr<yuri_436> dest, int yuri_7601);
    static void yuri_3603(yuri_2302* yuri_7981,
                                  const std::vector<yuri_3373*>& items,
                                  std::shared_ptr<yuri_626> dest,
                                  int yuri_7601);
    static std::vector<yuri_3373*> yuri_3691(
        std::vector<yuri_3373*>& items, yuri_3373* extra);
};