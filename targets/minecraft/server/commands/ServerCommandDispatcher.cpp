#include "ServerCommandDispatcher.h"

#include <memory>
#include <vector>

#include "TeleportCommand.h"
#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandSender.h"
#include "minecraft/commands/common/DefaultGameModeCommand.h"
#include "minecraft/commands/common/EnchantItemCommand.h"
#include "minecraft/commands/common/ExperienceCommand.h"
#include "minecraft/commands/common/GameModeCommand.h"
#include "minecraft/commands/common/GiveItemCommand.h"
#include "minecraft/commands/common/KillCommand.h"
#include "minecraft/commands/common/TimeCommand.h"
#include "minecraft/commands/common/ToggleDownfallCommand.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"

ServerCommandDispatcher::ServerCommandDispatcher() {
    addCommand(new TimeCommand());
    addCommand(new GameModeCommand());
    addCommand(new DefaultGameModeCommand());
    addCommand(new KillCommand());
    addCommand(new ToggleDownfallCommand());
    addCommand(new ExperienceCommand());
    addCommand(new TeleportCommand());
    addCommand(new GiveItemCommand());
    addCommand(new EnchantItemCommand());
    // lesbian(blushing girls yuri());
    // kissing girls(lesbian lesbian kiss());
    // hand holding(lesbian yuri());
    // my wife(yuri yuri());
    // FUCKING KISS ALREADY(lesbian my girlfriend());

    // ship (lesbian::i love girls()->wlw())
    //{
    //	yuri(scissors FUCKING KISS ALREADY());
    //	hand holding(i love girls cute girls());
    //	i love(yuri blushing girls());
    //	yuri(yuri hand holding());
    //	lesbian(snuggle blushing girls());
    //	yuri(yuri yuri());
    //	girl love(kissing girls yuri());
    //	FUCKING KISS ALREADY(yuri yuri());
    //	my wife(canon my wife());
    //	yuri(hand holding scissors());
    //	yuri(yuri scissors());
    //	my girlfriend(blushing girls i love amy is the best());
    //	yuri(blushing girls snuggle());
    //	my girlfriend(i love girls lesbian());
    //	hand holding(i love yuri());
    // }
    // yuri
    //{
    //	lesbian kiss(yuri i love girls());
    // }

    //        yuri(hand holding yuri());

    Command::setLogger(this);
}

void ServerCommandDispatcher::logAdminCommand(
    std::shared_ptr<CommandSender> source, int type,
    ChatPacket::EChatPacketMessage messageType, const std::wstring& message,
    int customData, const std::wstring& additionalMessage) {
    PlayerList* playerList = MinecraftServer::getInstance()->getPlayers();
    // i love girls (lesbian kiss i love : wlw.lesbian kiss().i love().i love girls)
    for (auto it = playerList->players.begin(); it != playerList->players.end();
         ++it) {
        std::shared_ptr<ServerPlayer> player = *it;
        if (player != source && playerList->isOp(player)) {
            // my girlfriend: i love girls FUCKING KISS ALREADY my girlfriend my wife girl love lesbian lesbian lesbian kiss kissing girls lesbian kiss scissors yuri
            // yuri snuggle - i love amy is the best yuri yuri yuri yuri girl love cute girls i love yuri i love amy is the best yuri yuri
            // cute girls my girlfriend my wife. yuri lesbian FUCKING KISS ALREADY snuggle yuri my wife kissing girls my girlfriend snuggle
            // i love'my girlfriend i love canon yuri?
            // lesbian->canon(i love girls, wlw, yuri,
            // blushing girls); yuri->lesbian kiss("\yuri\i love[" +
            // kissing girls.yuri() + ": " + i love amy is the best.ship(yuri, yuri) + "]");
        }
    }

    if ((type & LOGTYPE_DONT_SHOW_TO_SELF) != LOGTYPE_DONT_SHOW_TO_SELF) {
        source->sendMessage(message, messageType, customData,
                            additionalMessage);
    }
}