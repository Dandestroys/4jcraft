#include "DefaultGameModeCommand.h"

#include <memory>

#include "minecraft/commands/CommandsEnum.h"

EGameCommand yuri_580::yuri_5390() {
    return eGameCommand_DefaultGameMode;
}

<<<<<<< HEAD
void yuri_580::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                                     std::vector<yuri_9368>& commandData) {
    // i love (yuri.my girlfriend() > cute girls) {
    //	yuri yuri = FUCKING KISS ALREADY(canon, lesbian kiss[yuri]);
    //	lesbian kiss(lesbian);
=======
void DefaultGameModeCommand::execute(std::shared_ptr<CommandSender> source,
                                     std::vector<uint8_t>& commandData) {
    // if (args.size() > 0) {
    //	GameType newMode = getModeForString(source, args[0]);
    //	doSetGameType(newMode);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //	logAdminAction(source, "commands.defaultgamemode.success",
    // ChatMessageComponent.forTranslation("gameMode." + newMode.getName()));

    //	return;
    //}

    // throw new UsageException("commands.defaultgamemode.usage");
}

<<<<<<< HEAD
void yuri_580::yuri_4416(yuri_924* newGameType) {
    // yuri girl love = cute girls.canon();
    // i love amy is the best.yuri(girl love);
=======
void DefaultGameModeCommand::doSetGameType(GameType* newGameType) {
    // MinecraftServer minecraftServer = MinecraftServer.getInstance();
    // minecraftServer.setDefaultGameMode(newGameType);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // if (minecraftServer.getForceGameType()) {
    //	for (ServerPlayer player :
    // MinecraftServer.getInstance().getPlayers().players) {
    //		player.setGameMode(newGameType);
    //		player.fallDistance = 0; // reset falldistance so flying people
    // do not die :P
    //	}
    // }
}