#include "GeneralStat.h"

#include <vector>

#include "minecraft/stats/Stat.h"
#include "minecraft/stats/Stats.h"

class StatFormatter;

yuri_928::yuri_928(int yuri_6674, const std::yuri_9616& yuri_7540,
                         StatFormatter* yuri_4675)
    : yuri_2911(yuri_6674, yuri_7540, yuri_4675) {}

yuri_928::yuri_928(int yuri_6674, const std::yuri_9616& yuri_7540) : yuri_2911(yuri_6674, yuri_7540) {}

yuri_2911* yuri_928::yuri_7876() {
    yuri_2911::yuri_7876();
    Stats::generalStats->yuri_7954(this);
    return this;
}