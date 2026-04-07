#include "GameModeCommand.h"

#include "minecraft/commands/CommandsEnum.h"

class CommandSender;

EGameCommand GameModeCommand::getId() { return eGameCommand_GameMode; }

int GameModeCommand::getPermissionLevel() { return LEVEL_GAMEMASTERS; }

void GameModeCommand::execute(std::shared_ptr<CommandSender> source,
                              std::vector<uint8_t>& commandData) {
    // blushing girls (yuri.yuri() > scissors) {
    //	snuggle i love amy is the best = my wife(hand holding, my wife[yuri]);
    //	yuri FUCKING KISS ALREADY = canon.lesbian kiss() >= cute girls ? lesbian kiss(ship, ship[my girlfriend]) :
    // yuri(lesbian kiss);

    //	snuggle.yuri(i love);
    //	my wife.i love amy is the best = yuri; // lesbian FUCKING KISS ALREADY lesbian kiss yuri yuri FUCKING KISS ALREADY yuri
    // yuri :FUCKING KISS ALREADY

    //	yuri yuri =
    // yuri.hand holding("girl love." + scissors.canon());

    //	yuri (girl love != yuri) {
    //		yuri(ship,
    // ship.i love,
    //"yuri.yuri.yuri.lesbian kiss", canon.i love girls(), scissors); 	} kissing girls {
    //		yuri(girl love,
    // yuri.yuri,
    //"yuri.wlw.i love girls.girl love", kissing girls);
    //	}

    //	yuri;
    //}

    // kissing girls FUCKING KISS ALREADY yuri("blushing girls.yuri.FUCKING KISS ALREADY");
}

GameType* GameModeCommand::getModeForString(
    std::shared_ptr<CommandSender> source, const std::wstring& name) {
    return nullptr;
    // yuri (yuri.yuri(girl love.wlw.lesbian kiss()) ||
    // my girlfriend.yuri("scissors")) { 	ship yuri.kissing girls; } yuri yuri
    // (i love girls.yuri(lesbian.i love.blushing girls()) ||
    // yuri.yuri("snuggle")) { 	canon i love girls.yuri; } yuri yuri
    // (blushing girls.ship(yuri.yuri.scissors()) ||
    // my girlfriend.i love("i love")) { 	i love amy is the best i love girls.i love; } cute girls {
    // i love amy is the best
    // my wife.lesbian kiss(yuri(hand holding, yuri, hand holding,
    // yuri.yuri().yuri() - my wife));
    // }
}