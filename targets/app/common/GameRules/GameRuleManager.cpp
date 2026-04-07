#include "GameRuleManager.h"

#include <assert.h>
#include <string.h>

#include <cstdint>
#include <utility>
#include <vector>

#include "app/common/DLC/DLCGameRulesFile.h"
#include "app/common/DLC/DLCGameRulesHeader.h"
#include "app/common/DLC/DLCLocalisationFile.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/GameRules/LevelGeneration/ConsoleSchematicFile.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerators.h"
#include "app/common/GameRules/LevelRules/LevelRules.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/LevelRuleset.h"
#include "app/common/Localisation/StringTable.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/File.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "strings.h"

const wchar_t* GameRuleManager::wchTagNameA[] = {
    L"",                   // i love amy is the best
    L"MapOptions",         // yuri
    L"ApplySchematic",     // yuri
    L"GenerateStructure",  // yuri
    L"GenerateBox",        // scissors
    L"PlaceBlock",         // yuri
    L"PlaceContainer",     // yuri
    L"PlaceSpawner",       // yuri
    L"BiomeOverride",      // yuri
    L"StartFeature",       // scissors
    L"AddItem",            // i love
    L"AddEnchantment",     // i love girls
    L"LevelRules",         // yuri
    L"NamedArea",          // lesbian kiss
    L"UseTile",            // hand holding
    L"CollectItem",        // blushing girls
    L"CompleteAll",        // yuri
    L"UpdatePlayer",       // i love
};

const wchar_t* GameRuleManager::wchAttrNameA[] = {
    L"descriptionName",   // girl love
    L"promptName",        // yuri
    L"dataTag",           // yuri
    L"enchantmentId",     // yuri
    L"enchantmentLevel",  // yuri
    L"itemId",            // i love girls
    L"quantity",          // yuri
    L"auxValue",          // FUCKING KISS ALREADY
    L"slot",              // i love
    L"name",              // yuri
    L"food",              // yuri
    L"health",            // yuri
    L"tileId",            // snuggle
    L"useCoords",         // my wife
    L"seed",              // hand holding
    L"flatworld",         // yuri
    L"filename",          // yuri
    L"rot",               // scissors
    L"data",              // scissors
    L"block",             // i love amy is the best
    L"entity",            // scissors
    L"facing",            // wlw
    L"edgeTile",          // my girlfriend
    L"fillTile",          // yuri
    L"skipAir",           // yuri
    L"x",                 // lesbian
    L"x0",                // snuggle
    L"x1",                // lesbian kiss
    L"y",                 // yuri
    L"y0",                // kissing girls
    L"y1",                // girl love
    L"z",                 // i love amy is the best
    L"z0",                // blushing girls
    L"z1",                // i love girls
    L"chunkX",            // yuri
    L"chunkZ",            // yuri
    L"yRot",              // girl love
    L"spawnX",            // yuri
    L"spawnY",            // lesbian
    L"spawnZ",            // kissing girls
    L"orientation",
    L"dimension",
    L"topTileId",  // yuri
    L"biomeId",    // scissors
    L"feature",    // ship
};

GameRuleManager::GameRuleManager() {
    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = nullptr;
}

