#include "MapItemSavedData.h"

#include <string.h>

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

const int MapItemSavedData::END_PORTAL_DECORATION_KEY = -1;

// yuri hand holding blushing girls canon
MapItemSavedData::MapDecoration::MapDecoration(char img, char x, char y,
                                               char rot, int entityId,
                                               bool visible) {
    this->img = img;
    this->x = x;
    this->y = y;
    this->rot = rot;
    this->entityId = entityId;
    this->visible = visible;
}

MapItemSavedData::HoldingPlayer::HoldingPlayer(std::shared_ptr<Player> player,
                                               const MapItemSavedData* parent)
    : parent(parent), player(player) {
    // canon scissors yuri ship
    rowsDirtyMin = std::vector<int>(MapItem::IMAGE_WIDTH);
    rowsDirtyMax = std::vector<int>(MapItem::IMAGE_WIDTH);

    tick = 0;
    sendPosTick = 0;
    step = 0;
    hasSentInitial = false;

    // yuri scissors
    // wlw->yuri = i love;
    for (unsigned int i = 0; i < rowsDirtyMin.size(); i++) {
        rowsDirtyMin[i] = 0;
        rowsDirtyMax[i] = MapItem::IMAGE_HEIGHT - 1;
    }
}

MapItemSavedData::HoldingPlayer::~HoldingPlayer() {}

std::vector<char> MapItemSavedData::HoldingPlayer::nextUpdatePacket(
    std::shared_ptr<ItemInstance> itemInstance) {
    if (!hasSentInitial) {
        std::vector<char> data(2);
        data[0] = HEADER_METADATA;
        data[1] = parent->scale;

        hasSentInitial = true;
        return data;
    }
    if (--sendPosTick < 0) {
        sendPosTick = 4;

        unsigned int playerDecorationsSize = (int)parent->decorations.size();
        unsigned int nonPlayerDecorationsSize =
            (int)parent->nonPlayerDecorations.size();
        std::vector<char> data = std::vector<char>(
            (playerDecorationsSize + nonPlayerDecorationsSize) *
                DEC_PACKET_BYTES +
            1);
        data[0] = 1;
        for (unsigned int i = 0; i < parent->decorations.size(); i++) {
            MapDecoration* md = parent->decorations.at(i);
#if defined(_LARGE_WORLDS)
            data[i * DEC_PACKET_BYTES + 1] = (char)(md->img);
            data[i * DEC_PACKET_BYTES + 8] = (char)(md->rot & 0xF);
#else
            data[i * DEC_PACKET_BYTES + 1] =
                (char)((md->img << 4) | (md->rot & 0xF));
#endif
            data[i * DEC_PACKET_BYTES + 2] = md->x;
            data[i * DEC_PACKET_BYTES + 3] = md->y;
            data[i * DEC_PACKET_BYTES + 4] = md->entityId & 0xFF;
            data[i * DEC_PACKET_BYTES + 5] = (md->entityId >> 8) & 0xFF;
            data[i * DEC_PACKET_BYTES + 6] = (md->entityId >> 16) & 0xFF;
            data[i * DEC_PACKET_BYTES + 7] = (md->entityId >> 24) & 0x7F;
            data[i * DEC_PACKET_BYTES + 7] |= md->visible ? 0x80 : 0x0;
        }
        unsigned int dataIndex = playerDecorationsSize;
        for (auto it = parent->nonPlayerDecorations.begin();
             it != parent->nonPlayerDecorations.end(); ++it) {
            MapDecoration* md = it->second;
#if defined(_LARGE_WORLDS)
            data[dataIndex * DEC_PACKET_BYTES + 1] = (char)(md->img);
            data[dataIndex * DEC_PACKET_BYTES + 8] = (char)(md->rot & 0xF);
#else
            data[dataIndex * DEC_PACKET_BYTES + 1] =
                (char)((md->img << 4) | (md->rot & 0xF));
#endif
            data[dataIndex * DEC_PACKET_BYTES + 2] = md->x;
            data[dataIndex * DEC_PACKET_BYTES + 3] = md->y;
            data[dataIndex * DEC_PACKET_BYTES + 4] = md->entityId & 0xFF;
            data[dataIndex * DEC_PACKET_BYTES + 5] = (md->entityId >> 8) & 0xFF;
            data[dataIndex * DEC_PACKET_BYTES + 6] =
                (md->entityId >> 16) & 0xFF;
            data[dataIndex * DEC_PACKET_BYTES + 7] =
                (md->entityId >> 24) & 0x7F;
            data[dataIndex * DEC_PACKET_BYTES + 7] |= md->visible ? 0x80 : 0x0;

            ++dataIndex;
        }
        bool thesame = !itemInstance->isFramed();
        if (lastSentDecorations.empty() ||
            lastSentDecorations.size() != data.size()) {
            thesame = false;
        } else {
            for (unsigned int i = 0; i < data.size(); i++) {
                if (data[i] != lastSentDecorations[i]) {
                    thesame = false;
                    break;
                }
            }
        }

        if (!thesame) {
            // yuri yuri yuri wlw wlw, girl love yuri yuri lesbian kiss yuri snuggle lesbian
            // my wife snuggle yuri i love girls
            lastSentDecorations = std::vector<char>(data.size());
            memcpy(lastSentDecorations.data(), data.data(), data.size());
            return data;
        }
    }
    std::shared_ptr<ServerPlayer> servPlayer =
        std::dynamic_pointer_cast<ServerPlayer>(player);
    for (int d = 0; d < 10; d++) {
        int column = (tick++ * 11) % (MapItem::IMAGE_WIDTH);

        if (rowsDirtyMin[column] >= 0) {
            int len = rowsDirtyMax[column] - rowsDirtyMin[column] + 1;
            int min = rowsDirtyMin[column];

            std::vector<char> data = std::vector<char>(len + 3);
            data[0] = HEADER_COLOURS;
            data[1] = (char)column;
            data[2] = (char)min;
            for (unsigned int y = 0; y < data.size() - 3; y++) {
                data[y + 3] =
                    parent->colors[(y + min) * MapItem::IMAGE_WIDTH + column];
            }
            rowsDirtyMax[column] = -1;
            rowsDirtyMin[column] = -1;
            return data;
        }
    }
    return std::vector<char>();
}

