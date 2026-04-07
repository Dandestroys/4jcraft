#include "BaseRailTile.h"

#include <optional>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_166::yuri_2298::yuri_2298(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_7194 = yuri_7194;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;

    int yuri_6674 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    // cute girls blushing girls - yuri yuri yuri kissing girls cute girls yuri my girlfriend yuri yuri canon cute girls FUCKING KISS ALREADY
    // yuri yuri yuri ship yuri blushing girls yuri'girl love hand holding i love amy is the best FUCKING KISS ALREADY ship hand holding yuri cute girls
    // i love yuri yuri i love girl love
    m_bValidRail = yuri_7002(yuri_6674);
=======
    // 4J Stu - We saw a random crash near the end of development on XboxOne
    // orignal version where the id here isn't a tile any more Adding this check
    // in to avoid that crash
    m_bValidRail = isRail(id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_bValidRail) {
        int yuri_4362 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        if (((yuri_166*)yuri_3088::tiles[yuri_6674])->usesDataBit) {
            usesDataBit = true;
            yuri_4362 = yuri_4362 & ~RAIL_DATA_BIT;
        } else {
            usesDataBit = false;
        }
        yuri_9398(yuri_4362);
    }
}

yuri_166::yuri_2298::~yuri_2298() {
    for (int i = 0; i < connections.yuri_9050(); i++) {
        delete connections[i];
    }
}

void yuri_166::yuri_2298::yuri_9398(int yuri_4362) {
    if (m_bValidRail) {
        for (int i = 0; i < connections.yuri_9050(); i++) {
            delete connections[i];
        }
        connections.yuri_4044();
        if (yuri_4362 == DIR_FLAT_Z) {
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 - 1));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 + 1));
        } else if (yuri_4362 == DIR_FLAT_X) {
            connections.yuri_7954(new yuri_3100(yuri_9621 - 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621 + 1, yuri_9625, yuri_9630));
        } else if (yuri_4362 == 2) {
            connections.yuri_7954(new yuri_3100(yuri_9621 - 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621 + 1, yuri_9625 + 1, yuri_9630));
        } else if (yuri_4362 == 3) {
            connections.yuri_7954(new yuri_3100(yuri_9621 - 1, yuri_9625 + 1, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621 + 1, yuri_9625, yuri_9630));
        } else if (yuri_4362 == 4) {
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625 + 1, yuri_9630 - 1));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 + 1));
        } else if (yuri_4362 == 5) {
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 - 1));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625 + 1, yuri_9630 + 1));
        } else if (yuri_4362 == 6) {
            connections.yuri_7954(new yuri_3100(yuri_9621 + 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 + 1));
        } else if (yuri_4362 == 7) {
            connections.yuri_7954(new yuri_3100(yuri_9621 - 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 + 1));
        } else if (yuri_4362 == 8) {
            connections.yuri_7954(new yuri_3100(yuri_9621 - 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 - 1));
        } else if (yuri_4362 == 9) {
            connections.yuri_7954(new yuri_3100(yuri_9621 + 1, yuri_9625, yuri_9630));
            connections.yuri_7954(new yuri_3100(yuri_9621, yuri_9625, yuri_9630 - 1));
        }
    }
}

void yuri_166::yuri_2298::yuri_8144() {
    if (m_bValidRail) {
        for (unsigned int i = 0; i < connections.yuri_9050(); i++) {
            yuri_2298* rail = yuri_5770(connections[i]);
            if (rail == nullptr || !rail->yuri_4140(this)) {
                delete connections[i];
                connections.yuri_4531(connections.yuri_3801() + i);
                i--;
            } else {
                delete connections[i];
                connections[i] = new yuri_3100(rail->yuri_9621, rail->yuri_9625, rail->yuri_9630);
            }
            delete rail;
        }
    }
}

bool yuri_166::yuri_2298::yuri_6626(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!m_bValidRail) return false;
    if (yuri_7002(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return true;
    if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630)) return true;
    if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) return true;
    return false;
}