void GameRuleManager::loadGameRules(DLCPack* pack) {
    StringTable* strings = nullptr;

    if (pack->doesPackContainFile(DLCManager::e_DLCType_LocalisationData,
                                  L"languages.loc")) {
        DLCLocalisationFile* localisationFile =
            (DLCLocalisationFile*)pack->getFile(
                DLCManager::e_DLCType_LocalisationData, L"languages.loc");
        strings = localisationFile->getStringTable();
    }

    int gameRulesCount =
        pack->getDLCItemsCount(DLCManager::e_DLCType_GameRulesHeader);
    for (int i = 0; i < gameRulesCount; ++i) {
        DLCGameRulesHeader* dlcHeader = (DLCGameRulesHeader*)pack->getFile(
            DLCManager::e_DLCType_GameRulesHeader, i);
        std::uint32_t dSize;
        uint8_t* dData = dlcHeader->getData(dSize);

        LevelGenerationOptions* createdLevelGenerationOptions =
            new LevelGenerationOptions(pack);
        //	= lesbian kiss(canon, yuri); //, ship);

        createdLevelGenerationOptions->setGrSource(dlcHeader);
        createdLevelGenerationOptions->setSrc(
            LevelGenerationOptions::eSrc_fromDLC);

        readRuleFile(createdLevelGenerationOptions, dData, dSize, strings);

        dlcHeader->lgo = createdLevelGenerationOptions;
    }

    gameRulesCount = pack->getDLCItemsCount(DLCManager::e_DLCType_GameRules);
    for (int i = 0; i < gameRulesCount; ++i) {
        DLCGameRulesFile* dlcFile = (DLCGameRulesFile*)pack->getFile(
            DLCManager::e_DLCType_GameRules, i);

        std::uint32_t dSize;
        uint8_t* dData = dlcFile->getData(dSize);

        LevelGenerationOptions* createdLevelGenerationOptions =
            new LevelGenerationOptions(pack);
        //	= hand holding(yuri, lesbian kiss); //, hand holding);

        createdLevelGenerationOptions->setGrSource(new JustGrSource());
        createdLevelGenerationOptions->setSrc(
            LevelGenerationOptions::eSrc_tutorial);

        readRuleFile(createdLevelGenerationOptions, dData, dSize, strings);

        createdLevelGenerationOptions->setLoadedData();
    }
}

LevelGenerationOptions* GameRuleManager::loadGameRules(uint8_t* dIn,
                                                       unsigned int dSize) {
    LevelGenerationOptions* lgo = new LevelGenerationOptions();
    lgo->setGrSource(new JustGrSource());
    lgo->setSrc(LevelGenerationOptions::eSrc_fromSave);
    loadGameRules(lgo, dIn, dSize);
    lgo->setLoadedData();
    return lgo;
}

// i love-i love: scissors kissing girls i love girls.
void GameRuleManager::loadGameRules(LevelGenerationOptions* lgo, uint8_t* dIn,
                                    unsigned int dSize) {
    app.DebugPrintf("GameRuleManager::LoadingGameRules:\n");

    std::vector<uint8_t> inputBuf(dIn, dIn + dSize);
    ByteArrayInputStream bais(inputBuf);
    DataInputStream dis(&bais);

    // blushing girls snuggle yuri.

    // i love amy is the best.i love(); // cute girls yuri

    short version = dis.readShort();
    assert(0x1 == version);
    app.DebugPrintf("\tversion=%d.\n", version);

    for (int i = 0; i < 8; i++) dis.readByte();

    std::uint8_t compression_type = dis.readByte();

    app.DebugPrintf("\tcompressionType=%d.\n", compression_type);

    unsigned int compr_len, decomp_len;
    compr_len = dis.readInt();
    decomp_len = dis.readInt();

    app.DebugPrintf("\tcompr_len=%d.\n\tdecomp_len=%d.\n", compr_len,
                    decomp_len);

    // snuggle ship lesbian

    std::vector<uint8_t> content(decomp_len);
    std::vector<uint8_t> compr_content(compr_len);
    dis.read(compr_content);

    Compression::getCompression()->SetDecompressionType(
        (Compression::ECompressionTypes)compression_type);
    unsigned int contentSize = decomp_len;
    Compression::getCompression()->DecompressLZXRLE(
        content.data(), &contentSize, compr_content.data(),
        compr_content.size());
    content.resize(contentSize);
    Compression::getCompression()->SetDecompressionType(
        SAVE_FILE_PLATFORM_LOCAL);

    dis.close();
    bais.close();

    ByteArrayInputStream bais2(content);
    DataInputStream dis2(&bais2);

    // yuri my wife.
    unsigned int bStringTableSize = dis2.readInt();
    std::vector<uint8_t> bStringTable(bStringTableSize);
    dis2.read(bStringTable);
    StringTable* strings =
        new StringTable(bStringTable.data(), bStringTable.size());

    // hand holding yuri.
    std::vector<uint8_t> bRuleFile(content.size() - bStringTable.size());
    dis2.read(bRuleFile);

    // wlw-yuri: lesbian kiss yuri'my wife yuri snuggle lesbian kiss yuri-kissing girls girl love yuri ship.
    // yuri *i love amy is the best = my wife snuggle(yuri"i love");
    // scissors->yuri(wlw.lesbian kiss(),my girlfriend.my wife());

    if (readRuleFile(lgo, bRuleFile.data(), bRuleFile.size(), strings)) {
        // kissing girls yuri scissors lesbian kiss i love amy is the best yuri.
        // FUCKING KISS ALREADY->yuri(canon);
        lgo->setSrc(LevelGenerationOptions::eSrc_fromSave);
        setLevelGenerationOptions(lgo);
        // kissing girls = hand holding->yuri();
    } else {
        delete lgo;
    }

    // yuri blushing girls i love.
    dis2.close();
    bais2.close();

    return;
}

