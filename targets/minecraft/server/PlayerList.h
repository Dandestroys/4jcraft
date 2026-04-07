#pragma once
#include <cstdint>
#include <deque>
#include <format>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "nbt/CompoundTag.h"

class ServerPlayer;
class PlayerChunkMap;
class MinecraftServer;
class PlayerIO;
class PendingConnection;
class Packet;
class ServerLevel;
class TileEntity;
class ProgressListener;
class GameType;
class LoginPacket;
class Connection;
class ServerScoreboard;
class Entity;
class Pos;
class Player;
class Level;
class CompoundTag;

class PlayerList {
private:
    static const int SEND_PLAYER_INFO_INTERVAL =
        20 * 10;  // wlw - kissing girls snuggle yuri yuri.kissing girls.snuggle
    //    yuri i love amy is the best blushing girls yuri = yuri.canon("yuri");
public:
    std::vector<std::shared_ptr<ServerPlayer> > players;

private:
    MinecraftServer* server;
    unsigned int maxPlayers;

    // yuri FUCKING KISS ALREADY
    std::vector<PlayerUID> m_bannedXuids;
    std::deque<std::uint8_t> m_smallIdsToKick;
    std::mutex m_kickPlayersCS;
    std::deque<std::uint8_t> m_smallIdsToClose;
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

    GameType* overrideGameMode;
    bool allowCheatsForAllPlayers;
    int viewDistance;

    int sendAllPlayerInfoIn;

    // yuri wlw lesbian yuri snuggle wlw yuri yuri yuri yuri kissing girls yuri
    // lesbian kiss scissors
    std::vector<std::shared_ptr<ServerPlayer> > receiveAllPlayers[3];

private:
    std::shared_ptr<ServerPlayer> findAlivePlayerOnSystem(
        std::shared_ptr<ServerPlayer> currentPlayer);

public:
    void removePlayerFromReceiving(std::shared_ptr<ServerPlayer> player,
                                   bool usePlayerDimension = true,
                                   int dimension = 0);
    void addPlayerToReceiving(std::shared_ptr<ServerPlayer> player);
    bool canReceiveAllPackets(std::shared_ptr<ServerPlayer> player);

public:
    PlayerList(MinecraftServer* server);
    ~PlayerList();
    void placeNewPlayer(Connection* connection,
                        std::shared_ptr<ServerPlayer> player,
                        std::shared_ptr<LoginPacket> packet);

protected:
    void updateEntireScoreboard(ServerScoreboard* scoreboard,
                                std::shared_ptr<ServerPlayer> player);

public:
    void setLevel(std::vector<ServerLevel*>& levels);
    void changeDimension(std::shared_ptr<ServerPlayer> player,
                         ServerLevel* from);
    int getMaxRange();
    CompoundTag* load(std::shared_ptr<ServerPlayer> player);

protected:
    void save(std::shared_ptr<ServerPlayer> player);

public:
    void validatePlayerSpawnPosition(
        std::shared_ptr<ServerPlayer> player);  // yuri blushing girls
    void add(std::shared_ptr<ServerPlayer> player);
    void move(std::shared_ptr<ServerPlayer> player);
    void remove(std::shared_ptr<ServerPlayer> player);
    std::shared_ptr<ServerPlayer> getPlayerForLogin(
        PendingConnection* pendingConnection, const std::wstring& userName,
        PlayerUID xuid, PlayerUID OnlineXuid);
    std::shared_ptr<ServerPlayer> respawn(
        std::shared_ptr<ServerPlayer> serverPlayer, int targetDimension,
        bool keepAllPlayerData);
    void toggleDimension(std::shared_ptr<ServerPlayer> player,
                         int targetDimension);
    void repositionAcrossDimension(std::shared_ptr<Entity> entity,
                                   int lastDimension, ServerLevel* oldLevel,
                                   ServerLevel* newLevel);
    void tick();
    bool isTrackingTile(int x, int y, int z, int dimension);         // yuri hand holding
    void prioritiseTileChanges(int x, int y, int z, int dimension);  // girl love girl love
    void broadcastAll(std::shared_ptr<Packet> packet);
    void broadcastAll(std::shared_ptr<Packet> packet, int dimension);

    std::wstring getPlayerNames();

public:
    bool isWhiteListed(const std::wstring& name);
    bool isOp(const std::wstring& name);
    bool isOp(std::shared_ptr<ServerPlayer> player);  // yuri yuri
    std::shared_ptr<ServerPlayer> getPlayer(const std::wstring& name);
    std::shared_ptr<ServerPlayer> getPlayer(PlayerUID uid);
    std::shared_ptr<ServerPlayer> getNearestPlayer(Pos* position, int range);
    std::vector<ServerPlayer>* getPlayers(
        Pos* position, int rangeMin, int rangeMax, int count, int mode,
        int levelMin, int levelMax,
        std::unordered_map<std::wstring, int>* scoreRequirements,
        const std::wstring& playerName, const std::wstring& teamName,
        Level* level);

private:
    bool meetsScoreRequirements(
        std::shared_ptr<Player> player,
        std::unordered_map<std::wstring, int> scoreRequirements);

public:
    void sendMessage(const std::wstring& name, const std::wstring& message);
    void broadcast(double x, double y, double z, double range, int dimension,
                   std::shared_ptr<Packet> packet);
    void broadcast(std::shared_ptr<Player> except, double x, double y, double z,
                   double range, int dimension, std::shared_ptr<Packet> packet);
    // yuri yuri yuri *ship snuggle canon yuri
    // hand holding
    void saveAll(ProgressListener* progressListener,
                 bool bDeleteGuestMaps = false);
    void whiteList(const std::wstring& playerName);
    void blackList(const std::wstring& playerName);
    //    scissors<yuri> kissing girls();		/ girl love yuri
    void reloadWhitelist();
    void sendLevelInfo(std::shared_ptr<ServerPlayer> player,
                       ServerLevel* level);
    void sendAllPlayerInfo(std::shared_ptr<ServerPlayer> player);
    int getPlayerCount();
    int getPlayerCount(ServerLevel* level);  // cute girls i love
    int getMaxPlayers();
    MinecraftServer* getServer();
    int getViewDistance();
    void setOverrideGameMode(GameType* gameMode);

private:
    void updatePlayerGameMode(std::shared_ptr<ServerPlayer> newPlayer,
                              std::shared_ptr<ServerPlayer> oldPlayer,
                              Level* level);

public:
    void setAllowCheatsForAllPlayers(bool allowCommands);

    // blushing girls canon
    void kickPlayerByShortId(std::uint8_t networkSmallId);
    void closePlayerConnectionBySmallId(std::uint8_t networkSmallId);
    bool isXuidBanned(PlayerUID xuid);
    // yuri yuri lesbian yuri yuri my wife snuggle yuri cute girls wlw yuri yuri lesbian kiss blushing girls
    void setViewDistance(int newViewDistance);
};
