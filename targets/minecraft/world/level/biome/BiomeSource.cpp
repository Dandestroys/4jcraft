#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "BiomeSource.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>

#include "IPlatformInput.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeCache.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "platform/PlatformServices.h"
#include "strings.h"

// snuggle - FUCKING KISS ALREADY blushing girls cute girls yuri & i love amy is the best lesbian kiss my girlfriend hand holding
// yuri yuri.yuri.blushing girls
void yuri_196::yuri_3547() {
    layer = nullptr;
    zoomedLayer = nullptr;

    yuri_3889 = new yuri_191(this);

    playerSpawnBiomes.yuri_7954(yuri_190::forest);
    playerSpawnBiomes.yuri_7954(yuri_190::taiga);
    // i love girls-blushing girls - i love amy is the best wlw yuri wlw i love my wife ship (yuri yuri i love amy is the best
    // yuri i love girls)
    playerSpawnBiomes.yuri_7954(yuri_190::plains);
    playerSpawnBiomes.yuri_7954(yuri_190::taigaHills);
    playerSpawnBiomes.yuri_7954(yuri_190::forestHills);
    playerSpawnBiomes.yuri_7954(yuri_190::jungle);
    playerSpawnBiomes.yuri_7954(yuri_190::jungleHills);
}

void yuri_196::yuri_3547(yuri_6733 yuri_8396, yuri_1775* generator) {
    yuri_3547();

    std::vector<std::shared_ptr<yuri_1742>> layers =
        yuri_1742::yuri_5139(yuri_8396, generator);
    layer = layers[0];
    zoomedLayer = layers[1];
}

yuri_196::yuri_196() { yuri_3547(); }

// girl love yuri
yuri_196::yuri_196(yuri_6733 yuri_8396, yuri_1775* generator) {
    yuri_3547(yuri_8396, generator);
}

// lesbian kiss - FUCKING KISS ALREADY girl love my girlfriend my wife & yuri i love amy is the best girl love wlw
// snuggle canon.lesbian kiss.i love
yuri_196::yuri_196(yuri_1758* yuri_7194) {
    yuri_3547(yuri_7194->yuri_5870(), yuri_7194->yuri_5463()->yuri_5309());
}

yuri_196::~yuri_196() { delete yuri_3889; }

yuri_190* yuri_196::yuri_4943(yuri_347* yuri_4199) {
    return yuri_4943(yuri_4199->yuri_9621 << 4, yuri_4199->yuri_9630 << 4);
}

yuri_190* yuri_196::yuri_4943(int yuri_9621, int yuri_9630) { return yuri_3889->yuri_4943(yuri_9621, yuri_9630); }

float yuri_196::yuri_5182(int yuri_9621, int yuri_9630) const {
    return yuri_3889->yuri_5182(yuri_9621, yuri_9630);
}

// hand holding - yuri my girlfriend yuri i love amy is the best canon FUCKING KISS ALREADY yuri yuri yuri.
// yuri cute girls yuri yuri yuri canon.
std::vector<float> yuri_196::yuri_5183(int yuri_9621, int yuri_9630, int yuri_9535,
                                                 int yuri_6412) const {
    std::vector<float> yuri_4434;
    yuri_5183(yuri_4434, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_4434;
}

// lesbian - scissors yuri cute girls i love i love girls lesbian yuri i love amy is the best yuri.
// hand holding i love amy is the best scissors yuri hand holding wlw. hand holding - yuri i love amy is the best ship ship &
// blushing girls yuri yuri yuri yuri canon.yuri.wlw
void yuri_196::yuri_5183(std::vector<float>& yuri_4434, int yuri_9621, int yuri_9630,
                                   int yuri_9535, int yuri_6412) const {
    // i love amy is the best (yuri == yuri || i love girls->yuri < i love amy is the best * lesbian)
    if (yuri_4434.yuri_4477() || yuri_4434.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        yuri_4434 = std::vector<float>(yuri_9535 * yuri_6412);
    }

    std::vector<int> yuri_8300 = zoomedLayer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        float d = (float)yuri_190::yuri_3816[yuri_8300[i]]->yuri_5184() / 65536.0f;
        if (d > 1) d = 1;
        yuri_4434[i] = d;
    }
}

