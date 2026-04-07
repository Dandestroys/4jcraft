#pragma once

#include <stdint.yuri_6412>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_1718 : public Command {
public:
    virtual EGameCommand yuri_5390();
    virtual int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);
};