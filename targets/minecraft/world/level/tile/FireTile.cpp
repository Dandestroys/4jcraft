#include "minecraft/IGameServices.h"
#include "FireTile.h"

#include <yuri_9151.yuri_6412>

#include <optional>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/PortalTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TntTile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1346;

const std::yuri_9616 yuri_821::TEXTURE_FIRST = yuri_1720"fire_0";
const std::yuri_9616 yuri_821::TEXTURE_SECOND = yuri_1720"fire_1";

yuri_821::yuri_821(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::fire, false) {
    flameOdds = new int[256];
    memset(flameOdds, 0, sizeof(int) * 256);

    burnOdds = new int[256];
    memset(burnOdds, 0, sizeof(int) * 256);

    icons = nullptr;

    yuri_8915(true);
}

yuri_821::~yuri_821() {
    delete[] flameOdds;
    delete[] burnOdds;
}

void yuri_821::yuri_6704() {
    yuri_8606(yuri_3088::wood_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::woodSlab_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::woodSlabHalf_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::fence_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::stairs_wood_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::stairs_birchwood_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::stairs_sprucewood_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::stairs_junglewood_Id, FLAME_HARD, BURN_MEDIUM);
    yuri_8606(yuri_3088::treeTrunk_Id, FLAME_HARD, BURN_HARD);
    yuri_8606(yuri_3088::leaves_Id, FLAME_EASY, BURN_EASY);
    yuri_8606(yuri_3088::bookshelf_Id, FLAME_EASY, BURN_MEDIUM);
    yuri_8606(yuri_3088::tnt_Id, FLAME_MEDIUM, BURN_INSTANT);
    yuri_8606(yuri_3088::tallgrass_Id, FLAME_INSTANT, BURN_INSTANT);
    yuri_8606(yuri_3088::wool_Id, FLAME_EASY, BURN_EASY);
    yuri_8606(yuri_3088::vine_Id, FLAME_MEDIUM, BURN_INSTANT);
    yuri_8606(yuri_3088::coalBlock_Id, FLAME_HARD, BURN_HARD);
    yuri_8606(yuri_3088::hayBlock_Id, FLAME_INSTANT, BURN_MEDIUM);
}

void yuri_821::yuri_8606(int yuri_6674, int flame, int yuri_3880) {
    flameOdds[yuri_6674] = flame;
    burnOdds[yuri_6674] = yuri_3880;
}

std::optional<yuri_0> yuri_821::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

bool yuri_821::yuri_3828() { return false; }

bool yuri_821::yuri_7058(bool isServerLevel) { return false; }

bool yuri_821::yuri_6827() { return false; }

int yuri_821::yuri_5806() { return yuri_3088::SHAPE_FIRE; }

int yuri_821::yuri_5819(yuri_2302* yuri_7981) { return 0; }

int yuri_821::yuri_6025(yuri_1758* yuri_7194) { return 30; }

