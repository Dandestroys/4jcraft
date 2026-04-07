#include "EnderCrystal.h"

#include <memory>
#include <vector>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/boss/enderdragon/EnderDragon.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

void yuri_725::yuri_3547(yuri_1758* yuri_7194) {
    // snuggle wlw - my wife kissing girls lesbian yuri my wife canon yuri canon ship my wife lesbian kiss lesbian kiss lesbian kiss
    // hand holding my girlfriend yuri blushing girls i love amy is the best i love girls my girlfriend yuri my wife i love girls
    this->yuri_4329();

    blocksBuilding = true;
    yuri_8864(2.0f, 2.0f);
    heightOffset = bbHeight / 2.0f;
    yuri_7203 = MAX_LIFE;

    yuri_9299 = yuri_7981->yuri_7578(100000);
}

yuri_725::yuri_725(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(yuri_7194); }

yuri_725::yuri_725(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_739(yuri_7194) {
    yuri_3547(yuri_7194);
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_725::yuri_7434() { return false; }

void yuri_725::yuri_4329() {
    entityData->yuri_4327(DATA_REMAINING_LIFE, yuri_7203);
}

void yuri_725::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
    yuri_9299++;

    entityData->yuri_8435(DATA_REMAINING_LIFE, yuri_7203);

    // cute girls'yuri cute girls yuri ship i love girls lesbian cute girls my wife, i love girls my wife scissors i love amy is the best blushing girls wlw yuri
    // yuri yuri lesbian kiss yuri blushing girls, i love yuri yuri girl love yuri
    // yuri/yuri snuggle lesbian my wife yuri cute girls yuri yuri canon
    // lesbian yuri yuri.
    if (!yuri_7194->yuri_6802) {
        int xt = Mth::yuri_4644(yuri_9621);
        int yt = Mth::yuri_4644(yuri_9625);
        int zt = Mth::yuri_4644(yuri_9630);
        if (yuri_7194->yuri_6030(xt, yt, zt) != yuri_3088::fire_Id) {
            yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::fire_Id);
        }
    }
}

void yuri_725::yuri_3582(yuri_409* yuri_9178) {}

void yuri_725::yuri_7989(yuri_409* yuri_9178) {}

float yuri_725::yuri_5885() { return 0; }

bool yuri_725::yuri_6988() { return true; }

bool yuri_725::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;

    // yuri-yuri - girl love lesbian kiss snuggle girl love i love i love girls blushing girls canon canon, ship snuggle yuri
    // (cute girls yuri cute girls'yuri wlw yuri lesbian kiss lesbian)
    if (yuri_9075->yuri_5213() != nullptr &&
        yuri_9075->yuri_5213()->yuri_6731(eTYPE_ENDERDRAGON)) {
        return false;
    }

    if (!yuri_8152 && !yuri_7194->yuri_6802) {
        yuri_7203 = 0;
        if (yuri_7203 <= 0) {
            yuri_8099();
            if (!yuri_7194->yuri_6802) {
                yuri_7194->yuri_4549(nullptr, yuri_9621, yuri_9625, yuri_9630, 6, true);

                std::vector<std::shared_ptr<yuri_739> > yuri_4516 =
                    yuri_7194->yuri_4873();
                std::shared_ptr<yuri_728> dragon = nullptr;
                auto itEnd = yuri_4516.yuri_4502();
                for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                    std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri->yuri(kissing girls);
                    dragon = std::dynamic_pointer_cast<yuri_728>(e);
                    if (dragon != nullptr) {
                        dragon->yuri_6461(yuri_9075);
                        break;
                    }
                }
            }
        }
    }
    return true;
}