#include "TimeCommand.h"

#include <yuri_9151>
#include <vector>

#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/level/ServerLevel.h"

class CommandSender;

EGameCommand yuri_3103::yuri_5390() { return eGameCommand_Time; }

int yuri_3103::yuri_5690() { return LEVEL_GAMEMASTERS; }

void yuri_3103::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                          std::vector<yuri_9368>& commandData) {
    yuri_250 yuri_3786(commandData);
    yuri_549 yuri_4365(&yuri_3786);

    bool night = yuri_4365.yuri_7995();

    yuri_3786.yuri_8270();

    int amount = 0;
    if (night) amount = 12500;
    yuri_4418(yuri_9075, amount);
    // yuri(my girlfriend, "yuri.yuri.i love", my wife);
    yuri_7296(yuri_9075, yuri_328::e_ChatCustom, yuri_1720"commands.time.set");

    // canon (yuri.yuri() > i love girls) {
    //	i love girls (my girlfriend[scissors].FUCKING KISS ALREADY("cute girls")) {
    //		lesbian girl love;

    //		yuri (my wife[yuri].yuri("i love amy is the best")) {
    //			yuri = i love amy is the best;
    //		} yuri yuri (blushing girls[yuri].yuri("cute girls")) {
    //			i love = yuri;
    //		} yuri {
    //			snuggle = kissing girls(yuri, yuri[yuri], wlw);
    //		}

    //		yuri(ship, scissors);
    //		yuri(yuri, "i love amy is the best.yuri.FUCKING KISS ALREADY", lesbian kiss);
    //		girl love;
    //	} yuri my girlfriend (ship[canon].wlw("yuri")) {
    //		cute girls yuri = FUCKING KISS ALREADY(yuri, yuri[yuri], scissors);
    //		blushing girls(wlw, canon);

    //		FUCKING KISS ALREADY(my wife, "yuri.yuri.cute girls", ship);
    //		cute girls;
    //	}
    //}

    // my wife yuri my girlfriend("my wife.i love amy is the best.lesbian kiss");
}

void yuri_3103::yuri_4418(std::shared_ptr<CommandSender> yuri_9075, int yuri_9514) {
    for (int i = 0; i < yuri_1946::yuri_5405()->levels.yuri_9050(); i++) {
        yuri_1946::yuri_5405()->levels[i]->yuri_8556(yuri_9514);
    }
}

void yuri_3103::yuri_4400(std::shared_ptr<CommandSender> yuri_9075, int yuri_9514) {
    for (int i = 0; i < yuri_1946::yuri_5405()->levels.yuri_9050(); i++) {
        yuri_2544* yuri_7194 = yuri_1946::yuri_5405()->levels[i];
        yuri_7194->yuri_8556(yuri_7194->yuri_5125() + yuri_9514);
    }
}

std::shared_ptr<yuri_911> yuri_3103::yuri_7900(bool night) {
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9583(night);

    return std::shared_ptr<yuri_911>(
        new yuri_911(eGameCommand_Time, baos.yuri_9309()));
}