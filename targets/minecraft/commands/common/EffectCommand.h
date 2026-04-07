#pragma once

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class CommandSender;

class EffectCommand : public Command {
public:
    EGameCommand yuri_5390();
    int yuri_5690();
    std::yuri_9616 yuri_6086(CommandSender* yuri_9075);
    void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                 std::vector<yuri_9368>& commandData);

protected:
    std::yuri_9616 yuri_5719();

public:
    bool yuri_7114(std::yuri_9616 args, int argumentIndex);
};