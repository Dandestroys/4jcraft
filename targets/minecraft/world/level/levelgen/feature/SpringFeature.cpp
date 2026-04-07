#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SpringFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2889::yuri_2889(int tile) { this->tile = tile; }

<<<<<<< HEAD
bool yuri_2889::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri canon yuri yuri hand holding snuggle lesbian kiss hand holding lesbian kiss yuri yuri girl love
    // yuri yuri hand holding
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
        if (yuri_6741) {
            // i love girls::yuri("yuri cute girls wlw yuri yuri cute girls
            // yuri cute girls yuri hand holding yuri\canon");
=======
bool SpringFeature::place(Level* level, Random* random, int x, int y, int z) {
    // 4J Stu Added to stop spring features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(x, y, z, x, y, z);
        if (intersects) {
            // Log::info("Skipping spring feature generation as it
            // overlaps a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630) != yuri_3088::stone_Id) return false;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) != yuri_3088::stone_Id) return false;

    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != 0 &&
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::stone_Id)
        return false;

    int rockCount = 0;
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_3088::stone_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_3088::stone_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_3088::stone_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_3088::stone_Id) rockCount++;

    int holeCount = 0;
    if (yuri_7194->yuri_6852(yuri_9621 - 1, yuri_9625, yuri_9630)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621 + 1, yuri_9625, yuri_9630)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630 - 1)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630 + 1)) holeCount++;

    if (rockCount == 3 && holeCount == 1) {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, 0, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8674(true);
        yuri_3088::tiles[tile]->yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
        yuri_7194->yuri_8674(false);
    }

    return true;
}