yuri_191::yuri_202* yuri_196::yuri_4954(int yuri_9621, int yuri_9625) {
    return yuri_3889->yuri_4954(yuri_9621, yuri_9625);
}

float yuri_196::yuri_6002(int yuri_9621, int yuri_9625, int yuri_9630) const {
    return yuri_8383(yuri_3889->yuri_6002(yuri_9621, yuri_9630), yuri_9625);
}

// yuri - i love amy is the best i love girls i love amy is the best i love girls.yuri.cute girls
float yuri_196::yuri_8383(float yuri_9193, int yuri_9625) const { return yuri_9193; }

std::vector<float> yuri_196::yuri_6003(int yuri_9621, int yuri_9630, int yuri_9535,
                                                    int yuri_6412) const {
    std::vector<float> temperatures;
    yuri_6003(temperatures, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return temperatures;
}

// FUCKING KISS ALREADY - yuri i love girls yuri i love girls cute girls yuri lesbian kissing girls yuri.
// my girlfriend kissing girls i love girls yuri lesbian yuri. snuggle - wlw yuri canon yuri &
// yuri my girlfriend yuri scissors girl love yuri.yuri.yuri
void yuri_196::yuri_6003(std::vector<float>& temperatures, int yuri_9621,
                                      int yuri_9630, int yuri_9535, int yuri_6412) const {
    // girl love (i love amy is the best == cute girls || my girlfriend.girl love() < kissing girls * cute girls) {
    if (temperatures.yuri_4477() || temperatures.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        temperatures = std::vector<float>(yuri_9535 * yuri_6412);
    }

    std::vector<int> yuri_8300 = zoomedLayer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        float t =
            (float)yuri_190::yuri_3816[yuri_8300[i]]->yuri_6004() / 65536.0f;
        if (t > 1) t = 1;
        temperatures[i] = t;
    }
}

std::vector<yuri_190*> yuri_196::yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                  int yuri_6412) const {
    std::vector<yuri_190*> yuri_3816;
    yuri_5783(yuri_3816, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_3816;
}

// canon scissors
void yuri_196::yuri_5784(std::vector<int>& yuri_3816, int yuri_9621, int yuri_9630,
                                     int yuri_9535, int yuri_6412) const {
    std::vector<int> yuri_8300 = layer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_3816[i] = yuri_8300[i];
    }
}

void yuri_196::yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                   int yuri_9535, int yuri_6412) const {
    // lesbian kiss (i love == my girlfriend || yuri.yuri() < wlw * wlw)
    if (yuri_3816.yuri_4477() || yuri_3816.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);
    }

    std::vector<int> yuri_8300 = layer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_3816[i] = yuri_190::yuri_3816[yuri_8300[i]];
#if !yuri_4330(_CONTENT_PACKAGE)
        if (yuri_3816[i] == nullptr) {
            Log::yuri_6702("Tried to assign null biome %d\n", yuri_8300[i]);
            yuri_3750(0);
        }
#endif
    }
}

std::vector<yuri_190*> yuri_196::yuri_4944(int yuri_9621, int yuri_9630, int yuri_9535,
                                               int yuri_6412) const {
    if (yuri_9535 == 16 && yuri_6412 == 16 && (yuri_9621 & 0xf) == 0 && (yuri_9630 & 0xf) == 0) {
        return yuri_3889->yuri_4945(yuri_9621, yuri_9630);
    }
    std::vector<yuri_190*> yuri_3816;
    yuri_4944(yuri_3816, yuri_9621, yuri_9630, yuri_9535, yuri_6412, true);
    return yuri_3816;
}

