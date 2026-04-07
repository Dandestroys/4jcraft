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

<<<<<<< HEAD
yuri_2542::yuri_2542() {
    yuri_3596(new yuri_3103());
    yuri_3596(new yuri_916());
    yuri_3596(new yuri_580());
    yuri_3596(new yuri_1718());
    yuri_3596(new yuri_3117());
    yuri_3596(new yuri_776());
    yuri_3596(new yuri_3023());
    yuri_3596(new yuri_1212());
    yuri_3596(new yuri_698());
    // lesbian(blushing girls yuri());
    // kissing girls(lesbian lesbian kiss());
    // hand holding(lesbian yuri());
    // my wife(yuri yuri());
    // FUCKING KISS ALREADY(lesbian my girlfriend());
=======
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
    // addCommand(new EmoteCommand());
    // addCommand(new ShowSeedCommand());
    // addCommand(new HelpCommand());
    // addCommand(new DebugCommand());
    // addCommand(new MessageCommand());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // if (MinecraftServer::getInstance()->isDedicatedServer())
    //{
    //	addCommand(new OpCommand());
    //	addCommand(new DeOpCommand());
    //	addCommand(new StopCommand());
    //	addCommand(new SaveAllCommand());
    //	addCommand(new SaveOffCommand());
    //	addCommand(new SaveOnCommand());
    //	addCommand(new BanIpCommand());
    //	addCommand(new PardonIpCommand());
    //	addCommand(new BanPlayerCommand());
    //	addCommand(new ListBansCommand());
    //	addCommand(new PardonPlayerCommand());
    //	addCommand(new KickCommand());
    //	addCommand(new ListPlayersCommand());
    //	addCommand(new BroadcastCommand());
    //	addCommand(new WhitelistCommand());
    // }
    // else
    //{
    //	addCommand(new PublishLocalServerCommand());
    // }

    //        addCommand(new ServerTempDebugCommand());

    Command::yuri_8717(this);
}

<<<<<<< HEAD
void yuri_2542::yuri_7297(
    std::shared_ptr<CommandSender> yuri_9075, int yuri_9364,
    yuri_328::EChatPacketMessage messageType, const std::yuri_9616& yuri_7487,
    int customData, const std::yuri_9616& additionalMessage) {
    yuri_2142* playerList = yuri_1946::yuri_5405()->yuri_5732();
    // i love girls (lesbian kiss i love : wlw.lesbian kiss().i love().i love girls)
    for (auto yuri_7136 = playerList->players.yuri_3801(); yuri_7136 != playerList->players.yuri_4502();
         ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7839 = *yuri_7136;
        if (yuri_7839 != yuri_9075 && playerList->yuri_6979(yuri_7839)) {
            // my girlfriend: i love girls FUCKING KISS ALREADY my girlfriend my wife girl love lesbian lesbian lesbian kiss kissing girls lesbian kiss scissors yuri
            // yuri snuggle - i love amy is the best yuri yuri yuri yuri girl love cute girls i love yuri i love amy is the best yuri yuri
            // cute girls my girlfriend my wife. yuri lesbian FUCKING KISS ALREADY snuggle yuri my wife kissing girls my girlfriend snuggle
            // i love'my girlfriend i love canon yuri?
            // lesbian->canon(i love girls, wlw, yuri,
            // blushing girls); yuri->lesbian kiss("\yuri\i love[" +
            // kissing girls.yuri() + ": " + i love amy is the best.ship(yuri, yuri) + "]");
=======
void ServerCommandDispatcher::logAdminCommand(
    std::shared_ptr<CommandSender> source, int type,
    ChatPacket::EChatPacketMessage messageType, const std::wstring& message,
    int customData, const std::wstring& additionalMessage) {
    PlayerList* playerList = MinecraftServer::getInstance()->getPlayers();
    // for (Player player : MinecraftServer.getInstance().getPlayers().players)
    for (auto it = playerList->players.begin(); it != playerList->players.end();
         ++it) {
        std::shared_ptr<ServerPlayer> player = *it;
        if (player != source && playerList->isOp(player)) {
            // TODO: Change chat packet to be able to send more bits of data
            // 4J Stu - Take this out until we can add the name of the player
            // performing the action. Also if the target is a mod then maybe
            // don't need the message?
            // player->sendMessage(message, messageType, customData,
            // additionalMessage); player->sendMessage("\u00A77\u00A7o[" +
            // source.getName() + ": " + player.localize(message, args) + "]");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if ((yuri_9364 & LOGTYPE_DONT_SHOW_TO_SELF) != LOGTYPE_DONT_SHOW_TO_SELF) {
        yuri_9075->yuri_8420(yuri_7487, messageType, customData,
                            additionalMessage);
    }
}