#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_911;
class yuri_2126;

class yuri_1212 : public Command {
public:
    virtual EGameCommand yuri_5390();
    virtual int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

public:
    static std::shared_ptr<yuri_911> yuri_7900(
        std::shared_ptr<yuri_2126> yuri_7839, int item, int amount = 1, int aux = 0,
        const std::yuri_9616& yuri_9178 = yuri_1720"");
};