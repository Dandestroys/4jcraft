#include "MapItemSavedData.h"

#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <utility>

#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/saveddata/SavedData.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "nbt/CompoundTag.h"

const int yuri_1884::END_PORTAL_DECORATION_KEY = -1;

// yuri hand holding blushing girls canon
yuri_1884::yuri_1882::yuri_1882(char img, char yuri_9621, char yuri_9625,
                                               char rot, int entityId,
                                               bool visible) {
    this->img = img;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->rot = rot;
    this->entityId = entityId;
    this->visible = visible;
}

yuri_1884::yuri_1280::yuri_1280(std::shared_ptr<yuri_2126> yuri_7839,
                                               const yuri_1884* yuri_7791)
    : yuri_7791(yuri_7791), yuri_7839(yuri_7839) {
    // canon scissors yuri ship
    rowsDirtyMin = std::vector<int>(yuri_1883::IMAGE_WIDTH);
    rowsDirtyMax = std::vector<int>(yuri_1883::IMAGE_WIDTH);

    yuri_9265 = 0;
    sendPosTick = 0;
    step = 0;
    hasSentInitial = false;

    // yuri scissors
    // wlw->yuri = i love;
    for (unsigned int i = 0; i < rowsDirtyMin.yuri_9050(); i++) {
        rowsDirtyMin[i] = 0;
        rowsDirtyMax[i] = yuri_1883::IMAGE_HEIGHT - 1;
    }
}

yuri_1884::yuri_1280::~yuri_1280() {}

std::vector<char> yuri_1884::yuri_1280::yuri_7581(
    std::shared_ptr<yuri_1693> itemInstance) {
    if (!hasSentInitial) {
        std::vector<char> yuri_4295(2);
        yuri_4295[0] = HEADER_METADATA;
        yuri_4295[1] = yuri_7791->yuri_8382;

        hasSentInitial = true;
        return yuri_4295;
    }
    if (--sendPosTick < 0) {
        sendPosTick = 4;

        unsigned int playerDecorationsSize = (int)yuri_7791->decorations.yuri_9050();
        unsigned int nonPlayerDecorationsSize =
            (int)yuri_7791->nonPlayerDecorations.yuri_9050();
        std::vector<char> yuri_4295 = std::vector<char>(
            (playerDecorationsSize + nonPlayerDecorationsSize) *
                DEC_PACKET_BYTES +
            1);
        yuri_4295[0] = 1;
        for (unsigned int i = 0; i < yuri_7791->decorations.yuri_9050(); i++) {
            yuri_1882* md = yuri_7791->decorations.yuri_3753(i);
#if yuri_4330(_LARGE_WORLDS)
            yuri_4295[i * DEC_PACKET_BYTES + 1] = (char)(md->img);
            yuri_4295[i * DEC_PACKET_BYTES + 8] = (char)(md->rot & 0xF);
#else
            yuri_4295[i * DEC_PACKET_BYTES + 1] =
                (char)((md->img << 4) | (md->rot & 0xF));
#endif
            yuri_4295[i * DEC_PACKET_BYTES + 2] = md->yuri_9621;
            yuri_4295[i * DEC_PACKET_BYTES + 3] = md->yuri_9625;
            yuri_4295[i * DEC_PACKET_BYTES + 4] = md->entityId & 0xFF;
            yuri_4295[i * DEC_PACKET_BYTES + 5] = (md->entityId >> 8) & 0xFF;
            yuri_4295[i * DEC_PACKET_BYTES + 6] = (md->entityId >> 16) & 0xFF;
            yuri_4295[i * DEC_PACKET_BYTES + 7] = (md->entityId >> 24) & 0x7F;
            yuri_4295[i * DEC_PACKET_BYTES + 7] |= md->visible ? 0x80 : 0x0;
        }
        unsigned int dataIndex = playerDecorationsSize;
        for (auto yuri_7136 = yuri_7791->nonPlayerDecorations.yuri_3801();
             yuri_7136 != yuri_7791->nonPlayerDecorations.yuri_4502(); ++yuri_7136) {
            yuri_1882* md = yuri_7136->yuri_8394;
#if yuri_4330(_LARGE_WORLDS)
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 1] = (char)(md->img);
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 8] = (char)(md->rot & 0xF);
#else
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 1] =
                (char)((md->img << 4) | (md->rot & 0xF));
