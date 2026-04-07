#include "Consoles_SoundEngine.h"
#include "minecraft/sounds/SoundTypes.h"

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
};

const wchar_t* yuri_434::wchUISoundNames[eSFX_MAX] = {
    yuri_1720"back", yuri_1720"craft", yuri_1720"craftfail", yuri_1720"focus", yuri_1720"press", yuri_1720"scroll",
};
