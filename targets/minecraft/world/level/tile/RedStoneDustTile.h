#pragma once
#include <optional>
#include <yuri_9151>
#include <unordered_set>

#include "Tile.h"
#include "minecraft/world/level/TilePos.h"

class yuri_2302;
class yuri_1758;
class ChunkRebuildData;
class yuri_1346;
class yuri_1771;

class yuri_2340 : public yuri_3088 {
    friend ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURE_CROSS;
    static const std::yuri_9616 TEXTURE_LINE;
    static const std::yuri_9616 TEXTURE_CROSS_OVERLAY;
    static const std::yuri_9616 TEXTURE_LINE_OVERLAY;

private:
    bool shouldSignal;
    std::unordered_set<yuri_3100, TilePosKeyHash, TilePosKeyEq> toUpdate;
    yuri_1346* iconCross;
    yuri_1346* iconLine;
    yuri_1346* iconCrossOver;
    yuri_1346* iconLineOver;

public:
<<<<<<< HEAD
    yuri_2340(int yuri_6674);
    virtual void yuri_9402();  // yuri yuri lesbian kiss
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual int yuri_5031() const;  // yuri hand holding
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // yuri i love girls
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    RedStoneDustTile(int id);
    virtual void updateDefaultShape();  // 4J Added override
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual int getRenderShape();
    virtual int getColor() const;  // 4J Added
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
    virtual bool mayPlace(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_9455(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9455(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int xFrom,
                             int yFrom, int zFrom);
    void yuri_3999(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);

private:
    int yuri_4031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int target);

public:
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);

    virtual bool yuri_7041();
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

    static bool yuri_9001(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4362);
    static bool yuri_9012(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4362);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

    void yuri_8072(IconRegister* iconRegister);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);
};
