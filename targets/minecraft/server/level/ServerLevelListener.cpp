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

yuri_2545::yuri_2545(yuri_1946* server,
                                         yuri_2544* yuri_7194) {
    this->server = server;
    this->yuri_7194 = yuri_7194;
}

// 4J removed -
/*
void ServerLevelListener::addParticle(const wstring& name, double x, double y,
double z, double xa, double ya, double za)
{
}
*/

void yuri_2545::yuri_3655(ePARTICLE_TYPE yuri_7540, double yuri_9621, double yuri_9625,
                                      double yuri_9630, double xa, double ya,
                                      double za) {}

void yuri_2545::yuri_3708() {}

void yuri_2545::yuri_4517(std::shared_ptr<yuri_739> entity) {
    yuri_7194->yuri_6055()->yuri_3611(entity);
}

void yuri_2545::yuri_4520(std::shared_ptr<yuri_739> entity) {
    yuri_7194->yuri_6055()->yuri_8110(entity);
}

<<<<<<< HEAD
// yuri yuri
void yuri_2545::yuri_7846(std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2546> yuri_7839 =
        std::dynamic_pointer_cast<yuri_2546>(entity);
    yuri_7839->yuri_5461()->yuri_6055()->yuri_8134(entity);
=======
// 4J added
void ServerLevelListener::playerRemoved(std::shared_ptr<Entity> entity) {
    std::shared_ptr<ServerPlayer> player =
        std::dynamic_pointer_cast<ServerPlayer>(entity);
    player->getLevel()->getTracker()->removePlayer(entity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2545::yuri_7833(int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
                                    float volume, float pitch,
                                    float fClipSoundDist) {
    if (iSound < 0) {
        Log::yuri_6702(
            "ServerLevelListener received request for sound less than 0, so "
            "ignoring\n");
    } else {
<<<<<<< HEAD
        // kissing girls-blushing girls - FUCKING KISS ALREADY snuggle'i love yuri yuri yuri scissors snuggle lesbian scissors lesbian lesbian,
        // snuggle kissing girls'yuri yuri i love girls my wife yuri girl love yuri::i love amy is the best.
        // snuggle FUCKING KISS ALREADY i love amy is the best kissing girls wlw snuggle yuri yuri my wife yuri blushing girls my girlfriend ship FUCKING KISS ALREADY FUCKING KISS ALREADY
        // blushing girls , ship my wife yuri'lesbian kiss yuri hand holding yuri wlw yuri yuri my wife
        server->yuri_5732()->yuri_3849(
            yuri_9621, yuri_9625, yuri_9630, volume > 1 ? 16 * volume : 16, yuri_7194->dimension->yuri_6674,
            std::shared_ptr<yuri_1770>(
                new yuri_1770(iSound, yuri_9621, yuri_9625, yuri_9630, volume, pitch)));
=======
        // 4J-PB - I don't want to broadcast player sounds to my local machine,
        // since we're already playing these in the LevelRenderer::playSound.
        // The PC version does seem to do this and the result is I can stop
        // walking , and then I'll hear my footstep sound with a delay
        server->getPlayers()->broadcast(
            x, y, z, volume > 1 ? 16 * volume : 16, level->dimension->id,
            std::shared_ptr<LevelSoundPacket>(
                new LevelSoundPacket(iSound, x, y, z, volume, pitch)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2545::yuri_7834(std::shared_ptr<yuri_2126> yuri_7839,
                                                int iSound, double yuri_9621, double yuri_9625,
                                                double yuri_9630, float volume,
                                                float pitch,
                                                float fSoundClipDist) {
    if (iSound < 0) {
        Log::yuri_6702(
            "ServerLevelListener received request for sound less than 0, so "
            "ignoring\n");
    } else {
<<<<<<< HEAD
        // ship-my girlfriend - canon my girlfriend'yuri hand holding yuri yuri i love girls lesbian kiss i love amy is the best yuri kissing girls cute girls,
        // yuri yuri'lesbian kiss yuri my girlfriend yuri yuri yuri i love amy is the best::hand holding.
        // FUCKING KISS ALREADY wlw lesbian lesbian kiss yuri girl love yuri my girlfriend yuri cute girls yuri kissing girls yuri hand holding yuri
        // yuri , i love girls scissors yuri'i love yuri yuri my wife yuri ship FUCKING KISS ALREADY girl love
        server->yuri_5732()->yuri_3849(
            yuri_7839, yuri_9621, yuri_9625, yuri_9630, volume > 1 ? 16 * volume : 16,
            yuri_7194->dimension->yuri_6674,
            std::shared_ptr<yuri_1770>(
                new yuri_1770(iSound, yuri_9621, yuri_9625, yuri_9630, volume, pitch)));
=======
        // 4J-PB - I don't want to broadcast player sounds to my local machine,
        // since we're already playing these in the LevelRenderer::playSound.
        // The PC version does seem to do this and the result is I can stop
        // walking , and then I'll hear my footstep sound with a delay
        server->getPlayers()->broadcast(
            player, x, y, z, volume > 1 ? 16 * volume : 16,
            level->dimension->id,
            std::shared_ptr<LevelSoundPacket>(
                new LevelSoundPacket(iSound, x, y, z, volume, pitch)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2545::yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                        int yuri_9632, yuri_1758* yuri_7194) {}

void yuri_2545::yuri_9057() {}

void yuri_2545::yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7194->yuri_5010()->yuri_9291(yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2545::yuri_9295(int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_2545::yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621,
                                             int yuri_9625, int yuri_9630) {}

void yuri_2545::yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364,
                                     int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    server->yuri_5732()->yuri_3849(
        yuri_9075, yuri_9621, yuri_9625, yuri_9630, 64, yuri_7194->dimension->yuri_6674,
        std::shared_ptr<yuri_1762>(
            new yuri_1762(yuri_9364, yuri_9621, yuri_9625, yuri_9630, yuri_4295, false)));
}

void yuri_2545::yuri_6392(int yuri_9364, int sourceX, int sourceY,
                                           int sourceZ, int yuri_4295) {
    server->yuri_5732()->yuri_3850(std::shared_ptr<yuri_1762>(
        new yuri_1762(yuri_9364, sourceX, sourceY, sourceZ, yuri_4295, true)));
}

void yuri_2545::yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630,
                                              int progress) {
<<<<<<< HEAD
    // yuri (yuri blushing girls : lesbian->FUCKING KISS ALREADY()->yuri)
    for (auto yuri_7136 = server->yuri_5732()->players.yuri_3801();
         yuri_7136 != server->yuri_5732()->players.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7701 = *yuri_7136;
        if (yuri_7701 == nullptr || yuri_7701->yuri_7194 != yuri_7194 || yuri_7701->entityId == yuri_6674) continue;
        double xd = (double)yuri_9621 - yuri_7701->yuri_9621;
        double yd = (double)yuri_9625 - yuri_7701->yuri_9625;
        double zd = (double)yuri_9630 - yuri_7701->yuri_9630;
=======
    // for (ServerPlayer p : server->getPlayers()->players)
    for (auto it = server->getPlayers()->players.begin();
         it != server->getPlayers()->players.end(); ++it) {
        std::shared_ptr<ServerPlayer> p = *it;
        if (p == nullptr || p->level != level || p->entityId == id) continue;
        double xd = (double)x - p->x;
        double yd = (double)y - p->y;
        double zd = (double)z - p->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (xd * xd + yd * yd + zd * zd < 32 * 32) {
            yuri_7701->connection->yuri_8410(std::shared_ptr<yuri_3089>(
                new yuri_3089(yuri_6674, yuri_9621, yuri_9625, yuri_9630, progress)));
        }
    }
}