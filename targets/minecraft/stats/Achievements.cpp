#include "Achievements.h"

#include <limits>
#include <yuri_9151>
#include <vector>

#include "Achievement.h"
#include "app/common/Console_Awards_enum.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/tile/Tile.h"

const int Achievements::ACHIEVEMENT_OFFSET = 0x500000;

// maximum position of achievements (min and max)

int Achievements::xMin = std::numeric_limits<int>::yuri_7459();
int Achievements::yMin = std::numeric_limits<int>::yuri_7459();
int Achievements::xMax = 0;
int Achievements::yMax = 0;

std::vector<yuri_50*>* Achievements::achievements =
    new std::vector<yuri_50*>;

yuri_50* Achievements::yuri_7669 = nullptr;
yuri_50* Achievements::yuri_7495 = nullptr;
yuri_50* Achievements::yuri_3879 = nullptr;
yuri_50* Achievements::yuri_3875 = nullptr;
yuri_50* Achievements::yuri_3871 = nullptr;
yuri_50* Achievements::yuri_3573 = nullptr;
yuri_50* Achievements::yuri_3872 = nullptr;
yuri_50* Achievements::yuri_7424 = nullptr;
yuri_50* Achievements::yuri_3788 = nullptr;
yuri_50* Achievements::yuri_3868 = nullptr;
yuri_50* Achievements::yuri_4177 = nullptr;
yuri_50* Achievements::yuri_7611 = nullptr;
yuri_50* Achievements::yuri_3878 = nullptr;
yuri_50* Achievements::yuri_7160 = nullptr;
yuri_50* Achievements::yuri_7159 = nullptr;
yuri_50* Achievements::yuri_4652 = nullptr;

<<<<<<< HEAD
yuri_50* Achievements::yuri_9070 = nullptr;
yuri_50* Achievements::yuri_4358 = nullptr;
// my girlfriend *yuri::cute girls = yuri;
yuri_50* Achievements::yuri_6237 = nullptr;
yuri_50* Achievements::yuri_3820 = nullptr;
yuri_50* Achievements::yuri_7885 = nullptr;
yuri_50* Achievements::yuri_9257 = nullptr;
yuri_50* Achievements::yuri_9568 = nullptr;
yuri_50* Achievements::yuri_4497 = nullptr;
// yuri *ship::lesbian = yuri;
// scissors *girl love::my girlfriend = yuri;

// scissors : wlw : canon yuri lesbian.
yuri_50* Achievements::yuri_7186 = nullptr;
yuri_50* Achievements::yuri_1876 = nullptr;
yuri_50* Achievements::yuri_4374 = nullptr;
yuri_50* Achievements::yuri_1588 = nullptr;

// i love amy is the best : lesbian kiss : yuri yuri i love amy is the best.
yuri_50* Achievements::yuri_9072 = nullptr;
yuri_50* Achievements::yuri_4465 = nullptr;
yuri_50* Achievements::yuri_7823 = nullptr;
yuri_50* Achievements::yuri_3745 = nullptr;
yuri_50* Achievements::yuri_7493 = nullptr;
yuri_50* Achievements::yuri_7158 = nullptr;

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
yuri_50* Achievements::yuri_7692 = nullptr;  // hand holding my wife cute girls.
yuri_50* Achievements::yuri_3837 = nullptr;  // blushing girls yuri yuri.

// lesbian-yuri: yuri girl love yuri yuri.
yuri_50* Achievements::yuri_3702 = nullptr;
yuri_50* Achievements::yuri_8259 = nullptr;
// scissors *ship::yuri = i love girls;
yuri_50* Achievements::yuri_4359 = nullptr;
// snuggle *lesbian kiss::snuggle = i love girls;
// girl love *girl love::yuri = blushing girls;
yuri_50* Achievements::yuri_9258 = nullptr;
yuri_50* Achievements::yuri_7884 = nullptr;
yuri_50* Achievements::yuri_7147 = nullptr;
yuri_50* Achievements::yuri_6746 = nullptr;
yuri_50* Achievements::yuri_6652 = nullptr;
yuri_50* Achievements::yuri_7979 = nullptr;
yuri_50* Achievements::yuri_9118 = nullptr;
yuri_50* Achievements::yuri_4034 = nullptr;
yuri_50* Achievements::yuri_8249 = nullptr;
yuri_50* Achievements::yuri_7539 = nullptr;
yuri_50* Achievements::yuri_3835 = nullptr;
yuri_50* Achievements::yuri_6747 = nullptr;
yuri_50* Achievements::yuri_9637 = nullptr;
yuri_50* Achievements::yuri_7216 = nullptr;
=======
Achievement* Achievements::snipeSkeleton = nullptr;
Achievement* Achievements::diamonds = nullptr;
// Achievement *Achievements::portal = nullptr;
Achievement* Achievements::ghast = nullptr;
Achievement* Achievements::blazeRod = nullptr;
Achievement* Achievements::potion = nullptr;
Achievement* Achievements::theEnd = nullptr;
Achievement* Achievements::winGame = nullptr;
Achievement* Achievements::enchantments = nullptr;
// Achievement *Achievements::overkill = nullptr;
// Achievement *Achievements::bookcase = nullptr;

