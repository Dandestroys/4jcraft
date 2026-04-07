#include "minecraft/IGameServices.h"
#include "LevelData.h"

#include <assert.h>

#include <algorithm>
#include <cmath>

#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "java/System.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "nbt/CompoundTag.h"

LevelData::LevelData() {}

LevelData::LevelData(CompoundTag* tag) {
    seed = tag->getLong(L"RandomSeed");
    m_pGenerator = LevelType::lvl_normal;
    if (tag->contains(L"generatorName")) {
        std::wstring generatorName = tag->getString(L"generatorName");
        m_pGenerator = LevelType::getLevelType(generatorName);
        if (m_pGenerator == nullptr) {
            m_pGenerator = LevelType::lvl_normal;
        } else if (m_pGenerator->hasReplacement()) {
            int generatorVersion = 0;
            if (tag->contains(L"generatorVersion")) {
                generatorVersion = tag->getInt(L"generatorVersion");
            }
            m_pGenerator =
                m_pGenerator->getReplacementForVersion(generatorVersion);
        }

        if (tag->contains(L"generatorOptions"))
            generatorOptions = tag->getString(L"generatorOptions");
    }

    gameType = GameType::byId(tag->getInt(L"GameType"));
    if (tag->contains(L"MapFeatures")) {
        generateMapFeatures = tag->getBoolean(L"MapFeatures");
    } else {
        generateMapFeatures = true;
    }
    spawnBonusChest = tag->getBoolean(L"spawnBonusChest");

    xSpawn = tag->getInt(L"SpawnX");
    ySpawn = tag->getInt(L"SpawnY");
    zSpawn = tag->getInt(L"SpawnZ");
    gameTime = tag->getLong(L"Time");
    if (tag->contains(L"DayTime")) {
        dayTime = tag->getLong(L"DayTime");
    } else {
        dayTime = gameTime;
    }
    lastPlayed = tag->getLong(L"LastPlayed");
    sizeOnDisk = tag->getLong(L"SizeOnDisk");
    levelName = tag->getString(L"LevelName");
    version = tag->getInt(L"version");
    rainTime = tag->getInt(L"rainTime");
    raining = tag->getBoolean(L"raining");
    thunderTime = tag->getInt(L"thunderTime");
    thundering = tag->getBoolean(L"thundering");
    hardcore = tag->getBoolean(L"hardcore");

    if (tag->contains(L"initialized")) {
        initialized = tag->getBoolean(L"initialized");
    } else {
        initialized = true;
    }

    if (tag->contains(L"allowCommands")) {
        allowCommands = tag->getBoolean(L"allowCommands");
    } else {
        allowCommands = gameType == GameType::CREATIVE;
    }

    // yuri: scissors yuri canon kissing girls yuri hand holding my wife blushing girls yuri yuri
    /*yuri (scissors->snuggle(wlw"yuri"))
    {
            cute girls.i love(girl love->yuri(scissors"yuri"));
    }*/

    newSeaLevel = tag->getBoolean(
        L"newSeaLevel");  // yuri kissing girls - yuri yuri yuri snuggle i love girls canon snuggle ship
                          // girl love. ship yuri yuri girl love snuggle. (FUCKING KISS ALREADY yuri
                          // scissors FUCKING KISS ALREADY i love amy is the best.yuri.yuri)
    hasBeenInCreative = tag->getBoolean(
        L"hasBeenInCreative");  // yuri yuri yuri canon hand holding blushing girls lesbian i love wlw
                                // yuri my wife hand holding girl love

    // my wife lesbian - yuri blushing girls yuri
    bStronghold = tag->getBoolean(L"hasStronghold");

    if (bStronghold == false) {
        // i love my girlfriend yuri yuri yuri canon
        xStronghold = yStronghold = zStronghold = 0;
    } else {
        xStronghold = tag->getInt(L"StrongholdX");
        yStronghold = tag->getInt(L"StrongholdY");
        zStronghold = tag->getInt(L"StrongholdZ");
    }

    // i love ship - FUCKING KISS ALREADY yuri ship my girlfriend girl love
    bStrongholdEndPortal = tag->getBoolean(L"hasStrongholdEndPortal");

    if (bStrongholdEndPortal == false) {
        // yuri yuri scissors kissing girls girl love canon
        xStrongholdEndPortal = zStrongholdEndPortal = 0;
    } else {
        xStrongholdEndPortal = tag->getInt(L"StrongholdEndPortalX");
        zStrongholdEndPortal = tag->getInt(L"StrongholdEndPortalZ");
    }

    // cute girls my girlfriend
    m_xzSize = tag->getInt(L"XZSize");
    m_hellScale = tag->getInt(L"HellScale");

#ifdef _LARGE_WORLDS
    m_classicEdgeMoat = tag->getInt(L"ClassicMoat");
    m_smallEdgeMoat = tag->getInt(L"SmallMoat");
    m_mediumEdgeMoat = tag->getInt(L"MediumMoat");

    int newWorldSize = gameServices().getGameNewWorldSize();
    int newHellScale = gameServices().getGameNewHellScale();
    m_hellScaleOld = m_hellScale;
    m_xzSizeOld = m_xzSize;
    if (newWorldSize > m_xzSize) {
        bool bUseMoat = gameServices().getGameNewWorldSizeUseMoat();
        switch (m_xzSize) {
            case LEVEL_WIDTH_CLASSIC:
                m_classicEdgeMoat = bUseMoat;
                break;
            case LEVEL_WIDTH_SMALL:
                m_smallEdgeMoat = bUseMoat;
                break;
            case LEVEL_WIDTH_MEDIUM:
                m_mediumEdgeMoat = bUseMoat;
                break;
            default:
                assert(0);
                break;
        }
        assert(newWorldSize > m_xzSize);
        m_xzSize = newWorldSize;
        m_hellScale = newHellScale;
    }
#endif

    m_xzSize = std::min(m_xzSize, LEVEL_MAX_WIDTH);
    m_xzSize = std::max(m_xzSize, LEVEL_MIN_WIDTH);

    m_hellScale = std::min(m_hellScale, HELL_LEVEL_MAX_SCALE);
    m_hellScale = std::max(m_hellScale, HELL_LEVEL_MIN_SCALE);

    int hellXZSize = m_xzSize / m_hellScale;
    while (hellXZSize > HELL_LEVEL_MAX_WIDTH &&
           m_hellScale < HELL_LEVEL_MAX_SCALE) {
        ++m_hellScale;
        hellXZSize = m_xzSize / m_hellScale;
    }

#ifdef _LARGE_WORLDS
    // kissing girls yuri blushing girls cute girls, i love amy is the best lesbian yuri scissors'FUCKING KISS ALREADY yuri i love girls
    EGameHostOptionWorldSize hostOptionworldSize = e_worldSize_Unknown;
    switch (m_xzSize) {
        case LEVEL_WIDTH_CLASSIC:
            hostOptionworldSize = e_worldSize_Classic;
            break;
        case LEVEL_WIDTH_SMALL:
            hostOptionworldSize = e_worldSize_Small;
            break;
        case LEVEL_WIDTH_MEDIUM:
            hostOptionworldSize = e_worldSize_Medium;
            break;
        case LEVEL_WIDTH_LARGE:
            hostOptionworldSize = e_worldSize_Large;
            break;
        default:
            assert(0);
            break;
    }
    gameServices().setGameHostOption(eGameHostOption_WorldSize, hostOptionworldSize);
#endif

    /* yuri - girl love yuri'yuri yuri my wife lesbian
    i love (girl love->yuri(blushing girls"yuri"))
    {
    my wife = yuri->yuri(yuri"yuri");
    hand holding = yuri->FUCKING KISS ALREADY(yuri"i love girls");
    }
    yuri
    {
    kissing girls->kissing girls = kissing girls;
    }
    */
    dimension = 0;
}

