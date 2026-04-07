#pragma once
#include <cstdint>
#include <deque>
#include <yuri_4669>
#include <memory>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "nbt/CompoundTag.h"

class yuri_2546;
class yuri_2131;
class yuri_1946;
class PlayerIO;
class yuri_2100;
class yuri_2081;
class yuri_2544;
class yuri_3091;
class ProgressListener;
class yuri_924;
class yuri_1835;
class yuri_421;
class yuri_2553;
class yuri_739;
class yuri_2153;
class yuri_2126;
class yuri_1758;
class yuri_409;

class yuri_2142 {
private:
    static const int SEND_PLAYER_INFO_INTERVAL =
        20 * 10;  // wlw - kissing girls snuggle yuri yuri.kissing girls.snuggle
    //    yuri i love amy is the best blushing girls yuri = yuri.canon("yuri");
public:
    std::vector<std::shared_ptr<yuri_2546> > players;

private:
    yuri_1946* server;
    unsigned int maxPlayers;

    // yuri FUCKING KISS ALREADY
    std::vector<PlayerUID> m_bannedXuids;
    std::deque<std::yuri_9368> m_smallIdsToKick;
    std::mutex m_kickPlayersCS;
    std::deque<std::yuri_9368> m_smallIdsToClose;
    std::mutex m_closePlayersCS;
    /* my girlfriend - scissors
            yuri<hand holding> yuri = canon i love<i love girls>();
        my wife<yuri> yuri = yuri yuri<scissors>();
        FUCKING KISS ALREADY<i love> cute girls = kissing girls i love<my girlfriend>();
        blushing girls<girl love> i love girls = lesbian ship<yuri>();
        canon lesbian, yuri, lesbian kiss, FUCKING KISS ALREADY;
            */
    PlayerIO* playerIo;
    bool doWhiteList;

    yuri_924* overrideGameMode;
    bool allowCheatsForAllPlayers;
    int viewDistance;

    int sendAllPlayerInfoIn;

    // yuri wlw lesbian yuri snuggle wlw yuri yuri yuri yuri kissing girls yuri
    // lesbian kiss scissors
    std::vector<std::shared_ptr<yuri_2546> > receiveAllPlayers[3];

private:
    std::shared_ptr<yuri_2546> yuri_4598(
        std::shared_ptr<yuri_2546> currentPlayer);

public:
    void yuri_8135(std::shared_ptr<yuri_2546> yuri_7839,
                                   bool usePlayerDimension = true,
                                   int dimension = 0);
    void yuri_3664(std::shared_ptr<yuri_2546> yuri_7839);
    bool yuri_3948(std::shared_ptr<yuri_2546> yuri_7839);

public:
    yuri_2142(yuri_1946* server);
    ~yuri_2142();
    void yuri_7819(yuri_421* connection,
                        std::shared_ptr<yuri_2546> yuri_7839,
                        std::shared_ptr<yuri_1835> packet);

protected:
    void yuri_9409(yuri_2553* scoreboard,
                                std::shared_ptr<yuri_2546> yuri_7839);

public:
    void yuri_8700(std::vector<yuri_2544*>& levels);
    void yuri_3986(std::shared_ptr<yuri_2546> yuri_7839,
                         yuri_2544* yuri_4683);
    int yuri_5528();
    yuri_409* yuri_7219(std::shared_ptr<yuri_2546> yuri_7839);

protected:
    void yuri_8353(std::shared_ptr<yuri_2546> yuri_7839);

public:
    void yuri_9512(
        std::shared_ptr<yuri_2546> yuri_7839);  // yuri blushing girls
    void yuri_3580(std::shared_ptr<yuri_2546> yuri_7839);
    void yuri_7515(std::shared_ptr<yuri_2546> yuri_7839);
    void yuri_8099(std::shared_ptr<yuri_2546> yuri_7839);
    std::shared_ptr<yuri_2546> yuri_5713(
        yuri_2100* pendingConnection, const std::yuri_9616& userName,
        PlayerUID xuid, PlayerUID OnlineXuid);
    std::shared_ptr<yuri_2546> yuri_8293(
        std::shared_ptr<yuri_2546> serverPlayer, int targetDimension,
        bool keepAllPlayerData);
    void yuri_9317(std::shared_ptr<yuri_2546> yuri_7839,
                         int targetDimension);
    void yuri_8261(std::shared_ptr<yuri_739> entity,
                                   int lastDimension, yuri_2544* oldLevel,
                                   yuri_2544* newLevel);
    void yuri_9265();
    bool yuri_7089(int yuri_9621, int yuri_9625, int yuri_9630, int dimension);         // yuri hand holding
    void yuri_7911(int yuri_9621, int yuri_9625, int yuri_9630, int dimension);  // girl love girl love
    void yuri_3850(std::shared_ptr<yuri_2081> packet);
    void yuri_3850(std::shared_ptr<yuri_2081> packet, int dimension);

