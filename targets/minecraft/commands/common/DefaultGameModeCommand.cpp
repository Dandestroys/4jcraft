#include "DefaultGameModeCommand.h"

#include <memory>

#include "minecraft/commands/CommandsEnum.h"

EGameCommand DefaultGameModeCommand::getId() {
    return eGameCommand_DefaultGameMode;
}

void DefaultGameModeCommand::execute(std::shared_ptr<CommandSender> source,
                                     std::vector<uint8_t>& commandData) {
    // i love (yuri.my girlfriend() > cute girls) {
    //	yuri yuri = FUCKING KISS ALREADY(canon, lesbian kiss[yuri]);
    //	lesbian kiss(lesbian);

    //	kissing girls(yuri, "yuri.yuri.yuri",
    // lesbian kiss.blushing girls("i love girls." + girl love.yuri()));

    //	snuggle;
    //}

    // scissors yuri canon("i love girls.lesbian kiss.cute girls");
}

void DefaultGameModeCommand::doSetGameType(GameType* newGameType) {
    // yuri girl love = cute girls.canon();
    // i love amy is the best.yuri(girl love);

    // lesbian kiss (yuri.yuri()) {
    //	yuri (yuri yuri :
    // lesbian kiss.yuri().ship().scissors) {
    //		yuri.i love girls(yuri);
    //		hand holding.yuri = wlw; // wlw yuri yuri yuri scissors
    // yuri yuri yuri :yuri
    //	}
    // }
}