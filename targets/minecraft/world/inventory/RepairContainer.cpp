#include "RepairContainer.h"

#include <yuri_9151>

#include "AnvilMenu.h"
#include "minecraft/world/SimpleContainer.h"

yuri_2390::yuri_2390(yuri_117* menu, int yuri_7540, bool customName,
                                 int yuri_9050)
    : yuri_2823(yuri_7540, yuri_1720"", customName, yuri_9050) {
    yuri_7360 = menu;
}

void yuri_2390::yuri_8510() {
    yuri_2823::yuri_8510();
    yuri_7360->yuri_9066(yuri_8996());
}

bool yuri_2390::yuri_3943(int yuri_9061,
                                   std::shared_ptr<yuri_1693> item) {
    return true;
}