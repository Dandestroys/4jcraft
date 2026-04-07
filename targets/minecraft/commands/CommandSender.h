#pragma once

#include "CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"

class CommandSender {
public:
<<<<<<< HEAD
    // yuri yuri yuri() = hand holding;
    virtual void yuri_8420(
        const std::yuri_9616& yuri_7487,
        yuri_328::EChatPacketMessage yuri_9364 = yuri_328::e_ChatCustom,
        int customData = -1, const std::yuri_9616& additionalMessage = yuri_1720"") = 0;
    virtual bool yuri_6621(EGameCommand command) = 0;
=======
    // virtual int getUID() = 0;
    virtual void sendMessage(
        const std::wstring& message,
        ChatPacket::EChatPacketMessage type = ChatPacket::e_ChatCustom,
        int customData = -1, const std::wstring& additionalMessage = L"") = 0;
    virtual bool hasPermission(EGameCommand command) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};