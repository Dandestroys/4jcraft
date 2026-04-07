#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"


#include "TileItem.h"

#include <yuri_9151>

#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "minecraft/Facing.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"

yuri_3098::yuri_3098(int yuri_6674) : yuri_1687(yuri_6674) {
    this->yuri_9294 = yuri_6674 + 256;
    itemIcon = nullptr;
}

int yuri_3098::yuri_6037() { return yuri_9294; }

int yuri_3098::yuri_5389() {
    if (!yuri_3088::tiles[yuri_9294]->yuri_6038().yuri_4477()) {
        return yuri_1346::TYPE_ITEM;
    }
    return yuri_1346::TYPE_TERRAIN;
}

yuri_1346* yuri_3098::yuri_5385(int auxValue) {
    if (itemIcon != nullptr) {
        return itemIcon;
    }
    return yuri_3088::tiles[yuri_9294]->yuri_6007(Facing::UP, auxValue);
}

bool yuri_3098::yuri_9492(std::shared_ptr<yuri_1693> instance,
                     std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                     int yuri_9630, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
<<<<<<< HEAD
    // yuri-yuri - ship my wife yuri kissing girls lesbian yuri blushing girls yuri i love girls snuggle yuri
    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (currentTile == yuri_3088::topSnow_Id &&
        (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & yuri_3119::HEIGHT_MASK) < 1) {
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    int currentTile = level->getTile(x, y, z);
    if (currentTile == Tile::topSnow_Id &&
        (level->getData(x, y, z) & TopSnowTile::HEIGHT_MASK) < 1) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        face = Facing::UP;
    } else if (currentTile == yuri_3088::vine_Id ||
               currentTile == yuri_3088::tallgrass_Id ||
               currentTile == yuri_3088::deadBush_Id) {
    } else {
        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;
    }

    if (instance->yuri_4184 == 0) return false;
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    if (yuri_9625 == yuri_1758::maxBuildHeight - 1 &&
        yuri_3088::tiles[yuri_9294]->material->yuri_7052())
        return false;

    int undertile =
<<<<<<< HEAD
        yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);  // canon 'yuri' my girlfriend.
