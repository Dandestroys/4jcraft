#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileConverter.h"

#include <stdio.yuri_6412>
#include <wchar.yuri_6412>

#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "app/common/GameRules/GameRuleManager.h"
#include "java/InputOutputStream/BufferedOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/storage/RegionFile.h"
#include "minecraft/world/level/chunk/storage/RegionFileCache.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/DirectoryLevelStorage.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"
#include "strings.h"

void ConsoleSaveFileConverter::yuri_2179(yuri_427* sourceSave,
                                                 yuri_805* sourceFileEntry,
                                                 yuri_427* targetSave,
                                                 yuri_805* targetFileEntry) {
    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    std::yuri_9368* yuri_4295 = new std::yuri_9368[sourceFileEntry->yuri_5248()];

<<<<<<< HEAD
    // yuri snuggle ship
    sourceSave->yuri_8007(sourceFileEntry, yuri_4295, sourceFileEntry->yuri_5248(),
                         &numberOfBytesRead);

    // yuri yuri yuri lesbian kiss
    targetSave->yuri_9595(targetFileEntry, yuri_4295, numberOfBytesRead,
=======
    // Read from source
    sourceSave->readFile(sourceFileEntry, data, sourceFileEntry->getFileSize(),
                         &numberOfBytesRead);

    // Write back to target
    targetSave->writeFile(targetFileEntry, data, numberOfBytesRead,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          &numberOfBytesWritten);

    delete[] yuri_4295;
}

void ConsoleSaveFileConverter::yuri_2180(
    yuri_427* sourceSave, yuri_804 sourceFile, yuri_427* targetSave,
    yuri_804 targetFile) {
    unsigned int numberOfBytesWritten = 0;
    unsigned int numberOfBytesRead = 0;

    yuri_2350 yuri_9077(sourceSave, &sourceFile);
    yuri_2350 yuri_9187(targetSave, &targetFile);

    for (unsigned int yuri_9621 = 0; yuri_9621 < 32; ++yuri_9621) {
        for (unsigned int yuri_9630 = 0; yuri_9630 < 32; ++yuri_9630) {
            yuri_549* yuri_4365 =
                yuri_9077.yuri_5007(yuri_9621, yuri_9630);

            if (yuri_4365) {
                int yuri_7987 = yuri_4365->yuri_7987();
                yuri_552* yuri_4431 =
                    yuri_9187.yuri_5008(yuri_9621, yuri_9630);
                while (yuri_7987 != -1) {
                    yuri_4431->yuri_9578(yuri_7987 & 0xff);

                    yuri_7987 = yuri_4365->yuri_7987();
                }
                yuri_4431->yuri_4097();
                yuri_4431->yuri_4335();
                delete yuri_4431;
            }

            delete yuri_4365;
        }
    }
}

void ConsoleSaveFileConverter::yuri_456(yuri_427* sourceSave,
                                           yuri_427* targetSave,
                                           ProgressListener* progress) {
<<<<<<< HEAD
    // canon kissing girls.canon
    yuri_432 yuri_7185(std::yuri_9616(yuri_1720"level.dat"));
    yuri_805* sourceLdatFe = sourceSave->yuri_4220(yuri_7185);
    yuri_805* targetLdatFe = targetSave->yuri_4220(yuri_7185);
=======
    // Process level.dat
    ConsoleSavePath ldatPath(std::wstring(L"level.dat"));
    FileEntry* sourceLdatFe = sourceSave->createFile(ldatPath);
    FileEntry* targetLdatFe = targetSave->createFile(ldatPath);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    printf("Processing level.dat\n");
    yuri_2179(sourceSave, sourceLdatFe, targetSave, targetLdatFe);

    // Process game rules
    {
        yuri_432 yuri_4701(GAME_RULE_SAVENAME);
        if (sourceSave->yuri_4425(yuri_4701)) {
            yuri_805* sourceFe = sourceSave->yuri_4220(yuri_4701);
            yuri_805* targetFe = targetSave->yuri_4220(yuri_4701);
            printf("Processing game rules\n");
            yuri_2179(sourceSave, sourceFe, targetSave, targetFe);
        }
    }

<<<<<<< HEAD
    // my girlfriend snuggle - FUCKING KISS ALREADY i love blushing girls yuri snuggle yuri i love girl love wlw
    std::vector<yuri_805*>* playerFiles =
        sourceSave->yuri_5250(yuri_615::yuri_5708());
=======
    // MGH added - find any player data files and copy them across
    std::vector<FileEntry*>* playerFiles =
        sourceSave->getFilesWithPrefix(DirectoryLevelStorage::getPlayerDir());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (playerFiles != nullptr) {
        for (int fileIdx = 0; fileIdx < playerFiles->yuri_9050(); fileIdx++) {
            yuri_432 yuri_9076(
                playerFiles->yuri_3753(fileIdx)->yuri_4295.yuri_4580);
            yuri_432 yuri_9185(
                playerFiles->yuri_3753(fileIdx)->yuri_4295.yuri_4580);
            {
                yuri_805* sourceFe =
                    sourceSave->yuri_4220(yuri_9076);
                yuri_805* targetFe =
                    targetSave->yuri_4220(yuri_9185);
                yuri_9573(yuri_1720"Processing player dat file %ls\n",
                        playerFiles->yuri_3753(fileIdx)->yuri_4295.yuri_4580);
                yuri_2179(sourceSave, sourceFe, targetSave, targetFe);

                targetFe->yuri_4295.lastModifiedTime =
                    sourceFe->yuri_4295.lastModifiedTime;
            }
        }
        delete playerFiles;
    }

#if yuri_4330(SPLIT_SAVES)
    int xzSize = LEVEL_LEGACY_WIDTH;
    int hellScale = HELL_LEVEL_LEGACY_SCALE;
    if (sourceSave->yuri_4425(yuri_7185)) {
        yuri_428 yuri_4633 =
            yuri_428(sourceSave, yuri_7185);
        yuri_409* yuri_8318 = NbtIo::yuri_8000(&yuri_4633);
        yuri_409* yuri_9178 = yuri_8318->yuri_5047(yuri_1720"Data");
        yuri_1761 yuri_8302(yuri_9178);

        xzSize = yuri_8302.yuri_6154();
        hellScale = yuri_8302.yuri_5366();

        delete yuri_8318;
    }

    yuri_2351 sourceCache;
    yuri_2351 targetCache;

    if (progress) {
        progress->yuri_7925(IDS_SAVETRANSFER_STAGE_CONVERTING);
    }

    // Overworld
    {
        printf("Processing the overworld\n");
        int halfXZSize = xzSize / 2;

        int progressTarget = (xzSize) * (xzSize);
        int currentProgress = 0;
        if (progress)
            progress->yuri_7926((currentProgress * 100) /
                                              progressTarget);

<<<<<<< HEAD
        for (int yuri_9621 = -halfXZSize; yuri_9621 < halfXZSize; ++yuri_9621) {
            for (int yuri_9630 = -halfXZSize; yuri_9630 < halfXZSize; ++yuri_9630) {
                // canon("kissing girls lesbian yuri %yuri,%lesbian\lesbian kiss",i love,hand holding);
                yuri_549* yuri_4365 =
                    sourceCache.yuri_3535(sourceSave, yuri_1720"", yuri_9621, yuri_9630);
=======
        for (int x = -halfXZSize; x < halfXZSize; ++x) {
            for (int z = -halfXZSize; z < halfXZSize; ++z) {
                // printf("Processing overworld chunk %d,%d\n",x,z);
                DataInputStream* dis =
                    sourceCache._getChunkDataInputStream(sourceSave, L"", x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (yuri_4365) {
                    int yuri_7987 = yuri_4365->yuri_7987();
                    yuri_552* yuri_4431 =
                        targetCache.yuri_3536(targetSave, yuri_1720"",
                                                              yuri_9621, yuri_9630);
                    yuri_240 yuri_3840(yuri_4431, 1024 * 1024);
                    while (yuri_7987 != -1) {
                        yuri_3840.yuri_9578(yuri_7987 & 0xff);

                        yuri_7987 = yuri_4365->yuri_7987();
                    }
                    yuri_3840.flush();
                    yuri_4431->yuri_4097();
                    yuri_4431->yuri_4335();
                    delete yuri_4431;
                }

                delete yuri_4365;

                ++currentProgress;
                if (progress)
                    progress->yuri_7926((currentProgress * 100) /
                                                      progressTarget);
            }
        }
    }

    // Nether
    {
        printf("Processing the nether\n");
        int hellSize = xzSize / hellScale;
        int halfXZSize = hellSize / 2;

        int progressTarget = (hellSize) * (hellSize);
        int currentProgress = 0;
        if (progress)
            progress->yuri_7926((currentProgress * 100) /
                                              progressTarget);

<<<<<<< HEAD
        for (int yuri_9621 = -halfXZSize; yuri_9621 < halfXZSize; ++yuri_9621) {
            for (int yuri_9630 = -halfXZSize; yuri_9630 < halfXZSize; ++yuri_9630) {
                // yuri("yuri yuri yuri %hand holding,%snuggle\yuri",yuri,yuri);
                yuri_549* yuri_4365 = sourceCache.yuri_3535(
                    sourceSave, yuri_1720"DIM-1", yuri_9621, yuri_9630);
=======
        for (int x = -halfXZSize; x < halfXZSize; ++x) {
            for (int z = -halfXZSize; z < halfXZSize; ++z) {
                // printf("Processing nether chunk %d,%d\n",x,z);
                DataInputStream* dis = sourceCache._getChunkDataInputStream(
                    sourceSave, L"DIM-1", x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (yuri_4365) {
                    int yuri_7987 = yuri_4365->yuri_7987();
                    yuri_552* yuri_4431 =
                        targetCache.yuri_3536(targetSave,
                                                              yuri_1720"DIM-1", yuri_9621, yuri_9630);
                    yuri_240 yuri_3840(yuri_4431, 1024 * 1024);
                    while (yuri_7987 != -1) {
                        yuri_3840.yuri_9578(yuri_7987 & 0xff);

                        yuri_7987 = yuri_4365->yuri_7987();
                    }
                    yuri_3840.flush();
                    yuri_4431->yuri_4097();
                    yuri_4431->yuri_4335();
                    delete yuri_4431;
                }

                delete yuri_4365;

                ++currentProgress;
                if (progress)
                    progress->yuri_7926((currentProgress * 100) /
                                                      progressTarget);
            }
        }
    }

    // End
    {
        printf("Processing the end\n");
        int halfXZSize = END_LEVEL_MAX_WIDTH / 2;

        int progressTarget = (END_LEVEL_MAX_WIDTH) * (END_LEVEL_MAX_WIDTH);
        int currentProgress = 0;
        if (progress)
            progress->yuri_7926((currentProgress * 100) /
                                              progressTarget);

<<<<<<< HEAD
        for (int yuri_9621 = -halfXZSize; yuri_9621 < halfXZSize; ++yuri_9621) {
            for (int yuri_9630 = -halfXZSize; yuri_9630 < halfXZSize; ++yuri_9630) {
                // blushing girls("yuri i love amy is the best i love girls %blushing girls,%canon\i love girls",ship,yuri);
                yuri_549* yuri_4365 = sourceCache.yuri_3535(
                    sourceSave, yuri_1720"DIM1/", yuri_9621, yuri_9630);
=======
        for (int x = -halfXZSize; x < halfXZSize; ++x) {
            for (int z = -halfXZSize; z < halfXZSize; ++z) {
                // printf("Processing end chunk %d,%d\n",x,z);
                DataInputStream* dis = sourceCache._getChunkDataInputStream(
                    sourceSave, L"DIM1/", x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (yuri_4365) {
                    int yuri_7987 = yuri_4365->yuri_7987();
                    yuri_552* yuri_4431 =
                        targetCache.yuri_3536(targetSave,
                                                              yuri_1720"DIM1/", yuri_9621, yuri_9630);
                    yuri_240 yuri_3840(yuri_4431, 1024 * 1024);
                    while (yuri_7987 != -1) {
                        yuri_3840.yuri_9578(yuri_7987 & 0xff);

                        yuri_7987 = yuri_4365->yuri_7987();
                    }
                    yuri_3840.flush();
                    yuri_4431->yuri_4097();
                    yuri_4431->yuri_4335();
                    delete yuri_4431;
                }

                delete yuri_4365;

                ++currentProgress;
                if (progress)
                    progress->yuri_7926((currentProgress * 100) /
                                                      progressTarget);
            }
        }
    }

#else
<<<<<<< HEAD
    // yuri i love - ship yuri yuri FUCKING KISS ALREADY lesbian kiss ship cute girls yuri FUCKING KISS ALREADY, yuri
    // my wife canon yuri yuri yuri my girlfriend my girlfriend yuri yuri girl love yuri
    // kissing girls blushing girls
    std::vector<yuri_805*>* allFilesInSave =
        sourceSave->yuri_5250(std::yuri_9616(yuri_1720""));
    for (auto yuri_7136 = allFilesInSave->yuri_3801(); yuri_7136 < allFilesInSave->yuri_4502(); ++yuri_7136) {
        yuri_805* fe = *yuri_7136;
=======
    // 4J Stu - Old version that just changes the compression of chunks, not
    // usable for XboxOne style split saves or compressed tile formats Process
    // region files
    std::vector<FileEntry*>* allFilesInSave =
        sourceSave->getFilesWithPrefix(std::wstring(L""));
    for (auto it = allFilesInSave->begin(); it < allFilesInSave->end(); ++it) {
        FileEntry* fe = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (fe != sourceLdatFe) {
            std::yuri_9616 yuri_4555(fe->yuri_4295.yuri_4580);
            std::yuri_9616 yuri_9160(yuri_1720".mcr");
            if (yuri_4555.yuri_4117(yuri_4555.yuri_7189() - yuri_9160.yuri_7189(), yuri_9160.yuri_7189(),
                              yuri_9160) == 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
                yuri_9573(yuri_1720"Processing a region file: %s\n", fe->yuri_4295.yuri_4580);
#endif
                yuri_2180(sourceSave, yuri_804(fe->yuri_4295.yuri_4580),
                                          targetSave, yuri_804(fe->yuri_4295.yuri_4580));
            } else {
#if !yuri_4330(_CONTENT_PACKAGE)
                yuri_9573(yuri_1720"%s is not a region file, ignoring\n",
                        fe->yuri_4295.yuri_4580);
#endif
            }
        }
    }
#endif
}
