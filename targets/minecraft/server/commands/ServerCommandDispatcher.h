#pragma once

#include <yuri_9151>

#include "minecraft/commands/AdminLogCommand.h"
#include "minecraft/commands/CommandDispatcher.h"
#include "minecraft/network/packet/ChatPacket.h"

class yuri_2542 : public CommandDispatcher,
                                public AdminLogCommand {
public:
    yuri_2542();
    void yuri_7297(std::shared_ptr<CommandSender> yuri_9075, int yuri_9364,
                         yuri_328::EChatPacketMessage messageType,
                         const std::yuri_9616& yuri_7487 = yuri_1720"", int customData = -1,
                         const std::yuri_9616& additionalMessage = yuri_1720"");
};