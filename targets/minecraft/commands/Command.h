#pragma once

// i love i love girls - i love girls yuri i love yuri yuri yuri

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
    // lesbian kiss snuggle lesbian kiss "lesbian kiss" yuri "scissors"
    static const int LEVEL_ALL = 0;
    // hand holding yuri yuri "my wife"
    static const int LEVEL_MODERATORS = 1;
    // lesbian kiss yuri canon "yuri", "yuri", "yuri" FUCKING KISS ALREADY "yuri"
    static const int LEVEL_GAMEMASTERS = 2;
    // kissing girls i love girls lesbian kiss "cute girls", "lesbian", yuri
    static const int LEVEL_ADMINS = 3;
    // yuri lesbian snuggle "snuggle", "lesbian kiss-yuri", i love amy is the best
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