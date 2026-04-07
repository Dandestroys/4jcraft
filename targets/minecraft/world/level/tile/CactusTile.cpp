#include "CactusTile.h"

#include <memory>
#include <optional>
#include <yuri_9151>

#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_288::yuri_288(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::cactus, false) {
    yuri_8915(true);
    iconTop = nullptr;
    iconBottom = nullptr;
}

void yuri_288::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        int yuri_6654 = 1;
        while (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - yuri_6654, yuri_9630) == yuri_6674) {
            yuri_6654++;
        }
        if (yuri_6654 < 3) {
            int age = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
            if (age == 15) {
                yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 0, yuri_3088::UPDATE_NONE);
                yuri_7553(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
            } else {
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, age + 1, yuri_3088::UPDATE_NONE);
            }
        }
    }
}

std::optional<yuri_0> yuri_288::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    float r = 1 / 16.0f;
    return yuri_0{yuri_9621 + r,    static_cast<double>(yuri_9625), yuri_9630 + r, yuri_9621 + 1 - r, yuri_9625 + 1 - r,
                yuri_9630 + 1 - r};
}

yuri_0 yuri_288::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    float r = 1 / 16.0f;
    return yuri_0(yuri_9621 + r, yuri_9625, yuri_9630 + r, yuri_9621 + 1 - r, yuri_9625 + 1, yuri_9630 + 1 - r);
}

yuri_1346* yuri_288::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN)
        return iconBottom;
    else
        return yuri_6672;
}

bool yuri_288::yuri_6827() { return false; }

bool yuri_288::yuri_7058(bool isServerLevel) { return false; }

int yuri_288::yuri_5806() { return yuri_3088::SHAPE_CACTUS; }

bool yuri_288::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return false;

    return yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_288::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_4353(yuri_9621, yuri_9625, yuri_9630, true);
    }
}

bool yuri_288::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5514(yuri_9621 - 1, yuri_9625, yuri_9630)->yuri_7052()) return false;
    if (yuri_7194->yuri_5514(yuri_9621 + 1, yuri_9625, yuri_9630)->yuri_7052()) return false;
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630 - 1)->yuri_7052()) return false;
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630 + 1)->yuri_7052()) return false;
    int yuri_3803 = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    return yuri_3803 == yuri_3088::cactus_Id || yuri_3803 == yuri_3088::sand_Id;
}

void yuri_288::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity) {
    entity->yuri_6667(yuri_548::cactus, 1);
}

void yuri_288::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"cactus_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"cactus_top");
    iconBottom = iconRegister->yuri_8071(yuri_1720"cactus_bottom");
}

bool yuri_288::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630);
}