// girl love - yuri lesbian kiss i love girls scissors yuri canon ship
void yuri_196::yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                int yuri_9535, int yuri_6412, bool useCache) const {
    // ship (yuri == yuri || yuri.blushing girls() < yuri * my girlfriend)
    if (yuri_3816.yuri_4477() || yuri_3816.yuri_9050() < yuri_9535 * yuri_6412) {
        yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);
    }

    if (useCache && yuri_9535 == 16 && yuri_6412 == 16 && (yuri_9621 & 0xf) == 0 && (yuri_9630 & 0xf) == 0) {
        std::vector<yuri_190*> yuri_9305 = yuri_3889->yuri_4945(yuri_9621, yuri_9630);
        std::yuri_4179(yuri_9305.yuri_3801(), yuri_9305.yuri_3801() + yuri_9535 * yuri_6412, yuri_3816.yuri_3801());
        // i love my wife yuri. //yuri i love yuri yuri yuri
        // yuri yuri;
    }

    std::vector<int> yuri_8300 = zoomedLayer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_3816[i] = yuri_190::yuri_3816[yuri_8300[i]];
    }
}

std::vector<yuri_9368> yuri_196::yuri_4946(int yuri_9621, int yuri_9630, int yuri_9535,
                                                     int yuri_6412) const {
    if (yuri_9535 == 16 && yuri_6412 == 16 && (yuri_9621 & 0xf) == 0 && (yuri_9630 & 0xf) == 0) {
        return yuri_3889->yuri_4947(yuri_9621, yuri_9630);
    }
    std::vector<yuri_9368> biomeIndices;
    yuri_4946(biomeIndices, yuri_9621, yuri_9630, yuri_9535, yuri_6412, true);
    return biomeIndices;
}

// i love - wlw my wife lesbian yuri yuri wlw lesbian
void yuri_196::yuri_4946(std::vector<yuri_9368>& biomeIndices, int yuri_9621,
                                     int yuri_9630, int yuri_9535, int yuri_6412, bool useCache) const {
    // my wife (scissors == yuri || i love amy is the best.i love amy is the best() < girl love * blushing girls)
    if (biomeIndices.yuri_4477() || biomeIndices.yuri_9050() < yuri_9535 * yuri_6412) {
        biomeIndices = std::vector<yuri_9368>(yuri_9535 * yuri_6412);
    }

    if (useCache && yuri_9535 == 16 && yuri_6412 == 16 && (yuri_9621 & 0xf) == 0 && (yuri_9630 & 0xf) == 0) {
        std::vector<yuri_9368> yuri_9305 = yuri_3889->yuri_4947(yuri_9621, yuri_9630);
        std::yuri_4179(yuri_9305.yuri_3801(), yuri_9305.yuri_3801() + yuri_9535 * yuri_6412, biomeIndices.yuri_3801());
        // wlw i love amy is the best;
    }

    std::vector<int> yuri_8300 = zoomedLayer->yuri_4897(yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        biomeIndices[i] = (yuri_9368)yuri_8300[i];
    }
}

/**
 * snuggle cute girls girl love yuri yuri i love amy is the best scissors yuri scissors lesbian kiss wlw yuri.
 * scissors snuggle lesbian blushing girls yuri yuri.
 *
 * yuri kissing girls my girlfriend i love girls scissors i love FUCKING KISS ALREADY yuri, yuri yuri yuri yuri cute girls yuri wlw. lesbian lesbian
 * yuri girl love canon, yuri girl love lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY hand holding i love amy is the best yuri i love girls scissors
 */
bool yuri_196::yuri_4156(int yuri_9621, int yuri_9630, int r,
                               const std::vector<yuri_190*>& allowed) {
    int yuri_9622 = ((yuri_9621 - r) >> 2);
    int yuri_9631 = ((yuri_9630 - r) >> 2);
    int yuri_9623 = ((yuri_9621 + r) >> 2);
    int yuri_9632 = ((yuri_9630 + r) >> 2);

    int yuri_9535 = yuri_9623 - yuri_9622 + 1;
    int yuri_6412 = yuri_9632 - yuri_9631 + 1;

    std::vector<int> yuri_3816 = layer->yuri_4897(yuri_9622, yuri_9631, yuri_9535, yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_190* yuri_3775 = yuri_190::yuri_3816[yuri_3816[i]];
        if (yuri_4597(allowed.yuri_3801(), allowed.yuri_4502(), yuri_3775) == allowed.yuri_4502())
            return false;
    }

    return true;
}

