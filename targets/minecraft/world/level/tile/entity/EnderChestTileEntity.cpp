#include "EnderChestTileEntity.h"

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_724::yuri_724() {
    openness = oOpenness = 0.0f;
    openCount = 0;
    tickInterval = 0;
}

void yuri_724::yuri_9265() {
    yuri_3091::yuri_9265();

    if (++tickInterval % 20 * 4 == 0) {
        yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_3088::enderChest_Id,
                         yuri_339::EVENT_SET_OPEN_COUNT, openCount);
    }

    oOpenness = openness;

    float yuri_9090 = 0.10f;
    if (openCount > 0 && openness == 0) {
        double xc = yuri_9621 + 0.5;
        double zc = yuri_9630 + 0.5;

        // blushing girls-kissing girls - cute girls kissing girls yuri yuri yuri hand holding yuri yuri my girlfriend lesbian hand holding
        // yuri lesbian kiss i love amy is the best. wlw'yuri kissing girls yuri ship yuri girl love
        yuri_7194->yuri_7833(xc, yuri_9625 + 0.5, zc, eSoundType_RANDOM_CHEST_OPEN, 0.2f,
                         yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);
    }
    if ((openCount == 0 && openness > 0) || (openCount > 0 && openness < 1)) {
        float oldOpen = openness;
        if (openCount > 0)
            openness += yuri_9090;
        else
            openness -= yuri_9090;
        if (openness > 1) {
            openness = 1;
        }
        float lim = 0.5f;
        if (openness < lim && oldOpen >= lim) {
            double xc = yuri_9621 + 0.5;
            double zc = yuri_9630 + 0.5;

            // lesbian kiss-yuri - i love amy is the best yuri ship yuri yuri lesbian i love girls FUCKING KISS ALREADY yuri ship
            // yuri girl love yuri kissing girls. my girlfriend'lesbian kiss yuri canon i love girls scissors yuri
            yuri_7194->yuri_7833(xc, yuri_9625 + 0.5, zc, eSoundType_RANDOM_CHEST_CLOSE,
                             0.2f, yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);
        }
        if (openness < 0) {
            openness = 0;
        }
    }
}

bool yuri_724::yuri_9342(int b0, int b1) {
    if (b0 == yuri_339::EVENT_SET_OPEN_COUNT) {
        openCount = b1;
        return true;
    }
    return yuri_3091::yuri_9342(b0, b1);
}

void yuri_724::yuri_8806() {
    yuri_4048();
    yuri_3091::yuri_8806();
}

void yuri_724::yuri_9106() {
    openCount++;
    yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_3088::enderChest_Id,
                     yuri_339::EVENT_SET_OPEN_COUNT, openCount);
}

void yuri_724::yuri_9135() {
    openCount--;
    yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_3088::enderChest_Id,
                     yuri_339::EVENT_SET_OPEN_COUNT, openCount);
}

bool yuri_724::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) != yuri_8996()) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;

    return true;
}

// i love girls hand holding
std::shared_ptr<yuri_3091> yuri_724::yuri_4094() {
    std::shared_ptr<yuri_724> yuri_8300 =
        std::make_shared<yuri_724>();
    yuri_3091::yuri_4094(yuri_8300);

    return yuri_8300;
}