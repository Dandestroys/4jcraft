#include "AnvilTile.h"

#include "Direction.h"
#include "Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class yuri_1346;

const unsigned int yuri_119::ANVIL_NAMES[ANVIL_NAMES_LENGTH] = {
    IDS_TILE_ANVIL_INTACT,
    IDS_TILE_ANVIL_SLIGHTLYDAMAGED,
    IDS_TILE_ANVIL_VERYDAMAGED,
};

std::yuri_9616 yuri_119::TEXTURE_DAMAGE_NAMES[ANVIL_NAMES_LENGTH] = {
    yuri_1720"anvil_top", yuri_1720"anvil_top_damaged_1", yuri_1720"anvil_top_damaged_2"};

yuri_119::yuri_119(int yuri_6674) : yuri_1265(yuri_6674, yuri_1886::heavyMetal, false) {
    part = PART_BASE;
    yuri_8706(0);
    icons = nullptr;
}

bool yuri_119::yuri_6827() { return false; }

bool yuri_119::yuri_7058(bool isServerLevel) { return false; }

yuri_1346* yuri_119::yuri_6007(int face, int yuri_4295) {
    if (part == PART_TOP && face == Facing::UP) {
        int yuri_4294 = (yuri_4295 >> 2) % ANVIL_NAMES_LENGTH;
        return icons[yuri_4294];
    }
    return yuri_6672;
}

void yuri_119::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"anvil_base");
    icons = new yuri_1346*[ANVIL_NAMES_LENGTH];

    for (int i = 0; i < ANVIL_NAMES_LENGTH; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_DAMAGE_NAMES[i]);
    }
}

void yuri_119::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3;
    int dmg = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) >> 2;

    yuri_4361 = ++yuri_4361 % 4;
    if (yuri_4361 == 0)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Direction::NORTH | (dmg << 2),
                       yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 1)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Direction::EAST | (dmg << 2),
                       yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 2)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Direction::SOUTH | (dmg << 2),
                       yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 3)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Direction::WEST | (dmg << 2),
                       yuri_3088::UPDATE_CLIENTS);
}

bool yuri_119::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                    std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                    float clickX, float clickY, float clickZ, bool soundOnly) {
    if (yuri_7194->yuri_6802) {
        return true;
    }
    yuri_7839->yuri_9107(yuri_9621, yuri_9625, yuri_9630);
    return true;
}

int yuri_119::yuri_5806() { return SHAPE_ANVIL; }

int yuri_119::yuri_5947(int yuri_4295) { return yuri_4295 >> 2; }

void yuri_119::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            int forceData,
                            std::shared_ptr<yuri_3091> forceEntity) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 3;

    if (yuri_4361 == Direction::EAST || yuri_4361 == Direction::WEST) {
        yuri_8855(0, 0, 2 / 16.0f, 1, 1, 1 - 2 / 16.0f);
    } else {
        yuri_8855(2 / 16.0f, 0, 0, 1 - 2 / 16.0f, 1, 1);
    }
}

void yuri_119::yuri_4561(std::shared_ptr<yuri_794> entity) {
    entity->yuri_8656(true);
}

void yuri_119::yuri_7625(yuri_1758* yuri_7194, int xt, int yt, int zt, int yuri_4295) {
    yuri_7194->yuri_7195(LevelEvent::SOUND_ANVIL_LAND, xt, yt, zt, 0);
}

bool yuri_119::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 int face) {
    return true;
}