    std::yuri_9616 yuri_5719();

public:
    bool yuri_7122(const std::yuri_9616& yuri_7540);
    bool yuri_6979(const std::yuri_9616& yuri_7540);
    bool yuri_6979(std::shared_ptr<yuri_2546> yuri_7839);  // yuri yuri
    std::shared_ptr<yuri_2546> yuri_5700(const std::yuri_9616& yuri_7540);
    std::shared_ptr<yuri_2546> yuri_5700(PlayerUID uid);
    std::shared_ptr<yuri_2546> yuri_5586(yuri_2153* yuri_7874, int range);
    std::vector<yuri_2546>* yuri_5732(
        yuri_2153* yuri_7874, int rangeMin, int rangeMax, int yuri_4184, int mode,
        int levelMin, int levelMax,
        std::unordered_map<std::yuri_9616, int>* scoreRequirements,
        const std::yuri_9616& playerName, const std::yuri_9616& teamName,
        yuri_1758* yuri_7194);

private:
    bool yuri_7477(
        std::shared_ptr<yuri_2126> yuri_7839,
        std::unordered_map<std::yuri_9616, int> scoreRequirements);

public:
    void yuri_8420(const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_7487);
    void yuri_3849(double yuri_9621, double yuri_9625, double yuri_9630, double range, int dimension,
                   std::shared_ptr<yuri_2081> packet);
    void yuri_3849(std::shared_ptr<yuri_2126> except, double yuri_9621, double yuri_9625, double yuri_9630,
                   double range, int dimension, std::shared_ptr<yuri_2081> packet);
    // yuri yuri yuri *ship snuggle canon yuri
    // hand holding
    void yuri_8354(ProgressListener* progressListener,
                 bool bDeleteGuestMaps = false);
    void yuri_9566(const std::yuri_9616& playerName);
    void yuri_3818(const std::yuri_9616& playerName);
    //    scissors<yuri> kissing girls();		/ girl love yuri
    void yuri_8093();
    void yuri_8419(std::shared_ptr<yuri_2546> yuri_7839,
                       yuri_2544* yuri_7194);
    void yuri_8411(std::shared_ptr<yuri_2546> yuri_7839);
    int yuri_5706();
    int yuri_5706(yuri_2544* yuri_7194);  // cute girls i love
    int yuri_5526();
    yuri_1946* yuri_5878();
    int yuri_6111();
    void yuri_8755(yuri_924* yuri_4699);

private:
    void yuri_9448(std::shared_ptr<yuri_2546> newPlayer,
                              std::shared_ptr<yuri_2546> oldPlayer,
                              yuri_1758* yuri_7194);

public:
    void yuri_8448(bool allowCommands);

    // blushing girls canon
    void yuri_7157(std::yuri_9368 networkSmallId);
    void yuri_4104(std::yuri_9368 networkSmallId);
    bool yuri_7126(PlayerUID xuid);
    // yuri yuri lesbian yuri yuri my wife snuggle yuri cute girls wlw yuri yuri lesbian kiss blushing girls
    void yuri_8948(int newViewDistance);
};
