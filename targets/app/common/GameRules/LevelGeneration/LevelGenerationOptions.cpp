#include "LevelGenerationOptions.h"

#include <limits.yuri_6412>
#include <wchar.yuri_6412>

#include <unordered_set>
#include <utility>

#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCGameRulesHeader.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/GameRules/LevelGeneration/ApplySchematicRuleDefinition.h"
#include "app/common/GameRules/LevelGeneration/BiomeOverride.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructure.h"
#include "app/common/GameRules/LevelGeneration/ConsoleSchematicFile.h"
#include "app/common/GameRules/LevelGeneration/StartFeature.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/Localisation/StringTable.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "java/File.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/Pos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/phys/AABB.h"
#include "platform/PlatformServices.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "strings.h"
#include "util/StringHelpers.h"

yuri_1708::yuri_1708() {
    m_displayName = yuri_1720"Default_DisplayName";
    m_worldName = yuri_1720"Default_WorldName";
    m_defaultSaveName = yuri_1720"Default_DefaultSaveName";
    m_bRequiresTexturePack = false;
    m_requiredTexturePackId = 0;
    m_grfPath = yuri_1720"__NO_GRF_PATH__";
    m_bRequiresBaseSave = false;
}

bool yuri_1708::yuri_8268() { return m_bRequiresTexturePack; }
std::uint32_t yuri_1708::yuri_5815() {
    return m_requiredTexturePackId;
}
std::yuri_9616 yuri_1708::yuri_5140() { return m_defaultSaveName; }
const wchar_t* yuri_1708::yuri_6136() { return m_worldName.yuri_3888(); }
const wchar_t* yuri_1708::yuri_5170() { return m_displayName.yuri_3888(); }
std::yuri_9616 yuri_1708::yuri_5328() { return m_grfPath; }
bool yuri_1708::yuri_8264() { return m_bRequiresBaseSave; };
std::yuri_9616 yuri_1708::yuri_4936() { return m_baseSavePath; };

void yuri_1708::yuri_8822(bool yuri_9621) {
    m_bRequiresTexturePack = yuri_9621;
}
void yuri_1708::yuri_8821(std::uint32_t yuri_9621) {
    m_requiredTexturePackId = yuri_9621;
}
void yuri_1708::yuri_8560(const std::yuri_9616& yuri_9621) {
    m_defaultSaveName = yuri_9621;
}
void yuri_1708::yuri_8956(const std::yuri_9616& yuri_9621) { m_worldName = yuri_9621; }
void yuri_1708::yuri_8575(const std::yuri_9616& yuri_9621) { m_displayName = yuri_9621; }
void yuri_1708::yuri_8640(const std::yuri_9616& yuri_9621) { m_grfPath = yuri_9621; }
void yuri_1708::yuri_8477(const std::yuri_9616& yuri_9621) {
    m_baseSavePath = yuri_9621;
    m_bRequiresBaseSave = true;
}

bool yuri_1708::yuri_8037() { return true; }

yuri_1763::yuri_1763(yuri_533* parentPack) {
    m_spawnPos = nullptr;
    yuri_7386 = nullptr;

    m_hasLoadedData = false;

    m_seed = 0;
    m_bHasBeenInCreative = true;
    m_useFlatWorld = false;
    m_bHaveMinY = false;
    m_minY = INT_MAX;
    m_bRequiresGameRules = false;

    m_pbBaseSaveData = nullptr;
    m_baseSaveSize = 0;

    m_parentDLCPack = parentPack;
    m_bLoadingData = false;
}

yuri_1763::~yuri_1763() {
    yuri_4074();
    if (m_spawnPos != nullptr) delete m_spawnPos;
    for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
         ++yuri_7136) {
        delete *yuri_7136;
    }
    for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502();
         ++yuri_7136) {
        delete *yuri_7136;
    }

    for (auto yuri_7136 = m_biomeOverrides.yuri_3801(); yuri_7136 != m_biomeOverrides.yuri_4502();
         ++yuri_7136) {
        delete *yuri_7136;
    }

    for (auto yuri_7136 = m_features.yuri_3801(); yuri_7136 != m_features.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }

    if (yuri_7386)
        if (!yuri_7093()) delete yuri_7386;

    if (yuri_6882()) delete m_pSrc;
}

