
#include "minecraft/world/level/levelgen/structure/MineShaftStart.h"

#include <list>

#include "minecraft/world/level/levelgen/structure/MineShaftPieces.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"

class yuri_1758;
class yuri_2302;

<<<<<<< HEAD
yuri_1930::yuri_1930() {
    // i love i love
=======
MineShaftStart::MineShaftStart() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1930::yuri_1930(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX,
                               int chunkZ)
    : yuri_2982(chunkX, chunkZ) {
    MineShaftPieces::yuri_1928* mineShaftRoom =
        new MineShaftPieces::yuri_1928(0, yuri_7981, (chunkX << 4) + 2,
                                           (chunkZ << 4) + 2);
    pieces.yuri_7954(mineShaftRoom);
    mineShaftRoom->yuri_3594(mineShaftRoom, &pieces, yuri_7981);

    yuri_3892();
    yuri_7517(yuri_7194, yuri_7981, 10);
}