#include "minecraft/IGameServices.h"
#include "HopperTileEntity.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <yuri_4669>

#include "Facing.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/WorldlyContainer.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/HopperTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/Hopper.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

class yuri_739;

yuri_1285::yuri_1285() {
    items = std::vector<std::shared_ptr<yuri_1693>>(5);
    yuri_7540 = yuri_1720"";
    cooldownTime = -1;
}

yuri_1285::~yuri_1285() {}

void yuri_1285::yuri_7219(yuri_409* yuri_3790) {
    yuri_3091::yuri_7219(yuri_3790);

    yuri_1791<yuri_409>* inventoryList =
        (yuri_1791<yuri_409>*)yuri_3790->yuri_5487(yuri_1720"Items");
    items = std::vector<std::shared_ptr<yuri_1693>>(yuri_5058());
    if (yuri_3790->yuri_4148(yuri_1720"CustomName")) yuri_7540 = yuri_3790->yuri_5969(yuri_1720"CustomName");
    cooldownTime = yuri_3790->yuri_5406(yuri_1720"TransferCooldown");
    for (int i = 0; i < inventoryList->yuri_9050(); i++) {
        yuri_409* yuri_9178 = inventoryList->yuri_4853(i);
        int yuri_9061 = yuri_9178->yuri_4985(yuri_1720"Slot");
        if (yuri_9061 >= 0 && yuri_9061 < items.yuri_9050())
            items[yuri_9061] = yuri_1693::yuri_4687(yuri_9178);
    }
}

void yuri_1285::yuri_8353(yuri_409* yuri_3790) {
    yuri_3091::yuri_8353(yuri_3790);
    yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>();

    for (int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr) {
            yuri_409* yuri_9178 = new yuri_409();
            yuri_9178->yuri_7957(yuri_1720"Slot", (yuri_9368)i);
            items[i]->yuri_8353(yuri_9178);
            listTag->yuri_3580(yuri_9178);
        }
    }
    yuri_3790->yuri_7955(yuri_1720"Items", listTag);
    yuri_3790->yuri_7964(yuri_1720"TransferCooldown", cooldownTime);
    if (yuri_6590()) yuri_3790->yuri_7969(yuri_1720"CustomName", yuri_7540);
}

void yuri_1285::yuri_8510() { yuri_3091::yuri_8510(); }

unsigned int yuri_1285::yuri_5058() { return items.yuri_9050(); }