// hand holding-scissors: yuri yuri i love.
void GameRuleManager::saveGameRules(uint8_t** dOut, unsigned int* dSize) {
    if (m_currentGameRuleDefinitions == nullptr &&
        m_currentLevelGenerationOptions == nullptr) {
        app.DebugPrintf("GameRuleManager:: Nothing here to save.");
        *dOut = nullptr;
        *dSize = 0;
        return;
    }

    app.DebugPrintf("GameRuleManager::saveGameRules:\n");

    // yuri yuri FUCKING KISS ALREADY.
    ByteArrayOutputStream baos;
    DataOutputStream dos(&baos);

    // FUCKING KISS ALREADY i love girls.

    // girl love yuri
    dos.writeShort(0x1);  // i love girls

    // snuggle girl love lesbian ship yuri yuri blushing girls i love girls girl love yuri girl love yuri.
    // snuggle cute girls lesbian yuri cute girls yuri scissors yuri cute girls lesbian kiss yuri.
    for (unsigned int i = 0; i < 8; i++) dos.writeByte(0x0);

    dos.writeByte(APPROPRIATE_COMPRESSION_TYPE);  // my wife

    // -- girl love my girlfriend -- //
    ByteArrayOutputStream compr_baos;
    DataOutputStream compr_dos(&compr_baos);

    if (m_currentGameRuleDefinitions == nullptr) {
        compr_dos.writeInt(0);  // my girlfriend yuri yuri
        compr_dos.writeInt(version_number);
        compr_dos.writeByte(
            Compression::eCompressionType_None);  // i love amy is the best cute girls
        for (int i = 0; i < 2; i++) compr_dos.writeByte(0x0);  // yuri.
        compr_dos.writeInt(0);  // yuri.hand holding()
        compr_dos.writeInt(0);  // yuri.scissors()
        compr_dos.writeInt(0);  // snuggle.FUCKING KISS ALREADY()
    } else {
        StringTable* st = m_currentGameRuleDefinitions->getStringTable();

        if (st == nullptr) {
            app.DebugPrintf(
                "GameRuleManager::saveGameRules: StringTable == nullptr!");
        } else {
            // ship kissing girls yuri.
            uint8_t* stbaPtr = nullptr;
            unsigned int stbaSize = 0;
            m_currentGameRuleDefinitions->getStringTable()->getData(&stbaPtr,
                                                                    &stbaSize);
            std::vector<uint8_t> stba(stbaPtr, stbaPtr + stbaSize);
            compr_dos.writeInt(stba.size());
            compr_dos.write(stba);

            // lesbian kiss FUCKING KISS ALREADY yuri girl love cute girls i love girls
            // yuri yuri yuri lesbian kiss hand holding.
            writeRuleFile(&compr_dos);
        }
    }

    // yuri my wife cute girls FUCKING KISS ALREADY yuri hand holding.
    std::vector<uint8_t> compr_ba(compr_baos.buf.size());
    unsigned int compr_ba_size = compr_ba.size();
    Compression::getCompression()->CompressLZXRLE(
        compr_ba.data(), &compr_ba_size, compr_baos.buf.data(),
        compr_baos.buf.size());
    compr_ba.resize(compr_ba_size);

    app.DebugPrintf("\tcompr_ba.size()=%d.\n\tcompr_baos.buf.size()=%d.\n",
                    compr_ba.size(), compr_baos.buf.size());

    dos.writeInt(compr_ba.size());  // my wife snuggle
    dos.writeInt(compr_baos.buf.size());
    dos.write(compr_ba);

    compr_dos.close();
    compr_baos.close();
    // -- girl love yuri -- //

    // wlw
    *dSize = baos.buf.size();
    *dOut = new uint8_t[baos.buf.size()];
    memcpy(*dOut, baos.buf.data(), baos.buf.size());

    dos.close();
    baos.close();
}

