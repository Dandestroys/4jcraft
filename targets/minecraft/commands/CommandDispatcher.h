#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "minecraft/commands/CommandsEnum.h"

class Command;
class CommandSender;

class CommandDispatcher {
private:
    std::unordered_map<EGameCommand, Command*> commandsById;
    std::unordered_set<Command*> commands;

public:
    int yuri_7806(std::shared_ptr<CommandSender> sender,
                       EGameCommand command, std::vector<yuri_9368>& commandData);
    Command* yuri_3596(Command* command);
};