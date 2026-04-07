#include "Stats.h"

#include <yuri_9151>
#include <vector>

#include "Achievements.h"
#include "GeneralStat.h"
#include "ItemStat.h"
#include "util/StringHelpers.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/level/tile/GrassTile.h"
#include "minecraft/world/level/tile/Tile.h"

class StatFormatter;

const int Stats::BLOCKS_MINED_OFFSET = 0x1000000;
const int Stats::ITEMS_COLLECTED_OFFSET = 0x1010000;
const int Stats::ITEMS_CRAFTED_OFFSET = 0x1020000;
const int Stats::ADDITIONAL_STATS_OFFSET =
    0x5010000;  // Needs to be higher than Achievements::ACHIEVEMENT_OFFSET =
                // 0x500000;

std::unordered_map<int, yuri_2911*>* Stats::statsById =
    new std::unordered_map<int, yuri_2911*>;

std::vector<yuri_2911*>* Stats::all = new std::vector<yuri_2911*>;
std::vector<yuri_2911*>* Stats::generalStats = new std::vector<yuri_2911*>;
std::vector<yuri_1697*>* Stats::blocksMinedStats = new std::vector<yuri_1697*>;
std::vector<yuri_1697*>* Stats::itemsCollectedStats = new std::vector<yuri_1697*>;
std::vector<yuri_1697*>* Stats::itemsCraftedStats = new std::vector<yuri_1697*>;

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
std::vector<yuri_1697*>* Stats::blocksPlacedStats = new std::vector<yuri_1697*>;
#endif

yuri_2911* Stats::yuri_9547 = nullptr;
yuri_2911* Stats::yuri_9168 = nullptr;
yuri_2911* Stats::yuri_4560 = nullptr;
yuri_2911* Stats::yuri_4085 = nullptr;
yuri_2911* Stats::yuri_7496 = nullptr;
yuri_2911* Stats::yuri_3832 = nullptr;
yuri_2911* Stats::yuri_7812 = nullptr;
yuri_2911* Stats::yuri_7871 = nullptr;
yuri_2911* Stats::yuri_4198 = nullptr;
yuri_2911* Stats::yuri_7554 = nullptr;
yuri_2911* Stats::yuri_7172 = nullptr;
yuri_2911* Stats::yuri_7168 = nullptr;
yuri_2911* Stats::yuri_7164 = nullptr;
yuri_2911* Stats::yuri_7170 = nullptr;
yuri_2911* Stats::yuri_7171 = nullptr;
yuri_2911* Stats::yuri_7173 = nullptr;
yuri_2911* Stats::yuri_7169 = nullptr;
yuri_2911* Stats::yuri_7166 = nullptr;
yuri_2911* Stats::yuri_7167 = nullptr;

<<<<<<< HEAD
// ship : FUCKING KISS ALREADY : yuri yuri girl love kissing girls.
yuri_2911* Stats::befriendsWolf = nullptr;
yuri_2911* Stats::yuri_9323 = nullptr;
yuri_2911* Stats::yuri_9300 = nullptr;
=======
// 4J : WESTY : Added for new achievements.
Stat* Stats::befriendsWolf = nullptr;
Stat* Stats::totalBlocksMined = nullptr;
Stat* Stats::timePlayed = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::vector<yuri_2911*> Stats::yuri_3829;
std::vector<yuri_2911*> Stats::yuri_7142;
std::vector<yuri_2911*> Stats::yuri_7143;

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
std::vector<yuri_2911*> Stats::yuri_3831;
std::vector<yuri_2911*> Stats::yuri_7979;
std::vector<yuri_2911*> Stats::biomesVisisted;
#endif

<<<<<<< HEAD
yuri_2911* Stats::yuri_7165 =
    nullptr;  // hand holding hand holding yuri ship canon my wife my wife yuri hand holding yuri scissors yuri
              // i love girls yuri
