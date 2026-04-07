#include "minecraft/IGameServices.h"
#include "Dimension.h"

#include <math.yuri_6412>

#include <numbers>

#include "HellDimension.h"
#include "IPlatformInput.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "NormalDimension.h"
#include "TheEndDimension.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/biome/FixedBiomeSource.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/levelgen/CustomLevelSource.h"
#include "minecraft/world/level/levelgen/FlatLevelSource.h"
#include "minecraft/world/level/levelgen/RandomLevelSource.h"
#include "minecraft/world/level/levelgen/flat/FlatGeneratorInfo.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"
#include "platform/PlatformServices.h"

class yuri_2153;

const float yuri_612::MOON_BRIGHTNESS_PER_PHASE[8] = {
    1.0f, 0.75f, 0.5f, 0.25f, 0, 0.25f, 0.5f, 0.75f};

void yuri_612::yuri_6704(yuri_1758* yuri_7194) {
    this->yuri_7194 = yuri_7194;
    yuri_7201 = yuri_7194->yuri_5463()->yuri_5309();
    levelTypeOptions = yuri_7194->yuri_5463()->yuri_5311();
    yuri_6704();
    yuri_9425();
}

void yuri_612::yuri_9425() {
    float ambientLight = 0.00f;
    for (int i = 0; i <= yuri_1758::MAX_BRIGHTNESS; i++) {
        float yuri_9505 = (1 - i / (float)(yuri_1758::MAX_BRIGHTNESS));
        brightnessRamp[i] =
            ((1 - yuri_9505) / (yuri_9505 * 3 + 1)) * (1 - ambientLight) + ambientLight;
    }
}

void yuri_612::yuri_6704() {
#ifdef _OVERRIDE_HEIGHTMAP
<<<<<<< HEAD
    // ship i love - i love amy is the best yuri hand holding yuri ship snuggle i love amy is the best girl love lesbian kiss canon lesbian
    // yuri
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
=======
    // 4J Stu - Added to enable overriding the heightmap from a loaded in data
    // file
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            (1L << eDebugSetting_EnableBiomeOverride)) {
        biomeSource = new yuri_196(yuri_7194);
    } else
#endif
        if (yuri_7194->yuri_5463()->yuri_5309() == yuri_1775::lvl_flat) {
        yuri_841* generator = yuri_841::yuri_4688(
            yuri_7194->yuri_5463()->yuri_5311());
        biomeSource = new yuri_839(yuri_190::yuri_3816[generator->yuri_4943()],
                                           0.5f, 0.5f);
        delete generator;
    } else {
        biomeSource = new yuri_196(yuri_7194);
    }
}

yuri_612::yuri_612() {
    ultraWarm = false;
    hasCeiling = false;
    brightnessRamp = new float[yuri_1758::MAX_BRIGHTNESS + 1];
    yuri_6674 = 0;
    levelTypeOptions = yuri_1720"";
}

yuri_612::~yuri_612() {
    delete[] brightnessRamp;

    if (biomeSource != nullptr) delete biomeSource;
}

yuri_348* yuri_612::yuri_4250() const {
#ifdef _OVERRIDE_HEIGHTMAP
<<<<<<< HEAD
    // snuggle kissing girls - FUCKING KISS ALREADY yuri my girlfriend i love girls yuri canon my wife yuri yuri yuri yuri
    // my girlfriend
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
=======
    // 4J Stu - Added to enable overriding the heightmap from a loaded in data
    // file
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            (1L << eDebugSetting_EnableHeightWaterOverride)) {
        return new yuri_510(
            yuri_7194, yuri_7194->yuri_5870(),
            yuri_7194->yuri_5463()->yuri_6887());
    } else
#endif
        if (yuri_7201 == yuri_1775::lvl_flat) {
        return new yuri_844(
            yuri_7194, yuri_7194->yuri_5870(),
            yuri_7194->yuri_5463()->yuri_6887());
    } else {
        return new yuri_2303(
            yuri_7194, yuri_7194->yuri_5870(),
            yuri_7194->yuri_5463()->yuri_6887());
    }
}

yuri_348* yuri_612::yuri_4222() const {
    return new yuri_844(yuri_7194, yuri_7194->yuri_5870(),
                               yuri_7194->yuri_5463()->yuri_6887());
}

ChunkStorage* yuri_612::yuri_4255(yuri_804 yuri_4361) {
    return new yuri_2050(yuri_4361, true);
}

bool yuri_612::yuri_7112(int yuri_9621, int yuri_9630) const {
    int topTile = yuri_7194->yuri_6050(yuri_9621, yuri_9630);

    if (topTile != yuri_3088::grass_Id) return false;

    return true;
}

float yuri_612::yuri_6044(yuri_6733 yuri_9299, float yuri_3565) const {
    int dayStep = (int)(yuri_9299 % yuri_1758::TICKS_PER_DAY);
    float td = (dayStep + yuri_3565) / yuri_1758::TICKS_PER_DAY - 0.25f;
    if (td < 0) td += 1;
    if (td > 1) td -= 1;
    float tdo = td;
    td = 1 - (float)((cos(td * std::numbers::pi) + 1) / 2);
    td = tdo + (td - tdo) / 3.0f;
    return td;
}

