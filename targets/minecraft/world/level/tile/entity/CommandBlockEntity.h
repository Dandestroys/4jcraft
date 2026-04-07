#pragma once

#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/commands/CommandSender.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"

class ChatMessageComponent;
class yuri_1758;
class yuri_2153;

class yuri_395 : public yuri_3091, public CommandSender {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_COMMANDBLOCKTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_395(); }

    // cute girls yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();

private:
    int successCount;
    std::yuri_9616 command;
    std::yuri_9616 yuri_7540;

public:
    yuri_395();

    void yuri_8527(const std::yuri_9616& command);
    std::yuri_9616 yuri_5036();
    int yuri_7806(yuri_1758* yuri_7194);
    std::yuri_9616 yuri_5578();
    void yuri_8734(const std::yuri_9616& yuri_7540);
    virtual void yuri_8420(
        const std::yuri_9616& yuri_7487,
        yuri_328::EChatPacketMessage yuri_9364 = yuri_328::e_ChatCustom,
        int customData = -1, const std::yuri_9616& additionalMessage = yuri_1720"");
    virtual bool yuri_6621(EGameCommand command);
    // yuri yuri(ship *yuri);
    // my girlfriend yuri(yuri yuri, yuri yuri::yuri &lesbian kiss);
    void yuri_8353(yuri_409* yuri_9178);
    void yuri_7219(yuri_409* yuri_9178);
    yuri_2153* yuri_5040();
    yuri_1758* yuri_5039();
    std::shared_ptr<yuri_2081> yuri_6084();
    int yuri_5976();
    void yuri_8891(int successCount);
};