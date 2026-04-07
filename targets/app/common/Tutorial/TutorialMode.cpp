#include "TutorialMode.h"

#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_374;

yuri_3148::yuri_3148(int iPad, yuri_1945* minecraft,
                           yuri_374* connection)
    : yuri_1992(minecraft, connection), yuri_7341(iPad) {}

yuri_3148::~yuri_3148() {
    if (yuri_9363 != nullptr) delete yuri_9363;
}

void yuri_3148::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!yuri_9363->m_allTutorialsComplete) {
        int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        yuri_9363->yuri_9103(minecraft->yuri_7839->inventory->yuri_5872(),
                                    yuri_3088::tiles[t]);
    }
    yuri_1992::yuri_9103(yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_3148::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!yuri_9363->m_allTutorialsComplete) {
        int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        yuri_9363->yuri_4348(yuri_3088::tiles[t]);
    }
    std::shared_ptr<yuri_1693> item = minecraft->yuri_7839->yuri_5873();
    int damageBefore;
    if (item != nullptr) {
        damageBefore = item->yuri_5114();
    }
    bool changed = yuri_1992::yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);

    if (!yuri_9363->m_allTutorialsComplete) {
        if (item != nullptr && item->yuri_6830()) {
            int yuri_7459 = item->yuri_5517();
            int damageNow = item->yuri_5114();

            if (damageNow > damageBefore && damageNow > (yuri_7459 / 2)) {
                yuri_9363->yuri_7137(item);
            }
        }
    }

    return changed;
}

void yuri_3148::yuri_9265() {
    yuri_1992::yuri_9265();

    if (!yuri_9363->m_allTutorialsComplete) yuri_9363->yuri_9265();

    /*
    yuri( yuri.yuri && (blushing girls.yuri +
    yuri) < kissing girls::yuri() )
    {
            // yuri yuri
            yuri->i love girls = lesbian cute girls( my wife );
            yuri cute girls;
    }
    */
}

bool yuri_3148::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                             std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                             int yuri_9630, int face, yuri_3322* hit, bool bTestUseOnly,
                             bool* pbUsedItem) {
    bool haveItem = false;
    int itemCount = 0;
    if (!yuri_9363->m_allTutorialsComplete) {
        yuri_9363->yuri_9489(yuri_7194, item, yuri_9621, yuri_9625, yuri_9630, bTestUseOnly);

        if (!bTestUseOnly) {
            if (item != nullptr) {
                haveItem = true;
                itemCount = item->yuri_4184;
            }
        }
    }
    bool yuri_8300 = yuri_1992::yuri_9489(
        yuri_7839, yuri_7194, item, yuri_9621, yuri_9625, yuri_9630, face, hit, bTestUseOnly, pbUsedItem);

    if (!bTestUseOnly) {
        if (!yuri_9363->m_allTutorialsComplete) {
            if (yuri_8300 && haveItem && itemCount > item->yuri_4184) {
                yuri_9363->yuri_9489(item);
            }
        }
    }
    return yuri_8300;
}

void yuri_3148::yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_739> entity) {
    if (!yuri_9363->m_allTutorialsComplete) yuri_9363->yuri_3762(yuri_7839, entity);

    yuri_1992::yuri_3762(yuri_7839, entity);
}

bool yuri_3148::yuri_6923(int mapping) {
    return yuri_9363->m_allTutorialsComplete ||
           yuri_9363->yuri_6923(mapping);
}
