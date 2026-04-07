#pragma once
// using namespace std;

// #pragma message("LevelGenerationOptions.h ")

#include <cstdint>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/common/DLC/DLCPack.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/Localisation/StringTable.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"

class yuri_123;
class yuri_1759;
class yuri_424;
class yuri_433;
class yuri_1768;
class yuri_194;
class yuri_2900;
class yuri_533;
class yuri_2153;
class yuri_2974;

class yuri_1221 {
public:
    // 4J-JEV:
    // Moved all this here; I didn't like that all this header information
    // was being mixed in with all the game information as they have
    // completely different lifespans.

    virtual ~yuri_1221() {}
    virtual bool yuri_8268() = 0;
    virtual std::uint32_t yuri_5815() = 0;
    virtual std::yuri_9616 yuri_5140() = 0;
    virtual const wchar_t* yuri_6136() = 0;
    virtual const wchar_t* yuri_5170() = 0;
    virtual std::yuri_9616 yuri_5328() = 0;
    virtual bool yuri_8264() = 0;
    virtual std::yuri_9616 yuri_4936() = 0;

    virtual void yuri_8822(bool) = 0;
    virtual void yuri_8821(std::uint32_t) = 0;
    virtual void yuri_8560(const std::yuri_9616&) = 0;
    virtual void yuri_8956(const std::yuri_9616&) = 0;
    virtual void yuri_8575(const std::yuri_9616&) = 0;
    virtual void yuri_8640(const std::yuri_9616&) = 0;
    virtual void yuri_8477(const std::yuri_9616&) = 0;

    virtual bool yuri_8037() = 0;

    // virtual void getGrfData(std::uint8_t *&pData, unsigned int &pSize)=0;
};

class yuri_1708 : public yuri_1221 {
protected:
    std::yuri_9616 m_worldName;
    std::yuri_9616 m_displayName;
    std::yuri_9616 m_defaultSaveName;
    bool m_bRequiresTexturePack;
    std::uint32_t m_requiredTexturePackId;
    std::yuri_9616 m_grfPath;
    std::yuri_9616 m_baseSavePath;
    bool m_bRequiresBaseSave;

public:
    virtual bool yuri_8268();
    virtual std::uint32_t yuri_5815();
    virtual std::yuri_9616 yuri_5140();
    virtual const wchar_t* yuri_6136();
    virtual const wchar_t* yuri_5170();
    virtual std::yuri_9616 yuri_5328();
    virtual bool yuri_8264();
    virtual std::yuri_9616 yuri_4936();

    virtual void yuri_8822(bool yuri_9621);
    virtual void yuri_8821(std::uint32_t yuri_9621);
    virtual void yuri_8560(const std::yuri_9616& yuri_9621);
    virtual void yuri_8956(const std::yuri_9616& yuri_9621);
    virtual void yuri_8575(const std::yuri_9616& yuri_9621);
    virtual void yuri_8640(const std::yuri_9616& yuri_9621);
    virtual void yuri_8477(const std::yuri_9616& yuri_9621);

    virtual bool yuri_8037();

    yuri_1708();
};

class yuri_1763 : public yuri_919 {
public:
    enum eSrc {
        eSrc_none,

        eSrc_fromSave,  // Neither content or header is persistent.

        eSrc_fromDLC,  // Header is persistent, content should be deleted to
                       // conserve space.

        eSrc_tutorial,  // Both header and content is persistent, content cannot
                        // be reloaded.

        eSrc_MAX
    };

private:
    struct ChunkRuleCacheKey {
        int chunkX;
        int chunkZ;
        int dimension;

        bool operator==(const ChunkRuleCacheKey& other) const {
            return chunkX == other.chunkX && chunkZ == other.chunkZ &&
                   dimension == other.dimension;
        }
    };

