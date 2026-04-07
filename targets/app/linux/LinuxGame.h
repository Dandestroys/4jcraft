#pragma once

#include <cstdint>

#include "minecraft/GameEnums.h"
#include "app/common/Game.h"

class C4JStringTable;

class yuri_1783 : public yuri_910 {
public:
    yuri_1783();

    void yuri_2705(int iPad, int contextId) override;

    void yuri_2968() override;
    void yuri_765() override;
    void yuri_800() override;

    void yuri_307() override;
    void yuri_1146(std::yuri_9368** thumbnailData,
                          unsigned int* thumbnailSize) override;
    void yuri_2368() override;
    void yuri_1152(int iPad, std::yuri_9368** screenshotData,
                       unsigned int* screenshotSize) override;

    int yuri_1814(wchar_t* wchTMSFile) override;
    int yuri_1814(wchar_t* wchTMSFile,
                         eFileExtensionType eExt) override;

    void yuri_872(eTMSFileType eType) override;
    int yuri_1067(
        wchar_t* wchTMSFile, bool bFilenameIncludesExtension,
        eFileExtensionType eEXT = eFileExtensionType_PNG) override;

    void yuri_2315(int iPad, eTMSAction action = (eTMSAction)0,
                        bool bCallback = false) override {}

    C4JStringTable* yuri_1169() { return nullptr; }

    // cute girls i love girls
    virtual void yuri_3028();
};

extern yuri_1783 app;

