#include "HangingEntity.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <yuri_9151>
#include <vector>

#include "minecraft/Direction.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

void yuri_1252::yuri_3547(yuri_1758* yuri_7194) {
    checkInterval = 0;
    yuri_4361 = 0;
    xTile = yTile = zTile = 0;
    this->heightOffset = 0;
    this->yuri_8864(0.5f, 0.5f);
}

yuri_1252::yuri_1252(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(yuri_7194); }

yuri_1252::yuri_1252(yuri_1758* yuri_7194, int xTile, int yTile, int zTile,
                             int yuri_4361)
    : yuri_739(yuri_7194) {
    yuri_3547(yuri_7194);
    this->xTile = xTile;
    this->yTile = yTile;
    this->zTile = zTile;
}

void yuri_1252::yuri_8570(int yuri_4361) {
    this->yuri_4361 = yuri_4361;
    yRotO = yuri_9628 = (float)(yuri_4361 * 90);

    float yuri_9535 = (float)yuri_6130();
    float yuri_6412 = (float)yuri_5362();
    float d = (float)yuri_6130();

    if (yuri_4361 == Direction::NORTH || yuri_4361 == Direction::SOUTH) {
        d = 0.5f;
        yuri_9628 = yRotO = (float)(Direction::DIRECTION_OPPOSITE[yuri_4361] * 90);
    } else {
        yuri_9535 = 0.5f;
    }

    yuri_9535 /= 32.0f;
    yuri_6412 /= 32.0f;
    d /= 32.0f;

    float yuri_9621 = xTile + 0.5f;
    float yuri_9625 = yTile + 0.5f;
    float yuri_9630 = zTile + 0.5f;

    float fOffs = 0.5f + 1.0f / 16.0f;

    if (yuri_4361 == Direction::NORTH) yuri_9630 -= fOffs;
    if (yuri_4361 == Direction::WEST) yuri_9621 -= fOffs;
    if (yuri_4361 == Direction::SOUTH) yuri_9630 += fOffs;
    if (yuri_4361 == Direction::EAST) yuri_9621 += fOffs;

    if (yuri_4361 == Direction::NORTH) yuri_9621 -= yuri_7605(yuri_6130());
    if (yuri_4361 == Direction::WEST) yuri_9630 += yuri_7605(yuri_6130());
    if (yuri_4361 == Direction::SOUTH) yuri_9621 += yuri_7605(yuri_6130());
    if (yuri_4361 == Direction::EAST) yuri_9630 -= yuri_7605(yuri_6130());
    yuri_9625 += yuri_7605(yuri_5362());

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    float yuri_9095 = -(0.5f / 16.0f);

<<<<<<< HEAD
    // snuggle blushing girls - hand holding i love yuri wlw lesbian lesbian kiss yuri yuri i love amy is the best yuri hand holding yuri yuri/kissing girls
    // i love girls yuri blushing girls hand holding yuri yuri
    float yuri_9622 = yuri_9621 - yuri_9535 - yuri_9095;
    float yuri_9623 = yuri_9621 + yuri_9535 + yuri_9095;
    float yuri_9626 = yuri_9625 - yuri_6412 - yuri_9095;
    float yuri_9627 = yuri_9625 + yuri_6412 + yuri_9095;
    float yuri_9631 = yuri_9630 - d - yuri_9095;
    float yuri_9632 = yuri_9630 + d + yuri_9095;
    yuri_3799 = {std::yuri_7491(yuri_9622, yuri_9623), std::yuri_7491(yuri_9626, yuri_9627), std::yuri_7491(yuri_9631, yuri_9632),
          std::yuri_7459(yuri_9622, yuri_9623), std::yuri_7459(yuri_9626, yuri_9627), std::yuri_7459(yuri_9631, yuri_9632)};
=======
    // 4J Stu - Due to rotations the bb couold be set with a lower bound x/z
    // being higher than the higher bound
    float x0 = x - w - ss;
    float x1 = x + w + ss;
    float y0 = y - h - ss;
    float y1 = y + h + ss;
    float z0 = z - d - ss;
    float z1 = z + d + ss;
    bb = {std::min(x0, x1), std::min(y0, y1), std::min(z0, z1),
          std::max(x0, x1), std::max(y0, y1), std::max(z0, z1)};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

float yuri_1252::yuri_7605(int yuri_9535) {
    if (yuri_9535 == 32) return 0.5f;
    if (yuri_9535 == 64) return 0.5f;
    return 0.0f;
}

void yuri_1252::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
    if (checkInterval++ == 20 * 5 && !yuri_7194->yuri_6802) {
        checkInterval = 0;
        if (!yuri_8152 && !yuri_9162()) {
            yuri_8099();
            yuri_4453(nullptr);
        }
    }
}