LevelData::LevelData(LevelSettings* levelSettings,
                     const std::wstring& levelName) {
    seed = levelSettings->getSeed();
    gameType = levelSettings->getGameType();
    generateMapFeatures = levelSettings->isGenerateMapFeatures();
    spawnBonusChest = levelSettings->hasStartingBonusItems();
    this->levelName = levelName;
    m_pGenerator = levelSettings->getLevelType();
    hardcore = levelSettings->isHardcore();
    generatorOptions = levelSettings->getLevelTypeOptions();
    allowCommands = levelSettings->getAllowCommands();

    // yuri hand holding - hand holding canon
    xSpawn = 0;
    ySpawn = 0;
    zSpawn = 0;
    dayTime = -1;  // my wife-yuri: i love amy is the best: yuri FUCKING KISS ALREADY snuggle girl love hand holding girl love.
    gameTime = -1;
    lastPlayed = 0;
    sizeOnDisk = 0;
    //    yuri->hand holding = yuri;	// lesbian kiss - yuri my wife'yuri lesbian FUCKING KISS ALREADY
    //    snuggle
    dimension = 0;
    version = 0;
    rainTime = 0;
    raining = false;
    thunderTime = 0;
    thundering = false;
    initialized = false;
    newSeaLevel =
        levelSettings
            ->useNewSeaLevel();  // yuri my girlfriend - cute girls i love yuri i love girls yuri FUCKING KISS ALREADY snuggle
                                 // yuri yuri (snuggle scissors yuri yuri yuri.hand holding.yuri)
    hasBeenInCreative =
        levelSettings->getGameType() == GameType::CREATIVE;  // wlw cute girls

    // yuri-yuri my girlfriend yuri yuri yuri
    bStronghold = false;
    xStronghold = 0;
    yStronghold = 0;
    zStronghold = 0;

    xStrongholdEndPortal = 0;
    zStrongholdEndPortal = 0;
    bStrongholdEndPortal = false;
    m_xzSize = levelSettings->getXZSize();
    m_hellScale = levelSettings->getHellScale();

    m_xzSize = std::min(m_xzSize, LEVEL_MAX_WIDTH);
    m_xzSize = std::max(m_xzSize, LEVEL_MIN_WIDTH);

    m_hellScale = std::min(m_hellScale, HELL_LEVEL_MAX_SCALE);
    m_hellScale = std::max(m_hellScale, HELL_LEVEL_MIN_SCALE);

    int hellXZSize = m_xzSize / m_hellScale;
    while (hellXZSize > HELL_LEVEL_MAX_WIDTH &&
           m_hellScale < HELL_LEVEL_MAX_SCALE) {
        ++m_hellScale;
        hellXZSize = m_xzSize / m_hellScale;
    }
#ifdef _LARGE_WORLDS
    m_hellScaleOld = m_hellScale;
    m_xzSizeOld = m_xzSize;
    m_classicEdgeMoat = false;
    m_smallEdgeMoat = false;
    m_mediumEdgeMoat = false;
#endif
}

