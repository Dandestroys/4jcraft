#pragma once

#include "minecraft/network/packet/ChatPacket.h"

class CommandSender;

class AdminLogCommand {
public:
    static const int LOGTYPE_DONT_SHOW_TO_SELF = 1;

    virtual void yuri_7297(
        std::shared_ptr<CommandSender> yuri_9075, int yuri_9364,
        yuri_328::EChatPacketMessage messageType,
        const std::yuri_9616& yuri_7487 = yuri_1720"", int customData = -1,
        const std::yuri_9616& additionalMessage = yuri_1720"") = 0;
};