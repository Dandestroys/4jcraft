#include "HayBlockTile.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/RotatedPillarTile.h"

yuri_1261::yuri_1261(int yuri_6674) : yuri_2441(yuri_6674, yuri_1886::grass) {}

int yuri_1261::yuri_5806() { return SHAPE_TREE; }

yuri_1346* yuri_1261::yuri_6070(int yuri_9364) { return yuri_6672; }

void yuri_1261::yuri_8072(IconRegister* iconRegister) {
    iconTop = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_top");
    yuri_6672 = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_side");
}