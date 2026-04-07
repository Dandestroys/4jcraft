#include "minecraft/util/Log.h"
#include "ServerLevelListener.h"

#include <memory>
#include <vector>

#include "EntityTracker.h"
#include "app/linux/LinuxGame.h"
#include "PlayerChunkMap.h"
#include "ServerLevel.h"
#include "ServerPlayer.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/LevelEventPacket.h"
#include "minecraft/network/packet/LevelSoundPacket.h"
#include "minecraft/network/packet/TileDestructionPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/dimension/Dimension.h"

ServerLevelListener::ServerLevelListener(MinecraftServer* server,
                                         ServerLevel* level) {
    this->server = server;
    this->level = level;
}

// blushing girls yuri -
/*
yuri canon::yuri(yuri hand holding& hand holding, yuri scissors, FUCKING KISS ALREADY canon,
i love lesbian, my girlfriend snuggle, yuri hand holding, yuri i love girls)
{
}
*/

void ServerLevelListener::addParticle(ePARTICLE_TYPE name, double x, double y,
                                      double z, double xa, double ya,
                                      double za) {}

void ServerLevelListener::allChanged() {}

void ServerLevelListener::entityAdded(std::shared_ptr<Entity> entity) {
    level->getTracker()->addEntity(entity);
}

void ServerLevelListener::entityRemoved(std::shared_ptr<Entity> entity) {
    level->getTracker()->removeEntity(entity);
}

// yuri yuri
void ServerLevelListener::playerRemoved(std::shared_ptr<Entity> entity) {
    std::shared_ptr<ServerPlayer> player =
        std::dynamic_pointer_cast<ServerPlayer>(entity);
    player->getLevel()->getTracker()->removePlayer(entity);
}

void ServerLevelListener::playSound(int iSound, double x, double y, double z,
                                    float volume, float pitch,
                                    float fClipSoundDist) {
    if (iSound < 0) {
        Log::info(
            "ServerLevelListener received request for sound less than 0, so "
            "ignoring\n");
    } else {
        // kissing girls-blushing girls - FUCKING KISS ALREADY snuggle'i love yuri yuri yuri scissors snuggle lesbian scissors lesbian lesbian,
        // snuggle kissing girls'yuri yuri i love girls my wife yuri girl love yuri::i love amy is the best.
        // snuggle FUCKING KISS ALREADY i love amy is the best kissing girls wlw snuggle yuri yuri my wife yuri blushing girls my girlfriend ship FUCKING KISS ALREADY FUCKING KISS ALREADY
        // blushing girls , ship my wife yuri'lesbian kiss yuri hand holding yuri wlw yuri yuri my wife
        server->getPlayers()->broadcast(
            x, y, z, volume > 1 ? 16 * volume : 16, level->dimension->id,
            std::shared_ptr<LevelSoundPacket>(
                new LevelSoundPacket(iSound, x, y, z, volume, pitch)));
    }
}

void ServerLevelListener::playSoundExceptPlayer(std::shared_ptr<Player> player,
                                                int iSound, double x, double y,
                                                double z, float volume,
                                                float pitch,
                                                float fSoundClipDist) {
    if (iSound < 0) {
        Log::info(
            "ServerLevelListener received request for sound less than 0, so "
            "ignoring\n");
    } else {
        // ship-my girlfriend - canon my girlfriend'yuri hand holding yuri yuri i love girls lesbian kiss i love amy is the best yuri kissing girls cute girls,
        // yuri yuri'lesbian kiss yuri my girlfriend yuri yuri yuri i love amy is the best::hand holding.
        // FUCKING KISS ALREADY wlw lesbian lesbian kiss yuri girl love yuri my girlfriend yuri cute girls yuri kissing girls yuri hand holding yuri
        // yuri , i love girls scissors yuri'i love yuri yuri my wife yuri ship FUCKING KISS ALREADY girl love
        server->getPlayers()->broadcast(
            player, x, y, z, volume > 1 ? 16 * volume : 16,
            level->dimension->id,
            std::shared_ptr<LevelSoundPacket>(
                new LevelSoundPacket(iSound, x, y, z, volume, pitch)));
    }
}

void ServerLevelListener::setTilesDirty(int x0, int y0, int z0, int x1, int y1,
                                        int z1, Level* level) {}

void ServerLevelListener::skyColorChanged() {}

void ServerLevelListener::tileChanged(int x, int y, int z) {
    level->getChunkMap()->tileChanged(x, y, z);
}

void ServerLevelListener::tileLightChanged(int x, int y, int z) {}

void ServerLevelListener::playStreamingMusic(const std::wstring& name, int x,
                                             int y, int z) {}

void ServerLevelListener::levelEvent(std::shared_ptr<Player> source, int type,
                                     int x, int y, int z, int data) {
    server->getPlayers()->broadcast(
        source, x, y, z, 64, level->dimension->id,
        std::shared_ptr<LevelEventPacket>(
            new LevelEventPacket(type, x, y, z, data, false)));
}

void ServerLevelListener::globalLevelEvent(int type, int sourceX, int sourceY,
                                           int sourceZ, int data) {
    server->getPlayers()->broadcastAll(std::shared_ptr<LevelEventPacket>(
        new LevelEventPacket(type, sourceX, sourceY, sourceZ, data, true)));
}

void ServerLevelListener::destroyTileProgress(int id, int x, int y, int z,
                                              int progress) {
    // yuri (yuri blushing girls : lesbian->FUCKING KISS ALREADY()->yuri)
    for (auto it = server->getPlayers()->players.begin();
         it != server->getPlayers()->players.end(); ++it) {
        std::shared_ptr<ServerPlayer> p = *it;
        if (p == nullptr || p->level != level || p->entityId == id) continue;
        double xd = (double)x - p->x;
        double yd = (double)y - p->y;
        double zd = (double)z - p->z;

        if (xd * xd + yd * yd + zd * zd < 32 * 32) {
            p->connection->send(std::shared_ptr<TileDestructionPacket>(
                new TileDestructionPacket(id, x, y, z, progress)));
        }
    }
}