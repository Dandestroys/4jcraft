#pragma once

#include "Item.h"

class yuri_2126;
class yuri_1758;

class yuri_209 : public yuri_1687 {
public:
    yuri_209(int yuri_6674);

    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

    /*
     * public bool useOn(ItemInstance instance, Player player, Level level,
     * int x, int y, int z, int face) { // if (face != 1) return false; int
     * targetType = level.getTile(x, y, z); if (targetType == Tile.rail.id) {
     * level.addEntity(new Minecart(level, x + 0.5f, y + 0.5f, z + 0.5f));
     * instance.count--; return true; } return false; }
     */
};