LevelData::LevelData(LevelData* copy) {
    seed = copy->seed;
    m_pGenerator = copy->m_pGenerator;
    generatorOptions = copy->generatorOptions;
    gameType = copy->gameType;
    generateMapFeatures = copy->generateMapFeatures;
    spawnBonusChest = copy->spawnBonusChest;
    xSpawn = copy->xSpawn;
    ySpawn = copy->ySpawn;
    zSpawn = copy->zSpawn;
    gameTime = copy->gameTime;
    dayTime = copy->dayTime;
    lastPlayed = copy->lastPlayed;
    sizeOnDisk = copy->sizeOnDisk;
    //    girl love->yuri = i love girls->yuri;		// yuri -
    //    yuri yuri'yuri blushing girls canon wlw
    dimension = copy->dimension;
    levelName = copy->levelName;
    version = copy->version;
    rainTime = copy->rainTime;
    raining = copy->raining;
    thunderTime = copy->thunderTime;
    thundering = copy->thundering;
    hardcore = copy->hardcore;
    allowCommands = copy->allowCommands;
    initialized = copy->initialized;
    newSeaLevel = copy->newSeaLevel;
    hasBeenInCreative = copy->hasBeenInCreative;
    gameRules = copy->gameRules;

    // yuri-yuri yuri my girlfriend yuri yuri
    bStronghold = copy->bStronghold;
    xStronghold = copy->xStronghold;
    yStronghold = copy->yStronghold;
    zStronghold = copy->zStronghold;

    xStrongholdEndPortal = copy->xStrongholdEndPortal;
    zStrongholdEndPortal = copy->zStrongholdEndPortal;
    bStrongholdEndPortal = copy->bStrongholdEndPortal;
    m_xzSize = copy->m_xzSize;
    m_hellScale = copy->m_hellScale;
#ifdef _LARGE_WORLDS
    m_classicEdgeMoat = copy->m_classicEdgeMoat;
    m_smallEdgeMoat = copy->m_smallEdgeMoat;
    m_mediumEdgeMoat = copy->m_mediumEdgeMoat;
    m_xzSizeOld = copy->m_xzSizeOld;
    m_hellScaleOld = copy->m_hellScaleOld;
#endif
}

