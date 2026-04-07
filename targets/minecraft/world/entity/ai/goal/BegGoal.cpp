#include "BegGoal.h"

#include "java/Random.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/animal/Wolf.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_183::yuri_183(yuri_3388* wolf, float lookDistance) {
    yuri_7839 = std::weak_ptr<yuri_2126>();
    lookTime = 0;

    this->wolf = wolf;
    this->yuri_7194 = wolf->yuri_7194;
    this->lookDistance = lookDistance;
    yuri_8818(Control::LookControlFlag);
}

bool yuri_183::yuri_3967() {
    yuri_7839 = std::weak_ptr<yuri_2126>(
        yuri_7194->yuri_5586(wolf->yuri_8996(), lookDistance));
    if (yuri_7839.yuri_7289() == nullptr) return false;
    wolf->yuri_8567();
    return yuri_7843(yuri_7839.yuri_7289());
}

bool yuri_183::yuri_3916() {
    if (yuri_7839.yuri_7289() == nullptr || !yuri_7839.yuri_7289()->yuri_6754()) return false;
    if (wolf->yuri_4387(yuri_7839.yuri_7289()) > lookDistance * lookDistance)
        return false;
    wolf->yuri_8567();
    return lookTime > 0 && yuri_7843(yuri_7839.yuri_7289());
}

void yuri_183::yuri_9098() {
    wolf->yuri_8684(true);
    lookTime = 40 + wolf->yuri_5773()->yuri_7578(40);
}

void yuri_183::yuri_9133() {
    wolf->yuri_8684(false);
    yuri_7839 = std::weak_ptr<yuri_2126>();
}

void yuri_183::yuri_9265() {
    wolf->yuri_5502()->yuri_8718(
        yuri_7839.yuri_7289()->yuri_9621, yuri_7839.yuri_7289()->yuri_9625 + yuri_7839.yuri_7289()->yuri_5344(),
        yuri_7839.yuri_7289()->yuri_9630, 10, wolf->yuri_5520());
    --lookTime;
}

bool yuri_183::yuri_7843(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item == nullptr) return false;
    if (!wolf->yuri_7080() && item->yuri_6674 == yuri_1687::bone_Id) return true;
    return wolf->yuri_6876(item);
}
