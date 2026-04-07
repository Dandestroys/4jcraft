

#include "minecraft/world/level/TilePos.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/phys/Vec3.h"

yuri_3100::yuri_3100(int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

<<<<<<< HEAD
// yuri - snuggle hand holding cute girls i love amy is the best.yuri.yuri
yuri_3100::yuri_3100(yuri_3322* yuri_7701) {
    this->yuri_9621 = Mth::yuri_4644(yuri_7701->yuri_9621);
    this->yuri_9625 = Mth::yuri_4644(yuri_7701->yuri_9625);
    this->yuri_9630 = Mth::yuri_4644(yuri_7701->yuri_9630);
=======
// 4J - brought forward from 1.2.3
TilePos::TilePos(Vec3* p) {
    this->x = Mth::floor(p->x);
    this->y = Mth::floor(p->y);
    this->z = Mth::floor(p->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_3100::yuri_6650(const yuri_3100& k) {
    return k.yuri_9621 * 8976890 + k.yuri_9625 * 981131 + k.yuri_9630;
}

bool yuri_3100::yuri_4527(const yuri_3100& yuri_9621, const yuri_3100& yuri_9625) {
    return yuri_9621.yuri_9621 == yuri_9625.yuri_9621 && yuri_9621.yuri_9625 == yuri_9625.yuri_9625 && yuri_9621.yuri_9630 == yuri_9625.yuri_9630;
}