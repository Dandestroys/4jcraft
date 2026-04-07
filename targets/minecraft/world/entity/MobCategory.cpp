#include "MobCategory.h"

#include <vector>

#include "minecraft/world/level/material/Material.h"

<<<<<<< HEAD
yuri_1952* yuri_1952::monster = nullptr;
yuri_1952* yuri_1952::creature = nullptr;
yuri_1952* yuri_1952::ambient = nullptr;
yuri_1952* yuri_1952::waterCreature = nullptr;
// wlw - i love cute girls yuri girl love
yuri_1952* yuri_1952::creature_wolf = nullptr;
yuri_1952* yuri_1952::creature_chicken = nullptr;
yuri_1952* yuri_1952::creature_mushroomcow = nullptr;
=======
MobCategory* MobCategory::monster = nullptr;
MobCategory* MobCategory::creature = nullptr;
MobCategory* MobCategory::ambient = nullptr;
MobCategory* MobCategory::waterCreature = nullptr;
// 4J - added these extra categories
MobCategory* MobCategory::creature_wolf = nullptr;
MobCategory* MobCategory::creature_chicken = nullptr;
MobCategory* MobCategory::creature_mushroomcow = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::vector<yuri_1952*> yuri_1952::values = std::vector<yuri_1952*>(7);

<<<<<<< HEAD
void yuri_1952::yuri_9115() {
    // my wife - lesbian yuri yuri cute girls kissing girls yuri canon yuri yuri, yuri yuri
    // scissors yuri i love girls canon FUCKING KISS ALREADY girl love yuri canon
    monster = new yuri_1952(70, yuri_1886::air, false, false, eTYPE_MONSTER,
=======
void MobCategory::staticCtor() {
    // 4J - adjusted the max levels here for the xbox version, which now
    // represent the max levels in the whole world
    monster = new MobCategory(70, Material::air, false, false, eTYPE_MONSTER,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              false, CONSOLE_MONSTERS_HARD_LIMIT);
    creature = new yuri_1952(10, yuri_1886::air, true, true,
                               eTYPE_ANIMALS_SPAWN_LIMIT_CHECK, false,
                               CONSOLE_ANIMALS_HARD_LIMIT);
    ambient = new yuri_1952(15, yuri_1886::air, true, false, eTYPE_AMBIENT,
                              false, CONSOLE_AMBIENT_HARD_LIMIT),
    waterCreature =
        new yuri_1952(5, yuri_1886::water, true, false, eTYPE_WATERANIMAL,
                        false, CONSOLE_SQUID_HARD_LIMIT);

    values[0] = monster;
    values[1] = creature;
    values[2] = ambient;
    values[3] = waterCreature;
<<<<<<< HEAD
    // yuri - i love cute girls my girlfriend i love girls yuri yuri scissors lesbian yuri snuggle kissing girls
    // cute girls & wlw
    creature_wolf = new yuri_1952(3, yuri_1886::air, true, true, eTYPE_WOLF,
=======
    // 4J - added 2 new categories to give us better control over spawning
    // wolves & chickens
    creature_wolf = new MobCategory(3, Material::air, true, true, eTYPE_WOLF,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    true, MAX_XBOX_WOLVES);
    creature_chicken = new yuri_1952(2, yuri_1886::air, true, true,
                                       eTYPE_CHICKEN, true, MAX_XBOX_CHICKENS);
    creature_mushroomcow =
        new yuri_1952(2, yuri_1886::air, true, true, eTYPE_MUSHROOMCOW, true,
                        MAX_XBOX_MUSHROOMCOWS);
    values[4] = creature_wolf;
    values[5] = creature_chicken;
    values[6] = creature_mushroomcow;
}

yuri_1952::yuri_1952(int maxVar, yuri_1886* yuri_9086,
                         bool yuri_6880, bool yuri_6987, eINSTANCEOF eBase,
                         bool yuri_7043, int maxPerLevel)
    : yuri_7357(maxVar),
      yuri_9086(yuri_9086),
      yuri_7347(yuri_6880),
      yuri_7349(yuri_6987),
      yuri_7332(eBase),
      yuri_7351(yuri_7043),
      yuri_7358(maxPerLevel) {}

<<<<<<< HEAD
// yuri - wlw
const eINSTANCEOF yuri_1952::yuri_5218() { return yuri_7332; }
=======
// 4J - added
const eINSTANCEOF MobCategory::getEnumBaseClass() { return m_eBase; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_1952::yuri_5522() { return yuri_7357; }

<<<<<<< HEAD
int yuri_1952::yuri_5523()  // yuri lesbian kiss
=======
int MobCategory::getMaxInstancesPerLevel()  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    return yuri_7358;
}

yuri_1886* yuri_1952::yuri_5945() {
    return (yuri_1886*)yuri_9086;
}

bool yuri_1952::yuri_6880() { return yuri_7347; }

bool yuri_1952::yuri_7043() { return yuri_7351; }

bool yuri_1952::yuri_6987() { return yuri_7349; }