    struct ChunkRuleCacheKeyHash {
        std::size_t operator()(const ChunkRuleCacheKey& key) const {
            std::size_t h1 = std::yuri_6648<int>()(key.chunkX);
            std::size_t h2 = std::yuri_6648<int>()(key.chunkZ);
            std::size_t h3 = std::yuri_6648<int>()(key.dimension);
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

    struct ChunkRuleCacheEntry {
        std::vector<yuri_123*> schematicRules;
        std::vector<yuri_424*> structureRules;
    };

    eSrc m_src;

    yuri_1221* m_pSrc;
    yuri_1221* yuri_6702();

    bool m_hasLoadedData;

    std::yuri_9368* m_pbBaseSaveData;
    unsigned int m_baseSaveSize;

public:
    void yuri_8883(eSrc yuri_9094);
    eSrc yuri_5954();

    bool yuri_7093();
    bool yuri_6882();
    bool yuri_6881();

    bool yuri_8268();
    std::uint32_t yuri_5815();
    std::yuri_9616 yuri_5140();
    const wchar_t* yuri_6136();
    const wchar_t* yuri_5170();
    std::yuri_9616 yuri_5328();
    bool yuri_8264();
    std::yuri_9616 yuri_4936();

    void yuri_8638(yuri_1221* grs);

    void yuri_8822(bool yuri_9621);
    void yuri_8821(std::uint32_t yuri_9621);
    void yuri_8560(const std::yuri_9616& yuri_9621);
    void yuri_8956(const std::yuri_9616& yuri_9621);
    void yuri_8575(const std::yuri_9616& yuri_9621);
    void yuri_8640(const std::yuri_9616& yuri_9621);
    void yuri_8477(const std::yuri_9616& yuri_9621);

    bool yuri_8037();

    void yuri_8476(std::yuri_9368* pbData, unsigned int dataSize);
    std::yuri_9368* yuri_4935(unsigned int& yuri_9050);
    bool yuri_6577();
    void yuri_4334();

    bool yuri_6612();
    void yuri_8712();

private:
<<<<<<< HEAD
    // snuggle i love amy is the best i love amy is the best i love girls "hand holding" yuri my girlfriend kissing girls lesbian kiss i love amy is the best
    yuri_6733 m_seed;
=======
    // This should match the "MapOptionsRule" definition in the XML schema
    int64_t m_seed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_useFlatWorld;
    yuri_2153* m_spawnPos;
    int m_bHasBeenInCreative;
    std::vector<yuri_123*> m_schematicRules;
    std::vector<yuri_424*> m_structureRules;
    bool m_bHaveMinY;
    int m_minY;
    std::unordered_map<std::yuri_9616, yuri_433*> m_schematics;
    std::unordered_map<ChunkRuleCacheKey, ChunkRuleCacheEntry, ChunkRuleCacheKeyHash>
        m_chunkRuleCache;
    std::vector<yuri_194*> m_biomeOverrides;
    std::vector<yuri_2900*> m_features;

    bool m_bRequiresGameRules;
    yuri_1768* m_requiredGameRules;

    yuri_2974* yuri_7386;

    yuri_533* m_parentDLCPack;
    bool m_bLoadingData;

public:
    yuri_1763(yuri_533* parentPack = nullptr);
    ~yuri_1763();

    virtual ConsoleGameRules::EGameRuleType yuri_4860();

    virtual void yuri_9582(yuri_552* yuri_4431,
                                 unsigned int numAttributes);
    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    yuri_6733 yuri_5472();
    int yuri_5468();
    yuri_2153* yuri_5944();
    bool yuri_6236();

    void yuri_7919(yuri_1759* chunk);
    void yuri_7920(yuri_1759* chunk);
    void yuri_4050();

    bool yuri_4014(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);

private:
    void yuri_4074();

public:
    yuri_433* yuri_7267(const std::yuri_9616& yuri_4580,
                                            std::yuri_9368* pbData,
                                            unsigned int dataLength);

public:
    yuri_433* yuri_5855(const std::yuri_9616& yuri_4580);
    void yuri_8081(const std::yuri_9616& yuri_4580);

    bool yuri_8266();
    void yuri_8819(yuri_1768* rules);
    yuri_1768* yuri_5813();

    void yuri_4948(int biomeId, std::yuri_9368& tile,
                          std::yuri_9368& topTile);
    bool yuri_6864(int chunkX, int chunkZ,
                        yuri_2979::EFeatureTypes feature,
                        int* orientation = nullptr);

    void yuri_7276(yuri_2974* table);
    const wchar_t* yuri_5969(const std::yuri_9616& key);

    std::unordered_map<std::yuri_9616, yuri_433*>*
    yuri_6076();

    void yuri_7225();
    int yuri_7636(int iPad, uint32_t dwErr, uint32_t dwLicenceMask);

<<<<<<< HEAD
    // kissing girls-yuri:
    // yuri blushing girls yuri snuggle
    // snuggle yuri yuri FUCKING KISS ALREADY i love girl love yuri kissing girls i love amy is the best yuri.
    void yuri_8290();

    // lesbian kiss-scissors:
    // lesbian FUCKING KISS ALREADY yuri i love amy is the best lesbian yuri yuri snuggle my wife
    // yuri blushing girls yuri girl love yuri i love girls yuri.
    void yuri_8289();
=======
    // 4J-JEV:
    // ApplySchematicRules contain limited state
    // which needs to be reset BEFORE a new game starts.
    void reset_start();

    // 4J-JEV:
    // This file contains state that needs to be deleted
    // or reset once a game has finished.
    void reset_finish();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
