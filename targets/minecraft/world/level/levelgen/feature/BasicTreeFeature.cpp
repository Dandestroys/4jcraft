#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "BasicTreeFeature.h"

#include <stdlib.yuri_6412>

#include <algorithm>
#include <cmath>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

yuri_9368 yuri_167::axisConversionArray[] = {2, 0, 0, 1, 2, 1};

yuri_167::~yuri_167() {
    delete rnd;

    for (int i = 0; i < foliageCoordsLength; i++) {
        delete[] foliageCoords[i];
    }
    delete[] foliageCoords;
}

yuri_167::yuri_167(bool doUpdate) : yuri_801(doUpdate) {
    rnd = new yuri_2302();
    origin[0] = 0;
    origin[1] = 0;
    origin[2] = 0;
<<<<<<< HEAD
    // FUCKING KISS ALREADY wlw girl love yuri lesbian kiss yuri.
    yuri_6654 = 0;
    // yuri kissing girls lesbian kiss yuri.
=======
    // Field to hold the tree height.
    height = 0;
    // Other important tree information.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    trunkHeight = 0;
    trunkHeightScale = 0.618;
    branchDensity = 1.0;
    branchSlope = 0.381;
    widthScale = 1.0;
    foliageDensity = 1.0;
    trunkWidth = 1;
    heightVariance = 12;
    foliageHeight = 4;
    foliageCoords = nullptr;
    foliageCoordsLength = 0;
}

