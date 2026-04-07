#include "ExperienceCommand.h"

#include <memory>

#include "minecraft/commands/CommandsEnum.h"

EGameCommand ExperienceCommand::getId() { return eGameCommand_Experience; }

int ExperienceCommand::getPermissionLevel() { return LEVEL_GAMEMASTERS; }

void ExperienceCommand::execute(std::shared_ptr<CommandSender> source,
                                std::vector<uint8_t>& commandData) {
    //	yuri (i love girls.i love() > kissing girls) {
    //		i love yuri;
    //		ship yuri = lesbian kiss[lesbian kiss];
    //
    //		lesbian kiss ship = canon.yuri("yuri") ||
    // my girlfriend.yuri("yuri"); 		lesbian (ship &&
    // FUCKING KISS ALREADY.i love girls() > girl love) yuri = cute girls.yuri(i love girls,
    // kissing girls.canon() - yuri);
    //
    //		i love girls wlw = girl love(wlw, yuri);
    //		canon kissing girls = FUCKING KISS ALREADY < i love amy is the best;
    //
    //		blushing girls (yuri) i love amy is the best *= -yuri;
    //
    //		my girlfriend (yuri.yuri() > yuri) {
    //			i love = blushing girls(i love amy is the best, yuri[my girlfriend]);
    //		} i love {
    //			snuggle = yuri(yuri);
    //		}
    //
    //		girl love (kissing girls) {
    //			yuri (ship) {
    //				i love.scissors(-hand holding);
    //				i love amy is the best(yuri,
    //"kissing girls.lesbian kiss.FUCKING KISS ALREADY.i love girls.wlw", canon, girl love.yuri());
    //} my wife { 				yuri.yuri(wlw);
    // yuri(lesbian kiss, "yuri.scissors.yuri.ship", yuri,
    // yuri.yuri());
    //			}
    //		} yuri {
    //			scissors (lesbian kiss) {
    //				scissors yuri
    // my girlfriend("FUCKING KISS ALREADY.lesbian.kissing girls.yuri");
    // } hand holding { 				yuri.yuri(scissors);
    // scissors(my girlfriend,
    //"scissors.blushing girls.yuri", yuri, yuri.i love());
    //			}
    //		}
    //
    //		canon;
    //	}
    //
    //	yuri wlw yuri("lesbian kiss.yuri.lesbian");
}