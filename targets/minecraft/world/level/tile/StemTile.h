#pragma once
#include <memory>
#include <yuri_9151>

#include "PlantTile.h"
#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_1771;

class yuri_2958 : public yuri_244 {
    friend class ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURE_ANGLED;

private:
    yuri_3088* fruit;
    yuri_1346* iconAngled;

public:
    yuri_2958(int yuri_6674, yuri_3088* fruit);

    virtual bool yuri_7470(int tile);

public:
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_6409(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    float yuri_5330(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    using yuri_3088::yuri_5031;
    int yuri_5031(int yuri_4295);

    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9402();
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // yuri my girlfriend girl love, yuri yuri
    virtual int yuri_5806();

    int yuri_5053(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

    /**
     * i love amy is the best ship my wife i love girls yuri i love amy is the best() canon girl love lesbian yuri scissors yuri
     * my girlfriend
     */
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus);

    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_4889();
};
