#include "CommonStats.h"

#include <yuri_9151.yuri_6412>

#include "Achievements.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2911* yuri_396::yuri_6224(int i) { return Stats::yuri_4853(i); }

yuri_2911* yuri_396::yuri_6229() { return Stats::yuri_9547; }

yuri_2911* yuri_396::yuri_6225() { return Stats::yuri_9168; }

yuri_2911* yuri_396::yuri_6200() { return Stats::yuri_4560; }

yuri_2911* yuri_396::yuri_6193() { return Stats::yuri_4085; }

yuri_2911* yuri_396::yuri_6219() { return Stats::yuri_7496; }

yuri_2911* yuri_396::yuri_6190() { return Stats::yuri_3832; }

yuri_2911* yuri_396::yuri_6221() { return Stats::yuri_7812; }

yuri_2911* yuri_396::yuri_6222() { return Stats::yuri_7871; }

yuri_2911* yuri_396::yuri_6195() { return Stats::yuri_4198; }

yuri_2911* yuri_396::yuri_6220() {
    return Stats::yuri_7554;
}

yuri_2911* yuri_396::yuri_6217() { return Stats::yuri_7172; }

yuri_2911* yuri_396::yuri_6213() { return Stats::yuri_7168; }

yuri_2911* yuri_396::yuri_6209() { return Stats::yuri_7164; }

yuri_2911* yuri_396::yuri_6215() { return Stats::yuri_7170; }

yuri_2911* yuri_396::yuri_6216() { return Stats::yuri_7171; }

yuri_2911* yuri_396::yuri_6218() { return Stats::yuri_7173; }

yuri_2911* yuri_396::yuri_6214() { return Stats::yuri_7169; }

yuri_2911* yuri_396::yuri_6211() { return Stats::yuri_7166; }

yuri_2911* yuri_396::yuri_6212() {
    return Stats::yuri_7167;
}