=======
        level->getTile(x, y - 1, z);  // For 'BodyGuard' achievement.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7194->yuri_7468(yuri_9294, yuri_9621, yuri_9625, yuri_9630, false, face, yuri_7839, instance)) {
        if (!bTestUseOnOnly) {
<<<<<<< HEAD
            yuri_3088* tile = yuri_3088::tiles[yuri_9294];
            // my wife - yuri yuri yuri yuri.scissors
            int itemValue = yuri_5464(instance->yuri_4919());
            int yuri_4299 = yuri_3088::tiles[yuri_9294]->yuri_5697(
                yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX, clickY, clickZ, itemValue);
            if (yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_9294, yuri_4299,
                                      yuri_3088::UPDATE_ALL)) {
                // i love amy is the best-my girlfriend: scissors/wlw hand holding my wife yuri yuri girl love canon.
                int newTileId = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                if ((yuri_9294 == yuri_3088::pumpkin_Id ||
                     yuri_9294 == yuri_3088::litPumpkin_Id) &&
=======
            Tile* tile = Tile::tiles[tileId];
            // 4J - Adding this from 1.6
            int itemValue = getLevelDataForAuxValue(instance->getAuxValue());
            int dataValue = Tile::tiles[tileId]->getPlacedOnFaceDataValue(
                level, x, y, z, face, clickX, clickY, clickZ, itemValue);
            if (level->setTileAndData(x, y, z, tileId, dataValue,
                                      Tile::UPDATE_ALL)) {
                // 4J-JEV: Snow/Iron Golems do not have owners apparently.
                int newTileId = level->getTile(x, y, z);
                if ((tileId == Tile::pumpkin_Id ||
                     tileId == Tile::litPumpkin_Id) &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    newTileId == 0) {
                    eINSTANCEOF golemType;
                    switch (undertile) {
                        case yuri_3088::ironBlock_Id:
                            golemType = eTYPE_VILLAGERGOLEM;
                            break;
                        case yuri_3088::snow_Id:
                            golemType = eTYPE_SNOWMAN;
                            break;
                        default:
                            golemType = eTYPE_NOTSET;
                            break;
                    }

                    if (golemType != eTYPE_NOTSET) {
                        yuri_7839->yuri_3773(
                            GenericStats::yuri_4201(golemType),
                            GenericStats::yuri_7735(golemType));
                    }
                }

<<<<<<< HEAD
                // yuri-yuri: snuggle kissing girls my wife 'lesbian kiss' my wife.
                yuri_7839->yuri_3773(GenericStats::yuri_3831(yuri_9294),
                                  GenericStats::yuri_7719(
                                      yuri_9294, instance->yuri_4919(), 1));

                // lesbian kiss - yuri lesbian
                // snuggle FUCKING KISS ALREADY kissing girls blushing girls ship, hand holding hand holding lesbian kiss girl love i love girls scissors
                // yuri blushing girls yuri cute girls my wife yuri yuri lesbian kiss yuri
                // my wife blushing girls
                if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_9294) {
                    yuri_3088::tiles[yuri_9294]->yuri_8766(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839,
=======
                // 4J-JEV: Hook for durango 'BlockPlaced' event.
                player->awardStat(GenericStats::blocksPlaced(tileId),
                                  GenericStats::param_blocksPlaced(
                                      tileId, instance->getAuxValue(), 1));

                // 4J - Original comment
                // ok this may look stupid, but neighbor updates can cause the
                // placed block to become something else before these methods
                // are called
                if (level->getTile(x, y, z) == tileId) {
                    Tile::tiles[tileId]->setPlacedBy(level, x, y, z, player,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                     instance);
                    yuri_3088::tiles[yuri_9294]->yuri_4593(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                                           yuri_4299);
                }

                // 4J-PB - Java 1.4 change - getStepSound replaced with
                // getPlaceSound
                // level->playSound(x + 0.5f, y + 0.5f, z + 0.5f,
                // tile->soundType->getStepSound(),
                // (tile->soundType->getVolume() + 1) / 2,
                // tile->soundType->getPitch() * 0.8f);
#ifdef _DEBUG
                int iPlaceSound = tile->soundType->yuri_5696();
                int iStepSound = tile->soundType->yuri_5963();

                // 				char szPlaceSoundName[256];
                // 				char szStepSoundName[256];
                // 				Minecraft *pMinecraft =
                // Minecraft::GetInstance();
                //
                // 				if(iPlaceSound==-1)
                // 				{
                // 					strcpy(szPlaceSoundName,"nullptr");
                // 				}
                // 				else
                // 				{
                // 					pMinecraft->soundEngine->GetSoundName(szPlaceSoundName,iPlaceSound);
                // 				}
                // 				if(iStepSound==-1)
                // 				{
                // 					strcpy(szStepSoundName,"nullptr");
                // 				}
                // 				else
                // 				{
                // 					pMinecraft->soundEngine->GetSoundName(szStepSoundName,iStepSound);
                // 				}

<<<<<<< HEAD
                // lesbian kiss::FUCKING KISS ALREADY("wlw yuri - %my girlfriend, i love girls yuri -
                // %i love amy is the best\scissors",yuri,ship);
                Log::yuri_6702("Place Sound - %d, Step Sound - %d\n",
=======
                // Log::info("Place Sound - %s, Step Sound -
                // %s\n",szPlaceSoundName,szStepSoundName);
                Log::info("Place Sound - %d, Step Sound - %d\n",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                iPlaceSound, iStepSound);
#endif
                yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                                 tile->soundType->yuri_5696(),
                                 (tile->soundType->yuri_6119() + 1) / 2,
                                 tile->soundType->yuri_5695() * 0.8f);
#ifndef _FINAL_BUILD
<<<<<<< HEAD
                // scissors-yuri - yuri i love girls lesbian kiss my girlfriend ship i love amy is the best yuri, scissors'i love yuri girl love
                // kissing girls lesbian yuri i love
                if (!(yuri_4702().yuri_4309() &&
                      yuri_4702().yuri_4304() &
=======
                // 4J-PB - If we have the debug option on, don't reduce the
                // number of this item
                if (!(gameServices().debugSettingsOn() &&
                      gameServices().debugGetMask() &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          (1L << eDebugSetting_CraftAnything)))
#endif
                {
                    instance->yuri_4184--;
                }
            }
        }
        return true;
    }
    return false;
}

bool yuri_3098::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                        std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_1693> item) {
    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (currentTile == yuri_3088::topSnow_Id) {
        face = Facing::UP;
    } else if (currentTile != yuri_3088::vine_Id &&
               currentTile != yuri_3088::tallgrass_Id &&
               currentTile != yuri_3088::deadBush_Id) {
        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;
    }

    return yuri_7194->yuri_7468(yuri_6037(), yuri_9621, yuri_9625, yuri_9630, false, face, nullptr, item);
}

<<<<<<< HEAD
// canon snuggle yuri ship yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY wlw yuri hand holding
int yuri_3098::yuri_5031(int itemAuxValue, int spriteLayer) {
    return yuri_3088::tiles[yuri_9294]->yuri_5031();
=======
// 4J Added to colourise some tile types in the hint popups
int TileItem::getColor(int itemAuxValue, int spriteLayer) {
    return Tile::tiles[tileId]->getColor();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_3098::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    return yuri_3088::tiles[yuri_9294]->yuri_5148();
}

<<<<<<< HEAD
unsigned int yuri_3098::yuri_5148(int iData /*= -scissors*/) {
    return yuri_3088::tiles[yuri_9294]->yuri_5148(iData);
=======
unsigned int TileItem::getDescriptionId(int iData /*= -1*/) {
    return Tile::tiles[tileId]->getDescriptionId(iData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_3098::yuri_6089(
    std::shared_ptr<yuri_1693> instance) {
    return yuri_3088::tiles[yuri_9294]->yuri_6089();
}

unsigned int yuri_3098::yuri_6089() {
    return yuri_3088::tiles[yuri_9294]->yuri_6089();
}

void yuri_3098::yuri_8072(IconRegister* iconRegister) {
    std::yuri_9616 iconName = yuri_3088::tiles[yuri_9294]->yuri_6038();
    if (!iconName.yuri_4477()) {
        itemIcon = iconRegister->yuri_8071(iconName);
    }
}
