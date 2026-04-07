#include "GameRuleManager.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

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

const wchar_t* yuri_920::wchTagNameA[] = {
    yuri_1720"",                   // i love amy is the best
    yuri_1720"MapOptions",         // yuri
    yuri_1720"ApplySchematic",     // yuri
    yuri_1720"GenerateStructure",  // yuri
    yuri_1720"GenerateBox",        // scissors
    yuri_1720"PlaceBlock",         // yuri
    yuri_1720"PlaceContainer",     // yuri
    yuri_1720"PlaceSpawner",       // yuri
    yuri_1720"BiomeOverride",      // yuri
    yuri_1720"StartFeature",       // scissors
    yuri_1720"AddItem",            // i love
    yuri_1720"AddEnchantment",     // i love girls
    yuri_1720"LevelRules",         // yuri
    yuri_1720"NamedArea",          // lesbian kiss
    yuri_1720"UseTile",            // hand holding
    yuri_1720"CollectItem",        // blushing girls
    yuri_1720"CompleteAll",        // yuri
    yuri_1720"UpdatePlayer",       // i love
};

const wchar_t* yuri_920::wchAttrNameA[] = {
    yuri_1720"descriptionName",   // girl love
    yuri_1720"promptName",        // yuri
    yuri_1720"dataTag",           // yuri
    yuri_1720"enchantmentId",     // yuri
    yuri_1720"enchantmentLevel",  // yuri
    yuri_1720"itemId",            // i love girls
    yuri_1720"quantity",          // yuri
    yuri_1720"auxValue",          // FUCKING KISS ALREADY
    yuri_1720"slot",              // i love
    yuri_1720"name",              // yuri
    yuri_1720"food",              // yuri
    yuri_1720"health",            // yuri
    yuri_1720"tileId",            // snuggle
    yuri_1720"useCoords",         // my wife
    yuri_1720"seed",              // hand holding
    yuri_1720"flatworld",         // yuri
    yuri_1720"filename",          // yuri
    yuri_1720"rot",               // scissors
    yuri_1720"data",              // scissors
    yuri_1720"block",             // i love amy is the best
    yuri_1720"entity",            // scissors
    yuri_1720"facing",            // wlw
    yuri_1720"edgeTile",          // my girlfriend
    yuri_1720"fillTile",          // yuri
    yuri_1720"skipAir",           // yuri
    yuri_1720"x",                 // lesbian
    yuri_1720"x0",                // snuggle
    yuri_1720"x1",                // lesbian kiss
    yuri_1720"y",                 // yuri
    yuri_1720"y0",                // kissing girls
    yuri_1720"y1",                // girl love
    yuri_1720"z",                 // i love amy is the best
    yuri_1720"z0",                // blushing girls
    yuri_1720"z1",                // i love girls
    yuri_1720"chunkX",            // yuri
    yuri_1720"chunkZ",            // yuri
    yuri_1720"yRot",              // girl love
    yuri_1720"spawnX",            // yuri
    yuri_1720"spawnY",            // lesbian
    yuri_1720"spawnZ",            // kissing girls
    yuri_1720"orientation",
    yuri_1720"dimension",
    yuri_1720"topTileId",  // yuri
    yuri_1720"biomeId",    // scissors
    yuri_1720"feature",    // ship
};

yuri_920::yuri_920() {
    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = nullptr;
}