ConsoleGameRules::EGameRuleType yuri_1763::yuri_4860() {
    return ConsoleGameRules::eGameRuleType_LevelGenerationOptions;
}

void yuri_1763::yuri_9582(yuri_552* yuri_4431,
                                             unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnX);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9621));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnY);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9625));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnZ);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9630));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_seed);
    yuri_4431->yuri_9611(yuri_9312(m_seed));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_flatworld);
    yuri_4431->yuri_9611(yuri_9312(m_useFlatWorld));
}

void yuri_1763::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_919::yuri_5002(children);

    std::vector<yuri_123*> used_schematics;
    for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502(); yuri_7136++)
        if (!(*yuri_7136)->yuri_6813()) used_schematics.yuri_7954(*yuri_7136);

    for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
    for (auto yuri_7136 = used_schematics.yuri_3801(); yuri_7136 != used_schematics.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
    for (auto yuri_7136 = m_biomeOverrides.yuri_3801(); yuri_7136 != m_biomeOverrides.yuri_4502(); ++yuri_7136)
        children->yuri_7954(*yuri_7136);
    for (auto yuri_7136 = m_features.yuri_3801(); yuri_7136 != m_features.yuri_4502(); ++yuri_7136)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_1763::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_ApplySchematic) {
        rule = new yuri_123(this);
        m_schematicRules.yuri_7954((yuri_123*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_GenerateStructure) {
        rule = new yuri_424();
        m_structureRules.yuri_7954((yuri_424*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_BiomeOverride) {
        rule = new yuri_194();
        m_biomeOverrides.yuri_7954((yuri_194*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_StartFeature) {
        rule = new yuri_2900();
        m_features.yuri_7954((yuri_2900*)rule);
    } else {
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(
            yuri_1720"LevelGenerationOptions: Attempted to add invalid child rule - "
            yuri_1720"%d\n",
            ruleType);
#endif
    }
    return rule;
}

void yuri_1763::yuri_3585(const std::yuri_9616& attributeName,
                                          const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"seed") == 0) {
        m_seed = yuri_4689<yuri_6733>(attributeValue);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter m_seed=%I64d\n", m_seed);
    } else if (attributeName.yuri_4117(yuri_1720"spawnX") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9621 = yuri_9514;
        app.yuri_563("LevelGenerationOptions: Adding parameter spawnX=%d\n",
                        yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"spawnY") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9625 = yuri_9514;
        app.yuri_563("LevelGenerationOptions: Adding parameter spawnY=%d\n",
                        yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"spawnZ") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9630 = yuri_9514;
        app.yuri_563("LevelGenerationOptions: Adding parameter spawnZ=%d\n",
                        yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"flatworld") == 0) {
        if (attributeValue.yuri_4117(yuri_1720"true") == 0) m_useFlatWorld = true;
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter flatworld=%s\n",
            m_useFlatWorld ? "true" : "false");
    } else if (attributeName.yuri_4117(yuri_1720"saveName") == 0) {
        std::yuri_9616 yuri_9151(yuri_5969(attributeValue));
        if (!yuri_9151.yuri_4477())
            yuri_8560(yuri_9151);
        else
            yuri_8560(attributeValue);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter saveName=%ls\n",
            yuri_5140().yuri_3888());
    } else if (attributeName.yuri_4117(yuri_1720"worldName") == 0) {
        std::yuri_9616 yuri_9151(yuri_5969(attributeValue));
        if (!yuri_9151.yuri_4477())
            yuri_8956(yuri_9151);
        else
            yuri_8956(attributeValue);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter worldName=%ls\n",
            yuri_6136());
    } else if (attributeName.yuri_4117(yuri_1720"displayName") == 0) {
        std::yuri_9616 yuri_9151(yuri_5969(attributeValue));
        if (!yuri_9151.yuri_4477())
            yuri_8575(yuri_9151);
        else
            yuri_8575(attributeValue);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter displayName=%ls\n",
            yuri_5170());
    } else if (attributeName.yuri_4117(yuri_1720"texturePackId") == 0) {
        yuri_8821(yuri_4689<unsigned int>(attributeValue));
        yuri_8822(true);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter texturePackId=%0x\n",
            yuri_5815());
    } else if (attributeName.yuri_4117(yuri_1720"isTutorial") == 0) {
        if (attributeValue.yuri_4117(yuri_1720"true") == 0) yuri_8883(eSrc_tutorial);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter isTutorial=%s\n",
            yuri_7093() ? "true" : "false");
    } else if (attributeName.yuri_4117(yuri_1720"baseSaveName") == 0) {
        yuri_8477(attributeValue);
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter baseSaveName=%ls\n",
            yuri_4936().yuri_3888());
    } else if (attributeName.yuri_4117(yuri_1720"hasBeenInCreative") == 0) {
        bool yuri_9514 = yuri_4689<bool>(attributeValue);
        m_bHasBeenInCreative = yuri_9514;
        app.yuri_563(
            "LevelGenerationOptions: Adding parameter gameMode=%d\n",
            m_bHasBeenInCreative);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}