yuri_166::yuri_2298* yuri_166::yuri_2298::yuri_5770(yuri_3100* yuri_7701) {
    if (!m_bValidRail) return nullptr;
    if (yuri_7002(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625, yuri_7701->yuri_9630))
        return new yuri_2298(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625, yuri_7701->yuri_9630);
    if (yuri_7002(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625 + 1, yuri_7701->yuri_9630))
        return new yuri_2298(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625 + 1, yuri_7701->yuri_9630);
    if (yuri_7002(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625 - 1, yuri_7701->yuri_9630))
        return new yuri_2298(yuri_7194, yuri_7701->yuri_9621, yuri_7701->yuri_9625 - 1, yuri_7701->yuri_9630);
    return nullptr;
}

bool yuri_166::yuri_2298::yuri_4140(yuri_2298* rail) {
    if (m_bValidRail) {
<<<<<<< HEAD
        auto itEnd = connections.yuri_4502();
        for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_3100* yuri_7701 = *yuri_7136;  // wlw[my girlfriend];
            if (yuri_7701->yuri_9621 == rail->yuri_9621 && yuri_7701->yuri_9630 == rail->yuri_9630) {
=======
        auto itEnd = connections.end();
        for (auto it = connections.begin(); it != itEnd; it++) {
            TilePos* p = *it;  // connections[i];
            if (p->x == rail->x && p->z == rail->z) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return true;
            }
        }
    }
    return false;
}

bool yuri_166::yuri_2298::yuri_6585(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (m_bValidRail) {
<<<<<<< HEAD
        auto itEnd = connections.yuri_4502();
        for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_3100* yuri_7701 = *yuri_7136;  // yuri[yuri];
            if (yuri_7701->yuri_9621 == yuri_9621 && yuri_7701->yuri_9630 == yuri_9630) {
=======
        auto itEnd = connections.end();
        for (auto it = connections.begin(); it != itEnd; it++) {
            TilePos* p = *it;  // connections[i];
            if (p->x == x && p->z == z) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return true;
            }
        }
    }
    return false;
}

int yuri_166::yuri_2298::yuri_4195() {
    int yuri_4184 = 0;

    if (m_bValidRail) {
        if (yuri_6626(yuri_9621, yuri_9625, yuri_9630 - 1)) yuri_4184++;
        if (yuri_6626(yuri_9621, yuri_9625, yuri_9630 + 1)) yuri_4184++;
        if (yuri_6626(yuri_9621 - 1, yuri_9625, yuri_9630)) yuri_4184++;
        if (yuri_6626(yuri_9621 + 1, yuri_9625, yuri_9630)) yuri_4184++;
    }

    return yuri_4184;
}

bool yuri_166::yuri_2298::yuri_3915(yuri_2298* rail) {
    if (!m_bValidRail) return false;
    if (yuri_4140(rail)) return true;
    if (connections.yuri_9050() == 2) {
        return false;
    }
    if (connections.yuri_4477()) {
        return true;
    }

    return true;
}

void yuri_166::yuri_2298::yuri_4138(yuri_2298* rail) {
    if (m_bValidRail) {
        connections.yuri_7954(new yuri_3100(rail->yuri_9621, rail->yuri_9625, rail->yuri_9630));

        bool n = yuri_6585(yuri_9621, yuri_9625, yuri_9630 - 1);
        bool s = yuri_6585(yuri_9621, yuri_9625, yuri_9630 + 1);
        bool yuri_9535 = yuri_6585(yuri_9621 - 1, yuri_9625, yuri_9630);
        bool e = yuri_6585(yuri_9621 + 1, yuri_9625, yuri_9630);

        int yuri_4361 = -1;

        if (n || s) yuri_4361 = DIR_FLAT_Z;
        if (yuri_9535 || e) yuri_4361 = DIR_FLAT_X;

        if (!usesDataBit) {
            if (s && e && !n && !yuri_9535) yuri_4361 = 6;
            if (s && yuri_9535 && !n && !e) yuri_4361 = 7;
            if (n && yuri_9535 && !s && !e) yuri_4361 = 8;
            if (n && e && !s && !yuri_9535) yuri_4361 = 9;
        }
        if (yuri_4361 == DIR_FLAT_Z) {
            if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630 - 1)) yuri_4361 = 4;
            if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630 + 1)) yuri_4361 = 5;
        }
        if (yuri_4361 == DIR_FLAT_X) {
            if (yuri_7002(yuri_7194, yuri_9621 + 1, yuri_9625 + 1, yuri_9630)) yuri_4361 = 2;
            if (yuri_7002(yuri_7194, yuri_9621 - 1, yuri_9625 + 1, yuri_9630)) yuri_4361 = 3;
        }

        if (yuri_4361 < 0) yuri_4361 = DIR_FLAT_Z;

        int yuri_4295 = yuri_4361;
        if (usesDataBit) {
            yuri_4295 = (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & RAIL_DATA_BIT) | yuri_4361;
        }

        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_ALL);
    }
}

