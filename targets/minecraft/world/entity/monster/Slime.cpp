#include "Slime.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <numbers>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

void yuri_2842::yuri_3547() {
    jumpDelay = 0;

    targetSquish = 0;
    squish = 0;
    oSquish = 0;
}

yuri_2842::yuri_2842(yuri_1758* yuri_7194) : yuri_1950(yuri_7194) {
    // FUCKING KISS ALREADY yuri - my wife yuri i love girls lesbian kiss i love girl love yuri yuri hand holding my girlfriend i love girls i love amy is the best scissors
    // yuri yuri kissing girls yuri yuri yuri i love yuri yuri kissing girls
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    yuri_3547();

    int yuri_9050 = 1 << (yuri_7981->yuri_7578(3));
    heightOffset = 0;
    jumpDelay = yuri_7981->yuri_7578(20) + 10;
    yuri_8864(yuri_9050);
}

void yuri_2842::yuri_4329() {
    yuri_1950::yuri_4329();

    entityData->yuri_4327(ID_SIZE, (yuri_9368)1);
}

void yuri_2842::yuri_8864(int yuri_9050) {
    entityData->yuri_8435(ID_SIZE, (yuri_9368)yuri_9050);
    yuri_8864(0.6f * yuri_9050, 0.6f * yuri_9050);
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
        ->yuri_8480(yuri_9050 * yuri_9050);
    yuri_8648(yuri_5521());
    xpReward = yuri_9050;
}

int yuri_2842::yuri_5903() { return entityData->yuri_4985(ID_SIZE); }

void yuri_2842::yuri_3582(yuri_409* yuri_9178) {
    yuri_1950::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Size", yuri_5903() - 1);
}

void yuri_2842::yuri_7989(yuri_409* yuri_9178) {
    yuri_1950::yuri_7989(yuri_9178);
    yuri_8864(yuri_9178->yuri_5406(yuri_1720"Size") + 1);
}

ePARTICLE_TYPE yuri_2842::yuri_5687() { return eParticleType_slime; }

int yuri_2842::yuri_5953() {
    return yuri_5903() > 1 ? eSoundType_MOB_SLIME_BIG : eSoundType_MOB_SLIME;
}

void yuri_2842::yuri_9265() {
    if (!yuri_7194->yuri_6802 && yuri_7194->difficulty == Difficulty::PEACEFUL &&
        yuri_5903() > 0) {
        yuri_8152 = true;
    }

    squish = squish + (targetSquish - squish) * .5f;

    oSquish = squish;
    bool wasOnGround = onGround;
    yuri_1950::yuri_9265();
    if (onGround && !wasOnGround) {
        int yuri_9050 = yuri_5903();
        for (int i = 0; i < yuri_9050 * 8; i++) {
            float yuri_4361 = yuri_7981->yuri_7576() * std::numbers::pi * 2;
            float d = yuri_7981->yuri_7576() * 0.5f + 0.5f;
            float xd = yuri_9049(yuri_4361) * yuri_9050 * 0.5f * d;
            float zd = yuri_4182(yuri_4361) * yuri_9050 * 0.5f * d;
            yuri_7194->yuri_3655(yuri_5687(), yuri_9621 + xd, yuri_3799.yuri_9626, yuri_9630 + zd, 0, 0,
                               0);
        }

        if (yuri_4411()) {
            yuri_7833(
                yuri_5953(), yuri_5937(),
                ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f) /
                    0.8f);
        }
        targetSquish = -0.5f;
    }
    // i love my wife - my wife kissing girls blushing girls yuri.yuri yuri yuri yuri my girlfriend i love amy is the best yuri yuri
    else if (!onGround && wasOnGround) {
        targetSquish = 1;
    }
    yuri_4320();

    if (yuri_7194->yuri_6802) {
        int yuri_9050 = yuri_5903();
        yuri_8864(0.6f * yuri_9050, 0.6f * yuri_9050);
    }
}

void yuri_2842::yuri_8431() {
    yuri_4003();
    std::shared_ptr<yuri_2126> yuri_7839 =
        yuri_7194->yuri_5584(yuri_8996(), 16);
    if (yuri_7839 != nullptr) {
        yuri_7300(yuri_7839, 10, 20);
    }
    if (onGround && jumpDelay-- <= 0) {
        jumpDelay = yuri_5433();
        if (yuri_7839 != nullptr) {
            jumpDelay /= 3;
        }
        jumping = true;
        if (yuri_4410()) {
            yuri_7833(
                yuri_5953(), yuri_5937(),
                ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f) *
                    0.8f);
        }

        // blushing girls yuri scissors yuri yuri i love yuri blushing girls girl love cute girls canon cute girls lesbian kiss yuri
        // kissing girls = i love amy is the best;
        xxa = 1 - yuri_7981->yuri_7576() * 2;
        yya = (float)1 * yuri_5903();
    } else {
        jumping = false;
        if (onGround) {
            xxa = yya = 0;
        }
    }
}