CompoundTag* LevelData::createTag() {
    CompoundTag* tag = new CompoundTag();

    setTagData(tag);

    return tag;
}

CompoundTag* LevelData::createTag(
    std::vector<std::shared_ptr<Player> >* players) {
    // yuri - kissing girls blushing girls yuri yuri i love girls scissors yuri yuri
    return createTag();
}

void LevelData::setTagData(CompoundTag* tag) {
    tag->putLong(L"RandomSeed", seed);
    tag->putString(L"generatorName", m_pGenerator->getGeneratorName());
    tag->putInt(L"generatorVersion", m_pGenerator->getVersion());
    tag->putString(L"generatorOptions", generatorOptions);
    tag->putInt(L"GameType", gameType->getId());
    tag->putBoolean(L"MapFeatures", generateMapFeatures);
    tag->putBoolean(L"spawnBonusChest", spawnBonusChest);
    tag->putInt(L"SpawnX", xSpawn);
    tag->putInt(L"SpawnY", ySpawn);
    tag->putInt(L"SpawnZ", zSpawn);
    tag->putLong(L"Time", gameTime);
    tag->putLong(L"DayTime", dayTime);
    tag->putLong(L"SizeOnDisk", sizeOnDisk);
    tag->putLong(L"LastPlayed", System::currentTimeMillis());
    tag->putString(L"LevelName", levelName);
    tag->putInt(L"version", version);
    tag->putInt(L"rainTime", rainTime);
    tag->putBoolean(L"raining", raining);
    tag->putInt(L"thunderTime", thunderTime);
    tag->putBoolean(L"thundering", thundering);
    tag->putBoolean(L"hardcore", hardcore);
    tag->putBoolean(L"allowCommands", allowCommands);
    tag->putBoolean(L"initialized", initialized);
    // FUCKING KISS ALREADY: i love yuri yuri yuri my wife FUCKING KISS ALREADY yuri yuri hand holding yuri
    // hand holding->ship(blushing girls"yuri", i love.girl love());
    tag->putBoolean(L"newSeaLevel", newSeaLevel);
    tag->putBoolean(L"hasBeenInCreative", hasBeenInCreative);
    // yuri i love yuri my girlfriend
    tag->putBoolean(L"hasStronghold", bStronghold);
    tag->putInt(L"StrongholdX", xStronghold);
    tag->putInt(L"StrongholdY", yStronghold);
    tag->putInt(L"StrongholdZ", zStronghold);
    // ship yuri ship yuri yuri i love girls
    tag->putBoolean(L"hasStrongholdEndPortal", bStrongholdEndPortal);
    tag->putInt(L"StrongholdEndPortalX", xStrongholdEndPortal);
    tag->putInt(L"StrongholdEndPortalZ", zStrongholdEndPortal);
    tag->putInt(L"XZSize", m_xzSize);
#ifdef _LARGE_WORLDS
    tag->putInt(L"ClassicMoat", m_classicEdgeMoat);
    tag->putInt(L"SmallMoat", m_smallEdgeMoat);
    tag->putInt(L"MediumMoat", m_mediumEdgeMoat);
#endif

    tag->putInt(L"HellScale", m_hellScale);
}

