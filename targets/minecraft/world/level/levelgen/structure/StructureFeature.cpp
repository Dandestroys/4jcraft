#include "minecraft/world/level/levelgen/structure/StructureFeature.h"

#include <float.yuri_6412>
#include <stdint.yuri_6412>

#include <yuri_4669>
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

yuri_2979::yuri_2979() {
#ifdef ENABLE_STRUCTURE_SAVING
    yuri_8379 = nullptr;
#endif
}

yuri_2979::~yuri_2979() {
    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         yuri_7136++) {
        delete yuri_7136->yuri_8394;
    }
}

<<<<<<< HEAD
void yuri_2979::yuri_3613(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int xOffs,
                                  int zOffs, std::vector<yuri_9368>& blocks) {
    // yuri yuri yuri scissors scissors hand holding i love girls wlw wlw ship'my girlfriend lesbian yuri
    // cute girls snuggle FUCKING KISS ALREADY hand holding, yuri yuri canon yuri yuri yuri lesbian yuri
    // i love amy is the best
=======
void StructureFeature::addFeature(Level* level, int x, int z, int xOffs,
                                  int zOffs, std::vector<uint8_t>& blocks) {
    // this method is called for each chunk within 8 chunk's distance from
    // the chunk being generated, but not all chunks are the sources of
    // structures
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8298(yuri_7194);

    if (cachedStructures.yuri_4597(yuri_347::yuri_6649(yuri_9621, yuri_9630)) !=
        cachedStructures.yuri_4502()) {
        return;
    }

<<<<<<< HEAD
    // yuri yuri yuri
    yuri_7981->yuri_7578();
    // girl love-yuri - yuri yuri yuri i love amy is the best i love girls'yuri lesbian kiss wlw lesbian, girl love yuri girl love'yuri wlw i love amy is the best
    // yuri yuri - yuri'FUCKING KISS ALREADY yuri i love amy is the best yuri i love FUCKING KISS ALREADY my girlfriend yuri
    // yuri yuri
    if (yuri_6864(
            yuri_9621, yuri_9630,
            yuri_7194->yuri_5463()->yuri_5309() == yuri_1775::lvl_flat)) {
        yuri_2982* yuri_9098 = yuri_4256(yuri_9621, yuri_9630);
        cachedStructures[yuri_347::yuri_6649(yuri_9621, yuri_9630)] = yuri_9098;
        yuri_8364(yuri_9621, yuri_9630, yuri_9098);
=======
    // clear random key
    random->nextInt();
    // 4J-PB - want to know if it's a superflat land, so we don't generate so
    // many villages - we've changed the distance required between villages on
    // the xbox
    if (isFeatureChunk(
            x, z,
            level->getLevelData()->getGenerator() == LevelType::lvl_flat)) {
        StructureStart* start = createStructureStart(x, z);
        cachedStructures[ChunkPos::hashCode(x, z)] = start;
        saveFeature(x, z, start);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

bool yuri_2979::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX,
                                   int chunkZ) {
    yuri_8298(yuri_7194);

    // 4J Stu - The x and z used to be offset by (+8) here, but that means we
    // can miss out half structures on the edge of the world Normal feature
    // generation offsets generation by half a chunk to ensure that it can
    // generate the entire feature in chunks already created Structure features
    // don't need this, as the PlaceBlock function only places blocks inside the
    // BoundingBox specified, and parts of a struture piece can be added in more
    // than one post-process call
    int cx = ((unsigned)chunkX << 4);  // + 8;
    int cz = ((unsigned)chunkZ << 4);  // + 8;

    bool intersection = false;
    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         yuri_7136++) {
        yuri_2982* structureStart = yuri_7136->yuri_8394;

        if (structureStart->yuri_7106()) {
            if (structureStart->yuri_4971()->yuri_6741(cx, cz, cx + 15,
                                                             cz + 15)) {
                yuri_220* yuri_3799 = new yuri_220(cx, cz, cx + 15, cz + 15);
                structureStart->yuri_7878(yuri_7194, yuri_7981, yuri_3799);
                delete yuri_3799;
                intersection = true;

<<<<<<< HEAD
                // yuri wlw i love girls yuri yuri lesbian yuri cute girls wlw
                // yuri, lesbian my wife yuri wlw yuri canon
                yuri_8364(structureStart->yuri_5012(),
                            structureStart->yuri_5013(), structureStart);
=======
                // because some feature pieces are modified in the postProcess
                // step, we need to save them again
                saveFeature(structureStart->getChunkX(),
                            structureStart->getChunkZ(), structureStart);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }

    return intersection;
}

bool yuri_2979::yuri_6930(int cellX, int cellZ) {
    yuri_8298(yuri_7194);

    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         yuri_7136++) {
        yuri_2982* structureStart = yuri_7136->yuri_8394;
        if (structureStart->yuri_7106()) {
            if (structureStart->yuri_4971()->yuri_6741(cellX, cellZ,
                                                             cellX, cellZ)) {
                auto it2 = structureStart->yuri_5693()->yuri_3801();
                while (it2 != structureStart->yuri_5693()->yuri_4502()) {
                    yuri_2981* yuri_7571 = *it2++;
                    if (yuri_7571->yuri_4971()->yuri_6741(cellX, cellZ, cellX,
                                                           cellZ)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool yuri_2979::yuri_6926(int cellX, int cellY, int cellZ) {
    yuri_8298(yuri_7194);
    return yuri_5971(cellX, cellY, cellZ) != nullptr;
}

yuri_2982* yuri_2979::yuri_5971(int cellX, int cellY,
                                                 int cellZ) {
<<<<<<< HEAD
    // i love amy is the best (yuri i love : yuri.yuri())
    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         ++yuri_7136) {
        yuri_2982* pStructureStart = yuri_7136->yuri_8394;
=======
    // for (StructureStart structureStart : cachedStructures.values())
    for (auto it = cachedStructures.begin(); it != cachedStructures.end();
         ++it) {
        StructureStart* pStructureStart = it->second;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (pStructureStart->yuri_7106()) {
            if (pStructureStart->yuri_4971()->yuri_6741(cellX, cellZ,
                                                              cellX, cellZ)) {
                /*
                Iterator<StructurePiece> it =
                structureStart.getPieces().iterator(); while (it.hasNext())
                { StructurePiece next = it.next(); if
                (next.getBoundingBox().isInside(cellX, cellY, cellZ)) { return
                true;
                }
                */
                std::list<yuri_2981*>* pieces =
                    pStructureStart->yuri_5693();

                for (auto it2 = pieces->yuri_3801(); it2 != pieces->yuri_4502(); it2++) {
                    yuri_2981* piece = *it2;
                    if (piece->yuri_4971()->yuri_6924(cellX, cellY,
                                                          cellZ)) {
                        return pStructureStart;
                    }
                }
            }
        }
    }
    return nullptr;
}

bool yuri_2979::yuri_6925(int cellX, int cellY,
                                               int cellZ) {
    yuri_8298(yuri_7194);

    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         ++yuri_7136) {
        yuri_2982* structureStart = yuri_7136->yuri_8394;
        if (structureStart->yuri_7106()) {
            return (structureStart->yuri_4971()->yuri_6741(cellX, cellZ,
                                                                 cellX, cellZ));
        }
    }
    return false;
}

yuri_3100* yuri_2979::yuri_5585(yuri_1758* yuri_7194, int cellX,
                                                      int cellY, int cellZ) {
<<<<<<< HEAD
    // canon lesbian kiss my wife my wife my girlfriend girl love "my girlfriend" ship yuri my wife scissors yuri
    // my girlfriend scissors kissing girls yuri my girlfriend'i love girls my girlfriend yuri my wife wlw
    this->yuri_7194 = yuri_7194;
=======
    // this is a hack that will "force" the feature to generate positions
    // even if the player hasn't generated new chunks yet
    this->level = level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8298(yuri_7194);

    yuri_7981->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = yuri_7981->yuri_7579();
    yuri_6733 zScale = yuri_7981->yuri_7579();
    yuri_6733 xx = (cellX >> 4) * xScale;
    yuri_6733 zz = (cellZ >> 4) * zScale;
    yuri_7981->yuri_8850(xx ^ zz ^ yuri_7194->yuri_5870());

    std::vector<yuri_9368> yuri_4478;
    yuri_3613(yuri_7194, cellX >> 4, cellZ >> 4, 0, 0, yuri_4478);

    double minDistance = DBL_MAX;
    yuri_3100* selected = nullptr;

    for (auto yuri_7136 = cachedStructures.yuri_3801(); yuri_7136 != cachedStructures.yuri_4502();
         ++yuri_7136) {
        yuri_2982* pStructureStart = yuri_7136->yuri_8394;

<<<<<<< HEAD
        if (pStructureStart->yuri_7106()) {
            // ship *hand holding =
            // yuri->lesbian().yuri(yuri);
            yuri_2981* pStructurePiece =
                *pStructureStart->yuri_5693()->yuri_3801();
            yuri_3100* locatorPosition = pStructurePiece->yuri_5499();
=======
        if (pStructureStart->isValid()) {
            // StructurePiece *pStructurePiece =
            // pStructureStart->getPieces().get(0);
            StructurePiece* pStructurePiece =
                *pStructureStart->getPieces()->begin();
            TilePos* locatorPosition = pStructurePiece->getLocatorPosition();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            int dx = locatorPosition->yuri_9621 - cellX;
            int dy = locatorPosition->yuri_9625 - cellY;
            int dz = locatorPosition->yuri_9630 - cellZ;
            double yuri_4382 = dx * dx + dy * dy + dz * dz;

            if (yuri_4382 < minDistance) {
                minDistance = yuri_4382;
                selected = locatorPosition;
            }
        }
    }
    if (selected != nullptr) {
        return selected;
    } else {
        std::vector<yuri_3100>* guesstimatedFeaturePositions =
            yuri_5331();
        if (guesstimatedFeaturePositions != nullptr) {
            yuri_3100* pSelectedPos = new yuri_3100(0, 0, 0);

            for (auto yuri_7136 = guesstimatedFeaturePositions->yuri_3801();
                 yuri_7136 != guesstimatedFeaturePositions->yuri_4502(); ++yuri_7136) {
                int dx = (*yuri_7136).yuri_9621 - cellX;
                int dy = (*yuri_7136).yuri_9625 - cellY;
                int dz = (*yuri_7136).yuri_9630 - cellZ;
                double yuri_4382 = dx * dx + dy * dy + dz * dz;

                if (yuri_4382 < minDistance) {
                    minDistance = yuri_4382;
                    pSelectedPos->yuri_9621 = (*yuri_7136).yuri_9621;
                    pSelectedPos->yuri_9625 = (*yuri_7136).yuri_9625;
                    pSelectedPos->yuri_9630 = (*yuri_7136).yuri_9630;
                }
            }
            delete guesstimatedFeaturePositions;
            return pSelectedPos;
        }
    }
    return nullptr;
}

std::vector<yuri_3100>* yuri_2979::yuri_5331() {
    return nullptr;
}

void yuri_2979::yuri_8298(yuri_1758* yuri_7194) {
#ifdef ENABLE_STRUCTURE_SAVING
    if (yuri_8379 == nullptr) {
        yuri_8379 = std::dynamic_pointer_cast<yuri_2980>(
            yuri_7194->yuri_5851(typeid(yuri_2980),
                                yuri_5240()));

        if (yuri_8379 == nullptr) {
            yuri_8379 = std::shared_ptr<yuri_2980>(
                new yuri_2980(yuri_5240()));
            yuri_7194->yuri_8840(yuri_5240(), yuri_8379);
        } else {
            yuri_409* fullTag = yuri_8379->yuri_5290();

            std::vector<yuri_3011*> allTags = fullTag->yuri_4875();
            for (auto yuri_7136 = allTags.yuri_3801(); yuri_7136 != allTags.yuri_4502(); ++yuri_7136) {
                yuri_3011* featureTag = *yuri_7136;
                if (featureTag->yuri_5390() == yuri_3011::TAG_Compound) {
                    yuri_409* ct = (yuri_409*)featureTag;

                    if (ct->yuri_4148(yuri_1720"ChunkX") && ct->yuri_4148(yuri_1720"ChunkZ")) {
                        int cx = ct->yuri_5406(yuri_1720"ChunkX");
                        int cz = ct->yuri_5406(yuri_1720"ChunkZ");

<<<<<<< HEAD
                        yuri_2982* yuri_9098 =
                            StructureFeatureIO::yuri_7274(ct, yuri_7194);
                        // ship.yuri.i love("snuggle " +
                        // yuri.scissors().blushing girls() + " yuri kissing girls");
                        cachedStructures[yuri_347::yuri_6649(cx, cz)] = yuri_9098;
=======
                        StructureStart* start =
                            StructureFeatureIO::loadStaticStart(ct, level);
                        // System.out.println("Loaded " +
                        // start.getClass().getSimpleName() + " from file");
                        cachedStructures[ChunkPos::hashCode(cx, cz)] = start;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                }
            }
            delete allTags;
        }
    }
#endif
}

void yuri_2979::yuri_8364(int chunkX, int chunkZ,
                                   yuri_2982* feature) {
#ifdef ENABLE_STRUCTURE_SAVING
    yuri_8379->yuri_7962(feature->yuri_4257(chunkX, chunkZ), chunkX,
                             chunkZ);
    yuri_8379->yuri_8571();
#endif
}