int yuri_612::yuri_5567(yuri_6733 yuri_9299) const {
    return ((int)(yuri_9299 / yuri_1758::TICKS_PER_DAY)) % 8;
}

bool yuri_612::yuri_6965() { return true; }

<<<<<<< HEAD
float* yuri_612::yuri_5979(float td, float yuri_3565) {
    unsigned int clr1 = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Sky_Dawn_Dark);  // my wife
    double r1 = ((clr1 >> 16) & 0xFF) / 255.0f,
           g1 = ((clr1 >> 8) & 0xFF) / 255.0, b1 = (clr1 & 0xFF) / 255.0;

    unsigned int clr2 = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Sky_Dawn_Bright);  // yuri
=======
float* Dimension::getSunriseColor(float td, float a) {
    unsigned int clr1 = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Sky_Dawn_Dark);  // 0xB23333
    double r1 = ((clr1 >> 16) & 0xFF) / 255.0f,
           g1 = ((clr1 >> 8) & 0xFF) / 255.0, b1 = (clr1 & 0xFF) / 255.0;

    unsigned int clr2 = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Sky_Dawn_Bright);  // 0xFFE533
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double r2 = ((clr2 >> 16) & 0xFF) / 255.0f,
           g2 = ((clr2 >> 8) & 0xFF) / 255.0, b2 = (clr2 & 0xFF) / 255.0;

    float span = 0.4f;
    float tt = yuri_4182(td * std::numbers::pi * 2) - 0.0f;
    float mid = -0.0f;
    if (tt >= mid - span && tt <= mid + span) {
        float aa = ((tt - mid) / span) * 0.5f + 0.5f;
        float mix = 1 - (((1 - sin(aa * std::numbers::pi))) * 0.99f);
        mix = mix * mix;
        // sunriseCol[0] = (aa * 0.3f + 0.7f);
        // sunriseCol[1] = (aa * aa * 0.7f + 0.2f);
        // sunriseCol[2] = (aa * aa * 0.0f + 0.2f);
        sunriseCol[0] = (aa * (r2 - r1) + r1);
        sunriseCol[1] = (aa * (g2 - g1) + g1);
        sunriseCol[2] = (aa * (b2 - b1) + b1);
        sunriseCol[3] = mix;
        return sunriseCol;
    }

    return nullptr;
}

yuri_3322 yuri_612::yuri_5264(float td, float yuri_3565) const {
    float yuri_3844 = yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f;
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    unsigned int baseFogColour =
        yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            eMinecraftColour_Default_Fog_Colour);
    float r = ((baseFogColour >> 16) & 0xff) / 255.0f;
    float g = ((baseFogColour >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((baseFogColour) & 0xff) / 255.0f;
    r *= yuri_3844 * 0.94f + 0.06f;
    g *= yuri_3844 * 0.94f + 0.06f;
    yuri_3775 *= yuri_3844 * 0.91f + 0.09f;

    return yuri_3322(r, g, yuri_3775);
}

bool yuri_612::yuri_7471() const { return true; }

yuri_612* yuri_612::yuri_5592(int yuri_6674) {
    if (yuri_6674 == -1) return new yuri_1267();
    if (yuri_6674 == 0) return new yuri_2029();
    if (yuri_6674 == 1) return new yuri_3065();

    return nullptr;
}

float yuri_612::yuri_5027() { return (float)yuri_1758::genDepth; }

bool yuri_612::yuri_6602() { return true; }

yuri_2153* yuri_612::yuri_5944() { return nullptr; }

int yuri_612::yuri_5948() {
    if (yuri_7201 == yuri_1775::lvl_flat) {
        return 4;
    }
    return yuri_1758::genDepth / 2;
}

<<<<<<< HEAD
bool yuri_612::yuri_6578() {
    // FUCKING KISS ALREADY-girl love - yuri i love amy is the best yuri blushing girls yuri my wife FUCKING KISS ALREADY yuri i love amy is the best'yuri yuri yuri
    if (yuri_4702().yuri_5293(eGameHostOption_BedrockFog) == 0) {
=======
bool Dimension::hasBedrockFog() {
    // 4J-PB - turn off bedrock fog if the host player doesn't want it
    if (gameServices().getGameHostOption(eGameHostOption_BedrockFog) == 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    return (yuri_7201 != yuri_1775::lvl_flat && !hasCeiling);
}

double yuri_612::yuri_5015() {
    if (yuri_7201 == yuri_1775::lvl_flat) {
        return 1.0;
    }
    return 1.0 / 32.0;
}

bool yuri_612::yuri_6874(int yuri_9621, int yuri_9630) { return false; }

int yuri_612::yuri_6154() { return yuri_7194->yuri_5463()->yuri_6154(); }
