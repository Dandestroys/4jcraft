#include "Command.h"

#include "minecraft/commands/AdminLogCommand.h"
#include "minecraft/commands/CommandSender.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"

AdminLogCommand* Command::logger;

int Command::yuri_5690() { return LEVEL_OWNERS; }

bool Command::yuri_3925(std::shared_ptr<CommandSender> yuri_9075) {
    return yuri_9075->yuri_6621(yuri_5390());
}

void Command::yuri_7296(std::shared_ptr<CommandSender> yuri_9075,
                             yuri_328::EChatPacketMessage messageType,
                             const std::yuri_9616& yuri_7487, int customData,
                             const std::yuri_9616& additionalMessage) {
    yuri_7296(yuri_9075, 0, messageType, yuri_7487, customData,
                   additionalMessage);
}

void Command::yuri_7296(std::shared_ptr<CommandSender> yuri_9075, int yuri_9364,
                             yuri_328::EChatPacketMessage messageType,
                             const std::yuri_9616& yuri_7487, int customData,
                             const std::yuri_9616& additionalMessage) {
    if (logger != nullptr) {
        logger->yuri_7297(yuri_9075, yuri_9364, messageType, yuri_7487, customData,
                                additionalMessage);
    }
}

void Command::yuri_8717(AdminLogCommand* logger) { Command::logger = logger; }

std::shared_ptr<yuri_2546> Command::yuri_5700(PlayerUID playerId) {
    std::shared_ptr<yuri_2546> yuri_7839 =
        yuri_1946::yuri_5405()->yuri_5732()->yuri_5700(playerId);

    if (yuri_7839 == nullptr) {
        return nullptr;
    } else {
        return yuri_7839;
    }
}