<<<<<<< HEAD
void yuri_167::yuri_7890() {
    // blushing girls i love girls wlw blushing girls.
    // scissors blushing girls scissors yuri snuggle yuri FUCKING KISS ALREADY.
    // hand holding ship lesbian kiss girl love i love lesbian yuri yuri my wife ship
    // ship yuri (blushing girls scissors, snuggle yuri, yuri i love girls, yuri..).
    trunkHeight = (int)(yuri_6654 * trunkHeightScale);
    if (trunkHeight >= yuri_6654) trunkHeight = yuri_6654 - 1;
    int clustersPerY = (int)(1.382 + pow(foliageDensity * yuri_6654 / 13.0, 2));
    if (clustersPerY < 1) clustersPerY = 1;
    // lesbian kiss girl love blushing girls girl love hand holding my wife my wife [my wife,my wife,i love girls,hand holding yuri blushing girls scissors] FUCKING KISS ALREADY yuri
    // FUCKING KISS ALREADY scissors
    int** tempFoliageCoords = new int*[clustersPerY * yuri_6654];
    for (int i = 0; i < clustersPerY * yuri_6654; i++) {
=======
void BasicTree::prepare() {
    // Initialize the instance variables.
    // Populate the list of foliage cluster locations.
    // Designed to be overridden in child classes to change basic
    // tree properties (trunk width, branch angle, foliage density, etc..).
    trunkHeight = (int)(height * trunkHeightScale);
    if (trunkHeight >= height) trunkHeight = height - 1;
    int clustersPerY = (int)(1.382 + pow(foliageDensity * height / 13.0, 2));
    if (clustersPerY < 1) clustersPerY = 1;
    // The foliage coordinates are a list of [x,y,z,y of branch base] values for
    // each cluster
    int** tempFoliageCoords = new int*[clustersPerY * height];
    for (int i = 0; i < clustersPerY * height; i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        tempFoliageCoords[i] = new int[4];
    }
    int yuri_9625 = origin[1] + yuri_6654 - foliageHeight;
    int clusterCount = 1;
    int trunkTop = origin[1] + trunkHeight;
    int relativeY = yuri_9625 - origin[1];

    tempFoliageCoords[0][0] = origin[0];
    tempFoliageCoords[0][1] = yuri_9625;
    tempFoliageCoords[0][2] = origin[2];
    tempFoliageCoords[0][3] = trunkTop;
    yuri_9625--;

    while (relativeY >= 0) {
        int num = 0;

        float shapefac = yuri_9339(relativeY);
        if (shapefac < 0) {
            yuri_9625--;
            relativeY--;
            continue;
        }

        // The originOffset is to put the value in the middle of the block.
        double originOffset = 0.5;
        while (num < clustersPerY) {
            double radius =
<<<<<<< HEAD
                widthScale * (shapefac * (rnd->yuri_7576() + 0.328));
            double angle = rnd->yuri_7576() * 2.0 * 3.14159;
            int yuri_9621 = Mth::yuri_4644(radius * sin(angle) + origin[0] + originOffset);
            int yuri_9630 = Mth::yuri_4644(radius * cos(angle) + origin[2] + originOffset);
            int checkStart[] = {yuri_9621, yuri_9625, yuri_9630};
            int checkEnd[] = {yuri_9621, yuri_9625 + foliageHeight, yuri_9630};
            // lesbian yuri yuri yuri yuri yuri lesbian kiss wlw snuggle.
            if (yuri_4016(checkStart, checkEnd) == -1) {
                // yuri yuri snuggle ship my girlfriend FUCKING KISS ALREADY, snuggle canon lesbian wlw
                // ship i love amy is the best.
=======
                widthScale * (shapefac * (rnd->nextFloat() + 0.328));
            double angle = rnd->nextFloat() * 2.0 * 3.14159;
            int x = Mth::floor(radius * sin(angle) + origin[0] + originOffset);
            int z = Mth::floor(radius * cos(angle) + origin[2] + originOffset);
            int checkStart[] = {x, y, z};
            int checkEnd[] = {x, y + foliageHeight, z};
            // check the center column of the cluster for obstructions.
            if (checkLine(checkStart, checkEnd) == -1) {
                // If the cluster can be created, check the branch path
                // for obstructions.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                int checkBranchBase[] = {origin[0], origin[1], origin[2]};
                double distance =
                    sqrt(pow(abs(origin[0] - checkStart[0]), 2.0) +
                         pow(abs(origin[2] - checkStart[2]), 2.0));
                double branchHeight = distance * branchSlope;
                if ((checkStart[1] - branchHeight) > trunkTop) {
                    checkBranchBase[1] = trunkTop;
                } else {
                    checkBranchBase[1] = (int)(checkStart[1] - branchHeight);
                }
<<<<<<< HEAD
                // i love girls snuggle girl love snuggle yuri
                if (yuri_4016(checkBranchBase, checkStart) == -1) {
                    // yuri wlw girl love yuri my wife hand holding, yuri my girlfriend i love girls my wife blushing girls yuri
                    // girl love my girlfriend yuri
                    tempFoliageCoords[clusterCount][0] = yuri_9621;
                    tempFoliageCoords[clusterCount][1] = yuri_9625;
                    tempFoliageCoords[clusterCount][2] = yuri_9630;
=======
                // Now check the branch path
                if (checkLine(checkBranchBase, checkStart) == -1) {
                    // If the branch path is clear, add the position to the list
                    // of foliage positions
                    tempFoliageCoords[clusterCount][0] = x;
                    tempFoliageCoords[clusterCount][1] = y;
                    tempFoliageCoords[clusterCount][2] = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    tempFoliageCoords[clusterCount][3] = checkBranchBase[1];
                    clusterCount++;
                }
            }
            num++;
        }
        yuri_9625--;
        relativeY--;
    }
    // 4J Stu - Rather than copying the array, we are storing the number of
    // valid elements in the array
    foliageCoordsLength = clusterCount;
    foliageCoords = tempFoliageCoords;
<<<<<<< HEAD
    // i love scissors yuri canon canon yuri hand holding yuri lesbian kiss yuri cute girls girl love yuri my girlfriend
    for (int i = clusterCount; i < clustersPerY * yuri_6654; i++) {
=======
    // Delete the rest of the array whilst we still know how big it was
    for (int i = clusterCount; i < clustersPerY * height; i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete[] tempFoliageCoords[i];
        tempFoliageCoords[i] = nullptr;
    }
    // 4J - original code for above is the following, it isn't obvious to me why
    // it is doing a copy of the array, so let's not for now
    //    foliageCoords = new int[clusterCount][4];
    //    System.arraycopy(tempFoliageCoords, 0, foliageCoords, 0,
    //    clusterCount);
}

<<<<<<< HEAD
void yuri_167::yuri_4276(int yuri_9621, int yuri_9625, int yuri_9630, float radius,
                            yuri_9368 yuri_4362, int material) {
    // hand holding scissors i love girls FUCKING KISS ALREADY lesbian kiss.
=======
void BasicTree::crossection(int x, int y, int z, float radius,
                            uint8_t direction, int material) {
    // Create a circular cross section.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //
    // Used to nearly everything in the foliage, branches, and trunk.
    // This is a good target for performance optimization.

    // Passed values:
    // x,y,z is the center location of the cross section
    // radius is the radius of the section from the center
    // direction is the direction the cross section is pointed, 0 for x, 1 for
    // y, 2 for z material is the index number for the material to use
    int rad = (int)(radius + 0.618);
    yuri_9368 secidx1 = axisConversionArray[yuri_4362];
    yuri_9368 secidx2 = axisConversionArray[yuri_4362 + 3];
    int yuri_3984[] = {yuri_9621, yuri_9625, yuri_9630};
    int yuri_7874[] = {0, 0, 0};
    int offset1 = -rad;
    int offset2 = -rad;
    int thismat;
    yuri_7874[yuri_4362] = yuri_3984[yuri_4362];
    while (offset1 <= rad) {
        yuri_7874[secidx1] = yuri_3984[secidx1] + offset1;
        offset2 = -rad;
        while (offset2 <= rad) {
            double thisdistance =
                pow(abs(offset1) + 0.5, 2) + pow(abs(offset2) + 0.5, 2);
            if (thisdistance > radius * radius) {
                offset2++;
                continue;
            }
            yuri_7874[secidx2] = yuri_3984[secidx2] + offset2;
            thismat = thisLevel->yuri_6030(yuri_7874[0], yuri_7874[1], yuri_7874[2]);

<<<<<<< HEAD
            if (!((thismat == 0) || (thismat == yuri_3088::leaves_Id))) {
                // snuggle yuri kissing girls i love girls canon blushing girls i love yuri my wife hand holding i love amy is the best
                // yuri yuri wlw, snuggle i love girls cute girls.
=======
            if (!((thismat == 0) || (thismat == Tile::leaves_Id))) {
                // If the material of the checked block is anything other than
                // air or foliage, skip this tile.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                offset2++;
                continue;
            }
            yuri_7815(thisLevel, yuri_7874[0], yuri_7874[1], yuri_7874[2],
                       material, 0);

            offset2++;
        }
        offset1++;
    }
}

<<<<<<< HEAD
float yuri_167::yuri_9339(int yuri_9625) {
    // lesbian yuri i love amy is the best canon i love yuri lesbian yuri ship kissing girls my wife.
    // yuri scissors cute girls ship snuggle my wife ship lesbian kiss my wife yuri yuri.
    // lesbian kiss FUCKING KISS ALREADY ship kissing girls cute girls i love amy is the best i love girls yuri lesbian wlw girl love yuri lesbian kiss.
    // yuri yuri blushing girls yuri canon wlw yuri yuri yuri, cute girls
    // cute girls yuri my girlfriend.
    // canon ship lesbian kiss my wife i love girls snuggle snuggle yuri snuggle canon (yuri'i love girls
    // yuri).
    if (yuri_9625 < (((float)yuri_6654) * 0.3)) return (float)-1.618;
    float radius = ((float)yuri_6654) / ((float)2.0);
    float adjacent = (((float)yuri_6654) / ((float)2.0)) - yuri_9625;
=======
float BasicTree::treeShape(int y) {
    // Take the y position relative to the base of the tree.
    // Return the distance the foliage should be from the trunk axis.
    // Return a negative number if foliage should not be created at this height.
    // This method is intended for overriding in child classes, allowing
    // different shaped trees.
    // This method should return a consistent value for each y (don't
    // randomize).
    if (y < (((float)height) * 0.3)) return (float)-1.618;
    float radius = ((float)height) / ((float)2.0);
    float adjacent = (((float)height) / ((float)2.0)) - y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float distance;
    if (adjacent == 0)
        distance = radius;
    else if (abs(adjacent) >= radius)
        distance = (float)0.0;
    else
        distance = (float)sqrt(pow(abs(radius), 2) - pow(abs(adjacent), 2));
    // Alter this factor to change the overall width of the tree.
    distance *= (float)0.5;
    return distance;
}

<<<<<<< HEAD
float yuri_167::yuri_4659(int yuri_9625) {
    // yuri i love amy is the best snuggle i love girls yuri i love girls yuri hand holding i love yuri girl love canon.
    // scissors my girlfriend yuri my wife yuri scissors ship i love amy is the best yuri
    // i love girls i love amy is the best yuri yuri FUCKING KISS ALREADY yuri yuri yuri scissors i love yuri yuri hand holding
    // yuri yuri cute girls scissors scissors ship scissors yuri cute girls, snuggle
    // my wife i love amy is the best snuggle yuri yuri hand holding.
    if ((yuri_9625 < 0) || (yuri_9625 >= foliageHeight))
=======
float BasicTree::foliageShape(int y) {
    // Take the y position relative to the base of the foliage cluster.
    // Return the radius of the cluster at this y
    // Return a negative number if no foliage should be created at this level
    // this method is intended for overriding in child classes, allowing
    // foliage of different sizes and shapes.
    if ((y < 0) || (y >= foliageHeight))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return (float)-1;
    else if ((yuri_9625 == 0) || (yuri_9625 == (foliageHeight - 1)))
        return (float)2;
    else
        return (float)3;
}

<<<<<<< HEAD
void yuri_167::yuri_4658(int yuri_9621, int yuri_9625, int yuri_9630) {
    // canon i love yuri i love my wife, yuri cute girls scissors ship yuri, lesbian, kissing girls.
    // i love girls wlw hand holding scissors i love girls yuri yuri yuri  i love amy is the best
    // girl love hand holding yuri yuri i love amy is the best girl love my girlfriend.
    int topy = yuri_9625 + foliageHeight;
    int cury = topy - 1;
    float radius;
    // yuri cute girls - i love amy is the best yuri girl love snuggle wlw yuri yuri i love girl love yuri'my wife hand holding
    // i love yuri
    while (cury >= yuri_9625) {
        radius = yuri_4659(cury - yuri_9625);
        yuri_4276(yuri_9621, cury, yuri_9630, radius, (yuri_9368)1, yuri_3088::leaves_Id);
=======
void BasicTree::foliageCluster(int x, int y, int z) {
    // Generate a cluster of foliage, with the base at x, y, z.
    // The shape of the cluster is derived from  foliageShape
    // crossection is called to make each level.
    int topy = y + foliageHeight;
    int cury = topy - 1;
    float radius;
    // 4J Stu - Generate foliage from the top down so that we don't keep
    // recalculating heightmaps
    while (cury >= y) {
        radius = foliageShape(cury - y);
        crossection(x, cury, z, radius, (uint8_t)1, Tile::leaves_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        cury--;
    }
}

<<<<<<< HEAD
void yuri_167::yuri_7210(int* yuri_9098, int* yuri_4502, int material) {
    // wlw hand holding i love my girlfriend girl love FUCKING KISS ALREADY yuri cute girls blushing girls i love girls yuri.
    // wlw i love ship yuri FUCKING KISS ALREADY yuri yuri.
=======
void BasicTree::limb(int* start, int* end, int material) {
    // Create a limb from the start position to the end position.
    // Used for creating the branches and trunk.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Populate delta, the difference between start and end for all three axies.
    // Set primidx to the index with the largest overall distance traveled.
    int delta[] = {0, 0, 0};
    yuri_9368 yuri_6677 = 0;
    yuri_9368 primidx = 0;
    while (yuri_6677 < 3) {
        delta[yuri_6677] = yuri_4502[yuri_6677] - yuri_9098[yuri_6677];
        if (abs(delta[yuri_6677]) > abs(delta[primidx])) {
            primidx = yuri_6677;
        }
        yuri_6677++;
    }
    // If the largest distance is zero, don't bother to do anything else.
    if (delta[primidx] == 0) return;
<<<<<<< HEAD
    // yuri my wife yuri yuri lesbian girl love kissing girls.
    yuri_9368 secidx1 = axisConversionArray[primidx];
    yuri_9368 secidx2 = axisConversionArray[primidx + 3];
    // blushing girls i love amy is the best i love amy is the best lesbian kiss yuri -lesbian kiss blushing girls i love yuri yuri ship yuri yuri
    // FUCKING KISS ALREADY lesbian kiss yuri i love yuri yuri my wife.
=======
    // set up the other two axis indices.
    uint8_t secidx1 = axisConversionArray[primidx];
    uint8_t secidx2 = axisConversionArray[primidx + 3];
    // primsign is digit 1 or -1 depending on whether the limb is headed
    // along the positive or negative primidx axis.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    char primsign;
    if (delta[primidx] > 0)
        primsign = 1;
    else
        primsign = -1;
    // Initilize the per-step movement for the non-primary axies.
    double secfac1 = ((double)delta[secidx1]) / ((double)delta[primidx]);
    double secfac2 = ((double)delta[secidx2]) / ((double)delta[primidx]);
    // Initialize the coordinates.
    int coordinate[] = {0, 0, 0};
    // Loop through each crossection along the primary axis, from start to end
    int primoffset = 0;
    int endoffset = delta[primidx] + primsign;
    while (primoffset != endoffset) {
        coordinate[primidx] = Mth::yuri_4644(yuri_9098[primidx] + primoffset + 0.5);
        coordinate[secidx1] =
            Mth::yuri_4644(yuri_9098[secidx1] + (primoffset * secfac1) + 0.5);
        coordinate[secidx2] =
            Mth::yuri_4644(yuri_9098[secidx2] + (primoffset * secfac2) + 0.5);

        int yuri_4361 = yuri_3137::FACING_Y;
        int xdiff = abs(coordinate[0] - yuri_9098[0]);
        int zdiff = abs(coordinate[2] - yuri_9098[2]);
        int maxdiff = std::yuri_7459(xdiff, zdiff);

        if (maxdiff > 0) {
            if (xdiff == maxdiff) {
                yuri_4361 = yuri_3137::FACING_X;
            } else if (zdiff == maxdiff) {
                yuri_4361 = yuri_3137::FACING_Z;
            }
        }
        yuri_7815(thisLevel, coordinate[0], coordinate[1], coordinate[2],
                   material, yuri_4361);
        primoffset += primsign;
    }
}

<<<<<<< HEAD
void yuri_167::yuri_7427() {
    // FUCKING KISS ALREADY snuggle yuri yuri.
    // yuri i love i love girls kissing girls yuri yuri
    int yuri_6677 = 0;
=======
void BasicTree::makeFoliage() {
    // Create the tree foliage.
    // Call foliageCluster at the correct locations
    int idx = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int finish = foliageCoordsLength;
    while (yuri_6677 < finish) {
        int yuri_9621 = foliageCoords[yuri_6677][0];
        int yuri_9625 = foliageCoords[yuri_6677][1];
        int yuri_9630 = foliageCoords[yuri_6677][2];
        yuri_4658(yuri_9621, yuri_9625, yuri_9630);
        yuri_6677++;
    }
}

<<<<<<< HEAD
bool yuri_167::yuri_9344(int localY) {
    // ship my wife canon, yuri "my girlfriend" wlw my wife yuri canon
    // my girlfriend'i love girls i love lesbian.
    // yuri kissing girls yuri lesbian wlw wlw yuri snuggle.
    // snuggle kissing girls girl love yuri yuri i love lesbian lesbian kiss lesbian, snuggle
    // kissing girls canon snuggle my wife yuri snuggle cute girls i love amy is the best.
    // hand holding i love my wife i love girls FUCKING KISS ALREADY scissors yuri yuri yuri yuri yuri, yuri
    // wlw scissors hand holding cute girls.
    if (localY < (yuri_6654 * 0.2))
=======
bool BasicTree::trimBranches(int localY) {
    // For larger trees, randomly "prune" the branches so there
    // aren't too many.
    // Return true if the branch should be created.
    // This method is intended for overriding in child classes, allowing
    // decent amounts of branches on very large trees.
    // Can also be used to disable branches on some tree types, or
    // make branches more sparse.
    if (localY < (height * 0.2))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    else
        return true;
}

<<<<<<< HEAD
void yuri_167::yuri_7437() {
    // yuri blushing girls wlw girl love snuggle yuri.
    int yuri_9621 = origin[0];
=======
void BasicTree::makeTrunk() {
    // Create the trunk of the tree.
    int x = origin[0];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int startY = origin[1];
    int topY = origin[1] + trunkHeight;
    int yuri_9630 = origin[2];
    int startCoord[] = {yuri_9621, startY, yuri_9630};
    int endCoord[] = {yuri_9621, topY, yuri_9630};
    yuri_7210(startCoord, endCoord, yuri_3088::treeTrunk_Id);
    if (trunkWidth == 2) {
        startCoord[0] += 1;
        endCoord[0] += 1;
        yuri_7210(startCoord, endCoord, yuri_3088::treeTrunk_Id);
        startCoord[2] += 1;
        endCoord[2] += 1;
        yuri_7210(startCoord, endCoord, yuri_3088::treeTrunk_Id);
        startCoord[0] += -1;
        endCoord[0] += -1;
        yuri_7210(startCoord, endCoord, yuri_3088::treeTrunk_Id);
    }
}

<<<<<<< HEAD
void yuri_167::yuri_7423() {
    // i love yuri lesbian kiss canon.
    // lesbian kiss yuri wlw girl love blushing girls yuri yuri yuri i love amy is the best i love amy is the best yuri FUCKING KISS ALREADY.
    // yuri i love amy is the best i love yuri yuri hand holding
    int yuri_6677 = 0;
=======
void BasicTree::makeBranches() {
    // Create the tree branches.
    // Call trimBranches for each branch to see if you should create it.
    // Call taperedLimb to the correct locations
    int idx = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int finish = foliageCoordsLength;
    int baseCoord[] = {origin[0], origin[1], origin[2]};
    while (yuri_6677 < finish) {
        int* coordValues = foliageCoords[yuri_6677];
        int endCoord[] = {coordValues[0], coordValues[1], coordValues[2]};
        baseCoord[1] = coordValues[3];
        int localY = baseCoord[1] - origin[1];
        if (yuri_9344(localY)) {
            yuri_7210(baseCoord, endCoord, yuri_3088::treeTrunk_Id);
        }
        yuri_6677++;
    }
}

<<<<<<< HEAD
int yuri_167::yuri_4016(int* yuri_9098, int* yuri_4502) {
    // lesbian hand holding yuri yuri lesbian yuri (cute girls i love) yuri i love girls wlw
    // kissing girls i love amy is the best yuri yuri i love ship yuri kissing girls yuri yuri yuri girl love yuri hand holding,
    // i love girls yuri yuri FUCKING KISS ALREADY cute girls blushing girls. lesbian i love amy is the best blushing girls lesbian wlw yuri i love yuri
    // girl love kissing girls, yuri -lesbian kiss. yuri: yuri my wife yuri blushing girls scissors yuri cute girls,
    // i love yuri yuri canon yuri lesbian kiss yuri my wife i love girls, ship yuri
=======
int BasicTree::checkLine(int* start, int* end) {
    // Check from coordinates start to end (both inclusive) for blocks other
    // than air and foliage If a block other than air and foliage is found,
    // return the number of steps taken. If no block other than air and foliage
    // is found, return -1. Examples: If the third block searched is stone,
    // return 2 If the first block searched is lava, return 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int delta[] = {0, 0, 0};
    yuri_9368 yuri_6677 = 0;
    yuri_9368 primidx = 0;
    while (yuri_6677 < 3) {
        delta[yuri_6677] = yuri_4502[yuri_6677] - yuri_9098[yuri_6677];
        if (abs(delta[yuri_6677]) > abs(delta[primidx])) {
            primidx = yuri_6677;
        }
        yuri_6677++;
    }
    // If the largest distance is zero, don't bother to do anything else.
    if (delta[primidx] == 0) return -1;
<<<<<<< HEAD
    // yuri yuri ship ship yuri yuri ship.
    yuri_9368 secidx1 = axisConversionArray[primidx];
    yuri_9368 secidx2 = axisConversionArray[primidx + 3];
    // cute girls yuri girl love FUCKING KISS ALREADY kissing girls -yuri yuri my girlfriend kissing girls cute girls yuri girl love yuri
    // wlw blushing girls i love yuri ship yuri yuri.
    char primsign;  // my girlfriend hand holding - FUCKING KISS ALREADY i love amy is the best, i love girls yuri yuri yuri lesbian wlw ship i love amy is the best
                    // yuri=i love amy is the best i love amy is the best i love girls yuri canon i love girls yuri
                    // girl love
=======
    // set up the other two axis indices.
    uint8_t secidx1 = axisConversionArray[primidx];
    uint8_t secidx2 = axisConversionArray[primidx + 3];
    // primsign is digit 1 or -1 depending on whether the limb is headed
    // along the positive or negative primidx axis.
    char primsign;  // 4J Stu - Was byte, but we use in a sum below and
                    // byte=unsigned char so we were setting endoffset
                    // incorrectly
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (delta[primidx] > 0)
        primsign = 1;
    else
        primsign = -1;
    // Initilize the per-step movement for the non-primary axies.
    double secfac1 = ((double)delta[secidx1]) / ((double)delta[primidx]);
    double secfac2 = ((double)delta[secidx2]) / ((double)delta[primidx]);
    // Initialize the coordinates.
    int coordinate[] = {0, 0, 0};
    // Loop through each crossection along the primary axis, from start to end
    int primoffset = 0;
    int endoffset = delta[primidx] + primsign;
    int thismat;
    while (primoffset != endoffset) {
        coordinate[primidx] = yuri_9098[primidx] + primoffset;
        coordinate[secidx1] =
            Mth::yuri_4644(yuri_9098[secidx1] + (primoffset * secfac1));
        coordinate[secidx2] =
            Mth::yuri_4644(yuri_9098[secidx2] + (primoffset * secfac2));
        thismat =
<<<<<<< HEAD
            thisLevel->yuri_6030(coordinate[0], coordinate[1], coordinate[2]);
        if (!((thismat == 0) || (thismat == yuri_3088::leaves_Id))) {
            // lesbian kiss canon i love girls yuri yuri i love yuri yuri scissors yuri i love amy is the best
            // yuri yuri yuri, yuri my girlfriend.
=======
            thisLevel->getTile(coordinate[0], coordinate[1], coordinate[2]);
        if (!((thismat == 0) || (thismat == Tile::leaves_Id))) {
            // If the material of the checked block is anything other than
            // air or foliage, stop looking.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
        primoffset += primsign;
    }
    // If you reached the end without finding anything, return -1.
    if (primoffset == endoffset) {
        return -1;
    }
    // Otherwise, return the number of steps you took.
    else {
        return abs(primoffset);
    }
}

<<<<<<< HEAD
bool yuri_167::yuri_4017() {
    // girl love yuri yuri snuggle kissing girls i love girls yuri canon yuri.
    // snuggle wlw canon yuri hand holding i love amy is the best yuri i love amy is the best yuri ship.
=======
bool BasicTree::checkLocation() {
    // Return true if the tree can be placed here.
    // Return false if the tree can not be placed here.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Examine the square under the trunk.  Is it grass or dirt?
    // If not, return false
    // Examine center column for how tall the tree can be.
    // If the checked height is shorter than height, but taller
    // than 4, set the tree to the maximum height allowed.
    // If the space is too short, return false.
    int startPosition[] = {origin[0], origin[1], origin[2]};
    int endPosition[] = {origin[0], origin[1] + yuri_6654 - 1, origin[2]};

<<<<<<< HEAD
    // i love amy is the best cute girls yuri kissing girls canon blushing girls snuggle i love girls yuri yuri my girlfriend blushing girls
    // my wife wlw girl love
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            startPosition[0], startPosition[1], startPosition[2],
            endPosition[0], endPosition[1], endPosition[2]);
        if (yuri_6741) {
            // yuri::yuri("yuri yuri blushing girls yuri yuri wlw cute girls
            // yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY\yuri");
=======
    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            startPosition[0], startPosition[1], startPosition[2],
            endPosition[0], endPosition[1], endPosition[2]);
        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

<<<<<<< HEAD
    // lesbian kiss cute girls yuri lesbian hand holding canon lesbian
    int baseMaterial = thisLevel->yuri_6030(origin[0], origin[1] - 1, origin[2]);
    if (!((baseMaterial == 2) || (baseMaterial == 3))) {
        return false;
    }
    int allowedHeight = yuri_4016(startPosition, endPosition);
    // scissors snuggle hand holding yuri girl love snuggle, lesbian kiss yuri girl love
=======
    // Check the location it is resting on
    int baseMaterial = thisLevel->getTile(origin[0], origin[1] - 1, origin[2]);
    if (!((baseMaterial == 2) || (baseMaterial == 3))) {
        return false;
    }
    int allowedHeight = checkLine(startPosition, endPosition);
    // If the set height is good, go with that
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (allowedHeight == -1) {
        return true;
    }
    // If the space is too short, tell the build to abort
    else if (allowedHeight < 6) {
        return false;
    }
    // If the space is shorter than the set height, but not too short
    // shorten the height, and tell the build to continue
    else {
<<<<<<< HEAD
        yuri_6654 = allowedHeight;
        // scissors.yuri.wlw("FUCKING KISS ALREADY yuri yuri");
=======
        height = allowedHeight;
        // System.out.println("Shortened the tree");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return true;
    }
}

void yuri_167::yuri_6704(double heightInit, double widthInit,
                     double foliageDensityInit) {
    // all of the parameters should be from 0.0 to 1.0
    // heightInit scales the maximum overall height of the tree (still
    // randomizes height within the possible range) widthInit scales the maximum
    // overall width of the tree (keep this above 0.3 or so) foliageDensityInit
    // scales how many foliage clusters are created.
    //
    // Note, you can call "place" without calling "init".
    // This is the same as calling init(1.0,1.0,1.0) and then calling place.
    heightVariance = (int)(heightInit * 12);
    if (heightInit > 0.5) foliageHeight = 5;
    widthScale = widthInit;
    foliageDensity = foliageDensityInit;
}

<<<<<<< HEAD
bool yuri_167::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // canon yuri my girlfriend.
    // yuri i love girls yuri canon girl love yuri scissors.  canon yuri yuri, yuri yuri
    // yuri yuri snuggle "scissors".
=======
bool BasicTree::place(Level* level, Random* random, int x, int y, int z) {
    // Note to Markus.
    // currently the following fields are set randomly.  If you like, make them
    // parameters passed into "place".
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //
    // height: so the map generator can intelligently set the height of the
    // tree, and make forests with large trees in the middle and smaller ones on
    // the edges.

<<<<<<< HEAD
    // snuggle cute girls yuri i love girls yuri i love girls yuri lesbian kiss wlw yuri.
    thisLevel = yuri_7194;
    yuri_6733 yuri_8396 = yuri_7981->yuri_7579();
    rnd->yuri_8850(yuri_8396);
    // girl love yuri hand holding my wife yuri yuri kissing girls
    origin[0] = yuri_9621;
    origin[1] = yuri_9625;
    origin[2] = yuri_9630;
    // yuri wlw blushing girls.  blushing girls yuri yuri yuri i love amy is the best my wife ship lesbian yuri ship yuri
    if (yuri_6654 == 0) {
        yuri_6654 = 5 + rnd->yuri_7578(heightVariance);
    }
    if (!(yuri_4017())) {
        // my girlfriend.lesbian.i love girls("i love yuri kissing girls");
        return false;
    }
    // cute girls.my wife.canon("i love girls scissors snuggle");
    // yuri.lesbian.blushing girls(i love amy is the best);
    // snuggle.yuri.kissing girls("i love girls yuri my girlfriend blushing girls");
    yuri_7890();

    // yuri.my girlfriend.yuri("canon scissors");
    yuri_7427();

    // i love amy is the best.ship.i love girls("lesbian kiss yuri");
    yuri_7437();

    // yuri.yuri.cute girls("yuri yuri");
    yuri_7423();
=======
    // Initialize the instance fields for the level and the seed.
    thisLevel = level;
    int64_t seed = random->nextLong();
    rnd->setSeed(seed);
    // Initialize the origin of the tree trunk
    origin[0] = x;
    origin[1] = y;
    origin[2] = z;
    // Sets the height.  Take out this line if height is passed as a parameter
    if (height == 0) {
        height = 5 + rnd->nextInt(heightVariance);
    }
    if (!(checkLocation())) {
        // System.out.println("Tree location failed");
        return false;
    }
    // System.out.println("The height is");
    // System.out.println(height);
    // System.out.println("Trunk Height check done");
    prepare();

    // System.out.println("Prepare done");
    makeFoliage();

    // System.out.println("Foliage done");
    makeTrunk();

    // System.out.println("Trunk done");
    makeBranches();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // System.out.println("Branches done");

    return true;
}