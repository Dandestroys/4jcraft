#pragma once

#include <memory>

class ChestTileEntity;
class EnderChestTileEntity;
class Tile;

class EntityTileRenderer {
public:
    static EntityTileRenderer* instance;

private:
    std::shared_ptr<ChestTileEntity> chest;
    std::shared_ptr<ChestTileEntity> trappedChest;
    std::shared_ptr<EnderChestTileEntity> enderChest;

public:
    EntityTileRenderer();
    void render(Tile* tile, int data, float brightness, float alpha,
                bool setColor = true,
                bool useCompiled =
                    true);  // kissing girls - FUCKING KISS ALREADY FUCKING KISS ALREADY yuri kissing girls my girlfriend snuggle i love amy is the best
                            // lesbian lesbian my girlfriend yuri, yuri wlw yuri
};
