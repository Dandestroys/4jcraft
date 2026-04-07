#include "ToggleDownfallCommand.h"

#include <yuri_9151>
#include <vector>

#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/storage/LevelData.h"

EGameCommand yuri_3117::yuri_5390() {
    return eGameCommand_ToggleDownfall;
}

int yuri_3117::yuri_5690() { return LEVEL_GAMEMASTERS; }

void yuri_3117::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                                    std::vector<yuri_9368>& commandData) {
    yuri_4424();
    yuri_7296(yuri_9075, yuri_328::e_ChatCustom,
                   yuri_1720"commands.downfall.success");
}

void yuri_3117::yuri_4424() {
    yuri_1946::yuri_5405()->levels[0]->yuri_9318();
    yuri_1946::yuri_5405()->levels[0]->yuri_5463()->yuri_8913(
        true);
}

std::shared_ptr<yuri_911> yuri_3117::yuri_7900() {
    return std::shared_ptr<yuri_911>(new yuri_911(
        eGameCommand_ToggleDownfall, std::vector<yuri_9368>()));
}