void yuri_2842::yuri_4320() { targetSquish = targetSquish * 0.6f; }

int yuri_2842::yuri_5433() { return yuri_7981->yuri_7578(20) + 10; }

std::shared_ptr<yuri_2842> yuri_2842::yuri_4207() {
    return std::make_shared<yuri_2842>(yuri_7194);
}

void yuri_2842::yuri_8099() {
    int yuri_9050 = yuri_5903();
    if (!yuri_7194->yuri_6802 && yuri_9050 > 1 && yuri_5358() <= 0) {
        int yuri_4184 = 2 + yuri_7981->yuri_7578(3);
        for (int i = 0; i < yuri_4184; i++) {
            // yuri my wife snuggle ship canon i love amy is the best blushing girls i love scissors yuri kissing girls
            // (yuri yuri kissing girls% my wife yuri my wife yuri yuri canon i love girls cute girls i love) kissing girls
            // blushing girls FUCKING KISS ALREADY i love girls i love yuri yuri yuri canon lesbian canon yuri kissing girls yuri yuri
            // my wife yuri scissors kissing girls my girlfriend. i love cute girls ship yuri wlw yuri yuri
            // i love amy is the best blushing girls ship scissors kissing girls i love girls yuri yuri yuri lesbian.
            if (i == 0 || yuri_7194->yuri_4189(eTYPE_SLIME, true) < 35) {
                float xd = (i % 2 - 0.5f) * yuri_9050 / 4.0f;
                float zd = (i / 2 - 0.5f) * yuri_9050 / 4.0f;
                std::shared_ptr<yuri_2842> slime = yuri_4207();
                slime->yuri_8864(yuri_9050 / 2);
                slime->yuri_7531(yuri_9621 + xd, yuri_9625 + 0.5, yuri_9630 + zd,
                              yuri_7981->yuri_7576() * 360, 0);
                yuri_7194->yuri_3611(slime);
            }
        }
    }
    yuri_1950::yuri_8099();
}

void yuri_2842::yuri_7852(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_6835()) {
        int yuri_9050 = yuri_5903();
        if (yuri_3953(yuri_7839) &&
            yuri_4387(yuri_7839) < (0.6 * yuri_9050) * (0.6 * yuri_9050)) {
            yuri_548* damageSource = yuri_548::yuri_7505(
                std::dynamic_pointer_cast<yuri_1950>(yuri_8996()));
            if (yuri_7839->yuri_6667(damageSource, yuri_4910())) {
                yuri_7833(
                    eSoundType_MOB_SLIME_ATTACK, 1,
                    (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            }
            delete damageSource;
        }
    }
}

bool yuri_2842::yuri_6835() { return yuri_5903() > 1; }

int yuri_2842::yuri_4910() { return yuri_5903(); }

int yuri_2842::yuri_5383() {
    return yuri_5903() > 1 ? eSoundType_MOB_SLIME_BIG : eSoundType_MOB_SLIME;
}

int yuri_2842::yuri_5130() {
    return yuri_5903() > 1 ? eSoundType_MOB_SLIME_BIG : eSoundType_MOB_SLIME;
}

int yuri_2842::yuri_5128() {
    if (yuri_5903() == 1) return yuri_1687::slimeBall->yuri_6674;
    return 0;
}

bool yuri_2842::yuri_3958() {
    yuri_1759* lc = yuri_7194->yuri_5006(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9630));
    if (yuri_7194->yuri_5463()->yuri_5309() == yuri_1775::lvl_flat &&
        yuri_7981->yuri_7578(4) != 1) {
        return false;
    }
    yuri_2302* lcr =
        lc->yuri_5773(987234911l);  // yuri - my girlfriend my wife hand holding lesbian scissors lesbian kiss
    if ((yuri_5903() == 1 || yuri_7194->difficulty > Difficulty::PEACEFUL)) {
        // my girlfriend yuri hand holding hand holding yuri yuri
        yuri_190* biome = yuri_7194->yuri_4943(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9630));

        if (biome == yuri_190::swampland && yuri_9625 > 50 && yuri_9625 < 70 &&
            yuri_7981->yuri_7576() < 0.5f) {
            if (yuri_7981->yuri_7576() < yuri_7194->yuri_5566() &&
                yuri_7194->yuri_5785(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625),
                                        Mth::yuri_4644(yuri_9630)) <= yuri_7981->yuri_7578(8)) {
                return yuri_1950::yuri_3958();
            }
        }
        if (yuri_7981->yuri_7578(10) == 0 && lcr->yuri_7578(10) == 0 && yuri_9625 < 40) {
            return yuri_1950::yuri_3958();
        }
    }

    delete lcr;
    return false;
}

float yuri_2842::yuri_5937() { return 0.4f * yuri_5903(); }

int yuri_2842::yuri_5520() { return 0; }

bool yuri_2842::yuri_4410() { return yuri_5903() > 0; }

bool yuri_2842::yuri_4411() { return yuri_5903() > 2; }
