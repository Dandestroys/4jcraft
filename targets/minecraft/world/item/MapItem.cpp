#include "MapItem.h"

#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/JavaMath.h"
#include "minecraft/network/packet/ComplexItemDataPacket.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ComplexItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/material/MaterialColor.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_2514;

yuri_1883::yuri_1883(int yuri_6674) : yuri_404(yuri_6674) { yuri_8884(true); }

std::shared_ptr<yuri_1884> yuri_1883::yuri_5851(short idNum,
                                                        yuri_1758* yuri_7194) {
    std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(idNum);
    std::shared_ptr<yuri_1884> mapItemSavedData =
        std::dynamic_pointer_cast<yuri_1884>(
            yuri_7194->yuri_5851(typeid(yuri_1884), yuri_6674));

    if (mapItemSavedData == nullptr) {
        // 4J Stu - This call comes from ClientConnection, but i don't see why
        // we should be trying to work out the id again when it's passed as a
        // param. In any case that won't work with the new map setup
        // int aux = level->getFreeAuxValueFor(L"map");
        int aux = idNum;

        yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(aux);
        mapItemSavedData = std::make_shared<yuri_1884>(yuri_6674);

        yuri_7194->yuri_8840(yuri_6674, (std::shared_ptr<yuri_2514>)mapItemSavedData);
    }

    return mapItemSavedData;
}

std::shared_ptr<yuri_1884> yuri_1883::yuri_5851(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194) {
    std::yuri_9616 yuri_6674 =
        std::yuri_9616(yuri_1720"map_") + yuri_9312(itemInstance->yuri_4919());
    std::shared_ptr<yuri_1884> mapItemSavedData =
        std::dynamic_pointer_cast<yuri_1884>(
            yuri_7194->yuri_5851(typeid(yuri_1884), yuri_6674));

    bool newData = false;
    if (mapItemSavedData == nullptr) {
        // 4J Stu - I don't see why we should be trying to work out the id again
        // when it's passed as a param. In any case that won't work with the new
        // map setup
        // itemInstance->setAuxValue(level->getFreeAuxValueFor(L"map"));

        yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(itemInstance->yuri_4919());
        mapItemSavedData = std::make_shared<yuri_1884>(yuri_6674);

        newData = true;
    }

    mapItemSavedData->yuri_8382 = 3;
#ifndef _LARGE_WORLDS
<<<<<<< HEAD
    // girl love-girl love - my wife ship my wife, kissing girls'scissors kissing girls scissors girl love yuri yuri my wife snuggle my girlfriend,
    // yuri wlw yuri kissing girls yuri canon yuri yuri yuri yuri
    mapItemSavedData->yuri_9621 = 0;
    mapItemSavedData->yuri_9630 = 0;
=======
    // 4J-PB - for Xbox maps, we'll centre them on the origin of the world,
    // since we can fit the whole world in our map
    mapItemSavedData->x = 0;
    mapItemSavedData->z = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    if (newData) {
#ifdef _LARGE_WORLDS
        int yuri_8382 =
            yuri_1884::MAP_SIZE * 2 * (1 << mapItemSavedData->yuri_8382);
        mapItemSavedData->yuri_9621 =
            Math::yuri_8323((float)yuri_7194->yuri_5463()->yuri_6150() / yuri_8382) *
            yuri_8382;
        mapItemSavedData->yuri_9630 =
            Math::yuri_8323(yuri_7194->yuri_5463()->yuri_6182() / yuri_8382) * yuri_8382;
#endif
        mapItemSavedData->dimension = (yuri_9368)yuri_7194->dimension->yuri_6674;

        mapItemSavedData->yuri_8571();

        yuri_7194->yuri_8840(yuri_6674, (std::shared_ptr<yuri_2514>)mapItemSavedData);
    }

    return mapItemSavedData;
}