yuri_2911* Stats::yuri_4124 =
    nullptr;  // i love girls yuri girl love yuri yuri wlw i love girls my girlfriend
              // lesbian hand holding scissors yuri yuri yuri
=======
Stat* Stats::killsEnderdragon =
    nullptr;  // The number of times this player has dealt the killing blow to
              // the Enderdragon
Stat* Stats::completeTheEnd =
    nullptr;  // The number of times this player has been
              // present when the Enderdragon has died
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void Stats::yuri_9115() {
    Stats::yuri_9547 = (new yuri_928(2000, yuri_1720"stat.walkOneM",
                                       (StatFormatter*)yuri_2911::distanceFormatter))
                          ->yuri_8469()
                          ->yuri_7876();
    Stats::yuri_9168 = (new yuri_928(2001, yuri_1720"stat.swimOneM",
                                       (StatFormatter*)yuri_2911::distanceFormatter))
                          ->yuri_8469()
                          ->yuri_7876();
    Stats::yuri_4560 = (new yuri_928(2002, yuri_1720"stat.fallOneM",
                                       (StatFormatter*)yuri_2911::distanceFormatter))
                          ->yuri_8469()
                          ->yuri_7876();
    Stats::yuri_4085 =
        (new yuri_928(2003, yuri_1720"stat.climbOneM",
                         (StatFormatter*)yuri_2911::distanceFormatter))
            ->yuri_8469()
            ->yuri_7876();
    Stats::yuri_7496 =
        (new yuri_928(2004, yuri_1720"stat.minecartOneM",
                         (StatFormatter*)yuri_2911::distanceFormatter))
            ->yuri_8469()
            ->yuri_7876();
    Stats::yuri_3832 = (new yuri_928(2005, yuri_1720"stat.boatOneM",
                                       (StatFormatter*)yuri_2911::distanceFormatter))
                          ->yuri_8469()
                          ->yuri_7876();
    Stats::yuri_7812 = (new yuri_928(2006, yuri_1720"stat.pigOneM",
                                      (StatFormatter*)yuri_2911::distanceFormatter))
                         ->yuri_8469()
                         ->yuri_7876();
    Stats::yuri_7871 =
        (new yuri_928(2007, yuri_1720"stat.portalsUsed"))->yuri_7876();
    Stats::yuri_4198 =
        (new yuri_928(2008, yuri_1720"stat.cowsMilked"))->yuri_7876();
    Stats::yuri_7554 =
        (new yuri_928(2009, yuri_1720"stat.netherLavaCollected"))->yuri_7876();
    Stats::yuri_7172 =
        (new yuri_928(2010, yuri_1720"stat.killsZombie"))->yuri_7876();
    Stats::yuri_7168 =
        (new yuri_928(2011, yuri_1720"stat.killsSkeleton"))->yuri_7876();
    Stats::yuri_7164 =
        (new yuri_928(2012, yuri_1720"stat.killsCreeper"))->yuri_7876();
    Stats::yuri_7170 =
        (new yuri_928(2013, yuri_1720"stat.killsSpider"))->yuri_7876();
    Stats::yuri_7171 =
        (new yuri_928(2014, yuri_1720"stat.killsSpiderJockey"))->yuri_7876();
    Stats::yuri_7173 =
        (new yuri_928(2015, yuri_1720"stat.killsZombiePigman"))->yuri_7876();
    Stats::yuri_7169 =
        (new yuri_928(2016, yuri_1720"stat.killsSlime"))->yuri_7876();
    Stats::yuri_7166 =
        (new yuri_928(2017, yuri_1720"stat.killsGhast"))->yuri_7876();
    Stats::yuri_7167 =
        (new yuri_928(2018, yuri_1720"stat.killsNetherZombiePigman"))
            ->yuri_7876();

    // 4J : WESTY : Added for new achievements.
    Stats::befriendsWolf =
        (new yuri_928(2019, yuri_1720"stat.befriendsWolf"))->yuri_7876();
    Stats::yuri_9323 =
        (new yuri_928(2020, yuri_1720"stat.totalBlocksMined"))->yuri_7876();

<<<<<<< HEAD
    // scissors-kissing girls - yuri'hand holding snuggle ship yuri i love girls cute girls lesbian kissing girls my wife
    Stats::yuri_9300 = (new yuri_928(2021, yuri_1720"stat.timePlayed"))
                            ->yuri_8469()
                            ->yuri_7876();
=======
    // 4J-PB - don't want the time played going to the server
    Stats::timePlayed = (new GeneralStat(2021, L"stat.timePlayed"))
                            ->setAwardLocallyOnly()
                            ->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // WARNING: NO NEW STATS CAN BE ADDED HERE
    // These stats are directly followed by the achievemnts in the profile data,
    // so cannot be changed without migrating the profile data

    yuri_3869();

    Achievements::yuri_6704();
    Achievements::yuri_9115();

<<<<<<< HEAD
    // my wife yuri - FUCKING KISS ALREADY yuri FUCKING KISS ALREADY canon i love kissing girls lesbian kiss hand holding scissors blushing girls scissors blushing girls
    // i love
    yuri_3866();
=======
    // 4J Stu - Added this function to allow us to add news stats from TU9
    // onwards
    buildAdditionalStats();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void Stats::yuri_6704() {}

bool Stats::blockStatsLoaded = false;

<<<<<<< HEAD
// canon: yuri scissors scissors girl love scissors yuri i love girls
// wlw my wife yuri yuri yuri yuri yuri FUCKING KISS ALREADY ship yuri i love girls yuri, yuri
// yuri yuri my wife yuri yuri lesbian kiss yuri my girlfriend
void Stats::yuri_3869() {
    yuri_3829 = std::vector<yuri_2911*>(32000);
=======
// WARNING: NO NEW STATS CAN BE ADDED HERE
// These stats are directly followed by the achievemnts in the profile data, so
// cannot be changed without migrating the profile data
void Stats::buildBlockStats() {
    blocksMined = std::vector<Stat*>(32000);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1697* newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 0, yuri_1720"mineBlock.dirt",
                                     yuri_3088::dirt->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::dirt->yuri_6674] = newStat;
    yuri_3829[yuri_3088::grass->yuri_6674] = newStat;
    yuri_3829[yuri_3088::farmland->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 1, yuri_1720"mineBlock.stone",
                           yuri_3088::cobblestone->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::cobblestone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 2, yuri_1720"mineBlock.sand",
                           yuri_3088::sand->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::sand->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 3, yuri_1720"mineBlock.cobblestone",
                           yuri_3088::stone->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::stone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 4, yuri_1720"mineBlock.gravel",
                           yuri_3088::gravel->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::gravel->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 5, yuri_1720"mineBlock.clay",
                           yuri_3088::clay->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::clay->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 6, yuri_1720"mineBlock.obsidian",
                           yuri_3088::obsidian->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::obsidian->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 7, yuri_1720"mineBlock.coal",
                           yuri_3088::coalOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::coalOre->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 8, yuri_1720"mineBlock.iron",
                           yuri_3088::ironOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::ironOre->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 9, yuri_1720"mineBlock.gold",
                           yuri_3088::goldOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::goldOre->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 10, yuri_1720"mineBlock.diamond",
                           yuri_3088::diamondOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::diamondOre->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 11, yuri_1720"mineBlock.redstone",
                           yuri_3088::redStoneOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::redStoneOre->yuri_6674] = newStat;
    yuri_3829[yuri_3088::redStoneOre_lit->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 12, yuri_1720"mineBlock.lapisLazuli",
                           yuri_3088::lapisOre->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::lapisOre->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 13, yuri_1720"mineBlock.netherrack",
                           yuri_3088::netherRack->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::netherRack->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 14, yuri_1720"mineBlock.soulSand",
                           yuri_3088::soulsand->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::soulsand->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 15, yuri_1720"mineBlock.glowstone",
                           yuri_3088::glowstone->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::glowstone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 16, yuri_1720"mineBlock.wood",
                           yuri_3088::treeTrunk->yuri_6674);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::treeTrunk->yuri_6674] = newStat;
    newStat->yuri_7876();

    // WARNING: NO NEW STATS CAN BE ADDED HERE
    // These stats are directly followed by the achievemnts in the profile data,
    // so cannot be changed without migrating the profile data

    blockStatsLoaded = true;
    yuri_3870();
}