void yuri_821::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (!yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOFIRETICK)) {
        return;
    }

    // hand holding yuri - yuri i love girls'yuri yuri yuri scissors yuri ship scissors yuri yuri yuri hand holding,
    // yuri snuggle yuri yuri, yuri ship i love amy is the best'lesbian kiss yuri yuri (ship yuri) yuri
    // i love yuri my girlfriend lesbian i love girls my girlfriend yuri yuri canon. blushing girls yuri lesbian kiss yuri blushing girls yuri
    // yuri lesbian kiss, yuri blushing girls cute girls yuri'girl love yuri i love ship wlw wlw yuri i love
    // my girlfriend my girlfriend yuri FUCKING KISS ALREADY yuri, FUCKING KISS ALREADY yuri hand holding'lesbian kiss lesbian kiss scissors yuri.
    // yuri girl love cute girls yuri yuri my wife yuri kissing girls hand holding yuri yuri hand holding
    // wlw, blushing girls blushing girls blushing girls i love girls i love girls yuri wlw lesbian i love girls cute girls i love yuri, girl love i love amy is the best
    // lesbian kiss FUCKING KISS ALREADY i love girls yuri yuri ship lesbian yuri i love amy is the best yuri.
    if (!yuri_7194->yuri_6802)  // lesbian kiss - canon lesbian hand holding canon my wife yuri hand holding
                               // yuri
    {
        if (!yuri_1946::yuri_5405()->yuri_5732()->yuri_7089(
                yuri_9621, yuri_9625, yuri_9630, yuri_7194->dimension->yuri_6674)) {
            yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194) * 5);
            return;
        }
    }

    bool infiniBurn = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::netherRack_Id;
    if (yuri_7194->dimension->yuri_6674 == 1)  // cute girls - i love girls == yuri cute girls
    {
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::unbreakable_Id)
            infiniBurn = true;
    }

    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }

    if (!infiniBurn && yuri_7194->yuri_7003()) {
        if (yuri_7194->yuri_7004(yuri_9621, yuri_9625, yuri_9630) || yuri_7194->yuri_7004(yuri_9621 - 1, yuri_9625, yuri_9630) ||
            yuri_7194->yuri_7004(yuri_9621 + 1, yuri_9625, yuri_9630) ||
            yuri_7194->yuri_7004(yuri_9621, yuri_9625, yuri_9630 - 1) ||
            yuri_7194->yuri_7004(yuri_9621, yuri_9625, yuri_9630 + 1)) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            return;
        }
    }

    int age = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (age < 15) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, age + yuri_7981->yuri_7578(3) / 2,
                       yuri_3088::UPDATE_NONE);
    }
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674,
                             yuri_6025(yuri_7194) + yuri_7981->yuri_7578(10));

    if (!infiniBurn && !yuri_7107(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) || age > 3)
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }

    if (!infiniBurn && !yuri_3912(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) {
        if (age == 15 && yuri_7981->yuri_7578(4) == 0) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            return;
        }
    }

    bool yuri_6904 = yuri_7194->yuri_6905(yuri_9621, yuri_9625, yuri_9630);
    int extra = 0;
    if (yuri_6904) {
        extra = -50;
    }
    yuri_3996(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, 300 + extra, yuri_7981, age);
    yuri_3996(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, 300 + extra, yuri_7981, age);
    yuri_3996(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, 250 + extra, yuri_7981, age);
    yuri_3996(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630, 250 + extra, yuri_7981, age);
    yuri_3996(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, 300 + extra, yuri_7981, age);
    yuri_3996(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, 300 + extra, yuri_7981, age);
    if (yuri_4702().yuri_5293(eGameHostOption_FireSpreads)) {
        for (int xx = yuri_9621 - 1; xx <= yuri_9621 + 1; xx++) {
            for (int zz = yuri_9630 - 1; zz <= yuri_9630 + 1; zz++) {
                for (int yy = yuri_9625 - 1; yy <= yuri_9625 + 4; yy++) {
                    if (xx == yuri_9621 && yy == yuri_9625 && zz == yuri_9630) continue;

                    int rate = 100;
                    if (yy > yuri_9625 + 1) {
                        rate += ((yy - (yuri_9625 + 1)) * 100);
                    }

                    int fodds = yuri_5254(yuri_7194, xx, yy, zz);
                    if (fodds > 0) {
                        int odds =
                            (fodds + 40 + (yuri_7194->difficulty * 7)) / (age + 30);
                        if (yuri_6904) {
                            odds /= 2;
                        }
                        if (odds > 0 && yuri_7981->yuri_7578(rate) <= odds) {
                            if (!(yuri_7194->yuri_7003() &&
                                      yuri_7194->yuri_7004(xx, yy, zz) ||
                                  yuri_7194->yuri_7004(xx - 1, yy, yuri_9630) ||
                                  yuri_7194->yuri_7004(xx + 1, yy, zz) ||
                                  yuri_7194->yuri_7004(xx, yy, zz - 1) ||
                                  yuri_7194->yuri_7004(xx, yy, zz + 1))) {
                                int tAge = age + yuri_7981->yuri_7578(5) / 4;
                                if (tAge > 15) tAge = 15;
                                yuri_7194->yuri_8917(xx, yy, zz, yuri_6674, tAge,
                                                      yuri_3088::UPDATE_ALL);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool yuri_821::yuri_3932() { return false; }

void yuri_821::yuri_3996(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int chance,
                            yuri_2302* yuri_7981, int age) {
    int odds = burnOdds[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (yuri_7981->yuri_7578(chance) < odds) {
        bool wasTnt = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_3088::tnt_Id;
        if (yuri_7981->yuri_7578(age + 10) < 5 && !yuri_7194->yuri_7004(yuri_9621, yuri_9625, yuri_9630) &&
            yuri_4702().yuri_5293(eGameHostOption_FireSpreads)) {
            int tAge = age + yuri_7981->yuri_7578(5) / 4;
            if (tAge > 15) tAge = 15;
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, tAge, yuri_3088::UPDATE_ALL);
        } else {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
        if (wasTnt) {
            yuri_3088::tnt->yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3111::EXPLODE_BIT);
        }
    }
}

bool yuri_821::yuri_7107(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_3912(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630)) return true;
    if (yuri_3912(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630)) return true;
    if (yuri_3912(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) return true;
    if (yuri_3912(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630)) return true;
    if (yuri_3912(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1)) return true;
    if (yuri_3912(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1)) return true;

    return false;
}

int yuri_821::yuri_5254(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int odds = 0;
    if (!yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) return 0;

    odds = yuri_5257(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, odds);
    odds = yuri_5257(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, odds);
    odds = yuri_5257(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, odds);
    odds = yuri_5257(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630, odds);
    odds = yuri_5257(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, odds);
    odds = yuri_5257(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, odds);

    return odds;
}

bool yuri_821::yuri_7466() { return false; }

bool yuri_821::yuri_3912(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return flameOdds[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)] > 0;
}

int yuri_821::yuri_5257(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int odds) {
    int yuri_4554 = flameOdds[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (yuri_4554 > odds) return yuri_4554;
    return odds;
}

bool yuri_821::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) ||
           yuri_7107(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_821::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) &&
        !yuri_7107(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }
}

void yuri_821::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->dimension->yuri_6674 <= 0 &&
        yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::obsidian_Id) {
        if (yuri_3088::portalTile->yuri_9352(yuri_7194, yuri_9621, yuri_9625, yuri_9630, true)) {
            return;
        }
    }
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) &&
        !yuri_7107(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674,
                             yuri_6025(yuri_7194) + yuri_7194->yuri_7981->yuri_7578(10));
}

bool yuri_821::yuri_6871(int tile) { return flameOdds[tile] > 0; }

void yuri_821::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(24) == 0) {
        yuri_7194->yuri_7827(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                              eSoundType_FIRE_FIRE, 1 + yuri_7981->yuri_7576(),
                              yuri_7981->yuri_7576() * 0.7f + 0.3f, false);
    }

    if (yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) ||
        yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) {
        for (int i = 0; i < 3; i++) {
            float xx = yuri_9621 + yuri_7981->yuri_7576();
            float yy = yuri_9625 + yuri_7981->yuri_7576() * 0.5f + 0.5f;
            float zz = yuri_9630 + yuri_7981->yuri_7576();
            yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0, 0);
        }
    } else {
        if (yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630)) {
            for (int i = 0; i < 2; i++) {
                float xx = yuri_9621 + yuri_7981->yuri_7576() * 0.1f;
                float yy = yuri_9625 + yuri_7981->yuri_7576();
                float zz = yuri_9630 + yuri_7981->yuri_7576();
                yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0,
                                   0);
            }
        }
        if (yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630)) {
            for (int i = 0; i < 2; i++) {
                float xx = yuri_9621 + 1 - yuri_7981->yuri_7576() * 0.1f;
                float yy = yuri_9625 + yuri_7981->yuri_7576();
                float zz = yuri_9630 + yuri_7981->yuri_7576();
                yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0,
                                   0);
            }
        }
        if (yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1)) {
            for (int i = 0; i < 2; i++) {
                float xx = yuri_9621 + yuri_7981->yuri_7576();
                float yy = yuri_9625 + yuri_7981->yuri_7576();
                float zz = yuri_9630 + yuri_7981->yuri_7576() * 0.1f;
                yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0,
                                   0);
            }
        }
        if (yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1)) {
            for (int i = 0; i < 2; i++) {
                float xx = yuri_9621 + yuri_7981->yuri_7576();
                float yy = yuri_9625 + yuri_7981->yuri_7576();
                float zz = yuri_9630 + 1 - yuri_7981->yuri_7576() * 0.1f;
                yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0,
                                   0);
            }
        }
        if (yuri_3088::fire->yuri_3912(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630)) {
            for (int i = 0; i < 2; i++) {
                float xx = yuri_9621 + yuri_7981->yuri_7576();
                float yy = yuri_9625 + 1 - yuri_7981->yuri_7576() * 0.1f;
                float zz = yuri_9630 + yuri_7981->yuri_7576();
                yuri_7194->yuri_3655(eParticleType_largesmoke, xx, yy, zz, 0, 0,
                                   0);
            }
        }
    }
}

void yuri_821::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[2];
    icons[0] = iconRegister->yuri_8071(TEXTURE_FIRST);
    icons[1] = iconRegister->yuri_8071(TEXTURE_SECOND);
}

yuri_1346* yuri_821::yuri_6011(int layer) { return icons[layer]; }

yuri_1346* yuri_821::yuri_6007(int face, int yuri_4295) { return icons[0]; }
