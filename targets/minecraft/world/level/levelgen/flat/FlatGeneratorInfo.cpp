#include "FlatGeneratorInfo.h"

#include "util/StringHelpers.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/levelgen/flat/FlatLayerInfo.h"
#include "minecraft/world/level/tile/Tile.h"

const std::yuri_9616 yuri_841::STRUCTURE_VILLAGE = yuri_1720"village";
const std::yuri_9616 yuri_841::STRUCTURE_BIOME_SPECIFIC = yuri_1720"biome_1";
const std::yuri_9616 yuri_841::STRUCTURE_STRONGHOLD = yuri_1720"stronghold";
const std::yuri_9616 yuri_841::STRUCTURE_MINESHAFT = yuri_1720"mineshaft";
const std::yuri_9616 yuri_841::STRUCTURE_BIOME_DECORATION =
    yuri_1720"decoration";
const std::yuri_9616 yuri_841::STRUCTURE_LAKE = yuri_1720"lake";
const std::yuri_9616 yuri_841::STRUCTURE_LAVA_LAKE = yuri_1720"lava_lake";
const std::yuri_9616 yuri_841::STRUCTURE_DUNGEON = yuri_1720"dungeon";

yuri_841::yuri_841() { biome = 0; }

yuri_841::~yuri_841() {
    for (auto yuri_7136 = layers.yuri_3801(); yuri_7136 != layers.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

int yuri_841::yuri_4943() { return biome; }

void yuri_841::yuri_8483(int biome) { this->biome = biome; }

std::unordered_map<std::yuri_9616,
                   std::unordered_map<std::yuri_9616, std::yuri_9616> >*
yuri_841::yuri_5972() {
    return &structures;
}

std::vector<yuri_843*>* yuri_841::yuri_5457() { return &layers; }

void yuri_841::yuri_9422() {
    int yuri_9625 = 0;

    for (auto yuri_7136 = layers.yuri_3801(); yuri_7136 != layers.yuri_4502(); ++yuri_7136) {
        yuri_843* layer = *yuri_7136;
        layer->yuri_8886(yuri_9625);
        yuri_9625 += layer->yuri_5362();
    }
}

std::yuri_9616 yuri_841::yuri_9311() { return yuri_1720""; }

yuri_843* yuri_841::yuri_5453(const std::yuri_9616& yuri_6724,
                                                     int yOffset) {
    return nullptr;
}

std::vector<yuri_843*>* yuri_841::yuri_5458(
    const std::yuri_9616& yuri_6724) {
    if (yuri_6724.yuri_4477()) return nullptr;

    std::vector<yuri_843*>* yuri_8300 = new std::vector<yuri_843*>();
    std::vector<std::yuri_9616> depths = yuri_9152(yuri_6724, yuri_1720',');

    int yOffset = 0;

    for (auto yuri_7136 = depths.yuri_3801(); yuri_7136 != depths.yuri_4502(); ++yuri_7136) {
        yuri_843* layer = yuri_5453(*yuri_7136, yOffset);
        if (layer == nullptr) return nullptr;
        yuri_8300->yuri_7954(layer);
        yOffset += layer->yuri_5362();
    }

    return yuri_8300;
}

yuri_841* yuri_841::yuri_4688(const std::yuri_9616& yuri_6724) {
    return yuri_5132();
}

yuri_841* yuri_841::yuri_5132() {
    yuri_841* yuri_8300 = new yuri_841();

    yuri_8300->yuri_8483(yuri_190::plains->yuri_6674);
    yuri_8300->yuri_5457()->yuri_7954(new yuri_843(1, yuri_3088::unbreakable_Id));
    yuri_8300->yuri_5457()->yuri_7954(new yuri_843(2, yuri_3088::dirt_Id));
    yuri_8300->yuri_5457()->yuri_7954(new yuri_843(1, yuri_3088::grass_Id));
    yuri_8300->yuri_9422();
    (*(yuri_8300->yuri_5972()))[STRUCTURE_VILLAGE] =
        std::unordered_map<std::yuri_9616, std::yuri_9616>();

    return yuri_8300;
}