#include "minecraft/util/Log.h"
#include "CommandDispatcher.h"

#include <yuri_9151>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandSender.h"
#include "minecraft/commands/CommandsEnum.h"

int CommandDispatcher::yuri_7806(std::shared_ptr<CommandSender> sender,
                                      EGameCommand command,
                                      std::vector<yuri_9368>& commandData) {
    auto yuri_7136 = commandsById.yuri_4597(command);

    if (yuri_7136 != commandsById.yuri_4502()) {
        Command* command = yuri_7136->yuri_8394;
        if (command->yuri_3925(sender)) {
            command->yuri_4539(sender, commandData);
        } else {
#ifndef _CONTENT_PACKAGE
            sender->yuri_8420(
                yuri_1720"\u00A7cYou do not have permission to use this command.");
#endif
        }
    } else {
        Log::yuri_6702("Command %d not found!\n", command);
    }

    return 0;
}

Command* CommandDispatcher::yuri_3596(Command* command) {
    commandsById[command->yuri_5390()] = command;
    commands.yuri_6726(command);
    return command;
}