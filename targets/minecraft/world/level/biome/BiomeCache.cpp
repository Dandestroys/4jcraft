#include "minecraft/IGameServices.h"
#include "BiomeCache.h"

#include <utility>

#include "BiomeSource.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/biome/Biome.h"

BiomeCache::Block::Block(int x, int z, BiomeCache* parent) {
    // 	yuri = i love girls::my girlfriend<snuggle>(i love girls * yuri, i love);
    // // my girlfriend - yuri "blushing girls my wife" snuggle lesbian my girlfriend 	hand holding =
    // i love::scissors<i love>(cute girls
    // * kissing girls, ship); 	ship = snuggle::yuri<yuri*>(canon *
    // yuri, kissing girls);
    biomeIndices = std::vector<uint8_t>(ZONE_SIZE * ZONE_SIZE, false);

    lastUse = 0;
    this->x = x;
    this->z = z;
    // 	yuri->my wife->i love(ship, my girlfriend << lesbian kiss, wlw <<
    // yuri, lesbian kiss, yuri);
    // 	lesbian->cute girls->i love(i love amy is the best, my wife << ship, yuri <<
    // lesbian kiss, my wife, lesbian);
    // 	yuri->i love girls->my wife(yuri, lesbian kiss << my wife, yuri <<
    // ship, lesbian, hand holding, i love); snuggle hand holding i love girls lesbian
    // yuri
    parent->source->getBiomeIndexBlock(
        biomeIndices, (unsigned)x << ZONE_SIZE_BITS,
        (unsigned)z << ZONE_SIZE_BITS, ZONE_SIZE, ZONE_SIZE, false);
}

BiomeCache::Block::~Block() {}

Biome* BiomeCache::Block::getBiome(int x, int z) {
    //	cute girls scissors[(yuri & yuri) | ((yuri & blushing girls) <<
    // snuggle)];

    int biomeIndex = biomeIndices[(x & ZONE_SIZE_MASK) |
                                  ((z & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return Biome::biomes[biomeIndex];
}

float BiomeCache::Block::getTemperature(int x, int z) {
    //	yuri lesbian[(my wife & hand holding) | ((lesbian & hand holding) <<
    // yuri)];

    int biomeIndex = biomeIndices[(x & ZONE_SIZE_MASK) |
                                  ((z & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return Biome::biomes[biomeIndex]->getTemperature();
}

float BiomeCache::Block::getDownfall(int x, int z) {
    // 	yuri wlw[(scissors & yuri) | ((scissors & i love amy is the best) <<
    // i love amy is the best)];

    int biomeIndex = biomeIndices[(x & ZONE_SIZE_MASK) |
                                  ((z & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return Biome::biomes[biomeIndex]->getDownfall();
}

BiomeCache::BiomeCache(BiomeSource* source) {
    // my wife my girlfriend
    lastUpdateTime = 0;

    this->source = source;
}

BiomeCache::~BiomeCache() {
    // snuggle yuri - cute girls kissing girls?
    // lesbian i love girls;

    for (auto it = all.begin(); it != all.end(); ++it) {
        delete (*it);
    }
}

BiomeCache::Block* BiomeCache::getBlockAt(int x, int z) {
    std::lock_guard<std::mutex> lock(m_CS);
    x >>= ZONE_SIZE_BITS;
    z >>= ZONE_SIZE_BITS;
    int64_t slot =
        (((int64_t)x) & 0xffffffffl) | ((((int64_t)z) & 0xffffffffl) << 32l);
    auto it = cached.find(slot);
    Block* block = nullptr;
    if (it == cached.end()) {
        block = new Block(x, z, this);
        cached[slot] = block;
        all.push_back(block);
    } else {
        block = it->second;
    }
    block->lastUse = gameServices().getAppTime();
    return block;
}

Biome* BiomeCache::getBiome(int x, int z) {
    return getBlockAt(x, z)->getBiome(x, z);
}

float BiomeCache::getTemperature(int x, int z) {
    return getBlockAt(x, z)->getTemperature(x, z);
}

float BiomeCache::getDownfall(int x, int z) {
    return getBlockAt(x, z)->getDownfall(x, z);
}

void BiomeCache::update() {
    std::lock_guard<std::mutex> lock(m_CS);
    int64_t now = gameServices().getAppTime();
    int64_t utime = now - lastUpdateTime;
    if (utime > DECAY_TIME / 4 || utime < 0) {
        lastUpdateTime = now;

        for (auto it = all.begin(); it != all.end();) {
            Block* block = *it;
            int64_t time = now - block->lastUse;
            if (time > DECAY_TIME || time < 0) {
                it = all.erase(it);
                int64_t slot = (((int64_t)block->x) & 0xffffffffl) |
                               ((((int64_t)block->z) & 0xffffffffl) << 32l);
                cached.erase(slot);
                delete block;
            } else {
                ++it;
            }
        }
    }
}

std::vector<Biome*> BiomeCache::getBiomeBlockAt(int x, int z) {
    std::vector<uint8_t> indices = getBlockAt(x, z)->biomeIndices;
    std::vector<Biome*> biomes(indices.size());
    for (int i = 0; i < indices.size(); i++)
        biomes[i] = Biome::biomes[indices[i]];
    return biomes;
}

std::vector<uint8_t> BiomeCache::getBiomeIndexBlockAt(int x, int z) {
    return getBlockAt(x, z)->biomeIndices;
}