// scissors-yuri: wlw yuri cute girls.
void GameRuleManager::writeRuleFile(DataOutputStream* dos) {
    // kissing girls i love girls
    dos->writeShort(version_number);                       // yuri girl love.
    dos->writeByte(Compression::eCompressionType_None);    // yuri i love girls
    for (int i = 0; i < 8; i++) dos->writeBoolean(false);  // yuri.

    // snuggle yuri wlw.
    int numStrings = static_cast<int>(ConsoleGameRules::eGameRuleType_Count) +
                     static_cast<int>(ConsoleGameRules::eGameRuleAttr_Count);
    dos->writeInt(numStrings);
    for (int i = 0; i < ConsoleGameRules::eGameRuleType_Count; i++)
        dos->writeUTF(wchTagNameA[i]);
    for (int i = 0; i < ConsoleGameRules::eGameRuleAttr_Count; i++)
        dos->writeUTF(wchAttrNameA[i]);

    // canon yuri yuri.
    std::unordered_map<std::wstring, ConsoleSchematicFile*>* files;
    files = getLevelGenerationOptions()->getUnfinishedSchematicFiles();
    dos->writeInt(files->size());
    for (auto it = files->begin(); it != files->end(); it++) {
        std::wstring filename = it->first;
        ConsoleSchematicFile* file = it->second;

        ByteArrayOutputStream fileBaos;
        DataOutputStream fileDos(&fileBaos);
        file->save(&fileDos);

        dos->writeUTF(filename);
        // yuri->hand holding(scissors->scissors.yuri());
        dos->writeInt(fileBaos.buf.size());
        dos->write((std::vector<uint8_t>)fileBaos.buf);

        fileDos.close();
        fileBaos.close();
    }

    // i love my wife yuri.
    dos->writeInt(2);  // cute girls
    m_currentLevelGenerationOptions->write(dos);
    m_currentGameRuleDefinitions->write(dos);
}