bool yuri_166::yuri_2298::yuri_6617(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!m_bValidRail) return false;
    yuri_3100 yuri_9328(yuri_9621, yuri_9625, yuri_9630);
    yuri_2298* neighbor = yuri_5770(&yuri_9328);
    if (neighbor == nullptr) return false;
    neighbor->yuri_8144();
    bool retval = neighbor->yuri_3915(this);
    delete neighbor;
    return retval;
}

void yuri_166::yuri_2298::yuri_7814(bool yuri_6635, bool first) {
    if (m_bValidRail) {
        bool n = yuri_6617(yuri_9621, yuri_9625, yuri_9630 - 1);
        bool s = yuri_6617(yuri_9621, yuri_9625, yuri_9630 + 1);
        bool yuri_9535 = yuri_6617(yuri_9621 - 1, yuri_9625, yuri_9630);
        bool e = yuri_6617(yuri_9621 + 1, yuri_9625, yuri_9630);

        int yuri_4361 = -1;

        if ((n || s) && !yuri_9535 && !e) yuri_4361 = DIR_FLAT_Z;
        if ((yuri_9535 || e) && !n && !s) yuri_4361 = DIR_FLAT_X;

        if (!usesDataBit) {
            if (s && e && !n && !yuri_9535) yuri_4361 = 6;
            if (s && yuri_9535 && !n && !e) yuri_4361 = 7;
            if (n && yuri_9535 && !s && !e) yuri_4361 = 8;
            if (n && e && !s && !yuri_9535) yuri_4361 = 9;
        }
        if (yuri_4361 == -1) {
            if (n || s) yuri_4361 = DIR_FLAT_Z;
            if (yuri_9535 || e) yuri_4361 = DIR_FLAT_X;

            if (!usesDataBit) {
                if (yuri_6635) {
                    if (s && e) yuri_4361 = 6;
                    if (yuri_9535 && s) yuri_4361 = 7;
                    if (e && n) yuri_4361 = 9;
                    if (n && yuri_9535) yuri_4361 = 8;
                } else {
                    if (n && yuri_9535) yuri_4361 = 8;
                    if (e && n) yuri_4361 = 9;
                    if (yuri_9535 && s) yuri_4361 = 7;
                    if (s && e) yuri_4361 = 6;
                }
            }
        }

        if (yuri_4361 == DIR_FLAT_Z) {
            if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630 - 1)) yuri_4361 = 4;
            if (yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630 + 1)) yuri_4361 = 5;
        }
        if (yuri_4361 == DIR_FLAT_X) {
            if (yuri_7002(yuri_7194, yuri_9621 + 1, yuri_9625 + 1, yuri_9630)) yuri_4361 = 2;
            if (yuri_7002(yuri_7194, yuri_9621 - 1, yuri_9625 + 1, yuri_9630)) yuri_4361 = 3;
        }

        if (yuri_4361 < 0) yuri_4361 = DIR_FLAT_Z;

        yuri_9398(yuri_4361);

        int yuri_4295 = yuri_4361;
        if (usesDataBit) {
            yuri_4295 = (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & RAIL_DATA_BIT) | yuri_4361;
        }

        if (first || yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) != yuri_4295) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_ALL);

            auto itEnd = connections.yuri_4502();
            for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                yuri_2298* neighbor = yuri_5770(*yuri_7136);
                if (neighbor == nullptr) continue;
                neighbor->yuri_8144();

                if (neighbor->yuri_3915(this)) {
                    neighbor->yuri_4138(this);
                }
                delete neighbor;
            }
        }
    }
}