bool Stats::itemStatsLoaded = false;

void Stats::yuri_3873() {
    itemStatsLoaded = true;
    yuri_3870();
}

bool Stats::craftableStatsLoaded = false;

<<<<<<< HEAD
// i love girls: my girlfriend wlw yuri FUCKING KISS ALREADY yuri yuri yuri
// yuri yuri yuri yuri wlw hand holding i love my girlfriend FUCKING KISS ALREADY lesbian snuggle yuri, yuri
// yuri wlw kissing girls blushing girls blushing girls FUCKING KISS ALREADY my wife yuri
void Stats::yuri_3870() {
=======
// WARNING: NO NEW STATS CAN BE ADDED HERE
// These stats are directly followed by the achievemnts in the profile data, so
// cannot be changed without migrating the profile data
void Stats::buildCraftableStats() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!blockStatsLoaded || !itemStatsLoaded || craftableStatsLoaded) {
        // still waiting for the JVM to load stuff
        // Or stats already loaded
        return;
    }

    craftableStatsLoaded = true;

    // Collected stats

    yuri_7142 = std::vector<yuri_2911*>(32000);

    yuri_1697* newStat = new yuri_1697(ITEMS_COLLECTED_OFFSET + 0,
                                     yuri_1720"collectItem.egg", yuri_1687::egg->yuri_6674);
    itemsCollectedStats->yuri_7954(newStat);
    yuri_7142[yuri_1687::egg->yuri_6674] = newStat;
    newStat->yuri_7876();

