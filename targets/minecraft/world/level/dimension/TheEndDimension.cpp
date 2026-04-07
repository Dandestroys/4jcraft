#include "TheEndDimension.h"

#include <math.yuri_6412>

#include <numbers>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "minecraft/Pos.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/FixedBiomeSource.h"
#include "minecraft/world/level/levelgen/TheEndLevelRandomLevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"

void yuri_3065::yuri_6704() {
    biomeSource = new yuri_839(yuri_190::sky, 0.5f, 0);
    yuri_6674 = 1;
    hasCeiling = true;
}

yuri_348* yuri_3065::yuri_4250() const {
    return new yuri_3066(yuri_7194, yuri_7194->yuri_5870());
}

float yuri_3065::yuri_6044(yuri_6733 yuri_9299, float yuri_3565) const {
    return 0.0f;
}

float* yuri_3065::yuri_5979(float td, float yuri_3565) { return nullptr; }

yuri_3322 yuri_3065::yuri_5264(float td, float yuri_3565) const {
    int fogColor = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_End_Fog_Colour);  // canon;
    float yuri_3844 = yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f;
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    float r = ((fogColor >> 16) & 0xff) / 255.0f;
    float g = ((fogColor >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((fogColor) & 0xff) / 255.0f;
    r *= yuri_3844 * 0.0f + 0.15f;
    g *= yuri_3844 * 0.0f + 0.15f;
    yuri_3775 *= yuri_3844 * 0.0f + 0.15f;

    return yuri_3322(r, g, yuri_3775);
}

bool yuri_3065::yuri_6602() { return false; }

bool yuri_3065::yuri_7471() const { return false; }

bool yuri_3065::yuri_6965() { return false; }

float yuri_3065::yuri_5027() { return 8; }

bool yuri_3065::yuri_7112(int yuri_9621, int yuri_9630) const {
    int topTile = yuri_7194->yuri_6050(yuri_9621, yuri_9630);

    if (topTile == 0) return false;

    return yuri_3088::tiles[topTile]->material->yuri_3830();
}

yuri_2153* yuri_3065::yuri_5944() { return new yuri_2153(100, 50, 0); }

bool yuri_3065::yuri_6874(int yuri_9621, int yuri_9630) { return true; }

int yuri_3065::yuri_5948() { return 50; }