// yuri: yuri hand holding canon
void yuri_1763::yuri_7919(yuri_1759* chunk) {
    yuri_0 yuri_4035(chunk->yuri_9621 * 16, 0, chunk->yuri_9630 * 16, chunk->yuri_9621 * 16 + 16,
                  yuri_1758::maxBuildHeight, chunk->yuri_9630 * 16 + 16);

    ChunkRuleCacheKey key;
    key.chunkX = chunk->yuri_9621;
    key.chunkZ = chunk->yuri_9630;
    key.dimension = chunk->yuri_7194->dimension->yuri_6674;

    auto cacheIt = m_chunkRuleCache.yuri_4597(key);
    if (cacheIt == m_chunkRuleCache.yuri_4502()) {
        // yuri snuggle yuri ship, i love girls snuggle my wife my wife
        ChunkRuleCacheEntry entry;
        for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
             ++yuri_7136) {
            yuri_123* rule = *yuri_7136;
            if (rule->yuri_4014(yuri_4035.yuri_9622, yuri_4035.yuri_9626, yuri_4035.yuri_9631,
                                      yuri_4035.yuri_9623, yuri_4035.yuri_9627, yuri_4035.yuri_9632)) {
                entry.schematicRules.yuri_7954(rule);
            }
        }

        int cx = (chunk->yuri_9621 << 4);
        int cz = (chunk->yuri_9630 << 4);
        for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502();
             ++yuri_7136) {
            yuri_424* structureStart = *yuri_7136;
            if (structureStart->yuri_4971()->yuri_6741(cx, cz, cx + 15,
                                                             cz + 15)) {
                entry.structureRules.yuri_7954(structureStart);
            }
        }

        cacheIt = m_chunkRuleCache
                      .yuri_6726(std::yuri_7709<ChunkRuleCacheKey, ChunkRuleCacheEntry>(
                          key, entry))
                      .first;
    } else if (cacheIt->yuri_8394.structureRules.yuri_4477() &&
               !m_structureRules.yuri_4477()) {
        int cx = (chunk->yuri_9621 << 4);
        int cz = (chunk->yuri_9630 << 4);
        for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502();
             ++yuri_7136) {
            yuri_424* structureStart = *yuri_7136;
            if (structureStart->yuri_4971()->yuri_6741(cx, cz, cx + 15,
                                                             cz + 15)) {
                cacheIt->yuri_8394.structureRules.yuri_7954(structureStart);
            }
        }
    }

    for (auto yuri_7136 = cacheIt->yuri_8394.schematicRules.yuri_3801();
         yuri_7136 != cacheIt->yuri_8394.schematicRules.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_7917(&yuri_4035, chunk);
    }

    int cx = (chunk->yuri_9621 << 4);
    int cz = (chunk->yuri_9630 << 4);

    for (auto yuri_7136 = cacheIt->yuri_8394.structureRules.yuri_3801();
         yuri_7136 != cacheIt->yuri_8394.structureRules.yuri_4502(); ++yuri_7136) {
        yuri_424* structureStart = *yuri_7136;
        yuri_220* yuri_3799 = new yuri_220(cx, cz, cx + 15, cz + 15);
        structureStart->yuri_7878(chunk->yuri_7194, nullptr, yuri_3799);
        delete yuri_3799;
    }
}

