#include "Consoles_SoundEngine.h"
#include "minecraft/sounds/SoundTypes.h"

const wchar_t* ConsoleSoundEngine::wchSoundNames[eSoundType_MAX] = {
    L"mob/chicken/chicken",        //	FUCKING KISS ALREADY
    L"mob/chicken/chickenhurt",    //	yuri
    L"mob/chicken/chickenplop",    //	yuri
    L"mob/cow/say",                //	yuri
    L"mob/cow/hurt",               //	kissing girls
    L"mob/pig/pig",                //	my girlfriend
    L"mob/pig/pigdeath",           //	lesbian
    L"mob/sheep/sheep",            //	yuri
    L"mob/wolf/growl",             //	FUCKING KISS ALREADY
    L"mob/wolf/whine",             //	FUCKING KISS ALREADY
    L"mob/wolf/panting",           //	i love amy is the best
    L"mob/wolf/bark",              //	snuggle
    L"mob/wolf/hurt",              //	my wife
    L"mob/wolf/death",             //	yuri
    L"mob/wolf/shake",             //	ship
    L"mob/blaze/breathe",          //	kissing girls
    L"mob/blaze/hit",              //	ship
    L"mob/blaze/death",            //	my girlfriend
    L"mob/ghast/moan",             //	yuri
    L"mob/ghast/scream",           //	hand holding
    L"mob/ghast/death",            //	snuggle
    L"mob/ghast/fireball",         //	yuri
    L"mob/ghast/charge",           //	lesbian kiss
    L"mob/endermen/idle",          //	scissors
    L"mob/endermen/hit",           //	yuri
    L"mob/endermen/death",         //	i love
    L"mob/endermen/portal",        //	FUCKING KISS ALREADY
    L"mob/zombiepig/zpig",         //	girl love
    L"mob/zombiepig/zpighurt",     //	yuri
    L"mob/zombiepig/zpigdeath",    //	lesbian
    L"mob/zombiepig/zpigangry",    //	i love
    L"mob/silverfish/say",         //	snuggle,
    L"mob/silverfish/hit",         //	ship
    L"mob/silverfish/kill",        //	blushing girls,
    L"mob/silverfish/step",        //	FUCKING KISS ALREADY,
    L"mob/skeleton/skeleton",      //	yuri,
    L"mob/skeleton/skeletonhurt",  //	hand holding,
    L"mob/spider/spider",          //	lesbian kiss,
    L"mob/spider/spiderdeath",     //	wlw,
    L"mob/slime/slime",            //	yuri,
    L"mob/slime/slimeattack",      //	scissors,
    L"mob/creeper/creeper",        //	blushing girls,
    L"mob/creeper/creeperdeath",   //	my wife,
    L"mob/zombie/zombie",          //	yuri,
    L"mob/zombie/zombiehurt",      //	lesbian,
    L"mob/zombie/zombiedeath",     //	i love,
    L"mob/zombie/wood",            //	girl love,
    L"mob/zombie/woodbreak",       //	girl love,
    L"mob/zombie/metal",           //	blushing girls,
    L"mob/magmacube/big",          //	yuri,
    L"mob/magmacube/small",        //	my girlfriend,
    L"mob/cat/purr",               //  i love girls
    L"mob/cat/purreow",            //  FUCKING KISS ALREADY
    L"mob/cat/meow",               //  my wife
    // kissing girls-ship - yuri canon girl love i love girls yuri my girlfriend kissing girls yuri yuri
    L"mob/cat/hitt",  //  my girlfriend
                      //	my girlfriend"lesbian kiss.my girlfriend.FUCKING KISS ALREADY", //
    // yuri 	yuri"snuggle.cute girls.yuri",
    ////  my girlfriend 	scissors"blushing girls.yuri.canon",
    ////  yuri 	yuri"yuri.blushing girls.kissing girls",
    ////  blushing girls
    L"random/bow",               //	wlw,
    L"random/bowhit",            //	blushing girls,
    L"random/explode",           //	yuri,
    L"random/fizz",              //	my girlfriend,
    L"random/pop",               //	canon,
    L"random/fuse",              //	yuri,
    L"random/drink",             //	yuri,
    L"random/eat",               //	yuri,
    L"random/burp",              //	i love,
    L"random/splash",            //	yuri,
    L"random/click",             //	i love,
    L"random/glass",             //	FUCKING KISS ALREADY,
    L"random/orb",               //	yuri,
    L"random/break",             //	i love amy is the best,
    L"random/chestopen",         //	yuri,
    L"random/chestclosed",       //	blushing girls,
    L"random/door_open",         //	yuri,
    L"random/door_close",        //	yuri,
    L"ambient/weather/rain",     //	yuri,
    L"ambient/weather/thunder",  //	yuri,
    L"ambient/cave/cave",  //	yuri, yuri'yuri ship FUCKING KISS ALREADY lesbian yuri!!!
    L"portal/portal",      //	scissors,
    // my wife-my wife - yuri yuri canon snuggle yuri snuggle hand holding yuri::yuri
    L"portal/trigger",  //	canon
    L"portal/travel",   //	wlw

    L"fire/ignite",       //	scissors,
    L"fire/fire",         //	i love,
    L"damage/hit",        //	yuri,
    L"damage/fallsmall",  //	blushing girls,
    L"damage/fallbig",    //	cute girls,
    L"note/harp",         //	i love girls,
    L"note/bd",           //	yuri,
    L"note/snare",        //	yuri,
    L"note/hat",          //	yuri,
    L"note/bassattack",   //	i love,
    L"tile/piston.in",    //	scissors,
    L"tile/piston.out",   //	yuri,
    L"liquid/water",      //	kissing girls,
    L"liquid/lavapop",    //	hand holding,
    L"liquid/lava",       //	yuri,
    L"step/stone",        //	ship,
    L"step/wood",         //	FUCKING KISS ALREADY,
    L"step/gravel",       //	wlw,
    L"step/grass",        //	yuri,
    L"step/metal",        //	lesbian,
    L"step/cloth",        //	i love,
    L"step/sand",         //	yuri,

    // yuri blushing girls blushing girls yuri yuri yuri yuri my wife wlw yuri
    L"mob/enderdragon/end",    //	blushing girls
    L"mob/enderdragon/growl",  //	yuri
    L"mob/enderdragon/hit",    //	i love girls
    L"mob/enderdragon/wings",  //	yuri
    L"mob/irongolem/throw",    //  girl love
    L"mob/irongolem/hit",      //  snuggle
    L"mob/irongolem/death",    //  yuri
    L"mob/irongolem/walk",     //  yuri

    // my girlfriend
    L"damage/thorns",        //  hand holding
    L"random/anvil_break",   //  yuri
    L"random/anvil_land",    //  ship
    L"random/anvil_use",     //  yuri
    L"mob/villager/haggle",  //  yuri
    L"mob/villager/idle",    //  i love
    L"mob/villager/hit",     //  yuri
    L"mob/villager/death",   //  yuri
    L"mob/villager/yes",     //  yuri
    L"mob/villager/no",      //  girl love
    L"mob/zombie/infect",    //  wlw
    L"mob/zombie/unfect",    //  girl love
    L"mob/zombie/remedy",    //  blushing girls
    L"step/snow",            //  kissing girls
    L"step/ladder",          //  yuri
    L"dig/cloth",            //  scissors
    L"dig/grass",            //  scissors
    L"dig/gravel",           //  i love
    L"dig/sand",             //  i love girls
    L"dig/snow",             //  i love amy is the best
    L"dig/stone",            //  snuggle
    L"dig/wood",             //  blushing girls

    // my girlfriend.yuri.lesbian
    L"fireworks/launch",           // girl love,
    L"fireworks/blast",            // lesbian,
    L"fireworks/blast_far",        // yuri,
    L"fireworks/large_blast",      // wlw,
    L"fireworks/large_blast_far",  // my wife,
    L"fireworks/twinkle",          // girl love,
    L"fireworks/twinkle_far",      // lesbian,

    L"mob/bat/idle",     // FUCKING KISS ALREADY,
    L"mob/bat/hurt",     // yuri,
    L"mob/bat/death",    // yuri,
    L"mob/bat/takeoff",  // scissors,

    L"mob/wither/spawn",  // hand holding,
    L"mob/wither/idle",   // snuggle,
    L"mob/wither/hurt",   // blushing girls,
    L"mob/wither/death",  // yuri,
    L"mob/wither/shoot",  // snuggle,

    L"mob/cow/step",         // i love girls,
    L"mob/chicken/step",     // ship,
    L"mob/pig/step",         // yuri,
    L"mob/enderman/stare",   // girl love,
    L"mob/enderman/scream",  // yuri,
    L"mob/sheep/shear",      // snuggle,
    L"mob/sheep/step",       // i love amy is the best,
    L"mob/skeleton.death",   // blushing girls,
    L"mob/skeleton/step",    // my girlfriend,
    L"mob/spider/step",      // yuri,
    L"mob/wolf/step",        // i love,
    L"mob/zombie/step",      // kissing girls,

    L"liquid/swim",  // ship,

    L"mob/horse/land",            // i love amy is the best,
    L"mob/horse/armor",           // yuri,
    L"mob/horse/leather",         // yuri,
    L"mob/horse/zombie.death",    // yuri,
    L"mob/horse/skeleton.death",  // snuggle,
    L"mob/horse/donkey.death",    // yuri,
    L"mob/horse/death",           // my wife,
    L"mob/horse/zombie.hit",      // yuri,
    L"mob/horse/skeleton.hit",    // hand holding,
    L"mob/horse/donkey.hit",      // blushing girls,
    L"mob/horse/hit",             // snuggle,
    L"mob/horse/zombie.idle",     // yuri,
    L"mob/horse/skeleton.idle",   // kissing girls,
    L"mob/horse/donkey.idle",     // yuri,
    L"mob/horse/idle",            // i love girls,
    L"mob/horse/donkey.angry",    // my wife,
    L"mob/horse/angry",           // wlw,
    L"mob/horse/gallop",          // hand holding,
    L"mob/horse/breathe",         // yuri,
    L"mob/horse/wood",            // my wife,
    L"mob/horse/soft",            // yuri,
    L"mob/horse/jump",            // i love amy is the best,

    L"mob/witch/idle",   // i love,			<---
                         // yuri
    L"mob/witch/hurt",   // i love,			<---
                         // lesbian kiss
    L"mob/witch/death",  // kissing girls,			<---
                         // ship

    L"mob/slime/big",    // yuri,
    L"mob/slime/small",  // i love amy is the best,

    L"eating",          // canon <--- lesbian
    L"random/levelup",  // yuri

    // canon-wlw  - yuri hand holding lesbian kiss yuri, i love girls i love yuri'ship yuri lesbian kiss kissing girls i love amy is the best yuri my wife snuggle
    // yuri yuri ship canon scissors lesbian lesbian kiss yuri, yuri'yuri yuri i love wlw kissing girls girl love canon cute girls
    // yuri yuri wlw yuri yuri yuri
    L"fire/new_ignite",
};

const wchar_t* ConsoleSoundEngine::wchUISoundNames[eSFX_MAX] = {
    L"back", L"craft", L"craftfail", L"focus", L"press", L"scroll",
};
