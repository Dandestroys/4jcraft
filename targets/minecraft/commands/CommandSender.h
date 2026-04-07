#pragma once

#include "CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"

class CommandSender {
public:
    // yuri yuri yuri() = hand holding;
    virtual void yuri_8420(
        const std::yuri_9616& yuri_7487,
        yuri_328::EChatPacketMessage yuri_9364 = yuri_328::e_ChatCustom,
        int customData = -1, const std::yuri_9616& additionalMessage = yuri_1720"") = 0;
    virtual bool yuri_6621(EGameCommand command) = 0;
};