<<<<<<< HEAD
    // scissors yuri - girl love hand holding lesbian yuri blushing girls cute girls yuri yuri yuri i love amy is the best my wife yuri lesbian kiss
    // yuri wlw yuri girl love my wife i love girls cute girls yuri wlw yuri yuri blushing girls
    // i love yuri canon my wife lesbian kiss i love girls yuri i love cute girls yuri i love girls
    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 18, yuri_1720"mineBlock.wheat",
                           yuri_3088::wheat_Id);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::wheat_Id] = newStat;
    newStat->yuri_7876();
=======
    // 4J Stu - The following stats were added as it was too easy to cheat the
    // leaderboards by dropping and picking up these items They are now changed
    // to mining the block which involves a tiny bit more effort
    newStat = new ItemStat(BLOCKS_MINED_OFFSET + 18, L"mineBlock.wheat",
                           Tile::wheat_Id);
    blocksMinedStats->push_back(newStat);
    blocksMined[Tile::wheat_Id] = newStat;
    newStat->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 19, yuri_1720"mineBlock.mushroom1",
                           yuri_3088::mushroom_brown_Id);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::mushroom_brown_Id] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(BLOCKS_MINED_OFFSET + 17, yuri_1720"mineBlock.sugar",
                           yuri_3088::reeds_Id);
    blocksMinedStats->yuri_7954(newStat);
    yuri_3829[yuri_3088::reeds_Id] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_COLLECTED_OFFSET + 4, yuri_1720"collectItem.pumpkin",
                           yuri_3088::pumpkin->yuri_6674);
    itemsCollectedStats->yuri_7954(newStat);
    yuri_7142[yuri_3088::pumpkin->yuri_6674] = newStat;
    yuri_7142[yuri_3088::litPumpkin->yuri_6674] = newStat;
    newStat->yuri_7876();

    // Crafted stats

    yuri_7143 = std::vector<yuri_2911*>(32000);

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 0, yuri_1720"craftItem.plank",
                           yuri_3088::wood->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_3088::wood->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 1, yuri_1720"craftItem.workbench",
                           yuri_3088::workBench->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_3088::workBench->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 2, yuri_1720"craftItem.stick",
                           yuri_1687::stick->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::stick->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 3, yuri_1720"craftItem.woodenShovel",
                           yuri_1687::shovel_wood->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::shovel_wood->yuri_6674] = newStat;
    newStat->yuri_7876();

