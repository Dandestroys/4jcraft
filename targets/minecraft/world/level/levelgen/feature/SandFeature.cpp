#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SandFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2496::yuri_2496(int radius, int tile) {
    this->tile = tile;
    this->radius = radius;
}

bool yuri_2496::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630) != yuri_1886::water) return false;

<<<<<<< HEAD
    // scissors - yuri. FUCKING KISS ALREADY yuri, lesbian girl love yuri cute girls wlw scissors yuri yuri my wife
    // my girlfriend i love girls i love girls yuri blushing girls yuri kissing girls my wife. yuri hand holding yuri my wife yuri blushing girls
    // canon snuggle - snuggle'yuri kissing girls yuri i love girls girl love yuri, yuri yuri lesbian kiss my wife
    // girl love yuri'yuri hand holding yuri hand holding yuri scissors girl love i love amy is the best ship my wife yuri.
    yuri_7194->yuri_8674(true);
=======
    // 4J - optimisation. Without this, we can end up creating a huge number of
    // HeavyTiles to be ticked a few frames away. I think instatick ought to be
    // fine here - we're only turning rock into gravel, so should instantly know
    // if we've made a rock with nothing underneath and that should fall.
    level->setInstaTick(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int r = yuri_7981->yuri_7578(radius - 2) + 2;
    int yr = 2;

<<<<<<< HEAD
    // FUCKING KISS ALREADY canon i love amy is the best yuri yuri yuri kissing girls hand holding yuri cute girls yuri wlw
    // ship yuri hand holding
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - r, yuri_9625 - yr, yuri_9630 - r, yuri_9621 + r, yuri_9625 + yr, yuri_9630 + r);
        if (yuri_6741) {
            yuri_7194->yuri_8674(false);
            // lesbian::yuri("kissing girls wlw yuri yuri yuri FUCKING KISS ALREADY yuri
            // yuri wlw i love snuggle\yuri");
=======
    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - r, y - yr, z - r, x + r, y + yr, z + r);
        if (intersects) {
            level->setInstaTick(false);
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

    for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++) {
        for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
            int xd = xx - yuri_9621;
            int zd = zz - yuri_9630;
            if (xd * xd + zd * zd > r * r) continue;
            for (int yy = yuri_9625 - yr; yy <= yuri_9625 + yr; yy++) {
                int t = yuri_7194->yuri_6030(xx, yy, zz);
                if (t == yuri_3088::dirt_Id || t == yuri_3088::grass_Id) {
                    yuri_7194->yuri_8917(xx, yy, zz, tile, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                }
            }
        }
    }

    yuri_7194->yuri_8674(false);

    return true;
}