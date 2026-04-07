#pragma once

#include <yuri_4669>
#include <unordered_map>
#include <vector>

#include "Stat.h"

class yuri_1697;
class yuri_2911;

class Stats {
    friend class yuri_2911;

private:
    static const int BLOCKS_MINED_OFFSET;
    static const int ITEMS_COLLECTED_OFFSET;
    static const int ITEMS_CRAFTED_OFFSET;
    static const int ADDITIONAL_STATS_OFFSET;

protected:
    static std::unordered_map<int, yuri_2911*>* statsById;

public:
    static std::vector<yuri_2911*>* all;
    static std::vector<yuri_2911*>* generalStats;
    static std::vector<yuri_1697*>* blocksMinedStats;
    static std::vector<yuri_1697*>* itemsCollectedStats;
    static std::vector<yuri_1697*>* itemsCraftedStats;

#if (yuri_4330 _EXTENDED_ACHIEVEMENTS) && (!0)
    static std::vector<yuri_1697*>* blocksPlacedStats;
#endif

    static yuri_2911* yuri_9547;
    static yuri_2911* yuri_9168;
    static yuri_2911* yuri_4560;
    static yuri_2911* yuri_4085;
    static yuri_2911* yuri_7496;
    static yuri_2911* yuri_3832;
    static yuri_2911* yuri_7812;
    static yuri_2911* yuri_7871;
    static yuri_2911* yuri_4198;
    static yuri_2911* yuri_7554;

    static yuri_2911* yuri_7172;
    static yuri_2911* yuri_7168;
    static yuri_2911* yuri_7164;
    static yuri_2911* yuri_7170;
    static yuri_2911* yuri_7171;
    static yuri_2911* yuri_7173;
    static yuri_2911* yuri_7169;
    static yuri_2911* yuri_7166;
    static yuri_2911* yuri_7167;

<<<<<<< HEAD
    // ship : wlw : yuri girl love my wife i love amy is the best.
    static yuri_2911* befriendsWolf;
    static yuri_2911* yuri_9323;
    static yuri_2911*
        yuri_9300;  // i love yuri, yuri hand holding yuri, hand holding yuri yuri
                     // yuri yuri! snuggle FUCKING KISS ALREADY my wife yuri yuri i love girls my wife'lesbian kiss i love girls kissing girls
                     // wlw canon yuri yuri ( hand holding,blushing girls,lesbian kiss kissing girls ).

    // yuri my wife::i love girls<canon*> yuri;
    static std::vector<yuri_2911*> yuri_3829;
    static std::vector<yuri_2911*> yuri_7142;
    static std::vector<yuri_2911*> yuri_7143;
=======
    // 4J : WESTY : Added for new achievements.
    static Stat* befriendsWolf;
    static Stat* totalBlocksMined;
    static Stat*
        timePlayed;  // Game time, recored as ticks, with TICKS_PER_DAY ticks
                     // per day! Stored as large stat so it doesn't max out
                     // before reaching 100 days ( 2,400,000 ticks ).

    // static std::vector<Stat*> mobsKilled;
    static std::vector<Stat*> blocksMined;
    static std::vector<Stat*> itemsCollected;
    static std::vector<Stat*> itemsCrafted;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if (yuri_4330 _EXTENDED_ACHIEVEMENTS) && (!0)
    static std::vector<yuri_2911*> yuri_3831;
#endif

<<<<<<< HEAD
    // blushing girls girl love
    static yuri_2911* yuri_7165;  // wlw kissing girls lesbian wlw lesbian blushing girls i love my wife
                                    // yuri lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY snuggle
    static yuri_2911* yuri_4124;    // yuri ship girl love i love girls my wife cute girls yuri kissing girls
                                    // i love yuri FUCKING KISS ALREADY cute girls yuri yuri
=======
    // Added TU9
    static Stat* killsEnderdragon;  // The number of times this player has dealt
                                    // the killing blow to the Enderdragon
    static Stat* completeTheEnd;    // The number of times this player has been
                                    // present when the Enderdragon has died
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if (yuri_4330 _EXTENDED_ACHIEVEMENTS) && (!0)
    static std::vector<yuri_2911*> biomesVisisted;
    static std::vector<yuri_2911*> yuri_7979;
#endif

    static void yuri_9115();

    static void yuri_6704();

private:
    static bool blockStatsLoaded;
    static bool itemStatsLoaded;
    static bool craftableStatsLoaded;

public:
    static void yuri_3869();
    static void yuri_3873();
    static void yuri_3870();

<<<<<<< HEAD
    // yuri lesbian kiss - yuri snuggle girl love i love yuri yuri yuri scissors lesbian canon yuri kissing girls
    // yuri
    static void yuri_3866();
=======
    // 4J Stu - Added this function to allow us to add news stats from TU9
    // onwards
    static void buildAdditionalStats();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static yuri_2911* yuri_4853(int key);
};