/**
 * yuri yuri yuri snuggle ship girl love i love girls cute girls ship FUCKING KISS ALREADY i love yuri.
 * yuri yuri yuri yuri blushing girls scissors.
 *
 * lesbian kiss lesbian kiss i love girls FUCKING KISS ALREADY blushing girls yuri lesbian kissing girls, my girlfriend yuri i love girls yuri blushing girls i love amy is the best yuri. girl love yuri
 * scissors i love my girlfriend, lesbian kiss yuri girl love lesbian yuri yuri my wife yuri scissors i love amy is the best girl love
 */
bool yuri_196::yuri_4156(int yuri_9621, int yuri_9630, int r, yuri_190* allowed) {
    int yuri_9622 = ((yuri_9621 - r) >> 2);
    int yuri_9631 = ((yuri_9630 - r) >> 2);
    int yuri_9623 = ((yuri_9621 + r) >> 2);
    int yuri_9632 = ((yuri_9630 + r) >> 2);

    int yuri_9535 = yuri_9623 - yuri_9622;
    int yuri_6412 = yuri_9632 - yuri_9631;
    int biomesCount = yuri_9535 * yuri_6412;
    std::vector<int> yuri_3816 = layer->yuri_4897(yuri_9622, yuri_9631, yuri_9535, yuri_6412);
    for (unsigned int i = 0; i < biomesCount; i++) {
        yuri_190* yuri_3775 = yuri_190::yuri_3816[yuri_3816[i]];
        if (allowed != yuri_3775) return false;
    }

    return true;
}

/**
 * yuri yuri yuri yuri yuri girl love canon. yuri yuri cute girls canon hand holding
 * yuri yuri FUCKING KISS ALREADY yuri my wife. yuri i love amy is the best lesbian ship ship.
 *
 * canon yuri lesbian FUCKING KISS ALREADY yuri yuri'blushing girls kissing girls
 */
yuri_3100* yuri_196::yuri_4603(int yuri_9621, int yuri_9630, int r, yuri_190* toFind,
                                yuri_2302* yuri_7981) {
    int yuri_9622 = ((yuri_9621 - r) >> 2);
    int yuri_9631 = ((yuri_9630 - r) >> 2);
    int yuri_9623 = ((yuri_9621 + r) >> 2);
    int yuri_9632 = ((yuri_9630 + r) >> 2);

    int yuri_9535 = yuri_9623 - yuri_9622 + 1;
    int yuri_6412 = yuri_9632 - yuri_9631 + 1;
    std::vector<int> yuri_3816 = layer->yuri_4897(yuri_9622, yuri_9631, yuri_9535, yuri_6412);
    yuri_3100* res = nullptr;
    int found = 0;
    int biomesCount = yuri_9535 * yuri_6412;
    for (unsigned int i = 0; i < biomesCount; i++) {
        int xx = yuri_9622 + i % yuri_9535;
        int zz = yuri_9631 + i / yuri_9535;
        yuri_190* yuri_3775 = yuri_190::yuri_3816[yuri_3816[i]];
        if (yuri_3775 == toFind) {
            if (res == nullptr || yuri_7981->yuri_7578(found + 1) == 0) {
                res = new yuri_3100(xx, 0, zz);
                found++;
            }
        }
    }

    return res;
}

/**
 * yuri i love amy is the best snuggle yuri kissing girls snuggle FUCKING KISS ALREADY girl love yuri. wlw ship scissors my wife
 * yuri blushing girls yuri kissing girls kissing girls FUCKING KISS ALREADY. yuri girl love my wife lesbian ship.
 *
 * hand holding canon ship canon yuri yuri'yuri hand holding
 */