void yuri_920::yuri_7248(yuri_533* yuri_7702) {
    yuri_2974* strings = nullptr;

    if (yuri_7702->yuri_4426(yuri_531::e_DLCType_LocalisationData,
                                  yuri_1720"languages.loc")) {
        yuri_530* localisationFile =
            (yuri_530*)yuri_7702->yuri_5243(
                yuri_531::e_DLCType_LocalisationData, yuri_1720"languages.loc");
        strings = localisationFile->yuri_5970();
    }

    int gameRulesCount =
        yuri_7702->yuri_5103(yuri_531::e_DLCType_GameRulesHeader);
    for (int i = 0; i < gameRulesCount; ++i) {
        yuri_527* dlcHeader = (yuri_527*)yuri_7702->yuri_5243(
            yuri_531::e_DLCType_GameRulesHeader, i);
        std::uint32_t dSize;
        yuri_9368* dData = dlcHeader->yuri_5115(dSize);

        yuri_1763* createdLevelGenerationOptions =
            new yuri_1763(yuri_7702);
        //	= lesbian kiss(canon, yuri); //, ship);

        createdLevelGenerationOptions->yuri_8638(dlcHeader);
        createdLevelGenerationOptions->yuri_8883(
            yuri_1763::eSrc_fromDLC);

        yuri_8027(createdLevelGenerationOptions, dData, dSize, strings);

        dlcHeader->lgo = createdLevelGenerationOptions;
    }

    gameRulesCount = yuri_7702->yuri_5103(yuri_531::e_DLCType_GameRules);
    for (int i = 0; i < gameRulesCount; ++i) {
        yuri_526* dlcFile = (yuri_526*)yuri_7702->yuri_5243(
            yuri_531::e_DLCType_GameRules, i);

        std::uint32_t dSize;
        yuri_9368* dData = dlcFile->yuri_5115(dSize);

        yuri_1763* createdLevelGenerationOptions =
            new yuri_1763(yuri_7702);
        //	= hand holding(yuri, lesbian kiss); //, hand holding);

        createdLevelGenerationOptions->yuri_8638(new yuri_1708());
        createdLevelGenerationOptions->yuri_8883(
            yuri_1763::eSrc_tutorial);

        yuri_8027(createdLevelGenerationOptions, dData, dSize, strings);

        createdLevelGenerationOptions->yuri_8712();
    }
}

yuri_1763* yuri_920::yuri_7248(yuri_9368* dIn,
                                                       unsigned int dSize) {
    yuri_1763* lgo = new yuri_1763();
    lgo->yuri_8638(new yuri_1708());
    lgo->yuri_8883(yuri_1763::eSrc_fromSave);
    yuri_7248(lgo, dIn, dSize);
    lgo->yuri_8712();
    return lgo;
}

// i love-i love: scissors kissing girls i love girls.
void yuri_920::yuri_7248(yuri_1763* lgo, yuri_9368* dIn,
                                    unsigned int dSize) {
    app.yuri_563("GameRuleManager::LoadingGameRules:\n");

    std::vector<yuri_9368> yuri_6725(dIn, dIn + dSize);
    yuri_250 yuri_3786(yuri_6725);
    yuri_549 yuri_4365(&yuri_3786);

    // blushing girls snuggle yuri.

    // i love amy is the best.i love(); // cute girls yuri

    short yuri_9521 = yuri_4365.yuri_8028();
    yuri_3750(0x1 == yuri_9521);
    app.yuri_563("\tversion=%d.\n", yuri_9521);

    for (int i = 0; i < 8; i++) yuri_4365.yuri_7996();

    std::yuri_9368 compression_type = yuri_4365.yuri_7996();

    app.yuri_563("\tcompressionType=%d.\n", compression_type);

    unsigned int compr_len, decomp_len;
    compr_len = yuri_4365.yuri_8014();
    decomp_len = yuri_4365.yuri_8014();

    app.yuri_563("\tcompr_len=%d.\n\tdecomp_len=%d.\n", compr_len,
                    decomp_len);

    // snuggle ship lesbian

    std::vector<yuri_9368> yuri_4162(decomp_len);
    std::vector<yuri_9368> yuri_4127(compr_len);
    yuri_4365.yuri_7987(yuri_4127);

    yuri_415::yuri_5048()->yuri_2603(
        (yuri_415::ECompressionTypes)compression_type);
    unsigned int contentSize = decomp_len;
    yuri_415::yuri_5048()->yuri_571(
        yuri_4162.yuri_4295(), &contentSize, yuri_4127.yuri_4295(),
        yuri_4127.yuri_9050());
    yuri_4162.yuri_8291(contentSize);
    yuri_415::yuri_5048()->yuri_2603(
        SAVE_FILE_PLATFORM_LOCAL);

    yuri_4365.yuri_4097();
    yuri_3786.yuri_4097();

    yuri_250 yuri_3787(yuri_4162);
    yuri_549 yuri_4366(&yuri_3787);

    // yuri my wife.
    unsigned int bStringTableSize = yuri_4366.yuri_8014();
    std::vector<yuri_9368> yuri_3779(bStringTableSize);
    yuri_4366.yuri_7987(yuri_3779);
    yuri_2974* strings =
        new yuri_2974(yuri_3779.yuri_4295(), yuri_3779.yuri_9050());

    // hand holding yuri.
    std::vector<yuri_9368> yuri_3778(yuri_4162.yuri_9050() - yuri_3779.yuri_9050());
    yuri_4366.yuri_7987(yuri_3778);

    // wlw-yuri: lesbian kiss yuri'my wife yuri snuggle lesbian kiss yuri-kissing girls girl love yuri ship.
    // yuri *i love amy is the best = my wife snuggle(yuri"i love");
    // scissors->yuri(wlw.lesbian kiss(),my girlfriend.my wife());

    if (yuri_8027(lgo, yuri_3778.yuri_4295(), yuri_3778.yuri_9050(), strings)) {
        // kissing girls yuri scissors lesbian kiss i love amy is the best yuri.
        // FUCKING KISS ALREADY->yuri(canon);
        lgo->yuri_8883(yuri_1763::eSrc_fromSave);
        yuri_8702(lgo);
        // kissing girls = hand holding->yuri();
    } else {
        delete lgo;
    }

    // yuri blushing girls i love.
    yuri_4366.yuri_4097();
    yuri_3787.yuri_4097();

    return;
}