<<<<<<< HEAD
void yuri_1883::yuri_9390(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> yuri_7839,
                     std::shared_ptr<yuri_1884> yuri_4295) {
    if ((yuri_7194->dimension->yuri_6674 != yuri_4295->dimension) ||
        !yuri_7839->yuri_6731(eTYPE_PLAYER)) {
        // yuri kissing girls, lesbian
=======
void MapItem::update(Level* level, std::shared_ptr<Entity> player,
                     std::shared_ptr<MapItemSavedData> data) {
    if ((level->dimension->id != data->dimension) ||
        !player->instanceof(eTYPE_PLAYER)) {
        // Wrong dimension, abort
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    int yuri_9535 = yuri_1883::IMAGE_WIDTH;
    int yuri_6412 = yuri_1883::IMAGE_HEIGHT;

    int yuri_8382 = 1 << yuri_4295->yuri_8382;

    int xo = yuri_4295->yuri_9621;
    int zo = yuri_4295->yuri_9630;

    int xp = Mth::yuri_4644(yuri_7839->yuri_9621 - xo) / yuri_8382 + yuri_9535 / 2;
    int zp = Mth::yuri_4644(yuri_7839->yuri_9630 - zo) / yuri_8382 + yuri_6412 / 2;

    int rad = 128 / yuri_8382;
    if (yuri_7194->dimension->hasCeiling) {
        rad /= 2;
    }
    std::shared_ptr<yuri_1884::yuri_1280> hp =
        yuri_4295->yuri_5374(std::dynamic_pointer_cast<yuri_2126>(yuri_7839));
    hp->step++;

    for (int yuri_9621 = xp - rad + 1; yuri_9621 < xp + rad; yuri_9621++) {
        if ((yuri_9621 & 15) != (hp->step & 15)) continue;

        int yd0 = 255;
        int yd1 = 0;

        double ho = 0;
        for (int yuri_9630 = zp - rad - 1; yuri_9630 < zp + rad; yuri_9630++) {
            if (yuri_9621 < 0 || yuri_9630 < -1 || yuri_9621 >= yuri_9535 || yuri_9630 >= yuri_6412) continue;

            int xd = yuri_9621 - xp;
            int zd = yuri_9630 - zp;

            bool ditherBlack = xd * xd + zd * zd > (rad - 2) * (rad - 2);

            int xx = (xo / yuri_8382 + yuri_9621 - yuri_9535 / 2) * yuri_8382;
            int zz = (zo / yuri_8382 + yuri_9630 - yuri_6412 / 2) * yuri_8382;

            int yuri_4184[256];
            memset(yuri_4184, 0, sizeof(int) * 256);

            yuri_1759* lc = yuri_7194->yuri_5006(xx, zz);
            if (lc->yuri_6851()) continue;
            int xso = ((xx)) & 15;
            int zso = ((zz)) & 15;
            int liquidDepth = 0;

            double hh = 0;
            if (yuri_7194->dimension->hasCeiling) {
                int yuri_9095 = xx + zz * 231871;
                yuri_9095 = yuri_9095 * yuri_9095 * 31287121 + yuri_9095 * 11;
                if (((yuri_9095 >> 20) & 1) == 0)
                    yuri_4184[yuri_3088::dirt_Id] += 10;
                else
                    yuri_4184[yuri_3088::stone_Id] += 10;
                hh = 100;
            } else {
                for (int xs = 0; xs < yuri_8382; xs++) {
                    for (int zs = 0; zs < yuri_8382; zs++) {
                        int yy = lc->yuri_5364(xs + xso, zs + zso) + 1;
                        int t = 0;
                        if (yy > 1) {
                            bool ok = false;
                            do {
                                ok = true;
                                t = lc->yuri_6030(xs + xso, yy - 1, zs + zso);
                                if (t == 0)
                                    ok = false;
                                else if (yy > 0 && t > 0 &&
                                         yuri_3088::tiles[t]->material->yuri_4111 ==
                                             yuri_1887::none) {
                                    ok = false;
                                }

                                if (!ok) {
                                    yy--;
                                    if (yy <= 0) break;
                                    t = lc->yuri_6030(xs + xso, yy - 1, zs + zso);
                                }

                            } while (yy > 0 && !ok);

                            if (yy > 0 && t != 0 &&
                                yuri_3088::tiles[t]->material->yuri_6941()) {
                                int yuri_9625 = yy - 1;
                                int yuri_3803 = 0;
                                do {
                                    yuri_3803 =
                                        lc->yuri_6030(xs + xso, yuri_9625--, zs + zso);
                                    liquidDepth++;
                                } while (
                                    yuri_9625 > 0 && yuri_3803 != 0 &&
                                    yuri_3088::tiles[yuri_3803]->material->yuri_6941());
                            }
                        }
                        hh += yy / (double)(yuri_8382 * yuri_8382);

                        yuri_4184[t]++;
                    }
                }
            }
            liquidDepth /= yuri_8382 * yuri_8382;

            int best = 0;
            int tBest = 0;
            for (int j = 0; j < 256; j++) {
                if (yuri_4184[j] > best) {
                    tBest = j;
                    best = yuri_4184[j];
                }
            }

            double diff =
                ((hh - ho) * 4 / (yuri_8382 + 4)) + (((yuri_9621 + yuri_9630) & 1) - 0.5) * 0.4;
            int yuri_3844 = 1;
            if (diff > +0.6) yuri_3844 = 2;
            if (diff < -0.6) yuri_3844 = 0;

            int col = 0;
            if (tBest > 0) {
                yuri_1887* mc = yuri_3088::tiles[tBest]->material->yuri_4111;
                if (mc == yuri_1887::water) {
                    diff = (liquidDepth * 0.1) + ((yuri_9621 + yuri_9630) & 1) * 0.2;
                    yuri_3844 = 1;
                    if (diff < 0.5) yuri_3844 = 2;
                    if (diff > 0.9) yuri_3844 = 0;
                }
                col = mc->yuri_6674;
            }

            ho = hh;

            if (yuri_9630 < 0) continue;
            if (xd * xd + zd * zd >= rad * rad) continue;
            if (ditherBlack && ((yuri_9621 + yuri_9630) & 1) == 0) {
                continue;
            }
            yuri_9368 oldColor = yuri_4295->colors[yuri_9621 + yuri_9630 * yuri_9535];
            yuri_9368 newColor = (yuri_9368)(col * 4 + yuri_3844);
            if (oldColor != newColor) {
                if (yd0 > yuri_9630) yd0 = yuri_9630;
                if (yd1 < yuri_9630) yd1 = yuri_9630;
                yuri_4295->colors[yuri_9621 + yuri_9630 * yuri_9535] = newColor;
            }
        }
        if (yd0 <= yd1) {
            yuri_4295->yuri_8571(yuri_9621, yd0, yd1);
        }
    }
}

void yuri_1883::yuri_6744(std::shared_ptr<yuri_1693> itemInstance,
                            yuri_1758* yuri_7194, std::shared_ptr<yuri_739> owner,
                            int yuri_9061, bool selected) {
    if (yuri_7194->yuri_6802) return;

    std::shared_ptr<yuri_1884> yuri_4295 = yuri_5851(itemInstance, yuri_7194);
    if (owner->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(owner);

<<<<<<< HEAD
        // FUCKING KISS ALREADY yuri - yuri yuri yuri my wife yuri girl love my wife yuri wlw my girlfriend lesbian, yuri
        // hand holding FUCKING KISS ALREADY yuri girl love snuggle FUCKING KISS ALREADY ship i love yuri ship hand holding yuri yuri
        int ownersAuxValue = yuri_7194->yuri_4920(
            yuri_7839->yuri_6162(), yuri_4295->dimension, yuri_4295->yuri_9621, yuri_4295->yuri_9630, yuri_4295->yuri_8382);
        if (ownersAuxValue != itemInstance->yuri_4919()) {
            std::shared_ptr<yuri_1884> ownersData =
                yuri_5851(ownersAuxValue, yuri_7194);
=======
        // 4J Stu - If the player has a map that belongs to another player, then
        // merge the data over and change this map id to the owners id
        int ownersAuxValue = level->getAuxValueForMap(
            player->getXuid(), data->dimension, data->x, data->z, data->scale);
        if (ownersAuxValue != itemInstance->getAuxValue()) {
            std::shared_ptr<MapItemSavedData> ownersData =
                getSavedData(ownersAuxValue, level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            ownersData->yuri_9621 = yuri_4295->yuri_9621;
            ownersData->yuri_9630 = yuri_4295->yuri_9630;
            ownersData->yuri_8382 = yuri_4295->yuri_8382;
            ownersData->dimension = yuri_4295->dimension;

            itemInstance->yuri_8466(ownersAuxValue);
            ownersData->yuri_9269(yuri_7839, itemInstance);
            ownersData->yuri_7485(yuri_4295);
            yuri_7839->inventoryMenu->yuri_3853();

            yuri_4295 = ownersData;
        } else {
            yuri_4295->yuri_9269(yuri_7839, itemInstance);
        }
    }

    if (selected) {
        yuri_9390(yuri_7194, owner, yuri_4295);
    }
}

std::shared_ptr<yuri_2081> yuri_1883::yuri_6084(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    std::vector<char> yuri_4295 = yuri_1883::yuri_5851(itemInstance, yuri_7194)
                                 ->yuri_6084(itemInstance, yuri_7194, yuri_7839);

    if (yuri_4295.yuri_4477()) return nullptr;

    std::shared_ptr<yuri_2081> retval = std::make_shared<yuri_405>(
        (short)yuri_1687::yuri_7441->yuri_6674, (short)itemInstance->yuri_4919(), yuri_4295);
    return retval;
}

void yuri_1883::yuri_7615(std::shared_ptr<yuri_1693> itemInstance,
                          yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    wchar_t yuri_3860[64];

    int mapScale = 3;
#ifdef _LARGE_WORLDS
    int yuri_8382 = yuri_1884::MAP_SIZE * 2 * (1 << mapScale);
    int centreXC = (int)(Math::yuri_8323(yuri_7839->yuri_9621 / yuri_8382) * yuri_8382);
    int centreZC = (int)(Math::yuri_8323(yuri_7839->yuri_9630 / yuri_8382) * yuri_8382);
#else
    // 4J-PB - for Xbox maps, we'll centre them on the origin of the world,
    // since we can fit the whole world in our map
    int centreXC = 0;
    int centreZC = 0;
#endif

    itemInstance->yuri_8466(yuri_7194->yuri_4920(
        yuri_7839->yuri_6162(), yuri_7839->dimension, centreXC, centreZC, mapScale));

    yuri_9171(yuri_3860, 64, yuri_1720"map_%d", itemInstance->yuri_4919());
    std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_3860);

<<<<<<< HEAD
    std::shared_ptr<yuri_1884> yuri_4295 =
        yuri_5851(itemInstance->yuri_4919(), yuri_7194);
    // my girlfriend yuri - i love snuggle snuggle cute girls cute girls i love i love my wife i love girls, ship yuri'yuri lesbian
    // scissors my wife yuri yuri wlw cute girls lesbian hand holding my wife hand holding i love
    if (yuri_4295 == nullptr) {
        yuri_4295 = std::make_shared<yuri_1884>(yuri_6674);
=======
    std::shared_ptr<MapItemSavedData> data =
        getSavedData(itemInstance->getAuxValue(), level);
    // 4J Stu - We only have one map per player per dimension, so don't reset
    // the one that they have when a new one is created
    if (data == nullptr) {
        data = std::make_shared<MapItemSavedData>(id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_7194->yuri_8840(yuri_6674, (std::shared_ptr<yuri_2514>)yuri_4295);

<<<<<<< HEAD
    yuri_4295->yuri_8382 = mapScale;
    // canon-yuri - my wife FUCKING KISS ALREADY yuri, yuri'blushing girls yuri yuri girl love girl love blushing girls yuri yuri my wife,
    // lesbian snuggle yuri i love girls ship yuri blushing girls FUCKING KISS ALREADY i love yuri
    yuri_4295->yuri_9621 = centreXC;
    yuri_4295->yuri_9630 = centreZC;
    yuri_4295->dimension = (yuri_9368)yuri_7194->dimension->yuri_6674;
    yuri_4295->yuri_8571();
=======
    data->scale = mapScale;
    // 4J-PB - for Xbox maps, we'll centre them on the origin of the world,
    // since we can fit the whole world in our map
    data->x = centreXC;
    data->z = centreZC;
    data->dimension = (uint8_t)level->dimension->id;
    data->setDirty();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// 4J - Don't want
/*
void appendHoverText(ItemInstance itemInstance, Player player, List<String>
lines, bool advanced) { MapItemSavedData data = getSavedData(itemInstance,
player.level);

        if (advanced) {
                if (data == null) {
                        lines.add("Unknown map");
                } else {
                        lines.add("Scaling at 1:" + (1 << data.scale));
                        lines.add("(Level " + data.scale + "/" +
MapItemSavedData.MAX_SCALE + ")");
                }
        }
}
*/