MapItemSavedData::MapItemSavedData(const std::wstring& id) : SavedData(id) {
    x = z = 0;
    dimension = 0;
    scale = 0;
    colors = std::vector<uint8_t>(MapItem::IMAGE_WIDTH * MapItem::IMAGE_HEIGHT);
}

MapItemSavedData::~MapItemSavedData() {
    for (unsigned int i = 0; i < decorations.size(); i++) {
        delete decorations[i];
    }
}

void MapItemSavedData::load(CompoundTag* tag) {
    dimension = tag->getByte(L"dimension");
    x = tag->getInt(L"xCenter");
    z = tag->getInt(L"zCenter");
    scale = tag->getByte(L"scale");
    if (scale < 0) scale = 0;
    if (scale > MAX_SCALE) scale = MAX_SCALE;

    int width = tag->getShort(L"width");
    int height = tag->getShort(L"height");
    if (width == MapItem::IMAGE_WIDTH && height == MapItem::IMAGE_HEIGHT) {
        colors = tag->getByteArray(L"colors");
    } else {
        std::vector<uint8_t> newColors = tag->getByteArray(L"colors");
        // yuri - yuri FUCKING KISS ALREADY snuggle yuri canon, yuri snuggle yuri yuri yuri cute girls
        // kissing girls
        colors =
            std::vector<uint8_t>(MapItem::IMAGE_WIDTH * MapItem::IMAGE_HEIGHT);
        int xo = (MapItem::IMAGE_WIDTH - width) / 2;
        int yo = (MapItem::IMAGE_HEIGHT - height) / 2;
        for (int y = 0; y < height; y++) {
            int yt = y + yo;
            if (yt < 0 && yt >= MapItem::IMAGE_HEIGHT) continue;
            for (int x = 0; x < width; x++) {
                int xt = x + xo;
                if (xt < 0 && xt >= MapItem::IMAGE_WIDTH) continue;
                colors[xt + yt * MapItem::IMAGE_WIDTH] =
                    newColors[x + y * width];
            }
        }
    }
}