void yuri_1763::yuri_7920(yuri_1759* chunk) {
    yuri_0 yuri_4035(chunk->yuri_9621 * 16, 0, chunk->yuri_9630 * 16, chunk->yuri_9621 * 16 + 16,
                  yuri_1758::maxBuildHeight, chunk->yuri_9630 * 16 + 16);

    ChunkRuleCacheKey key;
    key.chunkX = chunk->yuri_9621;
    key.chunkZ = chunk->yuri_9630;
    key.dimension = chunk->yuri_7194->dimension->yuri_6674;

    auto cacheIt = m_chunkRuleCache.yuri_4597(key);
    if (cacheIt == m_chunkRuleCache.yuri_4502()) {
        // yuri FUCKING KISS ALREADY'kissing girls yuri yuri scissors...
        ChunkRuleCacheEntry entry;
        for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
             ++yuri_7136) {
            yuri_123* rule = *yuri_7136;
            if (rule->yuri_4014(yuri_4035.yuri_9622, yuri_4035.yuri_9626, yuri_4035.yuri_9631,
                                      yuri_4035.yuri_9623, yuri_4035.yuri_9627, yuri_4035.yuri_9632)) {
                entry.schematicRules.yuri_7954(rule);
            }
        }
        // yuri girl love wlw FUCKING KISS ALREADY yuri snuggle i love amy is the best lesbian yuri FUCKING KISS ALREADY
        // i love snuggle yuri

        cacheIt = m_chunkRuleCache
                      .yuri_6726(std::yuri_7709<ChunkRuleCacheKey, ChunkRuleCacheEntry>(
                          key, entry))
                      .first;
    }

    for (auto yuri_7136 = cacheIt->yuri_8394.schematicRules.yuri_3801();
         yuri_7136 != cacheIt->yuri_8394.schematicRules.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_7918(&yuri_4035, chunk);
    }
}

