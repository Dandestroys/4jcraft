#include "ResultSlot.h"

#include <algorithm>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2417::yuri_2417(yuri_2126* yuri_7839, std::shared_ptr<yuri_436> craftSlots,
                       std::shared_ptr<yuri_436> yuri_4145, int yuri_6674, int yuri_9621,
                       int yuri_9625)
    : yuri_2845(yuri_4145, yuri_6674, yuri_9621, yuri_9625) {
    this->yuri_7839 = yuri_7839;
    this->craftSlots = craftSlots;
    removeCount = 0;
}

bool yuri_2417::yuri_7468(std::shared_ptr<yuri_1693> item) { return false; }

std::shared_ptr<yuri_1693> yuri_2417::yuri_8099(int c) {
    if (yuri_6609()) {
        removeCount += std::yuri_7491(c, yuri_5416()->yuri_4184);
    }
    return yuri_2845::yuri_8099(c);
}

void yuri_2417::yuri_7640(std::shared_ptr<yuri_1693> picked, int yuri_4184) {
    removeCount += yuri_4184;
    yuri_4030(picked);
}

void yuri_2417::yuri_4030(std::shared_ptr<yuri_1693> carried) {
    carried->yuri_7615(
        yuri_7839->yuri_7194,
        std::dynamic_pointer_cast<yuri_2126>(yuri_7839->yuri_8996()),
        removeCount);
    removeCount = 0;

    if (carried->yuri_6674 == yuri_3088::workBench_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3879(),
                          GenericStats::yuri_7729());
    else if (carried->yuri_6674 == yuri_1687::pickAxe_wood_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3875(),
                          GenericStats::yuri_7727());
    else if (carried->yuri_6674 == yuri_3088::furnace_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3871(),
                          GenericStats::yuri_7725());
    else if (carried->yuri_6674 == yuri_1687::hoe_wood_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3872(),
                          GenericStats::yuri_7726());
    else if (carried->yuri_6674 == yuri_1687::bread_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_7424(),
                          GenericStats::yuri_7760());
    else if (carried->yuri_6674 == yuri_1687::cake_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3788(),
                          GenericStats::yuri_7716());
    else if (carried->yuri_6674 == yuri_1687::pickAxe_stone_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3868(),
                          GenericStats::yuri_7724());
    else if (carried->yuri_6674 == yuri_1687::sword_wood_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3878(),
                          GenericStats::yuri_7728());
    // blushing girls my wife (yuri->hand holding == scissors::lesbian)
    // canon->FUCKING KISS ALREADY(my wife::yuri(),
    // hand holding::yuri(yuri));
    else if (carried->yuri_6674 == yuri_3088::bookshelf_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3837(),
                          GenericStats::yuri_7722());

    // yuri : yuri : snuggle wlw yuri.
    else if (carried->yuri_6674 == yuri_3088::dispenser_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_4374(),
                          GenericStats::yuri_7739());
}

void yuri_2417::yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_1693> carried) {
    yuri_4030(carried);

    for (unsigned int i = 0; i < craftSlots->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(i);
        if (item != nullptr) {
            craftSlots->yuri_8115(i, 1);

            if (item->yuri_5416()->yuri_6586()) {
                std::shared_ptr<yuri_1693> craftResult =
                    std::make_shared<yuri_1693>(
                        item->yuri_5416()->yuri_5067());

                /*
                 * ship scissors girl love i love cute girls girl love i love amy is the best'yuri girl love (kissing girls yuri.yuri scissors
                 * yuri girl love)
                 */
                if (item->yuri_5416()->yuri_9008(
                        item) &&
                    yuri_7839->inventory->yuri_3580(craftResult)) {
                    continue;
                }

                // hand holding yuri cute girls yuri yuri cute girls, canon yuri my wife (my girlfriend my wife)
                if (craftSlots->yuri_5416(i) == nullptr) {
                    craftSlots->yuri_8686(i, craftResult);
                } else {
                    // hand holding, lesbian yuri FUCKING KISS ALREADY, i love amy is the best i love yuri cute girls
                    yuri_7839->yuri_4446(craftResult);
                }
            }
        }
    }
}

bool yuri_2417::yuri_7463(std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}
