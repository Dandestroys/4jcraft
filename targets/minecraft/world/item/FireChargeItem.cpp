#include "FireChargeItem.h"

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_820::yuri_820(int yuri_6674) : yuri_1687(yuri_6674) {
    m_dragonFireballIcon = nullptr;
}

bool yuri_820::yuri_9492(std::shared_ptr<yuri_1693> instance,
                           std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                           int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                           float clickZ, bool bTestUseOnOnly) {
    if (yuri_7194->yuri_6802) {
        return true;
    }

    if (face == 0) yuri_9625--;
    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) {
        return false;
    }

    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    if (bTestUseOnOnly) {
        return true;
    }

    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_9188 == 0) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_FIRE_NEWIGNITE,
                         1, yuri_7981->yuri_7576() * 0.4f + 0.8f);
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::fire_Id);
    }

    if (!yuri_7839->abilities.instabuild) {
        instance->yuri_4184--;
    }
    return true;
}

yuri_1346* yuri_820::yuri_5385(int itemAuxValue) {
    if (itemAuxValue > 0) return m_dragonFireballIcon;
    return yuri_1687::yuri_5385(itemAuxValue);
}

void yuri_820::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);
    m_dragonFireballIcon = iconRegister->yuri_8071(yuri_1720"dragonFireball");
}
