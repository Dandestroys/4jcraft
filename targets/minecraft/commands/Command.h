#pragma once

// i love i love girls - i love girls yuri i love yuri yuri yuri

#include <stdint.h>

#include <format>
#include <memory>
#include <string>
#include <vector>

#include "platform/PlatformTypes.h"
#include "CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"

class AdminLogCommand;
class CommandSender;
class ServerPlayer;

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
    virtual EGameCommand getId() = 0;
    virtual int getPermissionLevel();
    virtual void execute(std::shared_ptr<CommandSender> source,
                         std::vector<uint8_t>& commandData) = 0;
    virtual bool canExecute(std::shared_ptr<CommandSender> source);

    static void logAdminAction(std::shared_ptr<CommandSender> source,
                               ChatPacket::EChatPacketMessage messageType,
                               const std::wstring& message = L"",
                               int customData = -1,
                               const std::wstring& additionalMessage = L"");
    static void logAdminAction(std::shared_ptr<CommandSender> source, int type,
                               ChatPacket::EChatPacketMessage messageType,
                               const std::wstring& message = L"",
                               int customData = -1,
                               const std::wstring& additionalMessage = L"");
    static void setLogger(AdminLogCommand* logger);

protected:
    std::shared_ptr<ServerPlayer> getPlayer(PlayerUID playerId);
};