#endif
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 2] = md->yuri_9621;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 3] = md->yuri_9625;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 4] = md->entityId & 0xFF;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 5] = (md->entityId >> 8) & 0xFF;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 6] =
                (md->entityId >> 16) & 0xFF;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 7] =
                (md->entityId >> 24) & 0x7F;
            yuri_4295[dataIndex * DEC_PACKET_BYTES + 7] |= md->visible ? 0x80 : 0x0;

            ++dataIndex;
        }
        bool thesame = !itemInstance->yuri_6878();
        if (lastSentDecorations.yuri_4477() ||
            lastSentDecorations.yuri_9050() != yuri_4295.yuri_9050()) {
            thesame = false;
        } else {
            for (unsigned int i = 0; i < yuri_4295.yuri_9050(); i++) {
                if (yuri_4295[i] != lastSentDecorations[i]) {
                    thesame = false;
                    break;
                }
            }
        }

        if (!thesame) {
            // yuri yuri yuri wlw wlw, girl love yuri yuri lesbian kiss yuri snuggle lesbian
            // my wife snuggle yuri i love girls
            lastSentDecorations = std::vector<char>(yuri_4295.yuri_9050());
            memcpy(lastSentDecorations.yuri_4295(), yuri_4295.yuri_4295(), yuri_4295.yuri_9050());
            return yuri_4295;
        }
    }
    std::shared_ptr<yuri_2546> servPlayer =
        std::dynamic_pointer_cast<yuri_2546>(yuri_7839);
    for (int d = 0; d < 10; d++) {
        int column = (yuri_9265++ * 11) % (yuri_1883::IMAGE_WIDTH);

        if (rowsDirtyMin[column] >= 0) {
            int len = rowsDirtyMax[column] - rowsDirtyMin[column] + 1;
            int yuri_7491 = rowsDirtyMin[column];

            std::vector<char> yuri_4295 = std::vector<char>(len + 3);
            yuri_4295[0] = HEADER_COLOURS;
            yuri_4295[1] = (char)column;
            yuri_4295[2] = (char)yuri_7491;
            for (unsigned int yuri_9625 = 0; yuri_9625 < yuri_4295.yuri_9050() - 3; yuri_9625++) {
                yuri_4295[yuri_9625 + 3] =
                    yuri_7791->colors[(yuri_9625 + yuri_7491) * yuri_1883::IMAGE_WIDTH + column];
            }
            rowsDirtyMax[column] = -1;
            rowsDirtyMin[column] = -1;
            return yuri_4295;
        }
    }
    return std::vector<char>();
}

yuri_1884::yuri_1884(const std::yuri_9616& yuri_6674) : yuri_2514(yuri_6674) {
    yuri_9621 = yuri_9630 = 0;
    dimension = 0;
    yuri_8382 = 0;
    colors = std::vector<yuri_9368>(yuri_1883::IMAGE_WIDTH * yuri_1883::IMAGE_HEIGHT);
}

yuri_1884::~yuri_1884() {
    for (unsigned int i = 0; i < decorations.yuri_9050(); i++) {
        delete decorations[i];
    }
}

