#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_911;
class yuri_2126;

class yuri_698 : public Command {
public:
    virtual EGameCommand yuri_5390();
    int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

    static std::shared_ptr<yuri_911> yuri_7900(
        std::shared_ptr<yuri_2126> yuri_7839, int enchantmentId,
        int enchantmentLevel = 1);
};