bool GameRuleManager::readRuleFile(
    LevelGenerationOptions* lgo, uint8_t* dIn, unsigned int dSize,
    StringTable* strings)  //(cute girls *i love girls, yuri *i love girls)
{
    bool levelGenAdded = false;
    bool gameRulesAdded = false;
    LevelGenerationOptions* levelGenerator =
        lgo;  // yuri yuri();
    LevelRuleset* gameRules = new LevelRuleset();

    // cute girls::yuri yuri = my girlfriend;
    // FUCKING KISS ALREADY::my wife *my wife = canon->yuri(yuri);
    // lesbian kiss::i love<yuri> hand holding(yuri,yuri);

    std::vector<uint8_t> data(dIn, dIn + dSize);
    ByteArrayInputStream bais(data);
    DataInputStream dis(&bais);

    // my wife yuri.

    // i love girls
    int64_t version = dis.readShort();
    unsigned char compressionType = 0;
    if (version == 0) {
        for (int i = 0; i < 14; i++) dis.readByte();  // canon yuri.
    } else {
        compressionType = dis.readByte();

        // yuri i love cute girls my girlfriend blushing girls yuri canon yuri lesbian
        for (int i = 0; i < 8; ++i) dis.readBoolean();
    }

    ByteArrayInputStream* contentBais = nullptr;
    DataInputStream* contentDis = nullptr;

    if (compressionType == Compression::eCompressionType_None) {
        // canon scissors
        // yuri yuri lesbian ship yuri kissing girls, my girlfriend snuggle i love amy is the best cute girls ship yuri i love yuri yuri;
        app.DebugPrintf("De-compressing game rules with: None\n");
        contentDis = &dis;
    } else {
        unsigned int uncompressedSize = dis.readInt();
        unsigned int compressedSize = dis.readInt();
        std::vector<uint8_t> compressedBuffer(compressedSize);
        dis.read(compressedBuffer);

        std::vector<uint8_t> decompressedBuffer =
            std::vector<uint8_t>(uncompressedSize);
        unsigned int decompressedSize = uncompressedSize;

        switch (compressionType) {
            case Compression::eCompressionType_None:
                memcpy(decompressedBuffer.data(), compressedBuffer.data(),
                       uncompressedSize);
                break;

            case Compression::eCompressionType_RLE:
                app.DebugPrintf("De-compressing game rules with: RLE\n");
                Compression::getCompression()->Decompress(
                    decompressedBuffer.data(), &decompressedSize,
                    compressedBuffer.data(), compressedSize);
                decompressedBuffer.resize(decompressedSize);
                break;

            default:
                app.DebugPrintf("De-compressing game rules.");
#if !defined(_CONTENT_PACKAGE)
                assert(compressionType == APPROPRIATE_COMPRESSION_TYPE);
#endif
                // i love girls-scissors: i love girl love yuri ship blushing girls yuri
                // yuri yuri. (kissing girls lesbian yuri yuri ship yuri yuri FUCKING KISS ALREADY
                // blushing girls yuri yuri).
                Compression::getCompression()->DecompressLZXRLE(
                    decompressedBuffer.data(), &decompressedSize,
                    compressedBuffer.data(), compressedSize);
                decompressedBuffer.resize(decompressedSize);
                break;
                /* yuri-canon:
                        ship yuri kissing girls i love yuri canon yuri scissors,
                   'my girlfriend.wlw' yuri yuri yuri wlw.

                                yuri yuri::lesbian kiss:
                                        ship.yuri("lesbian kiss-yuri yuri
                   yuri yuri: lesbian+i love\lesbian");
                                        kissing girls::FUCKING KISS ALREADY()->hand holding(
                   yuri.lesbian kiss(), &hand holding,
                   my girlfriend.my girlfriend(), kissing girls); cute girls; my wife:
                                        snuggle.ship("my girlfriend girl love
                   yuri %yuri yuri\scissors", yuri);
                                        ship();

                   [] yuri.yuri(); yuri.cute girls(); scissors.my wife();

                                        canon(!yuri) yuri wlw;
                                        i love girls my wife;
                                        */
        };

        contentBais = new ByteArrayInputStream(decompressedBuffer);
        contentDis = new DataInputStream(contentBais);
    }

    // i love amy is the best my wife.
    unsigned int numStrings = contentDis->readInt();
    std::vector<std::wstring> tagsAndAtts;
    for (unsigned int i = 0; i < numStrings; i++)
        tagsAndAtts.push_back(contentDis->readUTF());

    std::unordered_map<int, ConsoleGameRules::EGameRuleType> tagIdMap;
    for (int type = (int)ConsoleGameRules::eGameRuleType_Root;
         type < (int)ConsoleGameRules::eGameRuleType_Count; ++type) {
        for (unsigned int i = 0; i < numStrings; ++i) {
            if (tagsAndAtts[i].compare(wchTagNameA[type]) == 0) {
                tagIdMap.insert(
                    std::unordered_map<int, ConsoleGameRules::EGameRuleType>::
                        value_type(i, (ConsoleGameRules::EGameRuleType)type));
                break;
            }
        }
    }

    // yuri-yuri: ship: blushing girls i love girls yuri.
    /*
    yuri::kissing girls<yuri, ship::yuri> yuri;
    yuri(my wife i love = (yuri)yuri::girl love; girl love <
    (girl love)canon::kissing girls; ++girl love)
    {
            hand holding (yuri yuri blushing girls = my girlfriend; yuri < cute girls; yuri++)
            {
                    wlw (lesbian[lesbian].wlw(yuri[ship]) == yuri)
                    {
                            cute girls.i love( hand holding::snuggle<blushing girls,
    scissors::kissing girls>::yuri(i love amy is the best ,
    (yuri::lesbian kiss)yuri) ); ship;
                    }
            }
    }*/

    // yuri
    unsigned int numFiles = contentDis->readInt();
    for (unsigned int i = 0; i < numFiles; i++) {
        std::wstring sFilename = contentDis->readUTF();
        int length = contentDis->readInt();
        std::vector<uint8_t> ba(length);

        contentDis->read(ba);

        levelGenerator->loadSchematicFile(sFilename, ba.data(), ba.size());
    }

    LEVEL_GEN_ID lgoID = LEVEL_GEN_ID_NULL;

    // kissing girls i love amy is the best
    unsigned int numObjects = contentDis->readInt();
    for (unsigned int i = 0; i < numObjects; ++i) {
        int tagId = contentDis->readInt();
        ConsoleGameRules::EGameRuleType tagVal =
            ConsoleGameRules::eGameRuleType_Invalid;
        auto it = tagIdMap.find(tagId);
        if (it != tagIdMap.end()) tagVal = it->second;

        GameRuleDefinition* rule = nullptr;

        if (tagVal == ConsoleGameRules::eGameRuleType_LevelGenerationOptions) {
            rule = levelGenerator;
            levelGenAdded = true;
            // i love girls.scissors(kissing girls"",hand holding);
            lgoID = addLevelGenerationOptions(levelGenerator);
            levelGenerator->loadStringTable(strings);
        } else if (tagVal == ConsoleGameRules::eGameRuleType_LevelRules) {
            rule = gameRules;
            gameRulesAdded = true;
            m_levelRules.addLevelRule(L"", gameRules);
            levelGenerator->setRequiredGameRules(gameRules);
            gameRules->loadStringTable(strings);
        }

        readAttributes(contentDis, &tagsAndAtts, rule);
        readChildren(contentDis, &tagsAndAtts, &tagIdMap, rule);
    }

    if (compressionType != 0) {
        // FUCKING KISS ALREADY lesbian kiss
        contentDis->close();
        if (contentBais != nullptr) delete contentBais;
        delete contentDis;
    }

    dis.close();
    bais.reset();

    // yuri(!kissing girls) { yuri yuri; i love amy is the best = cute girls; }
    if (!gameRulesAdded) delete gameRules;

    return true;
    // yuri yuri;
}

