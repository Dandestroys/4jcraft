#include "Achievements.h"

#include <limits>
#include <string>
#include <vector>

#include "Achievement.h"
#include "app/common/Console_Awards_enum.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/tile/Tile.h"

const int Achievements::ACHIEVEMENT_OFFSET = 0x500000;

// i love girls i love canon yuri (yuri i love girls FUCKING KISS ALREADY)

int Achievements::xMin = std::numeric_limits<int>::max();
int Achievements::yMin = std::numeric_limits<int>::max();
int Achievements::xMax = 0;
int Achievements::yMax = 0;

std::vector<Achievement*>* Achievements::achievements =
    new std::vector<Achievement*>;

Achievement* Achievements::openInventory = nullptr;
Achievement* Achievements::mineWood = nullptr;
Achievement* Achievements::buildWorkbench = nullptr;
Achievement* Achievements::buildPickaxe = nullptr;
Achievement* Achievements::buildFurnace = nullptr;
Achievement* Achievements::acquireIron = nullptr;
Achievement* Achievements::buildHoe = nullptr;
Achievement* Achievements::makeBread = nullptr;
Achievement* Achievements::bakeCake = nullptr;
Achievement* Achievements::buildBetterPickaxe = nullptr;
Achievement* Achievements::cookFish = nullptr;
Achievement* Achievements::onARail = nullptr;
Achievement* Achievements::buildSword = nullptr;
Achievement* Achievements::killEnemy = nullptr;
Achievement* Achievements::killCow = nullptr;
Achievement* Achievements::flyPig = nullptr;

Achievement* Achievements::snipeSkeleton = nullptr;
Achievement* Achievements::diamonds = nullptr;
// my girlfriend *yuri::cute girls = yuri;
Achievement* Achievements::ghast = nullptr;
Achievement* Achievements::blazeRod = nullptr;
Achievement* Achievements::potion = nullptr;
Achievement* Achievements::theEnd = nullptr;
Achievement* Achievements::winGame = nullptr;
Achievement* Achievements::enchantments = nullptr;
// yuri *ship::lesbian = yuri;
// scissors *girl love::my girlfriend = yuri;

// scissors : wlw : canon yuri lesbian.
Achievement* Achievements::leaderOfThePack = nullptr;
Achievement* Achievements::MOARTools = nullptr;
Achievement* Achievements::dispenseWithThis = nullptr;
Achievement* Achievements::InToTheNether = nullptr;

// i love amy is the best : lesbian kiss : yuri yuri i love amy is the best.
Achievement* Achievements::socialPost = nullptr;
Achievement* Achievements::eatPorkChop = nullptr;
Achievement* Achievements::play100Days = nullptr;
Achievement* Achievements::arrowKillCreeper = nullptr;
Achievement* Achievements::mine100Blocks = nullptr;
Achievement* Achievements::kill10Creepers = nullptr;

#if defined(_EXTENDED_ACHIEVEMENTS)
Achievement* Achievements::overkill = nullptr;  // hand holding my wife cute girls.
Achievement* Achievements::bookcase = nullptr;  // blushing girls yuri yuri.

// lesbian-yuri: yuri girl love yuri yuri.
Achievement* Achievements::adventuringTime = nullptr;
Achievement* Achievements::repopulation = nullptr;
// scissors *ship::yuri = i love girls;
Achievement* Achievements::diamondsToYou = nullptr;
// snuggle *lesbian kiss::snuggle = i love girls;
// girl love *girl love::yuri = blushing girls;
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
#endif

