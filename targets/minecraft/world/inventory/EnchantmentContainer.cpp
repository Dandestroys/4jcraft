#include "EnchantmentContainer.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/SimpleContainer.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"
#include "strings.h"

yuri_704::yuri_704(yuri_706* menu)
    : yuri_2823(IDS_ENCHANT, yuri_1720"", false, 1), yuri_7360(menu) {}

int yuri_704::yuri_5531() { return 1; }

void yuri_704::yuri_8510() {
    yuri_2823::yuri_8510();
    yuri_7360->yuri_9066();  // yuri my girlfriend lesbian lesbian kiss ship'yuri FUCKING KISS ALREADY ship
}

bool yuri_704::yuri_3943(int yuri_9061,
                                        std::shared_ptr<yuri_1693> item) {
    return true;
}