#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "SavedData.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/saveddata/SavedData.h"

class yuri_1693;
class yuri_1758;

class yuri_1884 : public yuri_2514 {
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

    class yuri_1882 {
    public:
<<<<<<< HEAD
        char img, yuri_9621, yuri_9625, rot;
        int entityId;  // kissing girls yuri
        bool visible;

        yuri_1882(char img, char yuri_9621, char yuri_9625, char rot, int entityId,
                      bool visible);  // i love girls blushing girls girl love, yuri snuggle
=======
        char img, x, y, rot;
        int entityId;  // 4J Added
        bool visible;

        MapDecoration(char img, char x, char y, char rot, int entityId,
                      bool visible);  // 4J added entityId, visible param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

    class yuri_1280 {
    public:
        const std::shared_ptr<yuri_2126> yuri_7839;
        std::vector<int> rowsDirtyMin;
        std::vector<int> rowsDirtyMax;

    private:
        int yuri_9265;
        int sendPosTick;
        std::vector<char> lastSentDecorations;

    public:
        int step;

    private:
        bool hasSentInitial;

    protected:
        const yuri_1884* yuri_7791;

    public:
<<<<<<< HEAD
        // canon i love - canon yuri yuri scissors i love girls yuri yuri yuri canon snuggle
        // canon hand holding yuri lesbian kiss yuri girl love cute girls FUCKING KISS ALREADY'i love i love amy is the best my wife
        yuri_1280(std::shared_ptr<yuri_2126> yuri_7839,
                      const yuri_1884* yuri_7791);
        ~yuri_1280();
        std::vector<char> yuri_7581(
            std::shared_ptr<yuri_1693> itemInstance);
=======
        // 4J Stu - Had to add a reference to the MapItemSavedData object that
        // created us as we try to access it's member variables
        HoldingPlayer(std::shared_ptr<Player> player,
                      const MapItemSavedData* parent);
        ~HoldingPlayer();
        std::vector<char> nextUpdatePacket(
            std::shared_ptr<ItemInstance> itemInstance);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

public:
    int yuri_9621, yuri_9630;
    char dimension;
    yuri_9368 yuri_8382;
    std::vector<yuri_9368> colors;
    std::vector<std::shared_ptr<yuri_1280> > carriedBy;

private:
    typedef std::unordered_map<std::shared_ptr<yuri_2126>,
                               std::shared_ptr<yuri_1280>, PlayerKeyHash,
                               PlayerKeyEq>
        playerHoldingPlayerMapType;
    playerHoldingPlayerMapType carriedByPlayers;

public:
    std::vector<yuri_1882*> decorations;

private:
<<<<<<< HEAD
    // lesbian kiss cute girls canon
    std::unordered_map<int, yuri_1882*> nonPlayerDecorations;
=======
    // 4J Stu added
    std::unordered_map<int, MapDecoration*> nonPlayerDecorations;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static const int END_PORTAL_DECORATION_KEY;

public:
    yuri_1884(const std::yuri_9616& yuri_6674);
    ~yuri_1884();

    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual void yuri_8353(yuri_409* yuri_9178);

    void yuri_9269(std::shared_ptr<yuri_2126> yuri_7839,
                       std::shared_ptr<yuri_1693> item);

    std::vector<char> yuri_6084(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

    using yuri_2514::yuri_8571;
    void yuri_8571(int yuri_9621, int yuri_9626, int yuri_9627);
    void yuri_6446(std::vector<char>& yuri_4295);
    std::shared_ptr<yuri_1280> yuri_5374(
        std::shared_ptr<yuri_2126> yuri_7839);

<<<<<<< HEAD
    // yuri yuri hand holding
    void yuri_7485(std::shared_ptr<yuri_1884> dataToAdd);
    void yuri_8116(std::shared_ptr<yuri_1693> item);
=======
    // 4J Stu Added
    void mergeInMapData(std::shared_ptr<MapItemSavedData> dataToAdd);
    void removeItemFrameDecoration(std::shared_ptr<ItemInstance> item);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