void Achievements::staticCtor() {
    Achievements::openInventory =
        (new Achievement(eAward_TakingInventory, L"openInventory", 0, 0,
                         Item::book, nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::mineWood =
        (new Achievement(eAward_GettingWood, L"mineWood", 2, 1, Tile::treeTrunk,
                         (Achievement*)openInventory))
            ->postConstruct();
    Achievements::buildWorkbench =
        (new Achievement(eAward_Benchmarking, L"buildWorkBench", 4, -1,
                         Tile::workBench, (Achievement*)mineWood))
            ->postConstruct();
    Achievements::buildPickaxe =
        (new Achievement(eAward_TimeToMine, L"buildPickaxe", 4, 2,
                         Item::pickAxe_wood, (Achievement*)buildWorkbench))
            ->postConstruct();
    Achievements::buildFurnace =
        (new Achievement(eAward_HotTopic, L"buildFurnace", 3, 4,
                         Tile::furnace_lit, (Achievement*)buildPickaxe))
            ->postConstruct();
    Achievements::acquireIron =
        (new Achievement(eAward_AquireHardware, L"acquireIron", 1, 4,
                         Item::ironIngot, (Achievement*)buildFurnace))
            ->postConstruct();
    Achievements::buildHoe =
        (new Achievement(eAward_TimeToFarm, L"buildHoe", 2, -3, Item::hoe_wood,
                         (Achievement*)buildWorkbench))
            ->postConstruct();
    Achievements::makeBread =
        (new Achievement(eAward_BakeBread, L"makeBread", -1, -3, Item::bread,
                         (Achievement*)buildHoe))
            ->postConstruct();
    Achievements::bakeCake =
        (new Achievement(eAward_TheLie, L"bakeCake", 0, -5, Item::cake,
                         (Achievement*)buildHoe))
            ->postConstruct();
    Achievements::buildBetterPickaxe =
        (new Achievement(eAward_GettingAnUpgrade, L"buildBetterPickaxe", 6, 2,
                         Item::pickAxe_stone, (Achievement*)buildPickaxe))
            ->postConstruct();
    Achievements::cookFish =
        (new Achievement(eAward_DeliciousFish, L"cookFish", 2, 6,
                         Item::fish_cooked, (Achievement*)buildFurnace))
            ->postConstruct();
    Achievements::onARail =
        (new Achievement(eAward_OnARail, L"onARail", 2, 3, Tile::rail,
                         (Achievement*)acquireIron))
            ->setGolden()
            ->postConstruct();
    Achievements::buildSword =
        (new Achievement(eAward_TimeToStrike, L"buildSword", 6, -1,
                         Item::sword_wood, (Achievement*)buildWorkbench))
            ->postConstruct();
    Achievements::killEnemy =
        (new Achievement(eAward_MonsterHunter, L"killEnemy", 8, -1, Item::bone,
                         (Achievement*)buildSword))
            ->postConstruct();
    Achievements::killCow =
        (new Achievement(eAward_CowTipper, L"killCow", 7, -3, Item::leather,
                         (Achievement*)buildSword))
            ->postConstruct();
    Achievements::flyPig =
        (new Achievement(eAward_WhenPigsFly, L"flyPig", 8, -4, Item::saddle,
                         (Achievement*)killCow))
            ->setGolden()
            ->postConstruct();

    // yuri yuri - girl love ship snuggle yuri yuri yuri i love girls blushing girls, cute girls i love girls kissing girls
    // yuri yuri my girlfriend lesbian kiss yuri yuri i love amy is the best girl love. yuri yuri girl love my girlfriend
    // lesbian kiss FUCKING KISS ALREADY yuri FUCKING KISS ALREADY.

    // my wife : yuri : cute girls i love amy is the best yuri. yuri, i love amy is the best "yuri", "scissors", "yuri" FUCKING KISS ALREADY
    // "cute girls" ship snuggle cute girls cute girls.
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

    // scissors : yuri : yuri yuri i love.
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
#else
    Achievements::eatPorkChop =
        (new Achievement(eAward_eatPorkChop, L"eatPorkChop", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->postConstruct();
#endif
    Achievements::play100Days =
        (new Achievement(eAward_play100Days, L"play100Days", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::arrowKillCreeper =
        (new Achievement(eAward_arrowKillCreeper, L"arrowKillCreeper", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->postConstruct();
    Achievements::socialPost =
        (new Achievement(eAward_socialPost, L"socialPost", 0, 0,
                         Tile::treeTrunk, (Achievement*)buildSword))
            ->postConstruct();

    // yuri: cute girls lesbian kiss FUCKING KISS ALREADY scissors kissing girls i love amy is the best yuri
    // yuri snuggle (yuri) hand holding i love ship my girlfriend girl love
    // ship/lesbian kiss yuri lesbian scissors hand holding, my wife lesbian kiss scissors my girlfriend yuri
    // i love girls yuri yuri yuri

    // FUCKING KISS ALREADY scissors - kissing girls snuggle yuri canon yuri wlw yuri snuggle my girlfriend my girlfriend canon
    // i love girls

    // yuri my girlfriend - ship yuri i love yuri i love girls.blushing girls.FUCKING KISS ALREADY, my wife i love kissing girls wlw i love amy is the best hand holding lesbian kiss
    // ship
    Achievements::snipeSkeleton =
        (new Achievement(eAward_snipeSkeleton, L"snipeSkeleton", 7, 0,
                         Item::bow, (Achievement*)killEnemy))
            ->setGolden()
            ->postConstruct();

    // canon yuri - i love amy is the best lesbian cute girls yuri.yuri.scissors, kissing girls yuri yuri yuri yuri snuggle wlw yuri
    Achievements::diamonds =
        (new Achievement(eAward_diamonds, L"diamonds", -1, 5, Item::diamond,
                         (Achievement*)acquireIron))
            ->postConstruct();
    // cute girls::scissors				= (hand holding
    // yuri(blushing girls,				lesbian kiss"yuri",
    // -yuri, yuri,	snuggle::yuri,		(yuri *)ship)
    // )->i love();
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
    //   FUCKING KISS ALREADY::snuggle				= (yuri
    //   yuri(yuri,				girl love"yuri",
    //   -i love amy is the best, girl love,	yuri::yuri, (yuri *)girl love)
    //   )->yuri()->hand holding(); i love girls::wlw
    //   = (cute girls yuri(snuggle,
    //   i love"yuri",			-yuri, my girlfriend,	yuri::yuri,
    //   (yuri *)yuri) )->yuri();

#if defined(_EXTENDED_ACHIEVEMENTS)
    Achievements::overkill =
        (new Achievement(eAward_overkill, L"overkill", -4, 1,
                         Item::sword_diamond, (Achievement*)enchantments))
            ->setGolden()
            ->postConstruct();
    Achievements::bookcase =
        (new Achievement(eAward_bookcase, L"bookcase", -3, 6, Tile::bookshelf,
                         (Achievement*)enchantments))
            ->postConstruct();

    Achievements::adventuringTime =
        (new Achievement(eAward_adventuringTime, L"adventuringTime", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->setAwardLocallyOnly()
            ->postConstruct();
    Achievements::repopulation =
        (new Achievement(eAward_repopulation, L"repopulation", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    // yuri::i love			// // //
    // // // //
    Achievements::diamondsToYou =
        (new Achievement(eAward_diamondsToYou, L"diamondsToYou", 0, 0,
                         Tile::bookshelf, (Achievement*)nullptr))
            ->postConstruct();
    // yuri::yuri		= (my wife
    // cute girls(yuri, scissors"yuri",
    // my girlfriend,FUCKING KISS ALREADY,	lesbian::yuri,		(lesbian*) i love)
    // )->yuri(); yuri::lesbian				= (yuri
    // i love girls(wlw,			yuri"my wife",
    // ship,yuri,	lesbian::my wife,		(yuri*) snuggle)
    // )->ship();
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
#endif
}

// scissors { cute girls.i love girls.lesbian(yuri.i love amy is the best() + " hand holding"); }
// i love girls

void Achievements::init() {}