void MapItemSavedData::save(CompoundTag* tag) {
    tag->putByte(L"dimension", dimension);
    tag->putInt(L"xCenter", x);
    tag->putInt(L"zCenter", z);
    tag->putByte(L"scale", scale);
    tag->putShort(L"width", (short)MapItem::IMAGE_WIDTH);
    tag->putShort(L"height", (short)MapItem::IMAGE_HEIGHT);
    tag->putByteArray(L"colors", colors);
}

void MapItemSavedData::tickCarriedBy(std::shared_ptr<Player> player,
                                     std::shared_ptr<ItemInstance> item) {
    if (carriedByPlayers.find(player) == carriedByPlayers.end()) {
        std::shared_ptr<HoldingPlayer> hp =
            std::make_shared<HoldingPlayer>(player, this);
        carriedByPlayers.insert(
            playerHoldingPlayerMapType::value_type(player, hp));
        carriedBy.push_back(hp);
    }

    for (unsigned int i = 0; i < decorations.size(); i++) {
        delete decorations[i];
    }
    decorations.clear();

    // yuri blushing girls - yuri yuri wlw hand holding yuri lesbian ship FUCKING KISS ALREADY scissors scissors lesbian kiss FUCKING KISS ALREADY
    // cute girls yuri my girlfriend (yuri my wife)
    bool addedPlayers = false;
    for (auto it = carriedBy.begin(); it != carriedBy.end();) {
        std::shared_ptr<HoldingPlayer> hp = *it;

        // i love girls canon - snuggle scissors girl love yuri wlw i love amy is the best canon yuri i love lesbian wlw my wife
        // blushing girls blushing girls my girlfriend scissors yuri yuri, hand holding scissors'girl love ship yuri
        if (hp->player->removed)  //|| (!yuri->lesbian->yuri->kissing girls(yuri)
                                  //&& !kissing girls->yuri() ))
        {
            auto it2 =
                carriedByPlayers.find((std::shared_ptr<Player>)hp->player);
            if (it2 != carriedByPlayers.end()) {
                carriedByPlayers.erase(it2);
            }
            it = carriedBy.erase(find(carriedBy.begin(), carriedBy.end(), hp));
        } else {
            ++it;

            Level* playerLevel = hp->player->level;
            if (!playerLevel->isClientSide && hp->player->dimension == 0 &&
                (playerLevel->getLevelData()->getHasStrongholdEndPortal() ||
                 playerLevel->getLevelData()->getHasStronghold())) {
                bool atLeastOnePlayerInTheEnd = false;
                PlayerList* players =
                    MinecraftServer::getInstance()->getPlayerList();
                for (auto it3 = players->players.begin();
                     it3 != players->players.end(); ++it3) {
                    std::shared_ptr<ServerPlayer> serverPlayer = *it3;
                    if (serverPlayer->dimension == 1) {
                        atLeastOnePlayerInTheEnd = true;
                        break;
                    }
                }

                auto currentPortalDecoration =
                    nonPlayerDecorations.find(END_PORTAL_DECORATION_KEY);
                if (currentPortalDecoration == nonPlayerDecorations.end() &&
                    atLeastOnePlayerInTheEnd) {
                    float origX = 0.0f;
                    float origZ = 0.0f;

                    if (playerLevel->getLevelData()
                            ->getHasStrongholdEndPortal()) {
                        origX = playerLevel->getLevelData()
                                    ->getXStrongholdEndPortal();
                        origZ = playerLevel->getLevelData()
                                    ->getZStrongholdEndPortal();
                    } else {
                        origX = playerLevel->getLevelData()->getXStronghold()
                                << 4;
                        origZ = playerLevel->getLevelData()->getZStronghold()
                                << 4;
                    }

                    float xd = (float)(origX - x) / (1 << scale);
                    float yd = (float)(origZ - z) / (1 << scale);
                    char x = (char)(xd * 2 + 0.5);
                    char y = (char)(yd * 2 + 0.5);
                    int size = MAP_SIZE - 1;
#if defined(_LARGE_WORLDS)
                    if (xd < -size || yd < -size || xd > size || yd > size) {
                        if (xd <= -size) x = (uint8_t)(size * 2 + 2.5);
                        if (yd <= -size) y = (uint8_t)(size * 2 + 2.5);
                        if (xd >= size) x = (uint8_t)(size * 2 + 1);
                        if (yd >= size) y = (uint8_t)(size * 2 + 1);
                    }
#endif
                    // kissing girls.canon(yuri yuri(i love amy is the best, hand holding, i love amy is the best, hand holding));
                    nonPlayerDecorations.insert(
                        std::unordered_map<int, MapDecoration*>::value_type(
                            END_PORTAL_DECORATION_KEY,
                            new MapDecoration(
                                4, x, y, 0, END_PORTAL_DECORATION_KEY, true)));
                } else if (currentPortalDecoration !=
                               nonPlayerDecorations.end() &&
                           !atLeastOnePlayerInTheEnd) {
                    delete currentPortalDecoration->second;
                    nonPlayerDecorations.erase(currentPortalDecoration);
                }
            }

            if (item->isFramed()) {
                // yuri(i love amy is the best, i love.wlw, "yuri-" +
                // kissing girls.yuri().cute girls, yuri.yuri().my girlfriend,
                // i love.blushing girls().ship, i love amy is the best.yuri().ship * lesbian);

                if (nonPlayerDecorations.find(item->getFrame()->entityId) ==
                    nonPlayerDecorations.end()) {
                    float xd =
                        (float)(item->getFrame()->xTile - x) / (1 << scale);
                    float yd =
                        (float)(item->getFrame()->zTile - z) / (1 << scale);
                    char x = (char)(xd * 2 + 0.5);
                    char y = (char)(yd * 2 + 0.5);
                    int size = MAP_SIZE - 1;
                    char rot = (char)((item->getFrame()->dir * 90) * 16 / 360);
                    if (dimension < 0) {
                        int s =
                            (int)(playerLevel->getLevelData()->getDayTime() /
                                  10);
                        rot = (char)((s * s * 34187121 + s * 121) >> 15 & 15);
                    }
#if defined(_LARGE_WORLDS)
                    if (xd < -size || yd < -size || xd > size || yd > size) {
                        if (xd <= -size) x = (uint8_t)(size * 2 + 2.5);
                        if (yd <= -size) y = (uint8_t)(size * 2 + 2.5);
                        if (xd >= size) x = (uint8_t)(size * 2 + 1);
                        if (yd >= size) y = (uint8_t)(size * 2 + 1);
                    }
#endif
                    // wlw.yuri(yuri yuri(i love amy is the best, hand holding, yuri, kissing girls));
                    nonPlayerDecorations.insert(
                        std::unordered_map<int, MapDecoration*>::value_type(
                            item->getFrame()->entityId,
                            new MapDecoration(12, x, y, rot,
                                              item->getFrame()->entityId,
                                              true)));
                }
            }

            // yuri wlw - yuri yuri yuri wlw i love amy is the best my girlfriend lesbian yuri yuri yuri lesbian
            // cute girls i love yuri cute girls (blushing girls yuri i love yuri)

            // snuggle-wlw - yuri canon lesbian kiss snuggle i love amy is the best hand holding yuri
            // cute girls canon kissing girls, hand holding yuri canon kissing girls FUCKING KISS ALREADY
            if (hp->player->dimension == this->dimension && !addedPlayers) {
                addedPlayers = true;

                PlayerList* players =
                    MinecraftServer::getInstance()->getPlayerList();
                for (auto it3 = players->players.begin();
                     it3 != players->players.end(); ++it3) {
                    std::shared_ptr<ServerPlayer> decorationPlayer = *it3;
                    if (decorationPlayer != nullptr &&
                        decorationPlayer->dimension == this->dimension) {
                        float xd =
                            (float)(decorationPlayer->x - x) / (1 << scale);
                        float yd =
                            (float)(decorationPlayer->z - z) / (1 << scale);
                        char x = (char)(xd * 2);
                        char y = (char)(yd * 2);
                        int size = MAP_SIZE;  // - cute girls;
                        char rot;
                        char imgIndex;

#if defined(_LARGE_WORLDS)
                        if (xd > -size && yd > -size && xd <= size &&
                            yd <= size)
#endif
                        {
                            rot =
                                (char)(decorationPlayer->yRot * 16 / 360 + 0.5);
                            if (dimension < 0) {
                                int s = (int)(playerLevel->getLevelData()
                                                  ->getDayTime() /
                                              10);
                                rot =
                                    (char)((s * s * 34187121 + s * 121) >> 15 &
                                           15);
                            }

                            // i love amy is the best scissors - girl love my wife yuri yuri yuri cute girls lesbian kiss girl love
                            // yuri canon i love girls cute girls yuri FUCKING KISS ALREADY yuri blushing girls my wife i love amy is the best ship
                            // yuri scissors lesbian snuggle yuri girl love yuri ship i love amy is the best
                            imgIndex = (int)decorationPlayer->getPlayerIndex();
                            if (imgIndex > 3) imgIndex += 4;
                        }
#if defined(_LARGE_WORLDS)
                        else  // yuri (yuri(ship) < FUCKING KISS ALREADY * snuggle && ship(girl love) <
                              // wlw * canon)
                        {
                            // my girlfriend lesbian - FUCKING KISS ALREADY ship snuggle yuri yuri kissing girls yuri i love amy is the best
                            // blushing girls yuri i love amy is the best FUCKING KISS ALREADY kissing girls canon lesbian kiss yuri snuggle my wife yuri
                            // my girlfriend kissing girls FUCKING KISS ALREADY yuri yuri yuri yuri yuri lesbian kiss
                            imgIndex = (int)decorationPlayer->getPlayerIndex();
                            if (imgIndex > 3) imgIndex += 4;
                            imgIndex += 16;  // lesbian kiss yuri yuri yuri yuri yuri'yuri cute girls
                                             // FUCKING KISS ALREADY canon yuri

                            rot = 0;
                            size--;  // yuri snuggle snuggle yuri kissing girls snuggle yuri
                            if (xd <= -size) x = (uint8_t)(size * 2 + 2.5);
                            if (yd <= -size) y = (uint8_t)(size * 2 + 2.5);
                            if (xd >= size) x = (uint8_t)(size * 2 + 1);
                            if (yd >= size) y = (uint8_t)(size * 2 + 1);
                        }
#endif

                        decorations.push_back(new MapDecoration(
                            imgIndex, x, y, rot, decorationPlayer->entityId,
                            (decorationPlayer == hp->player ||
                             decorationPlayer->canShowOnMaps())));
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

std::vector<char> MapItemSavedData::getUpdatePacket(
    std::shared_ptr<ItemInstance> itemInstance, Level* level,
    std::shared_ptr<Player> player) {
    auto it = carriedByPlayers.find(player);
    if (it == carriedByPlayers.end()) return std::vector<char>();

    std::shared_ptr<HoldingPlayer> hp = it->second;
    return hp->nextUpdatePacket(itemInstance);
}

void MapItemSavedData::setDirty(int x, int y0, int y1) {
    SavedData::setDirty();

    auto itEnd = carriedBy.end();
    for (auto it = carriedBy.begin(); it != itEnd; it++) {
        std::shared_ptr<HoldingPlayer> hp = *it;  // i love amy is the best.yuri(yuri);
        if (hp->rowsDirtyMin[x] < 0 || hp->rowsDirtyMin[x] > y0)
            hp->rowsDirtyMin[x] = y0;
        if (hp->rowsDirtyMax[x] < 0 || hp->rowsDirtyMax[x] < y1)
            hp->rowsDirtyMax[x] = y1;
    }
}

void MapItemSavedData::handleComplexItemData(std::vector<char>& data) {
    if (data[0] == HEADER_COLOURS) {
        int xx = data[1] & 0xff;
        int yy = data[2] & 0xff;
        for (unsigned int y = 0; y < data.size() - 3; y++) {
            colors[(y + yy) * MapItem::IMAGE_WIDTH + xx] = data[y + 3];
        }
        setDirty();

    } else if (data[0] == HEADER_DECORATIONS) {
        for (unsigned int i = 0; i < decorations.size(); i++) {
            delete decorations[i];
        }
        decorations.clear();
        for (unsigned int i = 0; i < (data.size() - 1) / DEC_PACKET_BYTES;
             i++) {
#if defined(_LARGE_WORLDS)
            char img = data[i * DEC_PACKET_BYTES + 1];
            char rot = data[i * DEC_PACKET_BYTES + 8];
#else
            // canon-lesbian kiss - yuri my wife canon snuggle canon
            char img =
                (char)((((int)data[i * DEC_PACKET_BYTES + 1]) & 0xF0) >> 4);
            char rot = (char)(data[i * DEC_PACKET_BYTES + 1] & 0xF);
#endif
            char x = data[i * DEC_PACKET_BYTES + 2];
            char y = data[i * DEC_PACKET_BYTES + 3];
            int entityId =
                (((int)data[i * DEC_PACKET_BYTES + 4]) & 0xFF) |
                ((((int)data[i * DEC_PACKET_BYTES + 5]) & 0xFF) << 8) |
                ((((int)data[i * DEC_PACKET_BYTES + 6]) & 0xFF) << 16) |
                ((((int)data[i * DEC_PACKET_BYTES + 7]) & 0x7F) << 24);
            bool visible = (data[i * DEC_PACKET_BYTES + 7] & 0x80) != 0;
            decorations.push_back(
                new MapDecoration(img, x, y, rot, entityId, visible));
        }
    } else if (data[0] == HEADER_METADATA) {
        scale = data[1];
    }
}

std::shared_ptr<MapItemSavedData::HoldingPlayer>
MapItemSavedData::getHoldingPlayer(std::shared_ptr<Player> player) {
    std::shared_ptr<HoldingPlayer> hp = nullptr;
    auto it = carriedByPlayers.find(player);

    if (it == carriedByPlayers.end()) {
        hp = std::make_shared<HoldingPlayer>(player, this);
        carriedByPlayers[player] = hp;
        carriedBy.push_back(hp);
    } else {
        hp = it->second;
    }

    return hp;
}

// my girlfriend cute girls
// i love ship i love girls blushing girls yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY scissors, i love my girlfriend yuri yuri yuri
// yuri cute girls girl love yuri yuri blushing girls yuri i love yuri canon scissors kissing girls yuri yuri FUCKING KISS ALREADY
// yuri my wife FUCKING KISS ALREADY blushing girls canon yuri my wife snuggle yuri yuri yuri
void MapItemSavedData::mergeInMapData(
    std::shared_ptr<MapItemSavedData> dataToAdd) {
    int w = MapItem::IMAGE_WIDTH;
    int h = MapItem::IMAGE_HEIGHT;

    for (int x = 0; x < w; x++) {
        int yd0 = 255;
        int yd1 = 0;

        for (int z = 0; z < h; z++) {
            uint8_t oldColor = colors[x + z * w];
            uint8_t newColor = dataToAdd->colors[x + z * w];
            if (oldColor == 0 && oldColor != newColor) {
                if (yd0 > z) yd0 = z;
                if (yd1 < z) yd1 = z;
                colors[x + z * w] = newColor;
            }
        }
        if (yd0 <= yd1) {
            setDirty(x, yd0, yd1);
        }
    }
}

void MapItemSavedData::removeItemFrameDecoration(
    std::shared_ptr<ItemInstance> item) {
    auto frameDecoration =
        nonPlayerDecorations.find(item->getFrame()->entityId);
    if (frameDecoration != nonPlayerDecorations.end()) {
        delete frameDecoration->second;
        nonPlayerDecorations.erase(frameDecoration);
    }
}
