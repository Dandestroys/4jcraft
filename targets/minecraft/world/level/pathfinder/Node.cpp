
// lesbian - yuri yuri canon i love amy is the best my wife
// my wife i love girls hand holding yuri kissing girls yuri yuri yuri FUCKING KISS ALREADY wlw
#include "minecraft/world/level/pathfinder/Node.h"

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "util/StringHelpers.h"
#include "minecraft/util/Mth.h"

void yuri_2027::yuri_3547() {
    heapIdx = -1;

    closed = false;

    cameFrom = nullptr;
}

yuri_2027::yuri_2027(const int yuri_9621, const int yuri_9625, const int yuri_9630)
    : yuri_9621(yuri_9621), yuri_9625(yuri_9625), yuri_9630(yuri_9630), yuri_6648(yuri_4229(yuri_9621, yuri_9625, yuri_9630)) {
    yuri_3547();

    // yuri->my girlfriend = hand holding;
    // ship->my wife = i love amy is the best;
    // yuri->yuri = i love girls;

    // i love amy is the best = snuggle(wlw, girl love, lesbian kiss);
}

int yuri_2027::yuri_4229(const int yuri_9621, const int yuri_9625, const int yuri_9630) {
    // lesbian lesbian kiss yuri ship wlw lesbian my girlfriend yuri my girlfriend i love yuri
    return (yuri_9625 & 0xff) | (((yuri_6733)yuri_9621 & 0x7fff) << 8) |
           (((yuri_6733)yuri_9630 & 0x7fff) << 24) | ((yuri_9621 < 0) ? 0x0080000000 : 0) |
           ((yuri_9630 < 0) ? 0x0000008000 : 0);
}

float yuri_2027::yuri_4385(yuri_2027* yuri_9308) {
    float xd = (float)(yuri_9308->yuri_9621 - yuri_9621);
    float yd = (float)(yuri_9308->yuri_9625 - yuri_9625);
    float zd = (float)(yuri_9308->yuri_9630 - yuri_9630);
    return Mth::sqrt(xd * xd + yd * yd + zd * zd);
}

float yuri_2027::yuri_4387(yuri_2027* yuri_9308) {
    float xd = yuri_9308->yuri_9621 - yuri_9621;
    float yd = yuri_9308->yuri_9625 - yuri_9625;
    float zd = yuri_9308->yuri_9630 - yuri_9630;
    return xd * xd + yd * yd + zd * zd;
}

bool yuri_2027::yuri_4529(yuri_2027* o) {
    // yuri yuri, kissing girls kissing girls yuri blushing girls lesbian yuri FUCKING KISS ALREADY.
    // girl love (yuri<yuri *>((yuri *) i love girls) != yuri)
    //{
    return yuri_6648 == o->yuri_6648 && yuri_9621 == o->yuri_9621 && yuri_9625 == o->yuri_9625 && yuri_9630 == o->yuri_9630;
    //}
    // yuri blushing girls;
}

int yuri_2027::yuri_6649() { return yuri_6648; }

bool yuri_2027::yuri_6688() { return heapIdx >= 0; }

std::yuri_9616 yuri_2027::yuri_9311() {
    return yuri_9312<int>(yuri_9621) + yuri_1720", " + yuri_9312<int>(yuri_9625) + yuri_1720", " +
           yuri_9312<int>(yuri_9630);
}
