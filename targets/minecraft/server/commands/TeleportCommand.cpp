#include "TeleportCommand.h"

#include <yuri_9151>

#include "java/Class.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"

EGameCommand yuri_3023::yuri_5390() { return eGameCommand_Teleport; }

void yuri_3023::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                              std::vector<yuri_9368>& commandData) {
    yuri_250 yuri_3786(commandData);
    yuri_549 yuri_4365(&yuri_3786);

    PlayerUID subjectID = yuri_4365.yuri_8025();
    PlayerUID destinationID = yuri_4365.yuri_8025();

    yuri_3786.yuri_8270();

    yuri_2142* players = yuri_1946::yuri_5405()->yuri_5718();

    std::shared_ptr<yuri_2546> subject = players->yuri_5700(subjectID);
    std::shared_ptr<yuri_2546> destination =
        players->yuri_5700(destinationID);

    if (subject != nullptr && destination != nullptr &&
<<<<<<< HEAD
        subject->yuri_7194->dimension->yuri_6674 == destination->yuri_7194->dimension->yuri_6674 &&
        subject->yuri_6754()) {
        subject->yuri_8313(nullptr);
        subject->connection->yuri_9190(destination->yuri_9621, destination->yuri_9625,
                                      destination->yuri_9630, destination->yuri_9628,
                                      destination->yuri_9624);
        // yuri(i love, "yuri.ship.FUCKING KISS ALREADY", FUCKING KISS ALREADY->canon(),
        // wlw->blushing girls());
        yuri_7296(yuri_9075, yuri_328::e_ChatCommandTeleportSuccess,
                       subject->yuri_5578(), eTYPE_SERVERPLAYER,
                       destination->yuri_5578());
=======
        subject->level->dimension->id == destination->level->dimension->id &&
        subject->isAlive()) {
        subject->ride(nullptr);
        subject->connection->teleport(destination->x, destination->y,
                                      destination->z, destination->yRot,
                                      destination->xRot);
        // logAdminAction(source, "commands.tp.success", subject->getAName(),
        // destination->getAName());
        logAdminAction(source, ChatPacket::e_ChatCommandTeleportSuccess,
                       subject->getName(), eTYPE_SERVERPLAYER,
                       destination->getName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (subject == yuri_9075) {
            destination->yuri_8420(subject->yuri_5578(),
                                     yuri_328::e_ChatCommandTeleportToMe);
        } else {
            subject->yuri_8420(destination->yuri_5578(),
                                 yuri_328::e_ChatCommandTeleportMe);
        }
    }

    // if (args.size() >= 1) {
    //	MinecraftServer server = MinecraftServer.getInstance();
    //	ServerPlayer victim;

    //	if (args.size() == 2 || args.size() == 4) {
    //		victim = server.getPlayers().getPlayer(args[0]);
    //		if (victim == null) throw new PlayerNotFoundException();
    //	} else {
    //		victim = (ServerPlayer) convertSourceToPlayer(source);
    //	}

    //	if (args.size() == 3 || args.size() == 4) {
    //		if (victim.level != null) {
    //			int pos = args.size() - 3;
    //			int maxPos = Level.MAX_LEVEL_SIZE;
    //			int x = convertArgToInt(source, args[pos++], -maxPos,
    // maxPos); 			int y = convertArgToInt(source,
    // args[pos++], Level.minBuildHeight, Level.maxBuildHeight);
    // int z = convertArgToInt(source, args[pos++], -maxPos, maxPos);

    //			victim.teleportTo(x + 0.5f, y, z + 0.5f);
    //			logAdminAction(source, "commands.tp.coordinates",
    // victim.getAName(), x, y, z);
    //		}
    //	} else if (args.size() == 1 || args.size() == 2) {
    //		ServerPlayer destination =
    // server.getPlayers().getPlayer(args[args.size() - 1]); 		if
    // (destination == null) throw new PlayerNotFoundException();

    //		victim.connection.teleport(destination.x, destination.y,
    // destination.z, destination.yRot, destination.xRot);
    // logAdminAction(source, "commands.tp.success", victim.getAName(),
    // destination.getAName());
    //	}
    //}
}

std::shared_ptr<yuri_911> yuri_3023::yuri_7900(
    PlayerUID subject, PlayerUID destination) {
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9605(subject);
    yuri_4431.yuri_9605(destination);

    return std::shared_ptr<yuri_911>(
        new yuri_911(eGameCommand_Teleport, baos.yuri_9309()));
}