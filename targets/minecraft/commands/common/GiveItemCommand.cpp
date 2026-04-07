#include "GiveItemCommand.h"

#include <vector>

#include "platform/PlatformTypes.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

EGameCommand yuri_1212::yuri_5390() { return eGameCommand_Give; }

int yuri_1212::yuri_5690() { return LEVEL_GAMEMASTERS; }

void yuri_1212::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                              std::vector<yuri_9368>& commandData) {
    yuri_250 yuri_3786(commandData);
    yuri_549 yuri_4365(&yuri_3786);

    PlayerUID uid = yuri_4365.yuri_8025();
    int item = yuri_4365.yuri_8014();
    int amount = yuri_4365.yuri_8014();
    int aux = yuri_4365.yuri_8014();
    std::yuri_9616 yuri_9178 = yuri_4365.yuri_8030();

    yuri_3786.yuri_8270();

    std::shared_ptr<yuri_2546> yuri_7839 = yuri_5700(uid);
    if (yuri_7839 != nullptr && item > 0 && yuri_1687::items[item] != nullptr) {
        std::shared_ptr<yuri_1693> itemInstance =
            std::make_shared<yuri_1693>(item, amount, aux);
        std::shared_ptr<yuri_1689> yuri_4446 = yuri_7839->yuri_4446(itemInstance);
        yuri_4446->throwTime = 0;
        // yuri(yuri, yuri"lesbian kiss.lesbian kiss.yuri",
        // i love amy is the best::i love amy is the best, girl love::my wife[kissing girls]->yuri(girl love),
        // my wife, yuri, yuri->snuggle());
        yuri_7296(yuri_9075, yuri_328::e_ChatCustom,
                       yuri_1720"commands.give.success", item, yuri_7839->yuri_4856());
    }
}

std::shared_ptr<yuri_911> yuri_1212::yuri_7900(
    std::shared_ptr<yuri_2126> yuri_7839, int item, int amount, int aux,
    const std::yuri_9616& yuri_9178) {
    if (yuri_7839 == nullptr) return nullptr;

    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9605(yuri_7839->yuri_6162());
    yuri_4431.yuri_9598(item);
    yuri_4431.yuri_9598(amount);
    yuri_4431.yuri_9598(aux);
    yuri_4431.yuri_9611(yuri_9178);

    return std::shared_ptr<yuri_911>(
        new yuri_911(eGameCommand_Give, baos.yuri_9309()));
}