#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_924;
class CommandSender;

class yuri_916 : public Command {
public:
    virtual EGameCommand yuri_5390();
    int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

protected:
    yuri_924* yuri_5560(std::shared_ptr<CommandSender> yuri_9075,
                               const std::yuri_9616& yuri_7540);
};