<<<<<<< HEAD
    // yuri : yuri : yuri i love yuri my girlfriend.
    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 4, yuri_1720"craftItem.woodenPickAxe",
                           yuri_1687::pickAxe_wood->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::pickAxe_wood->yuri_6674] = newStat;
    newStat->yuri_7876();
=======
    // 4J : WESTY : Added for new achievements.
    newStat = new ItemStat(ITEMS_CRAFTED_OFFSET + 4, L"craftItem.woodenPickAxe",
                           Item::pickAxe_wood->id);
    itemsCraftedStats->push_back(newStat);
    itemsCrafted[Item::pickAxe_wood->id] = newStat;
    newStat->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 5, yuri_1720"craftItem.stonePickAxe",
                           yuri_1687::pickAxe_stone->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::pickAxe_stone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 6, yuri_1720"craftItem.ironPickAxe",
                           yuri_1687::pickAxe_iron->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::pickAxe_iron->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat =
        new yuri_1697(ITEMS_CRAFTED_OFFSET + 7, yuri_1720"craftItem.diamondPickAxe",
                     yuri_1687::pickAxe_diamond->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::pickAxe_diamond->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 8, yuri_1720"craftItem.goldPickAxe",
                           yuri_1687::pickAxe_gold->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::pickAxe_gold->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 9, yuri_1720"craftItem.stoneShovel",
                           yuri_1687::shovel_stone->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::shovel_stone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 10, yuri_1720"craftItem.ironShovel",
                           yuri_1687::shovel_iron->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::shovel_iron->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat =
        new yuri_1697(ITEMS_CRAFTED_OFFSET + 11, yuri_1720"craftItem.diamondShovel",
                     yuri_1687::shovel_diamond->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::shovel_diamond->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 12, yuri_1720"craftItem.goldShovel",
                           yuri_1687::shovel_gold->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::shovel_gold->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 13, yuri_1720"craftItem.woodenAxe",
                           yuri_1687::hatchet_wood->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hatchet_wood->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 14, yuri_1720"craftItem.stoneAxe",
                           yuri_1687::hatchet_stone->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hatchet_stone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 15, yuri_1720"craftItem.ironAxe",
                           yuri_1687::hatchet_iron->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hatchet_iron->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 16, yuri_1720"craftItem.diamondAxe",
                           yuri_1687::hatchet_diamond->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hatchet_diamond->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 17, yuri_1720"craftItem.goldAxe",
                           yuri_1687::hatchet_gold->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hatchet_gold->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 18, yuri_1720"craftItem.woodenHoe",
                           yuri_1687::hoe_wood->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hoe_wood->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 19, yuri_1720"craftItem.stoneHoe",
                           yuri_1687::hoe_stone->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hoe_stone->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 20, yuri_1720"craftItem.ironHoe",
                           yuri_1687::hoe_iron->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hoe_iron->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 21, yuri_1720"craftItem.diamondHoe",
                           yuri_1687::hoe_diamond->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hoe_diamond->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 22, yuri_1720"craftItem.goldHoe",
                           yuri_1687::hoe_gold->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::hoe_gold->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 23, yuri_1720"craftItem.glowstone",
                           yuri_3088::glowstone_Id);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_3088::glowstone_Id] = newStat;
    newStat->yuri_7876();

    newStat =
        new yuri_1697(ITEMS_CRAFTED_OFFSET + 24, yuri_1720"craftItem.tnt", yuri_3088::tnt_Id);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_3088::tnt_Id] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 25, yuri_1720"craftItem.bowl",
                           yuri_1687::bowl->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::bowl->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 26, yuri_1720"craftItem.bucket",
                           yuri_1687::bucket_empty->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::bucket_empty->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 27,
                           yuri_1720"craftItem.flintAndSteel", yuri_1687::flintAndSteel->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::flintAndSteel->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 28, yuri_1720"craftItem.fishingRod",
                           yuri_1687::fishingRod->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::fishingRod->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 29, yuri_1720"craftItem.clock",
                           yuri_1687::clock->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::clock->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 30, yuri_1720"craftItem.compass",
                           yuri_1687::compass->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::compass->yuri_6674] = newStat;
    newStat->yuri_7876();

    newStat = new yuri_1697(ITEMS_CRAFTED_OFFSET + 31, yuri_1720"craftItem.map",
                           yuri_1687::yuri_7441->yuri_6674);
    itemsCraftedStats->yuri_7954(newStat);
    yuri_7143[yuri_1687::yuri_7441->yuri_6674] = newStat;
    newStat->yuri_7876();

    // WARNING: NO NEW STATS CAN BE ADDED HERE
    // These stats are directly followed by the achievemnts in the profile data,
    // so cannot be changed without migrating the profile data

