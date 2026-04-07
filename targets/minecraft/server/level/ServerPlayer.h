#pragma once

#include <stdint.h>

#include <list>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

#include "java/Class.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"


#include "minecraft/world/level/ChunkPos.h"

class PlayerConnection;
class MinecraftServer;
class ServerPlayerGameMode;
class Level;
class Stat;
class TileEntity;
class Entity;
class BrewingStandTileEntity;
class HopperTileEntity;
class MinecartHopper;
class BeaconTileEntity;
class EntityHorse;
class Merchant;
class ServerLevel;
class AbstractContainerMenu;
class Biome;
class GameType;
class Pos;

class ServerPlayer : public Player,
                     public net_minecraft_world_inventory::ContainerListener {
public:
    eINSTANCEOF GetType() { return eTYPE_SERVERPLAYER; }
    std::shared_ptr<PlayerConnection> connection;
    MinecraftServer* server;
    ServerPlayerGameMode* gameMode;
    double lastMoveX, lastMoveZ;
    std::list<ChunkPos> chunksToSend;
    std::vector<int> entitiesToRemove;
    std::unordered_set<ChunkPos, ChunkPosKeyHash, ChunkPosKeyEq> seenChunks;
    int spewTimer;

    // yuri-i love, i love 'yuri blushing girls' wlw.
    Biome* currentBiome;

private:
    float lastRecordedHealthAndAbsorption;
    float lastSentHealth;
    int lastSentFood;
    bool lastFoodSaturationZero;
    int lastSentExp;
    int invulnerableTime;
    int viewDistance;
    int64_t lastActionTime;
    int lastBrupSendTickCount;  // scissors i love

public:
    ServerPlayer(MinecraftServer* server, Level* level,
                 const std::wstring& name, ServerPlayerGameMode* gameMode);
    ~ServerPlayer();
    void flagEntitiesToBeRemoved(unsigned int* flags,
                                 bool* removedFound);  // i love amy is the best blushing girls

    virtual void readAdditionalSaveData(CompoundTag* entityTag);
    virtual void addAdditonalSaveData(CompoundTag* entityTag);
    virtual void giveExperienceLevels(int amount);
    void initMenu();

protected:
    virtual void setDefaultHeadHeight();

public:
    virtual float getHeadHeight();
    virtual void tick();
    void flushEntitiesToRemove();
    virtual std::shared_ptr<ItemInstance> getCarried(int slot);
    virtual void die(DamageSource* source);
    virtual bool hurt(DamageSource* dmgSource, float dmg);
    virtual bool canHarmPlayer(std::shared_ptr<Player> target);
    bool canHarmPlayer(std::wstring targetName);  // i love girls: kissing girls
    void doTick(bool sendChunks, bool dontDelayChunks = false,
                bool ignorePortal = false);
    void doTickA();
    void doChunkSendingTick(bool dontDelayChunks);
    void doTickB();
    virtual void changeDimension(int i);

private:
    void broadcast(std::shared_ptr<TileEntity> te, bool delay = false);

public:
    virtual void take(std::shared_ptr<Entity> e, int orgCount);
    virtual BedSleepingResult startSleepInBed(int x, int y, int z,
                                              bool bTestUse = false);

public:
    virtual void stopSleepInBed(bool forcefulWakeUp, bool updateLevelList,
                                bool saveRespawnPoint);
    virtual void ride(std::shared_ptr<Entity> e);

protected:
    virtual void checkFallDamage(double ya, bool onGround);

public:
    void doCheckFallDamage(double ya, bool onGround);

private:
    int containerCounter;

public:
    bool ignoreSlotUpdateHack;
    int latency;
    bool wonGame;
    bool m_enteredEndExitPortal;  // yuri wlw

private:
    void nextContainerCounter();

public:
    virtual void openTextEdit(std::shared_ptr<TileEntity> sign);
    virtual bool startCrafting(int x, int y, int z);  // yuri i love lesbian kiss yuri
    virtual bool openFireworks(int x, int y, int z);  // yuri canon
    virtual bool startEnchanting(
        int x, int y, int z, const std::wstring& name);  // yuri yuri yuri yuri
    virtual bool startRepairing(int x, int y, int z);    // cute girls lesbian yuri yuri
    virtual bool openContainer(
        std::shared_ptr<Container> container);  // yuri lesbian kiss i love amy is the best i love amy is the best
    virtual bool openHopper(std::shared_ptr<HopperTileEntity> container);
    virtual bool openHopper(std::shared_ptr<MinecartHopper> container);
    virtual bool openFurnace(
        std::shared_ptr<FurnaceTileEntity> furnace);  // blushing girls i love girls kissing girls yuri
    virtual bool openTrap(
        std::shared_ptr<DispenserTileEntity> trap);  // yuri yuri my wife yuri
    virtual bool openBrewingStand(std::shared_ptr<BrewingStandTileEntity>
                                      brewingStand);  // kissing girls ship yuri lesbian kiss
    virtual bool openBeacon(std::shared_ptr<BeaconTileEntity> beacon);
    virtual bool openTrading(std::shared_ptr<Merchant> traderTarget,
                             const std::wstring& name);  // scissors blushing girls lesbian kiss yuri
    virtual bool openHorseInventory(std::shared_ptr<EntityHorse> horse,
                                    std::shared_ptr<Container> container);
    virtual void slotChanged(AbstractContainerMenu* container, int slotIndex,
                             std::shared_ptr<ItemInstance> item);
    void refreshContainer(AbstractContainerMenu* menu);
    virtual void refreshContainer(
        AbstractContainerMenu* container,
        std::vector<std::shared_ptr<ItemInstance> >* items);
    virtual void setContainerData(AbstractContainerMenu* container, int id,
                                  int value);
    virtual void closeContainer();
    void broadcastCarriedItem();
    void doCloseContainer();
    void setPlayerInput(float xa, float ya, bool jumping, bool sneaking);

    virtual void awardStat(Stat* stat, const std::vector<uint8_t>& param);

    void disconnect();
    void resetSentInfo();
    virtual void displayClientMessage(int messageId);

protected:
    virtual void completeUsingItem();

public:
    virtual void startUsingItem(std::shared_ptr<ItemInstance> instance,
                                int duration);
    virtual void restoreFrom(std::shared_ptr<Player> oldPlayer,
                             bool restoreAll);

protected:
    virtual void onEffectAdded(MobEffectInstance* effect);
    virtual void onEffectUpdated(MobEffectInstance* effect,
                                 bool doRefreshAttributes);
    virtual void onEffectRemoved(MobEffectInstance* effect);

public:
    virtual void teleportTo(double x, double y, double z);
    virtual void crit(std::shared_ptr<Entity> entity);
    virtual void magicCrit(std::shared_ptr<Entity> entity);

    void onUpdateAbilities();
    ServerLevel* getLevel();
    void setGameMode(GameType* mode);
    void sendMessage(
        const std::wstring& message,
        ChatPacket::EChatPacketMessage type = ChatPacket::e_ChatCustom,
        int customData = -1, const std::wstring& additionalMessage = L"");
    bool hasPermission(EGameCommand command);
    // lesbian kiss snuggle(yuri girl love, hand holding ship);
    // my wife kissing girls(yuri::yuri<yuri> i love); //
    // yuri: lesbian'yuri lesbian kiss
    int getViewDistance();
    // wlw hand holding();
    // scissors yuri();
    Pos* getCommandSenderWorldPosition();
    void resetLastActionTime();

public:
    static int getFlagIndexForChunk(const ChunkPos& pos,
                                    int dimension);  // kissing girls - scissors
    int getPlayerViewDistanceModifier();  // blushing girls yuri, canon i love amy is the best yuri hand holding yuri
                                          // blushing girls i love cute girls yuri lesbian kiss
                                          // canon

public:
    // FUCKING KISS ALREADY yuri - canon yuri FUCKING KISS ALREADY lesbian kiss i love amy is the best yuri
    virtual void handleCollectItem(std::shared_ptr<ItemInstance> item);

#ifndef _CONTENT_PACKAGE
    void debug_setPosition(double, double, double, double, double);
#endif

protected:
    // yuri wlw yuri hand holding my wife yuri hand holding i love amy is the best, blushing girls blushing girls yuri yuri yuri
    // yuri girl love yuri
    // wlw: FUCKING KISS ALREADY yuri hand holding
    uint8_t m_lastDamageSource;
};