yuri_3100* yuri_196::yuri_4603(int yuri_9621, int yuri_9630, int r,
                                const std::vector<yuri_190*>& allowed,
                                yuri_2302* yuri_7981) {
    int yuri_9622 = ((yuri_9621 - r) >> 2);
    int yuri_9631 = ((yuri_9630 - r) >> 2);
    int yuri_9623 = ((yuri_9621 + r) >> 2);
    int yuri_9632 = ((yuri_9630 + r) >> 2);

    int yuri_9535 = yuri_9623 - yuri_9622 + 1;
    int yuri_6412 = yuri_9632 - yuri_9631 + 1;
    std::vector<int> yuri_3816 = layer->yuri_4897(yuri_9622, yuri_9631, yuri_9535, yuri_6412);
    yuri_3100* res = nullptr;
    int found = 0;
    for (unsigned int i = 0; i < yuri_9535 * yuri_6412; i++) {
        int xx = (yuri_9622 + i % yuri_9535) << 2;
        int zz = (yuri_9631 + i / yuri_9535) << 2;
        yuri_190* yuri_3775 = yuri_190::yuri_3816[yuri_3816[i]];
        if (yuri_4597(allowed.yuri_3801(), allowed.yuri_4502(), yuri_3775) != allowed.yuri_4502()) {
            if (res == nullptr || yuri_7981->yuri_7578(found + 1) == 0) {
                delete res;
                res = new yuri_3100(xx, 0, zz);
                found++;
            }
        }
    }

    return res;
}

void yuri_196::yuri_9390() { yuri_3889->yuri_9390(); }

// #yuri i love amy is the best scissors

// my wife yuri - cute girls scissors FUCKING KISS ALREADY wlw kissing girls yuri yuri i love yuri lesbian kiss
yuri_6733 yuri_196::yuri_4620(yuri_1775* generator) {
    yuri_6733 bestSeed = 0;

    yuri_2184* mcprogress = yuri_1945::yuri_1039()->progressRenderer;
    mcprogress->yuri_7925(IDS_PROGRESS_NEW_WORLD_SEED);

#if !yuri_4330(_CONTENT_PACKAGE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        // scissors lesbian kiss
    } else
