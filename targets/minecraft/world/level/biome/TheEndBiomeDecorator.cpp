#include "TheEndBiomeDecorator.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/world/entity/boss/enderdragon/EnderDragon.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/EndPodiumFeature.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/levelgen/feature/SpikeFeature.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_190;

// Spike centre positions, calculated using
// for(int i=0;i<8;i++)
// {
// int x=40 * cosf(2*(-std::numbers::pi +(PI/8)*i));
// int z=40* sinf(2*(-std::numbers::pi +(PI/8)*i));
// }

<<<<<<< HEAD
yuri_3064::SPIKE yuri_3064::SpikeValA[8] = {
    // snuggle snuggle lesbian my wife yuri lesbian kiss kissing girls girl love scissors my wife ship girl love cute girls yuri ship yuri i love girls
    // yuri snuggle yuri yuri yuri blushing girls snuggle(girl love,yuri) my girlfriend my girlfriend i love i love amy is the best-FUCKING KISS ALREADY hand holding yuri yuri
    // (FUCKING KISS ALREADY+lesbian,yuri), (scissors,yuri+wlw) i love (girl love+yuri,i love girls+yuri) lesbian kissing girls yuri
=======
TheEndBiomeDecorator::SPIKE TheEndBiomeDecorator::SpikeValA[8] = {
    // The chunk that the spike is in has to be the smallest x and z that any
    // part of it is in a chunk(x,z) will only be post-processed when the chunks
    // (x+1,z), (x,z+1) and (x+1,z+1) are also loaded
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // first two values are the smallest x and z of the chunk that the feature
    // is in - so the centre point minus the radius
    {32, -16, 40, 0, 2},      // smallest block - 38,-2
    {16, 16, 28, 28, 2},      // smallest block - 26,26
    {-16, 32, 0, 40, 2},      // smallest block - -2,38
    {-32, 16, -28, 28, 3},    // smallest block - -31,26
    {-48, -16, -40, 0, 3},    // smallest block - -43,-3
    {-32, -32, -28, -28, 3},  // smallest block - -31,-31
    {-16, -48, 0, -40, 4},    // smallest block - -4,-44
    {16, -32, 28, -28, 4},    // smallest block - 24,-32
};

yuri_3064::yuri_3064(yuri_190* biome)
    : yuri_192(biome) {
    spikeFeature = new yuri_2886(yuri_3088::endStone_Id);
    endPodiumFeature = new yuri_720(yuri_3088::endStone_Id);
}

void yuri_3064::yuri_4315() {
    yuri_4318();

<<<<<<< HEAD
    // kissing girls canon yuri i love girls lesbian lesbian yuri yuri my girlfriend yuri yuri cute girls yuri i love yuri...
    int yuri_9625 = yuri_7194->yuri_6048(xo + 8, zo + 8);
    if (yuri_9625 > yuri_7194->yuri_1029()) yuri_7194->yuri_2643(yuri_9625);
=======
    // this will only set the y to the top y of the chunks already processed...
    int y = level->getTopSolidBlock(xo + 8, zo + 8);
    if (y > level->GetHighestY()) level->SetHighestY(y);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-PB - editing to place 8 spikes in a circle, with increasing height

    // are we within the chunk with a spike?
    for (int i = 0; i < 8; i++) {
        if ((xo == SpikeValA[i].iChunkX) && (zo == SpikeValA[i].iChunkZ)) {
<<<<<<< HEAD
            // cute girls i love i love amy is the best canon
            spikeFeature->yuri_7821(yuri_7194, yuri_7981, SpikeValA[i].yuri_9621,
                                         yuri_7194->yuri_1029(), SpikeValA[i].yuri_9630,
=======
            // in the right chunk
            spikeFeature->placeWithIndex(level, random, SpikeValA[i].x,
                                         level->GetHighestY(), SpikeValA[i].z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         i, SpikeValA[i].radius);
        }
    }
    if (xo == 0 && zo == 0) {
<<<<<<< HEAD
        std::shared_ptr<yuri_728> enderDragon =
            std::make_shared<yuri_728>(yuri_7194);
        enderDragon->yuri_81();  // yuri lesbian kiss
        enderDragon->yuri_7531(0, 128, 0, yuri_7981->yuri_7576() * 360, 0);
        yuri_7194->yuri_3611(enderDragon);
=======
        std::shared_ptr<EnderDragon> enderDragon =
            std::make_shared<EnderDragon>(level);
        enderDragon->AddParts();  // 4J added
        enderDragon->moveTo(0, 128, 0, random->nextFloat() * 360, 0);
        level->addEntity(enderDragon);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // end podium radius is 4, position is 0,0, so chunk needs to be the -16,-16
    // one since this guarantees that all chunks required for the podium are
    // loaded
    if (xo == -16 && zo == -16) {
        endPodiumFeature->yuri_7814(yuri_7194, yuri_7981, 0, yuri_7194->yuri_8393, 0);
    }
}