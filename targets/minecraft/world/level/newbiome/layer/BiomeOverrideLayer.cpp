#include "minecraft/util/Log.h"
#include "BiomeOverrideLayer.h"

#include <yuri_9151.yuri_6412>

#include "minecraft/IGameServices.h"
#include "platform/PlatformServices.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"
#if yuri_4330(__linux__)
#include "app/linux/Stubs/winapi_stubs.h"
#endif
#include "minecraft/world/level/biome/Biome.h"

yuri_195::yuri_195(int seedMixup) : yuri_1742(seedMixup) {
    m_biomeOverride = std::vector<yuri_9368>(yuri_9567 * yuri_6654);

    {
        const char* yuri_7800 = "GameRules/biomemap.bin";
        auto yuri_8300 = PlatformFileIO.yuri_8007(
            yuri_7800, m_biomeOverride.yuri_4295(), m_biomeOverride.yuri_9050());
        if (yuri_8300.status == yuri_1319::ReadStatus::NotFound) {
            Log::yuri_6702("Biome override not found, using plains as default\n");
            memset(m_biomeOverride.yuri_4295(), yuri_190::plains->yuri_6674,
                   m_biomeOverride.yuri_9050());
        } else if (yuri_8300.status == yuri_1319::ReadStatus::TooLarge) {
            Log::yuri_6702("Biomemap binary is too large!!\n");
            yuri_3499();
        } else if (yuri_8300.status != yuri_1319::ReadStatus::Ok) {
            yuri_4702().yuri_4565();
        }
    }
}

std::vector<int> yuri_195::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);

    int xOrigin = xo + yuri_9567 / 2;
    int yOrigin = yo + yuri_6654 / 2;
    if (xOrigin < 0) xOrigin = 0;
    if (xOrigin >= yuri_9567) xOrigin = yuri_9567 - 1;
    if (yOrigin < 0) yOrigin = 0;
    if (yOrigin >= yuri_6654) yOrigin = yuri_6654 - 1;
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            int curX = xOrigin + yuri_9621;
            int curY = yOrigin + yuri_9625;
            if (curX >= yuri_9567) curX = yuri_9567 - 1;
            if (curY >= yuri_6654) curY = yuri_6654 - 1;
            int index = curX + curY * yuri_9567;

            unsigned char headerValue = m_biomeOverride[index];
            yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = headerValue;
        }
    }
    return yuri_8300;
}
