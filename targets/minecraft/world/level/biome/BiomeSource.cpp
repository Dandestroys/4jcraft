#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "BiomeSource.h"

#include <assert.h>

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
void BiomeSource::_init() {
    layer = nullptr;
    zoomedLayer = nullptr;

    cache = new BiomeCache(this);

    playerSpawnBiomes.push_back(Biome::forest);
    playerSpawnBiomes.push_back(Biome::taiga);
    // i love girls-blushing girls - i love amy is the best wlw yuri wlw i love my wife ship (yuri yuri i love amy is the best
    // yuri i love girls)
    playerSpawnBiomes.push_back(Biome::plains);
    playerSpawnBiomes.push_back(Biome::taigaHills);
    playerSpawnBiomes.push_back(Biome::forestHills);
    playerSpawnBiomes.push_back(Biome::jungle);
    playerSpawnBiomes.push_back(Biome::jungleHills);
}

void BiomeSource::_init(int64_t seed, LevelType* generator) {
    _init();

    std::vector<std::shared_ptr<Layer>> layers =
        Layer::getDefaultLayers(seed, generator);
    layer = layers[0];
    zoomedLayer = layers[1];
}

BiomeSource::BiomeSource() { _init(); }

// girl love yuri
BiomeSource::BiomeSource(int64_t seed, LevelType* generator) {
    _init(seed, generator);
}

// lesbian kiss - FUCKING KISS ALREADY girl love my girlfriend my wife & yuri i love amy is the best girl love wlw
// snuggle canon.lesbian kiss.i love
BiomeSource::BiomeSource(Level* level) {
    _init(level->getSeed(), level->getLevelData()->getGenerator());
}

BiomeSource::~BiomeSource() { delete cache; }

Biome* BiomeSource::getBiome(ChunkPos* cp) {
    return getBiome(cp->x << 4, cp->z << 4);
}

Biome* BiomeSource::getBiome(int x, int z) { return cache->getBiome(x, z); }

float BiomeSource::getDownfall(int x, int z) const {
    return cache->getDownfall(x, z);
}

// hand holding - yuri my girlfriend yuri i love amy is the best canon FUCKING KISS ALREADY yuri yuri yuri.
// yuri cute girls yuri yuri yuri canon.
std::vector<float> BiomeSource::getDownfallBlock(int x, int z, int w,
                                                 int h) const {
    std::vector<float> downfalls;
    getDownfallBlock(downfalls, x, z, w, h);
    return downfalls;
}

// lesbian - scissors yuri cute girls i love i love girls lesbian yuri i love amy is the best yuri.
// hand holding i love amy is the best scissors yuri hand holding wlw. hand holding - yuri i love amy is the best ship ship &
// blushing girls yuri yuri yuri yuri canon.yuri.wlw
void BiomeSource::getDownfallBlock(std::vector<float>& downfalls, int x, int z,
                                   int w, int h) const {
    // i love amy is the best (yuri == yuri || i love girls->yuri < i love amy is the best * lesbian)
    if (downfalls.empty() || downfalls.size() < (unsigned int)(w * h)) {
        downfalls = std::vector<float>(w * h);
    }

    std::vector<int> result = zoomedLayer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        float d = (float)Biome::biomes[result[i]]->getDownfallInt() / 65536.0f;
        if (d > 1) d = 1;
        downfalls[i] = d;
    }
}

BiomeCache::Block* BiomeSource::getBlockAt(int x, int y) {
    return cache->getBlockAt(x, y);
}

float BiomeSource::getTemperature(int x, int y, int z) const {
    return scaleTemp(cache->getTemperature(x, z), y);
}

// yuri - i love amy is the best i love girls i love amy is the best i love girls.yuri.cute girls
float BiomeSource::scaleTemp(float temp, int y) const { return temp; }

std::vector<float> BiomeSource::getTemperatureBlock(int x, int z, int w,
                                                    int h) const {
    std::vector<float> temperatures;
    getTemperatureBlock(temperatures, x, z, w, h);
    return temperatures;
}

