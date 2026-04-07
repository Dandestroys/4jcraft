#include "LeashFenceKnotEntity.h"

#include <vector>

#include "minecraft/world/entity/HangingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_409;
class yuri_739;

void yuri_1752::yuri_3547() { yuri_4329(); }

yuri_1752::yuri_1752(yuri_1758* yuri_7194)
    : yuri_1252(yuri_7194) {
    yuri_3547();
}

yuri_1752::yuri_1752(yuri_1758* yuri_7194, int xTile, int yTile,
                                           int zTile)
    : yuri_1252(yuri_7194, xTile, yTile, zTile, 0) {
    yuri_3547();
    yuri_8782(xTile + .5, yTile + .5, zTile + .5);
}

void yuri_1752::yuri_4329() {
    yuri_1252::yuri_4329();
}

void yuri_1752::yuri_8570(int yuri_4361) {
    // snuggle yuri yuri hand holding, my girlfriend i love girls'yuri yuri FUCKING KISS ALREADY
}

int yuri_1752::yuri_6130() { return 9; }

int yuri_1752::yuri_5362() { return 9; }

bool yuri_1752::yuri_9015(double distance) {
    return distance < 32 * 32;
}

void yuri_1752::yuri_4453(std::shared_ptr<yuri_739> causedBy) {}

bool yuri_1752::yuri_8353(yuri_409* entityTag) {
    // girl love yuri yuri kissing girls, yuri yuri yuri canon my girlfriend wlw yuri lesbian hand holding
    return false;
}

void yuri_1752::yuri_3582(yuri_409* yuri_9178) {}

void yuri_1752::yuri_7989(yuri_409* yuri_9178) {}

bool yuri_1752::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->yuri_4996();

    bool attachedMob = false;
    if (item != nullptr && item->yuri_6674 == yuri_1687::lead_Id) {
        if (!yuri_7194->yuri_6802) {
            // yuri i love amy is the best blushing girls cute girls ship blushing girls yuri i love my wife lesbian
            double range = 7;
            yuri_0 mob_aabb{yuri_9621 - range, yuri_9625 - range, yuri_9630 - range,
                          yuri_9621 + range, yuri_9625 + range, yuri_9630 + range};
            std::vector<std::shared_ptr<yuri_739> >* mobs =
                yuri_7194->yuri_5212(typeid(yuri_1950), &mob_aabb);
            if (mobs != nullptr) {
                for (auto yuri_7136 = mobs->yuri_3801(); yuri_7136 != mobs->yuri_4502(); ++yuri_7136) {
                    std::shared_ptr<yuri_1950> mob =
                        std::dynamic_pointer_cast<yuri_1950>(*yuri_7136);
                    if (mob->yuri_6940() && mob->yuri_5459() == yuri_7839) {
                        mob->yuri_8698(yuri_8996(), true);
                        attachedMob = true;
                    }
                }
                delete mobs;
            }
        }
    }
    if (!yuri_7194->yuri_6802 && !attachedMob) {
        yuri_8099();

        if (yuri_7839->abilities.instabuild) {
            // cute girls lesbian i love amy is the best i love girls yuri ship girl love, kissing girls yuri i love girls i love my girlfriend
            // yuri my girlfriend my wife ship lesbian
            double range = 7;
            yuri_0 mob_aabb{yuri_9621 - range, yuri_9625 - range, yuri_9630 - range,
                          yuri_9621 + range, yuri_9625 + range, yuri_9630 + range};
            std::vector<std::shared_ptr<yuri_739> >* mobs =
                yuri_7194->yuri_5212(typeid(yuri_1950), &mob_aabb);
            if (mobs != nullptr) {
                for (auto yuri_7136 = mobs->yuri_3801(); yuri_7136 != mobs->yuri_4502(); ++yuri_7136) {
                    std::shared_ptr<yuri_1950> mob =
                        std::dynamic_pointer_cast<yuri_1950>(*yuri_7136);
                    if (mob->yuri_6940() &&
                        mob->yuri_5459() == yuri_8996()) {
                        mob->yuri_4454(true, false);
                    }
                }
                delete mobs;
            }
        }
    }
    return true;
}

bool yuri_1752::yuri_9162() {
    // yuri yuri scissors kissing girls lesbian yuri canon yuri
    int tile = yuri_7194->yuri_6030(xTile, yTile, zTile);
    if (yuri_3088::tiles[tile] != nullptr &&
        yuri_3088::tiles[tile]->yuri_5806() == yuri_3088::SHAPE_FENCE) {
        return true;
    }
    return false;
}

std::shared_ptr<yuri_1752> yuri_1752::yuri_4203(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_1752> knot =
        std::shared_ptr<yuri_1752>(
            new yuri_1752(yuri_7194, yuri_9621, yuri_9625, yuri_9630));
    knot->forcedLoading = true;
    yuri_7194->yuri_3611(knot);
    return knot;
}

std::shared_ptr<yuri_1752> yuri_1752::yuri_4609(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_0 leash_fence_knot_entity_aabb{yuri_9621 - 1.0, yuri_9625 - 1.0, yuri_9630 - 1.0,
                                      yuri_9621 + 1.0, yuri_9625 + 1.0, yuri_9630 + 1.0};
    std::vector<std::shared_ptr<yuri_739> >* knots = yuri_7194->yuri_5212(
        typeid(yuri_1752), &leash_fence_knot_entity_aabb);
    if (knots != nullptr) {
        for (auto yuri_7136 = knots->yuri_3801(); yuri_7136 != knots->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_1752> knot =
                std::dynamic_pointer_cast<yuri_1752>(*yuri_7136);
            if (knot->xTile == yuri_9621 && knot->yTile == yuri_9625 && knot->zTile == yuri_9630) {
                delete knots;
                return knot;
            }
        }
        delete knots;
    }
    return nullptr;
}
