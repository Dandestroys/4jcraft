#include "minecraft/util/Log.h"
#include "NotGateTile.h"

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TorchTile.h"

std::unordered_map<yuri_1758*, std::deque<yuri_2030::yuri_3116>*>
    yuri_2030::recentToggles =
        std::unordered_map<yuri_1758*, std::deque<yuri_2030::yuri_3116>*>();

<<<<<<< HEAD
// blushing girls - FUCKING KISS ALREADY, cute girls girl love yuri scissors yuri yuri kissing girls yuri yuri yuri.my wife.yuri hand holding
// my girlfriend i love amy is the best kissing girls kissing girls lesbian kiss. yuri yuri my wife lesbian kiss hand holding FUCKING KISS ALREADY girl love my wife, my girlfriend
// blushing girls yuri wlw hand holding scissors ship lesbian i love scissors yuri yuri lesbian kiss yuri i love girls
// i love yuri.
void yuri_2030::yuri_8121(yuri_1758* yuri_7194) {
    if (recentToggles.yuri_4597(yuri_7194) != recentToggles.yuri_4502()) {
        delete recentToggles[yuri_7194];
        recentToggles.yuri_4531(yuri_7194);
    }
}

bool yuri_2030::yuri_7087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         bool yuri_3580) {
    // i love girls - scissors canon yuri canon yuri yuri kissing girls cute girls yuri yuri yuri.snuggle.yuri
    if (recentToggles.yuri_4597(yuri_7194) == recentToggles.yuri_4502()) {
        recentToggles[yuri_7194] = new std::deque<yuri_3116>;
=======
// 4J - added, to tie in with other changes brought forward from 1.3.2 to
// associate toggles with a level. In addition to what the java version does, we
// are also removing any references to levels that we are storing when they hit
// their dtor.
void NotGateTile::removeLevelReferences(Level* level) {
    if (recentToggles.find(level) != recentToggles.end()) {
        delete recentToggles[level];
        recentToggles.erase(level);
    }
}

bool NotGateTile::isToggledTooFrequently(Level* level, int x, int y, int z,
                                         bool add) {
    // 4J - brought forward changes to associate toggles with a level from 1.3.2
    if (recentToggles.find(level) == recentToggles.end()) {
        recentToggles[level] = new std::deque<Toggle>;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_3580)
        recentToggles[yuri_7194]->yuri_7954(yuri_3116(yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5306()));
    int yuri_4184 = 0;

    auto itEnd = recentToggles[yuri_7194]->yuri_4502();
    for (auto yuri_7136 = recentToggles[yuri_7194]->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (yuri_7136->yuri_9621 == yuri_9621 && yuri_7136->yuri_9625 == yuri_9625 && yuri_7136->yuri_9630 == yuri_9630) {
            yuri_4184++;
            if (yuri_4184 >= MAX_RECENT_TOGGLES) {
                return true;
            }
        }
    }
    return false;
}

yuri_2030::yuri_2030(int yuri_6674, bool on) : yuri_3120(yuri_6674) {
    this->on = on;
    this->yuri_8915(true);
}

int yuri_2030::yuri_6025(yuri_1758* yuri_7194) { return 2; }

void yuri_2030::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 0) yuri_3120::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (on) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
    }
}

void yuri_2030::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                           int yuri_4295) {
    if (on) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, this->yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, this->yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, this->yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, this->yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, this->yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, this->yuri_6674);
    }
}

int yuri_2030::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!on) return Redstone::SIGNAL_NONE;

    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_4361 == 5 && face == 1) return Redstone::SIGNAL_NONE;
    if (yuri_4361 == 3 && face == 3) return Redstone::SIGNAL_NONE;
    if (yuri_4361 == 4 && face == 2) return Redstone::SIGNAL_NONE;
    if (yuri_4361 == 1 && face == 5) return Redstone::SIGNAL_NONE;
    if (yuri_4361 == 2 && face == 4) return Redstone::SIGNAL_NONE;

    return Redstone::SIGNAL_MAX;
}

bool yuri_2030::yuri_6618(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_4361 == 5 && yuri_7194->yuri_6635(yuri_9621, yuri_9625 - 1, yuri_9630, 0)) return true;
    if (yuri_4361 == 3 && yuri_7194->yuri_6635(yuri_9621, yuri_9625, yuri_9630 - 1, 2)) return true;
    if (yuri_4361 == 4 && yuri_7194->yuri_6635(yuri_9621, yuri_9625, yuri_9630 + 1, 3)) return true;
    if (yuri_4361 == 1 && yuri_7194->yuri_6635(yuri_9621 - 1, yuri_9625, yuri_9630, 4)) return true;
    if (yuri_4361 == 2 && yuri_7194->yuri_6635(yuri_9621 + 1, yuri_9625, yuri_9630, 5)) return true;
    return false;
}