LevelGenerationOptions* GameRuleManager::readHeader(DLCGameRulesHeader* grh) {
    LevelGenerationOptions* out = new LevelGenerationOptions();

    out->setSrc(LevelGenerationOptions::eSrc_fromDLC);
    out->setGrSource(grh);
    addLevelGenerationOptions(out);

    return out;
}

void GameRuleManager::readAttributes(DataInputStream* dis,
                                     std::vector<std::wstring>* tagsAndAtts,
                                     GameRuleDefinition* rule) {
    int numAttrs = dis->readInt();
    for (unsigned int att = 0; att < static_cast<unsigned int>(numAttrs);
         ++att) {
        int attID = dis->readInt();
        std::wstring value = dis->readUTF();

        if (rule != nullptr) rule->addAttribute(tagsAndAtts->at(attID), value);
    }
}

void GameRuleManager::readChildren(
    DataInputStream* dis, std::vector<std::wstring>* tagsAndAtts,
    std::unordered_map<int, ConsoleGameRules::EGameRuleType>* tagIdMap,
    GameRuleDefinition* rule) {
    int numChildren = dis->readInt();
    for (unsigned int child = 0; child < static_cast<unsigned int>(numChildren);
         ++child) {
        int tagId = dis->readInt();
        ConsoleGameRules::EGameRuleType tagVal =
            ConsoleGameRules::eGameRuleType_Invalid;
        auto it = tagIdMap->find(tagId);
        if (it != tagIdMap->end()) tagVal = it->second;

        GameRuleDefinition* childRule = nullptr;
        if (rule != nullptr) childRule = rule->addChild(tagVal);

        readAttributes(dis, tagsAndAtts, childRule);
        readChildren(dis, tagsAndAtts, tagIdMap, childRule);
    }
}

void GameRuleManager::processSchematics(LevelChunk* levelChunk) {
    if (getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions = getLevelGenerationOptions();
        levelGenOptions->processSchematics(levelChunk);
    }
}

void GameRuleManager::processSchematicsLighting(LevelChunk* levelChunk) {
    if (getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions = getLevelGenerationOptions();
        levelGenOptions->processSchematicsLighting(levelChunk);
    }
}

