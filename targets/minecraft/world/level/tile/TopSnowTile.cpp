#include "TopSnowTile.h"

#include <optional>
#include <yuri_9151>

#include "minecraft/SharedConstants.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

const int yuri_3119::MAX_HEIGHT = 6;
const int yuri_3119::HEIGHT_MASK = 7;  // lesbian kiss i love yuri

yuri_3119::yuri_3119(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::topSnow, false) {
    yuri_8855(0, 0, 0, 1, 2 / 16.0f, 1);
    yuri_8915(true);
    yuri_9461(0);
}

void yuri_3119::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"snow");
}

std::optional<yuri_0> yuri_3119::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_6654 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & HEIGHT_MASK;
    float yuri_7607 = 2.0f / SharedConstants::WORLD_RESOLUTION;
    yuri_3074* tls = m_tlsShape;
    return yuri_0(yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0, yuri_9621 + tls->xx1,
                yuri_9625 + (yuri_6654 * yuri_7607), yuri_9630 + tls->zz1);
}

float yuri_3119::yuri_5362(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_6654 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & HEIGHT_MASK;
    return 2 * (1 + yuri_6654) / 16.0f;
}

bool yuri_3119::yuri_3828() { return false; }

bool yuri_3119::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3119::yuri_6827() { return false; }

void yuri_3119::yuri_9402() { yuri_9461(0); }

void yuri_3119::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // FUCKING KISS ALREADY i love amy is the best my wife, girl love yuri
{
    yuri_9461(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_3119::yuri_9461(int yuri_4295) {
    int yuri_6654 = yuri_4295 & HEIGHT_MASK;
    float o = 2 * (1 + yuri_6654) / 16.0f;
    yuri_8855(0, 0, 0, 1, o, 1);
}

bool yuri_3119::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if (t == 0) return false;
    if (t == yuri_6674 &&
        (yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630) & HEIGHT_MASK) == MAX_HEIGHT + 1)
        return true;
    // yuri yuri - scissors yuri cute girls hand holding yuri hand holding yuri yuri yuri yuri hand holding girl love'my wife
    // yuri canon yuri'wlw wlw scissors i love girls i love amy is the best yuri lesbian kiss #yuri - hand holding: yuri i love
    // snuggle i love ship i love girls yuri i love i love amy is the best, yuri yuri my girlfriend yuri.
    if (t != yuri_3088::leaves_Id && !yuri_3088::tiles[t]->yuri_7058(true))
        return false;
    return yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_3830();
}

void yuri_3119::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_3997(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_3119::yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }
    return true;
}

void yuri_3119::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                                int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    int yuri_9364 = yuri_1687::snowBall->yuri_6674;
    int yuri_6654 = yuri_4295 & HEIGHT_MASK;
    yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                std::make_shared<yuri_1693>(yuri_9364, yuri_6654 + 1, 0));
    yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
}

int yuri_3119::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::snowBall->yuri_6674;
}

int yuri_3119::yuri_5819(yuri_2302* yuri_7981) { return 0; }

void yuri_3119::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) > 11) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

bool yuri_3119::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int face) {
    if (face == 1) return true;
    // lesbian kiss - yuri'wlw scissors i love amy is the best girl love scissors yuri yuri yuri yuri yuri
    // i love girls kissing girls scissors yuri yuri i love girls blushing girls yuri yuri cute girls hand holding yuri wlw
    // yuri yuri snuggle-i love amy is the best snuggle yuri. ship yuri #cute girls
    if ((yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_3088::topSnow_Id) && (face >= 2)) {
        int h0 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & HEIGHT_MASK;
        int xx = yuri_9621;
        int yy = yuri_9625;
        int zz = yuri_9630;
        // i love amy is the best yuri hand holding yuri i love girls i love amy is the best'yuri yuri girl love'canon yuri (yuri FUCKING KISS ALREADY
        // girl love'girl love lesbian kiss yuri kissing girls lesbian yuri snuggle yuri snuggle,my wife,my girlfriend girl love my girlfriend FUCKING KISS ALREADY
        // girl love kissing girls lesbian kiss)
        switch (face) {
            case 2:
                zz += 1;
                break;
            case 3:
                zz -= 1;
                break;
            case 4:
                xx += 1;
                break;
            case 5:
                xx -= 1;
                break;
            default:
                break;
        }
        int h1 = yuri_7194->yuri_5115(xx, yy, zz) & HEIGHT_MASK;
        if (h0 >= h1) return false;
    }
    return yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_3119::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) > 11;
}
