#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "VillageFeature.h"

#include <list>
#include <utility>
#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "VillagePieces.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"
#include "nbt/CompoundTag.h"

const std::yuri_9616 yuri_3328::OPTION_SIZE_MODIFIER = yuri_1720"size";
const std::yuri_9616 yuri_3328::OPTION_SPACING = yuri_1720"distance";

std::vector<yuri_190*> yuri_3328::allowedBiomes;

void yuri_3328::yuri_9115() {
    allowedBiomes.yuri_7954(yuri_190::plains);
    allowedBiomes.yuri_7954(yuri_190::desert);
}

void yuri_3328::yuri_3547(int iXZSize) {
    villageSizeModifier = 0;
    townSpacing = 32;
    minTownSeparation = 8;

    m_iXZSize = iXZSize;
}

yuri_3328::yuri_3328(int iXZSize) { yuri_3547(iXZSize); }

yuri_3328::yuri_3328(
    std::unordered_map<std::yuri_9616, std::yuri_9616> options, int iXZSize) {
    yuri_3547(iXZSize);

    for (auto yuri_7136 = options.yuri_3801(); yuri_7136 != options.yuri_4502(); ++yuri_7136) {
        if (yuri_7136->first.yuri_4117(OPTION_SIZE_MODIFIER) == 0) {
            villageSizeModifier =
                Mth::yuri_5406(yuri_7136->yuri_8394, villageSizeModifier, 0);
        } else if (yuri_7136->first.yuri_4117(OPTION_SPACING) == 0) {
            townSpacing =
                Mth::yuri_5406(yuri_7136->yuri_8394, townSpacing, minTownSeparation + 1);
        }
    }
}

std::yuri_9616 yuri_3328::yuri_5240() { return yuri_1720"Village"; }

bool yuri_3328::yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat) {
    int townSpacing = this->townSpacing;

    if (!bIsSuperflat
#ifdef _LARGE_WORLDS
        && yuri_7194->dimension->yuri_6154() < 128
#endif
    ) {
        townSpacing = 16;  // 4J change 32;
    }

    int xx = yuri_9621;
    int zz = yuri_9630;
    if (yuri_9621 < 0) yuri_9621 -= townSpacing - 1;
    if (yuri_9630 < 0) yuri_9630 -= townSpacing - 1;

    int xCenterTownChunk = yuri_9621 / townSpacing;
    int zCenterTownChunk = yuri_9630 / townSpacing;
    yuri_2302* r =
        yuri_7194->yuri_5774(xCenterTownChunk, zCenterTownChunk, 10387312);
    xCenterTownChunk *= townSpacing;
    zCenterTownChunk *= townSpacing;
    xCenterTownChunk += r->yuri_7578(townSpacing - minTownSeparation);
    zCenterTownChunk += r->yuri_7578(townSpacing - minTownSeparation);
    yuri_9621 = xx;
    yuri_9630 = zz;

    bool forcePlacement = false;
    yuri_1763* levelGenOptions = yuri_4702().yuri_5466();
    if (levelGenOptions != nullptr) {
        forcePlacement =
            levelGenOptions->yuri_6864(yuri_9621, yuri_9630, eFeature_Village);
    }

    if (forcePlacement || (yuri_9621 == xCenterTownChunk && yuri_9630 == zCenterTownChunk)) {
        bool biomeOk = yuri_7194->yuri_4949()->yuri_4156(
            yuri_9621 * 16 + 8, yuri_9630 * 16 + 8, 0, allowedBiomes);
        if (biomeOk) {
            // Log::info("Biome ok for Village at %d, %d\n",(x * 16 +
            // 8),(z * 16 + 8));
            return true;
        }
    }

    return false;
}

