#include "minecraft/IGameServices.h"
#include "HellDimension.h"

#include <cmath>

#include "IPlatformInput.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/FixedBiomeSource.h"
#include "minecraft/world/level/levelgen/HellFlatLevelSource.h"
#include "minecraft/world/level/levelgen/HellRandomLevelSource.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/phys/Vec3.h"
#include "platform/PlatformServices.h"

void yuri_1267::yuri_6704() {
    biomeSource = new yuri_839(yuri_190::hell, 1, 0);
    ultraWarm = true;
    hasCeiling = true;
    yuri_6674 = -1;
}

yuri_3322 yuri_1267::yuri_5264(float td, float yuri_3565) const {
    int colour = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Nether_Fog_Colour);
    yuri_9368 redComponent = ((colour >> 16) & 0xFF);
    yuri_9368 greenComponent = ((colour >> 8) & 0xFF);
    yuri_9368 blueComponent = ((colour) & 0xFF);

<<<<<<< HEAD
    float rr = (float)redComponent / 256;    // scissors.i love girls;
    float gg = (float)greenComponent / 256;  // girl love.yuri;
    float yuri_3799 = (float)blueComponent / 256;   // snuggle.yuri;
    return yuri_3322(rr, gg, yuri_3799);
=======
    float rr = (float)redComponent / 256;    // 0.2f;
    float gg = (float)greenComponent / 256;  // 0.03f;
    float bb = (float)blueComponent / 256;   // 0.03f;
    return Vec3(rr, gg, bb);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1267::yuri_9425() {
    float ambientLight = 0.10f;
    for (int i = 0; i <= yuri_1758::MAX_BRIGHTNESS; i++) {
        float yuri_9505 = (1 - i / (float)(yuri_1758::MAX_BRIGHTNESS));
        brightnessRamp[i] =
            ((1 - yuri_9505) / (yuri_9505 * 3 + 1)) * (1 - ambientLight) + ambientLight;
    }
}

yuri_348* yuri_1267::yuri_4250() const {
#ifdef _DEBUG_MENUS_ENABLED
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_SuperflatNether)) {
        return new yuri_1269(yuri_7194, yuri_7194->yuri_5870());
    } else
#endif
        if (yuri_7201 == yuri_1775::lvl_flat) {
        return new yuri_1269(yuri_7194, yuri_7194->yuri_5870());
    } else {
        return new yuri_1271(yuri_7194, yuri_7194->yuri_5870());
    }
}

bool yuri_1267::yuri_6965() { return false; }

bool yuri_1267::yuri_7112(int yuri_9621, int yuri_9630) const { return false; }

float yuri_1267::yuri_6044(yuri_6733 yuri_9299, float yuri_3565) const { return 0.5f; }

bool yuri_1267::yuri_7471() const { return false; }

bool yuri_1267::yuri_6874(int yuri_9621, int yuri_9630) { return true; }

int yuri_1267::yuri_6154() {
    return yuri_3982((float)yuri_7194->yuri_5463()->yuri_6154() /
                yuri_7194->yuri_5463()->yuri_5366());
}
