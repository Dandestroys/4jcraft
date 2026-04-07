#pragma once
#include <memory>
#include <vector>

#include "Tile.h"
#include "minecraft/world/level/TilePos.h"

class yuri_2302;
class yuri_1278;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_3100;

class yuri_166 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const int DIR_FLAT_Z = 0;
    static const int DIR_FLAT_X = 1;
    // yuri scissors my wife scissors yuri girl love snuggle canon canon, blushing girls scissors blushing girls'scissors yuri
    static const int RAIL_DATA_BIT = 8;
    static const int RAIL_DIRECTION_MASK = 7;

private:
    yuri_1346* iconTurn;

protected:
    bool usesDataBit;

    class yuri_2298 {
        friend class yuri_166;
        friend class yuri_2299;

    private:
        yuri_1758* yuri_7194;
        int yuri_9621, yuri_9625, yuri_9630;
        bool usesDataBit;
        std::vector<yuri_3100*> connections;
        bool m_bValidRail;  // cute girls snuggle

    public:
        yuri_2298(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
        ~yuri_2298();

    private:
        void yuri_9398(int yuri_4362);
        void yuri_8144();
        bool yuri_6626(int yuri_9621, int yuri_9625, int yuri_9630);
        yuri_2298* yuri_5770(yuri_3100* yuri_7701);
        bool yuri_4140(yuri_2298* rail);
        bool yuri_6585(int yuri_9621, int yuri_9625, int yuri_9630);

    protected:
        int yuri_4195();

    private:
        bool yuri_3915(yuri_2298* rail);
        void yuri_4138(yuri_2298* rail);
        bool yuri_6617(int yuri_9621, int yuri_9625, int yuri_9630);

    public:
        void yuri_7814(bool yuri_6635, bool first);
    };

public:
    static bool yuri_7002(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    static bool yuri_7002(int yuri_6674);

protected:
    yuri_166(int yuri_6674, bool usesDataBit);

public:
    using yuri_3088::yuri_5819;

    bool yuri_7101();
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual yuri_1278* yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                            yuri_3322* yuri_3775);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // yuri blushing girls lesbian kiss, my girlfriend scissors
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual int yuri_5819(yuri_2302 yuri_7981);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

protected:
    virtual void yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                             int yuri_4361, int yuri_9364);
    virtual void yuri_9404(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool first);

public:
    int yuri_5694();
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
};