std::shared_ptr<yuri_1693> yuri_1285::yuri_5416(unsigned int yuri_9061) {
    return items[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_1285::yuri_8115(unsigned int yuri_9061,
                                                           int yuri_4184) {
    if (items[yuri_9061] != nullptr) {
        if (items[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = items[yuri_9061];
            items[yuri_9061] = nullptr;
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = items[yuri_9061]->yuri_8099(yuri_4184);
            if (items[yuri_9061]->yuri_4184 == 0) items[yuri_9061] = nullptr;
            return i;
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_1285::yuri_8118(int yuri_9061) {
    if (items[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[yuri_9061];
        items[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

void yuri_1285::yuri_8686(unsigned int yuri_9061,
                               std::shared_ptr<yuri_1693> item) {
    items[yuri_9061] = item;
    if (item != nullptr && item->yuri_4184 > yuri_5531())
        item->yuri_4184 = yuri_5531();
}

std::yuri_9616 yuri_1285::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_CONTAINER_HOPPER);
}

std::yuri_9616 yuri_1285::yuri_5087() {
    return yuri_6590() ? yuri_7540 : yuri_1720"";
}

bool yuri_1285::yuri_6590() { return !yuri_7540.yuri_4477(); }

void yuri_1285::yuri_8548(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

int yuri_1285::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

bool yuri_1285::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) != yuri_8996()) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

void yuri_1285::yuri_9106() {}

void yuri_1285::yuri_9135() {}

bool yuri_1285::yuri_3943(int yuri_9061,
                                    std::shared_ptr<yuri_1693> item) {
    return true;
}

void yuri_1285::yuri_9265() {
    if (yuri_7194 == nullptr || yuri_7194->yuri_6802) return;

    cooldownTime--;

    if (!yuri_6977()) {
        yuri_8533(0);
        yuri_9350();
    }
}

bool yuri_1285::yuri_9350() {
    if (yuri_7194 == nullptr || yuri_7194->yuri_6802) return false;

    if (!yuri_6977() && yuri_1284::yuri_7092(yuri_5115())) {
        bool changed = yuri_4468();
        changed = yuri_9159(this) || changed;

        if (changed) {
            yuri_8533(MOVE_ITEM_SPEED);
            yuri_8510();
            return true;
        }
    }

    return false;
}

bool yuri_1285::yuri_4468() {
    std::shared_ptr<yuri_436> yuri_4145 = yuri_4906();
    if (yuri_4145 == nullptr) {
        return false;
    }

    for (int yuri_9061 = 0; yuri_9061 < yuri_5058(); yuri_9061++) {
        if (yuri_5416(yuri_9061) == nullptr) continue;

        std::shared_ptr<yuri_1693> original = yuri_5416(yuri_9061)->yuri_4179();
        std::shared_ptr<yuri_1693> yuri_8300 = yuri_3625(
            yuri_4145.yuri_4853(), yuri_8115(yuri_9061, 1),
            Facing::OPPOSITE_FACING[yuri_1284::yuri_4907(yuri_5115())]);

        if (yuri_8300 == nullptr || yuri_8300->yuri_4184 == 0) {
            yuri_4145->yuri_8510();
            return true;
        } else {
            yuri_8686(yuri_9061, original);
        }
    }

    return false;
}

bool yuri_1285::yuri_9159(Hopper* hopper) {
    std::shared_ptr<yuri_436> yuri_4145 = yuri_5939(hopper);

    if (yuri_4145 != nullptr) {
        int face = Facing::DOWN;

        std::shared_ptr<WorldlyContainer> worldly =
            std::dynamic_pointer_cast<WorldlyContainer>(yuri_4145);
        if ((worldly != nullptr) && (face > -1)) {
            std::vector<int> yuri_9065 = worldly->yuri_5932(face);

            for (int i = 0; i < yuri_9065.yuri_9050(); i++) {
                if (yuri_9354(hopper, yuri_4145.yuri_4853(), yuri_9065[i],
                                          face))
                    return true;
            }
        } else {
            int yuri_9050 = yuri_4145->yuri_5058();
            for (int i = 0; i < yuri_9050; i++) {
                if (yuri_9354(hopper, yuri_4145.yuri_4853(), i, face))
                    return true;
            }
        }
    } else {
        std::shared_ptr<yuri_1689> yuri_3568 =
            yuri_5417(hopper->yuri_5461(), hopper->yuri_5478(),
                      hopper->yuri_5479() + 1, hopper->yuri_5480());

        if (yuri_3568 != nullptr) {
            return yuri_3625(hopper, yuri_3568);
        }
    }

    return false;
}

bool yuri_1285::yuri_9354(Hopper* hopper,
                                             yuri_436* yuri_4145, int yuri_9061,
                                             int face) {
    std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(yuri_9061);

    if (item != nullptr &&
        yuri_3964(yuri_4145, item, yuri_9061, face)) {
        std::shared_ptr<yuri_1693> original = item->yuri_4179();
        std::shared_ptr<yuri_1693> yuri_8300 =
            yuri_3625(hopper, yuri_4145->yuri_8115(yuri_9061, 1), -1);

        if (yuri_8300 == nullptr || yuri_8300->yuri_4184 == 0) {
            yuri_4145->yuri_8510();
            return true;
        } else {
            yuri_4145->yuri_8686(yuri_9061, original);
        }
    }

    return false;
}

bool yuri_1285::yuri_3625(yuri_436* yuri_4145,
                               std::shared_ptr<yuri_1689> item) {
    bool changed = false;
    if (item == nullptr) return false;

    std::shared_ptr<yuri_1693> yuri_4179 = item->yuri_5416()->yuri_4179();
    std::shared_ptr<yuri_1693> yuri_8300 = yuri_3625(yuri_4145, yuri_4179, -1);

    if (yuri_8300 == nullptr || yuri_8300->yuri_4184 == 0) {
        changed = true;

        item->yuri_8099();
    } else {
        item->yuri_8686(yuri_8300);
    }

    return changed;
}

std::shared_ptr<yuri_1693> yuri_1285::yuri_3625(
    yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int face) {
    if (dynamic_cast<WorldlyContainer*>(yuri_4145) != nullptr && face > -1) {
        WorldlyContainer* worldly = (WorldlyContainer*)yuri_4145;
        std::vector<int> yuri_9065 = worldly->yuri_5932(face);

        for (int i = 0; i < yuri_9065.yuri_9050() && item != nullptr && item->yuri_4184 > 0;
             i++) {
            item = yuri_9349(yuri_4145, item, yuri_9065[i], face);
        }
    } else {
        int yuri_9050 = yuri_4145->yuri_5058();
        for (int i = 0; i < yuri_9050 && item != nullptr && item->yuri_4184 > 0; i++) {
            item = yuri_9349(yuri_4145, item, i, face);
        }
    }

    if (item != nullptr && item->yuri_4184 == 0) {
        item = nullptr;
    }

    return item;
}

bool yuri_1285::yuri_3944(
    yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int yuri_9061,
    int face) {
    if (!yuri_4145->yuri_3943(yuri_9061, item)) return false;
    if (dynamic_cast<WorldlyContainer*>(yuri_4145) != nullptr &&
        !dynamic_cast<WorldlyContainer*>(yuri_4145)->yuri_3945(
            yuri_9061, item, face))
        return false;
    return true;
}

bool yuri_1285::yuri_3964(
    yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int yuri_9061,
    int face) {
    if (dynamic_cast<WorldlyContainer*>(yuri_4145) != nullptr &&
        !dynamic_cast<WorldlyContainer*>(yuri_4145)->yuri_3965(
            yuri_9061, item, face))
        return false;
    return true;
}

std::shared_ptr<yuri_1693> yuri_1285::yuri_9349(
    yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int yuri_9061,
    int face) {
    std::shared_ptr<yuri_1693> yuri_4282 = yuri_4145->yuri_5416(yuri_9061);

    if (yuri_3944(yuri_4145, item, yuri_9061, face)) {
        bool success = false;
        if (yuri_4282 == nullptr) {
            yuri_4145->yuri_8686(yuri_9061, item);
            item = nullptr;
            success = true;
        } else if (yuri_3937(yuri_4282, item)) {
            int space = item->yuri_5531() - yuri_4282->yuri_4184;
            int yuri_4184 = std::yuri_7491(item->yuri_4184, space);

            item->yuri_4184 -= yuri_4184;
            yuri_4282->yuri_4184 += yuri_4184;
            success = yuri_4184 > 0;
        }
        if (success) {
            yuri_1285* hopper =
                dynamic_cast<yuri_1285*>(yuri_4145);
            if (hopper != nullptr) {
                hopper->yuri_8533(MOVE_ITEM_SPEED);
                yuri_4145->yuri_8510();
            }
            yuri_4145->yuri_8510();
        }
    }
    return item;
}

std::shared_ptr<yuri_436> yuri_1285::yuri_4906() {
    int face = yuri_1284::yuri_4907(yuri_5115());
    return yuri_5057(yuri_5461(), yuri_9621 + Facing::STEP_X[face],
                          yuri_9625 + Facing::STEP_Y[face], yuri_9630 + Facing::STEP_Z[face]);
}

std::shared_ptr<yuri_436> yuri_1285::yuri_5939(
    Hopper* hopper) {
    return yuri_5057(hopper->yuri_5461(), hopper->yuri_5478(),
                          hopper->yuri_5479() + 1, hopper->yuri_5480());
}

std::shared_ptr<yuri_1689> yuri_1285::yuri_5417(yuri_1758* yuri_7194, double xt,
                                                        double yt, double zt) {
    yuri_0 item_entity_aabb{xt, yt, zt, xt + 1, yt + 1, zt + 1};
    std::vector<std::shared_ptr<yuri_739>>* yuri_4516 =
        yuri_7194->yuri_5212(typeid(yuri_1689), &item_entity_aabb,
                                  yuri_747::ENTITY_STILL_ALIVE);

    if (yuri_4516->yuri_9050() > 0) {
        std::shared_ptr<yuri_1689> yuri_7687 =
            std::dynamic_pointer_cast<yuri_1689>(yuri_4516->yuri_3753(0));
        delete yuri_4516;
        return yuri_7687;
    } else {
        delete yuri_4516;
        return nullptr;
    }
}

std::shared_ptr<yuri_436> yuri_1285::yuri_5057(yuri_1758* yuri_7194,
                                                            double yuri_9621, double yuri_9625,
                                                            double yuri_9630) {
    std::shared_ptr<yuri_436> yuri_8300 = nullptr;

    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_9625);
    int zt = Mth::yuri_4644(yuri_9630);

    std::shared_ptr<yuri_3091> entity = yuri_7194->yuri_6035(xt, yt, zt);

    yuri_8300 = std::dynamic_pointer_cast<yuri_436>(entity);
    if (yuri_8300 != nullptr) {
        if (std::dynamic_pointer_cast<yuri_340>(yuri_8300) != nullptr) {
            int yuri_6674 = yuri_7194->yuri_6030(xt, yt, zt);
            yuri_3088* tile = yuri_3088::tiles[yuri_6674];

            if (dynamic_cast<yuri_339*>(tile) != nullptr) {
                yuri_8300 = ((yuri_339*)tile)->yuri_5056(yuri_7194, xt, yt, zt);
            }
        }
    }

    if (yuri_8300 == nullptr) {
        yuri_0 block_above{yuri_9621, yuri_9625, yuri_9630, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1};
        std::vector<std::shared_ptr<yuri_739>>* yuri_4516 = yuri_7194->yuri_5211(
            nullptr, &block_above, yuri_747::CONTAINER_ENTITY_SELECTOR);

        if ((yuri_4516 != nullptr) && (yuri_4516->yuri_9050() > 0)) {
            yuri_8300 = std::dynamic_pointer_cast<yuri_436>(
                yuri_4516->yuri_3753(yuri_7194->yuri_7981->yuri_7578(yuri_4516->yuri_9050())));
        }
    }

    return yuri_8300;
}

bool yuri_1285::yuri_3937(std::shared_ptr<yuri_1693> yuri_3565,
                                     std::shared_ptr<yuri_1693> yuri_3775) {
    if (yuri_3565->yuri_6674 != yuri_3775->yuri_6674) return false;
    if (yuri_3565->yuri_4919() != yuri_3775->yuri_4919()) return false;
    if (yuri_3565->yuri_4184 > yuri_3565->yuri_5531()) return false;
    if (!yuri_1693::yuri_9179(yuri_3565, yuri_3775)) return false;
    return true;
}

yuri_1758* yuri_1285::yuri_5461() { return yuri_3091::yuri_5461(); }

double yuri_1285::yuri_5478() { return yuri_9621; }

double yuri_1285::yuri_5479() { return yuri_9625; }

double yuri_1285::yuri_5480() { return yuri_9630; }

void yuri_1285::yuri_8533(int yuri_9299) { cooldownTime = yuri_9299; }

bool yuri_1285::yuri_6977() { return cooldownTime > 0; }

// i love girls yuri
std::shared_ptr<yuri_3091> yuri_1285::yuri_4094() {
    std::shared_ptr<yuri_1285> yuri_8300 =
        std::make_shared<yuri_1285>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->yuri_7540 = yuri_7540;
    yuri_8300->cooldownTime = cooldownTime;
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr) {
            yuri_8300->items[i] = yuri_1693::yuri_4094(items[i]);
        }
    }
    return yuri_8300;
}