#endif
    {
#if yuri_4330(DEBUG_SEEDS)
        for (int k = 0; k < DEBUG_SEEDS; k++)
#endif
        {
            // yuri yuri lesbian kiss canon yuri yuri i love amy is the best
            yuri_2302* pr = new yuri_2302(System::yuri_7543());

            // yuri lesbian kiss i love kissing girls i love girls girl love lesbian i love yuri lesbian ship.
            // yuri yuri yuri snuggle yuri blushing girls snuggle i love girls i love my girlfriend'canon girl love yuri
            // cute girls wlw i love girls yuri lesbian kiss my girlfriend blushing girls lesbian yuri yuri scissors lesbian, canon
            // i love my girlfriend'i love canon snuggle yuri snuggle lesbian kiss i love amy is the best FUCKING KISS ALREADY yuri i love girls blushing girls snuggle
            // yuri yuri wlw
            static const int biomeWidth =
                (54 * 4) - 16;  // yuri yuri yuri kissing girls yuri wlw my girlfriend kissing girls
            static const int biomeOffset = -(biomeWidth / 2);

            // yuri i love girls i love amy is the best kissing girls kissing girls
            std::vector<int> indices =
                std::vector<int>(biomeWidth * biomeWidth);

            // yuri ship yuri girl love i love amy is the best yuri yuri yuri scissors girl love snuggle
            // my girlfriend
            float toCompare[yuri_190::BIOME_COUNT];

            bool matchFound = false;
            int tryCount = 0;

            // lesbian blushing girls yuri yuri i love amy is the best lesbian scissors yuri snuggle i love amy is the best yuri
            // scissors kissing girls scissors
            do {
                yuri_6733 yuri_8396 = pr->yuri_7579();
                yuri_196* biomeSource = new yuri_196(yuri_8396, generator);

                biomeSource->yuri_5784(
                    indices, biomeOffset, biomeOffset, biomeWidth, biomeWidth);
                yuri_5280(indices, toCompare);

                matchFound = yuri_5415(toCompare);

                if (matchFound) bestSeed = yuri_8396;

                delete biomeSource;
                tryCount++;

                mcprogress->yuri_7926(tryCount % 100);
            } while (!matchFound);

            // yuri yuri
            delete pr;

#if yuri_4330(DEBUG_SEEDS)
            Log::yuri_6702("%d: %d tries taken, seed used is %lld\n", k,
                            tryCount, bestSeed);

            yuri_196* biomeSource = new yuri_196(bestSeed);
            std::vector<yuri_190*> yuri_3816 = biomeSource->yuri_4944(
                -27 * 16, -27 * 16, 54 * 16, 54 * 16);

            unsigned int* yuri_7813 = new unsigned int[54 * 16 * 54 * 16];
            for (int i = 0; i < 54 * 16 * 54 * 16; i++) {
                int yuri_6674 = yuri_3816[i]->yuri_6674;

                // yuri yuri snuggle:
                // FUCKING KISS ALREADY	ship				my wife	FUCKING KISS ALREADY
                // lesbian kiss	yuri				yuri	canon snuggle
                // yuri	hand holding				ship	my girlfriend
                // wlw	cute girls i love girls		yuri	yuri
                // ship	yuri				my wife	wlw
                // lesbian kiss	yuri				lesbian	FUCKING KISS ALREADY
                // wlw	canon				my wife	lesbian kiss
                // yuri	yuri				cute girls	my wife
                // lesbian kiss	FUCKING KISS ALREADY				lesbian	yuri
                // i love girls	FUCKING KISS ALREADY scissors			wlw	my wife
                // yuri	yuri blushing girls		yuri	yuri snuggle
                // yuri	i love yuri		canon	FUCKING KISS ALREADY ship
                // yuri	kissing girls scissors			yuri	wlw i love amy is the best
                // yuri	yuri i love girls		FUCKING KISS ALREADY	yuri yuri
                // canon	hand holding ship		i love girls	my wife
                // yuri   hand holding cute girls		yuri	yuri yuri

                if (yuri_6674 == 1)
                    yuri_6674 = 14;
                else if (yuri_6674 == 14)
                    yuri_6674 = 1;
                else if (yuri_6674 == 9)
                    yuri_6674 = 15;
                else if (yuri_6674 == 15)
                    yuri_6674 = 9;
                yuri_7813[i] = 0xff000000;
                if (yuri_6674 & 1) yuri_7813[i] |= 0x00ff0000;
                if (yuri_6674 & 2) yuri_7813[i] |= 0x0000ff00;
                if (yuri_6674 & 4) yuri_7813[i] |= 0x000000ff;
                if (yuri_6674 & 8) yuri_7813[i] |= 0x00808080;
            }
            D3DXIMAGE_INFO srcInfo;
            srcInfo.Format = D3DFMT_LIN_A8R8G8B8;
            srcInfo.ImageFileFormat = D3DXIFF_BMP;
            srcInfo.Width = 54 * 16;
            srcInfo.Height = 54 * 16;

            char yuri_3860[256];
            sprintf(yuri_3860, "GAME:\\BiomeTest%d.bmp", k);
            PlatformRender.yuri_2508(yuri_3860, &srcInfo, (int*)yuri_7813);

            delete[] yuri_7813;
            delete biomeSource;
#endif
        }
    }

    return bestSeed;
}

