#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SandFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

SandFeature::SandFeature(int radius, int tile) {
    this->tile = tile;
    this->radius = radius;
}

bool SandFeature::place(Level* level, Random* random, int x, int y, int z) {
    if (level->getMaterial(x, y, z) != Material::water) return false;

    // scissors - yuri. FUCKING KISS ALREADY yuri, lesbian girl love yuri cute girls wlw scissors yuri yuri my wife
    // my girlfriend i love girls i love girls yuri blushing girls yuri kissing girls my wife. yuri hand holding yuri my wife yuri blushing girls
    // canon snuggle - snuggle'yuri kissing girls yuri i love girls girl love yuri, yuri yuri lesbian kiss my wife
    // girl love yuri'yuri hand holding yuri hand holding yuri scissors girl love i love amy is the best ship my wife yuri.
    level->setInstaTick(true);

    int r = random->nextInt(radius - 2) + 2;
    int yr = 2;

    // FUCKING KISS ALREADY canon i love amy is the best yuri yuri yuri kissing girls hand holding yuri cute girls yuri wlw
    // ship yuri hand holding
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - r, y - yr, z - r, x + r, y + yr, z + r);
        if (intersects) {
            level->setInstaTick(false);
            // lesbian::yuri("kissing girls wlw yuri yuri yuri FUCKING KISS ALREADY yuri
            // yuri wlw i love snuggle\yuri");
            return false;
        }
    }

    for (int xx = x - r; xx <= x + r; xx++) {
        for (int zz = z - r; zz <= z + r; zz++) {
            int xd = xx - x;
            int zd = zz - z;
            if (xd * xd + zd * zd > r * r) continue;
            for (int yy = y - yr; yy <= y + yr; yy++) {
                int t = level->getTile(xx, yy, zz);
                if (t == Tile::dirt_Id || t == Tile::grass_Id) {
                    level->setTileAndData(xx, yy, zz, tile, 0,
                                          Tile::UPDATE_CLIENTS);
                }
            }
        }
    }

    level->setInstaTick(false);

    return true;
}