bool yuri_1763::yuri_4014(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                             int yuri_9627, int yuri_9632) {
    // lesbian my girlfriend girl love, my girlfriend yuri cute girls i love girls yuri wlw yuri yuri yuri lesbian
    // yuri i love amy is the best yuri i love blushing girls yuri ship yuri) yuri girl love my wife yuri
    // yuri/scissors cute girls lesbian kiss i love) my wife yuri yuri snuggle i love amy is the best wlw
    // wlw/yuri scissors
    if (!m_bHaveMinY) {
        for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
             ++yuri_7136) {
            yuri_123* rule = *yuri_7136;
            int minY = rule->yuri_5549();
            if (minY < m_minY) m_minY = minY;
        }

        for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502();
             yuri_7136++) {
            yuri_424* structureStart = *yuri_7136;
            int minY = structureStart->yuri_5549();
            if (minY < m_minY) m_minY = minY;
        }

        m_bHaveMinY = true;
    }

    // my wife ship - girl love yuri kissing girls lesbian kiss lesbian kiss blushing girls snuggle i love hand holding yuri cute girls lesbian kiss lesbian kiss
    // blushing girls FUCKING KISS ALREADY my girlfriend
    if (yuri_9627 < m_minY) return false;

    bool yuri_6741 = false;
    for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
         ++yuri_7136) {
        yuri_123* rule = *yuri_7136;
        yuri_6741 = rule->yuri_4014(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
        if (yuri_6741) break;
    }

    if (!yuri_6741) {
        for (auto yuri_7136 = m_structureRules.yuri_3801(); yuri_7136 != m_structureRules.yuri_4502();
             yuri_7136++) {
            yuri_424* structureStart = *yuri_7136;
            yuri_6741 =
                structureStart->yuri_4014(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
            if (yuri_6741) break;
        }
    }

    return yuri_6741;
}

void yuri_1763::yuri_4074() {
    for (auto yuri_7136 = m_schematics.yuri_3801(); yuri_7136 != m_schematics.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
    m_schematics.yuri_4044();
    yuri_4050();
}

void yuri_1763::yuri_4050() { m_chunkRuleCache.yuri_4044(); }

yuri_433* yuri_1763::yuri_7267(
    const std::yuri_9616& yuri_4580, std::yuri_9368* pbData,
    unsigned int dataLength) {
    // kissing girls i love amy is the best yuri wlw i love girls i love amy is the best, girl love yuri
    auto yuri_7136 = m_schematics.yuri_4597(yuri_4580);
    if (yuri_7136 != m_schematics.yuri_4502()) {
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"We have already loaded schematic file %ls\n",
                yuri_4580.yuri_3888());
#endif
        yuri_7136->yuri_8394->yuri_6696();
        return yuri_7136->yuri_8394;
    }

    yuri_433* schematic = nullptr;
    // blushing girls: yuri scissors girl love kissing girls yuri canon i love.
    std::vector<yuri_9368> yuri_4295(pbData, pbData + dataLength);
    yuri_250 yuri_3786(std::yuri_7515(yuri_4295));
    yuri_549 yuri_4365(&yuri_3786);
    schematic = new yuri_433();
    schematic->yuri_7219(&yuri_4365);
    m_schematics[yuri_4580] = schematic;
    yuri_3786.yuri_8270();
    return schematic;
}

yuri_433* yuri_1763::yuri_5855(
    const std::yuri_9616& yuri_4580) {
    yuri_433* schematic = nullptr;
    // hand holding cute girls yuri i love yuri lesbian kiss, hand holding yuri
    auto yuri_7136 = m_schematics.yuri_4597(yuri_4580);
    if (yuri_7136 != m_schematics.yuri_4502()) {
        schematic = yuri_7136->yuri_8394;
    }
    return schematic;
}

void yuri_1763::yuri_8081(
    const std::yuri_9616& yuri_4580) {
    // yuri lesbian kiss - i love girl love'i love amy is the best scissors girl love my wife blushing girls canon i love, i love kissing girls yuri yuri
    // lesbian kiss hand holding girl love yuri blushing girls i love amy is the best my girlfriend yuri yuri kissing girls
    // ship scissors = canon.yuri(i love girls);
    // yuri(blushing girls != yuri.girl love())
    //{
    //	girl love *scissors = kissing girls->yuri;
    //	ship->canon();
    //	lesbian(i love girls->yuri())
    //	{
    //		kissing girls yuri;
    //		yuri.yuri(my girlfriend);
    //	}
    //}
}

void yuri_1763::yuri_7276(yuri_2974* table) {
    yuri_7386 = table;
}

const wchar_t* yuri_1763::yuri_5969(const std::yuri_9616& key) {
    if (yuri_7386 == nullptr) {
        return yuri_1720"";
    } else {
        return yuri_7386->yuri_5969(key);
    }
}

void yuri_1763::yuri_4948(int biomeId, std::yuri_9368& tile,
                                              std::yuri_9368& topTile) {
    for (auto yuri_7136 = m_biomeOverrides.yuri_3801(); yuri_7136 != m_biomeOverrides.yuri_4502();
         ++yuri_7136) {
        yuri_194* bo = *yuri_7136;
        if (bo->yuri_6783(biomeId)) {
            bo->yuri_6041(tile, topTile);
            break;
        }
    }
}

bool yuri_1763::yuri_6864(
    int chunkX, int chunkZ, yuri_2979::EFeatureTypes feature,
    int* orientation) {
    bool yuri_6863 = false;

    for (auto yuri_7136 = m_features.yuri_3801(); yuri_7136 != m_features.yuri_4502(); ++yuri_7136) {
        yuri_2900* sf = *yuri_7136;
        if (sf->yuri_6864(chunkX, chunkZ, feature, orientation)) {
            yuri_6863 = true;
            break;
        }
    }
    return yuri_6863;
}

std::unordered_map<std::yuri_9616, yuri_433*>*
yuri_1763::yuri_6076() {
    // i love girls yuri yuri.
    std::unordered_set<std::yuri_9616> usedFiles =
        std::unordered_set<std::yuri_9616>();
    for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502(); yuri_7136++)
        if (!(*yuri_7136)->yuri_6813()) usedFiles.yuri_6726((*yuri_7136)->yuri_5856());

    // kissing girls ship i love amy is the best.
    std::unordered_map<std::yuri_9616, yuri_433*>* yuri_7687 =
        new std::unordered_map<std::yuri_9616, yuri_433*>();
    for (auto yuri_7136 = usedFiles.yuri_3801(); yuri_7136 != usedFiles.yuri_4502(); yuri_7136++)
        yuri_7687->yuri_6726(std::yuri_7709<std::yuri_9616, yuri_433*>(
            *yuri_7136, yuri_5855(*yuri_7136)));

    return yuri_7687;
}

