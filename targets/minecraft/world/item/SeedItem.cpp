
#include "SeedItem.h"

#include <memory>

#include "Item.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_2534::yuri_2534(int yuri_6674, int yuri_8301, int targetLand) : yuri_1687(yuri_6674) {
    this->yuri_8301 = yuri_8301;
    this->targetLand = targetLand;
}

bool yuri_2534::yuri_9492(std::shared_ptr<yuri_1693> instance,
                     std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                     int yuri_9630, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
    // ship-snuggle - cute girls cute girls yuri snuggle i love amy is the best yuri i love girls FUCKING KISS ALREADY i love girls yuri my wife
    if (face != 1) return false;

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance) ||
        !yuri_7839->yuri_7474(yuri_9621, yuri_9625 + 1, yuri_9630, face, instance))
        return false;

    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_9188 == targetLand && yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        if (!bTestUseOnOnly) {
            yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_8301);
            instance->yuri_4184--;
        }
        return true;
    }
    return false;
}