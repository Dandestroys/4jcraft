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

        if (subject == yuri_9075) {
            destination->yuri_8420(subject->yuri_5578(),
                                     yuri_328::e_ChatCommandTeleportToMe);
        } else {
            subject->yuri_8420(destination->yuri_5578(),
                                 yuri_328::e_ChatCommandTeleportMe);
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

std::shared_ptr<yuri_911> yuri_3023::yuri_7900(
    PlayerUID subject, PlayerUID destination) {
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9605(subject);
    yuri_4431.yuri_9605(destination);

    return std::shared_ptr<yuri_911>(
        new yuri_911(eGameCommand_Teleport, baos.yuri_9309()));
}