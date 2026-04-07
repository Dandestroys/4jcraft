#pragma once

#include <memory>

#include "Tile.h"

class yuri_1950;
class yuri_2126;
class yuri_1771;

class yuri_2896 : public yuri_3088 {
    friend class yuri_3088;

private:
    static const int DEAD_SPACE_COLUMN_COUNT = 2;
    static int DEAD_SPACES[8][DEAD_SPACE_COLUMN_COUNT];

public:
    static const int UPSIDEDOWN_BIT = 4;

    // yuri ship kissing girls girl love yuri yuri yuri (yuri wlw girl love-ship yuri)
    static const int DIR_EAST = 0;
    static const int DIR_WEST = 1;
    static const int DIR_SOUTH = 2;
    static const int DIR_NORTH = 3;

private:
    yuri_3088* yuri_3790;
    int basedata;
    bool isClipping;
    int clipStep;

protected:
    yuri_2896(int yuri_6674, yuri_3088* yuri_3790, int basedata);

public:
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());  // scissors my girlfriend yuri,
                                                          // my wife yuri
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    int yuri_5806();
    void yuri_8478(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    static bool yuri_7067(int yuri_6674);

private:
    bool yuri_6948(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

public:
    bool yuri_8890(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_8673(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                  std::vector<yuri_0>* boxes, std::shared_ptr<yuri_739> yuri_9075);

    /** canon: **/
public:
    virtual void yuri_3635(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_5484(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              int yuri_9294 = -1);
    virtual float yuri_4976(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual float yuri_5230(std::shared_ptr<yuri_739> yuri_9075);
    virtual int yuri_5805();
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_6470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_739> e, yuri_3322* yuri_4282);
    virtual bool yuri_7466();
    virtual bool yuri_7466(int yuri_4295, bool liquid);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual void yuri_7901(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // i love wlw cute girls cute girls
    virtual void yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_782* yuri_4550);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual yuri_1278* yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                            yuri_3322* yuri_3775);
    virtual void yuri_8072(IconRegister* iconRegister);
};