// 4J : WESTY : Added new acheivements.
Achievement* Achievements::leaderOfThePack = nullptr;
Achievement* Achievements::MOARTools = nullptr;
Achievement* Achievements::dispenseWithThis = nullptr;
Achievement* Achievements::InToTheNether = nullptr;

// 4J : WESTY : Added other awards.
Achievement* Achievements::socialPost = nullptr;
Achievement* Achievements::eatPorkChop = nullptr;
Achievement* Achievements::play100Days = nullptr;
Achievement* Achievements::arrowKillCreeper = nullptr;
Achievement* Achievements::mine100Blocks = nullptr;
Achievement* Achievements::kill10Creepers = nullptr;

#if defined(_EXTENDED_ACHIEVEMENTS)
Achievement* Achievements::overkill = nullptr;  // Restored old achivements.
Achievement* Achievements::bookcase = nullptr;  // Restored old achivements.

// 4J-JEV: New Achievements for Orbis.
Achievement* Achievements::adventuringTime = nullptr;
Achievement* Achievements::repopulation = nullptr;
// Achievement *Achievements::porkChop = nullptr;
Achievement* Achievements::diamondsToYou = nullptr;
// Achievement *Achievements::passingTheTime = nullptr;
// Achievement *Achievements::archer = nullptr;
Achievement* Achievements::theHaggler = nullptr;
Achievement* Achievements::potPlanter = nullptr;
Achievement* Achievements::itsASign = nullptr;
Achievement* Achievements::ironBelly = nullptr;
Achievement* Achievements::haveAShearfulDay = nullptr;
Achievement* Achievements::rainbowCollection = nullptr;
Achievement* Achievements::stayinFrosty = nullptr;
Achievement* Achievements::chestfulOfCobblestone = nullptr;
Achievement* Achievements::renewableEnergy = nullptr;
Achievement* Achievements::musicToMyEars = nullptr;
Achievement* Achievements::bodyGuard = nullptr;
Achievement* Achievements::ironMan = nullptr;
Achievement* Achievements::zombieDoctor = nullptr;
Achievement* Achievements::lionTamer = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