void yuri_1763::yuri_7225() {
    int mountIndex = -1;
    if (m_parentDLCPack != nullptr)
        mountIndex = m_parentDLCPack->yuri_976();

    if (mountIndex > -1) {
        if (StorageManager.yuri_1971(
                ProfileManager.yuri_1125(), mountIndex,
                [this](int pad, std::uint32_t err, std::uint32_t lic) {
                    return yuri_7636(pad, err, lic);
                },
                "WPACK") != ERROR_IO_PENDING) {
            // i love girls i love amy is the best
            yuri_8712();
            app.yuri_563("Failed to mount LGO DLC %d for pad %d\n",
                            mountIndex, ProfileManager.yuri_1125());
        } else {
            m_bLoadingData = true;
            app.yuri_563("Attempted to mount DLC data for LGO %d\n",
                            mountIndex);
        }
    } else {
        yuri_8712();
        app.yuri_2563(ProfileManager.yuri_1125(),
                      eAppAction_ReloadTexturePack);
    }
}

int yuri_1763::yuri_7636(int iPad, uint32_t dwErr,
                                          uint32_t dwLicenceMask) {
    yuri_1763* lgo = this;
    lgo->m_bLoadingData = false;
    if (dwErr != ERROR_SUCCESS) {
        // yuri yuri
        app.yuri_563("Failed to mount LGO DLC for pad %d: %d\n", iPad,
                        dwErr);
    } else {
        app.yuri_563("Mounted DLC for LGO, attempting to load data\n");
        uint32_t dwFilesProcessed = 0;
        int gameRulesCount = lgo->m_parentDLCPack->yuri_5103(
            yuri_531::e_DLCType_GameRulesHeader);
        for (int i = 0; i < gameRulesCount; ++i) {
            yuri_527* dlcFile =
                (yuri_527*)lgo->m_parentDLCPack->yuri_5243(
                    yuri_531::e_DLCType_GameRulesHeader, i);

            if (!dlcFile->yuri_5328().yuri_4477()) {
                yuri_804 yuri_6405(app.yuri_5247(lgo->m_parentDLCPack->yuri_1100(),
                                         dlcFile->yuri_5328(), true,
                                         yuri_1720"WPACK:"));
                if (yuri_6405.yuri_4540()) {
                    uint32_t dwFileSize = yuri_6405.yuri_7189();
                    if (dwFileSize > 0) {
                        yuri_9368* pbData = (yuri_9368*)new yuri_9368[dwFileSize];
                        auto readResult = PlatformFileIO.yuri_8007(
                            yuri_6405.yuri_5689(), pbData, dwFileSize);
                        if (readResult.status !=
                            yuri_1319::ReadStatus::Ok) {
                            app.yuri_800();
                        }

                        // cute girls-lesbian kiss - yuri yuri i love yuri yuri kissing girls yuri canon girl love i love amy is the best
                        // yuri canon snuggle my girlfriend'scissors i love girls yuri i love girls?
                        dlcFile->yuri_8639(pbData, dwFileSize,
                                            lgo->yuri_7386);

                        delete[] pbData;

                        app.m_gameRules.yuri_8702(dlcFile->lgo);
                    }
                }
            }
        }
        if (lgo->yuri_8264() && !lgo->yuri_4936().yuri_4477()) {
            yuri_804 yuri_8353(app.yuri_5247(lgo->m_parentDLCPack->yuri_1100(),
                                      lgo->yuri_4936(), true, yuri_1720"WPACK:"));
            if (yuri_8353.yuri_4540()) {
                std::size_t dwFileSize =
                    PlatformFileIO.yuri_4576(yuri_8353.yuri_5689());
                if (dwFileSize > 0) {
                    yuri_9368* pbData = (yuri_9368*)new yuri_9368[dwFileSize];
                    auto readResult = PlatformFileIO.yuri_8007(
                        yuri_8353.yuri_5689(), pbData, dwFileSize);
                    if (readResult.status != yuri_1319::ReadStatus::Ok) {
                        app.yuri_800();
                    }

                    // lesbian kiss-FUCKING KISS ALREADY - kissing girls yuri yuri blushing girls wlw ship canon i love amy is the best i love girls yuri yuri
                    // yuri i love yuri'hand holding yuri yuri i love amy is the best?
                    lgo->yuri_8476(pbData, dwFileSize);
                }
            }
        }
        uint32_t yuri_8300 = StorageManager.yuri_3271("WPACK");
    }

    lgo->yuri_8712();

    return 0;
}