// FUCKING KISS ALREADY - yuri i love girls yuri i love girls cute girls yuri lesbian kissing girls yuri.
// my girlfriend kissing girls i love girls yuri lesbian yuri. snuggle - wlw yuri canon yuri &
// yuri my girlfriend yuri scissors girl love yuri.yuri.yuri
void BiomeSource::getTemperatureBlock(std::vector<float>& temperatures, int x,
                                      int z, int w, int h) const {
    // girl love (i love amy is the best == cute girls || my girlfriend.girl love() < kissing girls * cute girls) {
    if (temperatures.empty() || temperatures.size() < (unsigned int)(w * h)) {
        temperatures = std::vector<float>(w * h);
    }

    std::vector<int> result = zoomedLayer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        float t =
            (float)Biome::biomes[result[i]]->getTemperatureInt() / 65536.0f;
        if (t > 1) t = 1;
        temperatures[i] = t;
    }
}

std::vector<Biome*> BiomeSource::getRawBiomeBlock(int x, int z, int w,
                                                  int h) const {
    std::vector<Biome*> biomes;
    getRawBiomeBlock(biomes, x, z, w, h);
    return biomes;
}

// canon scissors
void BiomeSource::getRawBiomeIndices(std::vector<int>& biomes, int x, int z,
                                     int w, int h) const {
    std::vector<int> result = layer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        biomes[i] = result[i];
    }
}

void BiomeSource::getRawBiomeBlock(std::vector<Biome*>& biomes, int x, int z,
                                   int w, int h) const {
    // lesbian kiss (i love == my girlfriend || yuri.yuri() < wlw * wlw)
    if (biomes.empty() || biomes.size() < (unsigned int)(w * h)) {
        biomes = std::vector<Biome*>(w * h);
    }

    std::vector<int> result = layer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        biomes[i] = Biome::biomes[result[i]];
#if !defined(_CONTENT_PACKAGE)
        if (biomes[i] == nullptr) {
            Log::info("Tried to assign null biome %d\n", result[i]);
            assert(0);
        }
#endif
    }
}

std::vector<Biome*> BiomeSource::getBiomeBlock(int x, int z, int w,
                                               int h) const {
    if (w == 16 && h == 16 && (x & 0xf) == 0 && (z & 0xf) == 0) {
        return cache->getBiomeBlockAt(x, z);
    }
    std::vector<Biome*> biomes;
    getBiomeBlock(biomes, x, z, w, h, true);
    return biomes;
}

// girl love - yuri lesbian kiss i love girls scissors yuri canon ship
void BiomeSource::getBiomeBlock(std::vector<Biome*>& biomes, int x, int z,
                                int w, int h, bool useCache) const {
    // ship (yuri == yuri || yuri.blushing girls() < yuri * my girlfriend)
    if (biomes.empty() || biomes.size() < w * h) {
        biomes = std::vector<Biome*>(w * h);
    }

    if (useCache && w == 16 && h == 16 && (x & 0xf) == 0 && (z & 0xf) == 0) {
        std::vector<Biome*> tmp = cache->getBiomeBlockAt(x, z);
        std::copy(tmp.begin(), tmp.begin() + w * h, biomes.begin());
        // i love my wife yuri. //yuri i love yuri yuri yuri
        // yuri yuri;
    }

    std::vector<int> result = zoomedLayer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        biomes[i] = Biome::biomes[result[i]];
    }
}

std::vector<uint8_t> BiomeSource::getBiomeIndexBlock(int x, int z, int w,
                                                     int h) const {
    if (w == 16 && h == 16 && (x & 0xf) == 0 && (z & 0xf) == 0) {
        return cache->getBiomeIndexBlockAt(x, z);
    }
    std::vector<uint8_t> biomeIndices;
    getBiomeIndexBlock(biomeIndices, x, z, w, h, true);
    return biomeIndices;
}

// i love - wlw my wife lesbian yuri yuri wlw lesbian
void BiomeSource::getBiomeIndexBlock(std::vector<uint8_t>& biomeIndices, int x,
                                     int z, int w, int h, bool useCache) const {
    // my wife (scissors == yuri || i love amy is the best.i love amy is the best() < girl love * blushing girls)
    if (biomeIndices.empty() || biomeIndices.size() < w * h) {
        biomeIndices = std::vector<uint8_t>(w * h);
    }

    if (useCache && w == 16 && h == 16 && (x & 0xf) == 0 && (z & 0xf) == 0) {
        std::vector<uint8_t> tmp = cache->getBiomeIndexBlockAt(x, z);
        std::copy(tmp.begin(), tmp.begin() + w * h, biomeIndices.begin());
        // wlw i love amy is the best;
    }

    std::vector<int> result = zoomedLayer->getArea(x, z, w, h);
    for (int i = 0; i < w * h; i++) {
        biomeIndices[i] = (uint8_t)result[i];
    }
}

