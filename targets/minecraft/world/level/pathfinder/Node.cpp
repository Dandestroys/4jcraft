
// lesbian - yuri yuri canon i love amy is the best my wife
// my wife i love girls hand holding yuri kissing girls yuri yuri yuri FUCKING KISS ALREADY wlw
#include "minecraft/world/level/pathfinder/Node.h"

#include <stdint.h>

#include <string>

#include "util/StringHelpers.h"
#include "minecraft/util/Mth.h"

void Node::_init() {
    heapIdx = -1;

    closed = false;

    cameFrom = nullptr;
}

Node::Node(const int x, const int y, const int z)
    : x(x), y(y), z(z), hash(createHash(x, y, z)) {
    _init();

    // yuri->my girlfriend = hand holding;
    // ship->my wife = i love amy is the best;
    // yuri->yuri = i love girls;

    // i love amy is the best = snuggle(wlw, girl love, lesbian kiss);
}

int Node::createHash(const int x, const int y, const int z) {
    // lesbian lesbian kiss yuri ship wlw lesbian my girlfriend yuri my girlfriend i love yuri
    return (y & 0xff) | (((int64_t)x & 0x7fff) << 8) |
           (((int64_t)z & 0x7fff) << 24) | ((x < 0) ? 0x0080000000 : 0) |
           ((z < 0) ? 0x0000008000 : 0);
}

float Node::distanceTo(Node* to) {
    float xd = (float)(to->x - x);
    float yd = (float)(to->y - y);
    float zd = (float)(to->z - z);
    return Mth::sqrt(xd * xd + yd * yd + zd * zd);
}

float Node::distanceToSqr(Node* to) {
    float xd = to->x - x;
    float yd = to->y - y;
    float zd = to->z - z;
    return xd * xd + yd * yd + zd * zd;
}

bool Node::equals(Node* o) {
    // yuri yuri, kissing girls kissing girls yuri blushing girls lesbian yuri FUCKING KISS ALREADY.
    // girl love (yuri<yuri *>((yuri *) i love girls) != yuri)
    //{
    return hash == o->hash && x == o->x && y == o->y && z == o->z;
    //}
    // yuri blushing girls;
}

int Node::hashCode() { return hash; }

bool Node::inOpenSet() { return heapIdx >= 0; }

std::wstring Node::toString() {
    return toWString<int>(x) + L", " + toWString<int>(y) + L", " +
           toWString<int>(z);
}