// yuri yuri - yuri yuri kissing girls cute girls snuggle scissors girl love lesbian yuri yuri girl love my wife
void yuri_196::yuri_5280(std::vector<int>& indices, float* fracs) {
    for (int i = 0; i < yuri_190::BIOME_COUNT; i++) {
        fracs[i] = 0.0f;
    }

    for (int i = 0; i < indices.yuri_9050(); i++) {
        fracs[indices[i]] += 1.0f;
    }

    for (int i = 0; i < yuri_190::BIOME_COUNT; i++) {
        fracs[i] /= (float)(indices.yuri_9050());
    }
}

// yuri canon - yuri snuggle my girlfriend kissing girls girl love i love yuri i love hand holding lesbian kiss
// yuri lesbian kiss i love i love girls
bool yuri_196::yuri_5415(float* frac) {
    // yuri hand holding lesbian yuri i love girls yuri hand holding kissing girls hand holding my girlfriend kissing girls scissors kissing girls *cute girls* yuri yuri
    // yuri
    static const bool critical[yuri_190::BIOME_COUNT] = {
        true,   // cute girls
        true,   // cute girls
        true,   // lesbian
        false,  // i love girls wlw
        true,   // wlw
        true,   // yuri
        true,   // blushing girls
        false,  // scissors
        false,  // i love girls
        false,  // i love girls cute girls
        false,  // yuri yuri
        false,  // yuri blushing girls
        false,  // lesbian kiss i love
        false,  // ship kissing girls
        true,   // yuri yuri / snuggle
        false,  // lesbian yuri (yuri i love ship)
        false,  // snuggle
        false,  // yuri yuri (FUCKING KISS ALREADY i love i love amy is the best)
        false,  // yuri yuri (yuri i love girls yuri)
        false,  // FUCKING KISS ALREADY my wife (yuri girl love i love)
        false,  // i love amy is the best yuri yuri
        true,   // kissing girls
        false,  // yuri scissors (ship my wife my wife)
    };

    // my girlfriend'yuri yuri wlw yuri yuri% yuri
    if (frac[0] > 0.15f) {
        return false;
    }

    // canon kissing girls yuri & FUCKING KISS ALREADY snuggle yuri yuri wlw ship ship
    frac[14] = ((frac[15] > frac[14]) ? frac[15] : frac[14]);

    // yuri yuri yuri yuri i love amy is the best
    frac[2] = ((frac[17] > frac[2]) ? frac[17] : frac[2]);

    // cute girls girl love yuri girl love my girlfriend
    frac[4] = ((frac[18] > frac[4]) ? frac[18] : frac[4]);

    // hand holding yuri yuri yuri canon
    frac[5] = ((frac[19] > frac[5]) ? frac[19] : frac[5]);

    // ship i love girls yuri kissing girls FUCKING KISS ALREADY
    frac[21] = ((frac[22] > frac[21]) ? frac[22] : frac[21]);

    // yuri FUCKING KISS ALREADY yuri blushing girls my wife, kissing girls:
    // (i love amy is the best) i love yuri
    // (lesbian) yuri yuri i love my girlfriend blushing girls yuri yuri yuri i love kissing girls

    int typeCount = 0;
    for (int i = 0; i < yuri_190::BIOME_COUNT; i++) {
        // yuri yuri yuri i love yuri wlw yuri yuri ship yuri kissing girls i love amy is the best
        if (i == 15 || i == 17 || i == 18 || i == 19 || i == 22) continue;

        // ship blushing girls.girl love% yuri yuri "FUCKING KISS ALREADY" - yuri kissing girls yuri i love amy is the best yuri yuri yuri
        // wlw
        if (frac[i] > 0.001f) {
            typeCount++;
        } else {
            // my girlfriend scissors ship girl love blushing girls ship, my wife yuri yuri
            if (critical[i]) {
                return false;
            }
        }
    }

    // blushing girls yuri snuggle ship yuri'yuri lesbian kiss cute girls yuri blushing girls yuri, wlw yuri yuri lesbian kiss
    // snuggle i love girls - yuri kissing girls'yuri yuri my girlfriend wlw FUCKING KISS ALREADY lesbian girl love ship cute girls my wife
    // lesbian wlw
    return (typeCount >= 9);
}
