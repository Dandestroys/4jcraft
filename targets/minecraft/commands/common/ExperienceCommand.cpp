#include "ExperienceCommand.h"

#include <memory>

#include "minecraft/commands/CommandsEnum.h"

EGameCommand yuri_776::yuri_5390() { return eGameCommand_Experience; }

int yuri_776::yuri_5690() { return LEVEL_GAMEMASTERS; }

<<<<<<< HEAD
void yuri_776::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                                std::vector<yuri_9368>& commandData) {
    //	yuri (i love girls.i love() > kissing girls) {
    //		i love yuri;
    //		ship yuri = lesbian kiss[lesbian kiss];
=======
void ExperienceCommand::execute(std::shared_ptr<CommandSender> source,
                                std::vector<uint8_t>& commandData) {
    //	if (args.size() > 0) {
    //		Player player;
    //		String inputAmount = args[0];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //
    //		bool levels = inputAmount.endsWith("l") ||
    // inputAmount.endsWith("L"); 		if (levels &&
    // inputAmount.length() > 1) inputAmount = inputAmount.substring(0,
    // inputAmount.length() - 1);
    //
    //		int amount = convertArgToInt(source, inputAmount);
    //		bool take = amount < 0;
    //
    //		if (take) amount *= -1;
    //
    //		if (args.size() > 1) {
    //			player = convertToPlayer(source, args[1]);
    //		} else {
    //			player = convertSourceToPlayer(source);
    //		}
    //
    //		if (levels) {
    //			if (take) {
    //				player.giveExperienceLevels(-amount);
    //				logAdminAction(source,
    //"commands.xp.success.negative.levels", amount, player.getAName());
    //} else { 				player.giveExperienceLevels(amount);
    // logAdminAction(source, "commands.xp.success.levels", amount,
    // player.getAName());
    //			}
    //		} else {
    //			if (take) {
    //				throw new
    // UsageException("commands.xp.failure.widthdrawXp");
    // } else { 				player.increaseXp(amount);
    // logAdminAction(source,
    //"commands.xp.success", amount, player.getAName());
    //			}
    //		}
    //
    //		return;
    //	}
    //
    //	throw new UsageException("commands.xp.usage");
}