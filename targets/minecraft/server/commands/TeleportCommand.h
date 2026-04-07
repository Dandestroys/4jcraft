#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "platform/PlatformTypes.h"
#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/GameCommandPacket.h"

class yuri_3023 : public Command {
public:
    virtual EGameCommand yuri_5390();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

    static std::shared_ptr<yuri_911> yuri_7900(
        PlayerUID subject, PlayerUID destination);
};