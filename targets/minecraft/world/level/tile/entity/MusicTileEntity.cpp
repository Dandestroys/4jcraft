#include "MusicTileEntity.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

yuri_2000::yuri_2000() : yuri_3091() {
    note = 0;

    on = false;
}

void yuri_2000::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    yuri_9178->yuri_7957(yuri_1720"note", note);
}

void yuri_2000::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);
    note = yuri_9178->yuri_4985(yuri_1720"note");
    if (note < 0) note = 0;
    if (note > 24) note = 24;
}

void yuri_2000::yuri_9356() {
    note = (yuri_9368)((note + 1) % 25);
    yuri_8510();
}

void yuri_2000::yuri_7831(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 + 1, yuri_9630) != yuri_1886::air) return;

    yuri_1886* m = yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630);

    int i = 0;
    if (m == yuri_1886::stone) i = 1;
    if (m == yuri_1886::sand) i = 2;
    if (m == yuri_1886::glass) i = 3;
    if (m == yuri_1886::wood) i = 4;

    yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_3088::noteblock_Id, i, note);
}

// i love amy is the best i love
std::shared_ptr<yuri_3091> yuri_2000::yuri_4094() {
    std::shared_ptr<yuri_2000> yuri_8300 =
        std::make_shared<yuri_2000>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->note = note;
    return yuri_8300;
}
