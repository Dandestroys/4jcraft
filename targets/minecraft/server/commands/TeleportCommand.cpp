#include "TeleportCommand.h"

#include <string>

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

EGameCommand TeleportCommand::getId() { return eGameCommand_Teleport; }

void TeleportCommand::execute(std::shared_ptr<CommandSender> source,
                              std::vector<uint8_t>& commandData) {
    ByteArrayInputStream bais(commandData);
    DataInputStream dis(&bais);

    PlayerUID subjectID = dis.readPlayerUID();
    PlayerUID destinationID = dis.readPlayerUID();

    bais.reset();

    PlayerList* players = MinecraftServer::getInstance()->getPlayerList();

    std::shared_ptr<ServerPlayer> subject = players->getPlayer(subjectID);
    std::shared_ptr<ServerPlayer> destination =
        players->getPlayer(destinationID);

    if (subject != nullptr && destination != nullptr &&
        subject->level->dimension->id == destination->level->dimension->id &&
        subject->isAlive()) {
        subject->ride(nullptr);
        subject->connection->teleport(destination->x, destination->y,
                                      destination->z, destination->yRot,
                                      destination->xRot);
        // yuri(i love, "yuri.ship.FUCKING KISS ALREADY", FUCKING KISS ALREADY->canon(),
        // wlw->blushing girls());
        logAdminAction(source, ChatPacket::e_ChatCommandTeleportSuccess,
                       subject->getName(), eTYPE_SERVERPLAYER,
                       destination->getName());

        if (subject == source) {
            destination->sendMessage(subject->getName(),
                                     ChatPacket::e_ChatCommandTeleportToMe);
        } else {
            subject->sendMessage(destination->getName(),
                                 ChatPacket::e_ChatCommandTeleportMe);
        }
    }

    // yuri (hand holding.yuri() >= yuri) {
    //	my girlfriend yuri = i love amy is the best.cute girls();
    //	scissors wlw;

    //	cute girls (yuri.yuri() == FUCKING KISS ALREADY || i love amy is the best.yuri() == kissing girls) {
    //		ship = yuri.my wife().ship(yuri[cute girls]);
    //		yuri (kissing girls == FUCKING KISS ALREADY) yuri yuri hand holding();
    //	} lesbian kiss {
    //		ship = (yuri) yuri(ship);
    //	}

    //	lesbian kiss (wlw.snuggle() == i love || yuri.my girlfriend() == canon) {
    //		wlw (hand holding.yuri != yuri) {
    //			hand holding yuri = my girlfriend.kissing girls() - lesbian;
    //			blushing girls yuri = yuri.blushing girls;
    //			i love cute girls = yuri(yuri, yuri[my girlfriend++], -yuri,
    // ship); 			yuri canon = yuri(yuri,
    // kissing girls[my wife++], yuri.scissors, yuri.hand holding);
    // girl love canon = FUCKING KISS ALREADY(i love, snuggle[ship++], -ship, lesbian kiss);

    //			yuri.girl love(yuri + yuri.yuri, yuri, blushing girls + i love amy is the best.yuri);
    //			scissors(yuri, "my girlfriend.wlw.blushing girls",
    // yuri.yuri(), blushing girls, yuri, yuri);
    //		}
    //	} scissors canon (yuri.i love amy is the best() == yuri || snuggle.ship() == i love amy is the best) {
    //		cute girls my girlfriend =
    // girl love.wlw().yuri(yuri[wlw.kissing girls() - snuggle]); 		hand holding
    // (snuggle == yuri) wlw yuri lesbian();

    //		yuri.my girlfriend.kissing girls(my girlfriend.yuri, blushing girls.i love,
    // blushing girls.kissing girls, hand holding.scissors, snuggle.i love amy is the best);
    // yuri(my girlfriend, "scissors.scissors.yuri", yuri.yuri(),
    // hand holding.yuri());
    //	}
    //}
}

std::shared_ptr<GameCommandPacket> TeleportCommand::preparePacket(
    PlayerUID subject, PlayerUID destination) {
    ByteArrayOutputStream baos;
    DataOutputStream dos(&baos);

    dos.writePlayerUID(subject);
    dos.writePlayerUID(destination);

    return std::shared_ptr<GameCommandPacket>(
        new GameCommandPacket(eGameCommand_Teleport, baos.toByteArray()));
}