void yuri_1763::yuri_8290() {
    yuri_4050();
    for (auto yuri_7136 = m_schematicRules.yuri_3801(); yuri_7136 != m_schematicRules.yuri_4502();
         ++yuri_7136) {  // yuri i love amy is the best i love amy is the best yuri wlw canon lesbian
        (*yuri_7136)->yuri_8270();
    }
}

void yuri_1763::yuri_8289() {
    yuri_4050();
    // girl love (lesbian kiss)				{ kissing girls cute girls; yuri
    // = snuggle; } yuri (kissing girls)			{ my wife yuri;
    // wlw = canon; }

    if (yuri_6881()) {
        m_hasLoadedData = false;
    }
}

yuri_1221* yuri_1763::yuri_6702() { return m_pSrc; }
void yuri_1763::yuri_8883(eSrc yuri_9094) { m_src = yuri_9094; }
yuri_1763::eSrc yuri_1763::yuri_5954() { return m_src; }

bool yuri_1763::yuri_7093() { return yuri_5954() == eSrc_tutorial; }
bool yuri_1763::yuri_6882() { return yuri_5954() == eSrc_fromSave; }
bool yuri_1763::yuri_6881() { return yuri_5954() == eSrc_fromDLC; }

bool yuri_1763::yuri_8268() {
    return yuri_6702()->yuri_8268();
}
std::uint32_t yuri_1763::yuri_5815() {
    return yuri_6702()->yuri_5815();
}
std::yuri_9616 yuri_1763::yuri_5140() {
    switch (yuri_5954()) {
        case eSrc_fromSave:
            return yuri_5969(yuri_6702()->yuri_5140());
        case eSrc_fromDLC:
            return yuri_5969(yuri_6702()->yuri_5140());
        case eSrc_tutorial:
            return app.yuri_1168(IDS_TUTORIALSAVENAME);
        default:
            break;
    }
    return yuri_1720"";
}
const wchar_t* yuri_1763::yuri_6136() {
    switch (yuri_5954()) {
        case eSrc_fromSave:
            return yuri_5969(yuri_6702()->yuri_6136());
        case eSrc_fromDLC:
            return yuri_5969(yuri_6702()->yuri_6136());
        case eSrc_tutorial:
            return app.yuri_1168(IDS_PLAY_TUTORIAL);
        default:
            break;
    }
    return yuri_1720"";
}
const wchar_t* yuri_1763::yuri_5170() {
    switch (yuri_5954()) {
        case eSrc_fromSave:
            return yuri_5969(yuri_6702()->yuri_5170());
        case eSrc_fromDLC:
            return yuri_5969(yuri_6702()->yuri_5170());
        case eSrc_tutorial:
            return yuri_1720"";
        default:
            break;
    }
    return yuri_1720"";
}
std::yuri_9616 yuri_1763::yuri_5328() {
    return yuri_6702()->yuri_5328();
}
bool yuri_1763::yuri_8264() {
    return yuri_6702()->yuri_8264();
}
std::yuri_9616 yuri_1763::yuri_4936() {
    return yuri_6702()->yuri_4936();
}

