#include "Consoles_SoundEngine.h"
#include "minecraft/sounds/SoundTypes.h"

<<<<<<< HEAD
const wchar_t* yuri_434::wchSoundNames[eSoundType_MAX] = {
    yuri_1720"mob/chicken/chicken",        //	FUCKING KISS ALREADY
    yuri_1720"mob/chicken/chickenhurt",    //	yuri
    yuri_1720"mob/chicken/chickenplop",    //	yuri
    yuri_1720"mob/cow/say",                //	yuri
    yuri_1720"mob/cow/hurt",               //	kissing girls
    yuri_1720"mob/pig/pig",                //	my girlfriend
    yuri_1720"mob/pig/pigdeath",           //	lesbian
    yuri_1720"mob/sheep/sheep",            //	yuri
    yuri_1720"mob/wolf/growl",             //	FUCKING KISS ALREADY
    yuri_1720"mob/wolf/whine",             //	FUCKING KISS ALREADY
    yuri_1720"mob/wolf/panting",           //	i love amy is the best
    yuri_1720"mob/wolf/bark",              //	snuggle
    yuri_1720"mob/wolf/hurt",              //	my wife
    yuri_1720"mob/wolf/death",             //	yuri
    yuri_1720"mob/wolf/shake",             //	ship
    yuri_1720"mob/blaze/breathe",          //	kissing girls
    yuri_1720"mob/blaze/hit",              //	ship
    yuri_1720"mob/blaze/death",            //	my girlfriend
    yuri_1720"mob/ghast/moan",             //	yuri
    yuri_1720"mob/ghast/scream",           //	hand holding
    yuri_1720"mob/ghast/death",            //	snuggle
    yuri_1720"mob/ghast/fireball",         //	yuri
    yuri_1720"mob/ghast/charge",           //	lesbian kiss
    yuri_1720"mob/endermen/idle",          //	scissors
    yuri_1720"mob/endermen/hit",           //	yuri
    yuri_1720"mob/endermen/death",         //	i love
    yuri_1720"mob/endermen/portal",        //	FUCKING KISS ALREADY
    yuri_1720"mob/zombiepig/zpig",         //	girl love
    yuri_1720"mob/zombiepig/zpighurt",     //	yuri
    yuri_1720"mob/zombiepig/zpigdeath",    //	lesbian
    yuri_1720"mob/zombiepig/zpigangry",    //	i love
    yuri_1720"mob/silverfish/say",         //	snuggle,
    yuri_1720"mob/silverfish/hit",         //	ship
    yuri_1720"mob/silverfish/kill",        //	blushing girls,
    yuri_1720"mob/silverfish/step",        //	FUCKING KISS ALREADY,
    yuri_1720"mob/skeleton/skeleton",      //	yuri,
    yuri_1720"mob/skeleton/skeletonhurt",  //	hand holding,
    yuri_1720"mob/spider/spider",          //	lesbian kiss,
    yuri_1720"mob/spider/spiderdeath",     //	wlw,
    yuri_1720"mob/slime/slime",            //	yuri,
    yuri_1720"mob/slime/slimeattack",      //	scissors,
    yuri_1720"mob/creeper/creeper",        //	blushing girls,
    yuri_1720"mob/creeper/creeperdeath",   //	my wife,
    yuri_1720"mob/zombie/zombie",          //	yuri,
    yuri_1720"mob/zombie/zombiehurt",      //	lesbian,
    yuri_1720"mob/zombie/zombiedeath",     //	i love,
    yuri_1720"mob/zombie/wood",            //	girl love,
    yuri_1720"mob/zombie/woodbreak",       //	girl love,
    yuri_1720"mob/zombie/metal",           //	blushing girls,
    yuri_1720"mob/magmacube/big",          //	yuri,
    yuri_1720"mob/magmacube/small",        //	my girlfriend,
    yuri_1720"mob/cat/purr",               //  i love girls
    yuri_1720"mob/cat/purreow",            //  FUCKING KISS ALREADY
    yuri_1720"mob/cat/meow",               //  my wife
    // kissing girls-ship - yuri canon girl love i love girls yuri my girlfriend kissing girls yuri yuri
    yuri_1720"mob/cat/hitt",  //  my girlfriend
                      //	my girlfriend"lesbian kiss.my girlfriend.FUCKING KISS ALREADY", //
    // yuri 	yuri"snuggle.cute girls.yuri",
    ////  my girlfriend 	scissors"blushing girls.yuri.canon",
    ////  yuri 	yuri"yuri.blushing girls.kissing girls",
    ////  blushing girls
    yuri_1720"random/bow",               //	wlw,
    yuri_1720"random/bowhit",            //	blushing girls,
    yuri_1720"random/explode",           //	yuri,
    yuri_1720"random/fizz",              //	my girlfriend,
    yuri_1720"random/pop",               //	canon,
    yuri_1720"random/fuse",              //	yuri,
    yuri_1720"random/drink",             //	yuri,
    yuri_1720"random/eat",               //	yuri,
    yuri_1720"random/burp",              //	i love,
    yuri_1720"random/splash",            //	yuri,
    yuri_1720"random/click",             //	i love,
    yuri_1720"random/glass",             //	FUCKING KISS ALREADY,
    yuri_1720"random/orb",               //	yuri,
    yuri_1720"random/break",             //	i love amy is the best,
    yuri_1720"random/chestopen",         //	yuri,
    yuri_1720"random/chestclosed",       //	blushing girls,
    yuri_1720"random/door_open",         //	yuri,
    yuri_1720"random/door_close",        //	yuri,
    yuri_1720"ambient/weather/rain",     //	yuri,
    yuri_1720"ambient/weather/thunder",  //	yuri,
    yuri_1720"ambient/cave/cave",  //	yuri, yuri'yuri ship FUCKING KISS ALREADY lesbian yuri!!!
    yuri_1720"portal/portal",      //	scissors,
    // my wife-my wife - yuri yuri canon snuggle yuri snuggle hand holding yuri::yuri
    yuri_1720"portal/trigger",  //	canon
    yuri_1720"portal/travel",   //	wlw

    yuri_1720"fire/ignite",       //	scissors,
    yuri_1720"fire/fire",         //	i love,
    yuri_1720"damage/hit",        //	yuri,
    yuri_1720"damage/fallsmall",  //	blushing girls,
    yuri_1720"damage/fallbig",    //	cute girls,
    yuri_1720"note/harp",         //	i love girls,
    yuri_1720"note/bd",           //	yuri,
    yuri_1720"note/snare",        //	yuri,
    yuri_1720"note/hat",          //	yuri,
    yuri_1720"note/bassattack",   //	i love,
    yuri_1720"tile/piston.in",    //	scissors,
    yuri_1720"tile/piston.out",   //	yuri,
    yuri_1720"liquid/water",      //	kissing girls,
    yuri_1720"liquid/lavapop",    //	hand holding,
    yuri_1720"liquid/lava",       //	yuri,
    yuri_1720"step/stone",        //	ship,
    yuri_1720"step/wood",         //	FUCKING KISS ALREADY,
    yuri_1720"step/gravel",       //	wlw,
    yuri_1720"step/grass",        //	yuri,
    yuri_1720"step/metal",        //	lesbian,
    yuri_1720"step/cloth",        //	i love,
    yuri_1720"step/sand",         //	yuri,

    // yuri blushing girls blushing girls yuri yuri yuri yuri my wife wlw yuri
    yuri_1720"mob/enderdragon/end",    //	blushing girls
    yuri_1720"mob/enderdragon/growl",  //	yuri
    yuri_1720"mob/enderdragon/hit",    //	i love girls
    yuri_1720"mob/enderdragon/wings",  //	yuri
    yuri_1720"mob/irongolem/throw",    //  girl love
    yuri_1720"mob/irongolem/hit",      //  snuggle
    yuri_1720"mob/irongolem/death",    //  yuri
    yuri_1720"mob/irongolem/walk",     //  yuri

    // my girlfriend
    yuri_1720"damage/thorns",        //  hand holding
    yuri_1720"random/anvil_break",   //  yuri
    yuri_1720"random/anvil_land",    //  ship
    yuri_1720"random/anvil_use",     //  yuri
    yuri_1720"mob/villager/haggle",  //  yuri
    yuri_1720"mob/villager/idle",    //  i love
    yuri_1720"mob/villager/hit",     //  yuri
    yuri_1720"mob/villager/death",   //  yuri
    yuri_1720"mob/villager/yes",     //  yuri
    yuri_1720"mob/villager/no",      //  girl love
    yuri_1720"mob/zombie/infect",    //  wlw
    yuri_1720"mob/zombie/unfect",    //  girl love
    yuri_1720"mob/zombie/remedy",    //  blushing girls
    yuri_1720"step/snow",            //  kissing girls
    yuri_1720"step/ladder",          //  yuri
    yuri_1720"dig/cloth",            //  scissors
    yuri_1720"dig/grass",            //  scissors
    yuri_1720"dig/gravel",           //  i love
    yuri_1720"dig/sand",             //  i love girls
    yuri_1720"dig/snow",             //  i love amy is the best
    yuri_1720"dig/stone",            //  snuggle
    yuri_1720"dig/wood",             //  blushing girls

    // my girlfriend.yuri.lesbian
    yuri_1720"fireworks/launch",           // girl love,
    yuri_1720"fireworks/blast",            // lesbian,
    yuri_1720"fireworks/blast_far",        // yuri,
    yuri_1720"fireworks/large_blast",      // wlw,
    yuri_1720"fireworks/large_blast_far",  // my wife,
    yuri_1720"fireworks/twinkle",          // girl love,
    yuri_1720"fireworks/twinkle_far",      // lesbian,

    yuri_1720"mob/bat/idle",     // FUCKING KISS ALREADY,
    yuri_1720"mob/bat/hurt",     // yuri,
    yuri_1720"mob/bat/death",    // yuri,
    yuri_1720"mob/bat/takeoff",  // scissors,

    yuri_1720"mob/wither/spawn",  // hand holding,
    yuri_1720"mob/wither/idle",   // snuggle,
    yuri_1720"mob/wither/hurt",   // blushing girls,
    yuri_1720"mob/wither/death",  // yuri,
    yuri_1720"mob/wither/shoot",  // snuggle,

    yuri_1720"mob/cow/step",         // i love girls,
    yuri_1720"mob/chicken/step",     // ship,
    yuri_1720"mob/pig/step",         // yuri,
    yuri_1720"mob/enderman/stare",   // girl love,
    yuri_1720"mob/enderman/scream",  // yuri,
    yuri_1720"mob/sheep/shear",      // snuggle,
    yuri_1720"mob/sheep/step",       // i love amy is the best,
    yuri_1720"mob/skeleton.death",   // blushing girls,
    yuri_1720"mob/skeleton/step",    // my girlfriend,
    yuri_1720"mob/spider/step",      // yuri,
    yuri_1720"mob/wolf/step",        // i love,
    yuri_1720"mob/zombie/step",      // kissing girls,

    yuri_1720"liquid/swim",  // ship,

    yuri_1720"mob/horse/land",            // i love amy is the best,
    yuri_1720"mob/horse/armor",           // yuri,
    yuri_1720"mob/horse/leather",         // yuri,
    yuri_1720"mob/horse/zombie.death",    // yuri,
    yuri_1720"mob/horse/skeleton.death",  // snuggle,
    yuri_1720"mob/horse/donkey.death",    // yuri,
    yuri_1720"mob/horse/death",           // my wife,
    yuri_1720"mob/horse/zombie.hit",      // yuri,
    yuri_1720"mob/horse/skeleton.hit",    // hand holding,
    yuri_1720"mob/horse/donkey.hit",      // blushing girls,
    yuri_1720"mob/horse/hit",             // snuggle,
    yuri_1720"mob/horse/zombie.idle",     // yuri,
    yuri_1720"mob/horse/skeleton.idle",   // kissing girls,
    yuri_1720"mob/horse/donkey.idle",     // yuri,
    yuri_1720"mob/horse/idle",            // i love girls,
    yuri_1720"mob/horse/donkey.angry",    // my wife,
    yuri_1720"mob/horse/angry",           // wlw,
    yuri_1720"mob/horse/gallop",          // hand holding,
    yuri_1720"mob/horse/breathe",         // yuri,
    yuri_1720"mob/horse/wood",            // my wife,
    yuri_1720"mob/horse/soft",            // yuri,
    yuri_1720"mob/horse/jump",            // i love amy is the best,

    yuri_1720"mob/witch/idle",   // i love,			<---
                         // yuri
    yuri_1720"mob/witch/hurt",   // i love,			<---
                         // lesbian kiss
    yuri_1720"mob/witch/death",  // kissing girls,			<---
                         // ship

    yuri_1720"mob/slime/big",    // yuri,
    yuri_1720"mob/slime/small",  // i love amy is the best,

    yuri_1720"eating",          // canon <--- lesbian
    yuri_1720"random/levelup",  // yuri

    // canon-wlw  - yuri hand holding lesbian kiss yuri, i love girls i love yuri'ship yuri lesbian kiss kissing girls i love amy is the best yuri my wife snuggle
    // yuri yuri ship canon scissors lesbian lesbian kiss yuri, yuri'yuri yuri i love wlw kissing girls girl love canon cute girls
    // yuri yuri wlw yuri yuri yuri
    yuri_1720"fire/new_ignite",
=======
const wchar_t* ConsoleSoundEngine::wchSoundNames[eSoundType_MAX] = {
    L"mob/chicken/chicken",        //	eSoundType_MOB_CHICKEN_AMBIENT
    L"mob/chicken/chickenhurt",    //	eSoundType_MOB_CHICKEN_HURT
    L"mob/chicken/chickenplop",    //	eSoundType_MOB_CHICKENPLOP
    L"mob/cow/say",                //	eSoundType_MOB_COW_AMBIENT
    L"mob/cow/hurt",               //	eSoundType_MOB_COW_HURT
    L"mob/pig/pig",                //	eSoundType_MOB_PIG_AMBIENT
    L"mob/pig/pigdeath",           //	eSoundType_MOB_PIG_DEATH
    L"mob/sheep/sheep",            //	eSoundType_MOB_SHEEP_AMBIENT
    L"mob/wolf/growl",             //	eSoundType_MOB_WOLF_GROWL
    L"mob/wolf/whine",             //	eSoundType_MOB_WOLF_WHINE
    L"mob/wolf/panting",           //	eSoundType_MOB_WOLF_PANTING
    L"mob/wolf/bark",              //	eSoundType_MOB_WOLF_BARK
    L"mob/wolf/hurt",              //	eSoundType_MOB_WOLF_HURT
    L"mob/wolf/death",             //	eSoundType_MOB_WOLF_DEATH
    L"mob/wolf/shake",             //	eSoundType_MOB_WOLF_SHAKE
    L"mob/blaze/breathe",          //	eSoundType_MOB_BLAZE_BREATHE
    L"mob/blaze/hit",              //	eSoundType_MOB_BLAZE_HURT
    L"mob/blaze/death",            //	eSoundType_MOB_BLAZE_DEATH
    L"mob/ghast/moan",             //	eSoundType_MOB_GHAST_MOAN
    L"mob/ghast/scream",           //	eSoundType_MOB_GHAST_SCREAM
    L"mob/ghast/death",            //	eSoundType_MOB_GHAST_DEATH
    L"mob/ghast/fireball",         //	eSoundType_MOB_GHAST_FIREBALL
    L"mob/ghast/charge",           //	eSoundType_MOB_GHAST_CHARGE
    L"mob/endermen/idle",          //	eSoundType_MOB_ENDERMEN_IDLE
    L"mob/endermen/hit",           //	eSoundType_MOB_ENDERMEN_HIT
    L"mob/endermen/death",         //	eSoundType_MOB_ENDERMEN_DEATH
    L"mob/endermen/portal",        //	eSoundType_MOB_ENDERMEN_PORTAL
    L"mob/zombiepig/zpig",         //	eSoundType_MOB_ZOMBIEPIG_AMBIENT
    L"mob/zombiepig/zpighurt",     //	eSoundType_MOB_ZOMBIEPIG_HURT
    L"mob/zombiepig/zpigdeath",    //	eSoundType_MOB_ZOMBIEPIG_DEATH
    L"mob/zombiepig/zpigangry",    //	eSoundType_MOB_ZOMBIEPIG_ZPIGANGRY
    L"mob/silverfish/say",         //	eSoundType_MOB_SILVERFISH_AMBIENT,
    L"mob/silverfish/hit",         //	eSoundType_MOB_SILVERFISH_HURT
    L"mob/silverfish/kill",        //	eSoundType_MOB_SILVERFISH_DEATH,
    L"mob/silverfish/step",        //	eSoundType_MOB_SILVERFISH_STEP,
    L"mob/skeleton/skeleton",      //	eSoundType_MOB_SKELETON_AMBIENT,
    L"mob/skeleton/skeletonhurt",  //	eSoundType_MOB_SKELETON_HURT,
    L"mob/spider/spider",          //	eSoundType_MOB_SPIDER_AMBIENT,
    L"mob/spider/spiderdeath",     //	eSoundType_MOB_SPIDER_DEATH,
    L"mob/slime/slime",            //	eSoundType_MOB_SLIME,
    L"mob/slime/slimeattack",      //	eSoundType_MOB_SLIME_ATTACK,
    L"mob/creeper/creeper",        //	eSoundType_MOB_CREEPER_HURT,
    L"mob/creeper/creeperdeath",   //	eSoundType_MOB_CREEPER_DEATH,
    L"mob/zombie/zombie",          //	eSoundType_MOB_ZOMBIE_AMBIENT,
    L"mob/zombie/zombiehurt",      //	eSoundType_MOB_ZOMBIE_HURT,
    L"mob/zombie/zombiedeath",     //	eSoundType_MOB_ZOMBIE_DEATH,
    L"mob/zombie/wood",            //	eSoundType_MOB_ZOMBIE_WOOD,
    L"mob/zombie/woodbreak",       //	eSoundType_MOB_ZOMBIE_WOOD_BREAK,
    L"mob/zombie/metal",           //	eSoundType_MOB_ZOMBIE_METAL,
    L"mob/magmacube/big",          //	eSoundType_MOB_MAGMACUBE_BIG,
    L"mob/magmacube/small",        //	eSoundType_MOB_MAGMACUBE_SMALL,
    L"mob/cat/purr",               //  eSoundType_MOB_CAT_PURR
    L"mob/cat/purreow",            //  eSoundType_MOB_CAT_PURREOW
    L"mob/cat/meow",               //  eSoundType_MOB_CAT_MEOW
    // 4J-PB - correct the name of the event for hitting ocelots
    L"mob/cat/hitt",  //  eSoundType_MOB_CAT_HITT
                      //	L"mob.irongolem.throw", //
    // eSoundType_MOB_IRONGOLEM_THROW 	L"mob.irongolem.hit",
    ////  eSoundType_MOB_IRONGOLEM_HIT 	L"mob.irongolem.death",
    ////  eSoundType_MOB_IRONGOLEM_DEATH 	L"mob.irongolem.walk",
    ////  eSoundType_MOB_IRONGOLEM_WALK
    L"random/bow",               //	eSoundType_RANDOM_BOW,
    L"random/bowhit",            //	eSoundType_RANDOM_BOW_HIT,
    L"random/explode",           //	eSoundType_RANDOM_EXPLODE,
    L"random/fizz",              //	eSoundType_RANDOM_FIZZ,
    L"random/pop",               //	eSoundType_RANDOM_POP,
    L"random/fuse",              //	eSoundType_RANDOM_FUSE,
    L"random/drink",             //	eSoundType_RANDOM_DRINK,
    L"random/eat",               //	eSoundType_RANDOM_EAT,
    L"random/burp",              //	eSoundType_RANDOM_BURP,
    L"random/splash",            //	eSoundType_RANDOM_SPLASH,
    L"random/click",             //	eSoundType_RANDOM_CLICK,
    L"random/glass",             //	eSoundType_RANDOM_GLASS,
    L"random/orb",               //	eSoundType_RANDOM_ORB,
    L"random/break",             //	eSoundType_RANDOM_BREAK,
    L"random/chestopen",         //	eSoundType_RANDOM_CHEST_OPEN,
    L"random/chestclosed",       //	eSoundType_RANDOM_CHEST_CLOSE,
    L"random/door_open",         //	eSoundType_RANDOM_DOOR_OPEN,
    L"random/door_close",        //	eSoundType_RANDOM_DOOR_CLOSE,
    L"ambient/weather/rain",     //	eSoundType_AMBIENT_WEATHER_RAIN,
    L"ambient/weather/thunder",  //	eSoundType_AMBIENT_WEATHER_THUNDER,
    L"ambient/cave/cave",  //	eSoundType_CAVE_CAVE, DON'T USE FOR XBOX 360!!!
    L"portal/portal",      //	eSoundType_PORTAL_PORTAL,
    // 4J-PB - added a couple that were still using std::wstring
    L"portal/trigger",  //	eSoundType_PORTAL_TRIGGER
    L"portal/travel",   //	eSoundType_PORTAL_TRAVEL

    L"fire/ignite",       //	eSoundType_FIRE_IGNITE,
    L"fire/fire",         //	eSoundType_FIRE_FIRE,
    L"damage/hit",        //	eSoundType_DAMAGE_HURT,
    L"damage/fallsmall",  //	eSoundType_DAMAGE_FALL_SMALL,
    L"damage/fallbig",    //	eSoundType_DAMAGE_FALL_BIG,
    L"note/harp",         //	eSoundType_NOTE_HARP,
    L"note/bd",           //	eSoundType_NOTE_BD,
    L"note/snare",        //	eSoundType_NOTE_SNARE,
    L"note/hat",          //	eSoundType_NOTE_HAT,
    L"note/bassattack",   //	eSoundType_NOTE_BASSATTACK,
    L"tile/piston.in",    //	eSoundType_TILE_PISTON_IN,
    L"tile/piston.out",   //	eSoundType_TILE_PISTON_OUT,
    L"liquid/water",      //	eSoundType_LIQUID_WATER,
    L"liquid/lavapop",    //	eSoundType_LIQUID_LAVA_POP,
    L"liquid/lava",       //	eSoundType_LIQUID_LAVA,
    L"step/stone",        //	eSoundType_STEP_STONE,
    L"step/wood",         //	eSoundType_STEP_WOOD,
    L"step/gravel",       //	eSoundType_STEP_GRAVEL,
    L"step/grass",        //	eSoundType_STEP_GRASS,
    L"step/metal",        //	eSoundType_STEP_METAL,
    L"step/cloth",        //	eSoundType_STEP_CLOTH,
    L"step/sand",         //	eSoundType_STEP_SAND,

    // below this are the additional sounds from the second soundbank
    L"mob/enderdragon/end",    //	eSoundType_MOB_ENDERDRAGON_END
    L"mob/enderdragon/growl",  //	eSoundType_MOB_ENDERDRAGON_GROWL
    L"mob/enderdragon/hit",    //	eSoundType_MOB_ENDERDRAGON_HIT
    L"mob/enderdragon/wings",  //	eSoundType_MOB_ENDERDRAGON_MOVE
    L"mob/irongolem/throw",    //  eSoundType_MOB_IRONGOLEM_THROW
    L"mob/irongolem/hit",      //  eSoundType_MOB_IRONGOLEM_HIT
    L"mob/irongolem/death",    //  eSoundType_MOB_IRONGOLEM_DEATH
    L"mob/irongolem/walk",     //  eSoundType_MOB_IRONGOLEM_WALK

    // TU14
    L"damage/thorns",        //  eSoundType_DAMAGE_THORNS
    L"random/anvil_break",   //  eSoundType_RANDOM_ANVIL_BREAK
    L"random/anvil_land",    //  eSoundType_RANDOM_ANVIL_LAND
    L"random/anvil_use",     //  eSoundType_RANDOM_ANVIL_USE
    L"mob/villager/haggle",  //  eSoundType_MOB_VILLAGER_HAGGLE
    L"mob/villager/idle",    //  eSoundType_MOB_VILLAGER_IDLE
    L"mob/villager/hit",     //  eSoundType_MOB_VILLAGER_HIT
    L"mob/villager/death",   //  eSoundType_MOB_VILLAGER_DEATH
    L"mob/villager/yes",     //  eSoundType_MOB_VILLAGER_YES
    L"mob/villager/no",      //  eSoundType_MOB_VILLAGER_NO
    L"mob/zombie/infect",    //  eSoundType_MOB_ZOMBIE_INFECT
    L"mob/zombie/unfect",    //  eSoundType_MOB_ZOMBIE_UNFECT
    L"mob/zombie/remedy",    //  eSoundType_MOB_ZOMBIE_REMEDY
    L"step/snow",            //  eSoundType_STEP_SNOW
    L"step/ladder",          //  eSoundType_STEP_LADDER
    L"dig/cloth",            //  eSoundType_DIG_CLOTH
    L"dig/grass",            //  eSoundType_DIG_GRASS
    L"dig/gravel",           //  eSoundType_DIG_GRAVEL
    L"dig/sand",             //  eSoundType_DIG_SAND
    L"dig/snow",             //  eSoundType_DIG_SNOW
    L"dig/stone",            //  eSoundType_DIG_STONE
    L"dig/wood",             //  eSoundType_DIG_WOOD

    // 1.6.4
    L"fireworks/launch",           // eSoundType_FIREWORKS_LAUNCH,
    L"fireworks/blast",            // eSoundType_FIREWORKS_BLAST,
    L"fireworks/blast_far",        // eSoundType_FIREWORKS_BLAST_FAR,
    L"fireworks/large_blast",      // eSoundType_FIREWORKS_LARGE_BLAST,
    L"fireworks/large_blast_far",  // eSoundType_FIREWORKS_LARGE_BLAST_FAR,
    L"fireworks/twinkle",          // eSoundType_FIREWORKS_TWINKLE,
    L"fireworks/twinkle_far",      // eSoundType_FIREWORKS_TWINKLE_FAR,

    L"mob/bat/idle",     // eSoundType_MOB_BAT_IDLE,
    L"mob/bat/hurt",     // eSoundType_MOB_BAT_HURT,
    L"mob/bat/death",    // eSoundType_MOB_BAT_DEATH,
    L"mob/bat/takeoff",  // eSoundType_MOB_BAT_TAKEOFF,

    L"mob/wither/spawn",  // eSoundType_MOB_WITHER_SPAWN,
    L"mob/wither/idle",   // eSoundType_MOB_WITHER_IDLE,
    L"mob/wither/hurt",   // eSoundType_MOB_WITHER_HURT,
    L"mob/wither/death",  // eSoundType_MOB_WITHER_DEATH,
    L"mob/wither/shoot",  // eSoundType_MOB_WITHER_SHOOT,

    L"mob/cow/step",         // eSoundType_MOB_COW_STEP,
    L"mob/chicken/step",     // eSoundType_MOB_CHICKEN_STEP,
    L"mob/pig/step",         // eSoundType_MOB_PIG_STEP,
    L"mob/enderman/stare",   // eSoundType_MOB_ENDERMAN_STARE,
    L"mob/enderman/scream",  // eSoundType_MOB_ENDERMAN_SCREAM,
    L"mob/sheep/shear",      // eSoundType_MOB_SHEEP_SHEAR,
    L"mob/sheep/step",       // eSoundType_MOB_SHEEP_STEP,
    L"mob/skeleton.death",   // eSoundType_MOB_SKELETON_DEATH,
    L"mob/skeleton/step",    // eSoundType_MOB_SKELETON_STEP,
    L"mob/spider/step",      // eSoundType_MOB_SPIDER_STEP,
    L"mob/wolf/step",        // eSoundType_MOB_WOLF_STEP,
    L"mob/zombie/step",      // eSoundType_MOB_ZOMBIE_STEP,

    L"liquid/swim",  // eSoundType_LIQUID_SWIM,

    L"mob/horse/land",            // eSoundType_MOB_HORSE_LAND,
    L"mob/horse/armor",           // eSoundType_MOB_HORSE_ARMOR,
    L"mob/horse/leather",         // eSoundType_MOB_HORSE_LEATHER,
    L"mob/horse/zombie.death",    // eSoundType_MOB_HORSE_ZOMBIE_DEATH,
    L"mob/horse/skeleton.death",  // eSoundType_MOB_HORSE_SKELETON_DEATH,
    L"mob/horse/donkey.death",    // eSoundType_MOB_HORSE_DONKEY_DEATH,
    L"mob/horse/death",           // eSoundType_MOB_HORSE_DEATH,
    L"mob/horse/zombie.hit",      // eSoundType_MOB_HORSE_ZOMBIE_HIT,
    L"mob/horse/skeleton.hit",    // eSoundType_MOB_HORSE_SKELETON_HIT,
    L"mob/horse/donkey.hit",      // eSoundType_MOB_HORSE_DONKEY_HIT,
    L"mob/horse/hit",             // eSoundType_MOB_HORSE_HIT,
    L"mob/horse/zombie.idle",     // eSoundType_MOB_HORSE_ZOMBIE_IDLE,
    L"mob/horse/skeleton.idle",   // eSoundType_MOB_HORSE_SKELETON_IDLE,
    L"mob/horse/donkey.idle",     // eSoundType_MOB_HORSE_DONKEY_IDLE,
    L"mob/horse/idle",            // eSoundType_MOB_HORSE_IDLE,
    L"mob/horse/donkey.angry",    // eSoundType_MOB_HORSE_DONKEY_ANGRY,
    L"mob/horse/angry",           // eSoundType_MOB_HORSE_ANGRY,
    L"mob/horse/gallop",          // eSoundType_MOB_HORSE_GALLOP,
    L"mob/horse/breathe",         // eSoundType_MOB_HORSE_BREATHE,
    L"mob/horse/wood",            // eSoundType_MOB_HORSE_WOOD,
    L"mob/horse/soft",            // eSoundType_MOB_HORSE_SOFT,
    L"mob/horse/jump",            // eSoundType_MOB_HORSE_JUMP,

    L"mob/witch/idle",   // eSoundType_MOB_WITCH_IDLE,			<---
                         // missing
    L"mob/witch/hurt",   // eSoundType_MOB_WITCH_HURT,			<---
                         // missing
    L"mob/witch/death",  // eSoundType_MOB_WITCH_DEATH,			<---
                         // missing

    L"mob/slime/big",    // eSoundType_MOB_SLIME_BIG,
    L"mob/slime/small",  // eSoundType_MOB_SLIME_SMALL,

    L"eating",          // eSoundType_EATING <--- missing
    L"random/levelup",  // eSoundType_RANDOM_LEVELUP

    // 4J-PB  - Some sounds were updated, but we can't do that for the 360 or we
    // have to do a new sound bank instead, we'll add the sounds as new ones and
    // change the code to reference them
    L"fire/new_ignite",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

const wchar_t* yuri_434::wchUISoundNames[eSFX_MAX] = {
    yuri_1720"back", yuri_1720"craft", yuri_1720"craftfail", yuri_1720"focus", yuri_1720"press", yuri_1720"scroll",
};
