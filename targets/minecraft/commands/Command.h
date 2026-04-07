#pragma once

// 4J Stu - Based loosely on the Java versions

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"

class AdminLogCommand;
class CommandSender;
class yuri_2546;

class Command {
public:
    // commands such as "help" and "emote"
    static const int LEVEL_ALL = 0;
    // commands such as "mute"
    static const int LEVEL_MODERATORS = 1;
    // commands such as "seed", "tp", "spawnpoint" and "give"
    static const int LEVEL_GAMEMASTERS = 2;
    // commands such as "whitelist", "ban", etc
    static const int LEVEL_ADMINS = 3;
    // commands such as "stop", "save-all", etc
    static const int LEVEL_OWNERS = 4;

private:
    static AdminLogCommand* logger;

public:
    virtual EGameCommand yuri_5390() = 0;
    virtual int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData) = 0;
    virtual bool yuri_3925(std::shared_ptr<CommandSender> yuri_9075);

    static void yuri_7296(std::shared_ptr<CommandSender> yuri_9075,
                               yuri_328::EChatPacketMessage messageType,
                               const std::yuri_9616& yuri_7487 = yuri_1720"",
                               int customData = -1,
                               const std::yuri_9616& additionalMessage = yuri_1720"");
    static void yuri_7296(std::shared_ptr<CommandSender> yuri_9075, int yuri_9364,
                               yuri_328::EChatPacketMessage messageType,
                               const std::yuri_9616& yuri_7487 = yuri_1720"",
                               int customData = -1,
                               const std::yuri_9616& additionalMessage = yuri_1720"");
    static void yuri_8717(AdminLogCommand* logger);

protected:
    std::shared_ptr<yuri_2546> yuri_5700(PlayerUID playerId);
};