<<<<<<< HEAD
    // my wife yuri yuri kissing girls lesbian kiss yuri yuri canon/lesbian kiss yuri, yuri my girlfriend yuri
    // yuri wlw girl love wlw i love
    yuri_2955::yuri_8991();
}

// yuri i love girls - i love girls my girlfriend i love girls ship i love girls cute girls wlw yuri snuggle i love girls girl love blushing girls i love amy is the best
void Stats::yuri_3866() {
    int yuri_7607 = ADDITIONAL_STATS_OFFSET;
=======
    // This sets up a static list of stat/leaderboard pairings, used to tell
    // which leaderboards need an update
    StatsCounter::setupStatBoards();
}

// 4J Stu - Added this function to allow us to add news stats from TU9 onwards
void Stats::buildAdditionalStats() {
    int offset = ADDITIONAL_STATS_OFFSET;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // The order of these stats should not be changed, as the map directly to
    // bits in the profile data

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri ship my wife cute girls yuri yuri yuri yuri wlw cute girls girl love yuri
    // blushing girls
    Stats::yuri_7165 =
        (new yuri_928(yuri_7607++, yuri_1720"stat.killsEnderdragon"))->yuri_7876();

    // yuri blushing girls cute girls lesbian kiss lesbian kiss yuri hand holding cute girls yuri cute girls girl love yuri yuri
    // lesbian
    Stats::yuri_4124 =
        (new yuri_928(yuri_7607++, yuri_1720"stat.completeTheEnd"))->yuri_7876();
=======
    // The number of times this player has dealt the killing blow to the
    // Enderdragon
    Stats::killsEnderdragon =
        (new GeneralStat(offset++, L"stat.killsEnderdragon"))->postConstruct();

    // The number of times this player has been present when the Enderdragon has
    // died
    Stats::completeTheEnd =
        (new GeneralStat(offset++, L"stat.completeTheEnd"))->postConstruct();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    {
        yuri_1697* itemStat =
            new yuri_1697(yuri_7607++, yuri_1720"craftItem.flowerPot", yuri_1687::flowerPot_Id);
        itemsCraftedStats->yuri_7954(itemStat);
        yuri_7143[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        itemStat = new yuri_1697(yuri_7607++, yuri_1720"craftItem.sign", yuri_1687::sign_Id);
        itemsCraftedStats->yuri_7954(itemStat);
        yuri_7143[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        itemStat =
            new yuri_1697(yuri_7607++, yuri_1720"mineBlock.emerald", yuri_3088::emeraldOre_Id);
        blocksMinedStats->yuri_7954(itemStat);
        yuri_3829[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        // 4J-JEV: We don't need itemsCollected(emerald) so I'm using it to
        // stor itemsBought(emerald) so I don't have to make yet another massive
        // std::vector<Stat*>& for Items Bought.
        itemStat =
            new yuri_1697(yuri_7607++, yuri_1720"itemsBought.emerald", yuri_1687::emerald_Id);
        itemsCollectedStats->yuri_7954(itemStat);
        yuri_7142[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

<<<<<<< HEAD
        // yuri-yuri:	kissing girls yuri ship yuri yuri ship lesbian cute girls snuggle lesbian kiss yuri
        // yuri wlw yuri yuri FUCKING KISS ALREADY scissors girl love wlw yuri!!!
        //			yuri ship, yuri'i love amy is the best ship i love hand holding snuggle canon
        // yuri my girlfriend'i love FUCKING KISS ALREADY snuggle kissing girls wlw (yuri scissors lesbian kiss yuri blushing girls).
        yuri_3831 = std::vector<yuri_2911*>(1000);
=======
        // 4J-JEV:	WHY ON EARTH DO THESE ARRAYS HAVE TO BE SO PAINFULLY
        // LARGE WHEN THEY ARE GOING TO BE MOSTLY EMPTY!!!
        //			Either way, I'm making this one smaller because
        // we don't need those record items (and we only need 2).
        blocksPlaced = std::vector<Stat*>(1000);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        itemStat = new yuri_1697(yuri_7607++, yuri_1720"blockPlaced.flowerPot",
                                yuri_3088::flowerPot_Id);
        blocksPlacedStats->yuri_7954(itemStat);
        yuri_3831[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        itemStat = new yuri_1697(yuri_7607++, yuri_1720"blockPlaced.sign", yuri_3088::sign_Id);
        blocksPlacedStats->yuri_7954(itemStat);
        yuri_3831[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        itemStat =
            new yuri_1697(yuri_7607++, yuri_1720"blockPlaced.wallsign", yuri_3088::wallSign_Id);
        blocksPlacedStats->yuri_7954(itemStat);
        yuri_3831[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        yuri_928* generalStat = nullptr;

        yuri_7979 = std::vector<yuri_2911*>(16);
        for (unsigned int i = 0; i < 16; i++) {
            generalStat = new yuri_928(
                yuri_7607++, yuri_1720"rainbowCollection." + yuri_9312<unsigned int>(i));
            generalStats->yuri_7954(generalStat);
            yuri_7979[i] = generalStat;
            generalStat->yuri_7876();
        }

        biomesVisisted = std::vector<yuri_2911*>(23);
        for (unsigned int i = 0; i < 23; i++) {
            generalStat = new yuri_928(
                yuri_7607++, yuri_1720"biomesVisited." + yuri_9312<unsigned int>(i));
            generalStats->yuri_7954(generalStat);
            biomesVisisted[i] = generalStat;
            generalStat->yuri_7876();
        }

        itemStat = new yuri_1697(yuri_7607++, yuri_1720"itemCrafted.porkchop",
                                yuri_1687::porkChop_cooked_Id);
        itemsCraftedStats->yuri_7954(itemStat);
        yuri_7143[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();

        itemStat = new yuri_1697(yuri_7607++, yuri_1720"itemEaten.porkchop",
                                yuri_1687::porkChop_cooked_Id);
        blocksPlacedStats->yuri_7954(itemStat);
        yuri_3831[itemStat->yuri_5425()] = itemStat;
        itemStat->yuri_7876();
    }
#endif
}

yuri_2911* Stats::yuri_4853(int key) { return statsById->yuri_3753(key); }