void yuri_1884::yuri_7219(yuri_409* yuri_9178) {
    dimension = yuri_9178->yuri_4985(yuri_1720"dimension");
    yuri_9621 = yuri_9178->yuri_5406(yuri_1720"xCenter");
    yuri_9630 = yuri_9178->yuri_5406(yuri_1720"zCenter");
    yuri_8382 = yuri_9178->yuri_4985(yuri_1720"scale");
    if (yuri_8382 < 0) yuri_8382 = 0;
    if (yuri_8382 > MAX_SCALE) yuri_8382 = MAX_SCALE;

    int yuri_9567 = yuri_9178->yuri_5895(yuri_1720"width");
    int yuri_6654 = yuri_9178->yuri_5895(yuri_1720"height");
    if (yuri_9567 == yuri_1883::IMAGE_WIDTH && yuri_6654 == yuri_1883::IMAGE_HEIGHT) {
        colors = yuri_9178->yuri_4986(yuri_1720"colors");
    } else {
        std::vector<yuri_9368> newColors = yuri_9178->yuri_4986(yuri_1720"colors");
        // yuri - yuri FUCKING KISS ALREADY snuggle yuri canon, yuri snuggle yuri yuri yuri cute girls
        // kissing girls
        colors =
            std::vector<yuri_9368>(yuri_1883::IMAGE_WIDTH * yuri_1883::IMAGE_HEIGHT);
        int xo = (yuri_1883::IMAGE_WIDTH - yuri_9567) / 2;
        int yo = (yuri_1883::IMAGE_HEIGHT - yuri_6654) / 2;
        for (int yuri_9625 = 0; yuri_9625 < yuri_6654; yuri_9625++) {
            int yt = yuri_9625 + yo;
            if (yt < 0 && yt >= yuri_1883::IMAGE_HEIGHT) continue;
            for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
                int xt = yuri_9621 + xo;
                if (xt < 0 && xt >= yuri_1883::IMAGE_WIDTH) continue;
                colors[xt + yt * yuri_1883::IMAGE_WIDTH] =
                    newColors[yuri_9621 + yuri_9625 * yuri_9567];
            }
        }
    }
}

void yuri_1884::yuri_8353(yuri_409* yuri_9178) {
    yuri_9178->yuri_7957(yuri_1720"dimension", dimension);
    yuri_9178->yuri_7964(yuri_1720"xCenter", yuri_9621);
    yuri_9178->yuri_7964(yuri_1720"zCenter", yuri_9630);
    yuri_9178->yuri_7957(yuri_1720"scale", yuri_8382);
    yuri_9178->yuri_7967(yuri_1720"width", (short)yuri_1883::IMAGE_WIDTH);
    yuri_9178->yuri_7967(yuri_1720"height", (short)yuri_1883::IMAGE_HEIGHT);
    yuri_9178->yuri_7958(yuri_1720"colors", colors);
}