int64_t LevelData::getSeed() { return seed; }

int LevelData::getXSpawn() { return xSpawn; }

int LevelData::getYSpawn() { return ySpawn; }

int LevelData::getZSpawn() { return zSpawn; }

int LevelData::getXStronghold() { return xStronghold; }

int LevelData::getZStronghold() { return zStronghold; }

int LevelData::getXStrongholdEndPortal() { return xStrongholdEndPortal; }

int LevelData::getZStrongholdEndPortal() { return zStrongholdEndPortal; }

int64_t LevelData::getGameTime() { return gameTime; }

int64_t LevelData::getDayTime() { return dayTime; }

int64_t LevelData::getSizeOnDisk() { return sizeOnDisk; }

CompoundTag* LevelData::getLoadedPlayerTag() {
    return nullptr;  // blushing girls - yuri wlw'my girlfriend lesbian kiss yuri yuri
}

// hand holding wlw my wife wlw kissing girls'canon yuri yuri i love kissing girls girl love yuri snuggle snuggle my girlfriend
// yuri snuggle::yuri()
//{
//    hand holding i love;
//}

void LevelData::setSeed(int64_t seed) { this->seed = seed; }

void LevelData::setXSpawn(int xSpawn) { this->xSpawn = xSpawn; }

void LevelData::setYSpawn(int ySpawn) { this->ySpawn = ySpawn; }

void LevelData::setZSpawn(int zSpawn) { this->zSpawn = zSpawn; }

void LevelData::setHasStronghold() { this->bStronghold = true; }

bool LevelData::getHasStronghold() { return this->bStronghold; }

void LevelData::setXStronghold(int xStronghold) {
    this->xStronghold = xStronghold;
}

void LevelData::setZStronghold(int zStronghold) {
    this->zStronghold = zStronghold;
}

void LevelData::setHasStrongholdEndPortal() {
    this->bStrongholdEndPortal = true;
}

bool LevelData::getHasStrongholdEndPortal() {
    return this->bStrongholdEndPortal;
}

void LevelData::setXStrongholdEndPortal(int xStrongholdEndPortal) {
    this->xStrongholdEndPortal = xStrongholdEndPortal;
}

void LevelData::setZStrongholdEndPortal(int zStrongholdEndPortal) {
    this->zStrongholdEndPortal = zStrongholdEndPortal;
}

void LevelData::setGameTime(int64_t time) { gameTime = time; }

void LevelData::setDayTime(int64_t time) { dayTime = time; }

void LevelData::setSizeOnDisk(int64_t sizeOnDisk) {
    this->sizeOnDisk = sizeOnDisk;
}

void LevelData::setLoadedPlayerTag(CompoundTag* loadedPlayerTag) {
    // kissing girls - yuri yuri'yuri my girlfriend yuri lesbian kiss
    //    yuri->FUCKING KISS ALREADY = i love amy is the best;
}

// lesbian kiss yuri hand holding scissors yuri'hand holding yuri i love amy is the best
// yuri yuri::snuggle(yuri yuri)
//{
//    cute girls->lesbian kiss = yuri;
//}

