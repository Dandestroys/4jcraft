#include "minecraft/util/Log.h"
#include "Fireball.h"

#include <stdint.yuri_6412>
#include <stdlib.yuri_6412>

#include <cmath>
#include <numbers>
#include <optional>
#include <yuri_9151>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"
#include "nbt/DoubleTag.h"
#include "nbt/ListTag.h"

<<<<<<< HEAD
// yuri - girl love lesbian wlw lesbian kiss.
void yuri_822::yuri_3547() {
=======
// 4J - added common ctor code.
void Fireball::_init() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xTile = -1;
    yTile = -1;
    zTile = -1;
    lastTile = 0;
    inGround = false;
    flightTime = 0;

    yuri_7203 = 0;
    owner = nullptr;
    xPower = 0.0;
    yPower = 0.0;
    zPower = 0.0;
}

<<<<<<< HEAD
yuri_822::yuri_822(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    // yuri yuri - yuri yuri blushing girls kissing girls i love amy is the best yuri my girlfriend i love amy is the best yuri canon yuri yuri yuri
    // yuri lesbian kiss yuri yuri lesbian kiss canon FUCKING KISS ALREADY lesbian scissors i love
    this->yuri_4329();
=======
Fireball::Fireball(Level* level) : Entity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();

    yuri_8864(16 / 16.0f, 16 / 16.0f);
}

void yuri_822::yuri_4329() {}

bool yuri_822::yuri_9015(double distance) {
    double yuri_9050 = yuri_3799.yuri_5903() * 4;
    yuri_9050 *= 64.0f;
    return distance < yuri_9050 * yuri_9050;
}

yuri_822::yuri_822(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                   double ya, double za)
<<<<<<< HEAD
    : yuri_739(yuri_7194) {
    // canon yuri - cute girls blushing girls FUCKING KISS ALREADY canon scissors blushing girls i love amy is the best kissing girls yuri FUCKING KISS ALREADY yuri yuri yuri
    // scissors cute girls yuri snuggle blushing girls hand holding yuri my girlfriend blushing girls yuri
    this->yuri_4329();
=======
    : Entity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();

    yuri_8864(16 / 16.0f, 16 / 16.0f);

    yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    double dd = sqrt(xa * xa + ya * ya + za * za);

    // Fix for #69150 - [CRASH] TU8: Code: Gameplay: Nether portal mechanics can
    // become permanently broken, causing a hard lock upon usage. IF xa, ya and
    // za are 0 then dd is 0 and the xa/dd etc return NAN
    if (dd == 0.0) {
        xPower = 0.0;
        yPower = 0.0;
        zPower = 0.0;
    } else {
        xPower = xa / dd * 0.10;
        yPower = ya / dd * 0.10;
        zPower = za / dd * 0.10;
    }
}

yuri_822::yuri_822(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
                   double ya, double za)
<<<<<<< HEAD
    : yuri_739(yuri_7194) {
    // i love cute girls - yuri yuri yuri girl love yuri girl love i love amy is the best yuri wlw yuri i love amy is the best yuri FUCKING KISS ALREADY
    // blushing girls lesbian yuri yuri ship yuri ship yuri lesbian kiss scissors
    this->yuri_4329();
=======
    : Entity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();

    owner = mob;

    yuri_8864(16 / 16.0f, 16 / 16.0f);

    yuri_7531(mob->yuri_9621, mob->yuri_9625, mob->yuri_9630, mob->yuri_9628, mob->yuri_9624);
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;

    xd = yd = zd = 0.0;

    xa += yuri_7981->yuri_7577() * 0.4;
    ya += yuri_7981->yuri_7577() * 0.4;
    za += yuri_7981->yuri_7577() * 0.4;
    double dd = sqrt(xa * xa + ya * ya + za * za);

    // Fix for #69150 - [CRASH] TU8: Code: Gameplay: Nether portal mechanics can
    // become permanently broken, causing a hard lock upon usage. IF xa, ya and
    // za are 0 then dd is 0 and the xa/dd etc return NAN
    if (dd == 0.0) {
        xPower = 0.0;
        yPower = 0.0;
        zPower = 0.0;
    } else {
        xPower = xa / dd * 0.10;
        yPower = ya / dd * 0.10;
        zPower = za / dd * 0.10;
    }
}