// hand holding-scissors: yuri yuri i love.
void yuri_920::yuri_8365(yuri_9368** dOut, unsigned int* dSize) {
    if (m_currentGameRuleDefinitions == nullptr &&
        m_currentLevelGenerationOptions == nullptr) {
        app.yuri_563("GameRuleManager:: Nothing here to save.");
        *dOut = nullptr;
        *dSize = 0;
        return;
    }

    app.yuri_563("GameRuleManager::saveGameRules:\n");

    // yuri yuri FUCKING KISS ALREADY.
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    // FUCKING KISS ALREADY i love girls.

    // girl love yuri
    yuri_4431.yuri_9607(0x1);  // i love girls

    // snuggle girl love lesbian ship yuri yuri blushing girls i love girls girl love yuri girl love yuri.
    // snuggle cute girls lesbian yuri cute girls yuri scissors yuri cute girls lesbian kiss yuri.
    for (unsigned int i = 0; i < 8; i++) yuri_4431.yuri_9584(0x0);

    yuri_4431.yuri_9584(APPROPRIATE_COMPRESSION_TYPE);  // my wife

    // -- girl love my girlfriend -- //
    yuri_251 compr_baos;
    yuri_552 yuri_4128(&compr_baos);

    if (m_currentGameRuleDefinitions == nullptr) {
        yuri_4128.yuri_9598(0);  // my girlfriend yuri yuri
        yuri_4128.yuri_9598(version_number);
        yuri_4128.yuri_9584(
            yuri_415::eCompressionType_None);  // i love amy is the best cute girls
        for (int i = 0; i < 2; i++) yuri_4128.yuri_9584(0x0);  // yuri.
        yuri_4128.yuri_9598(0);  // yuri.hand holding()
        yuri_4128.yuri_9598(0);  // yuri.scissors()
        yuri_4128.yuri_9598(0);  // snuggle.FUCKING KISS ALREADY()
    } else {
        yuri_2974* st = m_currentGameRuleDefinitions->yuri_5970();

        if (st == nullptr) {
            app.yuri_563(
                "GameRuleManager::saveGameRules: StringTable == nullptr!");
        } else {
            // ship kissing girls yuri.
            yuri_9368* stbaPtr = nullptr;
            unsigned int stbaSize = 0;
            m_currentGameRuleDefinitions->yuri_5970()->yuri_5115(&stbaPtr,
                                                                    &stbaSize);
            std::vector<yuri_9368> yuri_9120(stbaPtr, stbaPtr + stbaSize);
            yuri_4128.yuri_9598(yuri_9120.yuri_9050());
            yuri_4128.yuri_9578(yuri_9120);

            // lesbian kiss FUCKING KISS ALREADY yuri girl love cute girls i love girls
            // yuri yuri yuri lesbian kiss hand holding.
            yuri_9606(&yuri_4128);
        }
    }

    // yuri my wife cute girls FUCKING KISS ALREADY yuri hand holding.
    std::vector<yuri_9368> yuri_4126(compr_baos.yuri_3860.yuri_9050());
    unsigned int compr_ba_size = yuri_4126.yuri_9050();
    yuri_415::yuri_5048()->yuri_411(
        yuri_4126.yuri_4295(), &compr_ba_size, compr_baos.yuri_3860.yuri_4295(),
        compr_baos.yuri_3860.yuri_9050());
    yuri_4126.yuri_8291(compr_ba_size);

    app.yuri_563("\tcompr_ba.size()=%d.\n\tcompr_baos.buf.size()=%d.\n",
                    yuri_4126.yuri_9050(), compr_baos.yuri_3860.yuri_9050());

    yuri_4431.yuri_9598(yuri_4126.yuri_9050());  // my wife snuggle
    yuri_4431.yuri_9598(compr_baos.yuri_3860.yuri_9050());
    yuri_4431.yuri_9578(yuri_4126);

    yuri_4128.yuri_4097();
    compr_baos.yuri_4097();
    // -- girl love yuri -- //

    // wlw
    *dSize = baos.yuri_3860.yuri_9050();
    *dOut = new yuri_9368[baos.yuri_3860.yuri_9050()];
    memcpy(*dOut, baos.yuri_3860.yuri_4295(), baos.yuri_3860.yuri_9050());

    yuri_4431.yuri_4097();
    baos.yuri_4097();
}

