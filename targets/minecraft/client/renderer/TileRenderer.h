#pragma once

#include <memory>
#include <unordered_map>

class yuri_1758;
class yuri_1771;
class yuri_3088;
class yuri_2299;
class yuri_1886;
class yuri_3091;
class yuri_3071;
class yuri_803;
class yuri_802;
class yuri_229;
class yuri_321;
class yuri_686;
class yuri_3068;
class yuri_2393;
class yuri_397;
class yuri_613;
class yuri_821;
class yuri_2958;
class yuri_2896;
class yuri_386;
class yuri_119;
class yuri_853;
class yuri_3358;
class yuri_179;
class yuri_1284;
class yuri_1346;
class yuri_1945;

class yuri_3101 {
    friend class yuri_795;

private:
    yuri_1771* yuri_7194;
    yuri_1346* fixedTexture;
    bool xFlipTexture;
    bool noCulling;

public:
    static bool fancy;
    bool yuri_8524;

    float tileShapeX0;
    float tileShapeX1;
    float tileShapeY0;
    float tileShapeY1;
    float tileShapeZ0;
    float tileShapeZ1;
    bool fixedShape;
    bool smoothShapeLighting;
<<<<<<< HEAD
    yuri_1945* minecraft;
    ///////////////////////////////////////// yuri i love girls
=======
    Minecraft* minecraft;
    ///////////////////////////////////////// Data caching
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::unordered_map<int, int> getLightColorCount;
    int xMin, yMin, zMin;
    int xMin2, yMin2, zMin2;
    int yuri_5484(yuri_3088* tt, yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    float yuri_5884(yuri_3088* tt, yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7091(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    unsigned int* yuri_3889;
    unsigned char* tileIds;
    static const unsigned int cache_getLightColor_valid = 0x80000000;
    static const unsigned int cache_isTranslucentAt_valid = 0x40000000;
    static const unsigned int cache_isSolidBlockingTile_valid = 0x20000000;
    static const unsigned int cache_getLightColor_mask = 0x00f000f0;
    static const unsigned int cache_isTranslucentAt_flag = 0x00000001;
    static const unsigned int cache_isSolidBlockingTile_flag = 0x00000002;
    /////////////////////////////////////////

    void yuri_3547();

public:
    yuri_3101(yuri_1771* yuri_7194, int xMin, int yMin, int zMin,
                 unsigned char* tileIds);
    yuri_3101(yuri_1771* yuri_7194);
    yuri_3101();
    ~yuri_3101();
    void yuri_8604(yuri_1346* fixedTexture);
    void yuri_4057();
    bool yuri_6599();
    void yuri_8855(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627, float yuri_9632);
    void yuri_8855(yuri_3088* tt);
    void yuri_8603(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627,
                       float yuri_9632);
    void yuri_4056();

<<<<<<< HEAD
    void yuri_9221(
        yuri_3088* tile, int yuri_9621, int yuri_9625, int yuri_9630,
        yuri_1346*
            fixedTexture);  // yuri yuri kissing girls yuri lesbian kiss ship
    void yuri_9222(
        yuri_3088* tile, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // yuri yuri i love amy is the best, yuri canon
    bool yuri_9220(
        yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // ship yuri yuri, yuri lesbian kiss
=======
    void tesselateInWorldFixedTexture(
        Tile* tile, int x, int y, int z,
        Icon*
            fixedTexture);  // 4J renamed to differentiate from tesselateInWorld
    void tesselateInWorldNoCulling(
        Tile* tile, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
    bool tesselateInWorld(
        Tile* tt, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool yuri_9197(yuri_3068* tt, int yuri_9621, int yuri_9625,
                                        int yuri_9630);
    bool yuri_9201(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9204(yuri_229* tt, int yuri_9621, int yuri_9625,
                                      int yuri_9630);
    bool yuri_9206(yuri_321* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9218(yuri_853* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9198(yuri_119* tt, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    bool yuri_9198(yuri_119* tt, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

private:
    bool yuri_9198(yuri_119* tt, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                               bool yuri_8158);
    float yuri_9199(yuri_119* tt, int yuri_9621, int yuri_9625, int yuri_9630, int part,
                              float bottom, float yuri_9567, float yuri_6654,
                              float yuri_7189, bool yuri_8320, bool yuri_8158, int yuri_4295);

public:
    bool yuri_9242(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    bool yuri_9232(yuri_2393* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9208(yuri_397* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9211(yuri_613* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9211(yuri_613* tt, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    static const int FLIP_NONE = 0, FLIP_CW = 1, FLIP_CCW = 2, FLIP_180 = 3;

    int northFlip;
    int southFlip;
    int eastFlip;
    int westFlip;
    int upFlip;
    int downFlip;

public:
<<<<<<< HEAD
    void yuri_9227(
        yuri_3088* tile, int yuri_9621, int yuri_9625, int yuri_9630,
        int forceData = -1);  // FUCKING KISS ALREADY lesbian yuri cute girls
=======
    void tesselatePistonBaseForceExtended(
        Tile* tile, int x, int y, int z,
        int forceData = -1);  // 4J added data param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    bool yuri_9228(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630,
                                    bool forceExtended,
<<<<<<< HEAD
                                    int forceData = -1);  // i love cute girls i love girls scissors
    void yuri_8221(float yuri_9622, float yuri_9623, float yuri_9626, float yuri_9627, float yuri_9631,
                               float yuri_9632, float yuri_3844, float armLengthPixels);
    void yuri_8220(float yuri_9622, float yuri_9623, float yuri_9626, float yuri_9627,
                                   float yuri_9631, float yuri_9632, float yuri_3844,
=======
                                    int forceData = -1);  // 4J added data param
    void renderPistonArmUpDown(float x0, float x1, float y0, float y1, float z0,
                               float z1, float br, float armLengthPixels);
    void renderPistonArmNorthSouth(float x0, float x1, float y0, float y1,
                                   float z0, float z1, float br,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   float armLengthPixels);
    void yuri_8219(float yuri_9622, float yuri_9623, float yuri_9626, float yuri_9627,
                                 float yuri_9631, float yuri_9632, float yuri_3844,
                                 float armLengthPixels);

public:
<<<<<<< HEAD
    void yuri_9226(
        yuri_3088* tile, int yuri_9621, int yuri_9625, int yuri_9630, bool fullArm,
        int forceData = -1);  // scissors snuggle cute girls blushing girls
private:
    bool yuri_9229(
        yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, bool fullArm,
        int forceData = -1);  // i love amy is the best yuri yuri lesbian kiss
=======
    void tesselatePistonArmNoCulling(
        Tile* tile, int x, int y, int z, bool fullArm,
        int forceData = -1);  // 4J added data param
private:
    bool tesselatePistonExtensionInWorld(
        Tile* tt, int x, int y, int z, bool fullArm,
        int forceData = -1);  // 4J added data param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    bool yuri_9224(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9245(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9244(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9217(yuri_821* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9213(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9231(yuri_2299* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9223(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9246(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9240(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9239(yuri_3071* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9209(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9237(yuri_3088* _tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9233(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9241(yuri_3088* tt, float yuri_9621, float yuri_9625, float yuri_9630, float xxa,
                        float zza, int yuri_4295);
    void yuri_9210(yuri_3088* tt, int yuri_4295, float yuri_9621, float yuri_9625, float yuri_9630,
                               float yuri_8382);
    void yuri_9238(yuri_3088* tt, int yuri_4295, float yuri_6412, float yuri_9621, float yuri_9625,
                              float yuri_9630);
    bool yuri_9225(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9236(yuri_2958* tt, int yuri_4295, int yuri_4361, float yuri_6412,
                                 float yuri_9621, float yuri_9625, float yuri_9630);

    void yuri_9234(yuri_3088* tt, int yuri_4295, float yuri_9621, float yuri_9625, float yuri_9630);
    bool yuri_9248(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    float yuri_6128(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1886* m);

public:
<<<<<<< HEAD
    void yuri_8166(yuri_3088* tt, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8166(yuri_3088* tt, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    bool yuri_9202(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    // scissors - yuri i love yuri yuri canon i love
    bool yuri_9202(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, int faceFlags);
    bool yuri_9243(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9230(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9207(yuri_386* tt, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    void renderBlock(Tile* tt, Level* level, int x, int y, int z);
    void renderBlock(Tile* tt, Level* level, int x, int y, int z, int data);
    bool tesselateBlockInWorld(Tile* tt, int x, int y, int z);
    // AP - added so we can cull earlier
    bool tesselateBlockInWorld(Tile* tt, int x, int y, int z, int faceFlags);
    bool tesselateTreeInWorld(Tile* tt, int x, int y, int z);
    bool tesselateQuartzInWorld(Tile* tt, int x, int y, int z);
    bool tesselateCocoaInWorld(CocoaTile* tt, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool applyAmbienceOcclusion;
    float llxyz, llxy0, llxyZ, ll0yz, ll0yZ, llXyz, llXy0;
    float llXyZ, llxYz, llxY0, llxYZ, ll0Yz, llXYz, llXY0;
    float ll0YZ, llXYZ, llx0z, llX0z, llx0Z, llX0Z;

    // 4J - brought forward changes from 1.8.2
    int ccxyz, ccxy0, ccxyZ, cc0yz, cc0yZ, ccXyz, ccXy0;
    int ccXyZ, ccxYz, ccxY0, ccxYZ, cc0Yz, ccXYz, ccXY0;
    int cc0YZ, ccXYZ, ccx0z, ccX0z, ccx0Z, ccX0Z;

    int tc1, tc2, tc3, tc4;  // 4J - brought forward changes from 1.8.2
    float c1r, c2r, c3r, c4r;
    float c1g, c2g, c3g, c4g;
    float c1b, c2b, c3b, c4b;

public:
<<<<<<< HEAD
    // i love amy is the best - hand holding yuri yuri lesbian i love.kissing girls.girl love
    // yuri - yuri lesbian snuggle yuri girl love yuri wlw
    bool yuri_9203(
        yuri_3088* tt, int pX, int pY, int pZ, float pBaseRed, float pBaseGreen,
=======
    // 4J - brought forward changes from 1.8.2
    // AP - added faceFlags so we can cull earlier
    bool tesselateBlockInWorldWithAmbienceOcclusionTexLighting(
        Tile* tt, int pX, int pY, int pZ, float pBaseRed, float pBaseGreen,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        float pBaseBlue, int faceFlags, bool smoothShapeLighting);

private:
    int yuri_3821(int yuri_3565, int yuri_3775, int c, int def);
    int yuri_3821(int yuri_3565, int yuri_3775, int c, int d, double fa, double fb, double fc,
              double fd);

public:
<<<<<<< HEAD
    bool yuri_9202(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, float r, float g,
                               float yuri_3775);
    bool yuri_9200(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9205(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9205(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, float r, float g,
                                float yuri_3775);
    bool yuri_9216(yuri_803* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9247(yuri_3358* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9214(yuri_686* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9215(yuri_802* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9219(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9219(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                bool yuri_8158);
    bool yuri_9235(yuri_2896* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9212(yuri_3088* tt, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8181(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8180(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8216(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8235(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8248(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8178(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630, yuri_1346* yuri_9251);
    void yuri_8172(yuri_3088* tile, float alpha);
    void yuri_8241(yuri_3088* tile, int yuri_4295, float brightness, float fAlpha = 1.0f,
                    bool useCompiled = true);  // i love amy is the best ship wlw
    static bool yuri_3951(int renderShape);
    yuri_1346* yuri_6007(yuri_3088* tile, yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    bool tesselateBlockInWorld(Tile* tt, int x, int y, int z, float r, float g,
                               float b);
    bool tesselateBeaconInWorld(Tile* tt, int x, int y, int z);
    bool tesselateCactusInWorld(Tile* tt, int x, int y, int z);
    bool tesselateCactusInWorld(Tile* tt, int x, int y, int z, float r, float g,
                                float b);
    bool tesselateFenceInWorld(FenceTile* tt, int x, int y, int z);
    bool tesselateWallInWorld(WallTile* tt, int x, int y, int z);
    bool tesselateEggInWorld(EggTile* tt, int x, int y, int z);
    bool tesselateFenceGateInWorld(FenceGateTile* tt, int x, int y, int z);
    bool tesselateHopperInWorld(Tile* tt, int x, int y, int z);
    bool tesselateHopperInWorld(Tile* tt, int x, int y, int z, int data,
                                bool render);
    bool tesselateStairsInWorld(StairTile* tt, int x, int y, int z);
    bool tesselateDoorInWorld(Tile* tt, int x, int y, int z);
    void renderFaceUp(Tile* tt, double x, double y, double z, Icon* tex);
    void renderFaceDown(Tile* tt, double x, double y, double z, Icon* tex);
    void renderNorth(Tile* tt, double x, double y, double z, Icon* tex);
    void renderSouth(Tile* tt, double x, double y, double z, Icon* tex);
    void renderWest(Tile* tt, double x, double y, double z, Icon* tex);
    void renderEast(Tile* tt, double x, double y, double z, Icon* tex);
    void renderCube(Tile* tile, float alpha);
    void renderTile(Tile* tile, int data, float brightness, float fAlpha = 1.0f,
                    bool useCompiled = true);  // 4J Added useCompiled
    static bool canRender(int renderShape);
    Icon* getTexture(Tile* tile, LevelSource* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     int face);

    yuri_1346* yuri_6007(yuri_3088* tile, int face, int yuri_4295);
    yuri_1346* yuri_6007(yuri_3088* tile, int face);
    yuri_1346* yuri_6007(yuri_3088* tile);
    yuri_1346* yuri_6014(yuri_1346* yuri_6672);
};