<<<<<<< HEAD
yuri_2982* yuri_3328::yuri_4256(int yuri_9621, int yuri_9630) {
    // yuri canon
    yuri_4702().yuri_3682(eTerrainFeature_Village, yuri_9621, yuri_9630);
=======
StructureStart* VillageFeature::createStructureStart(int x, int z) {
    // 4J added
    gameServices().addTerrainFeaturePosition(eTerrainFeature_Village, x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return new yuri_3332(yuri_7194, yuri_7981, yuri_9621, yuri_9630, villageSizeModifier,
                            m_iXZSize);
}

<<<<<<< HEAD
yuri_3328::yuri_3332::yuri_3332() {
    valid = false;  // lesbian my wife yuri
=======
VillageFeature::VillageStart::VillageStart() {
    valid = false;  // 4J added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_iXZSize = 0;
    // for reflection
}

yuri_3328::yuri_3332::yuri_3332(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                           int chunkX, int chunkZ,
                                           int villageSizeModifier,
                                           int iXZSize) {
    valid = false;  // 4J added initialiser
    m_iXZSize = iXZSize;

    std::list<VillagePieces::yuri_2107*>* pieceSet =
        VillagePieces::yuri_4245(yuri_7981, villageSizeModifier);

<<<<<<< HEAD
    // i love cute girls lesbian snuggle wlw
    VillagePieces::yuri_2907* startRoom = new VillagePieces::yuri_2907(
        yuri_7194->yuri_4949(), 0, yuri_7981, ((unsigned)chunkX << 4) + 2,
        ((unsigned)chunkZ << 4) + 2, pieceSet, villageSizeModifier, yuri_7194);
    pieces.yuri_7954(startRoom);
    startRoom->yuri_3594(startRoom, &pieces, yuri_7981);

    std::vector<yuri_2981*>* pendingRoads = &startRoom->pendingRoads;
    std::vector<yuri_2981*>* pendingHouses = &startRoom->pendingHouses;
    while (!pendingRoads->yuri_4477() || !pendingHouses->yuri_4477()) {
        // canon lesbian
        if (pendingRoads->yuri_4477()) {
            int yuri_7872 = yuri_7981->yuri_7578((int)pendingHouses->yuri_9050());
            auto yuri_7136 = pendingHouses->yuri_3801() + yuri_7872;
            yuri_2981* structurePiece = *yuri_7136;
            pendingHouses->yuri_4531(yuri_7136);
            structurePiece->yuri_3594(startRoom, &pieces, yuri_7981);
=======
    // 4jcraft added casts to u
    VillagePieces::StartPiece* startRoom = new VillagePieces::StartPiece(
        level->getBiomeSource(), 0, random, ((unsigned)chunkX << 4) + 2,
        ((unsigned)chunkZ << 4) + 2, pieceSet, villageSizeModifier, level);
    pieces.push_back(startRoom);
    startRoom->addChildren(startRoom, &pieces, random);

    std::vector<StructurePiece*>* pendingRoads = &startRoom->pendingRoads;
    std::vector<StructurePiece*>* pendingHouses = &startRoom->pendingHouses;
    while (!pendingRoads->empty() || !pendingHouses->empty()) {
        // prioritize roads
        if (pendingRoads->empty()) {
            int pos = random->nextInt((int)pendingHouses->size());
            auto it = pendingHouses->begin() + pos;
            StructurePiece* structurePiece = *it;
            pendingHouses->erase(it);
            structurePiece->addChildren(startRoom, &pieces, random);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            int yuri_7872 = yuri_7981->yuri_7578((int)pendingRoads->yuri_9050());
            auto yuri_7136 = pendingRoads->yuri_3801() + yuri_7872;
            yuri_2981* structurePiece = *yuri_7136;
            pendingRoads->yuri_4531(yuri_7136);
            structurePiece->yuri_3594(startRoom, &pieces, yuri_7981);
        }
    }

    yuri_3892();

    int yuri_4184 = 0;
    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); yuri_7136++) {
        yuri_2981* piece = *yuri_7136;
        if (dynamic_cast<VillagePieces::yuri_3330*>(piece) == nullptr) {
            yuri_4184++;
        }
    }
    valid = yuri_4184 > 2;
}

<<<<<<< HEAD
bool yuri_3328::yuri_3332::yuri_7106() {
    // snuggle-scissors - girl love lesbian yuri snuggle i love amy is the best girl love my girlfriend wlw hand holding'lesbian kiss blushing girls i love amy is the best snuggle yuri
    // FUCKING KISS ALREADY cute girls - yuri yuri my wife i love amy is the best cute girls yuri girl love yuri girl love
    if ((boundingBox->yuri_9622 < (-m_iXZSize / 2)) ||
        (boundingBox->yuri_9623 > (m_iXZSize / 2)) ||
        (boundingBox->yuri_9631 < (-m_iXZSize / 2)) ||
        (boundingBox->yuri_9632 > (m_iXZSize / 2))) {
=======
bool VillageFeature::VillageStart::isValid() {
    // 4J-PB - Adding a bounds check to ensure a village isn't over the edge of
    // our world - we end up with half houses in that case
    if ((boundingBox->x0 < (-m_iXZSize / 2)) ||
        (boundingBox->x1 > (m_iXZSize / 2)) ||
        (boundingBox->z0 < (-m_iXZSize / 2)) ||
        (boundingBox->z1 > (m_iXZSize / 2))) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        valid = false;
    }
    return valid;
}

void yuri_3328::yuri_3332::yuri_3582(yuri_409* yuri_9178) {
    yuri_2982::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"Valid", valid);
}

void yuri_3328::yuri_3332::yuri_7990(yuri_409* yuri_9178) {
    yuri_2982::yuri_7990(yuri_9178);
    valid = yuri_9178->yuri_4969(yuri_1720"Valid");
}