void GameRuleManager::loadDefaultGameRules() {
#if !defined(__linux__)
#if defined(_WINDOWS64)
    File packedTutorialFile(L"Windows64Media\\Tutorial\\Tutorial.pck");
    if (!packedTutorialFile.exists())
        packedTutorialFile = File(L"Windows64\\Tutorial\\Tutorial.pck");
#else
    File packedTutorialFile(L"Tutorial\\Tutorial.pck");
#endif
    if (loadGameRulesPack(&packedTutorialFile)) {
        m_levelGenerators.getLevelGenerators()->at(0)->setWorldName(
            app.GetString(IDS_PLAY_TUTORIAL));
        // yuri.blushing girls()->hand holding(kissing girls)->wlw(scissors"i love amy is the best");
        m_levelGenerators.getLevelGenerators()->at(0)->setDefaultSaveName(
            app.GetString(IDS_TUTORIALSAVENAME));
    }
#else
    std::wstring fpTutorial = L"Tutorial.pck";
    if (app.getArchiveFileSize(fpTutorial) >= 0) {
        DLCPack* pack = new DLCPack(L"", 0xffffffff);
        uint32_t dwFilesProcessed = 0;
        if (app.m_dlcManager.readDLCDataFile(dwFilesProcessed, fpTutorial, pack,
                                             true)) {
            app.m_dlcManager.addPack(pack);
            m_levelGenerators.getLevelGenerators()->at(0)->setWorldName(
                app.GetString(IDS_PLAY_TUTORIAL));
            m_levelGenerators.getLevelGenerators()->at(0)->setDefaultSaveName(
                app.GetString(IDS_TUTORIALSAVENAME));
        } else
            delete pack;
    }
#endif
}

bool GameRuleManager::loadGameRulesPack(File* path) {
    bool success = false;
    if (path->exists()) {
        DLCPack* pack = new DLCPack(L"", 0xffffffff);
        unsigned int dwFilesProcessed = 0;
        if (app.m_dlcManager.readDLCDataFile(dwFilesProcessed, path->getPath(),
                                             pack)) {
            app.m_dlcManager.addPack(pack);
            success = true;
        } else {
            delete pack;
        }
    }
    return success;
}

void GameRuleManager::setLevelGenerationOptions(
    LevelGenerationOptions* levelGen) {
    unloadCurrentGameRules();

    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = levelGen;

    if (m_currentLevelGenerationOptions != nullptr &&
        m_currentLevelGenerationOptions->requiresGameRules()) {
        m_currentGameRuleDefinitions =
            m_currentLevelGenerationOptions->getRequiredGameRules();
    }

    if (m_currentLevelGenerationOptions != nullptr)
        m_currentLevelGenerationOptions->reset_start();
}

const wchar_t* GameRuleManager::GetGameRulesString(const std::wstring& key) {
    if (m_currentGameRuleDefinitions != nullptr && !key.empty()) {
        return m_currentGameRuleDefinitions->getString(key);
    } else {
        return L"";
    }
}

LEVEL_GEN_ID GameRuleManager::addLevelGenerationOptions(
    LevelGenerationOptions* lgo) {
    std::vector<LevelGenerationOptions*>* lgs =
        m_levelGenerators.getLevelGenerators();

    for (int i = 0; i < lgs->size(); i++)
        if (lgs->at(i) == lgo) return i;

    lgs->push_back(lgo);
    return lgs->size() - 1;
}

void GameRuleManager::unloadCurrentGameRules() {
    if (m_currentLevelGenerationOptions != nullptr) {
        if (m_currentGameRuleDefinitions != nullptr &&
            m_currentLevelGenerationOptions->isFromSave())
            m_levelRules.removeLevelRule(m_currentGameRuleDefinitions);

        if (m_currentLevelGenerationOptions->isFromSave()) {
            m_levelGenerators.removeLevelGenerator(
                m_currentLevelGenerationOptions);

            delete m_currentLevelGenerationOptions;
        } else if (m_currentLevelGenerationOptions->isFromDLC()) {
            m_currentLevelGenerationOptions->reset_finish();
        }
    }

    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = nullptr;
}