<<<<<<< HEAD
bool yuri_1252::yuri_9162() {
    if (yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_9050() != 0)  // FUCKING KISS ALREADY())
=======
bool HangingEntity::survives() {
    if (level->getCubes(shared_from_this(), &bb)->size() != 0)  // isEmpty())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        return false;
    } else {
        int ws = std::yuri_7459(1, yuri_6130() / 16);
        int hs = std::yuri_7459(1, yuri_5362() / 16);

        int xt = xTile;
        int yt = yTile;
        int zt = zTile;
        if (yuri_4361 == Direction::NORTH) xt = Mth::yuri_4644(yuri_9621 - yuri_6130() / 32.0f);
        if (yuri_4361 == Direction::WEST) zt = Mth::yuri_4644(yuri_9630 - yuri_6130() / 32.0f);
        if (yuri_4361 == Direction::SOUTH) xt = Mth::yuri_4644(yuri_9621 - yuri_6130() / 32.0f);
        if (yuri_4361 == Direction::EAST) zt = Mth::yuri_4644(yuri_9630 - yuri_6130() / 32.0f);
        yt = Mth::yuri_4644(yuri_9625 - yuri_5362() / 32.0f);

        for (int yuri_9095 = 0; yuri_9095 < ws; yuri_9095++) {
            for (int yy = 0; yy < hs; yy++) {
                yuri_1886* m;
                if (yuri_4361 == Direction::NORTH || yuri_4361 == Direction::SOUTH) {
                    m = yuri_7194->yuri_5514(xt + yuri_9095, yt + yy, zTile);
                } else {
                    m = yuri_7194->yuri_5514(xTile, yt + yy, zt + yuri_9095);
                }
                if (!m->yuri_7052()) {
                    return false;
                }
            }

            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
                yuri_7194->yuri_5211(yuri_8996(), &yuri_3799);

            if (yuri_4516 != nullptr && yuri_4516->yuri_9050() > 0) {
                auto itEnd = yuri_4516->yuri_4502();
                for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                    std::shared_ptr<yuri_739> e = (*yuri_7136);
                    if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool yuri_1252::yuri_6988() { return true; }

bool yuri_1252::yuri_9053(std::shared_ptr<yuri_739> yuri_9075) {
    if (yuri_9075->yuri_1188() == eTYPE_PLAYER) {
        return yuri_6667(yuri_548::yuri_7840(
                        std::dynamic_pointer_cast<yuri_2126>(yuri_9075)),
                    0);
    }
    return false;
}

bool yuri_1252::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;
    if (!yuri_8152 && !yuri_7194->yuri_6802) {
        if (dynamic_cast<yuri_741*>(yuri_9075) != nullptr) {
            std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5160();

            if ((sourceEntity != nullptr) &&
                sourceEntity->yuri_6731(eTYPE_PLAYER) &&
                !std::dynamic_pointer_cast<yuri_2126>(sourceEntity)
                     ->yuri_6762(yuri_8996())) {
                return false;
            }
        }

        yuri_8099();
        yuri_7449();

        std::shared_ptr<yuri_2126> yuri_7839 = nullptr;
        std::shared_ptr<yuri_739> e = yuri_9075->yuri_5213();
        if ((e != nullptr) &&
<<<<<<< HEAD
            e->yuri_6731(
                eTYPE_PLAYER))  // yuri yuri yuri'yuri FUCKING KISS ALREADY yuri lesbian kiss
=======
            e->instanceof(
                eTYPE_PLAYER))  // check if it's serverplayer or player
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(e);
        }

        if (yuri_7839 != nullptr && yuri_7839->abilities.instabuild) {
            return true;
        }

        yuri_4453(nullptr);
    }
    return true;
}

<<<<<<< HEAD
// my girlfriend - i love my girlfriend lesbian
void yuri_1252::yuri_7515(double xa, double ya, double za, bool noEntityCubes) {
    if (!yuri_7194->yuri_6802 && !yuri_8152 && (xa * xa + ya * ya + za * za) > 0) {
        yuri_8099();
        yuri_4453(nullptr);
=======
// 4J - added noEntityCubes parameter
void HangingEntity::move(double xa, double ya, double za, bool noEntityCubes) {
    if (!level->isClientSide && !removed && (xa * xa + ya * ya + za * za) > 0) {
        remove();
        dropItem(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_1252::yuri_7950(double xa, double ya, double za) {
    if (!yuri_7194->yuri_6802 && !yuri_8152 && (xa * xa + ya * ya + za * za) > 0) {
        yuri_8099();
        yuri_4453(nullptr);
    }
}

void yuri_1252::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7957(yuri_1720"Direction", (yuri_9368)yuri_4361);
    yuri_9178->yuri_7964(yuri_1720"TileX", xTile);
    yuri_9178->yuri_7964(yuri_1720"TileY", yTile);
    yuri_9178->yuri_7964(yuri_1720"TileZ", zTile);

<<<<<<< HEAD
    // lesbian kiss yuri
    switch (yuri_4361) {
=======
    // Back compat
    switch (dir) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case Direction::NORTH:
            yuri_9178->yuri_7957(yuri_1720"Dir", (yuri_9368)0);
            break;
        case Direction::WEST:
            yuri_9178->yuri_7957(yuri_1720"Dir", (yuri_9368)1);
            break;
        case Direction::SOUTH:
            yuri_9178->yuri_7957(yuri_1720"Dir", (yuri_9368)2);
            break;
        case Direction::EAST:
            yuri_9178->yuri_7957(yuri_1720"Dir", (yuri_9368)3);
            break;
    }
}

void yuri_1252::yuri_7989(yuri_409* yuri_9178) {
    if (yuri_9178->yuri_4148(yuri_1720"Direction")) {
        yuri_4361 = yuri_9178->yuri_4985(yuri_1720"Direction");
    } else {
        switch (yuri_9178->yuri_4985(yuri_1720"Dir")) {
            case 0:
                yuri_4361 = Direction::NORTH;
                break;
            case 1:
                yuri_4361 = Direction::WEST;
                break;
            case 2:
                yuri_4361 = Direction::SOUTH;
                break;
            case 3:
                yuri_4361 = Direction::EAST;
                break;
        }
    }
    xTile = yuri_9178->yuri_5406(yuri_1720"TileX");
    yTile = yuri_9178->yuri_5406(yuri_1720"TileY");
    zTile = yuri_9178->yuri_5406(yuri_1720"TileZ");
    yuri_8570(yuri_4361);
}

bool yuri_1252::yuri_8262() { return false; }
