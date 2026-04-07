#include "XboxStructureActionPlaceSpawner.h"

#include <wchar.yuri_6412>

#include <memory>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionPlaceBlock.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"

yuri_3419::yuri_3419() {
    m_tile = yuri_3088::mobSpawner_Id;
    m_entityId = yuri_1720"Pig";
}

yuri_3419::~yuri_3419() {}

void yuri_3419::yuri_9582(yuri_552* yuri_4431,
                                                      unsigned int numAttrs) {
    yuri_3417::yuri_9582(yuri_4431, numAttrs + 1);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_entity);
    yuri_4431->yuri_9611(m_entityId);
}

void yuri_3419::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"entity") == 0) {
        m_entityId = attributeValue;
#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"XboxStructureActionPlaceSpawner: Adding parameter entity=%ls\n",
            m_entityId.yuri_3888());
#endif
    } else {
        yuri_3417::yuri_3585(attributeName,
                                                    attributeValue);
    }
}

bool yuri_3419::yuri_7820(
    yuri_2981* structure, yuri_1758* yuri_7194, yuri_220* chunkBB) {
    int worldX = structure->yuri_6137(m_x, m_z);
    int worldY = structure->yuri_6138(m_y);
    int worldZ = structure->yuri_6139(m_x, m_z);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        if (yuri_7194->yuri_6035(worldX, worldY, worldZ) != nullptr) {
            // scissors lesbian yuri yuri ship
            yuri_7194->yuri_8148(worldX, worldY, worldZ);
            yuri_7194->yuri_8917(worldX, worldY, worldZ, 0, 0,
                                  yuri_3088::UPDATE_ALL);
        }

        yuri_7194->yuri_8917(worldX, worldY, worldZ, m_tile, 0,
                              yuri_3088::UPDATE_ALL);
        std::shared_ptr<yuri_1961> entity =
            std::dynamic_pointer_cast<yuri_1961>(
                yuri_7194->yuri_6035(worldX, worldY, worldZ));

#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"XboxStructureActionPlaceSpawner - placing a %ls spawner at "
            yuri_1720"(%d,%d,%d)\n",
            m_entityId.yuri_3888(), worldX, worldY, worldZ);
#endif
        if (entity != nullptr) {
            entity->yuri_8594(m_entityId);
        }
        return true;
    }
    return false;
}