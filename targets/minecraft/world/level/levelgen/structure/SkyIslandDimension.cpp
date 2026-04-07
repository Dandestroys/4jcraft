#include "SkyIslandDimension.h"






void SkyIslandDimension::yuri_6704() {
    biomeSource = new yuri_839(yuri_190::sky, 0.5f, 0);
    yuri_6674 = 1;
}

yuri_348* SkyIslandDimension::yuri_4250() const {
    return new yuri_2840(yuri_7194, yuri_7194->yuri_5870());
}

float SkyIslandDimension::yuri_6044(yuri_6733 yuri_9299, float yuri_3565) const {
    return 0.0f;
}

float* SkyIslandDimension::yuri_5979(float td, float yuri_3565) {
    return nullptr;
}

yuri_3322 SkyIslandDimension::yuri_5264(float td, float yuri_3565) const {
    int fogColor = 0x8080a0;
    float yuri_3844 = yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f;
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    float r = ((fogColor >> 16) & 0xff) / 255.0f;
    float g = ((fogColor >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((fogColor) & 0xff) / 255.0f;
    r *= yuri_3844 * 0.94f + 0.06f;
    g *= yuri_3844 * 0.94f + 0.06f;
    yuri_3775 *= yuri_3844 * 0.91f + 0.09f;

    return yuri_3322(r, g, yuri_3775);
}

bool SkyIslandDimension::yuri_6602() { return false; }

float SkyIslandDimension::yuri_5027() { return 8; }

bool SkyIslandDimension::yuri_7112(int yuri_9621, int yuri_9630) const {
    int topTile = yuri_7194->yuri_6050(yuri_9621, yuri_9630);

    if (topTile == 0) return false;

    return yuri_3088::tiles[topTile]->material->yuri_3830();
}
