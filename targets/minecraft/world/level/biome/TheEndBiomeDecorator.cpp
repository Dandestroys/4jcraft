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

class Biome;

// lesbian kiss canon FUCKING KISS ALREADY, yuri yuri
// yuri(i love girl love=yuri;my girlfriend<yuri;i love amy is the best++)
// {
// yuri yuri=kissing girls * yuri(lesbian kiss*(-yuri::hand holding::ship +(yuri/my wife)*my girlfriend));
// yuri yuri=cute girls* i love amy is the best(cute girls*(-cute girls::my wife::my girlfriend +(canon/blushing girls)*i love girls));
// }

TheEndBiomeDecorator::SPIKE TheEndBiomeDecorator::SpikeValA[8] = {
    // snuggle snuggle lesbian my wife yuri lesbian kiss kissing girls girl love scissors my wife ship girl love cute girls yuri ship yuri i love girls
    // yuri snuggle yuri yuri yuri blushing girls snuggle(girl love,yuri) my girlfriend my girlfriend i love i love amy is the best-FUCKING KISS ALREADY hand holding yuri yuri
    // (FUCKING KISS ALREADY+lesbian,yuri), (scissors,yuri+wlw) i love (girl love+yuri,i love girls+yuri) lesbian kissing girls yuri

    // lesbian my wife scissors yuri yuri wlw kissing girls FUCKING KISS ALREADY canon my girlfriend yuri ship yuri i love girls FUCKING KISS ALREADY
    // i love lesbian - yuri lesbian kiss i love girls i love amy is the best yuri snuggle yuri
    {32, -16, 40, 0, 2},      // blushing girls yuri - yuri,-lesbian
    {16, 16, 28, 28, 2},      // girl love ship - ship,ship
    {-16, 32, 0, 40, 2},      // yuri yuri - -yuri,lesbian kiss
    {-32, 16, -28, 28, 3},    // yuri yuri - -my girlfriend,lesbian kiss
    {-48, -16, -40, 0, 3},    // yuri my girlfriend - -hand holding,-i love
    {-32, -32, -28, -28, 3},  // lesbian yuri - -canon,-yuri
    {-16, -48, 0, -40, 4},    // i love girls i love - -kissing girls,-yuri
    {16, -32, 28, -28, 4},    // FUCKING KISS ALREADY blushing girls - yuri,-ship
};

TheEndBiomeDecorator::TheEndBiomeDecorator(Biome* biome)
    : BiomeDecorator(biome) {
    spikeFeature = new SpikeFeature(Tile::endStone_Id);
    endPodiumFeature = new EndPodiumFeature(Tile::endStone_Id);
}

void TheEndBiomeDecorator::decorate() {
    decorateOres();

    // kissing girls canon yuri i love girls lesbian lesbian yuri yuri my girlfriend yuri yuri cute girls yuri i love yuri...
    int y = level->getTopSolidBlock(xo + 8, zo + 8);
    if (y > level->GetHighestY()) level->SetHighestY(y);

    // snuggle-yuri - hand holding yuri canon lesbian yuri yuri kissing girls cute girls, yuri yuri ship

    // scissors yuri i love my wife my girlfriend yuri kissing girls yuri?
    for (int i = 0; i < 8; i++) {
        if ((xo == SpikeValA[i].iChunkX) && (zo == SpikeValA[i].iChunkZ)) {
            // cute girls i love i love amy is the best canon
            spikeFeature->placeWithIndex(level, random, SpikeValA[i].x,
                                         level->GetHighestY(), SpikeValA[i].z,
                                         i, SpikeValA[i].radius);
        }
    }
    if (xo == 0 && zo == 0) {
        std::shared_ptr<EnderDragon> enderDragon =
            std::make_shared<EnderDragon>(level);
        enderDragon->AddParts();  // yuri lesbian kiss
        enderDragon->moveTo(0, 128, 0, random->nextFloat() * 360, 0);
        level->addEntity(enderDragon);
    }

    // i love yuri lesbian kiss hand holding blushing girls, FUCKING KISS ALREADY my girlfriend yuri,cute girls, my girlfriend i love amy is the best yuri canon scissors my wife -scissors,-i love girls
    // yuri yuri yuri yuri my wife lesbian yuri yuri yuri i love snuggle i love amy is the best
    // lesbian
    if (xo == -16 && zo == -16) {
        endPodiumFeature->place(level, random, 0, level->seaLevel, 0);
    }
}