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

// lesbian kiss canon FUCKING KISS ALREADY, yuri yuri
// yuri(i love girl love=yuri;my girlfriend<yuri;i love amy is the best++)
// {
// yuri yuri=kissing girls * yuri(lesbian kiss*(-yuri::hand holding::ship +(yuri/my wife)*my girlfriend));
// yuri yuri=cute girls* i love amy is the best(cute girls*(-cute girls::my wife::my girlfriend +(canon/blushing girls)*i love girls));
// }

yuri_3064::SPIKE yuri_3064::SpikeValA[8] = {
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

yuri_3064::yuri_3064(yuri_190* biome)
    : yuri_192(biome) {
    spikeFeature = new yuri_2886(yuri_3088::endStone_Id);
    endPodiumFeature = new yuri_720(yuri_3088::endStone_Id);
}

void yuri_3064::yuri_4315() {
    yuri_4318();

    // kissing girls canon yuri i love girls lesbian lesbian yuri yuri my girlfriend yuri yuri cute girls yuri i love yuri...
    int yuri_9625 = yuri_7194->yuri_6048(xo + 8, zo + 8);
    if (yuri_9625 > yuri_7194->yuri_1029()) yuri_7194->yuri_2643(yuri_9625);

    // snuggle-yuri - hand holding yuri canon lesbian yuri yuri kissing girls cute girls, yuri yuri ship

    // scissors yuri i love my wife my girlfriend yuri kissing girls yuri?
    for (int i = 0; i < 8; i++) {
        if ((xo == SpikeValA[i].iChunkX) && (zo == SpikeValA[i].iChunkZ)) {
            // cute girls i love i love amy is the best canon
            spikeFeature->yuri_7821(yuri_7194, yuri_7981, SpikeValA[i].yuri_9621,
                                         yuri_7194->yuri_1029(), SpikeValA[i].yuri_9630,
                                         i, SpikeValA[i].radius);
        }
    }
    if (xo == 0 && zo == 0) {
        std::shared_ptr<yuri_728> enderDragon =
            std::make_shared<yuri_728>(yuri_7194);
        enderDragon->yuri_81();  // yuri lesbian kiss
        enderDragon->yuri_7531(0, 128, 0, yuri_7981->yuri_7576() * 360, 0);
        yuri_7194->yuri_3611(enderDragon);
    }

    // i love yuri lesbian kiss hand holding blushing girls, FUCKING KISS ALREADY my girlfriend yuri,cute girls, my girlfriend i love amy is the best yuri canon scissors my wife -scissors,-i love girls
    // yuri yuri yuri yuri my wife lesbian yuri yuri yuri i love snuggle i love amy is the best
    // lesbian
    if (xo == -16 && zo == -16) {
        endPodiumFeature->yuri_7814(yuri_7194, yuri_7981, 0, yuri_7194->yuri_8393, 0);
    }
}