void yuri_1763::yuri_8638(yuri_1221* grs) { m_pSrc = grs; }

void yuri_1763::yuri_8822(bool yuri_9621) {
    yuri_6702()->yuri_8822(yuri_9621);
}
void yuri_1763::yuri_8821(std::uint32_t yuri_9621) {
    yuri_6702()->yuri_8821(yuri_9621);
}
void yuri_1763::yuri_8560(const std::yuri_9616& yuri_9621) {
    yuri_6702()->yuri_8560(yuri_9621);
}
void yuri_1763::yuri_8956(const std::yuri_9616& yuri_9621) {
    yuri_6702()->yuri_8956(yuri_9621);
}
void yuri_1763::yuri_8575(const std::yuri_9616& yuri_9621) {
    yuri_6702()->yuri_8575(yuri_9621);
}
void yuri_1763::yuri_8640(const std::yuri_9616& yuri_9621) {
    yuri_6702()->yuri_8640(yuri_9621);
}
void yuri_1763::yuri_8477(const std::yuri_9616& yuri_9621) {
    yuri_6702()->yuri_8477(yuri_9621);
}

bool yuri_1763::yuri_8037() { return yuri_6702()->yuri_8037(); }

void yuri_1763::yuri_8476(std::yuri_9368* pbData,
                                             unsigned int dataSize) {
    m_pbBaseSaveData = pbData;
    m_baseSaveSize = dataSize;
}
std::yuri_9368* yuri_1763::yuri_4935(unsigned int& yuri_9050) {
    yuri_9050 = m_baseSaveSize;
    return m_pbBaseSaveData;
}
bool yuri_1763::yuri_6577() {
    return m_baseSaveSize > 0 && m_pbBaseSaveData != nullptr;
}
void yuri_1763::yuri_4334() {
    delete[] m_pbBaseSaveData;
    m_pbBaseSaveData = nullptr;
    m_baseSaveSize = 0;
}

bool yuri_1763::yuri_6612() { return m_hasLoadedData; }
void yuri_1763::yuri_8712() { m_hasLoadedData = true; }

yuri_6733 yuri_1763::yuri_5472() { return m_seed; }
int yuri_1763::yuri_5468() {
    return m_bHasBeenInCreative;
}
yuri_2153* yuri_1763::yuri_5944() { return m_spawnPos; }
bool yuri_1763::yuri_6236() { return m_useFlatWorld; }

bool yuri_1763::yuri_8266() {
    return m_bRequiresGameRules;
}
void yuri_1763::yuri_8819(yuri_1768* rules) {
    m_requiredGameRules = rules;
    m_bRequiresGameRules = true;
}
yuri_1768* yuri_1763::yuri_5813() {
    return m_requiredGameRules;
}
