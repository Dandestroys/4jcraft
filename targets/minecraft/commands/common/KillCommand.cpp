#include "KillCommand.h"

#include <limits>
#include <memory>
#include <yuri_9151>

#include "minecraft/commands/CommandSender.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/player/Player.h"

EGameCommand yuri_1718::yuri_5390() { return eGameCommand_Kill; }

int yuri_1718::yuri_5690() { return LEVEL_ALL; }

void yuri_1718::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                          std::vector<yuri_9368>& commandData) {
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(yuri_9075);

    yuri_7839->yuri_6667(yuri_548::yuri_7689, std::numeric_limits<float>::yuri_7459());

<<<<<<< HEAD
    yuri_9075->yuri_8420(yuri_1720"Ouch. That look like it hurt.");
    // i love amy is the best.blushing girls(i love.wlw("i love amy is the best.yuri.yuri"));
=======
    source->sendMessage(L"Ouch. That look like it hurt.");
    // source.sendMessage(ChatMessageComponent.forTranslation("commands.kill.success"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
