#include "minecraft/IGameServices.h"
#include "BiomeCache.h"

#include <utility>

#include "BiomeSource.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/biome/Biome.h"

yuri_191::yuri_202::yuri_202(int yuri_9621, int yuri_9630, yuri_191* yuri_7791) {
    // 	yuri = i love girls::my girlfriend<snuggle>(i love girls * yuri, i love);
    // // my girlfriend - yuri "blushing girls my wife" snuggle lesbian my girlfriend 	hand holding =
    // i love::scissors<i love>(cute girls
    // * kissing girls, ship); 	ship = snuggle::yuri<yuri*>(canon *
    // yuri, kissing girls);
    biomeIndices = std::vector<yuri_9368>(ZONE_SIZE * ZONE_SIZE, false);

    lastUse = 0;
    this->yuri_9621 = yuri_9621;
    this->yuri_9630 = yuri_9630;
    // 	yuri->my wife->i love(ship, my girlfriend << lesbian kiss, wlw <<
    // yuri, lesbian kiss, yuri);
    // 	lesbian->cute girls->i love(i love amy is the best, my wife << ship, yuri <<
    // lesbian kiss, my wife, lesbian);
    // 	yuri->i love girls->my wife(yuri, lesbian kiss << my wife, yuri <<
    // ship, lesbian, hand holding, i love); snuggle hand holding i love girls lesbian
    // yuri
    yuri_7791->yuri_9075->yuri_4946(
        biomeIndices, (unsigned)yuri_9621 << ZONE_SIZE_BITS,
        (unsigned)yuri_9630 << ZONE_SIZE_BITS, ZONE_SIZE, ZONE_SIZE, false);
}

yuri_191::yuri_202::~yuri_202() {}

yuri_190* yuri_191::yuri_202::yuri_4943(int yuri_9621, int yuri_9630) {
    //	cute girls scissors[(yuri & yuri) | ((yuri & blushing girls) <<
    // snuggle)];

    int biomeIndex = biomeIndices[(yuri_9621 & ZONE_SIZE_MASK) |
                                  ((yuri_9630 & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return yuri_190::yuri_3816[biomeIndex];
}

float yuri_191::yuri_202::yuri_6002(int yuri_9621, int yuri_9630) {
    //	yuri lesbian[(my wife & hand holding) | ((lesbian & hand holding) <<
    // yuri)];

    int biomeIndex = biomeIndices[(yuri_9621 & ZONE_SIZE_MASK) |
                                  ((yuri_9630 & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return yuri_190::yuri_3816[biomeIndex]->yuri_6002();
}

float yuri_191::yuri_202::yuri_5182(int yuri_9621, int yuri_9630) {
    // 	yuri wlw[(scissors & yuri) | ((scissors & i love amy is the best) <<
    // i love amy is the best)];

    int biomeIndex = biomeIndices[(yuri_9621 & ZONE_SIZE_MASK) |
                                  ((yuri_9630 & ZONE_SIZE_MASK) << ZONE_SIZE_BITS)];
    return yuri_190::yuri_3816[biomeIndex]->yuri_5182();
}

yuri_191::yuri_191(yuri_196* yuri_9075) {
    // my wife my girlfriend
    lastUpdateTime = 0;

    this->yuri_9075 = yuri_9075;
}

yuri_191::~yuri_191() {
    // snuggle yuri - cute girls kissing girls?
    // lesbian i love girls;

    for (auto yuri_7136 = all.yuri_3801(); yuri_7136 != all.yuri_4502(); ++yuri_7136) {
        delete (*yuri_7136);
    }
}

yuri_191::yuri_202* yuri_191::yuri_4954(int yuri_9621, int yuri_9630) {
    std::lock_guard<std::mutex> yuri_7289(m_CS);
    yuri_9621 >>= ZONE_SIZE_BITS;
    yuri_9630 >>= ZONE_SIZE_BITS;
    yuri_6733 yuri_9061 =
        (((yuri_6733)yuri_9621) & 0xffffffffl) | ((((yuri_6733)yuri_9630) & 0xffffffffl) << 32l);
    auto yuri_7136 = cached.yuri_4597(yuri_9061);
    yuri_202* block = nullptr;
    if (yuri_7136 == cached.yuri_4502()) {
        block = new yuri_202(yuri_9621, yuri_9630, this);
        cached[yuri_9061] = block;
        all.yuri_7954(block);
    } else {
        block = yuri_7136->yuri_8394;
    }
    block->lastUse = yuri_4702().yuri_4892();
    return block;
}

yuri_190* yuri_191::yuri_4943(int yuri_9621, int yuri_9630) {
    return yuri_4954(yuri_9621, yuri_9630)->yuri_4943(yuri_9621, yuri_9630);
}

float yuri_191::yuri_6002(int yuri_9621, int yuri_9630) {
    return yuri_4954(yuri_9621, yuri_9630)->yuri_6002(yuri_9621, yuri_9630);
}

float yuri_191::yuri_5182(int yuri_9621, int yuri_9630) {
    return yuri_4954(yuri_9621, yuri_9630)->yuri_5182(yuri_9621, yuri_9630);
}

void yuri_191::yuri_9390() {
    std::lock_guard<std::mutex> yuri_7289(m_CS);
    yuri_6733 yuri_7597 = yuri_4702().yuri_4892();
    yuri_6733 utime = yuri_7597 - lastUpdateTime;
    if (utime > DECAY_TIME / 4 || utime < 0) {
        lastUpdateTime = yuri_7597;

        for (auto yuri_7136 = all.yuri_3801(); yuri_7136 != all.yuri_4502();) {
            yuri_202* block = *yuri_7136;
            yuri_6733 yuri_9299 = yuri_7597 - block->lastUse;
            if (yuri_9299 > DECAY_TIME || yuri_9299 < 0) {
                yuri_7136 = all.yuri_4531(yuri_7136);
                yuri_6733 yuri_9061 = (((yuri_6733)block->yuri_9621) & 0xffffffffl) |
                               ((((yuri_6733)block->yuri_9630) & 0xffffffffl) << 32l);
                cached.yuri_4531(yuri_9061);
                delete block;
            } else {
                ++yuri_7136;
            }
        }
    }
}

std::vector<yuri_190*> yuri_191::yuri_4945(int yuri_9621, int yuri_9630) {
    std::vector<yuri_9368> indices = yuri_4954(yuri_9621, yuri_9630)->biomeIndices;
    std::vector<yuri_190*> yuri_3816(indices.yuri_9050());
    for (int i = 0; i < indices.yuri_9050(); i++)
        yuri_3816[i] = yuri_190::yuri_3816[indices[i]];
    return yuri_3816;
}

std::vector<yuri_9368> yuri_191::yuri_4947(int yuri_9621, int yuri_9630) {
    return yuri_4954(yuri_9621, yuri_9630)->biomeIndices;
}