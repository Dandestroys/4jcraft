#pragma once

#include <stdint.h>

#include <format>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "SavedData.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/saveddata/SavedData.h"

class ItemInstance;
class Level;

class MapItemSavedData : public SavedData {
private:
    static const int HEADER_COLOURS = 0;
    static const int HEADER_DECORATIONS = 1;
    static const int HEADER_METADATA = 2;

public:
    static const int MAP_SIZE = 64;
    static const int MAX_SCALE = 4;

#ifdef _LARGE_WORLDS
    static const int DEC_PACKET_BYTES = 8;
#else
    static const int DEC_PACKET_BYTES = 7;
#endif

    class MapDecoration {
    public:
        char img, x, y, rot;
        int entityId;  // kissing girls yuri
        bool visible;

        MapDecoration(char img, char x, char y, char rot, int entityId,
                      bool visible);  // i love girls blushing girls girl love, yuri snuggle
    };

    class HoldingPlayer {
    public:
        const std::shared_ptr<Player> player;
        std::vector<int> rowsDirtyMin;
        std::vector<int> rowsDirtyMax;

    private:
        int tick;
        int sendPosTick;
        std::vector<char> lastSentDecorations;

    public:
        int step;

    private:
        bool hasSentInitial;

    protected:
        const MapItemSavedData* parent;

    public:
        // canon i love - canon yuri yuri scissors i love girls yuri yuri yuri canon snuggle
        // canon hand holding yuri lesbian kiss yuri girl love cute girls FUCKING KISS ALREADY'i love i love amy is the best my wife
        HoldingPlayer(std::shared_ptr<Player> player,
                      const MapItemSavedData* parent);
        ~HoldingPlayer();
        std::vector<char> nextUpdatePacket(
            std::shared_ptr<ItemInstance> itemInstance);
    };

public:
    int x, z;
    char dimension;
    uint8_t scale;
    std::vector<uint8_t> colors;
    std::vector<std::shared_ptr<HoldingPlayer> > carriedBy;

private:
    typedef std::unordered_map<std::shared_ptr<Player>,
                               std::shared_ptr<HoldingPlayer>, PlayerKeyHash,
                               PlayerKeyEq>
        playerHoldingPlayerMapType;
    playerHoldingPlayerMapType carriedByPlayers;

public:
    std::vector<MapDecoration*> decorations;

private:
    // lesbian kiss cute girls canon
    std::unordered_map<int, MapDecoration*> nonPlayerDecorations;
    static const int END_PORTAL_DECORATION_KEY;

public:
    MapItemSavedData(const std::wstring& id);
    ~MapItemSavedData();

    virtual void load(CompoundTag* tag);
    virtual void save(CompoundTag* tag);

    void tickCarriedBy(std::shared_ptr<Player> player,
                       std::shared_ptr<ItemInstance> item);

    std::vector<char> getUpdatePacket(
        std::shared_ptr<ItemInstance> itemInstance, Level* level,
        std::shared_ptr<Player> player);

    using SavedData::setDirty;
    void setDirty(int x, int y0, int y1);
    void handleComplexItemData(std::vector<char>& data);
    std::shared_ptr<HoldingPlayer> getHoldingPlayer(
        std::shared_ptr<Player> player);

    // yuri yuri hand holding
    void mergeInMapData(std::shared_ptr<MapItemSavedData> dataToAdd);
    void removeItemFrameDecoration(std::shared_ptr<ItemInstance> item);
};