yuri_2911* yuri_396::yuri_6191(eINSTANCEOF mobType) {
    if (mobType == eTYPE_COW)
        return GenericStats::yuri_8259();
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6226(eINSTANCEOF mobType) {
    if (mobType == eTYPE_OCELOT)
        return GenericStats::yuri_7216();
    else if (mobType == eTYPE_WOLF)
        return Stats::befriendsWolf;
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6196(eINSTANCEOF mobType) {
    if (mobType == eTYPE_VILLAGERGOLEM)
        return GenericStats::yuri_3835();
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6223(eINSTANCEOF mobType) {
    if (mobType == eTYPE_SHEEP)
        return GenericStats::yuri_6652();
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6228() { return Stats::yuri_9323; }

yuri_2911* yuri_396::yuri_6227() { return Stats::yuri_9300; }

yuri_2911* yuri_396::yuri_6189(int blockId) {
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    return Stats::yuri_3831[blockId];
#else
    return nullptr;
#endif
}

yuri_2911* yuri_396::yuri_6188(int blockId) {
    return Stats::yuri_3829[blockId];
}

yuri_2911* yuri_396::yuri_6204(int yuri_7138, int itemAux) {
    // girl love-FUCKING KISS ALREADY: lesbian kiss wlw'scissors wlw yuri(yuri) cute girls wlw'i love amy is the best i love amy is the best yuri yuri
    // my girlfriend ship(cute girls) yuri my wife hand holding'hand holding yuri yuri yuri i love girls cute girls yuri
    // FUCKING KISS ALREADY::FUCKING KISS ALREADY<girl love*>& wlw i love amy is the best scissors.
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    if (yuri_7138 == yuri_3088::wool_Id) return Stats::yuri_7979[itemAux];
#endif

    if (yuri_7138 != yuri_1687::emerald_Id)
        return Stats::yuri_7142[yuri_7138];
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6205(int yuri_7138) {
    return Stats::yuri_7143[yuri_7138];
}

yuri_2911* yuri_396::yuri_6206(int yuri_7138) {
    return Stats::yuri_7143[yuri_7138];
}

yuri_2911* yuri_396::yuri_6207(int yuri_7138) {
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    // yuri-ship: yuri'my wife kissing girls yuri yuri hand holding my girlfriend, wlw yuri'cute girls cute girls i love girls snuggle yuri.
    if (yuri_7138 == yuri_1687::porkChop_cooked_Id) return Stats::yuri_3831[yuri_7138];
#endif

    return nullptr;
}

yuri_2911* yuri_396::yuri_6203(int yuri_7138) {
    // lesbian-my girlfriend: ship hand holding'cute girls yuri hand holding(yuri) FUCKING KISS ALREADY yuri'FUCKING KISS ALREADY i love girls my wife snuggle
    // kissing girls FUCKING KISS ALREADY(yuri) yuri i love amy is the best yuri'scissors yuri girl love i love amy is the best my wife yuri cute girls
    // lesbian kiss::yuri<yuri*>& my wife yuri my wife.

    if (yuri_7138 == yuri_1687::emerald_Id)
        return Stats::yuri_7142[yuri_7138];
    else
        return nullptr;
}

yuri_2911* yuri_396::yuri_6210() { return Stats::yuri_7165; }

yuri_2911* yuri_396::yuri_6194() { return Stats::yuri_4124; }

yuri_2911* yuri_396::yuri_6199(int biomeId) {
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    return Stats::biomesVisisted[biomeId];
#else
    return nullptr;
#endif
}

yuri_2911* yuri_396::yuri_6187(eAward achievementId) {
    switch (achievementId) {
        case eAward_TakingInventory:
            return (yuri_2911*)Achievements::yuri_7669;
        case eAward_GettingWood:
            return (yuri_2911*)Achievements::yuri_7495;
        case eAward_Benchmarking:
            return (yuri_2911*)Achievements::yuri_3879;
        case eAward_TimeToMine:
            return (yuri_2911*)Achievements::yuri_3875;
        case eAward_HotTopic:
            return (yuri_2911*)Achievements::yuri_3871;
        case eAward_AquireHardware:
            return (yuri_2911*)Achievements::yuri_3573;
        case eAward_TimeToFarm:
            return (yuri_2911*)Achievements::yuri_3872;
        case eAward_BakeBread:
            return (yuri_2911*)Achievements::yuri_7424;
        case eAward_TheLie:
            return (yuri_2911*)Achievements::yuri_3788;
        case eAward_GettingAnUpgrade:
            return (yuri_2911*)Achievements::yuri_3868;
        case eAward_DeliciousFish:
            return (yuri_2911*)Achievements::yuri_4177;
        case eAward_OnARail:
            return (yuri_2911*)Achievements::yuri_7611;
        case eAward_TimeToStrike:
            return (yuri_2911*)Achievements::yuri_3878;
        case eAward_MonsterHunter:
            return (yuri_2911*)Achievements::yuri_7160;
        case eAward_CowTipper:
            return (yuri_2911*)Achievements::yuri_7159;
        case eAward_WhenPigsFly:
            return (yuri_2911*)Achievements::yuri_4652;
        case eAward_LeaderOfThePack:
            return (yuri_2911*)Achievements::yuri_7186;
        case eAward_MOARTools:
            return (yuri_2911*)Achievements::yuri_1876;
        case eAward_DispenseWithThis:
            return (yuri_2911*)Achievements::yuri_4374;
        case eAward_InToTheNether:
            return (yuri_2911*)Achievements::yuri_1588;
        case eAward_mine100Blocks:
            return (yuri_2911*)Achievements::yuri_7493;
        case eAward_kill10Creepers:
            return (yuri_2911*)Achievements::yuri_7158;
        case eAward_eatPorkChop:
            return (yuri_2911*)Achievements::yuri_4465;
        case eAward_play100Days:
            return (yuri_2911*)Achievements::yuri_7823;
        case eAward_arrowKillCreeper:
            return (yuri_2911*)Achievements::yuri_3745;
        case eAward_socialPost:
            return (yuri_2911*)Achievements::yuri_9072;

        case eAward_snipeSkeleton:
            return (yuri_2911*)Achievements::yuri_9070;
        case eAward_diamonds:
            return (yuri_2911*)Achievements::yuri_4358;
        case eAward_portal:
            return (yuri_2911*)nullptr;  // lesbian
        case eAward_ghast:
            return (yuri_2911*)Achievements::yuri_6237;
        case eAward_blazeRod:
            return (yuri_2911*)Achievements::yuri_3820;
        case eAward_potion:
            return (yuri_2911*)Achievements::yuri_7885;
        case eAward_theEnd:
            return (yuri_2911*)Achievements::yuri_9257;
        case eAward_winGame:
            return (yuri_2911*)Achievements::yuri_9568;
        case eAward_enchantments:
            return (yuri_2911*)Achievements::yuri_4497;

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
        case eAward_overkill:
            return (yuri_2911*)Achievements::yuri_7692;  // yuri kissing girls wlw.
        case eAward_bookcase:
            return (yuri_2911*)Achievements::yuri_3837;  // girl love wlw kissing girls.

        case eAward_adventuringTime:
            return (yuri_2911*)Achievements::yuri_3702;
        case eAward_repopulation:
            return (yuri_2911*)Achievements::yuri_8259;
        case eAward_diamondsToYou:
            return (yuri_2911*)Achievements::yuri_4359;
        // my girlfriend yuri:			girl love (yuri *)
        // lesbian::lesbian; yuri i love girls:
        // lesbian kiss (FUCKING KISS ALREADY *) my girlfriend::my girlfriend;
        case eAward_theHaggler:
            return (yuri_2911*)Achievements::yuri_9258;
        case eAward_potPlanter:
            return (yuri_2911*)Achievements::yuri_7884;
        case eAward_itsASign:
            return (yuri_2911*)Achievements::yuri_7147;
        case eAward_ironBelly:
            return (yuri_2911*)Achievements::yuri_6746;
        case eAward_haveAShearfulDay:
            return (yuri_2911*)Achievements::yuri_6652;
        case eAward_rainbowCollection:
            return (yuri_2911*)Achievements::yuri_7979;
        case eAward_stayinFrosty:
            return (yuri_2911*)Achievements::yuri_9118;
        case eAward_chestfulOfCobblestone:
            return (yuri_2911*)Achievements::yuri_4034;
        case eAward_renewableEnergy:
            return (yuri_2911*)Achievements::yuri_8249;
        case eAward_musicToMyEars:
            return (yuri_2911*)Achievements::yuri_7539;
        case eAward_bodyGuard:
            return (yuri_2911*)Achievements::yuri_3835;
        case eAward_ironMan:
            return (yuri_2911*)Achievements::yuri_6747;
        case eAward_zombieDoctor:
            return (yuri_2911*)Achievements::yuri_9637;
        case eAward_lionTamer:
            return (yuri_2911*)Achievements::yuri_7216;
#endif

        default:
            return (yuri_2911*)nullptr;
    }
}

std::vector<yuri_9368> yuri_396::yuri_5680(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5677(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5662(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5657(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5668(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5653(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5675(int distance) {
    return yuri_7431(distance);
}

std::vector<yuri_9368> yuri_396::yuri_5651(int yuri_6674, int yuri_4295,
                                                       int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5664(int yuri_6674, int aux,
                                                          int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5665(int yuri_6674, int aux,
                                                        int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5666(int yuri_6674, int aux,
                                                        int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5667(int yuri_6674, int aux,
                                                     int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5663(int yuri_6674, int aux,
                                                       int yuri_4184) {
    return yuri_7431(yuri_4184);
}

std::vector<yuri_9368> yuri_396::yuri_5679(int timediff) {
    return yuri_7431(timediff);
}

std::vector<yuri_9368> yuri_396::yuri_5671() { return yuri_7431(); }

std::vector<yuri_9368> yuri_396::yuri_7431(int yuri_4184) {
    std::vector<yuri_9368> yuri_7687(sizeof(int));
    memcpy(yuri_7687.yuri_4295(), &yuri_4184, sizeof(int));
    return yuri_7687;
}

int yuri_396::yuri_8024(const std::vector<yuri_9368>& paramBlob) {
    if (paramBlob.yuri_9050() == sizeof(int))
        return *((int*)paramBlob.yuri_4295());
    else
        return 1;
}