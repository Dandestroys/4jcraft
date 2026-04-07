#include "CocoaTile.h"

#include <optional>

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1346;

const std::yuri_9616 yuri_386::TEXTURE_AGES[] = {yuri_1720"cocoa_0", yuri_1720"cocoa_1",
                                                yuri_1720"cocoa_2"};

yuri_386::yuri_386(int yuri_6674) : yuri_614(yuri_6674, yuri_1886::plant, false) {
    yuri_8915(true);
}

yuri_1346* yuri_386::yuri_6007(int face, int yuri_4295) { return icons[2]; }

yuri_1346* yuri_386::yuri_6009(int age) {
    if (age < 0 || age >= COCOA_TEXTURES_LENGTH) {
        age = COCOA_TEXTURES_LENGTH - 1;
    }
    return icons[age];
}

void yuri_386::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, UPDATE_CLIENTS);
    } else if (yuri_7194->yuri_7981->yuri_7578(5) == 0) {
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int age = yuri_4870(yuri_4295);
        if (age < 2) {
            age++;
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, (age << 2) | (yuri_5163(yuri_4295)),
                           yuri_3088::UPDATE_CLIENTS);
        }
    }
}

bool yuri_386::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4361 = yuri_5163(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));

    yuri_9621 += Direction::STEP_X[yuri_4361];
    yuri_9630 += Direction::STEP_Z[yuri_4361];
    int attachedTo = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    return attachedTo == yuri_3088::treeTrunk_Id &&
           yuri_3137::yuri_6131(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630)) ==
               yuri_3137::JUNGLE_TRUNK;
}

int yuri_386::yuri_5806() { return SHAPE_COCOA; }

bool yuri_386::yuri_6827() { return false; }

bool yuri_386::yuri_7058(bool isServerLevel) { return false; }

std::optional<yuri_0> yuri_386::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_614::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

yuri_0 yuri_386::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_614::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_386::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            int forceData,
                            std::shared_ptr<yuri_3091> forceEntity) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_5163(yuri_4295);
    int age = yuri_4870(yuri_4295);

    int yuri_9567 = 4 + age * 2;
    int yuri_6654 = 5 + age * 2;

    float hWidth = yuri_9567 / 2.0f;

    switch (yuri_4361) {
        case Direction::SOUTH:
            yuri_8855((8.0f - hWidth) / 16.0f, (12.0f - yuri_6654) / 16.0f,
                     (15.0f - yuri_9567) / 16.0f, (8.0f + hWidth) / 16.0f,
                     (12.0f) / 16.0f, (15.0f) / 16.0f);
            break;
        case Direction::NORTH:
            yuri_8855((8.0f - hWidth) / 16.0f, (12.0f - yuri_6654) / 16.0f,
                     (1.0f) / 16.0f, (8.0f + hWidth) / 16.0f, (12.0f) / 16.0f,
                     (1.0f + yuri_9567) / 16.0f);
            break;
        case Direction::WEST:
            yuri_8855((1.0f) / 16.0f, (12.0f - yuri_6654) / 16.0f,
                     (8.0f - hWidth) / 16.0f, (1.0f + yuri_9567) / 16.0f,
                     (12.0f) / 16.0f, (8.0f + hWidth) / 16.0f);
            break;
        case Direction::EAST:
            yuri_8855((15.0f - yuri_9567) / 16.0f, (12.0f - yuri_6654) / 16.0f,
                     (8.0f - hWidth) / 16.0f, (15.0f) / 16.0f, (12.0f) / 16.0f,
                     (8.0f + hWidth) / 16.0f);
            break;
    }
}

void yuri_386::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3) + 0) % 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);
}

int yuri_386::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int face, float clickX, float clickY,
                                        float clickZ, int itemValue) {
    if (face == Facing::UP || face == Facing::DOWN) {
        face = Facing::NORTH;
    }
    return Direction::DIRECTION_OPPOSITE[Direction::FACING_DIRECTION[face]];
}

void yuri_386::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, UPDATE_CLIENTS);
    }
}

int yuri_386::yuri_4870(int yuri_4295) {
    return (yuri_4295 & yuri_614::DIRECTION_INV_MASK) >> 2;
}

void yuri_386::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                               float odds, int playerBonusLevel) {
    int age = yuri_4870(yuri_4295);
    int yuri_4184 = 1;
    if (age >= 2) {
        yuri_4184 = 3;
    }
    for (int i = 0; i < yuri_4184; i++) {
        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::make_shared<yuri_1693>(yuri_1687::dye_powder, 1,
                                                   yuri_671::BROWN));
    }
}

int yuri_386::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::dye_powder_Id;
}

int yuri_386::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_671::BROWN;
}

void yuri_386::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[COCOA_TEXTURES_LENGTH];

    for (int i = 0; i < COCOA_TEXTURES_LENGTH; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_AGES[i]);
    }
}