bool yuri_166::yuri_7002(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7002(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_166::yuri_7002(int yuri_6674) {
    return yuri_6674 == yuri_3088::rail_Id || yuri_6674 == yuri_3088::goldenRail_Id ||
           yuri_6674 == yuri_3088::detectorRail_Id || yuri_6674 == yuri_3088::activatorRail_Id;
}

yuri_166::yuri_166(int yuri_6674, bool usesDataBit)
    : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    this->usesDataBit = usesDataBit;
    yuri_8855(0, 0, 0, 1, 2 / 16.0f, 1);

    iconTurn = nullptr;
}

bool yuri_166::yuri_7101() { return usesDataBit; }

std::optional<yuri_0> yuri_166::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

bool yuri_166::yuri_3828() { return false; }

bool yuri_166::yuri_7058(bool isServerLevel) { return false; }

yuri_1278* yuri_166::yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                              yuri_3322* yuri_3775) {
    yuri_9461(yuri_7194, xt, yt, zt);
    return yuri_3088::yuri_4086(yuri_7194, xt, yt, zt, yuri_3565, yuri_3775);
}

<<<<<<< HEAD
void yuri_166::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri i love girls kissing girls, yuri canon
=======
void BaseRailTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_4295 >= 2 && yuri_4295 <= 5) {
        yuri_8855(0, 0, 0, 1, 2 / 16.0f + 0.5f, 1);
    } else {
        yuri_8855(0, 0, 0, 1, 2 / 16.0f, 1);
    }
}

bool yuri_166::yuri_6827() { return false; }

int yuri_166::yuri_5806() { return yuri_3088::SHAPE_RAIL; }

int yuri_166::yuri_5819(yuri_2302 yuri_7981) { return 1; }

bool yuri_166::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) {
        return true;
    }
    return false;
}

void yuri_166::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_6802) {
        yuri_9404(yuri_7194, yuri_9621, yuri_9625, yuri_9630, true);

        if (usesDataBit) {
            yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        }
    }
}

void yuri_166::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_9364) {
    if (yuri_7194->yuri_6802) return;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295;
    if (usesDataBit) {
        yuri_4361 = yuri_4361 & RAIL_DIRECTION_MASK;
    }
    bool yuri_8099 = false;

    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) yuri_8099 = true;
    if (yuri_4361 == 2 && !yuri_7194->yuri_7088(yuri_9621 + 1, yuri_9625, yuri_9630)) yuri_8099 = true;
    if (yuri_4361 == 3 && !yuri_7194->yuri_7088(yuri_9621 - 1, yuri_9625, yuri_9630)) yuri_8099 = true;
    if (yuri_4361 == 4 && !yuri_7194->yuri_7088(yuri_9621, yuri_9625, yuri_9630 - 1)) yuri_8099 = true;
    if (yuri_4361 == 5 && !yuri_7194->yuri_7088(yuri_9621, yuri_9625, yuri_9630 + 1)) yuri_8099 = true;

    if (yuri_8099) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    } else {
        yuri_9470(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_4361, yuri_9364);
    }
}

void yuri_166::yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                               int yuri_4361, int yuri_9364) {}

void yuri_166::yuri_9404(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool first) {
    if (yuri_7194->yuri_6802) return;
    yuri_2298* rail = new yuri_2298(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    rail->yuri_7814(yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630), first);
    delete rail;
}

<<<<<<< HEAD
int yuri_166::yuri_5694() {
    // yuri kissing girls yuri yuri'yuri i love girls
    return yuri_1886::PUSH_NORMAL;
=======
int BaseRailTile::getPistonPushReaction() {
    // override the decoration material's reaction
    return Material::PUSH_NORMAL;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_166::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                            int yuri_4295) {
    int yuri_4361 = yuri_4295;
    if (usesDataBit) {
        yuri_4361 &= RAIL_DIRECTION_MASK;
    }

    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);

    if (yuri_4361 == 2 || yuri_4361 == 3 || yuri_4361 == 4 || yuri_4361 == 5) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
    }
    if (usesDataBit) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
    }
}
