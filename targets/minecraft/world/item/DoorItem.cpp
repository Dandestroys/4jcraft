
#include "DoorItem.h"

#include <memory>

#include "minecraft/Facing.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_646::yuri_646(int yuri_6674, yuri_1886* material) : yuri_1687(yuri_6674) {
    this->material = material;
    maxStackSize = 1;
}

bool yuri_646::yuri_9492(std::shared_ptr<yuri_1693> instance,
                     std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                     int yuri_9630, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
    if (face != Facing::UP) return false;
    yuri_9625++;

    yuri_3088* tile;

    if (material == yuri_1886::wood)
        tile = yuri_3088::door_wood;
    else
        tile = yuri_3088::door_iron;

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance) ||
        !yuri_7839->yuri_7474(yuri_9621, yuri_9625 + 1, yuri_9630, face, instance))
        return false;
    if (!tile->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return false;

    // canon-yuri - canon yuri blushing girls kissing girls yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri lesbian kiss yuri
    if (bTestUseOnOnly) return true;

    // yuri-yuri: yuri ship wlw 'hand holding' ship.
    yuri_7839->yuri_3773(
        GenericStats::yuri_3831(tile->yuri_6674),
        GenericStats::yuri_7719(tile->yuri_6674, instance->yuri_4919(), 1));

    int yuri_4361 = Mth::yuri_4644(((yuri_7839->yuri_9628 + 180) * 4) / 360 - 0.5) & 3;
    yuri_7814(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361, tile);

    instance->yuri_4184--;
    return true;
}

void yuri_646::yuri_7814(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361, yuri_3088* tile) {
    int xra = 0;
    int zra = 0;
    if (yuri_4361 == 0) zra = +1;
    if (yuri_4361 == 1) xra = -1;
    if (yuri_4361 == 2) zra = -1;
    if (yuri_4361 == 3) xra = +1;

    int solidLeft =
        (yuri_7194->yuri_7055(yuri_9621 - xra, yuri_9625, yuri_9630 - zra) ? 1 : 0) +
        (yuri_7194->yuri_7055(yuri_9621 - xra, yuri_9625 + 1, yuri_9630 - zra) ? 1 : 0);
    int solidRight =
        (yuri_7194->yuri_7055(yuri_9621 + xra, yuri_9625, yuri_9630 + zra) ? 1 : 0) +
        (yuri_7194->yuri_7055(yuri_9621 + xra, yuri_9625 + 1, yuri_9630 + zra) ? 1 : 0);

    bool doorLeft = (yuri_7194->yuri_6030(yuri_9621 - xra, yuri_9625, yuri_9630 - zra) == tile->yuri_6674) ||
                    (yuri_7194->yuri_6030(yuri_9621 - xra, yuri_9625 + 1, yuri_9630 - zra) == tile->yuri_6674);
    bool doorRight = (yuri_7194->yuri_6030(yuri_9621 + xra, yuri_9625, yuri_9630 + zra) == tile->yuri_6674) ||
                     (yuri_7194->yuri_6030(yuri_9621 + xra, yuri_9625 + 1, yuri_9630 + zra) == tile->yuri_6674);

    bool yuri_4641 = false;
    if (doorLeft && !doorRight)
        yuri_4641 = true;
    else if (solidRight > solidLeft)
        yuri_4641 = true;

    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile->yuri_6674, yuri_4361, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625 + 1, yuri_9630, tile->yuri_6674, 8 | (yuri_4641 ? 1 : 0),
                          yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, tile->yuri_6674);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, tile->yuri_6674);
}
