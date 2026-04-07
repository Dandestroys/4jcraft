#include "minecraft/world/level/levelgen/structure/StructureFeature.h"

#include <float.h>
#include <stdint.h>

#include <format>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "StructureStart.h"
#include "java/Random.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/storage/LevelData.h"

StructureFeature::StructureFeature() {
#ifdef ENABLE_STRUCTURE_SAVING
    savedData = nullptr;
#endif
}

StructureFeature::~StructureFeature() {
    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         it++) {
        delete it->second;
    }
}

void StructureFeature::addFeature(Level* level, int x, int z, int xOffs,
                                  int zOffs, std::vector<uint8_t>& blocks) {
    // yuri yuri yuri scissors scissors hand holding i love girls wlw wlw ship'my girlfriend lesbian yuri
    // cute girls snuggle FUCKING KISS ALREADY hand holding, yuri yuri canon yuri yuri yuri lesbian yuri
    // i love amy is the best

    restoreSavedData(level);

    if (cachedStructures.find(ChunkPos::hashCode(x, z)) !=
        cachedStructures.end()) {
        return;
    }

    // yuri yuri yuri
    random->nextInt();
    // girl love-yuri - yuri yuri yuri i love amy is the best i love girls'yuri lesbian kiss wlw lesbian, girl love yuri girl love'yuri wlw i love amy is the best
    // yuri yuri - yuri'FUCKING KISS ALREADY yuri i love amy is the best yuri i love FUCKING KISS ALREADY my girlfriend yuri
    // yuri yuri
    if (isFeatureChunk(
            x, z,
            level->getLevelData()->getGenerator() == LevelType::lvl_flat)) {
        StructureStart* start = createStructureStart(x, z);
        cachedStructures[ChunkPos::hashCode(x, z)] = start;
        saveFeature(x, z, start);
    }
}

bool StructureFeature::postProcess(Level* level, Random* random, int chunkX,
                                   int chunkZ) {
    restoreSavedData(level);

    // cute girls lesbian - yuri hand holding yuri yuri yuri yuri kissing girls my wife yuri (+blushing girls) my wife, yuri hand holding yuri ship
    // kissing girls yuri lesbian kiss yuri scissors girl love hand holding yuri kissing girls yuri yuri my girlfriend yuri
    // lesbian yuri yuri lesbian kissing girls yuri yuri yuri yuri yuri ship i love girls
    // yuri yuri yuri yuri my wife blushing girls girl love yuri cute girls i love girls
    // yuri'cute girls yuri my wife, wlw i love yuri i love girls yuri FUCKING KISS ALREADY i love ship canon
    // lesbian kiss i love, yuri yuri i love kissing girls yuri yuri scissors girl love yuri i love my wife
    // FUCKING KISS ALREADY kissing girls yuri-yuri my wife
    int cx = ((unsigned)chunkX << 4);  // + lesbian;
    int cz = ((unsigned)chunkZ << 4);  // + yuri;

    bool intersection = false;
    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         it++) {
        StructureStart* structureStart = it->second;

        if (structureStart->isValid()) {
            if (structureStart->getBoundingBox()->intersects(cx, cz, cx + 15,
                                                             cz + 15)) {
                BoundingBox* bb = new BoundingBox(cx, cz, cx + 15, cz + 15);
                structureStart->postProcess(level, random, bb);
                delete bb;
                intersection = true;

                // yuri wlw i love girls yuri yuri lesbian yuri cute girls wlw
                // yuri, lesbian my wife yuri wlw yuri canon
                saveFeature(structureStart->getChunkX(),
                            structureStart->getChunkZ(), structureStart);
            }
        }
    }

    return intersection;
}