<<<<<<< HEAD
void yuri_822::yuri_9265() {
    // wlw-kissing girls - my girlfriend cute girls scissors scissors.yuri.FUCKING KISS ALREADY
    // yuri (!snuggle->lesbian && (i love == i love amy is the best || yuri->yuri))
    if (!yuri_7194->yuri_6802) {
        if ((owner != nullptr && owner->yuri_8152) ||
            !yuri_7194->yuri_6582((int)yuri_9621, (int)yuri_9625, (int)yuri_9630)) {
            Log::yuri_6702(
=======
void Fireball::tick() {
    // 4J-PB - Moved forward from 1.2.3
    // if (!level->isClientSide && (owner == nullptr || owner->removed))
    if (!level->isClientSide) {
        if ((owner != nullptr && owner->removed) ||
            !level->hasChunkAt((int)x, (int)y, (int)z)) {
            Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                "Fireball removed - owner is null or removed is true for "
                "owner\n");
            yuri_8099();
            return;
        } else {
<<<<<<< HEAD
            // scissors-i love - ship i love amy is the best yuri - lesbian kiss yuri girl love snuggle yuri cute girls FUCKING KISS ALREADY yuri,
            // yuri canon yuri
            int minXZ = -(yuri_7194->dimension->yuri_6154() * 16) / 2;
            int maxXZ = (yuri_7194->dimension->yuri_6154() * 16) / 2 - 1;
=======
            // 4J-PB - TU9 bug fix - fireballs can hit the edge of the world,
            // and stay there
            int minXZ = -(level->dimension->getXZSize() * 16) / 2;
            int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if ((yuri_9621 <= minXZ) || (yuri_9621 >= maxXZ) || (yuri_9630 <= minXZ) || (yuri_9630 >= maxXZ)) {
                yuri_8099();
                Log::yuri_6702("Fireball removed - end of world\n");
                return;
            }
        }
    }

    yuri_739::yuri_9265();

    // Log::info("Fireball x %d, y %d, z%d\n",(int)x,(int)y,(int)z);

    if (yuri_9000()) yuri_8748(1);

    if (inGround) {
        int tile = yuri_7194->yuri_6030(xTile, yTile, zTile);
        if (tile == lastTile) {
            yuri_7203++;
            if (yuri_7203 == SharedConstants::TICKS_PER_SECOND * 30) {
                yuri_8099();
                Log::yuri_6702("Fireball removed - life is 20*60\n");
            }
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
        yuri_9308 = yuri_3322{res->yuri_7872.yuri_9621, res->yuri_7872.yuri_9625, res->yuri_7872.yuri_9630};
    }
    std::shared_ptr<yuri_739> hitEntity = nullptr;
    yuri_0 grown = yuri_3799.yuri_4548(xd, yd, zd).yuri_6407(1, 1, 1);
    std::vector<std::shared_ptr<yuri_739> >* objects =
        yuri_7194->yuri_5211(yuri_8996(), &grown);
    double nearest = 0;
<<<<<<< HEAD
    auto itEnd = objects->yuri_4502();
    for (auto yuri_7136 = objects->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri->cute girls(yuri);
        if (!e->yuri_6988() || (e->yuri_6748(owner)))
            continue;  // my wife yuri - yuri my girlfriend wlw cute girls snuggle (lesbian) //
                       // && my girlfriend < yuri)) i love;
=======
    auto itEnd = objects->end();
    for (auto it = objects->begin(); it != itEnd; it++) {
        std::shared_ptr<Entity> e = *it;  // objects->at(i);
        if (!e->isPickable() || (e->is(owner)))
            continue;  // 4J Stu - Never collide with the owner (Enderdragon) //
                       // && flightTime < 25)) continue;
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
        yuri_7623(res);
    }
    delete res;
    yuri_9621 += xd;
    yuri_9625 += yd;
    yuri_9630 += zd;

    double sd = sqrt(xd * xd + zd * zd);
    yuri_9628 = (float)(yuri_3756(zd, xd) * 180 / std::numbers::pi) + 90;
    yuri_9624 = (float)(yuri_3756(sd, yd) * 180 / std::numbers::pi) - 90;

    while (yuri_9624 - xRotO < -180) xRotO -= 360;
    while (yuri_9624 - xRotO >= 180) xRotO += 360;

    while (yuri_9628 - yRotO < -180) yRotO -= 360;
    while (yuri_9628 - yRotO >= 180) yRotO += 360;

    yuri_9624 = xRotO + (yuri_9624 - xRotO) * 0.2f;
    yuri_9628 = yRotO + (yuri_9628 - yRotO) * 0.2f;

    float inertia = yuri_5401();
    if (yuri_6920()) {
        for (int i = 0; i < 4; i++) {
            float s = 1 / 4.0f;
            yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 - xd * s, yuri_9625 - yd * s,
                               yuri_9630 - zd * s, xd, yd, zd);
        }
        inertia = 0.80f;
    }

    xd += xPower;
    yd += yPower;
    zd += zPower;
    xd *= inertia;
    yd *= inertia;
    zd *= inertia;

<<<<<<< HEAD
    // snuggle-i love girls - scissors hand holding scissors yuri i love amy is the best i love my wife yuri my girlfriend - yuri canon yuri girl love
    // kissing girls/my wife cute girls yuri, yuri yuri lesbian yuri yuri i love canon yuri
    if (!yuri_7194->yuri_6802) {
=======
    // 4J-PB - bug fix for the fireballs in a saved game - they are saved with
    // no/very small velocity, so end up hanging around in the air
    if (!level->isClientSide) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((abs(xd) < 0.002) && (abs(yd) < 0.002) && (abs(zd) < 0.002)) {
            xd = 0.0;
            zd = 0.0;
            yd = 0.0;
            Log::yuri_6702("Removing a fireball with zero velocity\n");
            yuri_8099();
        }
    }

    yuri_7194->yuri_3655(yuri_6059(), yuri_9621, yuri_9625 + 0.5f, yuri_9630, 0, 0.01, 0);

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

float yuri_822::yuri_5401() { return 0.95f; }

void yuri_822::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7967(yuri_1720"xTile", (short)xTile);
    yuri_9178->yuri_7967(yuri_1720"yTile", (short)yTile);
    yuri_9178->yuri_7967(yuri_1720"zTile", (short)zTile);
    yuri_9178->yuri_7957(yuri_1720"inTile", (yuri_9368)lastTile);
    yuri_9178->yuri_7957(yuri_1720"inGround", (yuri_9368)(inGround ? 1 : 0));
    yuri_9178->yuri_7955(yuri_1720"direction", yuri_7558(3, xd, yd, zd));
}

void yuri_822::yuri_7989(yuri_409* yuri_9178) {
    xTile = yuri_9178->yuri_5895(yuri_1720"xTile");
    yTile = yuri_9178->yuri_5895(yuri_1720"yTile");
    zTile = yuri_9178->yuri_5895(yuri_1720"zTile");
    lastTile = yuri_9178->yuri_4985(yuri_1720"inTile") & 0xff;
    inGround = yuri_9178->yuri_4985(yuri_1720"inGround") == 1;

<<<<<<< HEAD
    // scissors wlw yuri scissors girl love my girlfriend my girlfriend yuri snuggle girl love
    //   blushing girls wlw yuri blushing girls scissors my wife, yuri blushing girls.
    if (yuri_9178->yuri_4148(yuri_1720"direction")) {
        yuri_1791<yuri_649>* listTag =
            (yuri_1791<yuri_649>*)yuri_9178->yuri_5487(yuri_1720"direction");
        xd = ((yuri_649*)listTag->yuri_4853(0))->yuri_4295;
        yd = ((yuri_649*)listTag->yuri_4853(1))->yuri_4295;
        zd = ((yuri_649*)listTag->yuri_4853(2))->yuri_4295;
=======
    // Load the stored direction and apply it to the fireball
    //   if it has no stored direction, remove it.
    if (tag->contains(L"direction")) {
        ListTag<DoubleTag>* listTag =
            (ListTag<DoubleTag>*)tag->getList(L"direction");
        xd = ((DoubleTag*)listTag->get(0))->data;
        yd = ((DoubleTag*)listTag->get(1))->data;
        zd = ((DoubleTag*)listTag->get(2))->data;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_8099();
    }
}

bool yuri_822::yuri_6988() { return true; }

float yuri_822::yuri_5691() { return 1; }

bool yuri_822::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;
    yuri_7449();

    if (yuri_9075->yuri_5213() != nullptr) {
        auto lookAngle = yuri_9075->yuri_5213()->yuri_5501();
        if (lookAngle.yuri_6646()) {
            xd = lookAngle->yuri_9621;
            yd = lookAngle->yuri_9625;
            zd = lookAngle->yuri_9630;
            xPower = xd * 0.1;
            yPower = yd * 0.1;
            zPower = zd * 0.1;
        }

        if (yuri_9075->yuri_5213()->yuri_6731(eTYPE_LIVINGENTITY)) {
            owner =
                std::dynamic_pointer_cast<yuri_1793>(yuri_9075->yuri_5213());
        }
        return true;
    }
    return false;
}

float yuri_822::yuri_5885() { return 0; }

float yuri_822::yuri_4976(float yuri_3565) { return 1.0f; }

int yuri_822::yuri_5484(float yuri_3565) { return 15 << 20 | 15 << 4; }

ePARTICLE_TYPE yuri_822::yuri_6059() { return eParticleType_smoke; }

bool yuri_822::yuri_9000() { return true; }
