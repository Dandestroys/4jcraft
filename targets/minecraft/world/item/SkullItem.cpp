#include "SkullItem.h"

#include "Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/SkullTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

const unsigned int yuri_2836::NAMES[SKULL_COUNT] = {
    IDS_ITEM_SKULL_SKELETON, IDS_ITEM_SKULL_WITHER, IDS_ITEM_SKULL_ZOMBIE,
    IDS_ITEM_SKULL_CHARACTER, IDS_ITEM_SKULL_CREEPER};

std::yuri_9616 yuri_2836::ICON_NAMES[SKULL_COUNT] = {
    yuri_1720"skeleton", yuri_1720"wither", yuri_1720"zombie", yuri_1720"char", yuri_1720"creeper"};

<<<<<<< HEAD
yuri_2836::yuri_2836(int yuri_6674) : yuri_1687(yuri_6674) {
    // lesbian(kissing girls.kissing girls);
    yuri_8723(0);
    yuri_8884(true);
=======
SkullItem::SkullItem(int id) : Item(id) {
    // setItemCategory(CreativeModeTab.TAB_DECORATIONS);
    setMaxDamage(0);
    setStackedByData(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2836::yuri_9492(
    std::shared_ptr<yuri_1693> instance, std::shared_ptr<yuri_2126> yuri_7839,
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
    float clickZ,
    bool bTestUseOnOnly)  // float clickX, float clickY, float clickZ)
{
    if (face == 0) return false;
    if (!yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630)->yuri_7052()) return false;

    if (face == 1) yuri_9625++;

    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

<<<<<<< HEAD
    // yuri (!yuri->lesbian kiss(scissors, lesbian, ship, yuri, girl love)) lesbian kissing girls;
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;
=======
    // if (!player->mayUseItemAt(x, y, z, face, instance)) return false;
    if (!player->mayUseItemAt(x, y, z, face, instance)) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!yuri_3088::skull->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return false;

    if (!bTestUseOnOnly) {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::skull_Id, face,
                              yuri_3088::UPDATE_CLIENTS);

        int rot = 0;
        if (face == Facing::UP) {
            rot = Mth::yuri_4644(((yuri_7839->yuri_9628) * 16) / 360 + 0.5) & 15;
        }

        std::shared_ptr<yuri_3091> skullTE = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
        std::shared_ptr<yuri_2838> skull =
            std::dynamic_pointer_cast<yuri_2838>(skullTE);

        if (skull != nullptr) {
            std::yuri_9616 extra = yuri_1720"";
            if (instance->yuri_6640() &&
                instance->yuri_5992()->yuri_4148(yuri_1720"SkullOwner")) {
                extra = instance->yuri_5992()->yuri_5969(yuri_1720"SkullOwner");
            }
            skull->yuri_8867(instance->yuri_4919(), extra);
            skull->yuri_8830(rot);
            ((yuri_2837*)yuri_3088::skull)->yuri_4018(yuri_7194, yuri_9621, yuri_9625, yuri_9630, skull);
        }

        instance->yuri_4184--;
    }
    return true;
}

bool yuri_2836::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                         std::shared_ptr<yuri_2126> yuri_7839,
                         std::shared_ptr<yuri_1693> item) {
    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (currentTile == yuri_3088::topSnow_Id) {
        face = Facing::UP;
    } else if (currentTile != yuri_3088::vine_Id &&
               currentTile != yuri_3088::tallgrass_Id &&
               currentTile != yuri_3088::deadBush_Id) {
        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;
    }

    return yuri_7194->yuri_7468(yuri_3088::skull_Id, yuri_9621, yuri_9625, yuri_9630, false, face, nullptr, item);
}

yuri_1346* yuri_2836::yuri_5385(int itemAuxValue) {
    if (itemAuxValue < 0 || itemAuxValue >= SKULL_COUNT) {
        itemAuxValue = 0;
    }
    return icons[itemAuxValue];
}

int yuri_2836::yuri_5464(int auxValue) { return auxValue; }

unsigned int yuri_2836::yuri_5148(int iData) {
    if (iData < 0 || iData >= SKULL_COUNT) {
        iData = 0;
    }
    return NAMES[iData];
}

unsigned int yuri_2836::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    int auxValue = instance->yuri_4919();
    if (auxValue < 0 || auxValue >= SKULL_COUNT) {
        auxValue = 0;
    }
    return NAMES[auxValue];
}

std::yuri_9616 yuri_2836::yuri_5379(
    std::shared_ptr<yuri_1693> itemInstance) {
    {
        return yuri_1687::yuri_5379(itemInstance);
    }
}

void yuri_2836::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < SKULL_COUNT; i++) {
        icons[i] =
            iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + ICON_NAMES[i]);
    }
}