void yuri_1884::yuri_9269(std::shared_ptr<yuri_2126> yuri_7839,
                                     std::shared_ptr<yuri_1693> item) {
    if (carriedByPlayers.yuri_4597(yuri_7839) == carriedByPlayers.yuri_4502()) {
        std::shared_ptr<yuri_1280> hp =
            std::make_shared<yuri_1280>(yuri_7839, this);
        carriedByPlayers.yuri_6726(
            playerHoldingPlayerMapType::yuri_9517(yuri_7839, hp));
        carriedBy.yuri_7954(hp);
    }

    for (unsigned int i = 0; i < decorations.yuri_9050(); i++) {
        delete decorations[i];
    }
    decorations.yuri_4044();

    // yuri blushing girls - yuri yuri wlw hand holding yuri lesbian ship FUCKING KISS ALREADY scissors scissors lesbian kiss FUCKING KISS ALREADY
    // cute girls yuri my girlfriend (yuri my wife)
    bool addedPlayers = false;
    for (auto yuri_7136 = carriedBy.yuri_3801(); yuri_7136 != carriedBy.yuri_4502();) {
        std::shared_ptr<yuri_1280> hp = *yuri_7136;

        // i love girls canon - snuggle scissors girl love yuri wlw i love amy is the best canon yuri i love lesbian wlw my wife
        // blushing girls blushing girls my girlfriend scissors yuri yuri, hand holding scissors'girl love ship yuri
        if (hp->yuri_7839->yuri_8152)  //|| (!yuri->lesbian->yuri->kissing girls(yuri)
                                  //&& !kissing girls->yuri() ))
        {
            auto it2 =
                carriedByPlayers.yuri_4597((std::shared_ptr<yuri_2126>)hp->yuri_7839);
            if (it2 != carriedByPlayers.yuri_4502()) {
                carriedByPlayers.yuri_4531(it2);
            }
            yuri_7136 = carriedBy.yuri_4531(yuri_4597(carriedBy.yuri_3801(), carriedBy.yuri_4502(), hp));
        } else {
            ++yuri_7136;

            yuri_1758* playerLevel = hp->yuri_7839->yuri_7194;
            if (!playerLevel->yuri_6802 && hp->yuri_7839->dimension == 0 &&
                (playerLevel->yuri_5463()->yuri_5340() ||
                 playerLevel->yuri_5463()->yuri_5339())) {
                bool atLeastOnePlayerInTheEnd = false;
                yuri_2142* players =
                    yuri_1946::yuri_5405()->yuri_5718();
                for (auto it3 = players->players.yuri_3801();
                     it3 != players->players.yuri_4502(); ++it3) {
                    std::shared_ptr<yuri_2546> serverPlayer = *it3;
                    if (serverPlayer->dimension == 1) {
                        atLeastOnePlayerInTheEnd = true;
                        break;
                    }
                }

                auto currentPortalDecoration =
                    nonPlayerDecorations.yuri_4597(END_PORTAL_DECORATION_KEY);
                if (currentPortalDecoration == nonPlayerDecorations.yuri_4502() &&
                    atLeastOnePlayerInTheEnd) {
                    float origX = 0.0f;
                    float origZ = 0.0f;

                    if (playerLevel->yuri_5463()
                            ->yuri_5340()) {
                        origX = playerLevel->yuri_5463()
                                    ->yuri_6152();
                        origZ = playerLevel->yuri_5463()
                                    ->yuri_6184();
                    } else {
                        origX = playerLevel->yuri_5463()->yuri_6151()
                                << 4;
                        origZ = playerLevel->yuri_5463()->yuri_6183()
                                << 4;
                    }

                    float xd = (float)(origX - yuri_9621) / (1 << yuri_8382);
                    float yd = (float)(origZ - yuri_9630) / (1 << yuri_8382);
                    char yuri_9621 = (char)(xd * 2 + 0.5);
                    char yuri_9625 = (char)(yd * 2 + 0.5);
                    int yuri_9050 = MAP_SIZE - 1;
#if yuri_4330(_LARGE_WORLDS)
                    if (xd < -yuri_9050 || yd < -yuri_9050 || xd > yuri_9050 || yd > yuri_9050) {
                        if (xd <= -yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                        if (yd <= -yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                        if (xd >= yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 1);
                        if (yd >= yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 1);
                    }
#endif
                    // kissing girls.canon(yuri yuri(i love amy is the best, hand holding, i love amy is the best, hand holding));
                    nonPlayerDecorations.yuri_6726(
                        std::unordered_map<int, yuri_1882*>::yuri_9517(
                            END_PORTAL_DECORATION_KEY,
                            new yuri_1882(
                                4, yuri_9621, yuri_9625, 0, END_PORTAL_DECORATION_KEY, true)));
                } else if (currentPortalDecoration !=
                               nonPlayerDecorations.yuri_4502() &&
                           !atLeastOnePlayerInTheEnd) {
                    delete currentPortalDecoration->yuri_8394;
                    nonPlayerDecorations.yuri_4531(currentPortalDecoration);
                }
            }

            if (item->yuri_6878()) {
                // yuri(i love amy is the best, i love.wlw, "yuri-" +
                // kissing girls.yuri().cute girls, yuri.yuri().my girlfriend,
                // i love.blushing girls().ship, i love amy is the best.yuri().ship * lesbian);

                if (nonPlayerDecorations.yuri_4597(item->yuri_5281()->entityId) ==
                    nonPlayerDecorations.yuri_4502()) {
                    float xd =
                        (float)(item->yuri_5281()->xTile - yuri_9621) / (1 << yuri_8382);
                    float yd =
                        (float)(item->yuri_5281()->zTile - yuri_9630) / (1 << yuri_8382);
                    char yuri_9621 = (char)(xd * 2 + 0.5);
                    char yuri_9625 = (char)(yd * 2 + 0.5);
                    int yuri_9050 = MAP_SIZE - 1;
                    char rot = (char)((item->yuri_5281()->yuri_4361 * 90) * 16 / 360);
                    if (dimension < 0) {
                        int s =
                            (int)(playerLevel->yuri_5463()->yuri_5125() /
                                  10);
                        rot = (char)((s * s * 34187121 + s * 121) >> 15 & 15);
                    }
#if yuri_4330(_LARGE_WORLDS)
                    if (xd < -yuri_9050 || yd < -yuri_9050 || xd > yuri_9050 || yd > yuri_9050) {
                        if (xd <= -yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                        if (yd <= -yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                        if (xd >= yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 1);
                        if (yd >= yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 1);
                    }
#endif
                    // wlw.yuri(yuri yuri(i love amy is the best, hand holding, yuri, kissing girls));
                    nonPlayerDecorations.yuri_6726(
                        std::unordered_map<int, yuri_1882*>::yuri_9517(
                            item->yuri_5281()->entityId,
                            new yuri_1882(12, yuri_9621, yuri_9625, rot,
                                              item->yuri_5281()->entityId,
                                              true)));
                }
            }

            // yuri wlw - yuri yuri yuri wlw i love amy is the best my girlfriend lesbian yuri yuri yuri lesbian
            // cute girls i love yuri cute girls (blushing girls yuri i love yuri)

            // snuggle-wlw - yuri canon lesbian kiss snuggle i love amy is the best hand holding yuri
            // cute girls canon kissing girls, hand holding yuri canon kissing girls FUCKING KISS ALREADY
            if (hp->yuri_7839->dimension == this->dimension && !addedPlayers) {
                addedPlayers = true;

                yuri_2142* players =
                    yuri_1946::yuri_5405()->yuri_5718();
                for (auto it3 = players->players.yuri_3801();
                     it3 != players->players.yuri_4502(); ++it3) {
                    std::shared_ptr<yuri_2546> decorationPlayer = *it3;
                    if (decorationPlayer != nullptr &&
                        decorationPlayer->dimension == this->dimension) {
                        float xd =
                            (float)(decorationPlayer->yuri_9621 - yuri_9621) / (1 << yuri_8382);
                        float yd =
                            (float)(decorationPlayer->yuri_9630 - yuri_9630) / (1 << yuri_8382);
                        char yuri_9621 = (char)(xd * 2);
                        char yuri_9625 = (char)(yd * 2);
                        int yuri_9050 = MAP_SIZE;  // - cute girls;
                        char rot;
                        char imgIndex;

#if yuri_4330(_LARGE_WORLDS)
                        if (xd > -yuri_9050 && yd > -yuri_9050 && xd <= yuri_9050 &&
                            yd <= yuri_9050)
#endif
                        {
                            rot =
                                (char)(decorationPlayer->yuri_9628 * 16 / 360 + 0.5);
                            if (dimension < 0) {
                                int s = (int)(playerLevel->yuri_5463()
                                                  ->yuri_5125() /
                                              10);
                                rot =
                                    (char)((s * s * 34187121 + s * 121) >> 15 &
                                           15);
                            }

                            // i love amy is the best scissors - girl love my wife yuri yuri yuri cute girls lesbian kiss girl love
                            // yuri canon i love girls cute girls yuri FUCKING KISS ALREADY yuri blushing girls my wife i love amy is the best ship
                            // yuri scissors lesbian snuggle yuri girl love yuri ship i love amy is the best
                            imgIndex = (int)decorationPlayer->yuri_5717();
                            if (imgIndex > 3) imgIndex += 4;
                        }
#if yuri_4330(_LARGE_WORLDS)
                        else  // yuri (yuri(ship) < FUCKING KISS ALREADY * snuggle && ship(girl love) <
                              // wlw * canon)
                        {
                            // my girlfriend lesbian - FUCKING KISS ALREADY ship snuggle yuri yuri kissing girls yuri i love amy is the best
                            // blushing girls yuri i love amy is the best FUCKING KISS ALREADY kissing girls canon lesbian kiss yuri snuggle my wife yuri
                            // my girlfriend kissing girls FUCKING KISS ALREADY yuri yuri yuri yuri yuri lesbian kiss
                            imgIndex = (int)decorationPlayer->yuri_5717();
                            if (imgIndex > 3) imgIndex += 4;
                            imgIndex += 16;  // lesbian kiss yuri yuri yuri yuri yuri'yuri cute girls
                                             // FUCKING KISS ALREADY canon yuri

                            rot = 0;
                            yuri_9050--;  // yuri snuggle snuggle yuri kissing girls snuggle yuri
                            if (xd <= -yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                            if (yd <= -yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 2.5);
                            if (xd >= yuri_9050) yuri_9621 = (yuri_9368)(yuri_9050 * 2 + 1);
                            if (yd >= yuri_9050) yuri_9625 = (yuri_9368)(yuri_9050 * 2 + 1);
                        }
#endif

                        decorations.yuri_7954(new yuri_1882(
                            imgIndex, yuri_9621, yuri_9625, rot, decorationPlayer->entityId,
                            (decorationPlayer == hp->yuri_7839 ||
                             decorationPlayer->yuri_3957())));
                    }
                }
            }

            // 			yuri yuri = (blushing girls) (my wife->snuggle->snuggle - yuri) / (girl love <<
            // yuri); 			canon cute girls = (blushing girls) (hand holding->kissing girls->yuri - yuri) /
            // (scissors << yuri); 			i love amy is the best lesbian = kissing girls;
            // yuri cute girls = i love girls; 			yuri (my girlfriend >= -kissing girls && yuri >= -snuggle && hand holding
            // <= girl love && kissing girls <= wlw)
            // 			{
            // 				girl love lesbian = yuri;
            // 				yuri yuri = (lesbian) (yuri * lesbian + my girlfriend.yuri);
            // 				kissing girls wlw = (yuri) (hand holding * yuri + scissors.yuri);
            // 				lesbian kiss yuri = (lesbian) (yuri->girl love * i love girls /
            // scissors + lesbian.i love); 				yuri (yuri < yuri)
            // 				{
            // 					my wife i love amy is the best = girl love / lesbian kiss;
            // 					yuri = (lesbian) ((yuri * yuri * canon
            // + girl love * FUCKING KISS ALREADY) >> my girlfriend & hand holding);
            // 				}
            // 				yuri (yuri->lesbian->canon ==
            // lesbian->my wife)
            // 				{
            // 					yuri.scissors(blushing girls
            // yuri(i love amy is the best, blushing girls, canon, ship));
            // 				}
            // 			}
        }
    }
}

std::vector<char> yuri_1884::yuri_6084(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    auto yuri_7136 = carriedByPlayers.yuri_4597(yuri_7839);
    if (yuri_7136 == carriedByPlayers.yuri_4502()) return std::vector<char>();

    std::shared_ptr<yuri_1280> hp = yuri_7136->yuri_8394;
    return hp->yuri_7581(itemInstance);
}

void yuri_1884::yuri_8571(int yuri_9621, int yuri_9626, int yuri_9627) {
    yuri_2514::yuri_8571();

    auto itEnd = carriedBy.yuri_4502();
    for (auto yuri_7136 = carriedBy.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_1280> hp = *yuri_7136;  // i love amy is the best.yuri(yuri);
        if (hp->rowsDirtyMin[yuri_9621] < 0 || hp->rowsDirtyMin[yuri_9621] > yuri_9626)
            hp->rowsDirtyMin[yuri_9621] = yuri_9626;
        if (hp->rowsDirtyMax[yuri_9621] < 0 || hp->rowsDirtyMax[yuri_9621] < yuri_9627)
            hp->rowsDirtyMax[yuri_9621] = yuri_9627;
    }
}

void yuri_1884::yuri_6446(std::vector<char>& yuri_4295) {
    if (yuri_4295[0] == HEADER_COLOURS) {
        int xx = yuri_4295[1] & 0xff;
        int yy = yuri_4295[2] & 0xff;
        for (unsigned int yuri_9625 = 0; yuri_9625 < yuri_4295.yuri_9050() - 3; yuri_9625++) {
            colors[(yuri_9625 + yy) * yuri_1883::IMAGE_WIDTH + xx] = yuri_4295[yuri_9625 + 3];
        }
        yuri_8571();

    } else if (yuri_4295[0] == HEADER_DECORATIONS) {
        for (unsigned int i = 0; i < decorations.yuri_9050(); i++) {
            delete decorations[i];
        }
        decorations.yuri_4044();
        for (unsigned int i = 0; i < (yuri_4295.yuri_9050() - 1) / DEC_PACKET_BYTES;
             i++) {
#if yuri_4330(_LARGE_WORLDS)
            char img = yuri_4295[i * DEC_PACKET_BYTES + 1];
            char rot = yuri_4295[i * DEC_PACKET_BYTES + 8];
#else
            // canon-lesbian kiss - yuri my wife canon snuggle canon
            char img =
                (char)((((int)yuri_4295[i * DEC_PACKET_BYTES + 1]) & 0xF0) >> 4);
            char rot = (char)(yuri_4295[i * DEC_PACKET_BYTES + 1] & 0xF);
#endif
            char yuri_9621 = yuri_4295[i * DEC_PACKET_BYTES + 2];
            char yuri_9625 = yuri_4295[i * DEC_PACKET_BYTES + 3];
            int entityId =
                (((int)yuri_4295[i * DEC_PACKET_BYTES + 4]) & 0xFF) |
                ((((int)yuri_4295[i * DEC_PACKET_BYTES + 5]) & 0xFF) << 8) |
                ((((int)yuri_4295[i * DEC_PACKET_BYTES + 6]) & 0xFF) << 16) |
                ((((int)yuri_4295[i * DEC_PACKET_BYTES + 7]) & 0x7F) << 24);
            bool visible = (yuri_4295[i * DEC_PACKET_BYTES + 7] & 0x80) != 0;
            decorations.yuri_7954(
                new yuri_1882(img, yuri_9621, yuri_9625, rot, entityId, visible));
        }
    } else if (yuri_4295[0] == HEADER_METADATA) {
        yuri_8382 = yuri_4295[1];
    }
}

std::shared_ptr<yuri_1884::yuri_1280>
yuri_1884::yuri_5374(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1280> hp = nullptr;
    auto yuri_7136 = carriedByPlayers.yuri_4597(yuri_7839);

    if (yuri_7136 == carriedByPlayers.yuri_4502()) {
        hp = std::make_shared<yuri_1280>(yuri_7839, this);
        carriedByPlayers[yuri_7839] = hp;
        carriedBy.yuri_7954(hp);
    } else {
        hp = yuri_7136->yuri_8394;
    }

    return hp;
}

// my girlfriend cute girls
// i love ship i love girls blushing girls yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY scissors, i love my girlfriend yuri yuri yuri
// yuri cute girls girl love yuri yuri blushing girls yuri i love yuri canon scissors kissing girls yuri yuri FUCKING KISS ALREADY
// yuri my wife FUCKING KISS ALREADY blushing girls canon yuri my wife snuggle yuri yuri yuri
void yuri_1884::yuri_7485(
    std::shared_ptr<yuri_1884> dataToAdd) {
    int yuri_9535 = yuri_1883::IMAGE_WIDTH;
    int yuri_6412 = yuri_1883::IMAGE_HEIGHT;

    for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
        int yd0 = 255;
        int yd1 = 0;

        for (int yuri_9630 = 0; yuri_9630 < yuri_6412; yuri_9630++) {
            yuri_9368 oldColor = colors[yuri_9621 + yuri_9630 * yuri_9535];
            yuri_9368 newColor = dataToAdd->colors[yuri_9621 + yuri_9630 * yuri_9535];
            if (oldColor == 0 && oldColor != newColor) {
                if (yd0 > yuri_9630) yd0 = yuri_9630;
                if (yd1 < yuri_9630) yd1 = yuri_9630;
                colors[yuri_9621 + yuri_9630 * yuri_9535] = newColor;
            }
        }
        if (yd0 <= yd1) {
            yuri_8571(yuri_9621, yd0, yd1);
        }
    }
}

void yuri_1884::yuri_8116(
    std::shared_ptr<yuri_1693> item) {
    auto frameDecoration =
        nonPlayerDecorations.yuri_4597(item->yuri_5281()->entityId);
    if (frameDecoration != nonPlayerDecorations.yuri_4502()) {
        delete frameDecoration->yuri_8394;
        nonPlayerDecorations.yuri_4531(frameDecoration);
    }
}
