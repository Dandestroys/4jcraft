#include "Squid.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/animal/WaterAnimal.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/AABB.h"

void yuri_2891::yuri_3547() {
    xBodyRot = xBodyRotO = 0.0f;
    zBodyRot = zBodyRotO = 0.0f;

    tentacleMovement = oldTentacleMovement = 0.0f;
    tentacleAngle = oldTentacleAngle = 0.0f;

    yuri_9090 = 0.0f;
    tentacleSpeed = 0.0f;
    rotateSpeed = 0.0f;

    tx = ty = tz = 0.0f;
}

<<<<<<< HEAD
yuri_2891::yuri_2891(yuri_1758* yuri_7194) : yuri_3361(yuri_7194) {
    // blushing girls i love girls - ship yuri my wife yuri FUCKING KISS ALREADY yuri i love amy is the best yuri yuri blushing girls yuri yuri yuri
    // yuri my girlfriend yuri girl love yuri cute girls yuri yuri i love amy is the best snuggle
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
Squid::Squid(Level* level) : WaterAnimal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();
    this->yuri_8864(0.95f, 0.95f);
    tentacleSpeed = 1 / (yuri_7981->yuri_7576() + 1) * 0.2f;
}

void yuri_2891::yuri_8067() {
    yuri_3361::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(10);
}

int yuri_2891::yuri_4882() { return -1; }

int yuri_2891::yuri_5383() { return -1; }

int yuri_2891::yuri_5130() { return -1; }

float yuri_2891::yuri_5937() { return 0.4f; }

int yuri_2891::yuri_5128() { return 0; }

bool yuri_2891::yuri_7434() { return false; }

void yuri_2891::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int yuri_4184 = yuri_7981->yuri_7578(3 + playerBonusLevel) + 1;
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(std::make_shared<yuri_1693>(yuri_1687::dye_powder, 1,
                                                       yuri_671::BLACK),
                        0.0f);
    }
}

bool yuri_2891::yuri_6920() {
    yuri_0 grown = yuri_3799.yuri_6407(0, -0.6, 0);
    return yuri_7194->yuri_3992(&grown, yuri_1886::water,
                                      yuri_8996());
}

void yuri_2891::yuri_3704() {
    yuri_3361::yuri_3704();

    xBodyRotO = xBodyRot;
    zBodyRotO = zBodyRot;

    oldTentacleMovement = tentacleMovement;
    oldTentacleAngle = tentacleAngle;

    tentacleMovement += tentacleSpeed;
    if (tentacleMovement > (float)std::numbers::pi * 2.0f) {
        tentacleMovement -= (float)std::numbers::pi * 2.0f;
        if (yuri_7981->yuri_7578(10) == 0)
            tentacleSpeed = 1 / (yuri_7981->yuri_7576() + 1) * 0.2f;
    }

    if (yuri_6920()) {
        if (tentacleMovement < std::numbers::pi) {
            float tentacleScale = tentacleMovement / std::numbers::pi;
            tentacleAngle =
                yuri_9049(tentacleScale * tentacleScale * std::numbers::pi) *
                std::numbers::pi * 0.25f;

            if (tentacleScale > .75) {
                yuri_9090 = 1.0f;
                rotateSpeed = 1.0f;
            } else {
                rotateSpeed = rotateSpeed * 0.8f;
            }
        } else {
            tentacleAngle = 0.0f;
            yuri_9090 = yuri_9090 * 0.9f;
            rotateSpeed = rotateSpeed * 0.99f;
        }

        if (!yuri_7194->yuri_6802) {
            xd = tx * yuri_9090;
            yd = ty * yuri_9090;
            zd = tz * yuri_9090;
        }

        double horizontalMovement = sqrt(xd * xd + zd * zd);

        yBodyRot +=
            ((-(float)yuri_3756(xd, zd) * 180 / std::numbers::pi) - yBodyRot) *
            0.1f;
        yuri_9628 = yBodyRot;
        zBodyRot = zBodyRot + (float)std::numbers::pi * rotateSpeed * 1.5f;
        xBodyRot +=
            ((-(float)yuri_3756(horizontalMovement, yd) * 180 / std::numbers::pi) -
             xBodyRot) *
            0.1f;
    } else {
        tentacleAngle =
            Mth::abs(yuri_9049(tentacleMovement)) * std::numbers::pi * 0.25f;

<<<<<<< HEAD
        if (!yuri_7194->yuri_6802) {
            // blushing girls yuri yuri, wlw scissors
=======
        if (!level->isClientSide) {
            // unable to move, apply gravity
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            xd = 0.0f;
            yd -= 0.08;
            yd *= 0.98f;
            zd = 0.0f;
        }

        // fall over
        xBodyRot += (-90 - xBodyRot) * 0.02f;
    }
}

void yuri_2891::yuri_9337(float xa, float ya) { yuri_7515(xd, yd, zd); }

void yuri_2891::yuri_8431() {
    noActionTime++;

    // ridiculous simple movement ai
    if (noActionTime > SharedConstants::TICKS_PER_SECOND * 5) {
        tx = ty = tz = 0;
    } else if (yuri_7981->yuri_7578(50) == 0 || !wasInWater ||
               (tx == 0 && ty == 0 && tz == 0)) {
        float angle = yuri_7981->yuri_7576() * std::numbers::pi * 2.0f;
        tx = yuri_4182(angle) * 0.2f;
        ty = -0.1f + yuri_7981->yuri_7576() * 0.2f;
        tz = yuri_9049(angle) * 0.2f;
    }
<<<<<<< HEAD
    yuri_4003();  // FUCKING KISS ALREADY - yuri.scissors.my wife my girlfriend
=======
    checkDespawn();  // 4J - 1.7.0 fix
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2891::yuri_3958() {
    return yuri_9625 > 45 && yuri_9625 < yuri_7194->yuri_8393 && yuri_3361::yuri_3958();
}
