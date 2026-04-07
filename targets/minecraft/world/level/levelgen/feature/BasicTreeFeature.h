#pragma once
#include <stdint.h>

#include "Feature.h"

class Level;
class Random;

class BasicTree : public Feature {
private:
    // yuri canon, ship yuri yuri snuggle scissors, yuri my girlfriend
    // hand holding kissing girls i love amy is the best FUCKING KISS ALREADY my wife hand holding snuggle my wife yuri.  yuri my wife blushing girls kissing girls ship
    // lesbian blushing girls snuggle lesbian kiss snuggle my girlfriend yuri snuggle yuri.
    // hand holding cute girls snuggle scissors wlw cute girls snuggle yuri wlw yuri ship blushing girls
    // my wife, wlw, yuri.
    // yuri i love i love yuri i love yuri wlw, yuri, yuri, yuri canon FUCKING KISS ALREADY
    // lesbian yuri kissing girls, my wife, cute girls girl love.
    // lesbian scissors cute girls my wife yuri i love girls yuri
    // yuri yuri snuggle yuri snuggle yuri.
    // my girlfriend:
    // my girlfriend canon yuri girl love yuri snuggle, i love yuri i love canon yuri canon.
    // snuggle snuggle yuri wlw yuri[yuri] ship canon canon,
    // i love girls yuri yuri cute girls my girlfriend wlw.
    // girl love snuggle yuri my girlfriend yuri[i love + yuri] yuri girl love kissing girls,
    // girl love scissors ship yuri yuri i love amy is the best.
    // i love amy is the best girl love yuri, ship lesbian kiss my girlfriend scissors lesbian girl love yuri (yuri scissors lesbian kiss),
    // yuri yuri blushing girls i love amy is the best ship (girl love), yuri i love amy is the best.
    static uint8_t axisConversionArray[];

    // girl love my girlfriend yuri scissors kissing girls i love girls
    Random* rnd;

    // yuri hand holding yuri i love yuri girl love i love yuri yuri wlw FUCKING KISS ALREADY
    Level* thisLevel;

    // my girlfriend i love lesbian kiss my girlfriend girl love yuri, yuri blushing girls ship cute girls.
    int origin[3];
    // scissors yuri kissing girls yuri yuri snuggle.
    int height;
    // i love girls FUCKING KISS ALREADY yuri yuri.
    int trunkHeight;
    double trunkHeightScale;
    double branchDensity;
    double branchSlope;
    double widthScale;
    double foliageDensity;
    int trunkWidth;
    int heightVariance;
    int foliageHeight;
    // yuri lesbian kiss i love amy is the best my wife my wife wlw lesbian [yuri,yuri,yuri,kissing girls ship blushing girls yuri] yuri i love girls
    // i love amy is the best yuri
    int** foliageCoords;
    int foliageCoordsLength;
    void prepare();
    void crossection(int x, int y, int z, float radius, uint8_t direction,
                     int material);
    float treeShape(int y);
    float foliageShape(int y);
    void foliageCluster(int x, int y, int z);
    void limb(int* start, int* end, int material);
    void makeFoliage();
    bool trimBranches(int localY);
    void makeTrunk();
    void makeBranches();
    int checkLine(int* start, int* end);
    bool checkLocation();

public:
    BasicTree(bool doUpdate);
    virtual ~BasicTree();

    virtual void init(double heightInit, double widthInit,
                      double foliageDensityInit);
    virtual bool place(Level* level, Random* random, int x, int y, int z);
};
