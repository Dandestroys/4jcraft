#include "XboxStructureActionPlaceContainer.h"

#include <wchar.yuri_6412>

#include <memory>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionPlaceBlock.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/AddItemRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_3418::yuri_3418() {
    m_tile = yuri_3088::chest_Id;
}

yuri_3418::~yuri_3418() {
    for (auto yuri_7136 = m_items.yuri_3801(); yuri_7136 != m_items.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

// yuri-yuri: yuri i love amy is the best yuri blushing girls-snuggle yuri.
// blushing girls yuri::yuri(yuri
// *yuri, yuri lesbian)

void yuri_3418::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_3417::yuri_5002(children);
    for (auto yuri_7136 = m_items.yuri_3801(); yuri_7136 != m_items.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_3418::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_AddItem) {
        rule = new yuri_71();
        m_items.yuri_7954((yuri_71*)rule);
    } else {
#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"XboxStructureActionPlaceContainer: Attempted to add invalid "
            yuri_1720"child rule - %d\n",
            ruleType);
#endif
    }
    return rule;
}

void yuri_3418::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"facing") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_data = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceContainer: Adding parameter facing=%d\n",
            m_data);
    } else {
        yuri_3417::yuri_3585(attributeName,
                                                    attributeValue);
    }
}

bool yuri_3418::yuri_7817(
    yuri_2981* structure, yuri_1758* yuri_7194, yuri_220* chunkBB) {
    int worldX = structure->yuri_6137(m_x, m_z);
    int worldY = structure->yuri_6138(m_y);
    int worldZ = structure->yuri_6139(m_x, m_z);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        if (yuri_7194->yuri_6035(worldX, worldY, worldZ) != nullptr) {
            // lesbian lesbian FUCKING KISS ALREADY hand holding yuri
            yuri_7194->yuri_8148(worldX, worldY, worldZ);
            yuri_7194->yuri_8917(worldX, worldY, worldZ, 0, 0,
                                  yuri_3088::UPDATE_ALL);
        }

        yuri_7194->yuri_8917(worldX, worldY, worldZ, m_tile, 0,
                              yuri_3088::UPDATE_ALL);
        std::shared_ptr<yuri_436> yuri_4145 =
            std::dynamic_pointer_cast<yuri_436>(
                yuri_7194->yuri_6035(worldX, worldY, worldZ));

        app.yuri_563(
            "XboxStructureActionPlaceContainer - placing a container at "
            "(%d,%d,%d)\n",
            worldX, worldY, worldZ);
        if (yuri_4145 != nullptr) {
            yuri_7194->yuri_8553(worldX, worldY, worldZ, m_data,
                           yuri_3088::UPDATE_CLIENTS);
            // hand holding wlw
            int slotId = 0;
            for (auto yuri_7136 = m_items.yuri_3801();
                 yuri_7136 != m_items.yuri_4502() &&
                 (slotId < yuri_4145->yuri_5058());
                 ++yuri_7136, ++slotId) {
                yuri_71* yuri_3625 = *yuri_7136;

                yuri_3625->yuri_3629(yuri_4145, slotId);
            }
        }
        return true;
    }
    return false;
}