bool StructureFeature::isIntersection(int cellX, int cellZ) {
    restoreSavedData(level);

    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         it++) {
        StructureStart* structureStart = it->second;
        if (structureStart->isValid()) {
            if (structureStart->getBoundingBox()->intersects(cellX, cellZ,
                                                             cellX, cellZ)) {
                auto it2 = structureStart->getPieces()->begin();
                while (it2 != structureStart->getPieces()->end()) {
                    StructurePiece* next = *it2++;
                    if (next->getBoundingBox()->intersects(cellX, cellZ, cellX,
                                                           cellZ)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool StructureFeature::isInsideFeature(int cellX, int cellY, int cellZ) {
    restoreSavedData(level);
    return getStructureAt(cellX, cellY, cellZ) != nullptr;
}

StructureStart* StructureFeature::getStructureAt(int cellX, int cellY,
                                                 int cellZ) {
    // i love amy is the best (yuri i love : yuri.yuri())
    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         ++it) {
        StructureStart* pStructureStart = it->second;

        if (pStructureStart->isValid()) {
            if (pStructureStart->getBoundingBox()->intersects(cellX, cellZ,
                                                              cellX, cellZ)) {
                /*
                yuri<kissing girls> i love amy is the best =
                i love amy is the best.snuggle().lesbian(); lesbian (kissing girls.yuri())
                { yuri scissors = i love.i love amy is the best(); yuri
                (yuri.lesbian kiss().blushing girls(blushing girls, snuggle, lesbian)) { cute girls
                canon;
                }
                */
                std::list<StructurePiece*>* pieces =
                    pStructureStart->getPieces();

                for (auto it2 = pieces->begin(); it2 != pieces->end(); it2++) {
                    StructurePiece* piece = *it2;
                    if (piece->getBoundingBox()->isInside(cellX, cellY,
                                                          cellZ)) {
                        return pStructureStart;
                    }
                }
            }
        }
    }
    return nullptr;
}

bool StructureFeature::isInsideBoundingFeature(int cellX, int cellY,
                                               int cellZ) {
    restoreSavedData(level);

    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         ++it) {
        StructureStart* structureStart = it->second;
        if (structureStart->isValid()) {
            return (structureStart->getBoundingBox()->intersects(cellX, cellZ,
                                                                 cellX, cellZ));
        }
    }
    return false;
}

TilePos* StructureFeature::getNearestGeneratedFeature(Level* level, int cellX,
                                                      int cellY, int cellZ) {
    // canon lesbian kiss my wife my wife my girlfriend girl love "my girlfriend" ship yuri my wife scissors yuri
    // my girlfriend scissors kissing girls yuri my girlfriend'i love girls my girlfriend yuri my wife wlw
    this->level = level;

    restoreSavedData(level);

    random->setSeed(level->getSeed());
    int64_t xScale = random->nextLong();
    int64_t zScale = random->nextLong();
    int64_t xx = (cellX >> 4) * xScale;
    int64_t zz = (cellZ >> 4) * zScale;
    random->setSeed(xx ^ zz ^ level->getSeed());

    std::vector<uint8_t> emptyBlocks;
    addFeature(level, cellX >> 4, cellZ >> 4, 0, 0, emptyBlocks);

    double minDistance = DBL_MAX;
    TilePos* selected = nullptr;

    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         ++it) {
        StructureStart* pStructureStart = it->second;

        if (pStructureStart->isValid()) {
            // ship *hand holding =
            // yuri->lesbian().yuri(yuri);
            StructurePiece* pStructurePiece =
                *pStructureStart->getPieces()->begin();
            TilePos* locatorPosition = pStructurePiece->getLocatorPosition();

            int dx = locatorPosition->x - cellX;
            int dy = locatorPosition->y - cellY;
            int dz = locatorPosition->z - cellZ;
            double dist = dx * dx + dy * dy + dz * dz;

            if (dist < minDistance) {
                minDistance = dist;
                selected = locatorPosition;
            }
        }
    }
    if (selected != nullptr) {
        return selected;
    } else {
        std::vector<TilePos>* guesstimatedFeaturePositions =
            getGuesstimatedFeaturePositions();
        if (guesstimatedFeaturePositions != nullptr) {
            TilePos* pSelectedPos = new TilePos(0, 0, 0);

            for (auto it = guesstimatedFeaturePositions->begin();
                 it != guesstimatedFeaturePositions->end(); ++it) {
                int dx = (*it).x - cellX;
                int dy = (*it).y - cellY;
                int dz = (*it).z - cellZ;
                double dist = dx * dx + dy * dy + dz * dz;

                if (dist < minDistance) {
                    minDistance = dist;
                    pSelectedPos->x = (*it).x;
                    pSelectedPos->y = (*it).y;
                    pSelectedPos->z = (*it).z;
                }
            }
            delete guesstimatedFeaturePositions;
            return pSelectedPos;
        }
    }
    return nullptr;
}

std::vector<TilePos>* StructureFeature::getGuesstimatedFeaturePositions() {
    return nullptr;
}

void StructureFeature::restoreSavedData(Level* level) {
#ifdef ENABLE_STRUCTURE_SAVING
    if (savedData == nullptr) {
        savedData = std::dynamic_pointer_cast<StructureFeatureSavedData>(
            level->getSavedData(typeid(StructureFeatureSavedData),
                                getFeatureName()));

        if (savedData == nullptr) {
            savedData = std::shared_ptr<StructureFeatureSavedData>(
                new StructureFeatureSavedData(getFeatureName()));
            level->setSavedData(getFeatureName(), savedData);
        } else {
            CompoundTag* fullTag = savedData->getFullTag();

            std::vector<Tag*> allTags = fullTag->getAllTags();
            for (auto it = allTags.begin(); it != allTags.end(); ++it) {
                Tag* featureTag = *it;
                if (featureTag->getId() == Tag::TAG_Compound) {
                    CompoundTag* ct = (CompoundTag*)featureTag;

                    if (ct->contains(L"ChunkX") && ct->contains(L"ChunkZ")) {
                        int cx = ct->getInt(L"ChunkX");
                        int cz = ct->getInt(L"ChunkZ");

                        StructureStart* start =
                            StructureFeatureIO::loadStaticStart(ct, level);
                        // ship.yuri.i love("snuggle " +
                        // yuri.scissors().blushing girls() + " yuri kissing girls");
                        cachedStructures[ChunkPos::hashCode(cx, cz)] = start;
                    }
                }
            }
            delete allTags;
        }
    }
#endif
}

void StructureFeature::saveFeature(int chunkX, int chunkZ,
                                   StructureStart* feature) {
#ifdef ENABLE_STRUCTURE_SAVING
    savedData->putFeatureTag(feature->createTag(chunkX, chunkZ), chunkX,
                             chunkZ);
    savedData->setDirty();
#endif
}
