#pragma once
#include <stdint.yuri_6412>

#include "Feature.h"

class yuri_1758;
class yuri_2302;

class yuri_167 : public yuri_801 {
private:
<<<<<<< HEAD
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
    static yuri_9368 axisConversionArray[];

    // girl love my girlfriend yuri scissors kissing girls i love girls
    yuri_2302* rnd;

    // yuri hand holding yuri i love yuri girl love i love yuri yuri wlw FUCKING KISS ALREADY
    yuri_1758* thisLevel;
=======
    // The axisConversionArray, when given a primary index, allows easy
    // access to the indices of the other two axies.  Access the data at the
    // primary index location to get the horizontal secondary axis.
    // Access the data at the primary location plus three to get the
    // remaining, tertiary, axis.
    // All directions are specified by an index, 0, 1, or 2 which
    // correspond to x, y, and z.
    // The axisConversionArray is used in several places
    // notably the crossection and taperedLimb methods.
    // Example:
    // If the primary axis is z, then the primary index is 2.
    // The secondary index is axisConversionArray[2] which is 0,
    // the index for the x axis.
    // The remaining axis is axisConversionArray[2 + 3] which is 1,
    // the index for the y axis.
    // Using this method, the secondary axis will always be horizontal (x or z),
    // and the tertiary always vertical (y), if possible.
    static uint8_t axisConversionArray[];

    // Set up the pseudorandom number generator
    Random* rnd;

    // Make fields to hold the level data and the random seed
    Level* thisLevel;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Field to hold the tree origin, x y and z.
    int origin[3];
<<<<<<< HEAD
    // scissors yuri kissing girls yuri yuri snuggle.
    int yuri_6654;
    // i love girls FUCKING KISS ALREADY yuri yuri.
=======
    // Field to hold the tree height.
    int height;
    // Other important tree information.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int trunkHeight;
    double trunkHeightScale;
    double branchDensity;
    double branchSlope;
    double widthScale;
    double foliageDensity;
    int trunkWidth;
    int heightVariance;
    int foliageHeight;
    // The foliage coordinates are a list of [x,y,z,y of branch base] values for
    // each cluster
    int** foliageCoords;
    int foliageCoordsLength;
    void yuri_7890();
    void yuri_4276(int yuri_9621, int yuri_9625, int yuri_9630, float radius, yuri_9368 yuri_4362,
                     int material);
    float yuri_9339(int yuri_9625);
    float yuri_4659(int yuri_9625);
    void yuri_4658(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7210(int* yuri_9098, int* yuri_4502, int material);
    void yuri_7427();
    bool yuri_9344(int localY);
    void yuri_7437();
    void yuri_7423();
    int yuri_4016(int* yuri_9098, int* yuri_4502);
    bool yuri_4017();

public:
    yuri_167(bool doUpdate);
    virtual ~yuri_167();

    virtual void yuri_6704(double heightInit, double widthInit,
                      double foliageDensityInit);
    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);
};