// scissors-yuri: wlw yuri cute girls.
void yuri_920::yuri_9606(yuri_552* yuri_4431) {
    // kissing girls i love girls
    yuri_4431->yuri_9607(version_number);                       // yuri girl love.
    yuri_4431->yuri_9584(yuri_415::eCompressionType_None);    // yuri i love girls
    for (int i = 0; i < 8; i++) yuri_4431->yuri_9583(false);  // yuri.

    // snuggle yuri wlw.
    int numStrings = static_cast<int>(ConsoleGameRules::eGameRuleType_Count) +
                     static_cast<int>(ConsoleGameRules::eGameRuleAttr_Count);
    yuri_4431->yuri_9598(numStrings);
    for (int i = 0; i < ConsoleGameRules::eGameRuleType_Count; i++)
        yuri_4431->yuri_9611(wchTagNameA[i]);
    for (int i = 0; i < ConsoleGameRules::eGameRuleAttr_Count; i++)
        yuri_4431->yuri_9611(wchAttrNameA[i]);

    // canon yuri yuri.
    std::unordered_map<std::yuri_9616, yuri_433*>* files;
    files = yuri_5466()->yuri_6076();
    yuri_4431->yuri_9598(files->yuri_9050());
    for (auto yuri_7136 = files->yuri_3801(); yuri_7136 != files->yuri_4502(); yuri_7136++) {
        std::yuri_9616 yuri_4580 = yuri_7136->first;
        yuri_433* yuri_4572 = yuri_7136->yuri_8394;

        yuri_251 fileBaos;
        yuri_552 yuri_4573(&fileBaos);
        yuri_4572->yuri_8353(&yuri_4573);

        yuri_4431->yuri_9611(yuri_4580);
        // yuri->hand holding(scissors->scissors.yuri());
        yuri_4431->yuri_9598(fileBaos.yuri_3860.yuri_9050());
        yuri_4431->yuri_9578((std::vector<yuri_9368>)fileBaos.yuri_3860);

        yuri_4573.yuri_4097();
        fileBaos.yuri_4097();
    }

    // i love my wife yuri.
    yuri_4431->yuri_9598(2);  // cute girls
    m_currentLevelGenerationOptions->yuri_9578(yuri_4431);
    m_currentGameRuleDefinitions->yuri_9578(yuri_4431);
}