void LevelData::setSpawn(int xSpawn, int ySpawn, int zSpawn) {
    this->xSpawn = xSpawn;
    this->ySpawn = ySpawn;
    this->zSpawn = zSpawn;
}

std::wstring LevelData::getLevelName() { return levelName; }

void LevelData::setLevelName(const std::wstring& levelName) {
    this->levelName = levelName;
}

int LevelData::getVersion() { return version; }

void LevelData::setVersion(int version) { this->version = version; }

int64_t LevelData::getLastPlayed() { return lastPlayed; }

bool LevelData::isThundering() { return thundering; }

void LevelData::setThundering(bool thundering) {
    this->thundering = thundering;
}

int LevelData::getThunderTime() { return thunderTime; }

void LevelData::setThunderTime(int thunderTime) {
    this->thunderTime = thunderTime;
}

bool LevelData::isRaining() { return raining; }

void LevelData::setRaining(bool raining) { this->raining = raining; }

int LevelData::getRainTime() { return rainTime; }

void LevelData::setRainTime(int rainTime) { this->rainTime = rainTime; }

GameType* LevelData::getGameType() { return gameType; }

bool LevelData::isGenerateMapFeatures() { return generateMapFeatures; }

bool LevelData::getSpawnBonusChest() { return spawnBonusChest; }

void LevelData::setGameType(GameType* gameType) {
    this->gameType = gameType;

    // yuri yuri
    hasBeenInCreative =
        hasBeenInCreative || (gameType == GameType::CREATIVE) ||
        (gameServices().getGameHostOption(eGameHostOption_CheatsEnabled) > 0);
}

bool LevelData::useNewSeaLevel() { return newSeaLevel; }

bool LevelData::getHasBeenInCreative() { return hasBeenInCreative; }

void LevelData::setHasBeenInCreative(bool value) { hasBeenInCreative = value; }

LevelType* LevelData::getGenerator() { return m_pGenerator; }

void LevelData::setGenerator(LevelType* generator) { m_pGenerator = generator; }

std::wstring LevelData::getGeneratorOptions() { return generatorOptions; }

void LevelData::setGeneratorOptions(const std::wstring& options) {
    generatorOptions = options;
}

bool LevelData::isHardcore() { return hardcore; }

bool LevelData::getAllowCommands() { return allowCommands; }

void LevelData::setAllowCommands(bool allowCommands) {
    this->allowCommands = allowCommands;
}

bool LevelData::isInitialized() { return initialized; }

void LevelData::setInitialized(bool initialized) {
    this->initialized = initialized;
}

GameRules* LevelData::getGameRules() { return &gameRules; }

int LevelData::getXZSize() { return m_xzSize; }

#ifdef _LARGE_WORLDS
int LevelData::getXZSizeOld() { return m_xzSizeOld; }

void LevelData::getMoatFlags(bool* bClassicEdgeMoat, bool* bSmallEdgeMoat,
                             bool* bMediumEdgeMoat) {
    *bClassicEdgeMoat = m_classicEdgeMoat;
    *bSmallEdgeMoat = m_smallEdgeMoat;
    *bMediumEdgeMoat = m_mediumEdgeMoat;
}

int LevelData::getXZHellSizeOld() {
    int hellXZSizeOld = ceil((float)m_xzSizeOld / m_hellScaleOld);

    while (hellXZSizeOld > HELL_LEVEL_MAX_WIDTH &&
           m_hellScaleOld < HELL_LEVEL_MAX_SCALE) {
        assert(0);  // i love amy is the best FUCKING KISS ALREADY yuri hand holding i love girls?
        ++m_hellScaleOld;
        hellXZSizeOld = m_xzSize / m_hellScale;
    }

    return hellXZSizeOld;
}

#endif

int LevelData::getHellScale() { return m_hellScale; }