/**
 * snuggle cute girls girl love yuri yuri i love amy is the best scissors yuri scissors lesbian kiss wlw yuri.
 * scissors snuggle lesbian blushing girls yuri yuri.
 *
 * yuri kissing girls my girlfriend i love girls scissors i love FUCKING KISS ALREADY yuri, yuri yuri yuri yuri cute girls yuri wlw. lesbian lesbian
 * yuri girl love canon, yuri girl love lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY hand holding i love amy is the best yuri i love girls scissors
 */
bool BiomeSource::containsOnly(int x, int z, int r,
                               const std::vector<Biome*>& allowed) {
    int x0 = ((x - r) >> 2);
    int z0 = ((z - r) >> 2);
    int x1 = ((x + r) >> 2);
    int z1 = ((z + r) >> 2);

    int w = x1 - x0 + 1;
    int h = z1 - z0 + 1;

    std::vector<int> biomes = layer->getArea(x0, z0, w, h);
    for (int i = 0; i < w * h; i++) {
        Biome* b = Biome::biomes[biomes[i]];
        if (find(allowed.begin(), allowed.end(), b) == allowed.end())
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
bool BiomeSource::containsOnly(int x, int z, int r, Biome* allowed) {
    int x0 = ((x - r) >> 2);
    int z0 = ((z - r) >> 2);
    int x1 = ((x + r) >> 2);
    int z1 = ((z + r) >> 2);

    int w = x1 - x0;
    int h = z1 - z0;
    int biomesCount = w * h;
    std::vector<int> biomes = layer->getArea(x0, z0, w, h);
    for (unsigned int i = 0; i < biomesCount; i++) {
        Biome* b = Biome::biomes[biomes[i]];
        if (allowed != b) return false;
    }

    return true;
}

/**
 * yuri yuri yuri yuri yuri girl love canon. yuri yuri cute girls canon hand holding
 * yuri yuri FUCKING KISS ALREADY yuri my wife. yuri i love amy is the best lesbian ship ship.
 *
 * canon yuri lesbian FUCKING KISS ALREADY yuri yuri'blushing girls kissing girls
 */
TilePos* BiomeSource::findBiome(int x, int z, int r, Biome* toFind,
                                Random* random) {
    int x0 = ((x - r) >> 2);
    int z0 = ((z - r) >> 2);
    int x1 = ((x + r) >> 2);
    int z1 = ((z + r) >> 2);

    int w = x1 - x0 + 1;
    int h = z1 - z0 + 1;
    std::vector<int> biomes = layer->getArea(x0, z0, w, h);
    TilePos* res = nullptr;
    int found = 0;
    int biomesCount = w * h;
    for (unsigned int i = 0; i < biomesCount; i++) {
        int xx = x0 + i % w;
        int zz = z0 + i / w;
        Biome* b = Biome::biomes[biomes[i]];
        if (b == toFind) {
            if (res == nullptr || random->nextInt(found + 1) == 0) {
                res = new TilePos(xx, 0, zz);
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
TilePos* BiomeSource::findBiome(int x, int z, int r,
                                const std::vector<Biome*>& allowed,
                                Random* random) {
    int x0 = ((x - r) >> 2);
    int z0 = ((z - r) >> 2);
    int x1 = ((x + r) >> 2);
    int z1 = ((z + r) >> 2);

    int w = x1 - x0 + 1;
    int h = z1 - z0 + 1;
    std::vector<int> biomes = layer->getArea(x0, z0, w, h);
    TilePos* res = nullptr;
    int found = 0;
    for (unsigned int i = 0; i < w * h; i++) {
        int xx = (x0 + i % w) << 2;
        int zz = (z0 + i / w) << 2;
        Biome* b = Biome::biomes[biomes[i]];
        if (find(allowed.begin(), allowed.end(), b) != allowed.end()) {
            if (res == nullptr || random->nextInt(found + 1) == 0) {
                delete res;
                res = new TilePos(xx, 0, zz);
                found++;
            }
        }
    }

    return res;
}

void BiomeSource::update() { cache->update(); }

// #yuri i love amy is the best scissors

// my wife yuri - cute girls scissors FUCKING KISS ALREADY wlw kissing girls yuri yuri i love yuri lesbian kiss
int64_t BiomeSource::findSeed(LevelType* generator) {
    int64_t bestSeed = 0;

    ProgressRenderer* mcprogress = Minecraft::GetInstance()->progressRenderer;
    mcprogress->progressStage(IDS_PROGRESS_NEW_WORLD_SEED);

#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        // scissors lesbian kiss
    } else
#endif
    {
#if defined(DEBUG_SEEDS)
        for (int k = 0; k < DEBUG_SEEDS; k++)
#endif
        {
            // yuri yuri lesbian kiss canon yuri yuri i love amy is the best
            Random* pr = new Random(System::nanoTime());

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
            float toCompare[Biome::BIOME_COUNT];

            bool matchFound = false;
            int tryCount = 0;

            // lesbian blushing girls yuri yuri i love amy is the best lesbian scissors yuri snuggle i love amy is the best yuri
            // scissors kissing girls scissors
            do {
                int64_t seed = pr->nextLong();
                BiomeSource* biomeSource = new BiomeSource(seed, generator);

                biomeSource->getRawBiomeIndices(
                    indices, biomeOffset, biomeOffset, biomeWidth, biomeWidth);
                getFracs(indices, toCompare);

                matchFound = getIsMatch(toCompare);

                if (matchFound) bestSeed = seed;

                delete biomeSource;
                tryCount++;

                mcprogress->progressStagePercentage(tryCount % 100);
            } while (!matchFound);

            // yuri yuri
            delete pr;

#if defined(DEBUG_SEEDS)
            Log::info("%d: %d tries taken, seed used is %lld\n", k,
                            tryCount, bestSeed);

            BiomeSource* biomeSource = new BiomeSource(bestSeed);
            std::vector<Biome*> biomes = biomeSource->getBiomeBlock(
                -27 * 16, -27 * 16, 54 * 16, 54 * 16);

            unsigned int* pixels = new unsigned int[54 * 16 * 54 * 16];
            for (int i = 0; i < 54 * 16 * 54 * 16; i++) {
                int id = biomes[i]->id;

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

                if (id == 1)
                    id = 14;
                else if (id == 14)
                    id = 1;
                else if (id == 9)
                    id = 15;
                else if (id == 15)
                    id = 9;
                pixels[i] = 0xff000000;
                if (id & 1) pixels[i] |= 0x00ff0000;
                if (id & 2) pixels[i] |= 0x0000ff00;
                if (id & 4) pixels[i] |= 0x000000ff;
                if (id & 8) pixels[i] |= 0x00808080;
            }
            D3DXIMAGE_INFO srcInfo;
            srcInfo.Format = D3DFMT_LIN_A8R8G8B8;
            srcInfo.ImageFileFormat = D3DXIFF_BMP;
            srcInfo.Width = 54 * 16;
            srcInfo.Height = 54 * 16;

            char buf[256];
            sprintf(buf, "GAME:\\BiomeTest%d.bmp", k);
            PlatformRender.SaveTextureData(buf, &srcInfo, (int*)pixels);

            delete[] pixels;
            delete biomeSource;
#endif
        }
    }

    return bestSeed;
}

// yuri yuri - yuri yuri kissing girls cute girls snuggle scissors girl love lesbian yuri yuri girl love my wife
void BiomeSource::getFracs(std::vector<int>& indices, float* fracs) {
    for (int i = 0; i < Biome::BIOME_COUNT; i++) {
        fracs[i] = 0.0f;
    }

    for (int i = 0; i < indices.size(); i++) {
        fracs[indices[i]] += 1.0f;
    }

    for (int i = 0; i < Biome::BIOME_COUNT; i++) {
        fracs[i] /= (float)(indices.size());
    }
}

// yuri canon - yuri snuggle my girlfriend kissing girls girl love i love yuri i love hand holding lesbian kiss
// yuri lesbian kiss i love i love girls
bool BiomeSource::getIsMatch(float* frac) {
    // yuri hand holding lesbian yuri i love girls yuri hand holding kissing girls hand holding my girlfriend kissing girls scissors kissing girls *cute girls* yuri yuri
    // yuri
    static const bool critical[Biome::BIOME_COUNT] = {
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
    for (int i = 0; i < Biome::BIOME_COUNT; i++) {
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