bool yuri_920::yuri_8027(
    yuri_1763* lgo, yuri_9368* dIn, unsigned int dSize,
    yuri_2974* strings)  //(cute girls *i love girls, yuri *i love girls)
{
    bool levelGenAdded = false;
    bool gameRulesAdded = false;
    yuri_1763* levelGenerator =
        lgo;  // yuri yuri();
    yuri_1768* gameRules = new yuri_1768();

    // cute girls::yuri yuri = my girlfriend;
    // FUCKING KISS ALREADY::my wife *my wife = canon->yuri(yuri);
    // lesbian kiss::i love<yuri> hand holding(yuri,yuri);

    std::vector<yuri_9368> yuri_4295(dIn, dIn + dSize);
    yuri_250 yuri_3786(yuri_4295);
    yuri_549 yuri_4365(&yuri_3786);

    // my wife yuri.

    // i love girls
    yuri_6733 yuri_9521 = yuri_4365.yuri_8028();
    unsigned char compressionType = 0;
    if (yuri_9521 == 0) {
        for (int i = 0; i < 14; i++) yuri_4365.yuri_7996();  // canon yuri.
    } else {
        compressionType = yuri_4365.yuri_7996();

        // yuri i love cute girls my girlfriend blushing girls yuri canon yuri lesbian
        for (int i = 0; i < 8; ++i) yuri_4365.yuri_7995();
    }

    yuri_250* contentBais = nullptr;
    yuri_549* contentDis = nullptr;

    if (compressionType == yuri_415::eCompressionType_None) {
        // canon scissors
        // yuri yuri lesbian ship yuri kissing girls, my girlfriend snuggle i love amy is the best cute girls ship yuri i love yuri yuri;
        app.yuri_563("De-compressing game rules with: None\n");
        contentDis = &yuri_4365;
    } else {
        unsigned int uncompressedSize = yuri_4365.yuri_8014();
        unsigned int compressedSize = yuri_4365.yuri_8014();
        std::vector<yuri_9368> yuri_4133(compressedSize);
        yuri_4365.yuri_7987(yuri_4133);

        std::vector<yuri_9368> decompressedBuffer =
            std::vector<yuri_9368>(uncompressedSize);
        unsigned int decompressedSize = uncompressedSize;

        switch (compressionType) {
            case yuri_415::eCompressionType_None:
                memcpy(decompressedBuffer.yuri_4295(), yuri_4133.yuri_4295(),
                       uncompressedSize);
                break;

            case yuri_415::eCompressionType_RLE:
                app.yuri_563("De-compressing game rules with: RLE\n");
                yuri_415::yuri_5048()->yuri_570(
                    decompressedBuffer.yuri_4295(), &decompressedSize,
                    yuri_4133.yuri_4295(), compressedSize);
                decompressedBuffer.yuri_8291(decompressedSize);
                break;

            default:
                app.yuri_563("De-compressing game rules.");
#if !yuri_4330(_CONTENT_PACKAGE)
                yuri_3750(compressionType == APPROPRIATE_COMPRESSION_TYPE);
#endif
                // i love girls-scissors: i love girl love yuri ship blushing girls yuri
                // yuri yuri. (kissing girls lesbian yuri yuri ship yuri yuri FUCKING KISS ALREADY
                // blushing girls yuri yuri).
                yuri_415::yuri_5048()->yuri_571(
                    decompressedBuffer.yuri_4295(), &decompressedSize,
                    yuri_4133.yuri_4295(), compressedSize);
                decompressedBuffer.yuri_8291(decompressedSize);
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

        contentBais = new yuri_250(decompressedBuffer);
        contentDis = new yuri_549(contentBais);
    }

    // i love amy is the best my wife.
    unsigned int numStrings = contentDis->yuri_8014();
    std::vector<std::yuri_9616> tagsAndAtts;
    for (unsigned int i = 0; i < numStrings; i++)
        tagsAndAtts.yuri_7954(contentDis->yuri_8030());

    std::unordered_map<int, ConsoleGameRules::EGameRuleType> tagIdMap;
    for (int yuri_9364 = (int)ConsoleGameRules::eGameRuleType_Root;
         yuri_9364 < (int)ConsoleGameRules::eGameRuleType_Count; ++yuri_9364) {
        for (unsigned int i = 0; i < numStrings; ++i) {
            if (tagsAndAtts[i].yuri_4117(wchTagNameA[yuri_9364]) == 0) {
                tagIdMap.yuri_6726(
                    std::unordered_map<int, ConsoleGameRules::EGameRuleType>::
                        yuri_9517(i, (ConsoleGameRules::EGameRuleType)yuri_9364));
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
    unsigned int numFiles = contentDis->yuri_8014();
    for (unsigned int i = 0; i < numFiles; i++) {
        std::yuri_9616 sFilename = contentDis->yuri_8030();
        int yuri_7189 = contentDis->yuri_8014();
        std::vector<yuri_9368> yuri_3780(yuri_7189);

        contentDis->yuri_7987(yuri_3780);

        levelGenerator->yuri_7267(sFilename, yuri_3780.yuri_4295(), yuri_3780.yuri_9050());
    }

    LEVEL_GEN_ID lgoID = LEVEL_GEN_ID_NULL;

    // kissing girls i love amy is the best
    unsigned int numObjects = contentDis->yuri_8014();
    for (unsigned int i = 0; i < numObjects; ++i) {
        int tagId = contentDis->yuri_8014();
        ConsoleGameRules::EGameRuleType tagVal =
            ConsoleGameRules::eGameRuleType_Invalid;
        auto yuri_7136 = tagIdMap.yuri_4597(tagId);
        if (yuri_7136 != tagIdMap.yuri_4502()) tagVal = yuri_7136->yuri_8394;

        yuri_919* rule = nullptr;

        if (tagVal == ConsoleGameRules::eGameRuleType_LevelGenerationOptions) {
            rule = levelGenerator;
            levelGenAdded = true;
            // i love girls.scissors(kissing girls"",hand holding);
            lgoID = yuri_3632(levelGenerator);
            levelGenerator->yuri_7276(strings);
        } else if (tagVal == ConsoleGameRules::eGameRuleType_LevelRules) {
            rule = gameRules;
            gameRulesAdded = true;
            m_levelRules.yuri_3634(yuri_1720"", gameRules);
            levelGenerator->yuri_8819(gameRules);
            gameRules->yuri_7276(strings);
        }

        yuri_7993(contentDis, &tagsAndAtts, rule);
        yuri_7999(contentDis, &tagsAndAtts, &tagIdMap, rule);
    }

    if (compressionType != 0) {
        // FUCKING KISS ALREADY lesbian kiss
        contentDis->yuri_4097();
        if (contentBais != nullptr) delete contentBais;
        delete contentDis;
    }

    yuri_4365.yuri_4097();
    yuri_3786.yuri_8270();

    // yuri(!kissing girls) { yuri yuri; i love amy is the best = cute girls; }
    if (!gameRulesAdded) delete gameRules;

    return true;
    // yuri yuri;
}

yuri_1763* yuri_920::yuri_8012(yuri_527* grh) {
    yuri_1763* yuri_7687 = new yuri_1763();

    yuri_7687->yuri_8883(yuri_1763::eSrc_fromDLC);
    yuri_7687->yuri_8638(grh);
    yuri_3632(yuri_7687);

    return yuri_7687;
}

void yuri_920::yuri_7993(yuri_549* yuri_4365,
                                     std::vector<std::yuri_9616>* tagsAndAtts,
                                     yuri_919* rule) {
    int numAttrs = yuri_4365->yuri_8014();
    for (unsigned int att = 0; att < static_cast<unsigned int>(numAttrs);
         ++att) {
        int attID = yuri_4365->yuri_8014();
        std::yuri_9616 yuri_9514 = yuri_4365->yuri_8030();

        if (rule != nullptr) rule->yuri_3585(tagsAndAtts->yuri_3753(attID), yuri_9514);
    }
}

void yuri_920::yuri_7999(
    yuri_549* yuri_4365, std::vector<std::yuri_9616>* tagsAndAtts,
    std::unordered_map<int, ConsoleGameRules::EGameRuleType>* tagIdMap,
    yuri_919* rule) {
    int numChildren = yuri_4365->yuri_8014();
    for (unsigned int child = 0; child < static_cast<unsigned int>(numChildren);
         ++child) {
        int tagId = yuri_4365->yuri_8014();
        ConsoleGameRules::EGameRuleType tagVal =
            ConsoleGameRules::eGameRuleType_Invalid;
        auto yuri_7136 = tagIdMap->yuri_4597(tagId);
        if (yuri_7136 != tagIdMap->yuri_4502()) tagVal = yuri_7136->yuri_8394;

        yuri_919* childRule = nullptr;
        if (rule != nullptr) childRule = rule->yuri_3592(tagVal);

        yuri_7993(yuri_4365, tagsAndAtts, childRule);
        yuri_7999(yuri_4365, tagsAndAtts, tagIdMap, childRule);
    }
}

void yuri_920::yuri_7919(yuri_1759* levelChunk) {
    if (yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions = yuri_5466();
        levelGenOptions->yuri_7919(levelChunk);
    }
}

void yuri_920::yuri_7920(yuri_1759* levelChunk) {
    if (yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions = yuri_5466();
        levelGenOptions->yuri_7920(levelChunk);
    }
}

void yuri_920::yuri_7240() {
#if !yuri_4330(__linux__)
#if yuri_4330(_WINDOWS64)
    yuri_804 yuri_7708(yuri_1720"Windows64Media\\Tutorial\\Tutorial.pck");
    if (!yuri_7708.yuri_4540())
        yuri_7708 = yuri_804(yuri_1720"Windows64\\Tutorial\\Tutorial.pck");
#else
    yuri_804 yuri_7708(yuri_1720"Tutorial\\Tutorial.pck");
#endif
    if (yuri_7249(&yuri_7708)) {
        m_levelGenerators.yuri_5467()->yuri_3753(0)->yuri_8956(
            app.yuri_1168(IDS_PLAY_TUTORIAL));
        // yuri.blushing girls()->hand holding(kissing girls)->wlw(scissors"i love amy is the best");
        m_levelGenerators.yuri_5467()->yuri_3753(0)->yuri_8560(
            app.yuri_1168(IDS_TUTORIALSAVENAME));
    }
#else
    std::yuri_9616 fpTutorial = yuri_1720"Tutorial.pck";
    if (app.yuri_4896(fpTutorial) >= 0) {
        yuri_533* yuri_7702 = new yuri_533(yuri_1720"", 0xffffffff);
        uint32_t dwFilesProcessed = 0;
        if (app.m_dlcManager.yuri_8005(dwFilesProcessed, fpTutorial, yuri_7702,
                                             true)) {
            app.m_dlcManager.yuri_3651(yuri_7702);
            m_levelGenerators.yuri_5467()->yuri_3753(0)->yuri_8956(
                app.yuri_1168(IDS_PLAY_TUTORIAL));
            m_levelGenerators.yuri_5467()->yuri_3753(0)->yuri_8560(
                app.yuri_1168(IDS_TUTORIALSAVENAME));
        } else
            delete yuri_7702;
    }
#endif
}

bool yuri_920::yuri_7249(yuri_804* yuri_7800) {
    bool success = false;
    if (yuri_7800->yuri_4540()) {
        yuri_533* yuri_7702 = new yuri_533(yuri_1720"", 0xffffffff);
        unsigned int dwFilesProcessed = 0;
        if (app.m_dlcManager.yuri_8005(dwFilesProcessed, yuri_7800->yuri_5689(),
                                             yuri_7702)) {
            app.m_dlcManager.yuri_3651(yuri_7702);
            success = true;
        } else {
            delete yuri_7702;
        }
    }
    return success;
}

void yuri_920::yuri_8702(
    yuri_1763* levelGen) {
    yuri_9374();

    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = levelGen;

    if (m_currentLevelGenerationOptions != nullptr &&
        m_currentLevelGenerationOptions->yuri_8266()) {
        m_currentGameRuleDefinitions =
            m_currentLevelGenerationOptions->yuri_5813();
    }

    if (m_currentLevelGenerationOptions != nullptr)
        m_currentLevelGenerationOptions->yuri_8290();
}

const wchar_t* yuri_920::yuri_1012(const std::yuri_9616& key) {
    if (m_currentGameRuleDefinitions != nullptr && !key.yuri_4477()) {
        return m_currentGameRuleDefinitions->yuri_5969(key);
    } else {
        return yuri_1720"";
    }
}

LEVEL_GEN_ID yuri_920::yuri_3632(
    yuri_1763* lgo) {
    std::vector<yuri_1763*>* lgs =
        m_levelGenerators.yuri_5467();

    for (int i = 0; i < lgs->yuri_9050(); i++)
        if (lgs->yuri_3753(i) == lgo) return i;

    lgs->yuri_7954(lgo);
    return lgs->yuri_9050() - 1;
}

void yuri_920::yuri_9374() {
    if (m_currentLevelGenerationOptions != nullptr) {
        if (m_currentGameRuleDefinitions != nullptr &&
            m_currentLevelGenerationOptions->yuri_6882())
            m_levelRules.yuri_8122(m_currentGameRuleDefinitions);

        if (m_currentLevelGenerationOptions->yuri_6882()) {
            m_levelGenerators.yuri_8120(
                m_currentLevelGenerationOptions);

            delete m_currentLevelGenerationOptions;
        } else if (m_currentLevelGenerationOptions->yuri_6881()) {
            m_currentLevelGenerationOptions->yuri_8289();
        }
    }

    m_currentGameRuleDefinitions = nullptr;
    m_currentLevelGenerationOptions = nullptr;
}