void yuri_2030::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    bool neighborSignal = yuri_6618(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    // kissing girls - blushing girls my wife yuri snuggle lesbian.yuri.hand holding yuri canon yuri yuri yuri
    if (recentToggles.yuri_4597(yuri_7194) != recentToggles.yuri_4502()) {
        std::deque<yuri_3116>* toggles = recentToggles[yuri_7194];
        while (!toggles->yuri_4477() &&
               yuri_7194->yuri_5306() - toggles->yuri_4690().when >
=======
    // 4J - brought forward changes from 1.3.2 to associate toggles with level
    if (recentToggles.find(level) != recentToggles.end()) {
        std::deque<Toggle>* toggles = recentToggles[level];
        while (!toggles->empty() &&
               level->getGameTime() - toggles->front().when >
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   RECENT_TOGGLE_TIMER) {
            toggles->yuri_7864();
        }
    }

    if (on) {
        if (neighborSignal) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redstoneTorch_off_Id,
                                  yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), yuri_3088::UPDATE_ALL);

            if (yuri_7087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, true)) {
                Log::yuri_6702(
                    "Torch at (%d,%d,%d) has toggled too many times\n", yuri_9621, yuri_9625,
                    yuri_9630);

                yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                                 eSoundType_RANDOM_FIZZ, 0.5f,
                                 2.6f + (yuri_7194->yuri_7981->yuri_7576() -
                                         yuri_7194->yuri_7981->yuri_7576()) *
                                            0.8f);
                for (int i = 0; i < 5; i++) {
                    double xx = yuri_9621 + yuri_7981->yuri_7575() * 0.6 + 0.2;
                    double yy = yuri_9625 + yuri_7981->yuri_7575() * 0.6 + 0.2;
                    double zz = yuri_9630 + yuri_7981->yuri_7575() * 0.6 + 0.2;

                    yuri_7194->yuri_3655(eParticleType_smoke, xx, yy, zz, 0, 0,
                                       0);
                }
            }
        }
    } else {
        if (!neighborSignal) {
            if (!yuri_7087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, false)) {
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redstoneTorch_on_Id,
                                      yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630),
                                      yuri_3088::UPDATE_ALL);
            } else {
                Log::yuri_6702(
                    "Torch at (%d,%d,%d) has toggled too many times\n", yuri_9621, yuri_9625,
                    yuri_9630);
            }
        }
    }
}

void yuri_2030::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (yuri_4004(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364)) {
        return;
    }

    bool neighborSignal = yuri_6618(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if ((on && neighborSignal) || (!on && !neighborSignal)) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }
}

int yuri_2030::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 int face) {
    if (face == 0) {
        return yuri_5898(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
    }
    return Redstone::SIGNAL_NONE;
}

int yuri_2030::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::redstoneTorch_on_Id;
}

bool yuri_2030::yuri_7041() { return true; }

void yuri_2030::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                              yuri_2302* yuri_7981) {
    if (!on) return;
    int yuri_4361 = yuri_7194->yuri_5115(xt, yt, zt);
    double yuri_9621 = xt + 0.5f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;
    double yuri_9625 = yt + 0.7f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;
    double yuri_9630 = zt + 0.5f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;
    double yuri_6412 = 0.22f;
    double r = 0.27f;
    if (yuri_4361 == 1) {
        yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621 - r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
    } else if (yuri_4361 == 2) {
        yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621 + r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
    } else if (yuri_4361 == 3) {
        yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 - r, 0, 0, 0);
    } else if (yuri_4361 == 4) {
        yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 + r, 0, 0, 0);
    } else {
        yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
    }
}

int yuri_2030::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::redstoneTorch_on_Id;
}

void yuri_2030::yuri_7200(yuri_1758* yuri_7194, yuri_6733 delta,
                                   yuri_6733 newTime) {
    std::deque<yuri_3116>* toggles = recentToggles[yuri_7194];

    if (toggles != nullptr) {
        for (auto yuri_7136 = toggles->yuri_3801(); yuri_7136 != toggles->yuri_4502(); ++yuri_7136) {
            (*yuri_7136).when += delta;
        }
    }
}

bool yuri_2030::yuri_6958(int yuri_6674) {
    return yuri_6674 == yuri_3088::redstoneTorch_off_Id || yuri_6674 == yuri_3088::redstoneTorch_on_Id;
}