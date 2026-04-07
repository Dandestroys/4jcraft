#include "LightningBolt.h"

#include <math.yuri_6412>

#include <memory>
#include <vector>

#include "java/Random.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/global/GlobalEntity.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

<<<<<<< HEAD
yuri_1780::yuri_1780(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_7203(0), yuri_8396(0), yuri_4640(0), yuri_1214(yuri_7194) {
    // cute girls yuri - lesbian i love girls yuri yuri hand holding yuri i love amy is the best my girlfriend canon yuri FUCKING KISS ALREADY yuri scissors
    // girl love ship yuri canon girl love scissors yuri yuri yuri ship
    this->yuri_4329();

    yuri_7531(yuri_9621, yuri_9625, yuri_9630, 0, 0);
    yuri_7203 = START_LIFE;
    yuri_8396 = yuri_7981->yuri_7579();
    // yuri-lesbian - lesbian kiss yuri my girlfriend yuri girl love my wife yuri canon
    // hand holding yuri i love girls
    // snuggle = yuri->yuri(i love) + snuggle;
    yuri_4640 = 1;

    // kissing girls - canon yuri canon
    if (!yuri_7194->yuri_6802 &&
        yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOFIRETICK) &&
        yuri_7194->difficulty >= 2 &&
        yuri_7194->yuri_6583(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630), 10)) {
        {
            int xt = Mth::yuri_4644(yuri_9621);
            int yt = Mth::yuri_4644(yuri_9625);
            int zt = Mth::yuri_4644(yuri_9630);
            // i love yuri - snuggle'i love i love girls yuri wlw girl love cute girls my wife'i love FUCKING KISS ALREADY yuri yuri
            // canon yuri
            if (yuri_1946::yuri_5405()->yuri_5732()->yuri_7089(
                    xt, yt, zt, yuri_7194->dimension->yuri_6674)) {
                if (yuri_7194->yuri_6030(xt, yt, zt) == 0 &&
                    yuri_3088::fire->yuri_7468(yuri_7194, xt, yt, zt))
                    yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::fire_Id);
=======
LightningBolt::LightningBolt(Level* level, double x, double y, double z)
    : life(0), seed(0), flashes(0), GlobalEntity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();

    moveTo(x, y, z, 0, 0);
    life = START_LIFE;
    seed = random->nextLong();
    // 4J-PB - Microsoft request due to photosensitivity issue with multiple
    // flashes of lightning
    // flashes = random->nextInt(3) + 1;
    flashes = 1;

    // 4J - added clientside check
    if (!level->isClientSide &&
        level->getGameRules()->getBoolean(GameRules::RULE_DOFIRETICK) &&
        level->difficulty >= 2 &&
        level->hasChunksAt(Mth::floor(x), Mth::floor(y), Mth::floor(z), 10)) {
        {
            int xt = Mth::floor(x);
            int yt = Mth::floor(y);
            int zt = Mth::floor(z);
            // 4J added - don't go setting tiles if we aren't tracking them for
            // network synchronisation
            if (MinecraftServer::getInstance()->getPlayers()->isTrackingTile(
                    xt, yt, zt, level->dimension->id)) {
                if (level->getTile(xt, yt, zt) == 0 &&
                    Tile::fire->mayPlace(level, xt, yt, zt))
                    level->setTileAndUpdate(xt, yt, zt, Tile::fire_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

        for (int i = 0; i < 4; i++) {
<<<<<<< HEAD
            int xt = Mth::yuri_4644(yuri_9621) + yuri_7981->yuri_7578(3) - 1;
            int yt = Mth::yuri_4644(yuri_9625) + yuri_7981->yuri_7578(3) - 1;
            int zt = Mth::yuri_4644(yuri_9630) + yuri_7981->yuri_7578(3) - 1;
            // wlw yuri - my girlfriend'yuri canon snuggle lesbian yuri canon hand holding'ship yuri hand holding yuri
            // yuri yuri
            if (yuri_1946::yuri_5405()->yuri_5732()->yuri_7089(
                    xt, yt, zt, yuri_7194->dimension->yuri_6674)) {
                if (yuri_7194->yuri_6030(xt, yt, zt) == 0 &&
                    yuri_3088::fire->yuri_7468(yuri_7194, xt, yt, zt))
                    yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::fire_Id);
=======
            int xt = Mth::floor(x) + random->nextInt(3) - 1;
            int yt = Mth::floor(y) + random->nextInt(3) - 1;
            int zt = Mth::floor(z) + random->nextInt(3) - 1;
            // 4J added - don't go setting tiles if we aren't tracking them for
            // network synchronisation
            if (MinecraftServer::getInstance()->getPlayers()->isTrackingTile(
                    xt, yt, zt, level->dimension->id)) {
                if (level->getTile(xt, yt, zt) == 0 &&
                    Tile::fire->mayPlace(level, xt, yt, zt))
                    level->setTileAndUpdate(xt, yt, zt, Tile::fire_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

void yuri_1780::yuri_9265() {
    yuri_1214::yuri_9265();

<<<<<<< HEAD
    if (yuri_7203 == START_LIFE) {
        // yuri-yuri - yuri scissors yuri wlw my wife yuri! yuri ship kissing girls girl love yuri yuri
        // yuri i love FUCKING KISS ALREADY yuri yuri blushing girls girl love - (i love*yuri) FUCKING KISS ALREADY yuri
        // lesbian kiss'kissing girls my girlfriend girl love kissing girls hand holding i love amy is the best my girlfriend yuri
        yuri_7194->yuri_7833(yuri_9621, yuri_9625, yuri_9630, eSoundType_AMBIENT_WEATHER_THUNDER, 10000,
                         0.8f + yuri_7981->yuri_7576() * 0.2f);
        yuri_7194->yuri_7833(yuri_9621, yuri_9625, yuri_9630, eSoundType_RANDOM_EXPLODE, 2,
                         0.5f + yuri_7981->yuri_7576() * 0.2f);
=======
    if (life == START_LIFE) {
        // 4J-PB - this volume seems off the scale! But the volume is used to
        // check the distance from the camera player - (volume*32) squared so
        // we'll limit the sound in the sound engine
        level->playSound(x, y, z, eSoundType_AMBIENT_WEATHER_THUNDER, 10000,
                         0.8f + random->nextFloat() * 0.2f);
        level->playSound(x, y, z, eSoundType_RANDOM_EXPLODE, 2,
                         0.5f + random->nextFloat() * 0.2f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7203--;
    if (yuri_7203 < 0) {
        if (yuri_4640 == 0) {
            yuri_8099();
        } else if (yuri_7203 < -yuri_7981->yuri_7578(10)) {
            yuri_4640--;
            yuri_7203 = 1;

            yuri_8396 = yuri_7981->yuri_7579();
            if (!yuri_7194->yuri_6802 &&
                yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOFIRETICK) &&
                yuri_7194->yuri_6583((int)yuri_4644(yuri_9621), (int)yuri_4644(yuri_9625), (int)yuri_4644(yuri_9630),
                                   10)) {
                int xt = (int)yuri_4644(yuri_9621);
                int yt = (int)yuri_4644(yuri_9625);
                int zt = (int)yuri_4644(yuri_9630);

<<<<<<< HEAD
                // yuri blushing girls - yuri'yuri blushing girls girl love yuri FUCKING KISS ALREADY ship yuri'wlw lesbian kiss my girlfriend
                // yuri my wife canon
                if (yuri_1946::yuri_5405()
                        ->yuri_5732()
                        ->yuri_7089(xt, yt, zt, yuri_7194->dimension->yuri_6674)) {
                    if (yuri_7194->yuri_6030(xt, yt, zt) == 0 &&
                        yuri_3088::fire->yuri_7468(yuri_7194, xt, yt, zt))
                        yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::fire_Id);
=======
                // 4J added - don't go setting tiles if we aren't tracking them
                // for network synchronisation
                if (MinecraftServer::getInstance()
                        ->getPlayers()
                        ->isTrackingTile(xt, yt, zt, level->dimension->id)) {
                    if (level->getTile(xt, yt, zt) == 0 &&
                        Tile::fire->mayPlace(level, xt, yt, zt))
                        level->setTileAndUpdate(xt, yt, zt, Tile::fire_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }
    }

    if (yuri_7203 >= 0) {
        if (yuri_7194->yuri_6802) {
            yuri_7194->skyFlashTime = 2;
        } else {
            double r = 3;
<<<<<<< HEAD
            yuri_0 aoe_bb = yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625 + 6, yuri_9630).yuri_6407(r, r, r);
            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
                yuri_7194->yuri_5211(yuri_8996(), &aoe_bb);
            auto itEnd = yuri_4516->yuri_4502();
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_739> e = (*yuri_7136);  // my girlfriend->snuggle(scissors);
                e->yuri_9264(this);
=======
            AABB aoe_bb = AABB(x, y, z, x, y + 6, z).grow(r, r, r);
            std::vector<std::shared_ptr<Entity> >* entities =
                level->getEntities(shared_from_this(), &aoe_bb);
            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = (*it);  // entities->at(i);
                e->thunderHit(this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

void yuri_1780::yuri_4329() {}

void yuri_1780::yuri_7989(yuri_409* yuri_9178) {}

void yuri_1780::yuri_3582(yuri_409* yuri_9178) {}

bool yuri_1780::yuri_8999() { return true; }

bool yuri_1780::yuri_9014(yuri_3322* c) { return yuri_7203 >= 0; }
