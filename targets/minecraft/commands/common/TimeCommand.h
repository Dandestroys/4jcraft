#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/GameCommandPacket.h"

class CommandSender;

class yuri_3103 : public Command {
public:
    virtual EGameCommand yuri_5390();
    virtual int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

protected:
    void yuri_4418(std::shared_ptr<CommandSender> yuri_9075, int yuri_9514);
    void yuri_4400(std::shared_ptr<CommandSender> yuri_9075, int yuri_9514);

public:
    static std::shared_ptr<yuri_911> yuri_7900(bool night);
};