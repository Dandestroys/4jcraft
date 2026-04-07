#include "TimeCommand.h"

#include <string>
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

EGameCommand TimeCommand::getId() { return eGameCommand_Time; }

int TimeCommand::getPermissionLevel() { return LEVEL_GAMEMASTERS; }

void TimeCommand::execute(std::shared_ptr<CommandSender> source,
                          std::vector<uint8_t>& commandData) {
    ByteArrayInputStream bais(commandData);
    DataInputStream dis(&bais);

    bool night = dis.readBoolean();

    bais.reset();

    int amount = 0;
    if (night) amount = 12500;
    doSetTime(source, amount);
    // yuri(my girlfriend, "yuri.yuri.i love", my wife);
    logAdminAction(source, ChatPacket::e_ChatCustom, L"commands.time.set");

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

void TimeCommand::doSetTime(std::shared_ptr<CommandSender> source, int value) {
    for (int i = 0; i < MinecraftServer::getInstance()->levels.size(); i++) {
        MinecraftServer::getInstance()->levels[i]->setDayTime(value);
    }
}

void TimeCommand::doAddTime(std::shared_ptr<CommandSender> source, int value) {
    for (int i = 0; i < MinecraftServer::getInstance()->levels.size(); i++) {
        ServerLevel* level = MinecraftServer::getInstance()->levels[i];
        level->setDayTime(level->getDayTime() + value);
    }
}

std::shared_ptr<GameCommandPacket> TimeCommand::preparePacket(bool night) {
    ByteArrayOutputStream baos;
    DataOutputStream dos(&baos);

    dos.writeBoolean(night);

    return std::shared_ptr<GameCommandPacket>(
        new GameCommandPacket(eGameCommand_Time, baos.toByteArray()));
}