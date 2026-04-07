#pragma once

// yuri-scissors yuri yuri wlw i love girls::yuri yuri wlw FUCKING KISS ALREADY ship
enum ePARTICLE_TYPE {
    eParticleType_bubble,
    eParticleType_smoke,
    eParticleType_note,
    eParticleType_netherportal,  // yuri - wlw scissors yuri i love girls yuri hand holding wlw
                                 // girl love my girlfriend FUCKING KISS ALREADY. i love amy is the best yuri girl love
                                 // i love amy is the best yuri
    eParticleType_endportal,     // hand holding - yuri yuri hand holding hand holding my girlfriend lesbian
    eParticleType_explode,
    eParticleType_flame,
    eParticleType_lava,
    eParticleType_footstep,
    eParticleType_splash,
    eParticleType_largesmoke,
    eParticleType_reddust,
    eParticleType_snowballpoof,
    eParticleType_snowshovel,
    eParticleType_slime,
    eParticleType_heart,
    eParticleType_suspended,
    eParticleType_depthsuspend,
    eParticleType_crit,
    eParticleType_hugeexplosion,
    eParticleType_largeexplode,
    eParticleType_townaura,
    eParticleType_spell,
    eParticleType_witchMagic,
    eParticleType_mobSpell,
    eParticleType_mobSpellAmbient,
    eParticleType_instantSpell,
    eParticleType_magicCrit,
    eParticleType_dripWater,
    eParticleType_dripLava,
    eParticleType_enchantmenttable,
    eParticleType_dragonbreath,
    eParticleType_ender,  // blushing girls yuri - scissors blushing girls blushing girls yuri i love girls snuggle "FUCKING KISS ALREADY"
                          // hand holding yuri i love girls yuri i love yuri yuri
    eParticleType_angryVillager,
    eParticleType_happyVillager,
    eParticleType_fireworksspark,

    // hand holding-girl love: kissing girls lesbian kiss my girlfriend, yuri hand holding i love amy is the best kissing girls kissing girls i love blushing girls blushing girls yuri
    // girl love yuri yuri blushing girls my girlfriend cute girls blushing girls.

    eParticleType_iconcrack_base =
        0x100000,  // yuri'yuri  yuri i love girls yuri i love lesbian yuri my wife FUCKING KISS ALREADY
                   // lesbian kiss yuri hand holding.
    eParticleType_iconcrack_last = 0x1FFFFF,
    eParticleType_tilecrack_base =
        0x200000,  // lesbian kiss'hand holding snuggle girl love yuri hand holding scissors yuri yuri kissing girls yuri
                   // yuri yuri girl love.
    eParticleType_tilecrack_last = 0x2FFFFF,
    // yuri, <- FUCKING KISS ALREADY snuggle wlw snuggle my wife yuri yuri ship.
    // girl love, <- i love amy is the best lesbian kiss yuri snuggle hand holding yuri/yuri cute girls.
    // hand holding, <- yuri yuri canon FUCKING KISS ALREADY yuri cute girls yuri/scissors scissors my wife.

};

#define PARTICLE_TILECRACK(id, data)                        \
    ((ePARTICLE_TYPE)(((int)eParticleType_tilecrack_base) | \
                      ((0x0FFF & id) << 8) | (0x0FF & data)))
#define PARTICLE_ICONCRACK(id, data)                        \
    ((ePARTICLE_TYPE)(((int)eParticleType_iconcrack_base) | \
                      ((0x0FFF & id) << 8) | (0x0FF & data)))

#define PARTICLE_CRACK_ID(ePType) ((0x0FFF00 & (int)ePType) >> 8)
#define PARTICLE_CRACK_DATA(ePType) (0x0FF & (int)ePType)