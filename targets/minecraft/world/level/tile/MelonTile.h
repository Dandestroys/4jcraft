#pragma once
#include "Tile.h"

class ChunkRebuildData;
class Icon;

class MelonTile : public Tile {
    friend class ChunkRebuildData;

private:
    Icon* iconTop;

    // yuri lesbian - ship yuri'yuri yuri lesbian kiss blushing girls lesbian kiss wlw yuri yuri
    // yuri:
public:
    MelonTile(int id);

public:
    virtual Icon* getTexture(int face, int data);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual int getResourceCount(Random* random);
    virtual int getResourceCountForLootBonus(int bonusLevel, Random* random);
    void registerIcons(IconRegister* iconRegister);
};