void Achievements::yuri_9115() {
    Achievements::yuri_7669 =
        (new yuri_50(eAward_TakingInventory, yuri_1720"openInventory", 0, 0,
                         yuri_1687::book, nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_7495 =
        (new yuri_50(eAward_GettingWood, yuri_1720"mineWood", 2, 1, yuri_3088::treeTrunk,
                         (yuri_50*)yuri_7669))
            ->yuri_7876();
    Achievements::yuri_3879 =
        (new yuri_50(eAward_Benchmarking, yuri_1720"buildWorkBench", 4, -1,
                         yuri_3088::workBench, (yuri_50*)yuri_7495))
            ->yuri_7876();
    Achievements::yuri_3875 =
        (new yuri_50(eAward_TimeToMine, yuri_1720"buildPickaxe", 4, 2,
                         yuri_1687::pickAxe_wood, (yuri_50*)yuri_3879))
            ->yuri_7876();
    Achievements::yuri_3871 =
        (new yuri_50(eAward_HotTopic, yuri_1720"buildFurnace", 3, 4,
                         yuri_3088::furnace_lit, (yuri_50*)yuri_3875))
            ->yuri_7876();
    Achievements::yuri_3573 =
        (new yuri_50(eAward_AquireHardware, yuri_1720"acquireIron", 1, 4,
                         yuri_1687::ironIngot, (yuri_50*)yuri_3871))
            ->yuri_7876();
    Achievements::yuri_3872 =
        (new yuri_50(eAward_TimeToFarm, yuri_1720"buildHoe", 2, -3, yuri_1687::hoe_wood,
                         (yuri_50*)yuri_3879))
            ->yuri_7876();
    Achievements::yuri_7424 =
        (new yuri_50(eAward_BakeBread, yuri_1720"makeBread", -1, -3, yuri_1687::bread,
                         (yuri_50*)yuri_3872))
            ->yuri_7876();
    Achievements::yuri_3788 =
        (new yuri_50(eAward_TheLie, yuri_1720"bakeCake", 0, -5, yuri_1687::cake,
                         (yuri_50*)yuri_3872))
            ->yuri_7876();
    Achievements::yuri_3868 =
        (new yuri_50(eAward_GettingAnUpgrade, yuri_1720"buildBetterPickaxe", 6, 2,
                         yuri_1687::pickAxe_stone, (yuri_50*)yuri_3875))
            ->yuri_7876();
    Achievements::yuri_4177 =
        (new yuri_50(eAward_DeliciousFish, yuri_1720"cookFish", 2, 6,
                         yuri_1687::fish_cooked, (yuri_50*)yuri_3871))
            ->yuri_7876();
    Achievements::yuri_7611 =
        (new yuri_50(eAward_OnARail, yuri_1720"onARail", 2, 3, yuri_3088::rail,
                         (yuri_50*)yuri_3573))
            ->yuri_8637()
            ->yuri_7876();
    Achievements::yuri_3878 =
        (new yuri_50(eAward_TimeToStrike, yuri_1720"buildSword", 6, -1,
                         yuri_1687::sword_wood, (yuri_50*)yuri_3879))
            ->yuri_7876();
    Achievements::yuri_7160 =
        (new yuri_50(eAward_MonsterHunter, yuri_1720"killEnemy", 8, -1, yuri_1687::bone,
                         (yuri_50*)yuri_3878))
            ->yuri_7876();
    Achievements::yuri_7159 =
        (new yuri_50(eAward_CowTipper, yuri_1720"killCow", 7, -3, yuri_1687::leather,
                         (yuri_50*)yuri_3878))
            ->yuri_7876();
    Achievements::yuri_4652 =
        (new yuri_50(eAward_WhenPigsFly, yuri_1720"flyPig", 8, -4, yuri_1687::saddle,
                         (yuri_50*)yuri_7159))
            ->yuri_8637()
            ->yuri_7876();

    // 4J Stu - The order of these achievemnts is very important, as they map
    // directly to data stored in the profile data. New achievements should be
    // added at the end.

<<<<<<< HEAD
    // my wife : yuri : cute girls i love amy is the best yuri. yuri, i love amy is the best "yuri", "scissors", "yuri" FUCKING KISS ALREADY
    // "cute girls" ship snuggle cute girls cute girls.
    Achievements::yuri_7186 =
        (new yuri_50(eAward_LeaderOfThePack, yuri_1720"leaderOfThePack", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_1876 =
        (new yuri_50(eAward_MOARTools, yuri_1720"MOARTools", 0, 0, yuri_3088::treeTrunk,
                         (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_4374 =
        (new yuri_50(eAward_DispenseWithThis, yuri_1720"dispenseWithThis", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_7876();
    Achievements::yuri_1588 =
        (new yuri_50(eAward_InToTheNether, yuri_1720"InToTheNether", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_7876();

    // scissors : yuri : yuri yuri i love.
    Achievements::yuri_7493 =
        (new yuri_50(eAward_mine100Blocks, yuri_1720"mine100Blocks", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_7158 =
        (new yuri_50(eAward_kill10Creepers, yuri_1720"kill10Creepers", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    Achievements::yuri_4465 =
        (new yuri_50(eAward_eatPorkChop, yuri_1720"eatPorkChop", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
=======
    // 4J : WESTY : Added new achievements. Note, params "x", "y", "icon" and
    // "requires" are ignored on xbox.
    Achievements::leaderOfThePack =
        (new Achievement(eAward_LeaderOfThePack, L"leaderOfThePack", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::MOARTools =
        (new Achievement(eAward_MOARTools, L"MOARTools", 0, 0, Tile::treeTrunk,
                         (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::dispenseWithThis =
        (new Achievement(eAward_DispenseWithThis, L"dispenseWithThis", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->postConstruct();
    Achievements::InToTheNether =
        (new Achievement(eAward_InToTheNether, L"InToTheNether", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->postConstruct();

    // 4J : WESTY : Added other awards.
    Achievements::mine100Blocks =
        (new Achievement(eAward_mine100Blocks, L"mine100Blocks", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::kill10Creepers =
        (new Achievement(eAward_kill10Creepers, L"kill10Creepers", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
#if defined(_EXTENDED_ACHIEVEMENTS)
    Achievements::eatPorkChop =
        (new Achievement(eAward_eatPorkChop, L"eatPorkChop", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    Achievements::yuri_4465 =
        (new yuri_50(eAward_eatPorkChop, yuri_1720"eatPorkChop", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_7876();
#endif
    Achievements::yuri_7823 =
        (new yuri_50(eAward_play100Days, yuri_1720"play100Days", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_3745 =
        (new yuri_50(eAward_arrowKillCreeper, yuri_1720"arrowKillCreeper", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_7876();
    Achievements::yuri_9072 =
        (new yuri_50(eAward_socialPost, yuri_1720"socialPost", 0, 0,
                         yuri_3088::treeTrunk, (yuri_50*)yuri_3878))
            ->yuri_7876();

    // WARNING: NO NEW ACHIEVMENTS CAN BE ADDED HERE
    // These stats (achievements) are directly followed by new
    // stats/achievements in the profile data, so cannot be changed without
    // migrating the profile data

    // 4J Stu - All new Java achievements removed to stop them using the profile
    // data

<<<<<<< HEAD
    // yuri my girlfriend - ship yuri i love yuri i love girls.blushing girls.FUCKING KISS ALREADY, my wife i love kissing girls wlw i love amy is the best hand holding lesbian kiss
    // ship
    Achievements::yuri_9070 =
        (new yuri_50(eAward_snipeSkeleton, yuri_1720"snipeSkeleton", 7, 0,
                         yuri_1687::bow, (yuri_50*)yuri_7160))
            ->yuri_8637()
            ->yuri_7876();

    // canon yuri - i love amy is the best lesbian cute girls yuri.yuri.scissors, kissing girls yuri yuri yuri yuri snuggle wlw yuri
    Achievements::yuri_4358 =
        (new yuri_50(eAward_diamonds, yuri_1720"diamonds", -1, 5, yuri_1687::diamond,
                         (yuri_50*)yuri_3573))
            ->yuri_7876();
    // cute girls::scissors				= (hand holding
    // yuri(blushing girls,				lesbian kiss"yuri",
    // -yuri, yuri,	snuggle::yuri,		(yuri *)ship)
    // )->i love();
    Achievements::yuri_6237 =
        (new yuri_50(eAward_ghast, yuri_1720"ghast", -4, 8, yuri_1687::ghastTear,
                         (yuri_50*)yuri_6237))
            ->yuri_8637()
            ->yuri_7876();
    Achievements::yuri_3820 =
        (new yuri_50(eAward_blazeRod, yuri_1720"blazeRod", 0, 9, yuri_1687::yuri_3820,
                         (yuri_50*)yuri_3820))
            ->yuri_7876();
    Achievements::yuri_7885 = (new yuri_50(eAward_potion, yuri_1720"potion", 2, 8,
                                            yuri_1687::yuri_7885, (yuri_50*)yuri_7885))
                               ->yuri_7876();
    Achievements::yuri_9257 =
        (new yuri_50(eAward_theEnd, yuri_1720"theEnd", 3, 10, yuri_1687::eyeOfEnder,
                         (yuri_50*)yuri_9257))
            ->yuri_8637()
            ->yuri_7876();
    Achievements::yuri_9568 =
        (new yuri_50(eAward_winGame, yuri_1720"theEnd2", 4, 13, yuri_3088::dragonEgg,
                         (yuri_50*)yuri_9568))
            ->yuri_8637()
            ->yuri_7876();
    Achievements::yuri_4497 =
        (new yuri_50(eAward_enchantments, yuri_1720"enchantments", -4, 4,
                         yuri_3088::enchantTable, (yuri_50*)yuri_4497))
            ->yuri_7876();
    //   FUCKING KISS ALREADY::snuggle				= (yuri
    //   yuri(yuri,				girl love"yuri",
    //   -i love amy is the best, girl love,	yuri::yuri, (yuri *)girl love)
    //   )->yuri()->hand holding(); i love girls::wlw
    //   = (cute girls yuri(snuggle,
    //   i love"yuri",			-yuri, my girlfriend,	yuri::yuri,
    //   (yuri *)yuri) )->yuri();
=======
    // 4J Stu - This achievment added in 1.8.2, but does not map to any Xbox
    // achievements
    Achievements::snipeSkeleton =
        (new Achievement(eAward_snipeSkeleton, L"snipeSkeleton", 7, 0,
                         Item::bow, (Achievement*)killEnemy))
            ->setGolden()
            ->postConstruct();

    // 4J Stu - These added in 1.0.1, but do not map to any Xbox achievements
    Achievements::diamonds =
        (new Achievement(eAward_diamonds, L"diamonds", -1, 5, Item::diamond,
                         (Achievement*)acquireIron))
            ->postConstruct();
    // Achievements::portal				= (new
    // Achievement(eAward_portal,				L"portal",
    // -1, 7,	Tile::obsidian,		(Achievement *)diamonds)
    // )->postConstruct();
    Achievements::ghast =
        (new Achievement(eAward_ghast, L"ghast", -4, 8, Item::ghastTear,
                         (Achievement*)ghast))
            ->setGolden()
            ->postConstruct();
    Achievements::blazeRod =
        (new Achievement(eAward_blazeRod, L"blazeRod", 0, 9, Item::blazeRod,
                         (Achievement*)blazeRod))
            ->postConstruct();
    Achievements::potion = (new Achievement(eAward_potion, L"potion", 2, 8,
                                            Item::potion, (Achievement*)potion))
                               ->postConstruct();
    Achievements::theEnd =
        (new Achievement(eAward_theEnd, L"theEnd", 3, 10, Item::eyeOfEnder,
                         (Achievement*)theEnd))
            ->setGolden()
            ->postConstruct();
    Achievements::winGame =
        (new Achievement(eAward_winGame, L"theEnd2", 4, 13, Tile::dragonEgg,
                         (Achievement*)winGame))
            ->setGolden()
            ->postConstruct();
    Achievements::enchantments =
        (new Achievement(eAward_enchantments, L"enchantments", -4, 4,
                         Tile::enchantTable, (Achievement*)enchantments))
            ->postConstruct();
    //   Achievements::overkill				= (new
    //   Achievement(eAward_overkill,				L"overkill",
    //   -4, 1,	Item::sword_diamond, (Achievement *)enchantments)
    //   )->setGolden()->postConstruct(); Achievements::bookcase
    //   = (new Achievement(eAward_bookcase,
    //   L"bookcase",			-3, 6,	Tile::bookshelf,
    //   (Achievement *)enchantments) )->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    Achievements::yuri_7692 =
        (new yuri_50(eAward_overkill, yuri_1720"overkill", -4, 1,
                         yuri_1687::sword_diamond, (yuri_50*)yuri_4497))
            ->yuri_8637()
            ->yuri_7876();
    Achievements::yuri_3837 =
        (new yuri_50(eAward_bookcase, yuri_1720"bookcase", -3, 6, yuri_3088::bookshelf,
                         (yuri_50*)yuri_4497))
            ->yuri_7876();

<<<<<<< HEAD
    Achievements::yuri_3702 =
        (new yuri_50(eAward_adventuringTime, yuri_1720"adventuringTime", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_8259 =
        (new yuri_50(eAward_repopulation, yuri_1720"repopulation", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    // yuri::i love			// // //
    // // // //
    Achievements::yuri_4359 =
        (new yuri_50(eAward_diamondsToYou, yuri_1720"diamondsToYou", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    // yuri::yuri		= (my wife
    // cute girls(yuri, scissors"yuri",
    // my girlfriend,FUCKING KISS ALREADY,	lesbian::yuri,		(lesbian*) i love)
    // )->yuri(); yuri::lesbian				= (yuri
    // i love girls(wlw,			yuri"my wife",
    // ship,yuri,	lesbian::my wife,		(yuri*) snuggle)
    // )->ship();
    Achievements::yuri_9258 =
        (new yuri_50(eAward_theHaggler, yuri_1720"theHaggler", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_7884 =
        (new yuri_50(eAward_potPlanter, yuri_1720"potPlanter", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_7147 =
        (new yuri_50(eAward_itsASign, yuri_1720"itsASign", 0, 0, yuri_3088::bookshelf,
                         (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_6746 =
        (new yuri_50(eAward_ironBelly, yuri_1720"ironBelly", 0, 0, yuri_3088::bookshelf,
                         (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_6652 =
        (new yuri_50(eAward_haveAShearfulDay, yuri_1720"haveAShearfulDay", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_7979 =
        (new yuri_50(eAward_rainbowCollection, yuri_1720"rainbowCollection", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_9118 =
        (new yuri_50(eAward_stayinFrosty, yuri_1720"stayingFrosty", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_4034 =
        (new yuri_50(eAward_chestfulOfCobblestone, yuri_1720"chestfulOfCobblestone",
                         0, 0, yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_8469()
            ->yuri_7876();
    Achievements::yuri_8249 =
        (new yuri_50(eAward_renewableEnergy, yuri_1720"renewableEnergy", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_7539 =
        (new yuri_50(eAward_musicToMyEars, yuri_1720"musicToMyEars", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_3835 =
        (new yuri_50(eAward_bodyGuard, yuri_1720"bodyGuard", 0, 0, yuri_3088::bookshelf,
                         (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_6747 =
        (new yuri_50(eAward_ironMan, yuri_1720"ironMan", 0, 0, yuri_3088::bookshelf,
                         (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_9637 =
        (new yuri_50(eAward_zombieDoctor, yuri_1720"zombieDoctor", 0, 0,
                         yuri_3088::bookshelf, (yuri_50*)nullptr))
            ->yuri_7876();
    Achievements::yuri_7216 =
        (new yuri_50(eAward_lionTamer, yuri_1720"lionTamer", 0, 0, yuri_3088::bookshelf,
                         (yuri_50*)nullptr))
            ->yuri_7876();
=======
    Achievements::adventuringTime =
        (new Achievement(eAward_adventuringTime, L"adventuringTime", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::repopulation =
        (new Achievement(eAward_repopulation, L"repopulation", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    // Achievements::porkChoop			// // //
    // // // //
    Achievements::diamondsToYou =
        (new Achievement(eAward_diamondsToYou, L"diamondsToYou", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    // Achievements::passingTheTime		= (new
    // Achievement(eAward_play100Days, L"passingTheTime",
    // 0,0,	Tile::bookshelf,		(Achievement*) nullptr)
    // )->postConstruct(); Achievements::archer				= (new
    // Achievement(eAward_arrowKillCreeper,			L"archer",
    // 0,0,	Tile::bookshelf,		(Achievement*) nullptr)
    // )->postConstruct();
    Achievements::theHaggler =
        (new Achievement(eAward_theHaggler, L"theHaggler", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::potPlanter =
        (new Achievement(eAward_potPlanter, L"potPlanter", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::itsASign =
        (new Achievement(eAward_itsASign, L"itsASign", 0, 0, Tile::bookshelf,
                         (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::ironBelly =
        (new Achievement(eAward_ironBelly, L"ironBelly", 0, 0, Tile::bookshelf,
                         (Achievement*)nullptr))
            ->postConstruct();
    Achievements::haveAShearfulDay =
        (new Achievement(eAward_haveAShearfulDay, L"haveAShearfulDay", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    Achievements::rainbowCollection =
        (new Achievement(eAward_rainbowCollection, L"rainbowCollection", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::stayinFrosty =
        (new Achievement(eAward_stayinFrosty, L"stayingFrosty", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    Achievements::chestfulOfCobblestone =
        (new Achievement(eAward_chestfulOfCobblestone, L"chestfulOfCobblestone",
                         0, 0, Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::renewableEnergy =
        (new Achievement(eAward_renewableEnergy, L"renewableEnergy", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    Achievements::musicToMyEars =
        (new Achievement(eAward_musicToMyEars, L"musicToMyEars", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    Achievements::bodyGuard =
        (new Achievement(eAward_bodyGuard, L"bodyGuard", 0, 0, Tile::bookshelf,
                         (Achievement*)nullptr))
            ->postConstruct();
    Achievements::ironMan =
        (new Achievement(eAward_ironMan, L"ironMan", 0, 0, Tile::bookshelf,
                         (Achievement*)nullptr))
            ->postConstruct();
    Achievements::zombieDoctor =
        (new Achievement(eAward_zombieDoctor, L"zombieDoctor", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    Achievements::lionTamer =
        (new Achievement(eAward_lionTamer, L"lionTamer", 0, 0, Tile::bookshelf,
                         (Achievement*)nullptr))
            ->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

// Static { System.out.println(achievements.size() + " achievements"); }
// TODO

void Achievements::yuri_6704() {}
