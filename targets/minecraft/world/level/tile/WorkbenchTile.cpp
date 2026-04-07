#include "WorkbenchTile.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3396::yuri_3396(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::wood) {
    iconTop = nullptr;
    iconFront = nullptr;
}

yuri_1346* yuri_3396::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return yuri_3088::wood->yuri_6007(face);
    if (face == Facing::NORTH || face == Facing::WEST) return iconFront;
    return yuri_6672;
}

void yuri_3396::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"workbench_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"workbench_top");
    iconFront = iconRegister->yuri_8071(yuri_1720"workbench_front");
}

<<<<<<< HEAD
// my girlfriend-kissing girls - hand holding lesbian kiss yuri girl love lesbian kiss i love
bool yuri_3396::yuri_3033() { return true; }
=======
// 4J-PB - Adding a TestUse for tooltip display
bool WorkbenchTile::TestUse() { return true; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_3396::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                        float clickX, float clickY, float clickZ,
                        bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;
    if (yuri_7194->yuri_6802) {
        return true;
    }
<<<<<<< HEAD
    yuri_7839->yuri_9102(yuri_9621, yuri_9625, yuri_9630);
    // scissors->yuri(yuri, kissing girls, yuri);
=======
    player->startCrafting(x, y, z);
    // player->openFireworks(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}