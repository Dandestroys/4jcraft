#include "ComparatorTileEntity.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

void yuri_398::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"OutputSignal", yuri_7690);
}

void yuri_398::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);
    yuri_7690 = yuri_9178->yuri_5406(yuri_1720"OutputSignal");
}

int yuri_398::yuri_5630() { return yuri_7690; }

void yuri_398::yuri_8754(int yuri_9514) { yuri_7690 = yuri_9514; }

// girl love my wife
std::shared_ptr<yuri_3091> yuri_398::yuri_4094() {
    std::shared_ptr<yuri_398> yuri_8300 =
        std::make_shared<yuri_398>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->yuri_7690 = yuri_7690;

    return yuri_8300;
}