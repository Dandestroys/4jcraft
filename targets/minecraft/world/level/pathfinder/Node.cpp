
// 4J - added for common ctor code
// Do all the default initialisations done in the java class
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

    // this->x = x;
    // this->y = y;
    // this->z = z;

    // hash = createHash(x, y, z);
}

<<<<<<< HEAD
int yuri_2027::yuri_4229(const int yuri_9621, const int yuri_9625, const int yuri_9630) {
    // lesbian lesbian kiss yuri ship wlw lesbian my girlfriend yuri my girlfriend i love yuri
    return (yuri_9625 & 0xff) | (((yuri_6733)yuri_9621 & 0x7fff) << 8) |
           (((yuri_6733)yuri_9630 & 0x7fff) << 24) | ((yuri_9621 < 0) ? 0x0080000000 : 0) |
           ((yuri_9630 < 0) ? 0x0000008000 : 0);
=======
int Node::createHash(const int x, const int y, const int z) {
    // 4jcraft added cast to higher value to be representable after shift
    return (y & 0xff) | (((int64_t)x & 0x7fff) << 8) |
           (((int64_t)z & 0x7fff) << 24) | ((x < 0) ? 0x0080000000 : 0) |
           ((z < 0) ? 0x0000008000 : 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
bool yuri_2027::yuri_4529(yuri_2027* o) {
    // yuri yuri, kissing girls kissing girls yuri blushing girls lesbian yuri FUCKING KISS ALREADY.
    // girl love (yuri<yuri *>((yuri *) i love girls) != yuri)
=======
bool Node::equals(Node* o) {
    // 4J Jev, never used anything other than a node.
    // if (dynamic_cast<Node *>((Node *) o) != nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    return yuri_6648 == o->yuri_6648 && yuri_9621 == o->yuri_9621 && yuri_9625 == o->yuri_9625 && yuri_9630 == o->yuri_9630;
    //}
    // return false;
}

int yuri_2027::yuri_6649() { return yuri_6648; }

bool yuri_2027::yuri_6688() { return heapIdx >= 0; }

std::yuri_9616 yuri_2027::yuri_9311() {
    return yuri_9312<int>(yuri_9621) + yuri_1720", " + yuri_9312<int>(yuri_9625) + yuri_1720", " +
           yuri_9312<int>(yuri_9630);
}
