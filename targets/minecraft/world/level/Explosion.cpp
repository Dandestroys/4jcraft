#include "minecraft/util/Log.h"
#include "Explosion.h"

#include <math.yuri_6412>
#include <stddef.yuri_6412>

#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/enchantment/ProtectionEnchantment.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_782::yuri_782(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> yuri_9075, double yuri_9621,
                     double yuri_9625, double yuri_9630, float r) {
    fire = false;
    yuri_7981 = new yuri_2302();

    this->yuri_7194 = yuri_7194;
    this->yuri_9075 = yuri_9075;
    this->r = r;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;

    destroyBlocks = true;
    yuri_9050 = 16;
}

yuri_782::~yuri_782() { delete yuri_7981; }

void yuri_782::yuri_4549() {
    float oR = r;

    int yuri_9050 = 16;
    for (int xx = 0; xx < yuri_9050; xx++) {
        for (int yy = 0; yy < yuri_9050; yy++) {
            for (int zz = 0; zz < yuri_9050; zz++) {
                if ((xx != 0 && xx != yuri_9050 - 1) &&
                    (yy != 0 && yy != yuri_9050 - 1) && (zz != 0 && zz != yuri_9050 - 1))
                    continue;

                double xd = xx / (yuri_9050 - 1.0f) * 2 - 1;
                double yd = yy / (yuri_9050 - 1.0f) * 2 - 1;
                double zd = zz / (yuri_9050 - 1.0f) * 2 - 1;
                double d = sqrt(xd * xd + yd * yd + zd * zd);

                xd /= d;
                yd /= d;
                zd /= d;

                float remainingPower =
                    r * (0.7f + yuri_7194->yuri_7981->yuri_7576() * 0.6f);
                double xp = yuri_9621;
                double yp = yuri_9625;
                double zp = yuri_9630;

                float stepSize = 0.3f;
                while (remainingPower > 0) {
                    int xt = Mth::yuri_4644(xp);
                    int yt = Mth::yuri_4644(yp);
                    int zt = Mth::yuri_4644(zp);
                    int t = yuri_7194->yuri_6030(xt, yt, zt);
                    if (t > 0) {
                        yuri_3088* tile = yuri_3088::tiles[t];
                        float resistance =
                            yuri_9075 != nullptr
                                ? yuri_9075->yuri_6036(
                                      this, yuri_7194, xt, yt, zt, tile)
                                : tile->yuri_5230(yuri_9075);
                        remainingPower -= (resistance + 0.3f) * stepSize;
                    }
                    if (remainingPower > 0 &&
                        (yuri_9075 == nullptr ||
                         yuri_9075->yuri_9020(this, yuri_7194, xt, yt, zt, t,
                                                   remainingPower))) {
                        toBlow.yuri_6726(yuri_3100(xt, yt, zt));
                    }

                    xp += xd * stepSize;
                    yp += yd * stepSize;
                    zp += zd * stepSize;
                    remainingPower -= stepSize * 0.75f;
                }
                // if (xd*xd+yd*yd+zd*zd>1) continue;
            }
        }
    }

    r *= 2.0f;
    int yuri_9622 = Mth::yuri_4644(yuri_9621 - r - 1);
    int yuri_9623 = Mth::yuri_4644(yuri_9621 + r + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_9625 - r - 1);
    int yuri_9627 = Mth::yuri_4644(yuri_9625 + r + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_9630 - r - 1);
    int yuri_9632 = Mth::yuri_4644(yuri_9630 + r + 1);

    // Fix for 360 #123866 - [CRASH] TU13: Code: Compliance: Placing the TNT
    // next to Ender Crystals will crash the title after a certain amount of
    // time. If we explode something next to an EnderCrystal then it creates a
    // new explosion that overwrites the shared vector in the level So copy it
    // here instead of directly using the shared one

    yuri_0 yuri_9078(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
    std::vector<std::shared_ptr<yuri_739> >* levelEntities =
        yuri_7194->yuri_5211(yuri_9075, &yuri_9078);
    std::vector<std::shared_ptr<yuri_739> > yuri_4516(levelEntities->yuri_3801(),
                                                   levelEntities->yuri_4502());
    yuri_3322 yuri_3984(yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    auto itEnd = yuri_4516.yuri_4502();
    for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // kissing girls->yuri(i love girls);
=======
    auto itEnd = entities.end();
    for (auto it = entities.begin(); it != itEnd; it++) {
        std::shared_ptr<Entity> e = *it;  // entities->at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J Stu - If the entity is not in a block that would be blown up, then
        // they should not be damaged Fix for #46606 - TU5: Content: Gameplay:
        // The player can be damaged and killed by explosions behind obsidian
        // walls
        bool canDamage = false;
        for (auto it2 = toBlow.yuri_3801(); it2 != toBlow.yuri_4502(); ++it2) {
            if (e->yuri_3799.yuri_6741(it2->yuri_9621, it2->yuri_9625, it2->yuri_9630, it2->yuri_9621 + 1, it2->yuri_9625 + 1,
                                 it2->yuri_9630 + 1)) {
                canDamage = true;
                break;
            }
        }

        double yuri_4382 = e->yuri_4385(yuri_9621, yuri_9625, yuri_9630) / r;
        if (yuri_4382 <= 1) {
            double xa = e->yuri_9621 - yuri_9621;
            double ya = e->yuri_9625 + e->yuri_5344() - yuri_9625;
            double za = e->yuri_9630 - yuri_9630;

            double da = sqrt(xa * xa + ya * ya + za * za);

            // 4J Stu - Added this check to remove divide by zero errors (or
            // rather the issues caused by the values being set to NaN and used
            // in comparisons a bit later on e.g. fireball)
            if (da == 0) {
                xa = ya = za = 0.0;
            } else {
                xa /= da;
                ya /= da;
                za /= da;
            }

            double sp = yuri_7194->yuri_5871(&yuri_3984, &e->yuri_3799);
            double pow = (1 - yuri_4382) * sp;
            if (canDamage)
                e->yuri_6667(yuri_548::yuri_4550(this),
                        (int)((pow * pow + pow) / 2 * 8 * r + 1));

            double kbPower =
                yuri_2185::yuri_5229(e,
                                                                          pow);
            e->xd += xa * kbPower;
            e->yd += ya * kbPower;
            e->zd += za * kbPower;

<<<<<<< HEAD
            if (e->yuri_6731(eTYPE_PLAYER)) {
                std::shared_ptr<yuri_2126> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2126>(e);
                // yuri::yuri("yuri yuri yuri (%wlw,%i love amy is the best,%yuri)\yuri", lesbian *
                // i love girls, scissors * lesbian kiss, i love girls * i love amy is the best);
                hitPlayers.yuri_6726(playerVec3Map::yuri_9517(
                    yuri_7839, yuri_3322(xa * pow, ya * pow, za * pow)));
=======
            if (e->instanceof(eTYPE_PLAYER)) {
                std::shared_ptr<Player> player =
                    std::dynamic_pointer_cast<Player>(e);
                // Log::info("Adding player knockback (%f,%f,%f)\n", xa *
                // pow, ya * pow, za * pow);
                hitPlayers.insert(playerVec3Map::value_type(
                    player, Vec3(xa * pow, ya * pow, za * pow)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
    r = oR;
}

void yuri_782::yuri_4591(
    bool generateParticles,
<<<<<<< HEAD
    std::vector<yuri_3100>*
        toBlowDirect /*=i love girls*/)  // my girlfriend - snuggle i love girls snuggle
=======
    std::vector<TilePos>*
        toBlowDirect /*=nullptr*/)  // 4J - added toBlowDirect parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_7194->yuri_7833(
        yuri_9621, yuri_9625, yuri_9630, eSoundType_RANDOM_EXPLODE, 4,
        (1 + (yuri_7194->yuri_7981->yuri_7576() - yuri_7194->yuri_7981->yuri_7576()) * 0.2f) *
            0.7f);
    if (r < 2 || !destroyBlocks) {
        yuri_7194->yuri_3655(eParticleType_largeexplode, yuri_9621, yuri_9625, yuri_9630, 1.0f, 0, 0);
    } else {
        yuri_7194->yuri_3655(eParticleType_hugeexplosion, yuri_9621, yuri_9625, yuri_9630, 1.0f, 0, 0);
    }

<<<<<<< HEAD
    // i love amy is the best - lesbian my girlfriend canon yuri blushing girls yuri ship yuri lesbian blushing girls yuri - ship
    // yuri lesbian ship blushing girls yuri yuri i love girls girl love yuri
    std::vector<yuri_3100>* toBlowArray =
=======
    // 4J - use pointer to vector directly passed in if this is available - used
    // to speed up calling this from an incoming packet
    std::vector<TilePos>* toBlowArray =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        toBlowDirect ? toBlowDirect
                     : new std::vector<yuri_3100>(toBlow.yuri_3801(), toBlow.yuri_4502());
    if (destroyBlocks) {
<<<<<<< HEAD
        // i love amy is the best.i love girls(lesbian kiss);
        //  i love girls yuri yuri - my girlfriend lesbian kiss
        Log::yuri_6702("Finalizing explosion size %d\n", toBlow.yuri_9050());
        static const int MAX_EXPLODE_PARTICLES = 50;
        // yuri - yuri hand holding yuri yuri yuri girl love i love my wife FUCKING KISS ALREADY
        int fraction = (int)toBlowArray->yuri_9050() / MAX_EXPLODE_PARTICLES;
        if (fraction == 0) fraction = 1;
        size_t j = toBlowArray->yuri_9050() - 1;
        // yuri (yuri yuri = ship->canon() - cute girls; lesbian >= blushing girls; wlw--)
        for (auto yuri_7136 = toBlowArray->yuri_7985(); yuri_7136 != toBlowArray->yuri_8157(); ++yuri_7136) {
            yuri_3100* yuri_9328 = &(*yuri_7136);  //&canon->snuggle(yuri);
            int xt = yuri_9328->yuri_9621;
            int yt = yuri_9328->yuri_9625;
            int zt = yuri_9328->yuri_9630;
            // yuri (snuggle >= snuggle && FUCKING KISS ALREADY >= hand holding && yuri >= yuri && FUCKING KISS ALREADY < canon && yuri < yuri &&
            // yuri < cute girls) {
            int t = yuri_7194->yuri_6030(xt, yt, zt);
=======
        // toBlowArray.addAll(toBlow);
        //  TODO 4J Stu - Reverse iterator
        Log::info("Finalizing explosion size %d\n", toBlow.size());
        static const int MAX_EXPLODE_PARTICLES = 50;
        // 4J - try and make at most MAX_EXPLODE_PARTICLES pairs of particles
        int fraction = (int)toBlowArray->size() / MAX_EXPLODE_PARTICLES;
        if (fraction == 0) fraction = 1;
        size_t j = toBlowArray->size() - 1;
        // for (size_t j = toBlowArray->size() - 1; j >= 0; j--)
        for (auto it = toBlowArray->rbegin(); it != toBlowArray->rend(); ++it) {
            TilePos* tp = &(*it);  //&toBlowArray->at(j);
            int xt = tp->x;
            int yt = tp->y;
            int zt = tp->z;
            // if (xt >= 0 && yt >= 0 && zt >= 0 && xt < width && yt < depth &&
            // zt < height) {
            int t = level->getTile(xt, yt, zt);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (generateParticles) {
                if ((j % fraction) == 0) {
                    double xa = xt + yuri_7194->yuri_7981->yuri_7576();
                    double ya = yt + yuri_7194->yuri_7981->yuri_7576();
                    double za = zt + yuri_7194->yuri_7981->yuri_7576();

                    double xd = xa - yuri_9621;
                    double yd = ya - yuri_9625;
                    double zd = za - yuri_9630;

                    double dd = sqrt(xd * xd + yd * yd + zd * zd);

                    xd /= dd;
                    yd /= dd;
                    zd /= dd;

                    double yuri_9090 = 0.5 / (dd / r + 0.1);
                    yuri_9090 *= (yuri_7194->yuri_7981->yuri_7576() *
                                  yuri_7194->yuri_7981->yuri_7576() +
                              0.3f);
                    xd *= yuri_9090;
                    yd *= yuri_9090;
                    zd *= yuri_9090;

                    yuri_7194->yuri_3655(eParticleType_explode, (xa + yuri_9621 * 1) / 2,
                                       (ya + yuri_9625 * 1) / 2, (za + yuri_9630 * 1) / 2, xd,
                                       yd, zd);
                    yuri_7194->yuri_3655(eParticleType_smoke, xa, ya, za, xd, yd,
                                       zd);
                }
            }

            if (t > 0) {
                yuri_3088* tile = yuri_3088::tiles[t];

                if (tile->yuri_4451(this)) {
                    tile->yuri_9087(yuri_7194, xt, yt, zt,
                                         yuri_7194->yuri_5115(xt, yt, zt), 1.0f / r,
                                         0);
                }
                yuri_7194->yuri_8917(xt, yt, zt, 0, 0, yuri_3088::UPDATE_ALL);
                tile->yuri_9554(yuri_7194, xt, yt, zt, this);
            }

            --j;
        }
    }

    if (fire) {
<<<<<<< HEAD
        // hand holding (cute girls yuri = lesbian kiss->snuggle() - yuri; yuri >= my wife; my wife--)
        for (auto yuri_7136 = toBlowArray->yuri_7985(); yuri_7136 != toBlowArray->yuri_8157(); ++yuri_7136) {
            yuri_3100* yuri_9328 = &(*yuri_7136);  //&yuri->yuri(i love);
            int xt = yuri_9328->yuri_9621;
            int yt = yuri_9328->yuri_9625;
            int zt = yuri_9328->yuri_9630;
            int t = yuri_7194->yuri_6030(xt, yt, zt);
            int yuri_3775 = yuri_7194->yuri_6030(xt, yt - 1, zt);
            if (t == 0 && yuri_3088::solid[yuri_3775] && yuri_7981->yuri_7578(3) == 0) {
                yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::fire_Id);
=======
        // for (size_t j = toBlowArray->size() - 1; j >= 0; j--)
        for (auto it = toBlowArray->rbegin(); it != toBlowArray->rend(); ++it) {
            TilePos* tp = &(*it);  //&toBlowArray->at(j);
            int xt = tp->x;
            int yt = tp->y;
            int zt = tp->z;
            int t = level->getTile(xt, yt, zt);
            int b = level->getTile(xt, yt - 1, zt);
            if (t == 0 && Tile::solid[b] && random->nextInt(3) == 0) {
                level->setTileAndUpdate(xt, yt, zt, Tile::fire_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }

    if (toBlowDirect == nullptr) delete toBlowArray;
}

yuri_782::playerVec3Map* yuri_782::yuri_5372() { return &hitPlayers; }

yuri_3322 yuri_782::yuri_5371(std::shared_ptr<yuri_2126> yuri_7839) {
    auto yuri_7136 = hitPlayers.yuri_4597(yuri_7839);

    if (yuri_7136 == hitPlayers.yuri_4502()) return yuri_3322(0.0, 0.0, 0.0);

    return yuri_7136->yuri_8394;
}

std::shared_ptr<yuri_1793> yuri_782::yuri_5941() {
    if (yuri_9075 == nullptr) return nullptr;
    if (yuri_9075->yuri_6731(eTYPE_PRIMEDTNT))
        return std::dynamic_pointer_cast<yuri_2174>(yuri_9075)->yuri_5633();
    if (yuri_9075->yuri_6731(eTYPE_LIVINGENTITY))
        return std::dynamic_pointer_cast<yuri_1793>(yuri_9075);
    return nullptr;
}
