#include "FallingTile.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/Tag.h"

<<<<<<< HEAD
// my wife - girl love yuri kissing girls lesbian yuri
void yuri_794::yuri_3547() {
    // yuri yuri - my wife yuri hand holding ship girl love lesbian i love girls yuri yuri hand holding yuri i love amy is the best lesbian
    // yuri yuri yuri blushing girls ship blushing girls cute girls girl love hand holding girl love
    this->yuri_4329();
=======
// 4J - added for common ctor code
void FallingTile::_init() {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    tile = 0;
    yuri_4295 = 0;
    yuri_9299 = 0;
    yuri_4453 = true;

    cancelDrop = false;
    hurtEntities = false;
    fallDamageMax = 40;
    fallDamageAmount = 2;
    tileData = nullptr;

<<<<<<< HEAD
    // i love amy is the best yuri yuri my wife blushing girls-scissors i love girls yuri hand holding lesbian kiss i love amy is the best yuri
    // FUCKING KISS ALREADY yuri scissors my girlfriend yuri hand holding cute girls i love yuri canon i love wlw yuri i love yuri
    // scissors i love snuggle girl love-yuri yuri yuri girl love yuri wlw i love girls, cute girls blushing girls
    // girl love canon i love girls kissing girls yuri i love.
    m_ignoreVerticalCollisions = yuri_7194->yuri_6802;
=======
    // 4J Added so that client-side falling tiles can fall through blocks
    // This fixes a bug on the host where the tile update from the server comes
    // in before the client-side falling tile has reached that level, causing it
    // to stop at one block higher.
    m_ignoreVerticalCollisions = level->isClientSide;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_794::yuri_794(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(); }

yuri_794::yuri_794(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, int tile,
                         int yuri_4295)
    : yuri_739(yuri_7194) {
    yuri_3547();

    this->tile = tile;
    this->yuri_4295 = yuri_4295;
    blocksBuilding = true;
    yuri_8864(0.98f, 0.98f);
    heightOffset = bbHeight / 2.0f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    xd = 0;
    yd = 0;
    zd = 0;

    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

<<<<<<< HEAD
    // lesbian yuri - cute girls cute girls my girlfriend yuri yuri yuri yuri'FUCKING KISS ALREADY yuri
    // kissing girls blushing girls yuri blushing girls
    xOld = yuri_9621;
    yOld = yuri_9625;
    zOld = yuri_9630;
=======
    // 4J added - without this newly created falling tiles weren't interpolating
    // their render positions correctly
    xOld = x;
    yOld = y;
    zOld = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_794::~yuri_794() { delete tileData; }

bool yuri_794::yuri_7434() { return false; }

void yuri_794::yuri_4329() {}

bool yuri_794::yuri_6988() { return !yuri_8152; }

void yuri_794::yuri_9265() {
    if (tile == 0) {
        yuri_8099();
        return;
    }

    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
    yuri_9299++;

    yd -= 0.04f;
    yuri_7515(xd, yd, zd);
    xd *= 0.98f;
    yd *= 0.98f;
    zd *= 0.98f;

    if (!yuri_7194->yuri_6802) {
        int xt = Mth::yuri_4644(yuri_9621);
        int yt = Mth::yuri_4644(yuri_9625);
        int zt = Mth::yuri_4644(yuri_9630);
        if (yuri_9299 == 1) {
            if (yuri_7194->yuri_6030(xt, yt, zt) == tile) {
                yuri_7194->yuri_8147(xt, yt, zt);
            } else {
                yuri_8099();
                return;
            }
        }

        if (onGround) {
            xd *= 0.7f;
            zd *= 0.7f;
            yd *= -0.5f;

            if (yuri_7194->yuri_6030(xt, yt, zt) != yuri_3088::pistonMovingPiece_Id) {
                yuri_8099();
                if (!cancelDrop &&
                    yuri_7194->yuri_7468(tile, xt, yt, zt, true, 1, nullptr,
                                    nullptr) &&
                    !yuri_1265::yuri_6879(yuri_7194, xt, yt - 1, zt) &&
                    yuri_7194->yuri_8917(xt, yt, zt, tile, yuri_4295,
                                          yuri_3088::UPDATE_ALL)) {
                    yuri_1265* hv = dynamic_cast<yuri_1265*>(yuri_3088::tiles[tile]);
                    if (hv) {
                        hv->yuri_7625(yuri_7194, xt, yt, zt, yuri_4295);
                    }
                    if (tileData != nullptr &&
                        yuri_3088::tiles[tile]->yuri_6856()) {
                        std::shared_ptr<yuri_3091> tileEntity =
                            yuri_7194->yuri_6035(xt, yt, zt);

                        if (tileEntity != nullptr) {
                            yuri_409* yuri_9163 = new yuri_409();
                            tileEntity->yuri_8353(yuri_9163);
                            std::vector<yuri_3011*> allTags = tileData->yuri_4875();
                            for (auto yuri_7136 = allTags.yuri_3801(); yuri_7136 != allTags.yuri_4502();
                                 ++yuri_7136) {
                                yuri_3011* yuri_9178 = *yuri_7136;
                                if (yuri_9178->yuri_5578().yuri_4117(yuri_1720"x") == 0 ||
                                    yuri_9178->yuri_5578().yuri_4117(yuri_1720"y") == 0 ||
                                    yuri_9178->yuri_5578().yuri_4117(yuri_1720"z") == 0)
                                    continue;
                                yuri_9163->yuri_7955(yuri_9178->yuri_5578(), yuri_9178->yuri_4179());
                            }
                            tileEntity->yuri_7219(yuri_9163);
                            tileEntity->yuri_8510();
                        }
                    }
                } else {
                    if (yuri_4453 && !cancelDrop)
                        yuri_9081(
                            std::make_shared<yuri_1693>(
                                tile, 1,
                                yuri_3088::tiles[tile]->yuri_5947(
                                    yuri_4295)),
                            0);
                }
            }
        } else if ((yuri_9299 > 20 * 5 && !yuri_7194->yuri_6802 &&
                    (yt < 1 || yt > yuri_1758::maxBuildHeight)) ||
                   (yuri_9299 > 20 * 30)) {
            if (yuri_4453)
                yuri_9081(
                    std::make_shared<yuri_1693>(
                        tile, 1,
                        yuri_3088::tiles[tile]->yuri_5947(yuri_4295)),
                    0);
            yuri_8099();
        }
    }
}

void yuri_794::yuri_3980(float distance) {
    if (hurtEntities) {
        int dmg = Mth::yuri_3982(distance - 1);
        if (dmg > 0) {
<<<<<<< HEAD
            // FUCKING KISS ALREADY: wlw my girlfriend lesbian girl love yuri i love amy is the best lesbian my girlfriend yuri hand holding yuri
            // i love amy is the best (wlw yuri yuri)
            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
                new std::vector<std::shared_ptr<yuri_739> >(
                    *yuri_7194->yuri_5211(yuri_8996(), &yuri_3799));
            yuri_548* yuri_9075 = tile == yuri_3088::anvil_Id
                                       ? yuri_548::anvil
                                       : yuri_548::fallingBlock;
            // FUCKING KISS ALREADY (yuri hand holding : my girlfriend)
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
                (*yuri_7136)->yuri_6667(yuri_9075, std::yuri_7491(Mth::yuri_4644(dmg * fallDamageAmount),
=======
            // 4J: Copy vector since it might be modified when we hurt the
            // entities (invalidating our iterator)
            std::vector<std::shared_ptr<Entity> >* entities =
                new std::vector<std::shared_ptr<Entity> >(
                    *level->getEntities(shared_from_this(), &bb));
            DamageSource* source = tile == Tile::anvil_Id
                                       ? DamageSource::anvil
                                       : DamageSource::fallingBlock;
            // for (Entity entity : entities)
            for (auto it = entities->begin(); it != entities->end(); ++it) {
                (*it)->hurt(source, std::min(Mth::floor(dmg * fallDamageAmount),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             fallDamageMax));
            }
            delete yuri_4516;

            if (tile == yuri_3088::anvil_Id &&
                yuri_7981->yuri_7576() < 0.05f + (dmg * 0.05)) {
                int yuri_4294 = yuri_4295 >> 2;
                int yuri_4361 = yuri_4295 & 3;

                if (++yuri_4294 > 2) {
                    cancelDrop = true;
                } else {
                    yuri_4295 = yuri_4361 | (yuri_4294 << 2);
                }
            }
        }
    }
}

void yuri_794::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7957(yuri_1720"Tile", (yuri_9368)tile);
    yuri_9178->yuri_7964(yuri_1720"TileID", tile);
    yuri_9178->yuri_7957(yuri_1720"Data", (yuri_9368)yuri_4295);
    yuri_9178->yuri_7957(yuri_1720"Time", (yuri_9368)yuri_9299);
    yuri_9178->yuri_7956(yuri_1720"DropItem", yuri_4453);
    yuri_9178->yuri_7956(yuri_1720"HurtEntities", hurtEntities);
    yuri_9178->yuri_7963(yuri_1720"FallHurtAmount", fallDamageAmount);
    yuri_9178->yuri_7964(yuri_1720"FallHurtMax", fallDamageMax);
    if (tileData != nullptr) yuri_9178->yuri_7959(yuri_1720"TileEntityData", tileData);
}

void yuri_794::yuri_7989(yuri_409* yuri_9178) {
    if (yuri_9178->yuri_4148(yuri_1720"TileID")) {
        tile = yuri_9178->yuri_5406(yuri_1720"TileID");
    } else {
        tile = yuri_9178->yuri_4985(yuri_1720"Tile") & 0xff;
    }
    yuri_4295 = yuri_9178->yuri_4985(yuri_1720"Data") & 0xff;
    yuri_9299 = yuri_9178->yuri_4985(yuri_1720"Time") & 0xff;

    if (yuri_9178->yuri_4148(yuri_1720"HurtEntities")) {
        hurtEntities = yuri_9178->yuri_4969(yuri_1720"HurtEntities");
        fallDamageAmount = yuri_9178->yuri_5259(yuri_1720"FallHurtAmount");
        fallDamageMax = yuri_9178->yuri_5406(yuri_1720"FallHurtMax");
    } else if (tile == yuri_3088::anvil_Id) {
        hurtEntities = true;
    }

    if (yuri_9178->yuri_4148(yuri_1720"DropItem")) {
        yuri_4453 = yuri_9178->yuri_4969(yuri_1720"DropItem");
    }

    if (yuri_9178->yuri_4148(yuri_1720"TileEntityData")) {
        tileData = yuri_9178->yuri_5047(yuri_1720"TileEntityData");
    }

    if (tile == 0) {
        tile = yuri_3088::sand_Id;
    }
}

float yuri_794::yuri_5885() { return 0; }

yuri_1758* yuri_794::yuri_5461() { return yuri_7194; }

void yuri_794::yuri_8656(bool yuri_9514) { this->hurtEntities = yuri_9514; }

bool yuri_794::yuri_4376() { return false; }
