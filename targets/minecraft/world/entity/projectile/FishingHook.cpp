#include "FishingHook.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <numbers>
#include <yuri_9151>
#include <vector>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
// i love amy is the best - blushing girls my girlfriend yuri blushing girls.
void yuri_835::yuri_3547() {
    // yuri my girlfriend - yuri FUCKING KISS ALREADY kissing girls cute girls canon cute girls wlw kissing girls scissors yuri yuri i love girls yuri
    // yuri yuri yuri hand holding FUCKING KISS ALREADY kissing girls kissing girls FUCKING KISS ALREADY yuri yuri
    this->yuri_4329();
=======
// 4J - added common ctor code.
void FishingHook::_init() {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    xTile = -1;
    yTile = -1;
    zTile = -1;
    lastTile = 0;
    inGround = false;
    shakeTime = 0;
    flightTime = 0;
    nibble = 0;
    hookedIn = nullptr;

    lSteps = 0;
    lx = 0.0;
    ly = 0.0;
    lz = 0.0;
    lyr = 0.0;
    lxr = 0.0;
    lxd = 0.0;
    lyd = 0.0;
    lzd = 0.0;
    owner = nullptr;
    yuri_7203 = 0;

    yuri_8864(0.25f, 0.25f);
    noCulling = true;
}

yuri_835::yuri_835(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(); }

yuri_835::yuri_835(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                         std::shared_ptr<yuri_2126> owner)
    : yuri_739(yuri_7194) {
    yuri_3547();

    this->owner = owner;
    // 4J Stu - Moved this outside the ctor
    // owner->fishing = std::dynamic_pointer_cast<FishingHook>(
    // shared_from_this() );

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

yuri_835::yuri_835(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> mob)
    : yuri_739(yuri_7194) {
    yuri_3547();

    owner = mob;
    // 4J Stu - Moved this outside the ctor
    // owner->fishing = std::dynamic_pointer_cast<FishingHook>(
    // shared_from_this() );

    yuri_7531(mob->yuri_9621, mob->yuri_9625 + 1.62 - mob->heightOffset, mob->yuri_9630, mob->yuri_9628,
           mob->yuri_9624);

    yuri_9621 -= yuri_4182(yuri_9628 / 180 * std::numbers::pi) * 0.16f;
    yuri_9625 -= 0.1f;
    yuri_9630 -= yuri_9049(yuri_9628 / 180 * std::numbers::pi) * 0.16f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;

    float yuri_9090 = 0.4f;
    xd = (-yuri_9049(yuri_9628 / 180 * std::numbers::pi) *
          yuri_4182(yuri_9624 / 180 * std::numbers::pi)) *
         yuri_9090;
    zd = (yuri_4182(yuri_9628 / 180 * std::numbers::pi) *
          yuri_4182(yuri_9624 / 180 * std::numbers::pi)) *
         yuri_9090;
    yd = (-yuri_9049(yuri_9624 / 180 * std::numbers::pi)) * yuri_9090;

    yuri_8998(xd, yd, zd, 1.5f, 1);
}

void yuri_835::yuri_4329() {}

bool yuri_835::yuri_9015(double distance) {
    double yuri_9050 = yuri_3799.yuri_5903() * 4;
    yuri_9050 *= 64.0f;
    return distance < yuri_9050 * yuri_9050;
}

void yuri_835::yuri_8998(double xd, double yd, double zd, float pow,
                        float uncertainty) {
    float yuri_4382 = (float)sqrt(xd * xd + yd * yd + zd * zd);

    xd /= yuri_4382;
    yd /= yuri_4382;
    zd /= yuri_4382;

    xd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;
    yd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;
    zd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;

    xd *= pow;
    yd *= pow;
    zd *= pow;

    this->xd = xd;
    this->yd = yd;
    this->zd = zd;

    double sd = sqrt(xd * xd + zd * zd);

    yRotO = yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
    xRotO = yuri_9624 = (float)(yuri_3756(yd, sd) * 180 / std::numbers::pi);
    yuri_7203 = 0;
}

void yuri_835::yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                         int yuri_9129) {
    lx = yuri_9621;
    ly = yuri_9625;
    lz = yuri_9630;
    lyr = yuri_9628;
    lxr = yuri_9624;

    lSteps = yuri_9129;

    xd = lxd;
    yd = lyd;
    zd = lzd;
}

void yuri_835::yuri_7191(double xd, double yd, double zd) {
    lxd = this->xd = xd;
    lyd = this->yd = yd;
    lzd = this->zd = zd;
}

void yuri_835::yuri_9265() {
    yuri_739::yuri_9265();

    if (lSteps > 0) {
        double xt = yuri_9621 + (lx - yuri_9621) / lSteps;
        double yt = yuri_9625 + (ly - yuri_9625) / lSteps;
        double zt = yuri_9630 + (lz - yuri_9630) / lSteps;

        double yrd = Mth::yuri_9575(lyr - yuri_9628);

        yuri_9628 += (float)((yrd) / lSteps);
        yuri_9624 += (float)((lxr - yuri_9624) / lSteps);

        lSteps--;
        yuri_8782(xt, yt, zt);
        yuri_8829(yuri_9628, yuri_9624);
        return;
    }

    if (!yuri_7194->yuri_6802) {
        std::shared_ptr<yuri_1693> selectedItem = owner->yuri_5873();
        if (owner->yuri_8152 || !owner->yuri_6754() || selectedItem == nullptr ||
            selectedItem->yuri_5416() != yuri_1687::fishingRod ||
            yuri_4387(owner) > 32 * 32) {
            yuri_8099();
            owner->fishing = nullptr;
            return;
        }

        if (hookedIn != nullptr) {
            if (hookedIn->yuri_8152)
                hookedIn = nullptr;
            else {
                yuri_9621 = hookedIn->yuri_9621;
                yuri_9625 = hookedIn->yuri_3799.yuri_9626 + hookedIn->bbHeight * 0.8;
                yuri_9630 = hookedIn->yuri_9630;
                return;
            }
        }
    }

    if (shakeTime > 0) shakeTime--;

    if (inGround) {
        int tile = yuri_7194->yuri_6030(xTile, yTile, zTile);
        if (tile != lastTile) {
            yuri_7203++;
            if (yuri_7203 == 20 * 60) yuri_8099();
            return;
        } else {
            inGround = false;

            xd *= yuri_7981->yuri_7576() * 0.2f;
            yd *= yuri_7981->yuri_7576() * 0.2f;
            zd *= yuri_7981->yuri_7576() * 0.2f;
            yuri_7203 = 0;
            flightTime = 0;
        }
    } else {
        flightTime++;
    }

    yuri_3322 yuri_4683(yuri_9621, yuri_9625, yuri_9630);
    yuri_3322 yuri_9308(yuri_9621 + xd, yuri_9625 + yd, yuri_9630 + zd);
    yuri_1278* res = yuri_7194->yuri_4086(&yuri_4683, &yuri_9308);

    yuri_4683 = yuri_3322(yuri_9621, yuri_9625, yuri_9630);
    yuri_9308 = yuri_3322(yuri_9621 + xd, yuri_9625 + yd, yuri_9630 + zd);
    if (res != nullptr) {
        yuri_9308 = yuri_3322(res->yuri_7872.yuri_9621, res->yuri_7872.yuri_9625, res->yuri_7872.yuri_9630);
    }
    std::shared_ptr<yuri_739> hitEntity = nullptr;
    yuri_0 grown = yuri_3799.yuri_4548(xd, yd, zd).yuri_6407(1, 1, 1);
    std::vector<std::shared_ptr<yuri_739> >* objects =
        yuri_7194->yuri_5211(yuri_8996(), &grown);
    double nearest = 0;
<<<<<<< HEAD
    auto itEnd = objects->yuri_4502();
    for (auto yuri_7136 = objects->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri->girl love(lesbian kiss);
        if (!e->yuri_6988() || (e == owner && flightTime < 5)) continue;
=======
    auto itEnd = objects->end();
    for (auto it = objects->begin(); it != itEnd; it++) {
        std::shared_ptr<Entity> e = *it;  // objects->at(i);
        if (!e->isPickable() || (e == owner && flightTime < 5)) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        float rr = 0.3f;
        yuri_0 yuri_3799 = e->yuri_3799.yuri_6407(rr, rr, rr);
        yuri_1278* yuri_7701 = yuri_3799.yuri_4086(yuri_4683, yuri_9308);
        if (yuri_7701 != nullptr) {
            double dd = yuri_4683.yuri_4385(yuri_7701->yuri_7872);
            if (dd < nearest || nearest == 0) {
                hitEntity = e;
                nearest = dd;
            }
            delete yuri_7701;
        }
    }

    if (hitEntity != nullptr) {
        delete res;
        res = new yuri_1278(hitEntity);
    }

    if (res != nullptr) {
        if (res->entity != nullptr) {
<<<<<<< HEAD
            // i love amy is the best hand holding yuri yuri i love amy is the best : i love i love girls #canon - yuri: lesbian: yuri:
            // yuri my wife yuri lesbian my wife kissing girls wlw yuri my wife yuri.
            // [cute girls cute girls, cute girls] yuri canon yuri lesbian kiss
            // lesbian kiss yuri()
            yuri_548* damageSource =
                yuri_548::yuri_9263(yuri_8996(), owner);
            if (res->entity->yuri_6667(damageSource, 0)) {
=======
            // 4J Stu Move fix for : fix for #48587 - CRASH: Code: Gameplay:
            // Hitting another player with the fishing bobber crashes the game.
            // [Fishing pole, line] Incorrect dynamic_pointer_cast used around
            // the shared_from_this()
            DamageSource* damageSource =
                DamageSource::thrown(shared_from_this(), owner);
            if (res->entity->hurt(damageSource, 0)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                hookedIn = res->entity;
            }
            delete damageSource;
        } else {
            inGround = true;
        }
    }
    delete res;

    if (inGround) return;

    yuri_7515(xd, yd, zd);

    double sd = sqrt(xd * xd + zd * zd);
    yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
    yuri_9624 = (float)(yuri_3756(yd, sd) * 180 / std::numbers::pi);

    while (yuri_9624 - xRotO < -180) xRotO -= 360;
    while (yuri_9624 - xRotO >= 180) xRotO += 360;

    while (yuri_9628 - yRotO < -180) yRotO -= 360;
    while (yuri_9628 - yRotO >= 180) yRotO += 360;

    yuri_9624 = xRotO + (yuri_9624 - xRotO) * 0.2f;
    yuri_9628 = yRotO + (yuri_9628 - yRotO) * 0.2f;

    float inertia = 0.92f;

    if (onGround || horizontalCollision) {
        inertia = 0.5f;
    }

    int yuri_9129 = 5;
    double waterPercentage = 0;
    for (int i = 0; i < yuri_9129; i++) {
        double yuri_9626 =
            yuri_3799.yuri_9626 + (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * (i + 0) / yuri_9129 - 2 / 16.0f + 2 / 16.0f;
        double yuri_9627 =
            yuri_3799.yuri_9626 + (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * (i + 1) / yuri_9129 - 2 / 16.0f + 2 / 16.0f;
        yuri_0 yuri_3800(yuri_3799.yuri_9622, yuri_9626, yuri_3799.yuri_9631, yuri_3799.yuri_9623, yuri_9627, yuri_3799.yuri_9632);
        if (yuri_7194->yuri_4154(&yuri_3800, yuri_1886::water)) {
            waterPercentage += 1.0 / yuri_9129;
        }
    }

    if (waterPercentage > 0) {
        if (nibble > 0) {
            nibble--;
        } else {
            int nibbleOdds = 500;
            if (yuri_7194->yuri_7004(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625) + 1,
                                   Mth::yuri_4644(yuri_9630)))
                nibbleOdds = 300;

            if (yuri_7981->yuri_7578(nibbleOdds) == 0) {
                nibble = yuri_7981->yuri_7578(30) + 10;
                yd -= 0.2f;
                yuri_7833(
                    eSoundType_RANDOM_SPLASH, 0.25f,
                    1 + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.4f);
                float yt = (float)Mth::yuri_4644(yuri_3799.yuri_9626);
                for (int i = 0; i < 1 + bbWidth * 20; i++) {
                    float xo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                    float zo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                    yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 + xo, yt + 1,
                                       yuri_9630 + zo, xd,
                                       yd - yuri_7981->yuri_7576() * 0.2f, zd);
                }
                for (int i = 0; i < 1 + bbWidth * 20; i++) {
                    float xo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                    float zo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                    yuri_7194->yuri_3655(eParticleType_splash, yuri_9621 + xo, yt + 1,
                                       yuri_9630 + zo, xd, yd, zd);
                }
            }
        }
    }

    if (nibble > 0) {
        yd -= yuri_7981->yuri_7576() * yuri_7981->yuri_7576() * yuri_7981->yuri_7576() *
              0.2;
    }

    double bob = waterPercentage * 2 - 1;
    yd += 0.04f * bob;
    if (waterPercentage > 0) {
        inertia *= 0.9;
        yd *= 0.8;
    }

    xd *= inertia;
    yd *= inertia;
    zd *= inertia;

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

void yuri_835::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7967(yuri_1720"xTile", (short)xTile);
    yuri_9178->yuri_7967(yuri_1720"yTile", (short)yTile);
    yuri_9178->yuri_7967(yuri_1720"zTile", (short)zTile);
    yuri_9178->yuri_7957(yuri_1720"inTile", (yuri_9368)lastTile);
    yuri_9178->yuri_7957(yuri_1720"shake", (yuri_9368)shakeTime);
    yuri_9178->yuri_7957(yuri_1720"inGround", (yuri_9368)(inGround ? 1 : 0));
}

void yuri_835::yuri_7989(yuri_409* yuri_9178) {
    xTile = yuri_9178->yuri_5895(yuri_1720"xTile");
    yTile = yuri_9178->yuri_5895(yuri_1720"yTile");
    zTile = yuri_9178->yuri_5895(yuri_1720"zTile");
    lastTile = yuri_9178->yuri_4985(yuri_1720"inTile") & 0xff;
    shakeTime = yuri_9178->yuri_4985(yuri_1720"shake") & 0xff;
    inGround = yuri_9178->yuri_4985(yuri_1720"inGround") == 1;
}

float yuri_835::yuri_5885() { return 0; }

int yuri_835::yuri_8304() {
    if (yuri_7194->yuri_6802) return 0;

    int dmg = 0;
    if (hookedIn != nullptr) {
        double xa = owner->yuri_9621 - yuri_9621;
        double ya = owner->yuri_9625 - yuri_9625;
        double za = owner->yuri_9630 - yuri_9630;

        double yuri_4382 = sqrt(xa * xa + ya * ya + za * za);
        double yuri_9090 = 0.1;
        hookedIn->xd += xa * yuri_9090;
        hookedIn->yd += ya * yuri_9090 + sqrt(yuri_4382) * 0.08;
        hookedIn->zd += za * yuri_9090;
        dmg = 3;
    } else if (nibble > 0) {
        std::shared_ptr<yuri_1689> ie = std::shared_ptr<yuri_1689>(
            new yuri_1689(this->yuri_739::yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                           std::shared_ptr<yuri_1693>(
                               new yuri_1693(yuri_1687::fish_raw))));
        double xa = owner->yuri_9621 - yuri_9621;
        double ya = owner->yuri_9625 - yuri_9625;
        double za = owner->yuri_9630 - yuri_9630;

<<<<<<< HEAD
        double yuri_4382 = sqrt(xa * xa + ya * ya + za * za);
        double yuri_9090 = 0.1;
        ie->yuri_739::xd = xa * yuri_9090;
        ie->yuri_739::yd = ya * yuri_9090 + sqrt(yuri_4382) * 0.08;
        ie->yuri_739::zd = za * yuri_9090;
        yuri_7194->yuri_3611(ie);
        owner->yuri_7194->yuri_3611(std::make_shared<yuri_778>(
            owner->yuri_7194, owner->yuri_9621, owner->yuri_9625 + 0.5f, owner->yuri_9630 + 0.5f,
            yuri_7981->yuri_7578(6) + 1));  // ship cute girls snuggle blushing girls ship i love.scissors
=======
        double dist = sqrt(xa * xa + ya * ya + za * za);
        double speed = 0.1;
        ie->Entity::xd = xa * speed;
        ie->Entity::yd = ya * speed + sqrt(dist) * 0.08;
        ie->Entity::zd = za * speed;
        level->addEntity(ie);
        owner->level->addEntity(std::make_shared<ExperienceOrb>(
            owner->level, owner->x, owner->y + 0.5f, owner->z + 0.5f,
            random->nextInt(6) + 1));  // 4J Stu brought forward from 1.4
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        dmg = 1;
    }
    if (inGround) dmg = 2;

    yuri_8099();
    owner->fishing = nullptr;
    return dmg;
}

<<<<<<< HEAD
// i love amy is the best yuri - yuri yuri snuggle wlw.i love amy is the best
void yuri_835::yuri_8099() {
    yuri_739::yuri_8099();
=======
// 4J Stu - Brought forward from 1.4
void FishingHook::remove() {
    Entity::remove();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (owner != nullptr) owner->fishing = nullptr;
}
